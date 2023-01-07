/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:36 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:39 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*buffer;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		buffer = *lst;
		*lst = (*lst)->next;
		del(buffer->content);
		free(buffer);
	}
	lst = NULL;
}
