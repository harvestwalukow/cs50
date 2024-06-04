number = int(input("Number: "))
digits = list(str(number))

digits_reverse = []
for i in digits[::-1]:
    digits_reverse.append(i)

# Luhn's Algorithm
multiply = []
for i in range(1, len(digits), 2):
    multiply.append(str(2 * int(digits_reverse[i])))

for i in range(len(multiply)):
    if len(multiply[i]) == 2:
        multiply.append(multiply[i][0])
        multiply.append(multiply[i][1])
        multiply[i] = 0

sum = 0
for i in range(len(multiply)):
    sum += int(multiply[i])

not_multiply = []
for i in range(0, len(digits), 2):
    not_multiply.append(str(int(digits_reverse[i])))
for i in range(len(not_multiply)):
    sum += int(not_multiply[i])

# Check validity and type
second_digit_mastercard = ["1", "2", "3", "4", "5"]
if sum % 10 == 0:
    if len(digits) == 15 and (digits[0] == "3" and (digits[1] == "4" or digits[1] == "7")):
        print("AMEX")
    elif len(digits) == 16 and (digits[0] == "5" and digits[1] in second_digit_mastercard):
        print("MASTERCARD")
    elif len(digits) == 13 or len(digits) == 16 and digits[0] == "4":
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
