/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:11:59 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/18 13:22:18 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_ptr(const char src, va_list ptr)
{
  if (src == 'c')
    return(ft_putchar(va_arg(ptr, int)));
  else if (src == 's')
    return (ft_putstr(va_arg(ptr, char *)));
  else if (src == 'i' || src == 'd')
    return (ft_putnbr(va_arg(ptr, int)));
  else if (src == 'x' || src == 'X')
    return (ft_put_hex(va_arg(ptr, unsigned int ), src));
  else if (src == 'p')
    return (ft_put_addp(va_arg(ptr, unsigned long), src));
  else if (src == 'u')
    return (ft_unsi_putnbr(va_arg(ptr, unsigned int)));
  else if(src == '%')
    ft_putchar('%');
  return (1);
}
int ft_printf(const char *src, ...)
{
  int i;
  int len;
  len = 0;
  i = 0;
  va_list ptr;
  va_start(ptr, src);
  if(src[i] == 0)
    return 0;
  while (src[i])
  {
    if (src[i] == '%')
    {
      len += ft_ptr(src[++i], ptr);
      i++;
    }
    else
    {
      len++;
      ft_putchar(src[i]);
      i++;
    }
  }
  va_end(ptr);
  return (len);
}
// #include<stdio.h>
// int main()
// {
//   printf("%d\n",ft_printf("hjghjgk %s jhgkjgkg ", NULL));
//   //printf("%d\n",printf("hello% ", 0));
// }