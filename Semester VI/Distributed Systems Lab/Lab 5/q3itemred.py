import fileinput
transactionsCount = 0
salesTotal = 0
for line in fileinput.input():
    data = line.strip().split("\t")
    if (len(data) != 2):
        continue
    currentKey, currentValue = data
    transactionsCount += 1
    salesTotal += float(currentValue)
print (transactionsCount, "\t", salesTotal)