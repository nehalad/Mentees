# -*- coding: utf-8 -*-

import requests
import json

# **********************************************
# *** Update or verify the following values. ***
# **********************************************

# Replace the accessKey string value with your valid access key.
accessKey = 'b5c5d1bf217c490fbca8ce6835d2d785'

# Replace or verify the region.
#
# You must use the same region in your REST API call as you used to obtain your access keys.
# For example, if you obtained your access keys from the westus region, replace 
# "westcentralus" in the URI below with "westus".
#
# NOTE: Free trial access keys are generated in the westcentralus region, so if you are using
# a free trial access key, you should not need to change this region.
uri = 'https://westcentralus.api.cognitive.microsoft.com/text/analytics/v2.0/keyphrases'


def GetLanguage (documents):
    "Detects the languages for a set of documents and returns the information."

    headers = {'Ocp-Apim-Subscription-Key': accessKey}
    body = json.dumps (documents)
    r=requests.post(uri, headers=headers, data=body)    
    
    print(r.json())

with open('email.txt', 'r') as myfile:
    data=myfile.read().replace('\n', ' ')
    
data=data.replace("\"", "")
data=data.replace("\'", "")
data=data.replace("\\", "")
data=data.replace("\/", "")
data=data.replace(":", "")
data=data.replace("<", "")
data=data.replace(">", "")    

documents = '{ "documents": [{ "id": "1", "text": "'+data+'" }]}'

print(documents)
documents=json.loads(documents)

print ('Please wait a moment for the results to appear.\n')

GetLanguage (documents)
#print (json.dumps(json.loads(result), indent=4))
