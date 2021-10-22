# function to return maximum iterations of a perticular pattern in a sequence

import csv
from sys import exit
from sys import argv


def counter(s, o):
    max = 0
    t = 1
    l = len(s)

    s = s[(s.find(o) + len(o)):]
    while True:
        if s.find(o) == 0:
            t += 1
            s = s[len(o):]
        else:
            if t > max:
                max = t
            t = 1
            s = s[(s.find(o) + len(o)):]

        if s == "":
            break
    return str(max)
    

#
if len(argv) != 3:
    print("Usage error: dna.py database/<name of data base>.csv sequence/<name of file>.txt")
    exit()

#
with open(argv[2], "r") as personDNA:
    readDNA = csv.reader(personDNA)
    for row in readDNA:
        dna = row
        break

#
dna = str(dna)

#
with open(argv[1], "r") as database:
    read_database = csv.reader(database)
    for row in read_database:
        lists = row
        break

#
elements = 0
for element in lists:
    elements += 1

#
storage = []
for i in range(elements):
    storage.append(counter(dna, lists[i]))


# print(storage)
with open(argv[1], "r") as database:
    read_database = csv.reader(database)
    next(read_database)
    for row in read_database:
        if elements == 4:
            if row[1] == storage[1] and row[2] == storage[2] and row[3] == storage[3]:
                print(f"{row[0]}")
                exit()
        elif elements == 9:
            if row[1] == storage[1] and row[2] == storage[2] and row[3] == storage[3] and row[4] == storage[4] and row[5] == storage[5] and row[6] == storage[6] and row[7] == storage[7] and row[8] == storage[8]:
                print(f"{row[0]}")
                exit()
    print("No match")