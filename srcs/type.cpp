/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:21:02 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:21:03 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.hpp"

/********************************************************************/

Type::Type(void)
{
	return;
}

Type::~Type(void)
{
	return;
}

Type::Type(Type const &ref)
{
	*this = ref;
	return;
}

Type &			Type::operator=(Type const &ref)
{
	this->_type = ref.get_type();
	this->_value = ref.get_value();
	if (this != &ref)
		*this = ref;
	return *this;
}


std::string			Type::get_type(void) const
{
	return(this->_type);
}

std::string			Type::get_value(void) const
{
	return(this->_value);
}

eOperandType	Type::get_enum_type(void) const
{
	if (this->_type.compare("int8") == 0)
		return (INT8);
	else if (this->_type.compare("int16") == 0)
		return (INT16);
	else if (this->_type.compare("int32") == 0)
		return (INT32);
	else if (this->_type.compare("float") == 0)
		return (FLOAT);
	else if (this->_type.compare("double") == 0)
		return (DOUBLE);
	
	return (DOUBLE);
}

/********************************************************************/

Type::Error::Error(void)
{
	return;
}

Type::Error::Error(std::string mesenge) : _mesenge(mesenge)
{
	return;
}

Type::Error::Error(Error const & ref)
{
	*this = ref;
	return;
}

Type::Error::~Error(void) throw()
{
	return;
}

std::string				Type::Error::get_error(void) const
{
	return (this->_mesenge);
}

Type::Error &			Type::Error::operator=(Error const & ref)
{
	this->_mesenge = ref.get_error();
	if (this != & ref) 
		*this = ref;
	return *this;
}

char const *	 		Type::Error::what(void) const throw()
{
	return (this->_mesenge.c_str());
}

/********************************************************************/

void 					Type::set_param(std::string command) throw(Error)
{
	this->set_type(&command);
	this->set_value(&command);
}

void					Type::set_type(std::string *type) throw(Error)
{
	if (type->compare(0, 4, "int8") == 0)
	{
		_type = "int8";
		type->erase(type->begin(), type->begin() + 4);
	}
	else if (type->compare(0, 5, "int16") == 0)
	{
		_type = "int16";
		type->erase(type->begin(), type->begin() + 5);
	}
	else if (type->compare(0, 5, "int32") == 0)
	{
		_type = "int32";
		type->erase(type->begin(), type->begin() + 5);
	}
	else if (type->compare(0, 5, "float") == 0)
	{
		_type = "float";
		type->erase(type->begin(), type->begin() + 5);
	}
	else if (type->compare(0, 6, "double") == 0)
	{
		_type = "double";
		type->erase(type->begin(), type->begin() + 6);
	}
	else
		throw Type::Error("!" + *type + "!:" + "Unknown type");
}

void					Type::set_value(std::string *value) throw(Error)
{
	if (value->front() == '(' && value->back() == ')')
	{
		value->erase(value->begin());
		value->erase(value->end() - 1);

		int 		status_error = 0;
		int 		status_digit = 0;
		int 		status_minus = 0;
		int 		status_point = 0;
		std::string buff = *value;

		if (this->_type == "int8" || this->_type == "int16" || this->_type == "int32")
			status_point = 1;

		while (!value->empty() && status_error == 0)
		{
			if (std::isdigit(value->front()))
			{
				this->_value += value->front();
				status_digit++;
			}
			else if (value->front() == '-')
			{
				if (status_digit != 0)
					status_error++;
				this->_value += value->front();
				status_minus++;
			}
			else if (value->front() == '.')
			{
				if (status_digit == 0 || status_point != 0)
					status_error++;
				this->_value += value->front();
				status_point++;
			}
			value->erase(value->begin());	
		}
		if (status_error != 0)
			throw Type::Error("!" + buff + "!:" + "GRAMMAR ERROR");
	}
	else
		throw Type::Error("!" + *value + "!:" + "GRAMMAR ERROR");
}

/********************************************************************/

std::ostream &			operator<<(std::ostream &os, Type const & ref)
{
		os << ref.get_type() << ":" << ref.get_value();
		return os;
}

std::ostream &			operator<<(std::ostream &os, Type::Error const & ref)
{
	os << ref.get_error();
	return os;
}
