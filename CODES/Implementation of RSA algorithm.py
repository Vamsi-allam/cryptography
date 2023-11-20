# Implementation of RSA algorithm

from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii
def rsa_encryption(private_key, public_key, message):
 rsa_public_key = RSA.importKey(binascii.unhexlify(public_key))
 rsa_public_key = PKCS1_OAEP.new(rsa_public_key)
 encrypted = rsa_public_key.encrypt(message)
 return binascii.hexlify(encrypted)
def rsa_decryption(private_key, public_key, encrypted):
 rsa_private_key = RSA.importKey(binascii.unhexlify(private_key))
 rsa_private_key = PKCS1_OAEP.new(rsa_private_key)
 decrypted = rsa_private_key.decrypt(binascii.unhexlify(encrypted))
 return decrypted
keyPair = RSA.generate(bits=1024)
pubKey = keyPair.publickey()
pubKeyPEM = pubKey.exportKey()
privKeyPEM = keyPair.exportKey()
print(f"Public key: {binascii.hexlify(pubKeyPEM)}")
print(f"Private key: {binascii.hexlify(privKeyPEM)}")
message = b'This is a test.'
encrypted = rsa_encryption(privKeyPEM, pubKeyPEM, message)
print("Encrypted:", encrypted)
decrypted = rsa_decryption(privKeyPEM, pubKeyPEM, encrypted)
print("Decrypted:", decrypted)
