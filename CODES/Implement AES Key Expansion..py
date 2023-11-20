# Implement AES Key Expansion.


from Crypto.Cipher import AES
from Crypto.Util import Counter
import os
def aes_key_expansion(key):
cipher = AES.new(key, AES.MODE_ECB)
iv = os.urandom(16) ctr = Counter.new(128)
cipher_ctr = AES.new(key, AES.MODE_CTR, counter=ctr)

return cipher, cipher_ctr

key = os.urandom(32) cipher, cipher_ctr =aes_key_expansion(key)
print("Cipher with expanded key:",cipher) 
print("Cipher with expanded key and CTR mode:",cipher_ctr)
