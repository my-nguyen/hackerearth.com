// part of Code Monk (Revision) challenge on 9/9/2015
// passed: sample input & test #1.
// failed the other 10 tests
#include <stdio.h>
#include <stdlib.h> // strtok()
#include <string.h> // strstr()

#define MAX_INPUT 2000
#define ROW_COUNT 32
#define COLUMN_COUNT 32

char patterns[][COLUMN_COUNT+1] =
{
  "_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#",
  "#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_"
};

void main()
{
  char string[MAX_INPUT];
  fgets(string, MAX_INPUT, stdin);
  int rcount = atoi(strtok(string, " "));
  int ccount = atoi(strtok(NULL, " "));
// printf("rcount: %d, ccount: %d\n", rcount, ccount);

  char** table = malloc(rcount * sizeof(char*));
  int i;
  for (i = 0; i < rcount; i++)
  {
    // 2 extra characters to accommodate '\n' from fgets() and '\0'
    table[i] = malloc(MAX_INPUT+2);
    fgets(table[i], MAX_INPUT, stdin);
    strtok(table[i], "\n");
// printf("line[%d]: %s\n", i, table[i]);
  }

  int pcount = 0;
  for (i = 0; i < rcount-ROW_COUNT; i++)
  {
    // look for a pattern of 32 pieces, starting with a white piece
    char* start;
    if (start = strstr(table[i], patterns[0]))
    {
      // record the offset of this pattern
      int diff = start - table[i];
// printf("found pattern at %d, offset %d\n", i, diff);
      // keep looking for the remaining consecutive 31 patterns
      int j;
      for (j = 1; j < ROW_COUNT; j++)
        // if a non-pattern is found within the next 31 lines, then this is not
        // a board
        if (strstr(table[i+j], patterns[j%2]) - table[i+j] != diff)
        {
          printf("pattern broken at %d\n", i+j);
          break;
        }

      // 32 lines with 32 patterns were found!
      if (j == ROW_COUNT)
      {
        // printf("board found, from %d to %d\n", i, i+j);
        pcount++;
      }

      // don't forget to update i, for the outer loop
      i += j;
    }
  }

  printf("%d\n", pcount);

  for (i = 0; i < rcount; i++)
    free(table[i]);
  free(table);
}
