/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:20:40 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:20:42 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.hpp"

/********************************************************************/

Machine::Machine(void)
{
	_exit = false;
	return;
}

Machine::~Machine(void) throw(Error)
{
	this->exit();
	return;
}

Machine::Machine(Machine const &ref)
{
	*this = ref;
	return;
}

Machine &			Machine::operator=(Machine const &ref)
{
	this->_exit = ref._exit;
	this->_command = ref.get_command();
	this->_operands = ref._operands;
	if (this != &ref)
		*this = ref;
	return *this;
}

std::string 		Machine::get_command(void) const
{
	return (this->_command);
}

/********************************************************************/

Machine::Error::Error(void)
{
	return;
}

Machine::Error::Error(std::string mesenge) : _mesenge(mesenge)
{
	return;
}

Machine::Error::Error(Error const & ref)
{
	*this = ref;
	return;
}

Machine::Error::~Error(void) throw()
{
	return;
}

std::string		Machine::Error::get_error(void) const
{
	return (this->_mesenge);
}

Machine::Error &			Machine::Error::operator=(Error const & ref)
{
	this->_mesenge = ref.get_error();
	if (this != & ref) 
		*this = ref;
	return *this;
}

char const *	 		Machine::Error::what(void) const throw()
{
	return (this->_mesenge.c_str());
}

/********************************************************************/

std::vector<std::string>		ft_split(std::string str)
{
	std::string 				buf;
	std::vector<std::string>	command;

	size_t iter = 0;
	while(iter < str.size())
	{

		if (str.at(iter) != ' ' && str.at(iter) != ';')
			buf.push_back(str.at(iter));
		
		if (str.at(iter) == ' ' || (iter + 1) == str.size())
		{
			if (!buf.empty())
				command.push_back(buf);
			buf.clear();
		}
		
		if (str.at(iter) == ';')
		{
			if (!buf.empty())
				command.push_back(buf);
			break;
		}
		iter++;
	}

	return (command);
}

