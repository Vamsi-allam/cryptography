# Implementation of Simplified DES Decryption
def Fk(k, sk):
 return (k & 0xF0) ^ ((sk[((k >> 3) & 0x02) | (k & 0x01)] & 0x0F) << 4) | (k 
& 0x0F) ^ sk[((k >> 1) & 0x02) | ((k >> 2) & 0x01)]
def switch(k):
 return (k & 0x0F) << 4 | (k >> 4)
def sdes_decryption(key, ciphertext):
 sk = [None] * 4
 sk[0] = (key >> 7) & 0x03
 sk[1] = (key >> 5) & 0x03
 sk[2] = (key >> 3) & 0x03
 sk[3] = (key >> 1) & 0x03
 return switch(Fk(switch(Fk(ciphertext, sk)), sk))
key= 0b1010011100
ciphertext = 0b1100011
decrypted_text = sdes_decryption(key, ciphertext)

print("Decrypted text:", bin(decrypted_text))
