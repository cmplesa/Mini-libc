// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}

char *strncpy(char destination[], const char source[], size_t len)
{
    size_t i = 0;
    while (i < len && source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }

    while (i < len) {
        destination[i] = '\0';
        i++;
    }

    return destination;
}
char *strcat(char *destination, const char *source)
{
    int i = 0;
    int j = 0;
    while (destination[i] != '\0') {
        i++;
    }
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }

    destination[i] = '\0';
    return destination;
}


char *strncat(char *destination, const char *source, size_t len)
{
    int i = 0;
    int j = 0;

    while (destination[i] != '\0') {
        i++;
    }

    while (len && source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
        len--;
    }

    destination[i] = '\0';

    return destination;
}

int strcmp(const char str1[], const char str2[])
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }

    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

int strncmp(const char str1[], const char str2[], size_t len)
{
    size_t i = 0;

    while (i < len && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }

    if (i == len) {
        return 0;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}


size_t strlen(const char str[])
{
    size_t i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}

char *strchr(const char str[], int c)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == (char)c) {
            return (char *)&str[i];
        }
        i++;
    }

    return NULL;
}


char *strrchr(const char str[], int c)
{
    int i = 0;
    char *last = NULL;

    while (str[i] != '\0') {
        if (str[i] == (char)c) {
            last = (char *)&str[i];
        }
        i++;
    }

    return last;
}


char *strstr(const char haystack[], const char needle[])
{
    if (*needle == '\0') {
        return (char *)haystack;
    }

    int i, j;
    for (i = 0; haystack[i] != '\0'; i++) {
        for (j = 0; needle[j] != '\0'; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (needle[j] == '\0') {
            return (char *)&haystack[i];
        }
    }
    return NULL;
}


char *strrstr(const char *haystack, const char *needle)
{
    if (needle == NULL || needle[0] == '\0') {
        return (char *)haystack;
    }

    const char *last = NULL;
    int i = 0;

    while (haystack[i] != '\0') {
        int h = i;
        int n = 0;

        while (haystack[h] == needle[n] && needle[n] != '\0') {
            h++;
            n++;
        }

        if (needle[n] == '\0') {
            last = &haystack[i];
        }

        i++;
    }

    return (char *)last;
}


void *memcpy(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    const char *src = (const char *)source;
    size_t i = 0;
    while (i < num) {
        dest[i] = src[i];
        i++;
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    const char *src = (const char *)source;
    if (dest < src) {
        size_t i = 0;
        while (i < num) {
            dest[i] = src[i];
            i++;
        }
    } else {
        size_t i = num;
        while (i > 0) {
            dest[i - 1] = src[i - 1];
            i--;
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;
    for (size_t i = 0; i < num; i++) {
        if (p1[i] == p2[i]) {
            continue;
        } else {
            return p1[i] - p2[i];
        }
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
    unsigned char *src = (unsigned char *)source;

    for (size_t i = 0; i < num; i++) {
        src[i] = (unsigned char)value;
    }

    return source;
}

