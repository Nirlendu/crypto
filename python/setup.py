from distutils.core import setup
from distutils.extension import Extension
import sys

setup(name='license',
      version='0.1',
      ext_modules=[Extension('license', 
                             sources = ['src/license.c', 'src/hash.c'],
                             define_macros = [('WIN32', 1 if sys.platform == 'win32' else 0)])]
      )
