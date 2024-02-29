C++ program for Affine Cryptograph algorithm, including both encoding and decoding algorithms.

Affine Cryptography is a method to cipher/decipher a message by replacing the characters from the message into different characters using 2 key values which are both co-prime with 26 and smaller than 26. The characters of the message will be labeled in order of the alphabet, starting from 0 for letter A, and ending at 25 for letter Z. The encoding and decoding algorithms will proceed as the following:
- Encoding algorithm: Returns a ciphertext string (C) from a plaintext input (P), given 2 key values a & b:
  P(x) = (ax + b) mod 26 (x is the label of each character)
- Decoding algorithm: Returns a plaintext string (P) from a ciphertext input (C), given 2 key values a & b.
  C(x) = (a^-1)(x - b) mod 26 (x is the label of each character)
  
  a^-1 is the inverse of a. Since the set of value for a and a^-1 both contain the same values, its value has to be so that a(a^-1) mod 26 = 1.
  The set of values for a and a^-1 is as the following:
  a    = {1, 3, 5,  7,  9, 11, 15, 17, 19, 21, 23, 25};
  a^-1 = {1, 9, 21, 15, 3, 19, 7,  23, 11, 5,  17, 25};
