/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curseWindowDisplayer.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 05:51:15 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/12 05:57:09 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "curseWindowDisplayer.hpp"

curseWindowDisplayer::curseWindowDisplayer( void ) {
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	srand(time(NULL));
	return ;
}

curseWindowDisplayer::curseWindowDisplayer( curseWindowDisplayer const & src ) {
	*this = src;
	return;
}

curseWindowDisplayer::~curseWindowDisplayer( void ) {
	endwin();
	return;
}

curseWindowDisplayer &	curseWindowDisplayer::operator=( curseWindowDisplayer const & src ) {
	return *this;
}

void	curseWindowDisplayer::mainLoop(void) {
	while (77) {
		int ch;

		while (ch = getch()) {
			if (ch == ERR)
				break ;
			else if (ch == ECHAP)
				return ;
		}

		clear();
		refresh();
	}
}
