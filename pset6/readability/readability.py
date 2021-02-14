from cs50 import get_string

s = get_string("Text: ")
s = s.lower()
words = 1
sent = 0
letters = 0

for i in range(len(s)):
    if s[i] == " ":
        words += 1
    elif s[i] == "." or s[i] == "!" or s[i] == "?":
        sent += 1
    elif s[i] >= "a" and s[i] <= "z":
        letters += 1




L = letters / words * 100
S = sent / words * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")