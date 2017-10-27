#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int random_num() {
  int file_fd = open("/dev/random", O_RDONLY);
  if (file_fd < 0) {
    printf("error: %s\n", strerror(errno));
  }

  int rand_int;
  if (read(file_fd, &rand_int, 4) < 0) {
    printf("error: %s\n", strerror(errno));
  }

  if (close(file_fd) < 0) {
    printf("error: %s\n", strerror(errno));
  }
  
  return rand_int;
}


int main() {
  //printf("random number: %d\n", random_num());
  int count = 0;
  int[10] array;
  while (count < 10) {
    array[count] = random_num();
    count++;
  }


}
