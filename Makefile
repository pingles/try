CFLAGS := "-D_POSIX_SOURCE"

.PHONY: clean

try: try.c
	cc -Wall -pedantic try.c $(CFLAGS) -o try -std=c99

clean:
	rm -rf try
