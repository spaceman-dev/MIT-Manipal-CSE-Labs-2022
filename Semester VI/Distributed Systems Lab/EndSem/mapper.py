import sys
import pandas as pd

# Heart Disease Dataset
df = pd.read_csv('countries 1.csv')
df = df.dropna()
words1 = list(df['country'].values)
words2 = list(df['population'].values)

# Mapper output
for (word1, word2) in zip(words1, words2):
    print(f'{word1} \t {word2}')