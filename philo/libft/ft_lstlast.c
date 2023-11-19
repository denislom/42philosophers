/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:30:27 by dlom              #+#    #+#             */
/*   Updated: 2023/02/05 14:32:21 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
RETURNS the las node of the list.
lst: beginning of the list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
