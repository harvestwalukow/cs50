text = input("Text: ").lower()

occur = [".", "!", "?"]
letters = 0
words = 1
sentences = 0

for c in text:
    if c.isalpha():
        letters += 1
    if c == " ":
        words += 1
    if c in occur:
        sentences += 1

L = (letters / words) * 100
S = (sentences / words) * 100

index = 0.0588 * L - 0.296 * S - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
