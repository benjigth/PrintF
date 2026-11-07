/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fonction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begauthi <begauthi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 19:09:51 by begauthi          #+#    #+#             */
/*   Updated: 2026/11/07 19:22:49 by begauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

int	ft_putnbr_base(unsigned long n, char *base, unsigned long len)
{
	int	count;

	count = 0;
	if (n >= len)
		count += ft_putnbr_base(n / len, base, len);
	count += ft_putchar(base[n % len]);
	return (count);
}
