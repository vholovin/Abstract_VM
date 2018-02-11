/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:20:09 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:20:10 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define	OPERAND_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <exception>
#include <math.h>
#include <float.h>


# include "IOperand.hpp"

class Operand : public IOperand
{
	private:
std::string		_value_str;
int				_precision;
eOperandType	_type;

	public:
				Operand(void);
				Operand(Operand const &ref);
				Operand(eOperandType type, std::string const & value) throw(Error);
				~Operand(void);

Operand &				operator=(Operand const &ref);
IOperand *				operator+(const IOperand & ref) const;
IOperand *				operator-(const IOperand & ref) const;
IOperand *				operator*(const IOperand & ref) const;
IOperand *				operator/(const IOperand & ref) const;
IOperand *				operator%(const IOperand & ref) const;

int 					getPrecision(void) const;
eOperandType			getType(void) const;
std::string const &		toString(void) const;



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

std::ostream &		operator<<(std::ostream & os, Operand const & ref);
std::ostream &		operator<<(std::ostream & os, Operand::Error const & ref);

#endif
