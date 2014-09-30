# try

`try` repeatedly runs a command until it succeeds (when it returns an exit code of `0`).

Often I find I want to run a command repeatedly until it succeeds. For example, when spawning virtual machines I'll keep running `ssh me@mymachine`. These commands often fail to complete successfully (SSH not authorized, no DNS etc.) but *should* succeed eventually.

## Building

    $ make

## Installing

You can specify the directory you'd like to install the binary to by setting a `PREFIX` environment variable when you `make install`.

    $ PREFIX=/usr/local make install

The binary would be placed in `$PREFIX/bin/try`.

## Running

    $ try ssh me@mymachine
    ... time passes ...
    Warning: Permanently added '[foobar.com]:22,[...]:...' ...
    Welcome to Ubuntu 12.04

You can change the delay between retries by specifying a delay parameter as follows, setting the retry delay to be 10 seconds.

    $ try -d 10

## License

`try` is released under the GNU General Public License v3. Please see `COPYING` for more information.