# Implementation of RC4
def KSA(key):
 key_length = len(key)
 S = list(range(256))
 j = 0
 for i in range(256):
 j = (j + S[i] + key[i % key_length]) % 256
 S[i], S[j] = S[j], S[i] # swap
 return S
def PRGA(S):
 i = 0
 j = 0
 while True:
 i = (i + 1) % 256
 j = (j + S[i]) % 256
 S[i], S[j] = S[j], S[i] # swap
 K = S[(S[i] + S[j]) % 256]
 yield K
def RC4(key):
 S = KSA(key)
 return PRGA(S)
key = 'Key'
plaintext = 'Plaintext'
plaintext_bytes = [ord(c) for c in plaintext]
# Generate key stream
keystream = RC4([ord(c) for c in key])
ciphertext = [p ^ next(keystream) for p in plaintext_bytes]
print('Ciphertext:', ciphertext)
keystream = RC4([ord(c) for c in key])
decrypted = [c ^ next(keystream) for c in ciphertext]
print('Decrypted:', ''.join(map(chr, decrypted)))
