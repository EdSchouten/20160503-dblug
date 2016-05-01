#include <stdio.h>

int global_variable;

int main() {
  fprintf(stderr, "%p\n", &global_variable);
}
