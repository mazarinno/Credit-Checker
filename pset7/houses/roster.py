import sys
import csv
import cs50
# checking length of arguments, quitting if incorrect
if len(sys.argv) != 2:
    sys.exit("Bad argument")

house = sys.argv[1]
# db query and execute, SQL orders by last then first name
db = cs50.SQL("sqlite:///students.db")
rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)
# spaced out these print functions for readability, and since those added new lines, i used this sys function to keep the format without the new lines
for row in rows:
    sys.stdout.write(row['first'] + ' ')
    if row['middle'] != None:
        sys.stdout.write(row['middle'] + ' ')
    sys.stdout.write(row['last'] + ', ' + 'born ')
    print(row['birth'])