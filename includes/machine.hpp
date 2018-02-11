/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:20:02 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:20:03 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_HPP
# define MACHINE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <exception>

# include "operand.hpp"
# include "type.hpp"

class Machine
{
	private:
bool						_exit;
std::string					_command;
std::vector<IOperand *>		_operands;

IOperand *	createOperand(eOperandType type, const std::string & value);
IOperand *	createInt8(const std::string &);
IOperand *	createInt16(const std::string &);
IOperand *	createInt32(const std::string &);
IOperand *	createFloat(const std::string &);
IOperand *	createDouble(const std::string &);

	public:
				Machine(void);
				Machine(Machine const &ref);
				~Machine(void) throw(Error);

Machine &				operator=(Machine const &ref);
std::string				get_command(void) const;



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



void					run(std::string command) throw(Error);

void					push(std::string command) throw(Error);
void					pop(void) throw(Error);
void					dump(void) throw(Error);
void					assert(std::string command) throw(Error);
void					add(void) throw(Error);
void					sub(void) throw(Error);
void					mul(void) throw(Error);
void					div(void) throw(Error);
void					mod(void) throw(Error);
void					print(void) throw(Error);

void					exit(void) throw(Error);
};

std::ostream &		operator<<(std::ostream & os, Machine const & ref);
std::ostream &		operator<<(std::ostream & os, Machine::Error const & ref);

#endif
