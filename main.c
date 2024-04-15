#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// point of program: given an .env file, return the contents to the user as JSON
// payload

#define MAX_LINE_LENGTH 1024 // Maximum length of a line
#define MAX_VALUES 256       // Maximum number of key value pairs

void parse_line(char line[], Map *map) {
  char *token = strtok(line, "=");

  if (token != NULL) {
    map->key = malloc(strlen(token) + 1);
    if (map->key != NULL) {
      strcpy(map->key, token);
    }

    token = strtok(NULL, "=");
    if (token != NULL) {
      map->value = malloc(strlen(token) + 1);
      if (map->value != NULL) {
        strcpy(map->value, token);
      }
    }
  }
}

void print_map(Map *map, int size) {
  printf("Printing the contents of your .env file:\n");
  printf("----------------------------------------\n");
  printf("{\n");
  for (int i = 0; i < size; i++) {
    printf("    %s: %s, \n", map[i].key, map[i].value);
  }
  printf("}\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please pass one argument, the file path.");
    return -1;
  }

  char *file_path = argv[1]; // file path argument
  FILE *file = fopen(file_path, "r");

  if (file == NULL) {
    printf("File not found.");
    return -1;
  }

  char line[MAX_LINE_LENGTH];
  Map map[MAX_VALUES];
  unsigned int line_count = 0;

  // read .env file and add lines to buffer array
  while (fgets(line, sizeof(line), file) != NULL && line_count < MAX_VALUES) {
    // remove \n character from each line
    size_t len = strlen(line);
    if (line[len - 1] == '\n')
      line[len - 1] = '\0';

    parse_line(line, &map[line_count]);
    line_count++;
  }

  // close file when done
  fclose(file);

  // print map to console
  print_map(map, line_count);

  // free map before exiting
  for (int i = 0; i < line_count; i++) {
    free(map[i].key);
    free(map[i].value);
  }

  return 1;
}
