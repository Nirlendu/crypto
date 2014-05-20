from ctypes import cdll, c_char_p

lib ="/home/saucyvicki/Desktop/Idea_Device/lib/librijndael.so"
dll = cdll.LoadLibrary(lib)
r_enc = (lambda x, y: dll.encrypt(c_char_p(x), c_char_p(y)))
r_dec = (lambda u, v:dll.decrypt(c_char_p(u), c_char_p(v)))

# r_enc('passwordishere', 'cipher.txt')
# r_dec('passwordishere', 'cipher.txt')
