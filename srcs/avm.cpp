/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:20:34 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:20:35 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"
#include "machine.hpp"

/********************************************************************/

Avm::Avm(void)
{
	return;
}

Avm::~Avm(void)
{
	return;
}

Avm::Avm(Avm const &ref)
{
	*this = ref;
	return;
}

Avm &		Avm::operator=(Avm const &ref)
{
	this->_status_read = ref.get_status();
	if (this != &ref)
		*this = ref;
	return *this;
}

std::string	Avm::get_status(void) const
{
	return(this->_status_read);
}

/********************************************************************/

Avm::Error::Error(void)
{
	return;
}

Avm::Error::Error(std::string mesenge) : _mesenge(mesenge)
{
	return;
}

Avm::Error::Error(Error const & ref)
{
	*this = ref;
	return;
}

Avm::Error::~Error(void) throw()
{
	return;
}

std::string		Avm::Error::get_error(void) const
{
	return (this->_mesenge);
}

Avm::Error &			Avm::Error::operator=(Error const & ref)
{
	this->_mesenge = ref.get_error();
	if (this != & ref) 
		*this = ref;
	return *this;
}

char const *	 		Avm::Error::what(void) const throw()
{
	return (this->_mesenge.c_str());
}

/********************************************************************/

void 		Avm::read_file(std::string file_name) throw(Error)
{
	std::ifstream	file(file_name.c_str(), std::ios::in);
	std::string		command;
	size_t			number_error = 0;

	this->_status_read = "read_file";
	if (file)
	{
		Machine			*VM = new Machine();

		while (std::getline(file, command))
		{
			if (!command.empty())
			{
				try
				{
					VM->run(command);
				}
				catch (std::exception &e)
				{
					number_error++;
					std::cout << "ERROR: " << e.what() << std::endl;
				}
			}
		}
		file.close();
		try
		{
			delete (VM);
		}
		catch (std::exception &e)
		{
			std::cout << "ERROR: " << e.what() << std::endl;
		}
		if (number_error != 0)
			throw Avm::Error("The assembly program includes one or several lexical errors or syntactic errors or input after exit");
	}
	else
		throw Avm::Error("File not found");
}

void 		Avm::read_terminal(void) throw(Error)
{
	std::string		command;
	Machine			*VM = new Machine();
	size_t			number_error = 0;

	this->_status_read = "read_terminal";
	while (getline(std::cin, command) && command.find(";;") != 0)
	{
		if (!command.empty())
		{
			try
			{
				VM->run(command);
			}
			catch (std::exception &e)
			{
				number_error++;
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
	}
	try
	{
		delete (VM);
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	if (number_error != 0)
		throw Avm::Error("The assembly program includes one or several lexical errors or syntactic errors or input after exit");
}

/********************************************************************/

std::ostream &			operator<<(std::ostream &os, Avm const & ref)
{
		os << ref.get_status();
		return os;
}

std::ostream &			operator<<(std::ostream &os, Avm::Error const & ref)
{
	os << ref.get_error();
	return os;
}
