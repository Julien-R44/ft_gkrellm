/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WindowDisplayer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 06:01:52 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/12 06:14:53 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_DISPLAYER_HPP
# define WINDOW_DISPLAYER_HPP

#include <vector>
#include <iostream>
#include "IMonitorModule.hpp"

class WindowDisplayer {
public:
	WindowDisplayer() {}
	WindowDisplayer(WindowDisplayer const & src) {}
	~WindowDisplayer() {}

	WindowDisplayer &		operator=( WindowDisplayer const & src ) {}

	virtual void			mainLoop(void) {}
private:
	std::vector<IMonitorModule>		_modules;
};

#endif
