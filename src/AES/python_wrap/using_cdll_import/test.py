from ctypes import cdll, c_char_p

lib ="../../lib/librijndael.so"
dll = cdll.LoadLibrary(lib)
dll.enc.restype = c_char_p
dll.dec.restype = c_char_p
r_enc = (lambda x, y: dll.enc(c_char_p(x), c_char_p(y)))
r_dec = (lambda u, v: dll.dec(c_char_p(u), c_char_p(v)))

# r_enc('passwordishere', 'message which has to be encrypted')
# r_dec('passwordishere', 'some encrypted text after base64 encoding of the encryption')
