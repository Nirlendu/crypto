from distutils.core import setup
from distutils.extension import Extension
import sys

setup(name='license',
      version='0.1',
      ext_modules=[Extension('license',
			     sources = ['src/sha_python.c', '../../src/SHA/hash.c'],
                             define_macros = [('WIN32', 0 if sys.platform == 'win32' else 1)])]
      )
