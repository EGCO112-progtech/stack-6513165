#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i, N, j;
  Stack s;
  s.top = NULL;
  s.size = 0;

  for (i = 1; i < argc; i++) {
    N = 0;
    for (j = 0; j < strlen(argv[i]); j++) {
      switch (argv[i][j]) {
      case '{':
      case '[':
        push(&s, (argv[i][j]));
        break;
      case '}':
          if(s.size==0) N=2;
        else{
        if (pop(&s) != '{') {
             N = 1;
        }
          }
        break;
      case ']':
        if(s.size==0) N=2;
        else{
        if (pop(&s) != '[') {
             N = 1;
        }
          }
        break;
      default:
        printf("Please enter only the parenthesis");
      }
      if (N == 1)
        break;
    }

    if (s.size > 0) {
      printf("argv %d: Incorrect: too many open parenthesis\n", i);
      pop_all(&s);
    } else if (N == 0) {
      printf("argv %d: Correct\n", i);
      pop_all(&s);
    } else if (N == 2) {
      printf("argv %d: Incorrect: too many closed parenthesis\n", i);
      pop_all(&s);
    } else {
      printf("argv %d: Incorrect: mismatch\n", i);
      pop_all(&s);
    }
  }

  /*
  Stack s;
  printf("Checking the parentheses in argv arguments\n");
   for(i=1;i<argc;i++){

      for(j=0;j<strlen(argv[i]);j++){
        /* Use stack to help with the parentheses*/

  /*  }

 }
*/

  return 0;
}
