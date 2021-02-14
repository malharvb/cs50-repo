from cs50 import get_string

def main():
    n = get_string("Number: ")
    sum = 0
    val = False
    n = reverse(n)
    
    for i in range(len(n)):
        if i % 2 == 1:
            tmp = int(n[i]) * 2
            if tmp / 10 >= 1:
                k = int(tmp / 10)
                tmp = tmp % 10
                tmp = tmp + k
        else:
            tmp = int(n[i])
        sum = sum + tmp

    
    

    if sum % 10 == 0:
        if n[len(n)-1] == '3' and (n[len(n)-2] == '4' or n[len(n)-2] == '7') and len(n) == 15:
            print("AMEX")
        elif n[len(n)-1] == '5'and len(n) == 16 and (int(n[len(n)-2]) in range(1,6)):
            print("MASTERCARD")
        elif n[len(n)-1] == '4'and (len(n) == 13 or len(n) == 16):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")
    




def reverse(n): 
  str = "" 
  for i in n: 
    str = i + str
  return str

main()