void							Machine::run(std::string command) throw(Error)
{
	if (this->_exit == true)
		throw Machine::Error("VM has closed");
	else
	{
		this->_command = command;
		std::vector<std::string> split_command = ft_split(command);

		if (split_command.size() == 0)
		{
//			std::cout << "commentar in front" << std::endl;
		}
		else if (split_command[0] == "push" && split_command.size() == 2)
		{
			try
			{
				this->push(split_command[1]);
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "pop" && split_command.size() == 1)
		{
			try
			{
				this->pop();
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "dump" && split_command.size() == 1)
		{
			try
			{
				this->dump();
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "assert" && split_command.size() == 2)
		{
			try
			{
				this->assert(split_command[1]);
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "add" && split_command.size() == 1)
		{	
			try
			{
				this->add();
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "sub" && split_command.size() == 1)
		{	
			try
			{
				this->sub();
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "mul" && split_command.size() == 1)
		{	
			try
			{
				this->mul();
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "div" && split_command.size() == 1)
		{	
			try
			{
				this->div();
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "mod" && split_command.size() == 1)
		{	
			try
			{
				this->mod();
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "print" && split_command.size() == 1)
		{
			try
			{
				this->print();
			}
			catch (std::exception &e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else if (split_command[0] == "exit" && split_command.size() == 1)
			this->_exit = true;
		else
			throw Machine::Error("!" + command + "!:" + "An instruction is unknown");
	}
}

/********************************************************************/

void			Machine::push(std::string command) throw(Error)
{
	Type 		set_type;
	IOperand	*new_element;
	try
	{
		set_type.set_param(command);
		new_element = this->createOperand(set_type.get_enum_type(), set_type.get_value());
		this->_operands.push_back(new_element);
	}
	catch (std::exception &e)
	{
			std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void			Machine::pop(void) throw(Error)
{
	if (this->_operands.size() == 0)
		throw Machine::Error("Instruction pop on an empty stack");
	const IOperand* op = this->_operands.back();
	delete op;
	this->_operands.pop_back();
}

void			Machine::dump(void) throw(Error)
{
	if (this->_operands.size() == 0)
		throw Machine::Error("Instruction dump on an empty stack");
	else
	{
		int iter = this->_operands.size();
		while(iter > 0)
		{
			iter--;
			std::cout << this->_operands.at(iter)->toString() << std::endl;
		}
	}
}

void			Machine::assert(std::string command) throw(Error)
{
	Type 	assert_type;
	if (this->_operands.size() == 0)
		throw Machine::Error("Instruction assert on an empty stack");
	try
	{
		assert_type.set_param(command);
	}
	catch (std::exception &e)
	{
			std::cout << "ERROR: " << e.what() << std::endl;
	}
	const IOperand* op = this->_operands.back();
	if (op->getType() != assert_type.get_enum_type())
		throw Machine::Error("An assert instruction is not true: different type");
	if (op->toString() != assert_type.get_value())
		throw Machine::Error("An assert instruction is not true: different value");
}

void			Machine::add(void) throw(Error)
{
	if (_operands.size() < 2)
		throw Machine::Error("The stack is composed of strictly less that two values when an arithmetic instruction is executed");
	try
	{
		const IOperand* op_1 = this->_operands.at(this->_operands.size() - 1);
		const IOperand* op_2 = this->_operands.at(this->_operands.size() - 2);
		IOperand* rezult  = *op_2 + *op_1;
		delete op_1;
		delete op_2;
		this->_operands.pop_back();
		this->_operands.pop_back();
		this->_operands.push_back(rezult);
	}
	catch (std::exception &e)
	{
			std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void			Machine::sub(void) throw(Error)
{
	if (_operands.size() < 2)
		throw Machine::Error("The stack is composed of strictly less that two values when an arithmetic instruction is executed");
	try
	{
		const IOperand* op_1 = this->_operands.at(this->_operands.size() - 1);
		const IOperand* op_2 = this->_operands.at(this->_operands.size() - 2);
		IOperand* rezult  = *op_2 - *op_1;
		delete op_1;
		delete op_2;
		this->_operands.pop_back();
		this->_operands.pop_back();
		this->_operands.push_back(rezult);
	}
	catch (std::exception &e)
	{
			std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void			Machine::mul(void) throw(Error)
{
	if (_operands.size() < 2)
		throw Machine::Error("The stack is composed of strictly less that two values when an arithmetic instruction is executed");
	try
	{
		const IOperand* op_1 = this->_operands.at(this->_operands.size() - 1);
		const IOperand* op_2 = this->_operands.at(this->_operands.size() - 2);
		IOperand* rezult  = *op_2 * *op_1;
		delete op_1;
		delete op_2;
		this->_operands.pop_back();
		this->_operands.pop_back();
		this->_operands.push_back(rezult);
	}
	catch (std::exception &e)
	{
			std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void			Machine::div(void) throw(Error)
{
	if (_operands.size() < 2)
		throw Machine::Error("The stack is composed of strictly less that two values when an arithmetic instruction is executed");
	try
	{
		const IOperand* op_1 = this->_operands.at(this->_operands.size() - 1);
		const IOperand* op_2 = this->_operands.at(this->_operands.size() - 2);
		IOperand* rezult  = *op_2 / *op_1;
		delete op_1;
		delete op_2;
		this->_operands.pop_back();
		this->_operands.pop_back();
		this->_operands.push_back(rezult);
	}
	catch (std::exception &e)
	{
			std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void			Machine::mod(void) throw(Error)
{
	if (_operands.size() < 2)
		throw Machine::Error("The stack is composed of strictly less that two values when an arithmetic instruction is executed");
	try
	{
		const IOperand* op_1 = this->_operands.at(this->_operands.size() - 1);
		const IOperand* op_2 = this->_operands.at(this->_operands.size() - 2);
		IOperand* rezult  = *op_2 % *op_1;
		delete op_1;
		delete op_2;
		this->_operands.pop_back();
		this->_operands.pop_back();
		this->_operands.push_back(rezult);
	}
	catch (std::exception &e)
	{
			std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void			Machine::print(void) throw(Error)
{
	if (this->_operands.size() == 0)
		throw Machine::Error("Instruction print on an empty stack");
	const IOperand* op = this->_operands.back();
 	if (op->getType() != INT8)
		throw Machine::Error("Instruction print on no 8-bit integer");
 	std::cout << static_cast<char>(std::stoi(op->toString())) << std::endl;
}

/********************************************************************/

IOperand *		Machine::createOperand(eOperandType type, const std::string & value)
{
	IOperand *new_element = NULL;

	switch (type)
	{
		case INT8:
		new_element = this->createInt8(value);
		break;
		
		case INT16:
		new_element = this->createInt16(value);
		break;

		case INT32:
		new_element = this->createInt32(value);
		break;

		case FLOAT:
		new_element = this->createFloat(value);
		break;
		
		case DOUBLE:
		new_element = this->createDouble(value);
		break;
	}
	if (new_element == NULL)
		throw Machine::Error("Can not create new element");		

  return (new_element);
}

IOperand *		Machine::createInt8(const std::string & value)
{
	IOperand *new_element = NULL;
	try
	{
		new_element = new Operand(INT8, value);
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	return(new_element);
}

IOperand *		Machine::createInt16(const std::string & value)
{
	IOperand *new_element = NULL;
	try
	{
		new_element = new Operand(INT16, value);
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	return(new_element);
}

IOperand *		Machine::createInt32(const std::string & value)
{
	IOperand *new_element = NULL;
	try
	{
		new_element = new Operand(INT32, value);
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	return(new_element);
}

IOperand *		Machine::createFloat(const std::string & value)
{
	IOperand *new_element = NULL;
	try
	{
		new_element = new Operand(FLOAT, value);
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	return(new_element);
}

IOperand *		Machine::createDouble(const std::string & value)
{
	IOperand *new_element = NULL;
	try
	{
		new_element = new Operand(DOUBLE, value);
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	return(new_element);
}

/********************************************************************/

void			Machine::exit(void) throw(Error)
{	
	while (!this->_operands.empty())
	{
		const IOperand* op = this->_operands.back();
		delete op;
		this->_operands.pop_back();
	}

	if(!_exit)
		throw Machine::Error("No match for instruction exit");
}

/********************************************************************/

std::ostream &			operator<<(std::ostream &os, Machine const & ref)
{
		os << ref.get_command();
		return os;
}

std::ostream &			operator<<(std::ostream &os, Machine::Error const & ref)
{
	os << ref.get_error();
	return os;
}
