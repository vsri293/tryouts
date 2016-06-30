import csv
import requests
import json
import re

addr1 = ""
addr2 = ""
city = ""
state = ""
pincode = ""
resp = requests.get("http://fms-bulk-sage-app.vip.nm.flipkart.com:8888/geocode")
payload = {'addr1':addr1, 'addr2':addr2, 'city': city, 'state': state, 'pincode': pincode}
cnt = 0


def remove(strip_list, addr):
    strip_addr = ""
    # print strip_list
    addr = str(addr)
    addr = re.sub('[.,]', ' ', addr)
    addr = addr.split(" ")
    for word in addr:
        tmp_word = word.lower()

        if tmp_word in strip_list:
            continue
        strip_addr += str(word)
        strip_addr += " "

    return strip_addr


def populate_stop_words(strip_list):
    strip_list.append('near')
    strip_list.append('paas')
    strip_list.append('behind')
    strip_list.append('opposite')
    strip_list.append('next')
    strip_list.append('to')
    strip_list.append('ke')
    strip_list.append('opp')
    strip_list.append(' ')
    return strip_list


def populate_address_words(strip_list, addr):
    addr = str(addr)
    addr = re.sub('[,]', ' ', addr)
    addr = addr.split(" ")
    for word in addr:
        tmp_word = word.lower()
        strip_list.append(tmp_word)
    return strip_list


with open('../../Downloads/golden_data.csv', 'rb') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        cnt += 1
        print row
        strip_list = []
        addr1 = row['addr1']
        addr2 = row['addr2']
        city = row['city']
        state = row['state']
        pincode = row['pincode']
        gcbm_type = "nothing"
        gcbm_name = "nothing"
        payload = {'addr1':addr1, 'addr2':addr2, 'city': city, 'state': state, 'pincode': pincode}
        resp = requests.get(url="http://fms-bulk-sage-app.vip.nm.flipkart.com:8888/geocode", params=payload)
        print resp.url
        resp = resp.json()
        if resp.get('results'):
            result = resp['results']
            if len(result) > 0:
                gcbm_dict = result[0]
                addr_list = gcbm_dict['address_components']
                if len(addr_list) > 0:
                    if addr_list[0].get('DOCTYPE'):
                        gcbm_type = addr_list[0]['DOCTYPE']
                    if addr_list[0].get('NAME'):
                        gcbm_name = addr_list[0]['NAME']

                strip_list = populate_address_words(strip_list, gcbm_dict['formatted_address'])


        for x in gcbm_name.lower().split(' '):
            strip_list.append(x)
        # strip_list.append(str(x) for x in gcbm_name.lower().split(' '))
        strip_list = populate_stop_words(strip_list)
        strip_addr = remove(strip_list, row['addr_full'])
        print gcbm_type
        print strip_addr
        print "----"
        if cnt == 10:
            break

