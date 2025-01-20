#include <stdio.h>
#include <unistd.h>
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putuinbr_fd(unsigned int num, int fd)
{
    if ((num / 10) > 0)
	{
		ft_putuinbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
	else
		ft_putchar_fd(num % 10 + '0', fd);
}

int main(void)
{
    int num = 10;
    ft_putuinbr_fd(num, 1);
    return (0);
}