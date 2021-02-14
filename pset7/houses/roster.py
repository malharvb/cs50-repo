from sys import argv, exit
from cs50 import SQL

if len(argv) != 2:
    print("Usage Problem")
    exit(1)


db = SQL("sqlite:///students.db")
house = argv[1]
if  house == "Gryffindor" or house == "Slytherin" or house == "Ravenclaw" or house == "Hufflepuff":
    data = db.execute("SELECT first,middle,last,birth FROM students WHERE house = ? ORDER BY last, first;", house)

    for value in data:
        if value["middle"] == None:
            print(f"{value['first']} {value['last']}, born {value['birth']}")
        else:
            print(f"{value['first']} {value['middle']} {value['last']}, born {value['birth']}")
else:
    print("Usage Problem")
