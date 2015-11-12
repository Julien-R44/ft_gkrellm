/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curseWindowDisplayer.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 05:51:15 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/12 06:02:22 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSE_WINDOW_DISPLAYER_HPP
# define CURSE_WINDOW_DISPLAYER_HPP

#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include "WindowDisplayer.hpp"

class curseWindowDisplayer : public WindowDisplayer {
public:
	typedef enum	e_keys {
		ECHAP = 27,
		K_SPACE = 32,
		K_RIGHT = 261,
		K_LEFT = 260,
		K_UP = 259,
		K_DOWN = 258,
		K_ONE = 49,
		K_TWO = 50,
		K_THREE = 51
	}				t_keys;

	curseWindowDisplayer();
	curseWindowDisplayer(curseWindowDisplayer const & src);
	~curseWindowDisplayer();

	curseWindowDisplayer &		operator=( curseWindowDisplayer const & src );

	void		mainLoop();
};

#endif
