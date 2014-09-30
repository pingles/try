CFLAGS := "-D_POSIX_SOURCE"
PREFIX ?= /usr/local
exec_bin := $(PREFIX)/bin

.PHONY: clean

try: try.c
	cc -Wall -pedantic try.c $(CFLAGS) -o try -std=c99

install: try
	cp try $(exec_bin)/try

uninstall: $(exec_bin)/try
	rm $(exec_bin)/try

clean:
	rm -rf try
