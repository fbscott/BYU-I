import csv

# dictionary to hold the education level and counts
education_counts = {}

def get_education_counts(file):
    """hash function"""
    with open(file) as csv_file:

        rows = csv.reader(csv_file)

        for row in rows:

            # get the education level from the 4th column (index 3) of each row
            education_level = row[3]

            # if the education level is in the dictionary
            if education_level in education_counts:
                # add 1 to the existing value
                education_counts[education_level] += 1
            # if the education level is NOT in the dictionary
            else:
                # add it with a count of 1
                education_counts[education_level] = 1

        # loop through each key in the dictionary and print out its associated value
        for key in education_counts.keys():
            print(f"{education_counts[key]} -- {key}")

        csv_file.close()

def main():

    get_education_counts("c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\census.csv")

if __name__ == "__main__":
    main()
