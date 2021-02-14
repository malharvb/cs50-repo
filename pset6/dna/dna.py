from csv import reader, DictReader
from sys import argv, exit

if(len(argv) != 3):
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

rows = []
results = []

with open(argv[1], 'r') as csvfile:
    info = reader(csvfile)
    sv = next(info)
    #print(sv)
    for row in info:
        rows.append(row)

with open(argv[2], 'r') as txt:
    data = txt.read()

    for c in range(1,len(sv)):
        count = 0
        max_count = 0
        consec = False
        for i in range(len(data)):
            # problem in this function mostly check
            if consec == False:
                j = i - len(sv[c])

            if data[i : i + len(sv[c])] == sv[c] and j == i - len(sv[c]):
                consec = True
                count+=1
                j = i
                #i = i + len(sv[c])
                if count > max_count:
                    max_count = count
            elif j + len(sv[c]) + 1 == i:
                consec = False
                count = 0


        #print(max_count)

        results.append(max_count)
        c+=1


#print(len(rows))
found = False
for i in range(len(rows)):
    r_c = 0
    for j in range(1,len(sv)):
        #print(rows[i][j])
        #print(results[j-1])
        if int(rows[i][j]) == results[j-1]:
            r_c += 1

            if r_c == len(sv)-1:
                print(rows[i][0])
                found = True


if found == False:
    print("No Match")