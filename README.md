# TrimLx
Trim words or phrases in a tab-delimited file for a pipeline use of less -S -x

## Install
    $ ls -l    # check trimlx.c and makefile
    $ make     # compile and link using gcc
    $ ls -l    # check trimlx and triml
    $ chmod +x triml
    $ sudo mv -i trimlx triml /usr/local/bin/    # or somewhere else

## Synopsis
    triml [[-x] tab_stop_length] [input.tsv]

## Description
The TrimLx programme trims each character string in a tab-delimited text file to fit the tab-stop length. If a character string, which should not contain any tab characters, is equal to or longer than the tab-stop length, only (tab_stop_length - 2) characters from the beginning are printed and then a sharp character is added. The output is printed onto the standard output, which is then pipelined to less -S -x tab_stop_length. A sh script, triml, is also provided. This is the command general users type to execute TrimLx and the less command.

## Options
For the triml command, option -v is available to check versions of both triml and trimlx. A make-believe option -x can be added with the triml command as shown in the Usage section. Tab-stop length can usually be specified as the first command argument without any option string, but can be specified with -x. The default length is 8.

## Usage
    $ triml -v
    $ triml foo.tsv
    $ triml 12 foo.tsv
    $ triml -x12 foo.tsv
    $ triml -x 12 foo.tsv
    $ triml foo.tsv 12
    $ cat baz.tsv qux.tsv | triml
    $ cat baz.tsv qux.tsv | triml 14
    $ cat baz.tsv qux.tsv | triml -x14
    $ cat baz.tsv qux.tsv | triml -x 14

## Author
Kohji OKAMURA, Ph.D.

## History
    2015-11-19  First release as trimft written in Perl
    2016-04-10  Rewritten in C
    2016-04-26  Released via GitHub
    2016-06-23  As the command, sh script triml provided
    2016-07-07  Make-believe option -x added for triml ver. 0.2
