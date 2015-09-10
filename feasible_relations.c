// part of Code Monk (Revision) challenge on 9/9/2015
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 20
#define MAX_CASE 10
#define FALSE 0
#define TRUE 1
#define NOT_FOUND -1

struct variables_t
{
  // dynamic-memory array containing all variables (integers)
  int* data;
  // the number of variables added into array so far, which may not be equal to size
  int count;
};
typedef struct variables_t variables_t;

void va_initialize(variables_t* variables, int size)
{
  variables->count = 0;
  variables->data = malloc(size * sizeof(int));
}

void va_destroy(variables_t* variables)
{
  free(variables->data);
}

// this method looks up a target number from variables. it returns a pointer to
// the target in the array if found; it returns NULL otherwise.
int* va_find(variables_t* variables, int target)
{
  // only search up to variables->count (the number of variables added so far)
  int k;
  for (k = 0; k < variables->count; k++)
  {
    if (variables->data[k] == 0)
      break;
    if (variables->data[k] == target)
      return variables->data + k;
  }
  return NULL;
}

// this method adds variable to the end of the data array and returns a pointer
// to the added number
int* va_add(variables_t* variables, int variable)
{
  variables->data[variables->count] = variable;
  variables->count++;
  return variables->data + variables->count - 1;
}

// this method tries to find a target number in the data array. it returns a
// pointer to the target if found; otherwise it adds the target into the data array
// and returns a pointer to the number just added
int* va_find_add(variables_t* variables, int target)
{
  int* index = va_find(variables, target);
  if (index == NULL)
    index = va_add(variables, target);
  return index;
}

int va_print(variables_t* variables)
{
  printf("All variables:");
  int i;
  for (i = 0; i < variables->count; i++)
    printf(" %d", variables->data[i]);
  printf("\n");
}

struct relation_t
{
  // static-memory array of 2 pointers, each pointing to a variable contained in
  // variables_t.data
  int* indices[2];
  // whether the relation is equal or not
  int equal;
};
typedef struct relation_t relation_t;

// this method records the index to the lhs and the rhs numbers in the variables
// data array, and also records the relation (whether it's equal or not)
void re_initialize(relation_t* relation, int lhs, int equal, int rhs, variables_t* variables)
{
  relation->indices[0] = va_find_add(variables, lhs);
  relation->indices[1] = va_find_add(variables, rhs);
  relation->equal = equal;
}

void re_print(relation_t* relation)
{
  printf("%d %s %d\n", *relation->indices[0], (relation->equal ? "=" : "!="), *relation->indices[1]);
}

struct relations_t
{
  // dynamic-memory array containing all relations
  relation_t* data;
  // number of relations in array
  int size;
};
typedef struct relations_t relations_t;

void rs_initialize(relations_t* relations, int size)
{
  relations->size = size;
  relations->data = malloc(size * sizeof(relation_t));
}

void rs_destroy(relations_t* relations)
{
  free(relations->data);
}

void rs_print(relations_t* relations)
{
  printf("All relations:\n");
  int i;
  for (i = 0; i < relations->size; i++)
    re_print(relations->data + i);
}

struct case_t
{
  variables_t variables;
  relations_t relations;
};
typedef struct case_t case_t;

void ca_print(case_t* cas)
{
  va_print(&cas->variables);
  rs_print(&cas->relations);
}

void main()
{
  // read number of test cases
  char input[MAX_INPUT];
  fgets(input, MAX_INPUT, stdin);
  int tcount = atoi(input);

  case_t cases[MAX_CASE];
  // process each test case
  int i;
  for (i = 0; i < tcount; i++)
  {
    // read next line
    fgets(input, MAX_INPUT, stdin);
    // extract number of variables
    va_initialize(&cases[i].variables, atoi(strtok(input, " ")));
    // extract number of relations
    rs_initialize(&cases[i].relations, atoi(strtok(NULL, " ")));

    // process each relation
    int j;
    for (j = 0; j < cases[i].relations.size; j++)
    {
      // read next relation
      fgets(input, MAX_INPUT, stdin);
      strtok(input, "\n");

      // break down each relation as 2 numbers (lhs and rhs) and boolean equal
      // (whether it's equal or not), and records these 3 elements.
      int lhs = atoi(strtok(input, " "));
      int equal = !strcmp(strtok(NULL, " "), "=");
      int rhs = atoi(strtok(NULL, " "));
      re_initialize(cases[i].relations.data+j, lhs, equal, rhs, &cases[i].variables);
    }
  }

  for (i = 0; i < tcount; i++)
  {
    ca_print(cases+i);
    int j;
    for (j = 0; j < cases[i].relations.size; j++)
    {
      // cases[i].relations.data
    }
  }

  for (i = 0; i < tcount; i++)
  {
    va_destroy(&cases[i].variables);
    rs_destroy(&cases[i].relations);
  }
}
