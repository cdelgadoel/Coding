def toBinary(letter):
    num = ord(letter)
    resp = ''
    while num > 0:
        if num & 1:
            resp = '1'+resp
        else:
            resp = '0'+resp
        num>>=1
    return resp

for letter in 'InternetOfThings':
    print(toBinary(letter))