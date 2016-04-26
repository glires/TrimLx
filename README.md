# TrimLx
Trim words or phrases in a tab-delimited file for a pipeline use of less -S -x

## Synopsis
    trimlx [-h] [-x width] input.tsv

## Description
The TrimLx programme trims each character string in a tab-delimited text file to fit the tab stop. If a character string, which should not contain any tab characters, is equal to or longer than the tab stop, only (tab_stop - 2) characters from the beginning are printed and then a sharp character is added. The output is printed onto the standard output, which is usually pipelined to less -S -x tab_stop.

## Options
    -h  Print usage
    -x  Set the width or the length of the tab stop (default: 8)

## Usage
    $ trimlx -h
    $ trimlx foo.tsv | less -S
    $ trimlx -x 13 bar.tsv | less -S -x 13

## Return values
If it succeeds, EXIT_SUCCESS is returned. When an unexpected character is found, 1 is returned.

## Author
Kohji OKAMURA, Ph.D.

## History
    2015-11-19  First release as trimft written in Perl
    2016-04-10  Rewritten in C
    2016-04-11  Use fputs() instead of fprintf()
    2016-04-21  Use freopen() to handle stdin
    2016-04-26  Released via GitHub
