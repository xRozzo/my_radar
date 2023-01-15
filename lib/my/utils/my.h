/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include "dirent.h"
#include <sys/types.h>


#ifndef MY_H_
    #define MY_H_

char *handles_num(char *arr, int number);

char* handles_decimal_hex(double nb);

bool includes_conv(const char* format, int i);

bool includes_lenmod(const char* format, int i);

bool includes_flags(const char* format, int i);

bool includes_precision(const char* format, int i);

bool includes_width(const char* format, int i);

int cnt_printf(const char* format, int i);

char* handles_a(va_list *va, char *format);

char* handles_A(va_list *va, char *format);

char* handles_b(va_list *va, char *format);

char* handles_c(va_list *va, char *format);

char* handle_decimal_hex(double nb);

char* handles_d(va_list *va, char *format);

char* handles_E(va_list *va, char *format);

char* handles_f(va_list *va, char *format);

char* negative_exponent_e(char* array, double num, bool negative);

char* positive_exponent_e(char* array, double num, bool negative);

char* handles_e(va_list *va, char *format);

char* positive_exponent_E(char* array, double num, bool negative);

char* negative_exponent_e(char* array, double num, bool negative);

char* handles_f(va_list *va, char *format);

char* handles_F(va_list *va, char *format);

char* handles_g(va_list *va, char *format);

char* handles_G(va_list *va, char *format);

char* handles_i(va_list *va, char *format);

char* handles_n(va_list *va, char *format);

char* handles_o(va_list *va, char *format);

char* handles_x_p(void *ptr);

char* handles_p(va_list *va, char *format);

char* handles_s(va_list *va, char *format);

char* cat_str(char* main_str, char* temp_str);

char* get_octal(int num, int* arr, char* temp, char* format);

char* handles_S(va_list *va, char *format);

char* handles_u(va_list *va, char *format);

char* handles_x(va_list *va, char *format);

char* handles_X(va_list *va, char *format);

int len_ulong_long(char const *str);

char *my_revstr_ulong_long(char *str);

char* my_ulong_long_to_str(unsigned long long num);

char* my_long_to_str(long num);

char* my_int_to_str(int num);

char* my_uint_to_str(unsigned int num);

int if_hexadecimal(char const *str, int cnt_1);

int is_char_alpha(char c);

int num_words(char const *str, int i, int cnt);

char **my_str_to_word_array(char const *str);

int string(char const *str);

int change_sign(int sign, int number);

int get_sign_before_int(int i, char const *str, int sign);

int prevent_under_overflow(char *aux, int i, int number, int number1);

char *strlowcase02(char *str);

int compare_and_swap(int *array, int temp);

char *same_strs (char *str, char const *to_find, int index);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_isneg(int n);

int my_printf(char *format, ...);

int my_is_prime(int nb);

void my_putchar(char c);

int my_put_nbr(int nb);

int change_sign(int sign, int number);

int my_getnbr(char const *str);

int get_sign_before_int(int i, char const *str, int sign);

int prevent_under_overflow(char *aux, int i, int number, int number1);

int my_putstr(char const *str);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

void my_sort_int_array(int *array, int size);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

char *my_strdup(char const *src);

int my_strcmp (char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

bool is_num(char c);

bool is_float(char *str);

bool is_only_num(char *str);

char *strcat_malloc(char *dest, char const *src);

bool is_special_float(char *str, int nb);

char *special_float(char *string, int nb);

char *precision_int(char* string, int nb);

char **str_split(char const *str, char separator);

char **separate_string(char **array, char *str, char separator, int array_len);

void handle_l(struct dirent *dir, char *file_path, char *file_name); // two

int check_if_file(char *argv[]);

void handle_a(struct dirent *dir, char *file_path, char *file_name); // one

void handle_d(struct dirent *dir, char *file_path, char *file_name);

void print_file_path(char *file_path);

void read_directory(char *string, char *argv[], char* file_path);

void calls_read_directory(char *file_path, char *argv[]);

void print_h(void);

float string_to_float(const char *str);                                                                                                                                                                                                                                                                                                                                                                                                                                                           

char **read_map(int argc, char* argv[], char *buff);

void *my_memcpy(void *destination, const void *source, size_t num_bytes);

void delate(void *ptr);

void display_usage_radar(void);

#endif /* MY_H_ */
