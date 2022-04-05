from operator import itemgetter
import sys
odd_count = 0
even_count = 0
for line in sys.stdin:
    line = line.strip()
    num = line.split()
    for currnum in num:
        try:
            odd_count = int(odd_count)
            even_count = int(even_count)
            currnum = int(currnum)
        except ValueError:
            continue
        if currnum%2 == 0:
            even_count += 1
        else:
            odd_count += 1
print ('%s odd and %s even'%(odd_count, even_count))