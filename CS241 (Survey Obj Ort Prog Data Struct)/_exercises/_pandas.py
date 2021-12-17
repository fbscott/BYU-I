import numpy as np
import pandas as pd

# source:
# http://www.gregreda.com/2013/10/26/intro-to-pandas-data-structures/

# lists
s = pd.Series([1, 3, 5, np.nan, 6, 8])
s2 = pd.Series([7, 'Heisenberg', 3.14, -1789710578, 'Happy Eating!'])

print(s)
print('\n')
print(s2)
print('\n')

# dictionaries
d = {
    'Chicago': 1000,
    'New York': 1300,
    'Portland': 900,
    'San Francisco': 1100,
    'Austin': 450,
    'Boston': None
}

cities = pd.Series(d)

# table
print(cities)
print('\n')

less_than_1000 = cities < 1000

print(less_than_1000)
print('\n')
print(cities[less_than_1000])
print('\n')

# round to zero (0) decimals
print(f"{cities['Austin']:.0f}")
print('\n')

data = {
    'year': [2010, 2011, 2012, 2011, 2012, 2010, 2011, 2012],
    'team': ['Bears', 'Bears', 'Bears', 'Packers', 'Packers', 'Lions', 'Lions', 'Lions'],
    'wins': [11, 8, 10, 15, 11, 6, 10, 4],
    'losses': [5, 8, 6, 1, 5, 10, 6, 12]
}
football = pd.DataFrame(data, columns=['year', 'team', 'wins', 'losses'])

print(football)
print('\n')

from_csv = pd.read_csv('c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\mariano-rivera.csv')
print(from_csv.head())
print('\n')

cols = ['num', 'game', 'date', 'team', 'home_away', 'opponent',
        'result', 'quarter', 'distance', 'receiver', 'score_before',
        'score_after']
no_headers = pd.read_csv('c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\peyton-passing-TDs-2012.csv', sep=',', header=None,
                         names=cols)
print(no_headers.head())
print('\n')
