/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:19:56 by vholovin          #+#    #+#             */
/*   Updated: 2018/02/06 16:19:57 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_HPP
# define AVM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <exception>
# include <vector>

class Avm
{
	private:
std::string		_status_read;

	public:
				Avm(void);
				Avm(Avm const &ref);
				~Avm(void);

Avm &					operator=(Avm const &ref);
std::string				get_status(void) const;

void					read_file(std::string file_name) throw(Error);
void					read_terminal(void) throw(Error);



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

std::ostream &		operator<<(std::ostream & os, Avm const & ref);
std::ostream &		operator<<(std::ostream & os, Avm::Error const & ref);

#endif
