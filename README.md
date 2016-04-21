# TrimLx
Trim words or phrases in a tab-delimited file for a pipeline use of less -S -x

The TrimLx programme trims each character string in a tab-delimited text file to fit the tab stop. If a character string, which should not contain any tab characters, is equal to or longer than the tab stop, only (tab_stop - 2) characters from the beginning are printed and then a sharp character is added. The output is printed onto the standard output, which is usually pipelined to less -S -x tab_stop.
