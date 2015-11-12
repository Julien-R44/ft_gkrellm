/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfmlWindowDisplayer.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 05:38:56 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/12 06:02:40 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_WINDOW_DISPLAYER_HPP
# define SFML_WINDOW_DISPLAYER_HPP

#include <SFML/Graphics.hpp>
#include "WindowDisplayer.hpp"

class sfmlWindowDisplayer : public WindowDisplayer, public sf::RenderWindow {
public:
	sfmlWindowDisplayer(void);
	sfmlWindowDisplayer(sfmlWindowDisplayer const & src);
	~sfmlWindowDisplayer(void);

	sfmlWindowDisplayer &		operator=( sfmlWindowDisplayer const & src );

	void	mainLoop(void);

};


#endif
