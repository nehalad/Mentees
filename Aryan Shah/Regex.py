import re
import os
from collections import Counter
import numpy as np

with open('email.txt', 'r') as myfile:
    data=myfile.read().replace('\n', ' ')

myRegularExpression =r"(\b(\d{3}[-\.\s]??\d{3}[-\.\s]??\d{4})\b|\b(\(\d{3}\)\s*\d{3}[-\.\s]??\d{4})\b|\b(\d{3}[-\.\s]??\d{4})\b)"
stringTotest="My name is Rupin  and my email is rupin@curiositygym.com and aryan.shah@dbis.edu.in"
a=re.findall(myRegularExpression, data)
print(a)

#words=data.split(" ")
#counts = Counter(words).most_common(20)
#print(counts)
#labels, values = zip(counts[0].items())
##
### sort your values in descending order
##indSort = np.argsort(values)[::-1]
##
### rearrange your data
##labels = np.array(labels)[indSort]
##values = np.array(values)[indSort]
##
##indexes = np.arange(len(labels))
##
##bar_width = 0.35
##
##plt.bar(indexes, values)
##
### add labels
##plt.xticks(indexes + bar_width, labels)
##plt.show()
