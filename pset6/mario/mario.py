from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n < 9 and n > 0:
        break

for i in range(1,n+1):
    for c in range(n-i):
        print(" ", end = "")
    
    for a in range(i):
        print("#", end = "")
    print("  ", end = "")    
    
    
    for a in range(i):
        print("#", end = "")
        
    print("")