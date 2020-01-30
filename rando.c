#include "stack.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define OPTIONS "n:"

int main(int argc, char **argv) {
  uint32_t x = 0, n = 100;

  int c;
  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    case 'n':
      n = strtol(optarg, (char **)NULL, 10);
      break;
    default:
      printf("Invalid argument\n");
      break;
    }
  }

  stack *s = newStack(n * n);

  srandom(time(0));

  do {
    for (uint32_t i = 0; i < random() % n; i += 1) {
      if (push(s, &x)) {
        printf(">"); x +=1;
      } else {
        printf("Full!\n");
      }
    }
    putchar('\n');

    for (uint32_t i = 0; i < random() % n; i += 1) {
      if (pop(s, &x)) {
        printf("<");
      }
    }
    putchar('\n');
  } while (!emptyS(s));

  delStack(s);

  return 0;
}
