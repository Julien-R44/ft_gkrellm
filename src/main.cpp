/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 03:06:04 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/20 05:05:06 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Skeleton.hpp"

int main(void) {
	Skeleton		skeleton("SDL2 Skeleton", 900, 500);

	skeleton.init();
	// skeleton.loadObj('res/42.obj', );
	skeleton.infoRenderer();

	while (skeleton.isActive()) {
		skeleton.loop();
	}

	skeleton.terminate();
	return (0);
}
