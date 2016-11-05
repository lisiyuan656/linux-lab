#include <linux/unistd.h>
#define __NR_cp_range 285
__syscall2(int, cp_range, void *start_addr, void *end_addr)

int main() {
  int size = 10;
  int i;
  int *array = malloc(size);
  for (i=0; i<size; i++) array[i] = i;
  cp_range(array, array+size-1);
  for (i=0; i<size; i++) array[i] = 100;
  cp_range(array, array+size-1);
  return 0;
}
