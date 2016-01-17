# -*- coding: cp1250 -*-
from pygooglechart import PieChart3D
import re

n = input("Podaj liczbe danych: \n")

with open ("lotr.txt", "r") as myfile:
    data = myfile.read().replace('\n', '').replace(',',' ').replace('"','').replace('\'','')
    data = data.replace('\\',' ').replace('/',' ').replace(':',' ')
    data = data.replace('[',' ').replace(']',' ').replace('(',' ').replace(')',' ').replace(';',' ')
    data = data.replace('   ',' ').replace('  ',' ').replace('\t','').replace('\x96','')  
sentences = data.split('.')
sentencesLens = []
for sentence in sentences:
    sentencesLens.append((len(sentence),sentence))

topSentences = []
topLens = []
for pair in sorted(sentencesLens,reverse = True)[:n]:
    topLens.append(pair[0])
    topSentences.append(pair[1][:20]+'...')


words = sorted(data.replace('.','').lower().split(' '))
uniqueWords = []
for word in words:
    if word not in uniqueWords:
        uniqueWords.append(word)
wordsfreq = []
for word in uniqueWords:
    wordsfreq.append((words.count(word),word))

topWords = []
topOccurences = []
for pair in sorted(wordsfreq)[:n]:
    topOccurences.append(pair[0])
    topWords.append(pair[1])

chart = PieChart3D(800,300)
chart2 = PieChart3D(800,300)

chart.add_data(topLens)
chart2.add_data(topOccurences)

chart.set_pie_labels(topSentences)
chart2.set_pie_labels(topWords)

print chart.get_url()
print('\n\n\n')
print chart2.get_url()

input('...')

