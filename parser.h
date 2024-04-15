#ifndef parser_h
#define parser_h

struct Key {
  char *key;
};

struct Value {
  char *value;
};

typedef struct map {
  char *key;
  char *value;
} Map;

#endif
