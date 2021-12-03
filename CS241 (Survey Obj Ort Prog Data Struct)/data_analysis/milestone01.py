import pandas as pd
import matplotlib.pyplot as plt
# from pandas.core.frame import DataFrame
import seaborn as sns
import os

os.chdir('c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\nba_basketball_data')

# Merge datasets before getting started.
master = pd.read_csv('basketball_master.csv')
players = pd.read_csv('basketball_players.csv')

nba = pd.merge(players, master, how = 'left', left_on = 'playerID', right_on = 'bioID')

# PART I - Step 01:
# Calculate the mean and median number of points scored. (In other words, each
# row is the amount of points a player scored during a particular season.
# Calculate the median of these values. The result of this is that we have the
# median number of points players score each season.)
mean = nba.points.mean()
median = nba.points.median()

print('\nStep 01\n')
print(f'mean: {mean:.2f}')
print(f'median: {median}')
print('\n')

# PART I - Step 02:
# Determine the highest number of points recorded in a single season. Identify
# who scored those points and the year they did so.

# Source: https://stackoverflow.com/questions/52396477/printing-a-pandas-dataframe-without-row-number-index/52396530

max = nba[['playerID', 'useFirst', 'lastName', 'year', 'points']].sort_values('points', ascending = False).head(1)

print('Step 02\n')
print(max)
print()
print(f'{max.useFirst.to_string(index = False)} {max.lastName.to_string(index = False)} scored {max.points.to_string(index = False)} points in {max.year.to_string(index = False)}.')
print()

# PART I - Step 03:
# Produce a boxplot that shows the distribution of total points, total assists,
# and total rebounds (each of these three is a separate box plot, but they can
# be on the same scale and in the same graphic).
plots = pd.DataFrame(nba, columns = ['points', 'assists', 'rebounds'])

sns.boxplot(data = plots)

# could also be done like this
# sns.boxplot(data = nba[['points', 'assists', 'rebounds']])

# plt.savefig() has to be called BEFORE plt.show() otherwise the image will be blank
plt.savefig('boxplot_reboundsPerGame.png') # save the file

plt.show() # plot boxplot


# PART I - Step 04:
# Produce a plot that shows how the number of points scored has changed over
# time by showing the median of points scored per year, over time. The x-axis
# is the year and the y-axis is the median number of points among all players
# for that year.
nba_grouped_year = nba[['points', 'year']].groupby('year').median()

# print(nba[['year', 'useFirst', 'lastName', 'points', 'GP', 'points']].sort_values('points', ascending = False).head(10))

nba_grouped_year = nba_grouped_year.reset_index()
nba_grouped_year = nba_grouped_year[nba_grouped_year['points'] > 0]
sns.regplot(data = nba_grouped_year, x = 'year', y = 'points').set_title("Median points per year")

plt.savefig('facet_pointsPerYear.png') # save the file

plt.show()
