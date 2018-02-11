/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:20:56 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:20:57 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operand.hpp"

/********************************************************************/

Operand::Operand(void)
{
	return;
}

Operand::~Operand(void)
{
	return;
}

Operand::Operand(Operand const &ref)
{
	*this = ref;
	return;
}

Operand &			Operand::operator=(Operand const &ref)
{
	this->_value_str = ref._value_str;
	this->_precision = ref._precision;
	this->_type = ref._type;
	
	if (this != &ref)
		*this = ref;
	return *this;
}

/********************************************************************/

Operand::Error::Error(void)
{
	return;
}

Operand::Error::Error(std::string mesenge) : _mesenge(mesenge)
{
	return;
}

Operand::Error::Error(Error const & ref)
{
	*this = ref;
	return;
}

Operand::Error::~Error(void) throw()
{
	return;
}

std::string					Operand::Error::get_error(void) const
{
	return (this->_mesenge);
}

Operand::Error &			Operand::Error::operator=(Error const & ref)
{
	this->_mesenge = ref.get_error();
	if (this != & ref) 
		*this = ref;
	return *this;
}

char const *	 			Operand::Error::what(void) const throw()
{
	return (this->_mesenge.c_str());
}

/********************************************************************/

IOperand *			Operand::operator+( IOperand const & ref ) const
{
	eOperandType type = ( this->_type >= ref.getType() ) ? this->_type : ref.getType();
	int precision = ( this->_precision >= ref.getPrecision() ) ? this->_precision: ref.getPrecision();

	switch (type)
	{
		case INT8:
		{
			long long rezult = std::stoll(this->_value_str) + std::stoll(ref.toString());
			if (rezult < SCHAR_MIN)
				throw Operand::Error("Underflow add on a rezult");
			else if (rezult > SCHAR_MAX)
				throw Operand::Error("Overflow add on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT8, ss.str()));
			}
		}
		break;
		
		case INT16:
		{
			long long rezult = std::stoll(this->_value_str) + std::stoll(ref.toString());
			if (rezult < SHRT_MIN)
				throw Operand::Error("Underflow add on a rezult");
			else if (rezult > SHRT_MAX)
				throw Operand::Error("Overflow add on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT16, ss.str()));
			}
		}
		break;

		case INT32:
		{
			long long rezult = std::stoll(this->_value_str) + std::stoll(ref.toString());
			if (rezult < INT_MIN)
				throw Operand::Error("Underflow add on a rezult");
			else if (rezult > INT_MAX)
				throw Operand::Error("Overflow add on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT32, ss.str()));
			}
		}
		break;

		case FLOAT:
		{
			long double rezult = std::stold(this->_value_str) + std::stold(ref.toString());
			if (rezult < -FLT_MIN)
				throw Operand::Error("Underflow add on a rezult");
			else if (rezult > FLT_MAX)
				throw Operand::Error("Overflow add on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << std::setprecision(precision) << rezult;
				return (new Operand(FLOAT, ss.str()));
			}
		}
		break;
		
		case DOUBLE:
		{
			long double rezult = std::stold(this->_value_str) + std::stold(ref.toString());
			if (rezult < -DBL_MAX)
				throw Operand::Error("Underflow add on a rezult");
			else if (rezult > DBL_MAX)
				throw Operand::Error("Overflow add on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << std::setprecision(precision) << rezult;
				return (new Operand(DOUBLE, ss.str()));
			}
		}
		break;
	}
	return (0);
}

