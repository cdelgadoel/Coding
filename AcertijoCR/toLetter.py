for _ in range(16):
    binary = input()
    ascii = 0
    for num in binary:
        ascii *= 2
        if num == '1':
            ascii += 1
    print(chr(ascii), end = "")
print("")