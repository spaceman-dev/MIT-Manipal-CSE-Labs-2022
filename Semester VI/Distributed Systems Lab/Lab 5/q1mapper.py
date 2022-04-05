import sys
import pandas as pd
df = pd.read_csv('heart_disease_data.csv')
age = df['age']
for word in age:
    print(word, "\t", 1)