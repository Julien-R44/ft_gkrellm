/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 05:23:45 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/12 06:07:27 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

class IMonitorModule {
public:
	IMonitorModule() {}
	IMonitorModule(IMonitorModule const & src);
	~IMonitorModule() {}

	IMonitorModule &		operator=( IMonitorModule const & src );

};

#endif
