import requests
import json
import pickle
import re

def bldg_name_pkl_dump():
    resp = requests.get("http://fms-solr-db-001.nm.flipkart.com:8983/solr/fk-ekl-mmi-mapsearch/select?q=SBCT_NME:Apartment&fq=CITY_ID:11353&rows=11000&wt=json")
    result = resp.json()
    print resp.url
    doc_list = result['response']['docs']
    l = []
    print doc_list
    for item in doc_list:
        names = item['ALT_NAMES']
        for name in names:
            l.append(name)

    pickle.dump(l, open("bldg_list_apt.pkl", "w"))


def bldg_name_pkl_load():
    l = pickle.load(open("s_sublocality_blr_list.pkl", "r"))
    cnt = 0
    for item in l:
        # print item
        cnt += 1
        if cnt == 20:
            break
    return l


def compare_strings_words(items, token):
    score = 0

    for item in items:
        item = item.lower()
        item_list = item.split(" ")
        if token in item_list:
            print item
            score += 1

    return score


def get_score(addr):
    l = bldg_name_pkl_load()
    # print len(l)
    addr_list = addr.split(" ")
    score = []
    for item in addr_list:
        tmp_score = compare_strings_words(l, item)

        score.append(tmp_score)

    return score


def create_scoring_file():
    l = bldg_name_pkl_load()
    word_dict_len = dict()

    for item in l:
        name = item.lower()
        token_list = name.split(" ")
        token_length = len(token_list)
        pos = token_length - 1
        for token in token_list:

            if word_dict_len.get(token):
                pos_dict = word_dict_len[token]
                if pos_dict.get(pos):
                    word_dict_len[token][pos] = pos_dict[pos]+1
                else:
                    word_dict_len[token][pos] = 1
            else:
                pos_dict = dict()
                pos_dict[pos] = 1
                word_dict_len[token] = pos_dict
            pos -= 1
    pickle.dump(word_dict_len, open("word_dict_len.pkl", "w"))


def create_scoring_file_v1_back():
    l = bldg_name_pkl_load()
    word_dict_len = dict()

    for item in l:
        name = item.lower()
        token_list = name.split(" ")
        token_length = len(token_list)
        pos = token_length - 1
        for token in token_list:
            if pos == 0:
                bin_pos = 0
            else:
                bin_pos = 1
            if word_dict_len.get(token):
                pos_dict = word_dict_len[token]
                if pos_dict.get(bin_pos):
                    word_dict_len[token][bin_pos] = pos_dict[bin_pos]+1
                else:
                    word_dict_len[token][bin_pos] = 1
            else:
                pos_dict = dict()
                pos_dict[bin_pos] = 1
                word_dict_len[token] = pos_dict
            pos -= 1
    pickle.dump(word_dict_len, open("s_subloc_blr_dict_v1_back.pkl", "w"))


def calc_sum(pos_dict):
    sum = 0
    for key in pos_dict.keys():
        sum += pos_dict[key]

    return sum


def read_scoring_file(addr):
    l = pickle.load(open("word_dict_len.pkl", "r"))
    addr_list = addr.split(" ")
    score = []
    tot_count = []
    pos = 1
    ans = 0
    for item in addr_list:
        if l.get(item):
            pos_dict = l[item]
            tot_count.append(calc_sum(pos_dict))
            if pos_dict.get(pos):
                score.append(pos_dict[pos])
                ans += (pos_dict[pos]*100)/calc_sum(pos_dict)
            else:
                score.append(0)
                ans += 0
        else:
            tot_count.append(0)
            score.append(0)
            ans += 0
        pos += 1
    return score,tot_count,ans


def read_scoring_v1_back_file(addr,occ):
    l = pickle.load(open("word_dict_len_v1_back.pkl", "r"))
    addr_list = addr.split(" ")
    score = []
    tot_count = []
    pos = len(addr_list)-1
    ans = 0
    for item in addr_list:
        if pos == 0:
            bin_pos = 0
        else:
            bin_pos = 1

        if l.get(item):
            pos_dict = l[item]
            tot_count.append(calc_sum(pos_dict))
            if pos_dict.get(bin_pos):
                score.append(pos_dict[bin_pos])
                ans += (pos_dict[bin_pos]*10000)/occ[bin_pos]
            else:
                score.append(0)
                ans += 0
        else:
            tot_count.append(0)
            score.append(0)
            ans += 0
        pos -= 1
    return score,tot_count,ans


def find_occ(file_name):
    l = pickle.load(open(file_name, "r"))

    key_list = l.keys()
    occ0 = 0
    occ1 = 0
    for item in key_list:
        key_dict = l[item]
        if key_dict.get(0):
            occ0 += key_dict[0]
        if key_dict.get(1):
            occ1 += key_dict[1]
        # print key_dict
        # break
    return occ0, occ1


