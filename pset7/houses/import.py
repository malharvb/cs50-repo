from cs50 import SQL
from sys import argv, exit
from csv import reader, DictReader

if len(argv) != 2:
    print("Usage Problem")
    exit(1)

db = SQL("sqlite:///students.db")
#db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

with open(argv[1], 'r') as students:
    
    reader = DictReader(students)
    
    for row in reader:
       
        name = row["name"].split()
        
        if len(name) == 3:
            first = name[0]
            middle = name[1]
            last = name[2]
        else:
            first = name[0]
            middle = None
            last = name[1]
            
        house = row["house"]    
        birth = row["birth"]
            
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)", first, middle, last, house, birth)
            