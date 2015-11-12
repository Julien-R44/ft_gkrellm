/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 04:11:37 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/12 06:12:40 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "sfmlWindowDisplayer.hpp"
#include "curseWindowDisplayer.hpp"

int main(void) {

 	// sf::cursesWindowDisplayer window();

	sfmlWindowDisplayer window;
	WindowDisplayer *displayer = &window;

	// window.init();
	window.mainLoop();

	// sf::Font font;
	// if (!font.loadFromFile("oswald.ttf")) {
	// 	std::cout << "Error bruh" << std::endl;
	// }
	// sf::Text text;

	// text.setFont(font);
	// text.setString("Hello World!");
	// text.setCharacterSize(24);
	// text.setColor(sf::Color::Red);



	return EXIT_SUCCESS;
}
