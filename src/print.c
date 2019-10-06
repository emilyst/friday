#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"


int print(const char * restrict format, ...) {
  va_list args;
  va_start(args, format);

  char *temp = NULL;
  int result = vasprintf(&(temp), format, args);
  printf("%s\n", temp);
  free(temp);

  va_end(args);

  return result;
}

int print_string_attribute(const char *name, const char *value) {
  const int total_width = 40;
  const int name_width  = strnlen(name, total_width);
  const int padding     = (total_width / 2 - name_width) + name_width;
  return print("%*s: %s", padding, name, value);
}

int print_double_attribute(const char *name, const double value) {
  char *temp = NULL;
  if (asprintf(&temp, "%f", value)) {};
  int result = print_string_attribute(name, temp);
  free(temp);

  return result;
}
