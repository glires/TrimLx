# TrimLx
Trim words or phrases in a tab-delimited file for a pipeline use of less -S -x

## Install
    $ ls -l    # check trimlx.c and makefile
    $ make     # compile and link using gcc
    $ ls -l    # check trimlx and triml
    $ sudo mv -i trimlx triml /usr/local/bin/    # or somewhere else

## Synopsis
    triml [tab_width] [input.tsv]

## Description
The TrimLx programme trims each character string in a tab-delimited text file to fit the tab stop. If a character string, which should not contain any tab characters, is equal to or longer than the tab stop, only (tab_stop - 2) characters from the beginning are printed and then a sharp character is added. The output is printed onto the standard output, which is then pipelined to less -S -x tab_stop. A sh script, triml, is also provided. This is the command general users type to execute TrimLx and the less command.

## Options
No options are supported, but the first command argument can be an integer value to specify the tab-stop length. The default value is 8.

## Usage
    $ triml foo.tsv
    $ triml 12 bar.tsv
    $ cat baz.tsv | triml
    $ cat qux.tsv | triml 16

## Author
Kohji OKAMURA, Ph.D.

## History
    2015-11-19  First release as trimft written in Perl
    2016-04-10  Rewritten in C
    2016-04-26  Released via GitHub
    2016-06-23  As the command, sh script triml provided
