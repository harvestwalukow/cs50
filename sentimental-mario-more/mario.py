while True:
    try:
        height = int(input("Height: "))
        if 0 < height < 9:
            break
    except ValueError:
        print("Input a number.")

for i in range(1, height + 1):
    print(f"{' ' * (height-i) + '#' * i + '  ' + '#' * i}")
