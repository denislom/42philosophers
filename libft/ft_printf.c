/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:04:45 by dlom              #+#    #+#             */
/*   Updated: 2023/02/11 22:04:45 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ft_printf.h>
#include "libft.h"
/* [1] FROM: PRINZ, Peter a Ulla KIRCH-PRINZ. C Pocket Reference. O'REILLY,
2003. ISBN 978-0-596-00436-1.
1. declare an object of type va_list (named arglist)
	-va_list: the optional arguments are accessed through va_list
2. Invoke the macro va_start to prepare arglist object to
	return the first optional argument
	- the parametres of va_start are the arglist object and the name of the last 
	mandatory parameter.
3. Invoke the macro va_arg with the initialized arglist object to obtain each of
	the optional arguments in sequence. The second parameter of va_arg is the 
	type of the optional argument that is being obtained.
	After those invocations the arglist object is prepared to deliver the first 
	optional argument that has not yet been read.
4. After reading out the argument list the function should invoke the va_end 
macro
	before returning control to the caller.
	- The only parametre of va_end is the arglist object.

[2] FROM: PRINZ, Peter a Tony. C in a Nutshell: THE DEFINITIVE REFERENCE.
2nd Edition. Sebastopol: O'REILLY, 2016. ISBN 978-1-491-90475-6.

EXAMPLE OF PRINTF
int	score = 120;
char	player[] = "Mary";
printf("%s has %d points. \n", player, score);

THE HEADER stdarg.h defines one type and four macros for use in accessing the
optional arguments of functions that support them.

va_list: object commonly called an argument pointer, serves as a reference
	to a list of optional arguments.
va_start: macro, sets the argument pointer to the first optional 
	argument in the list.
va_arg(): macro, returns the current argument and sets the argument 
	pointer to the next one in the list.
va_copy(): macro, copies the va_list object in its current state.
va_end(): macro, cleans up after the use of a va+list object. A 
	function with a variable number of arguments must contain
	a va_end() macro call corresponding to each invocation
	of va_start() or va_copy().

Macros va_copy() and va_end() may also be implemented as functions.

Variadic functions (functions with a variable number of arguments) require a 
fixed numberof mandatory arguments (at least 1), followed by
a variable number of optional arguments.
Examples are printf(), scanf().
The number of optional arguments is either determined by the values
of the mandatory arguments or by a special value that terminates
the list of optional arguments.

Printf() has one mandatory argument of format string (char *str).
The conversion specifiers in the format string determine the number 
and the types of the the optional arguments.
int	ft_printf(char *str, ...)
... stands for the optional arguments.

void	va_start(va_list, argptr, lastparam);
	This macro initializes the argument pointer argptr with the position 
	of the first 
	optional argument. The macros's second argument must be the name of 
	the function's
	last named parameter. This macro must be called before the function 
	can use the 
	optional arguments.
type	va_arg(va_list argptr, type);
	This macro expands to yield the optional argument currently referenced
	by argptr,
	and also advances argptr to reference the next argument in the list.
	The second argument of the macro va_arg is the type of the argument 
	being read.
void	va_end(va_list argptr);
	Call it when you have finished using an argument pointer. Necessary 
	before
	reinitializing an argument pointer by va_start() or va_copy().
void	copy(va_list dest, va_list src);
	This macro initializes the argument pointer dest with the current 
	values of src.
*/

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_variable(va_list argptr, char format)
{
	int	num_char;

	num_char = 0;
	if (format == 'c')
		num_char = ft_putchar(va_arg(argptr, int));
	else if (format == 's')
		num_char = ft_putstr(va_arg(argptr, char *));
	else if (format == 'p')
		num_char = ft_print_pointer(va_arg(argptr, uintptr_t));
	else if (format == 'd' || format == 'i')
		num_char = ft_print_decimal_number(va_arg(argptr, int));
	else if (format == 'u')
		num_char = ft_print_unsigned_decimal(va_arg(argptr, unsigned int));
	else if (format == 'x' || format == 'X')
		num_char = ft_print_hexadecimal(va_arg(argptr, int), format);
	else if (format == '%')
	{
		num_char = 1;
		ft_putchar(format);
	}
	return (num_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		printed_chars;

	i = 0;
	printed_chars = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed_chars = printed_chars + print_variable(argptr, str[i + 1]);
			i = i + 2;
		}
		else
		{
			printed_chars = printed_chars + ft_putchar(str[i]);
			i++;
		}
	}
	va_end(argptr);
	return (printed_chars);
}
