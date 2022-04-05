from __future__ import print_function
import sys
lastWord = None
sum = 0
for line in sys.stdin:
    word, count = line.strip().split('\t', 1)
    count = int(count)
    if(lastWord == None):
        lastWord = word
        sum = count
        continue
    if(word == lastWord):
        sum += count
    else:
        print(lastWord,'\t',sum)
        sum = count
        lastWord = word
if(lastWord == word):
    print(lastWord,'\t',sum)