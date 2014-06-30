import os
import sys
import string
from time import sleep

from rijndael import encd, decd


key = 'vicki'
message = 'this is some random text'
cipher = encd(key, message)
print cipher
for i in range(11):
	sleep(1)
	cipher1 = encd(key, message)
	try:
		assert cipher == cipher1
	except 	AssertionError:
		print i
		print cipher1

