import numpy as np
import pandas as pd
dataframe = pd.read_csv("covid_19_data.csv")
countryName = dataframe["Country/Region"]
peakCases = dataframe["Confirmed"]
for x in range(len(countryName)):
    print("%s\t%d" %(countryName[x],peakCases[x]))