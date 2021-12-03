import pandas

census_data = pandas.read_csv("c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\census.csv")
mean = census_data.iloc[:, [2]].mean()
median = census_data.iloc[:, [2]].median()
max = census_data.iloc[:, [2]].max()

# census_data = pandas.read_csv("c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\census.csv", header = None)
# mean = census_data[2].mean()
# median = census_data[2].median()
# max = census_data[2].max()

print(mean)
print(median)
print(max)
print(f"Median age: {median[0]:.2f}")