IOperand *			Operand::operator-( IOperand const & ref ) const
{
	eOperandType type = ( this->_type >= ref.getType() ) ? this->_type : ref.getType();
	int precision = ( this->_precision >= ref.getPrecision() ) ? this->_precision: ref.getPrecision();

	switch (type)
	{
		case INT8:
		{
			long long rezult = std::stoll(this->_value_str) - std::stoll(ref.toString());
			if (rezult < SCHAR_MIN)
				throw Operand::Error("Underflow sub on a rezult");
			else if (rezult > SCHAR_MAX)
				throw Operand::Error("Overflow sub on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT8, ss.str()));
			}
		}
		break;
		
		case INT16:
		{
			long long rezult = std::stoll(this->_value_str) - std::stoll(ref.toString());
			if (rezult < SHRT_MIN)
				throw Operand::Error("Underflow sub on a rezult");
			else if (rezult > SHRT_MAX)
				throw Operand::Error("Overflow sub on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT16, ss.str()));
			}
		}
		break;

		case INT32:
		{
			long long rezult = std::stoll(this->_value_str) - std::stoll(ref.toString());
			if (rezult < INT_MIN)
				throw Operand::Error("Underflow sub on a rezult");
			else if (rezult > INT_MAX)
				throw Operand::Error("Overflow sub on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT32, ss.str()));
			}
		}
		break;

		case FLOAT:
		{
			long double rezult = std::stold(this->_value_str) - std::stold(ref.toString());
			if (rezult < -FLT_MIN)
				throw Operand::Error("Underflow sub on a rezult");
			else if (rezult > FLT_MAX)
				throw Operand::Error("Overflow sub on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << std::setprecision(precision) << rezult;
				return (new Operand(FLOAT, ss.str()));
			}
		}
		break;
		
		case DOUBLE:
		{
			long double rezult = std::stold(this->_value_str) - std::stold(ref.toString());
			if (rezult < -DBL_MAX)
				throw Operand::Error("Underflow sub on a rezult");
			else if (rezult > DBL_MAX)
				throw Operand::Error("Overflow sub on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << std::setprecision(precision) << rezult;
				return (new Operand(DOUBLE, ss.str()));
			}
		}
		break;
	}
	return (0);
}

IOperand *			Operand::operator*( IOperand const & ref ) const
{
	eOperandType type = ( this->_type >= ref.getType() ) ? this->_type : ref.getType();
	int precision = ( this->_precision >= ref.getPrecision() ) ? this->_precision: ref.getPrecision();

	switch (type)
	{
		case INT8:
		{
			long long rezult = std::stoll(this->_value_str) * std::stoll(ref.toString());
			if (rezult < SCHAR_MIN)
				throw Operand::Error("Underflow mul on a rezult");
			else if (rezult > SCHAR_MAX)
				throw Operand::Error("Overflow mul on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT8, ss.str()));
			}
		}
		break;
		
		case INT16:
		{
			long long rezult = std::stoll(this->_value_str) * std::stoll(ref.toString());
			if (rezult < SHRT_MIN)
				throw Operand::Error("Underflow mul on a rezult");
			else if (rezult > SHRT_MAX)
				throw Operand::Error("Overflow mul on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT16, ss.str()));
			}
		}
		break;

		case INT32:
		{
			long long rezult = std::stoll(this->_value_str) * std::stoll(ref.toString());
			if (rezult < INT_MIN)
				throw Operand::Error("Underflow mul on a rezult");
			else if (rezult > INT_MAX)
				throw Operand::Error("Overflow mul on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << rezult;
				return (new Operand(INT32, ss.str()));
			}
		}
		break;

		case FLOAT:
		{
			long double rezult = std::stold(this->_value_str) * std::stold(ref.toString());
			if (rezult < -FLT_MIN)
				throw Operand::Error("Underflow mul on a rezult");
			else if (rezult > FLT_MAX)
				throw Operand::Error("Overflow mul on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << std::setprecision(precision) << rezult;
				return (new Operand(FLOAT, ss.str()));
			}
		}
		break;
		
		case DOUBLE:
		{
			long double rezult = std::stold(this->_value_str) * std::stold(ref.toString());
			if (rezult < -DBL_MAX)
				throw Operand::Error("Underflow mul on a rezult");
			else if (rezult > DBL_MAX)
				throw Operand::Error("Overflow mul on a rezult");
			else
			{
				std::stringstream ss (std::stringstream::out);
				ss << std::setprecision(precision) << rezult;
				return (new Operand(DOUBLE, ss.str()));
			}
		}
		break;
	}
	return (0);
}

