#include "libftprintf.h"

int  ft_nbrthex_fd(int num, int capital)
{
    int count;
    count = long_to_hex(num, capital);
    return count;

}
