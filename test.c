#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#define OPTIONS "n:"

int main(int argc, char **argv) {
  uint32_t n = 100;

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

  stack *s = newStack(n);

  for (uint32_t i = 0; i < n; i += 1) {
    printf("> %d\n", i);
    (void) push(s, &i);
  }

  uint32_t x;
  while (!emptyS(s)) {
    (void) pop(s, &x);
    printf("< %d\n", x);
  }

  delStack(s);

  return 0;
}
