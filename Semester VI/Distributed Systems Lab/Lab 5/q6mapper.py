import sys
def f(a):
    return 4.0/(1.0 + a*a)
for line in sys.stdin:
    line = line.strip()
    words = line.split()
    n = int(words[0])
    delta = 1.0 / n
    for i in range(0, n):
        print("1\t%1.10f"%(f(i * delta)*delta))