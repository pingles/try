/*
Copyright (c) Paul Ingles 2014

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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