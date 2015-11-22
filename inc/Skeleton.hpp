/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Skeleton.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 11:31:02 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/20 05:18:14 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKELETON_HPP
# define SKELETON_HPP

// Graphics
# include <SDL2/SDL.h>
# include <GL/glew.h>
# include <SDL2/SDL_opengl.h>

# include <iostream>
# include <string>

// STL
# include <vector>
# include <algorithm>

// Stream
# include <fstream>
# include <sstream>

// GLM
# define GLM_FORCE_RADIANS
# include <glm/vec3.hpp>
# include <glm/vec4.hpp>
# include <glm/mat4x4.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <glm/gtc/type_ptr.hpp>

using std::string;

class Skeleton {

public:
	Skeleton(string const & title, int width, int height);
	Skeleton(Skeleton const & src);
	~Skeleton(void);

	Skeleton &		operator=( Skeleton const & src );

	void			init( void );
	void			loop( void );
	void			terminate( void );
	bool			isActive( void ) const;
	void			infoRenderer( void ) const;

	void 			loadObj(const char* filename, std::vector<glm::vec4> &vertices, std::vector<glm::vec3> &normals, std::vector<GLushort> &elements);
private:
	string const 		_appName;
	bool				_isActive;
	int					_width;
	int					_height;

	SDL_Window			*_window;
	SDL_GLContext		_context;
	SDL_Event			_event;

	GLuint				_programId;
	GLuint				_matrixId;
	GLuint				_vertexBuffer;
	GLuint				_colorBuffer;

	glm::mat4 			_projection;
	glm::mat4			_model;
	glm::mat4			_view;
	glm::mat4			_mvp;

	std::vector<glm::vec4> _suzanne_vertices;

	// Init
	GLuint				_setupShaders(const char *vertex_path, const char *fragment_path) const;
	void				_setupMatrices( void );

	bool				_exitHook( void ) const;
	void				_keyHooks( void );

	// Tools
	std::string 		_loadFile(const char *filePath) const;
};

std::ostream &			operator<<(std::ostream & o, const glm::mat4 & src);

#endif
