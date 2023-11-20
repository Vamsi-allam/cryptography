# Implement the Encryption and Decryption of Row Transposition.
# Key: 4 3 1 2 5 6 7
# Plaintext: a t t a c k po s t p o n ed u n t i l tw o a m x y z
# Ciphertext: TTNAAPTMTSUOAODWCOIXKNLYPETZ

def encrypt(plain_text, key):
    cipher_text = ""
    col = len(key)
    row = len(plain_text) // col
    if len(plain_text) % col:
        row += 1
    matrix = [['' for _ in range(col)] for __ in range(row)]
    for i in range(len(plain_text)):
        matrix[i // col][i % col] = plain_text[i]
    for k in key:
        for r in range(row):
            if matrix[r][k-1]:
                cipher_text += matrix[r][k-1]
    return cipher_text
def decrypt(cipher_text, key):
    plain_text = ""
    col = len(key)
    row = len(cipher_text) // col
    if len(cipher_text) % col:
        row += 1
    matrix = [['' for _ in range(col)] for __ in range(row)]
    c = 0
    for k in key:
        for r in range(row):
            if c < len(cipher_text):
                matrix[r][k-1] = cipher_text[c]
                c += 1
    for r in range(row):
        for k in range(col):
            if matrix[r][k]:
                plain_text += matrix[r][k]
    return plain_text
key = [4, 3, 1, 2, 5, 6, 7]
plain_text = "ATTACKPOSTPONEDUNTILTWOAMXYZ"
cipher_text = encrypt(plain_text, key)
print("Cipher Text: ", cipher_text)
decrypted_text = decrypt(cipher_text, key)
print("Decrypted Text: ", decrypted_text) 
