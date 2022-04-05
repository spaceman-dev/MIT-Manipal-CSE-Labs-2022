import pandas as pd
import numpy as np
def read_input(dataframe):
    for x in dataframe["age"]:
        yield x
def main(separator = "\t"):
    filename = input("Enter a filename: ")
    dataframe = pd.read_csv(filename)
    data = read_input(dataframe)
    for x in data:
        print("%s%s%d" %(x,separator,1))
if __name__ == "__main__":
    main()