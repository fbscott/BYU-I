import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sb

data = pd.read_csv('c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\weather_year.csv')

# print(data)
# print(len(data))
# print(data.columns)
# print(data['EDT']) # get data by column
# print(data[['EDT', 'Max TemperatureF']]) # get data by for multiple columns
# print(data.EDT) # dot notation
# print(data.EDT.head()) # first 5 items
# print(data.EDT.head(10)) # first 10 items
# print(data['Max TemperatureF'].head())

# rename columns
data.columns = [
    "date", "max_temp", "mean_temp", "min_temp", "max_dew",
    "mean_dew", "min_dew", "max_humidity", "mean_humidity",
    "min_humidity", "max_pressure", "mean_pressure",
    "min_pressure", "max_visibilty", "mean_visibility",
    "min_visibility", "max_wind", "mean_wind", "min_wind",
    "precipitation", "cloud_cover", "events", "wind_dir"
]

# print(data)
# print(data.mean_temp.head())
# print(data.mean_temp.std()) # standard deviation
# print(data.std())

# plot stuff
# data.mean_temp.hist() # create histogram
sb.histplot(data.mean_temp)
plt.show() # plot historgram
