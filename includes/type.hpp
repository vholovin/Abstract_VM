/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:20:16 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:20:18 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HPP
# define TYPE_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <string>

# include "IOperand.hpp"
# include "machine.hpp"

class Type
{
	private:
std::string		_type;
std::string		_value;

	public:
				Type(void);
				Type(Type const &ref);
				~Type(void);

Type &					operator=(Type const &ref);

std::string				get_type(void) const;
eOperandType			get_enum_type(void) const;
std::string				get_value(void) const;

void					set_param(std::string command) throw(Error);
void					set_type(std::string *type) throw (Error);
void					set_value(std::string *value) throw (Error);



			class 		Error: public std::exception
			{
				private:
			std::string		_mesenge;

				public:
							Error(void);
							Error(std::string mesenge);
							 Error(Error const &ref);
							 ~Error(void) throw();

			std::string				get_error() const;
			Error &					operator=(Error const &ref);

			virtual	char const *	what(void) const throw();
			};



};

std::ostream &		operator<<(std::ostream & os, Type const & ref);
std::ostream &		operator<<(std::ostream & os, Type::Error const & ref);

#endif
