#include "philo.h"

int get_num(char *s)
{
    int num;

    num  = 0;
    while (*s)
    {
        num = num * 10 + ((*s) - '0');
        s++;
    }

    return (num);
}