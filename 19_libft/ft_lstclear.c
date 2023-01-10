/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:36 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/10 15:52:02 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*buffer;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		buffer = *lst;
		*lst = (*lst)->next;
		free(buffer);
	}
	lst = NULL;
}
