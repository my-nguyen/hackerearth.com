// part of Code Monk (Revision) challenge on 9/9/2015
// passed: sample input & test 1, 4, 5, 7, 8, 9
// failed the other tests (20 altogether)
// Candy distribution
// It's your birthday today, right? If it is, then we wish you Happy Birthday
// and good luck in the contest. But, even if it is not, you have to be ready to
// give candies to your friend when this day comes!
// You have N candies to distribute and you decide to give them to anyone who
// shows up. Because this is your day, you invented your own method of
// distributing all these candies . The process is the following:
// Initially, there are N candies placed in one pile. While there are any
// candies left, a person shows up and do the following:
// Picks up the first pile with candies, let's call this pile P.
// If P has one or two candies, he takes all the candies from P. Otherwise, he
// takes just one candy, divide the rest into some number of piles, at least 2,
// of equal sizes and put them in front the other piles.
// Because at HackerEarth we like math, we are interested how many different
// such processes are there. We consider two processes different if and only if
// one distributes candies to different number of people than the other or both
// distribute candies to the same number of people and there exists a person who
// decides to distribute candies differently in them. You have to return the
// number of different such processes modulo M = 109 + 7.
// Input format:
// In the first and only line there is one integer N.
// Output format:
// In one line output a single integer - the answer to the problem modulo
// M = 109 + 7.
// Constraints:
// 1 <= N <= 1012
// Sample Input(Plaintext Link)
// 5
// Sample Output(Plaintext Link)
// 2
// Explanation
// There are 5 candies initially. The first person after taking one candy for
// himself can divide the other 4 candies in two ways:
// into 4 piles with 1 candy on each of them
// into 2 piles with 2 candies.
// In the first case, 4 people will show up and each of them will take one candy
// for himself. In the second case, 2 people will show up and each of the will
// take 2 candies for himself.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

int mycompare(const void* left, const void* right)
{
  return *((const int*)left) - *((const int*)right);
}

char* tostring(int array[], int size, char* string)
{
  strcpy(string, "[");
  int i;
  for (i = 0; i < size; i++)
  {
    if (i)
      strcat(string, " ");
    sprintf(string+strlen(string), "%d", array[i]);
  }
  strcat(string, "]");
  return string;
}

// find all factors of a target number
void find_factors(int number, int factors[], int* size)
{
  // 1 is always a divisor
  *size = 0;
  factors[(*size)++] = 1;
  if (number > 1)
  {
    // number is also always a divisor
    factors[(*size)++] = number;
    // start looking for other factors from 2 on up.
    int i = 2;
    while (i <= sqrt(number))
    {
      // if number is evenly divisible by i, then retain i, and possibly also
      // the division of number/i.
      if (number % i == 0)
      {
        factors[(*size)++] = i;
        if (i != number/i)
          factors[(*size)++] = number/i;
      }
      i += 1;
    }
    qsort(factors, *size, sizeof(int), mycompare);
  }
}

int pcount = 0;
void process(int ccount)
{
  if (ccount == 1 || ccount == 2)
    ; // printf("candies: %d, take all\n", ccount);
  else
  {
    // take 1 candy
    // printf("candies: %d, take 1\n", ccount);
    ccount--;
    int factors[1000];
    int fcount;
    find_factors(ccount, factors, &fcount);
    char string[1000];
    // printf("factors: %s\n", tostring(factors, fcount, string));
    if (fcount == 2)
    {
      // fcount[1] is ccount: it's a prime number
      // printf("candies: %d, divide into %d piles", factors[1], factors[1]);
      pcount++;
    }
    else
    {
      int i;
      // skip factor 1
      for (i = 1; i < fcount; i++)
      {
        // printf("divide into %d piles of %d candies each\n", factors[i], ccount/factors[i]);
        pcount++;
        process(ccount/factors[i]);
      }
    }
  }
}

#define MAX_INPUT 1000
void main()
{
  char input[MAX_INPUT];
  int ccount = atoi(fgets(input, MAX_INPUT, stdin));
  process(ccount);
  printf("%d\n", pcount);
}
