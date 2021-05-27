import sys # used for argv parsing
import csv # used for the csv files

# exits if argument is incorrect
if len(sys.argv) != 3:
    sys.exit("Bad argument")

# allocating names to the files parsed through the argument
database = sys.argv[1]
sequence = sys.argv[2]

STR = [] # STR is the strands of STRs in a list
people = {} # dictionary of people and their STR numbers
persons = -1
# STR value allocation loop
with open(database) as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    linecount = 0
    for row in reader:
        persons += 1
        if linecount == 0:
            STR = row[1:]
            linecount += 1
            
# not sure how to allocate values for str list and people list without doing csvreader twice
# this is the people loop
with open(database) as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    next(reader)
    people = {row[0]:row[1:] for row in reader}

# this is how many dna str's there are. i iterate over that in loops later
strands = len(STR)    

# opening the sequence and storing into memory
dna = []
dna = open(sequence, 'r').read()

# array that puts how many times any one strand is in the dna sequence
i = 0
countArray = []
while i < strands:
    j = 0
    count = 0
    maxstr = -1;
    while j < len(dna):
        strcheck = dna[j:len(STR[i]) + j]
        if strcheck == STR[i]:
            j += len(STR[i])
            count += 1
            maxstr = max(maxstr, count)
        else:
            count = 0
            j += 1
    countArray.append(maxstr)
    if j == len(dna):
        i += 1

# here is a string that converts the final result array into strings, since i couldn't figure out how to conver the dictionary's values into integers :pensive:
l = 0
while l < strands:
    countArray[l] = str(countArray[l])
    l += 1


# iterating over strands again to see if they match with values in the people arrays and then printing the match 
k = 0
while k < persons:
    if list(people.values())[k] == countArray:
        print(list(people.keys())[k])
        exit(0) # exits program when match is found
    k += 1

# if we have gone over every person and there is no match...
print("No match")