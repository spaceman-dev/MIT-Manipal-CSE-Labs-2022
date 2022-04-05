from operator import itemgetter 
import sys 
currentWord = None 
currentCount = 0 
word = None 
for line in sys.stdin: 
    line = line.strip() 
    word, count = line.split('\t', 1) 
    try: 
        count = int(count) 
    except ValueError: 
        continue 
    if(currentWord == word):
        currentCount += count 
    else: 
        if(currentWord):
            print('%s\t%s'%(currentWord, currentCount)) 
        currentCount = count 
        currentWord = word 
if (currentWord == word): 
    print('%s\t%s'%(currentWord, currentCount)) 