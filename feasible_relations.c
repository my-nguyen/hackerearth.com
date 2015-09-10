// part of Code Monk (Revision) challenge on 9/9/2015
// passed: sample input & test #7.
// failed the other 6 tests
// Feasible relations
// As a programmer, you sometimes have to deal with some math and this is the
// time to do it. You are given a list of binary relations, equalities and
// inequalities, like a = b, a != d, b = c etc. Your task is to output YES if
// you can assign integers to input variables in such a way, that you can
// satisfy all equalities and inequalities. Otherwise you should output NO.
// Input format:
// In the first line there is one integer T denoting the number of test cases.
// Description of T test cases follow. Each one have two integers N and K given
// in the first line denoting the number of variables and the number of
// relations between them for this test case. All variables are represented by
// integers in range [1, N]. K lines follow. Each of them is of the form "x1 R
// x2" where x1 and x2 are integers representing variables and R is either "="
// or "!=" and denotes the kind of relation between these variables.
// Output format:
// Output exactly T lines. In i-th of them, output the answer to the i-th test case.
// Constraints:
// T <= 10
// 1 <= N, K <= 106
// Sum of N in one test file does not exceed 106
// Sum of K in one test file does not exceed 106
// Sample Input(Plaintext Link)
// 2
// 2 2
// 1 = 2
// 1 != 2
// 3 2
// 1 = 2
// 2 != 3
// Sample Output(Plaintext Link)
// NO
// YES
// Explanation
// There are 2 test cases. In the first one, you cannot fulfill all relations,
// because equality and inequality of two number cannot be both true. In the
// second one, you can for example assign 10 to 1 and 2 and 20 to 3 in order to
// fulfill all relations.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 20
#define MAX_CASE 10
#define MAX_RELATIONS 10
#define FALSE 0
#define TRUE 1

// forward reference
struct variable_t;

struct relations_t
{
  // let's hard-cord max number of relations for now
  struct variable_t* data[MAX_RELATIONS];
  int count;
};
typedef struct relations_t relations_t;

struct variable_t
{
  int number;
  relations_t equal;
  relations_t unequal;
};
typedef struct variable_t variable_t;

void rs_initialize(relations_t* relations)
{
  relations->count = 0;
}

void rs_add(relations_t* relations, variable_t* variable)
{
  relations->data[relations->count] = variable;
  relations->count++;
}

void va_initialize(variable_t* variable)
{
  rs_initialize(&variable->equal);
  rs_initialize(&variable->unequal);
}

void va_print(variable_t* variable)
{
  int i;
  for (i = 0; i < variable->equal.count; i++)
    printf("%d = %d\n", variable->number, variable->equal.data[i]->number);
  for (i = 0; i < variable->unequal.count; i++)
    printf("%d != %d\n", variable->number, variable->unequal.data[i]->number);
}

int va_conflict(variable_t* variable)
{
  int i;
  for (i = 0; i < variable->equal.count; i++)
  {
    int j;
    for (j = 0; j < variable->unequal.count; j++)
      if (variable->equal.data[i] == variable->unequal.data[j])
        return TRUE;
  }
  return FALSE;
}
struct variables_t
{
  // dynamic-memory array containing all variables (integers)
  variable_t* data;
  // the number of variables added into array so far, which may not be equal to size
  int count;
};
typedef struct variables_t variables_t;

void vs_initialize(variables_t* variables, int size)
{
  variables->count = 0;
  variables->data = malloc(size * sizeof(variable_t));
  int i;
  for (i = 0; i < size; i++)
    va_initialize(variables->data + i);
}

void vs_destroy(variables_t* variables)
{
  free(variables->data);
}

// this method looks up a target number from variables. it returns a pointer to
// the target in the array if found; it returns NULL otherwise.
variable_t* vs_find(variables_t* variables, int target)
{
  // only search up to variables->count (the number of variables added so far)
  int k;
  for (k = 0; k < variables->count; k++)
  {
    if (variables->data[k].number == target)
      return variables->data + k;
  }
  return NULL;
}

// this method adds variable to the end of the data array and returns a pointer
// to the added number
variable_t* vs_add(variables_t* variables, int number)
{
  variables->data[variables->count].number = number;
  variables->count++;
  return variables->data + variables->count - 1;
}

// this method tries to find a target number in the data array. it returns a
// pointer to the target if found; otherwise it adds the target into the data array
// and returns a pointer to the number just added
variable_t* vs_find_add(variables_t* variables, int target)
{
  variable_t* index = vs_find(variables, target);
  if (index == NULL)
    index = vs_add(variables, target);
  return index;
}

int vs_print(variables_t* variables)
{
  printf("All variables:");
  int i;
  for (i = 0; i < variables->count; i++)
    printf(" %d", variables->data[i].number);
  printf("\n");
  printf("All relations:\n");
  for (i = 0; i < variables->count; i++)
    va_print(variables->data + i);
}

// this method records the index to the lhs and the rhs numbers in the variables
// data array, and also records the relation (whether it's equal or not)
void vs_relation(variables_t* variables, int lhs, int rhs, int equal)
{
  variable_t* left = vs_find_add(variables, lhs);
  variable_t* right = vs_find_add(variables, rhs);
  if (equal)
  {
    rs_add(&left->equal, right);
    rs_add(&right->equal, left);
  }
  else
  {
    rs_add(&left->unequal, right);
    rs_add(&right->unequal, left);
  }
}

void main()
{
  // read number of test cases
  char input[MAX_INPUT];
  fgets(input, MAX_INPUT, stdin);
  int tcount = atoi(input);

  variables_t variables[MAX_CASE];
  // process each test case
  int i;
  for (i = 0; i < tcount; i++)
  {
    // read next line
    fgets(input, MAX_INPUT, stdin);
    // extract number of variables
    vs_initialize(variables+i, atoi(strtok(input, " ")));
    // extract number of relations
    int rcount = atoi(strtok(NULL, " "));

    // process each relation
    int j;
    for (j = 0; j < rcount; j++)
    {
      // read next relation
      fgets(input, MAX_INPUT, stdin);
      strtok(input, "\n");

      // break down each relation as 2 numbers (lhs and rhs) and boolean equal
      // (whether it's equal or not), and records these 3 elements.
      int lhs = atoi(strtok(input, " "));
      int equal = strcmp(strtok(NULL, " "), "!=");
      int rhs = atoi(strtok(NULL, " "));
      vs_relation(variables+i, lhs, rhs, equal);
    }
  }

  for (i = 0; i < tcount; i++)
  {
    /*
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("Test %d\n", i+1);
    vs_print(variables + i);
    */
    int conflict = FALSE;
    int j;
    for (j = 0; j < variables[i].count; j++)
    {
      if (va_conflict(variables[i].data + j))
      {
        conflict = TRUE;
        break;
      }
    }
    printf("%s\n", (conflict ? "NO" : "YES"));
  }

  for (i = 0; i < tcount; i++)
    vs_destroy(variables + i);
}
