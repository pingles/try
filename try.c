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
#include <stdbool.h>
#include <getopt.h>

void print_usage() {
  printf("Usage: try [-dh] <command>\n");
  printf("  -d <seconds>   seconds to wait between executing command. defaults to 2 seconds.\n");
  printf("  -h             print this message\n");
}

char* parse_command(int argc, char** argv, int start) {
  int commandlength = 0;
  for (int i = start; i < argc; i++) {
    commandlength = strlen(argv[i]);
  }
  char* commandstr = malloc(sizeof(char*) * (commandlength + 1));
  memset(commandstr, 0, (commandlength + 1));

  for (int i = start; i < argc; i++) {
    if (strlen(commandstr) > 0) {
      strcat(commandstr, " ");
    }
    strcat(commandstr, argv[i]);
  }
  return commandstr;
}

int main(int argc, char** argv) {
  int opt;
  int delay = 2;

  while ((opt = getopt(argc, argv, "hd:")) != -1) {
    switch (opt) {
    case 'h':
      print_usage();
      exit(0);
    case 'd':
      delay = strtol(optarg, NULL, 10);
      if (delay == 0) {
        delay = 2; // default delay if we can't parse the value
      }
      break;
    }
  }

  char* commandstr = parse_command(argc, argv, optind);

  if (strlen(commandstr) == 0) {
    printf("Must provide command.\n");
    print_usage();
    exit(-1);
  }

  int result = system(commandstr);
  for (;;) {
    if (result == EXIT_SUCCESS) {
      exit(0);
    }

    int sleep_res = sleep(delay);
    if (sleep_res != 0) {
      printf("sleep interrupted: %d", sleep_res);
    }

    result = system(commandstr);
  }

  return EXIT_SUCCESS;
}