def find_bldg_name():
    # bldg_name_pkl_dump()
    occ0, occ1 = find_occ()
    occ = []
    occ.append(occ0)
    occ.append(occ1)

    while 1:
        inp_addr = raw_input("input address- ")
        if inp_addr == "0":
            break
        l = []
        inp_addr = re.sub('[,]', ' ', inp_addr)
        inp_addr = inp_addr.lower()
        max_score = 0
        addr_list = inp_addr.split(" ")
        len_addr = len(addr_list)
        for idx in range(0, len_addr, 1):
            addr = str(addr_list[idx])
            # print addr
            for idy in range(idx+1, idx+4, 1):
                if idy > len_addr-1:
                    break
                addr = str(addr) + " " + str(addr_list[idy])
                x, y, score = read_scoring_v1_back_file(addr, occ)
                # print addr_list[idy]

                tup = (addr, int(score))
                l.append(tup)

                # sorted(l, key=lambda x:x[1])
                # print l
                # print addr + " " + str(score)
        addr = inp_addr
        x, y, score = read_scoring_file(addr)
        print x,y
        # print score

        print get_score(addr)
        l = sorted(l, reverse=True, key=lambda x:x[1])
        print l
        print "---"

# create_scoring_file_v1_back()
# find_bldg_name()


def loc_pkl_dump(url, file_name):
    resp = requests.get(url)
    result = resp.json()
    print resp.url
    doc_list = result['response']['docs']
    l = []
    # print doc_list
    for item in doc_list:
        names = item['ALT_NAMES']
        for name in names:
            l.append(name)

    pickle.dump(l, open(file_name, "w"))


def build_pkl_file():
    url = "http://fms-solr-db-001.nm.flipkart.com:8983/solr/fk-ekl-mmi-mapsearch/select?q=DOCTYPE:S_Sublocality_region&wt=json&fq=CITY_ID:11353&rows=567"
    file_name = "s_sublocality_blr_list.pkl"
    loc_pkl_dump(url, file_name)


def read_scoring_v1_file(addr, file_name):
    occ0, occ1 = find_occ(file_name)
    occ = []
    occ.append(occ0)
    occ.append(occ1)
    l = pickle.load(open(file_name, "r"))
    addr_list = addr.split(" ")
    score = []
    tot_count = []
    pos = len(addr_list)-1
    ans = 0
    for item in addr_list:
        if pos == 0:
            bin_pos = 0
        else:
            bin_pos = 1

        if l.get(item):
            pos_dict = l[item]
            tot_count.append(calc_sum(pos_dict))
            if pos_dict.get(bin_pos):
                score.append(pos_dict[bin_pos])
                ans += (pos_dict[bin_pos]*10000)/occ[bin_pos]
            else:
                score.append(0)
                ans += 0
        else:
            tot_count.append(0)
            score.append(0)
            ans += 0
        pos -= 1
    return score,tot_count,ans


def predict_top_location(doctype):
    # bldg_name_pkl_dump()
    if doctype == "bldg":
        file_name = "word_dict_len_v1_back.pkl"
    if doctype == "s_sub_loc":
        file_name = "s_subloc_blr_dict_v1_back.pkl"
    while 1:
        inp_addr = raw_input("input address- ")
        if inp_addr == "0":
            break
        l = []
        inp_addr = re.sub('[,]', ' ', inp_addr)
        inp_addr = inp_addr.lower()
        max_score = 0
        addr_list = inp_addr.split(" ")
        len_addr = len(addr_list)
        for idx in range(0, len_addr, 1):
            addr = str(addr_list[idx])
            # print addr
            for idy in range(idx+1, idx+4, 1):
                if idy > len_addr-1:
                    break
                addr = str(addr) + " " + str(addr_list[idy])
                x, y, score = read_scoring_v1_file(addr, file_name)
                # print addr_list[idy]
                print addr
                print x,y
                tup = (addr, int(score))
                l.append(tup)

                # sorted(l, key=lambda x:x[1])
                # print l
                # print addr + " " + str(score)
        addr = inp_addr
        # x, y, score = read_scoring_file(addr)
        # print x,y
        # print score

        # print get_score(addr)
        l = sorted(l, reverse=True, key=lambda x:x[1])
        print l
        print "---"


def get_top_prediction(inp_addr, doctype):
    if doctype == "bldg":
        file_name = "word_dict_len_v1_back.pkl"
    if doctype == "s_sub_loc":
        file_name = "s_subloc_blr_dict_v1_back.pkl"
    l = []
    inp_addr = re.sub('[,]', ' ', inp_addr)
    inp_addr = inp_addr.lower()
    addr_list = inp_addr.split(" ")
    len_addr = len(addr_list)
    for idx in range(0, len_addr, 1):
        addr = str(addr_list[idx])
        # print addr
        for idy in range(idx+1, idx+4, 1):
            if idy > len_addr-1:
                break
            addr = str(addr) + " " + str(addr_list[idy])
            x, y, score = read_scoring_v1_file(addr, file_name)
            tup = (addr, int(score))
            l.append(tup)

    l = sorted(l, reverse=True, key=lambda x:x[1])
    return l

# predict_top_location("s_sub_loc")