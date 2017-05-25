/*                                                                           */
/* NAME                                                                      */
/*   TrimLx - trim words in a tab-delimited file for a use of less -x        */
/*                                                                           */
/* SYNOPSIS                                                                  */
/*   trimlx -h                                                               */
/*   trimlx [-x width] input.tsv                                             */
/*                                                                           */
/* DESCRIPTION                                                               */
/*   The TrimLx programme trims each character string in a tab-delimited     */
/*   text file to fit the tab stop. If a character string, which should not  */
/*   contain any tab characters, is equal to or longer than the tab stop,    */
/*   only (tab_stop - 2) characters from the beginning are printed and then  */
/*   a sharp character is added.                                             */
/*   The output is printed onto the standard output, which is usually        */
/*   pipelined to less -S -x tab_stop.                                       */
/*                                                                           */
/* USAGE                                                                     */
/*   $ trimlx -h                                                             */
/*   $ trimlx foo.tsv | less -S                                              */
/*   $ trimlx -x 13 bar tsv | less -S -x 13                                  */
/*                                                                           */
/* RETURN VALUES                                                             */
/*   If it succeeds, EXIT_SUCCESS is returned.                               */
/*   When an unexpected character is found, 1 is returned.                   */
/*                                                                           */
/* OPTIONS                                                                   */
/*   -h  Print usage                                                         */
/*   -x  Set the width or the length of the tab stop (default: 8)            */
/*                                                                           */
/* AUTHOR                                                                    */
/*   Coded by Kohji OKAMURA, Ph.D.                                           */
/*                                                                           */
/* HISTORY                                                                   */
/*   2015-11-19  First release as trimft written in Perl                     */
/*   2016-04-10  Rewritten in C                                              */
/*   2016-04-11  Use fputs() instead of fprintf()                            */
/*   2016-04-21  Use freopen() to handle stdin                               */
/*   2016-04-26  Released via GitHub                                         */
/*   2017-04-26  Avoid warn_unused_result for the use of freopen()           */
/*                                                                           */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define VERSION        "0.1"
#define MAX_CHAR_LONG  0x8000
#define MAX_CHAR_SHORT 0x4000
#define MIN_CHAR       0x1
#define TAB_STOP       8

int getopt(int, char * const [], const char *);

extern char *optarg;

int tabstop = TAB_STOP;
char line[MAX_CHAR_LONG];

int main(int argc, char *argv[])
{
  int counter, wcounter, opt;
  FILE *check;
  char word[MAX_CHAR_SHORT];
  register char one;

  while ((opt = getopt(argc, argv, "hvx:")) != -1)
  {
    switch (opt)
    {
      case 'h': fprintf(stdout, "Usage: cat foo.tsv | trimlx [-x width] | "
                  "less -S [-x widht]\n");
                return EXIT_SUCCESS;
      case 'v': fprintf(stdout, "TrimLx ver. %s\n", VERSION);
                return EXIT_SUCCESS;
      case 'x': tabstop = atoi(optarg);
                break;
      default:  fprintf(stderr, "Unknown option: %c\n", opt);
                  /* does not exit */
    }
  }
  check = fopen(argv[argc - 1], "r");
  if (check != NULL)
  {
    fclose(check);
    check = freopen(argv[argc - 1], "r", stdin);
  }

  while (fgets(line, MAX_CHAR_LONG, stdin) != NULL)
  {
    counter = wcounter = 0;
    while (1)
    {
      one = line[counter];
      if (one != '\t' && one != '\n' && one != '\r')
      { word[wcounter++] = one; counter++; }
      else if (one == '\t')
      {
        counter++;
        if (wcounter < tabstop)
        {
          word[wcounter] = one;
          word[wcounter + 1] = '\0';
          fputs(word, stdout); wcounter = 0; continue;
        }
        else
        {
          word[tabstop - 2] = '#';
          word[tabstop - 1] = one;
          word[tabstop]     = '\0';
          fputs(word, stdout); wcounter = 0; continue;
        }
      }
      else if (one == '\n' || one == '\r')
      {
        word[wcounter]     = '\n';
        word[wcounter + 1] = '\0';
        fputs(word, stdout); goto next_line;
      }
      else
      { fprintf(stderr, "Unexpected error 1: %s", line); exit(1); }
    }
    next_line: ;
  }

  return EXIT_SUCCESS;
}
