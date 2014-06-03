import os
import sys
import string
import unittest
from random import choice, randint
sys.path.append(os.path.abspath("../AES_wrappers/python_wrap/"))

from rijndael import enc, dec

def rand_str(min=100, max=10000):
    return ''.join([choice(string.printable) for _ in range(randint(min, max))])

class TestA(unittest.TestCase):
    def setUp(self):
        pass

    def test_enc_dec(self):
        for _ in range(1000):
            key = rand_str()
            for _ in range(1000):
                val = rand_str()
                assert(val==dec(key, enc(key, val)))

if __name__ == "__main__":
    unittest.main()
