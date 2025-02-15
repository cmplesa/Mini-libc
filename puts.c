#include <unistd.h>
#include <string.h>

int puts(const char *s)
{
    long s_len = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        s_len++;
    }
    if (write(1, s, s_len) != s_len)
    {
        return -1;
    }

    if (write(1, "\n", 1) != 1)
    {
        return -1;
    }

    return s_len + 1;
}
