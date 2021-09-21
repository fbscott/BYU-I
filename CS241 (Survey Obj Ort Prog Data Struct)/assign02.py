import csv

###############################################################################
# GET FILE NAME
###############################################################################
def getFileName():
    return input("Please enter the data file: ")

###############################################################################
# READ FILE
###############################################################################
def readFile(file):
    count = 0
    sum = 0
    max_rate_str = ""
    min_rate_str = ""

    with open(file, newline = "") as csv_file:
        max_rate = 0
        min_rate = 1

        # sort by column header
        rates = csv.DictReader(csv_file, delimiter = ",")

        for row in rates:
            current_rate = float(row['comm_rate'])
            count += 1
            sum += current_rate

            if min_rate > current_rate:
                min_rate = current_rate
                min_rate_str = str(f"{row['utility_name']} ({row['zip']}, {row['state']}) - ${current_rate}")

            if max_rate < current_rate:
                max_rate = current_rate
                max_rate_str = str(f"{row['utility_name']} ({row['zip']}, {row['state']}) - ${current_rate}")

        csv_file.close()

    average = sum / count

    return (average, max_rate_str, min_rate_str)

###############################################################################
# MAIN
###############################################################################
def main():

    file_name = getFileName()

    (average_rate, high_str, low_str) = readFile(file_name)

    print(f"\nThe average commercial rate is: {average_rate}\n")
    print(f"The highest rate is:\n{high_str}\n")
    print(f"The lowest rate is:\n{low_str}")

if __name__ == "__main__":
    main()
