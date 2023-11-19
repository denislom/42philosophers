/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:34:34 by dlom              #+#    #+#             */
/*   Updated: 2023/02/05 14:35:57 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed

lst: The node to free.
del: The address of the function used to delete
the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del != NULL)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}
