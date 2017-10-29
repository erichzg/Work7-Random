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
  int array[10];
  printf("Generating random numbers: \n");
  while (count < 10) {
    array[count] = random_num();
    printf("random %d: %d\n", count, array[count]);
    count++;
  }
  printf("\nWriting numbers to file:\n");
  int write_fd = open("random_nums.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (write_fd < 0) {
    printf("error: %s\n", strerror(errno));
  }
  if (write(write_fd, array, 40) < 0) {
    printf("error: %s\n", strerror(errno));
  }
  if (close(write_fd) < 0) {
    printf("error: %s\n", strerror(errno));
  }

  printf("Reading numbers from file:\n");
  int read_fd = open("random_nums.txt", O_RDONLY);
  if (read_fd < 0) {
    printf("error: %s\n", strerror(errno));
  }
  int read_array[10];
  if (read(read_fd, read_array, 40) < 0) {
    printf("error: %s\n", strerror(errno));
  }
  if (close(read_fd) < 0) {
    printf("error: %s\n", strerror(errno));
  }

  printf("Verification that written values were the same: \n");
  count = 0;
  while (count < 10) {
    printf("random %d: %d\n", count, read_array[count]);
    count++;
  }
  return 0;
}
