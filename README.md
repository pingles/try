# try

`try` helps to repeatedly run a command until it succeeds.

Often I find I want to run a command repeatedly until it succeeds. For example, when spawning virtual machines I'll keep running `ssh me@mymachine`. These commands often fail to complete successfully (SSH not authorized, no DNS etc.) but *should* succeed eventually.

## Building

    $ autoreconf --install

    $ ./configure
    $ make install  

## Running

    $ try ssh me@mymachine
    ... time passes ...
    Warning: Permanently added '[foobar.com]:22,[...]:...' ...
    Welcome to Ubuntu 12.04

## License

Distributed under the GNU General Public License v3.