IOperand *			Operand::operator/( IOperand const & ref ) const
{
	eOperandType type = ( this->_type >= ref.getType() ) ? this->_type : ref.getType();
	int precision = ( this->_precision >= ref.getPrecision() ) ? this->_precision: ref.getPrecision();

	if (std::stold(ref.toString()) == 0)
		throw Operand::Error("Div by zero!");
	else
	{
		switch (type)
		{
			case INT8:
			{
				long long rezult = std::stoll(this->_value_str) / std::stoll(ref.toString());
				if (rezult < SCHAR_MIN)
					throw Operand::Error("Underflow div on a rezult");
				else if (rezult > SCHAR_MAX)
					throw Operand::Error("Overflow div on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << rezult;
					return (new Operand(INT8, ss.str()));
				}
			}
			break;
			
			case INT16:
			{
				long long rezult = std::stoll(this->_value_str) / std::stoll(ref.toString());
				if (rezult < SHRT_MIN)
					throw Operand::Error("Underflow div on a rezult");
				else if (rezult > SHRT_MAX)
					throw Operand::Error("Overflow div on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << rezult;
					return (new Operand(INT16, ss.str()));
				}
			}
			break;

			case INT32:
			{
				long long rezult = std::stoll(this->_value_str) / std::stoll(ref.toString());
				if (rezult < INT_MIN)
					throw Operand::Error("Underflow div on a rezult");
				else if (rezult > INT_MAX)
					throw Operand::Error("Overflow div on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << rezult;
					return (new Operand(INT32, ss.str()));
				}
			}
			break;

			case FLOAT:
			{
				long double rezult = std::stold(this->_value_str) / std::stold(ref.toString());
				if (rezult < -FLT_MIN)
					throw Operand::Error("Underflow div on a rezult");
				else if (rezult > FLT_MAX)
					throw Operand::Error("Overflow div on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << std::setprecision(precision) << rezult;
					return (new Operand(FLOAT, ss.str()));
				}
			}
			break;
		
			case DOUBLE:
			{
				long double rezult = std::stold(this->_value_str) / std::stold(ref.toString());
				if (rezult < -DBL_MAX)
					throw Operand::Error("Underflow div on a rezult");
				else if (rezult > DBL_MAX)
					throw Operand::Error("Overflow div on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << std::setprecision(precision) << rezult;
					return (new Operand(DOUBLE, ss.str()));
				}
			}
			break;
		}
	}
	return (0);
}

IOperand *			Operand::operator%( IOperand const & ref ) const
{
	eOperandType type = ( this->_type >= ref.getType() ) ? this->_type : ref.getType();
	int precision = ( this->_precision >= ref.getPrecision() ) ? this->_precision: ref.getPrecision();

	if (std::stold(ref.toString()) == 0)
		throw Operand::Error("Mod by zero!");
	else
	{
		switch (type)
		{
			case INT8:
			{
				long long rezult = std::stoll(this->_value_str) % std::stoll(ref.toString());
				if (rezult < SCHAR_MIN)
					throw Operand::Error("Underflow mod on a rezult");
				else if (rezult > SCHAR_MAX)
					throw Operand::Error("Overflow mod on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << rezult;
					return (new Operand(INT8, ss.str()));
				}
			}
			break;
			
			case INT16:
			{
				long long rezult = std::stoll(this->_value_str) % std::stoll(ref.toString());
				if (rezult < SHRT_MIN)
					throw Operand::Error("Underflow mod on a rezult");
				else if (rezult > SHRT_MAX)
					throw Operand::Error("Overflow mod on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << rezult;
					return (new Operand(INT16, ss.str()));
				}
			}
			break;

			case INT32:
			{
				long long rezult = std::stoll(this->_value_str) % std::stoll(ref.toString());
				if (rezult < INT_MIN)
					throw Operand::Error("Underflow mod on a rezult");
				else if (rezult > INT_MAX)
					throw Operand::Error("Overflow mod on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << rezult;
					return (new Operand(INT32, ss.str()));
				}
			}
			break;

			case FLOAT:
			{
				long double rezult = fmod(std::stold(this->_value_str), std::stold(ref.toString()));
				if (rezult < -FLT_MIN)
					throw Operand::Error("Underflow mod on a rezult");
				else if (rezult > FLT_MAX)
					throw Operand::Error("Overflow mod on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << std::setprecision(precision) << rezult;
					return (new Operand(FLOAT, ss.str()));
				}
			}
			break;
		
			case DOUBLE:
			{
				long double rezult = fmod(std::stold(this->_value_str), std::stold(ref.toString()));
				if (rezult < -DBL_MAX)
					throw Operand::Error("Underflow mod on a rezult");
				else if (rezult > DBL_MAX)
					throw Operand::Error("Overflow mod on a rezult");
				else
				{
					std::stringstream ss (std::stringstream::out);
					ss << std::setprecision(precision) << rezult;
					return (new Operand(DOUBLE, ss.str()));
				}
			}
			break;
		}
	}
	return (0);
}

/********************************************************************/

