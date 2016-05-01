#include <stdio.h>

static int global_variable;

int main() {
  fprintf(stderr, "%p\n", &global_variable);
}
