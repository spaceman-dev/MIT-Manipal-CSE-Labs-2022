import pandas as pd
import numpy as np
dataframe = pd.read_excel("German_Credit.xlsx")
x = dataframe["CreditAmount"]
y = dataframe["DurationOfCreditInMonths"]
for i in range(len(x)):
    print("{0}\t{1}".format(x[i],y[i]))