Operand::Operand(eOperandType type, std::string const & value) throw(Error)
{
	this->_type = type;
	switch (this->_type)
	{
		case INT8:
		{
			bool		status = true;
			long long	rezult;
			try
			{
				rezult = std::stoll(value);
			}
			catch (std::exception &e)
			{
				status = false;
				std::cout << "ERROR: " << e.what() << std::endl;
			}
			if (status == true)
			{
				if (rezult < SCHAR_MIN)
					throw Operand::Error("Underflow on a value");
				else if (rezult > SCHAR_MAX)
					throw Operand::Error("Overflow on a value");
				else
				{
					this->_precision = 0;
					std::stringstream ss(std::stringstream::out);
					ss << std::setprecision(this->_precision) << rezult;
					this->_value_str = ss.str();
				}
			}
			else
				throw Operand::Error("Operand not found");
		}
		break;
		
		case INT16:
		{
			bool		status = true;
			long long	rezult;
			try
			{
				rezult = std::stoll(value);
			}
			catch (std::exception &e)
			{
				status = false;
				std::cout << "ERROR: " << e.what() << std::endl;
			}
			if (status == true)
			{
				if (rezult < SHRT_MIN)
					throw Operand::Error("Underflow on a value");
				else if (rezult > SHRT_MAX)
					throw Operand::Error("Overflow on a value");
				else
				{
					this->_precision = 0;
					std::stringstream ss(std::stringstream::out);
					ss << std::setprecision(this->_precision) << rezult;
					this->_value_str = ss.str();
				}
			}
			else
				throw Operand::Error("Operand not found");
		}
		break;

		case INT32:
		{
			bool		status = true;
			long long	rezult;
			try
			{
				rezult = std::stoll(value);
			}
			catch (std::exception &e)
			{
				status = false;
				std::cout << "ERROR: " << e.what() << std::endl;
			}
			if (status == true)
			{
				if (rezult < INT_MIN)
					throw Operand::Error("Underflow on a value");
				else if (rezult > INT_MAX)
					throw Operand::Error("Overflow on a value");
				else
				{
					this->_precision = 0;
					std::stringstream ss(std::stringstream::out);
					ss << std::setprecision(this->_precision) << rezult;
					this->_value_str = ss.str();
				}
			}
			else
				throw Operand::Error("Operand not found");
		}
		break;

		case FLOAT:
		{
			bool		status = true;
			long double	rezult;
			try
			{
				rezult = std::stold(value);
			}
			catch (std::exception &e)
			{
				status = false;
				std::cout << "ERROR: " << e.what() << std::endl;
			}
			if (status == true)
			{
				if (rezult < -FLT_MAX)
					throw Operand::Error("Underflow on a value");
				else if (rezult > FLT_MAX)
					throw Operand::Error("Overflow on a value");
				else
				{
					this->_precision = FLT_DIG;
					std::stringstream ss(std::stringstream::out);
					ss << std::setprecision(this->_precision) << rezult;
					this->_value_str = ss.str();
				}
			}
			else
				throw Operand::Error("Operand not found");
		}
		break;
		
		case DOUBLE:
		{
			bool		status = true;
			long double	rezult;
			try
			{
				rezult = std::stold(value);
			}
			catch (std::exception &e)
			{
				status = false;
				std::cout << "ERROR: " << e.what() << std::endl;
			}
			if (status == true)
			{
				if (rezult < -DBL_MAX)
					throw Operand::Error("Underflow on a value");
				else if (rezult > DBL_MAX)
					throw Operand::Error("Overflow on a value");
				else
				{
					this->_precision = DBL_DIG;
					std::stringstream ss(std::stringstream::out);
					ss << std::setprecision(this->_precision) << rezult;
					this->_value_str = ss.str();
				}
			}
			else
				throw Operand::Error("Operand not found");
		}
		break;
	}
}

/********************************************************************/

int 						Operand::getPrecision( void ) const
{
	return (this->_precision);
}

eOperandType 				Operand::getType( void ) const
{
	return (this->_type);
}

std::string const &			Operand::toString( void ) const
{
	return (this->_value_str);	
}

/********************************************************************/

std::ostream &			operator<<(std::ostream &os, Operand const & ref)
{
		os << ref.getType() << " : " << ref.toString() << " : " << ref.getPrecision();
		return os;
}

std::ostream &			operator<<(std::ostream &os, Operand::Error const & ref)
{
	os << ref.get_error();
	return os;
}
