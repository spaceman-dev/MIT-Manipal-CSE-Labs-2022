from __future__ import print_function
import sys
import pandas as pd
df = pd.read_csv('covid_19_data.csv')
country = df['Deaths']
for word in country:
    print(word,'\t',1)