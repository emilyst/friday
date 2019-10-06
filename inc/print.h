#pragma once


int print(const char * restrict, ...) __attribute__ ((format (printf,1,2)));
int print_string_attribute(const char *, const char *);
int print_double_attribute(const char *, const double);

#define print_attribute(name, value) _Generic((name),                                                 \
                                              default: _Generic((value),                              \
                                                                const char *: print_string_attribute, \
                                                                char *:       print_string_attribute, \
                                                                default:      print_double_attribute) \
                                             )(name, value)
