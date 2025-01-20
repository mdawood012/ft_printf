#include <stdio.h>
#include "libftprintf.h"
#include <stddef.h> 
#include "limits.h"

int main(void)
{
    ft_printf(" %p %p ", 0, 0);
    return (0);
}
// //now i've got to figure out the p category. i think it might be problematic when it
// //comes to pointers where it is equal to null. 
// //instead it has issues when the memory adddress is LONG_MIN, LONG_MAX etc. 
//test 6, 8, 9. 