/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lu_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:18:53 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/02 16:11:41 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_lu_int(long unsigned int n)
{
    int	len;

	len = 0;
    if (n >= 10)
        len += printf_lu_int(n / 10);
    len += printf_char('0' + n % 10);
    return (len);
}
