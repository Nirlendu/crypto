python: setup.py rijndael_python.c ../lib/rijndael.c ../lib/enc_dec.c ../lib/base64.c
	python setup.py install --install-platlib $$PWD

.PHONY: clean

clean:
	rm -rf build
	rm *so *info
