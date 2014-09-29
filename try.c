#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
  int commandlength = 0;
  for (int i = 1; i < argc; i++) {
    commandlength = strlen(argv[i]);
  }
  char* commandstr = malloc(sizeof(char*) * (commandlength + 1));
  memset(commandstr, 0, (commandlength + 1));
  
  for (int i = 1; i < argc; i++) {
    if (strlen(commandstr) > 0) {
      strcat(commandstr, " ");
    }
    strcat(commandstr, argv[i]);
  }
  
  int result = system(commandstr);
  while (result != 0) {
    sleep(2);
    result = system(commandstr);
  }
  
  return EXIT_SUCCESS;
}