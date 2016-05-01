#include <time.h>

int main() {
  for (int i = 0; i < 100000000; ++i)
    time(NULL);
}
