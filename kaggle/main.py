import pandas as pd

test_csv = 'titanic/test.csv'
train_csv = 'titanic/train.csv'

data = pd.read_csv(train_csv)


print(data.head())
print(data.describe())
