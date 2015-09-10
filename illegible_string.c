// part of Code Monk (Revision) challenge on 9/9/2015
// passed: sample input.
// failed all 16 tests
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct block_t
{
  int start;
  int length;
};
typedef struct block_t block_t;

// this method returns the frequency of occurrence of letter within string
int count(char* string, int size, char letter)
{
  int count = 0;
  int i;
  for (i = 0; i < size; i++)
    if (string[i] == letter)
      count++;
  return count;
}

// this method returns the sum of all integers within array numbers
int sum(int numbers[], int size)
{
  int sum = 0;
  int i;
  for (i = 0; i < size; i++)
    sum += numbers[i];
  return sum;
}

#define MAX_INPUT 1000000
void main()
{
  // read from input
  char tmp[MAX_INPUT+1];
  int scount = atoi(fgets(tmp, MAX_INPUT, stdin));
  char* string = malloc(scount);
  fgets(string, MAX_INPUT, stdin);

  // collect strings of consecutive v's and w's. each such string constitutes a block
  block_t blocks[1000];
  int bcount = 0;
  int i;
  for (i = 0; i < scount; i++)
    // look for either 'v' or 'w'
    if (string[i] == 'v' || string[i] == 'w')
    {
      // start a new block: retain the location (start, length)
      blocks[bcount].start = i;
      blocks[bcount].length = 1;
      // keep looking for consecutive 'v' or 'w'
      while (string[i] == 'v' || string[i] == 'w')
      {
        i++;
        blocks[bcount].length++;
      }
      // end of one block
      bcount++;
    }

  // calculate min and max lengths of each block
  int* mins = malloc(bcount * sizeof(int));
  int* maxs = malloc(bcount * sizeof(int));
  int vtotal = 0;
  int wtotal = 0;
  for (i = 0; i < bcount; i++)
  {
    // count number of v's and w's in current block
    int vblock = count(string+blocks[i].start, blocks[i].length, 'v');
    int wblock = count(string+blocks[i].start, blocks[i].length, 'w');
    // calculate and retain the min and max lengths of current block
    mins[i] = vblock/2 + vblock%2;
    maxs[i] = wblock*2;
    // take the total of all v's and w's
    vtotal += vblock;
    wtotal += wblock;
  }

  // calculate the sum of all min lengths and all max lengths, for use in report printf()
  int min_sum = sum(mins, bcount);
  int max_sum = sum(maxs, bcount);

  // temporary count, for use in report printf()
  int tcount = scount - vtotal - wtotal;
printf("scount: %d, bcount: %d, vtotal: %d, wtotal: %d, tcount: %d, min_sum: %d, max_sum: %d\n",
scount, bcount, vtotal, wtotal, tcount, min_sum, max_sum);
  // report
  printf("%d %d\n", tcount+min_sum+wtotal, tcount+max_sum+vtotal);

  free(mins);
  free(maxs);
  free(string);
}
