import requests
import json
import bldg_name as bn
import pickle

def get_json(url):
    result = requests.get(url)
    solr_response = result.json()
    return solr_response


def get_addr_list(url):
    solr_response = get_json(url)
    response = solr_response['response']
    docs = response['docs']
    docs_length = len(docs)
    addr_list = list(k['addr1'] for k in docs if k.get('addr1'))
    return addr_list


def publish_result(doctype):
    addr_list = get_addr_list("http://localhost:8983/solr/extractor/select?q=city:Bangalore&wt=json&rows=170")
    l = []
    print len(addr_list)
    cnt = 0
    for addr in addr_list:
        predictions = bn.get_top_prediction(addr, doctype)
        # print addr
        # print predictions
        # print "----"
        l.append((addr, predictions))
        print cnt
        cnt += 1
    pickle.dump(l, open("publish_results.pkl", "w"))


def write_addr_predictions_file(file_name_read, file_name_write):
    l = pickle.load(open(file_name_read, "r"))
    target = open(file_name_write, "w")
    for item in l:
        addr = item[0]
        predictions = item[1]
        max_score = predictions[0][1]
        print max_score
        target.write(addr)
        target.write("\n")
        target.write("\n")
        target.write("Building prediciton with score : ")
        target.write("\n")
        target.write("---------------------------------------------")
        target.write("\n")
        for prediction in predictions:
            prediction_string = str(prediction[0]) + " -- " + str(prediction[1])
            target.write(prediction_string)
            target.write("\n")
        target.write("---------------------------------------------")
        target.write("\n")
        target.write("*********************************************")
        target.write("\n")
        target.write("\n")
    target.close()


if __name__=="__main__":
    # doctype = "bldg"
    # publish_result(doctype)
    write_addr_predictions_file("publish_results.pkl", "bldg_predictions.txt")