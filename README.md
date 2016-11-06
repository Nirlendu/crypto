crypto
=========

Platform independent crypto library for components.
SHA-1 used for checking the integrity and AES-256 used for encryption and decryption of data.

Library wrappers for some common langauages are present in respective wrapper directories.

Eg. To install AES in python, run

```
make aes-python
```

To run AES in python, open python prompt

```
import rijndael
x = rijndael.encode('SECRET_KEY', 'secret_message')
print rijndael.decode('SECRET_KEY', x)
```


To install SHA in python,

```
make sha-python
```
