/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:20:51 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:20:52 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"

int		main(int argc, char** argv)
{
	if (argc > 2)
		std::cout << "to much argument: use ./avm or ./avm <file>" << std::endl;
	else
	{
		try
		{
			Avm avm;
			if (argc == 2)
				avm.read_file((std::string)argv[1]);
			else
				avm.read_terminal();
		}
		catch (std::exception &e)
		{
			std::cout << "ERROR: " << e.what() << std::endl;
		}
	}
	return (0);
}
