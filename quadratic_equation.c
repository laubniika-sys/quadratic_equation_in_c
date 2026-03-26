#include<unistd.h>
#include<math.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char c;

	if(n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if(n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10 + '0');
	write(1, &c, 1);
}

void	ft_quadratic_equation(double a, double b, double c)
{
	double delta;
	double x1;
	double x2;
	double real;
	double img;

	if(a == 0)
	{
		ft_putstr("The value of 'a' can not be zero");
		return ;
	}
	delta = b * b - 4 * a * c;
	if(delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		ft_putstr("There are two real roots\n");
		ft_putstr(" x1 = ");
		ft_putnbr((int)x1);
		ft_putstr("\n");
		ft_putstr(" x2 = ");
		ft_putnbr((int)x2);
		ft_putstr("\n");
	}
	else if(delta == 0)
	{
		x1 = -b / (2 * a);
		ft_putstr("There is only a real root\n");
		ft_putstr(" x = ");
		ft_putnbr((int)x1);
		ft_putstr("\n");
	}
	else
	{
		real = -b / (2 * a);
		img = sqrt(-delta) / (2 * a);
		ft_putstr("There are two complex roots\n");
		ft_putstr(" x1= ");
		ft_putnbr((int)real);
		ft_putstr("+");
		ft_putnbr((int)img);
		ft_putstr("i\n");
		ft_putstr(" x2= ");
		ft_putnbr((int)real);
		ft_putstr("-");
		ft_putnbr((int)img);
		ft_putstr("i\n");
	}
}

int main(void)
{
	ft_putstr("--- x^2 - 5x + 6 = 0 ---\n");
	ft_quadratic_equation(1, -5, 6);
	return (0);
}





