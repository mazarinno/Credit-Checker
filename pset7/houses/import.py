import sys
import csv
import cs50
# checking length of arguments, quitting if incorrect
if len(sys.argv) != 2:
    sys.exit("Bad argument")
# putting sysargv two's name into mem to call later
characters = sys.argv[1]
# calling db into mem
db = cs50.SQL("sqlite:///students.db")
# open characters.csv, read and assign names for each row
with open(characters, "r") as characters:
    reader = csv.DictReader(characters)

    for row in reader:
        # put names in array, check length to see if middle name exists or not
        name = row['name'].split()
        if len(name) == 3:
            first = name[0]
            middle = name[1]
            last = name[2]
        else:
            first = name[0]
            middle = None
            last = name[1]
        house = row['house']
        birth = row['birth']
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)