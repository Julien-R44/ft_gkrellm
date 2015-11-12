/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfmlWindowDisplayer.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 05:42:39 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/12 06:17:17 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfmlWindowDisplayer.hpp"

sfmlWindowDisplayer::sfmlWindowDisplayer( void ):
	sf::RenderWindow(sf::VideoMode(200, 600, 32), "ft_gkrellm")
{
	return ;
}

sfmlWindowDisplayer::sfmlWindowDisplayer( sfmlWindowDisplayer const & src ) {
	*this = src;
	return;
}

sfmlWindowDisplayer::~sfmlWindowDisplayer( void ) {
	return;
}

sfmlWindowDisplayer &	sfmlWindowDisplayer::operator=( sfmlWindowDisplayer const & src ) {
	return *this;
}

void		sfmlWindowDisplayer::mainLoop(void) {
	while (isOpen()) {

		// HOOK
		sf::Event event;
		while (pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				close();
		}

		// DISPLAY
		clear();
		display();
	}
}
