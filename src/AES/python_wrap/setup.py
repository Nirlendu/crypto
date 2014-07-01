from distutils.core import setup
from distutils.extension import Extension
import sys

setup(name='rijndael',
      version='0.1',
      ext_modules=[Extension('rijndael',
			     sources = ['rijndael_python.c','../lib/enc_dec.c','../lib/base64.c', '../lib/rijndael.c'],
                             define_macros = [('WIN32', 0 if sys.platform == 'win32' else 1)])]
      )
