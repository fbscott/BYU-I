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

# PART II - Step 01:
# Some players score a lot of points because they attempt a lot of shots. Among
# players that have scored a lot of points, are there some that are much more
# efficient (points per attempt) than others?
grouped_points = nba[['fgMade', 'fgAttempted']].groupby('fgAttempted').median()

grouped_points = grouped_points.reset_index()
grouped_points = grouped_points[grouped_points['fgMade'] > 0]

# sns.regplot(data = grouped_points, x = 'fgAttempted', y = 'fgMade').set_title("Median attempts per year")
# plt.savefig('pt_2_step_1_facet_attempts_per_year.png') # save the file
# plt.show()

# PART II - Step 02:
# It seems like some players may excel in one statistical category, but produce
# very little in other areas. Are there any players that are exceptional across
# many categories?
# player_stats = pd.DataFrame(players, columns = ['year', 'points', 'rebounds'])
player_stats = pd.DataFrame({
    'Year': players.year,
    'Points': players.points,
    'Rebounds': players.rebounds
})
player_stats.groupby(['Year']).mean()
# player_stats = players[['year', 'points', 'rebounds']].groupby('year').sum()

# print(player_stats.head())
# print(player_stats.describe())

df = pd.DataFrame({
    'Day': ['Mon', 'Tue', 'Wed', 'Thur', 'Fri'],
    'Morning': [44, 46, 49, 59, 54],
    'Evening': [33, 46, 50, 49, 60]
})

# print(player_stats.year)
# print(df.Day)

# #set seaborn plotting aesthetics
# sns.set(style = 'white')

# #create stacked bar chart
# df.set_index('Day').plot(kind = 'bar', stacked = True, color = ['steelblue', 'red'])

# plt.show()

# PART II - Step 03:
# Much has been said about the rise of the three-point shot in recent years. It
# seems that players are shooting and making more three-point shots than ever.
# Recognizing that this dataset doesn't contain the very most recent data, do
# you see a trend of more three-point shots either across the league or among
# certain groups of players? Is there a point at which popularity increased
# dramatically?
three_pointers_over_time = nba[['threeMade', 'year']].groupby('year').sum()

three_pointers_over_time = three_pointers_over_time.reset_index()
three_pointers_over_time = three_pointers_over_time[three_pointers_over_time['threeMade'] > 0]

# sns.regplot(data = three_pointers_over_time, x = 'year', y = 'threeMade').set_title("Median three-pointers made per year")
# plt.savefig('pt_2_step_3_facet_three_pointers_made_per_year.png') # save the file
# plt.show()

# PART III - Step 01:
# Many sports analysts argue about which player is the GOAT (the Greatest Of
# All Time). Based on this data, who would you say is the GOAT? Provide
# evidence to back up your decision.
#create DataFrame
df = pd.DataFrame({'Day': ['points', 'fgMade', 'rebounds', 'steals', 'minutes'],
                   'player 1': [1, 1, 1, 1, 1],
                   'player 2': [2, 2, 2, 2, 2],
                   'player 3': [3, 3, 3, 3, 3],
                   'player 4': [4, 4, 4, 4, 4],
                   'player 5': [5, 5, 5, 5, 5],
                   'player 6': [6, 6, 6, 6, 6],
                   'player 7': [7, 7, 7, 7, 7],
                   'player 8': [8, 8, 8, 8, 8],
                   'player 9': [9, 9, 9, 9, 9],
                   'player 10': [10, 10, 10, 10, 10]})

#view DataFrame
print(df)

#set seaborn plotting aesthetics
# sns.set(style='white')

#create stacked bar chart
# df.set_index('Day').plot(kind='bar', stacked=True, color=['steelblue', 'red'])
# plt.show()

# PART III - Step 02:
# The biographical data in this dataset contains information about home towns,
# home states, and home countries for these players. Can you find anything
# interesting about players who came from a similar location?


# PART III - Step 03:
# Find something else in this dataset that you consider interesting. Produce a
# graph to communicate your insight.

