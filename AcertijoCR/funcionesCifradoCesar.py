def caesar_cipher(file_path, offset=94):
    # Read the input file
    with open(file_path, 'r') as file:
        original_text = file.read()

    # Apply Caesar cipher
    ciphered_text = ''
    for char in original_text:
        if 48 <= ord(char) <= 122:
            ciphered_char = chr(((ord(char) - 48 + offset) % (123-48)) + 48)
        else:
            ciphered_char = char
        ciphered_text += ciphered_char

    # Write the ciphered text to a new file
    output_file_path = file_path[:-4] + '_cifrada.txt'
    with open(output_file_path, 'w') as file:
        file.write(ciphered_text)

    return output_file_path

def caesar_decipher(file_path, offset=94):
    # Read the input file
    with open(file_path, 'r') as file:
        ciphered_text = file.read()

    # Apply Caesar decipher
    deciphered_text = ''
    for char in ciphered_text:
        # Only decipher printable ASCII characters (32-126)
        if 48 <= ord(char) <= 122:
            deciphered_char = chr(((ord(char) - 48 - offset) % (123-48)) + 48)
        else:
            deciphered_char = char
        deciphered_text += deciphered_char

    # Write the deciphered text to a new file
    output_file_path = file_path[:-4] + '_descifrada.txt'
    with open(output_file_path, 'w') as file:
        file.write(deciphered_text)

    return output_file_path

#caesar_cipher('carta.txt')
#caesar_decipher('carta_cifrada.txt')