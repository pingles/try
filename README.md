# try

Command to repeatedly run another command until it "succeeds".

Often I find I want to run a command repeatedly until it succeeds. For example, when spawning virtual machines I'll keep running `ssh me@mymachine`. These commands often fail to complete successfully (SSH not authorized, no DNS etc.) but *should* succeed eventually.

`try` helps to repeatedly run a command until it succeeds.

## Building

    $ make

## Running

    $ try ssh me@mymachine
    ...
    Warning: Permanently added '[foobar.com]:22,[...]:...' ...
    Welcome to Ubuntu 12.04

## To Do

* Add an option to print usage/help
* Allow users to specify an option to control the retry delay

## License

