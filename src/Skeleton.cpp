/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Skeleton.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 11:31:35 by y0ja              #+#    #+#             */
/*   Updated: 2015/11/22 07:14:43 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Skeleton.hpp"

const GLfloat vertex[] = {
	-1.0, -1.0, -1.0,   1.0, -1.0, -1.0,   1.0, 1.0, -1.0,
	-1.0, -1.0, -1.0,   -1.0, 1.0, -1.0,   1.0, 1.0, -1.0,

	1.0, -1.0, 1.0,   1.0, -1.0, -1.0,   1.0, 1.0, -1.0,
	1.0, -1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, -1.0,

	-1.0, -1.0, 1.0,   1.0, -1.0, 1.0,   1.0, -1.0, -1.0,
	-1.0, -1.0, 1.0,   -1.0, -1.0, -1.0,   1.0, -1.0, -1.0,

	-1.0, -1.0, 1.0,   1.0, -1.0, 1.0,   1.0, 1.0, 1.0,
	-1.0, -1.0, 1.0,   -1.0, 1.0, 1.0,   1.0, 1.0, 1.0,

	-1.0, -1.0, -1.0,   -1.0, -1.0, 1.0,   -1.0, 1.0, 1.0,
	-1.0, -1.0, -1.0,   -1.0, 1.0, -1.0,   -1.0, 1.0, 1.0,

	-1.0, 1.0, 1.0,   1.0, 1.0, 1.0,   1.0, 1.0, -1.0,
	-1.0, 1.0, 1.0,   -1.0, 1.0, -1.0,   1.0, 1.0, -1.0
};

const GLfloat g_color_buffer_data[] = {
	0.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
	0.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

	0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,
	0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,

	0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,
	0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,

	1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,
	1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,

	0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,
	0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,

	0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,
	0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0
};

Skeleton::Skeleton( std::string const & title, int width, int height ):
	_isActive(false),
	_appName(title),
	_width(width),
	_height(height)
{
	return ;
}

Skeleton::Skeleton( Skeleton const & src ) {
	*this = src;
	return;
}

Skeleton::~Skeleton( void ) {
	return;
}

Skeleton &	Skeleton::operator=( Skeleton const & src ) {
	return *this;
}

void				Skeleton::init( void ) {

	if (SDL_Init(SDL_INIT_VIDEO) == -1) throw "SDL_Init failed.";

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	_window = SDL_CreateWindow(
		_appName.c_str(),
		SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED,
		_width, _height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	if (_window == NULL) throw "SDL_CreateWindow failed.";

	_context = SDL_GL_CreateContext(_window);
	if (_context == NULL) throw "SDL_GL_CreateContext failed.";

	GLenum err = glewInit();
	if (err != GLEW_OK)
		throw "glewInit failed.";

	glClearColor(0.160f, 0.160f, 0.160f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// TEST LOAD OBJ
	std::vector<glm::vec3> suzanne_normals;
	std::vector<GLushort> suzanne_elements;

	loadObj("res/cube.obj", _suzanne_vertices, suzanne_normals, suzanne_elements);

	// VAO
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	// Vertex Buffer
	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	// glBufferData(GL_ARRAY_BUFFER, _suzanne_vertices.size() * sizeof(glm::vec4), &_suzanne_vertices[0], GL_STATIC_DRAW);
	// Color buffer
	glGenBuffers(1, &_colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

	this->_programId = _setupShaders("./shader/VertexShader.vs", "./shader/FragmentShader.fs");

	_setupMatrices();

	_isActive = true;


}

void				Skeleton::_setupMatrices( void ) {
	_matrixId = glGetUniformLocation(_programId, "MVP");

	// Projection Matrix
	_projection = glm::perspective(70.0f, (float) _width / _height, 1.0f, 100.0f);
	std::cout << "Projection :" << std::endl;
	std::cout << _projection << std::endl;

	// View Matrix
	_view = glm::lookAt(
		glm::vec3(4, 3, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);
	std::cout << "View :" << std::endl;
	std::cout << _view << std::endl;

	// Model Matrix
	_model = glm::mat4(1.0f);
	std::cout << "Model :" << std::endl;
	std::cout << _model << std::endl;

	// MVP Matrix
	_mvp = _projection * _view * _model;
	std::cout << "MVP :" << std::endl;
	std::cout << _mvp << std::endl;

}

void				Skeleton::_keyHooks( void ) {
	switch (_event.type) {
		case SDL_KEYDOWN:
			if (_event.key.keysym.sym == SDLK_RIGHT)
				_mvp = glm::rotate(_mvp, 0.0005f, glm::vec3(0.0, 1.0, 0.0));
			if (_event.key.keysym.sym == SDLK_LEFT)
				_mvp = glm::rotate(_mvp, -0.0005f, glm::vec3(0.0, 1.0, 0.0));
			if (_event.key.keysym.sym == SDLK_DOWN)
				_mvp = glm::rotate(_mvp, 0.0005f, glm::vec3(1.0, 0.0, 0.0));
			if (_event.key.keysym.sym == SDLK_UP)
				_mvp = glm::rotate(_mvp, -0.0005f, glm::vec3(1.0, 0.0, 0.0));

	}
}

void				Skeleton::loop( void ) {
	// Hooks
	SDL_PollEvent(&_event);
	_isActive = _exitHook();
	_keyHooks();

	// Display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 glUseProgram(_programId);
		glUniformMatrix4fv(_matrixId, 1, GL_FALSE, glm::value_ptr(_mvp));
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,NULL);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
		glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, 0,NULL);

		glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
		glDisableVertexAttribArray(0);
	glUseProgram(0);

	SDL_GL_SwapWindow(_window);
}

void				Skeleton::terminate( void ) {
	SDL_GL_DeleteContext(_context);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void 				Skeleton::loadObj(const char* filename, std::vector<glm::vec4> &vertices, std::vector<glm::vec3> &normals, std::vector<GLushort> &elements)
{
	std::ifstream in(filename, std::ios::in);
	if (!in) {
		std::cerr << "Cannot open " << filename << std::endl;
		exit(1);
	}

	std::string line;
	while (getline(in, line))
	{
		if (line.substr(0,2) == "v ") {
			std::istringstream s(line.substr(2));
			glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
			vertices.push_back(v);
		}
		else if (line.substr(0,2) == "f ") {
			std::istringstream s(line.substr(2));
			GLushort a,b,c;
			s >> a; s >> b; s >> c;
			a--; b--; c--;
		   elements.push_back(a); elements.push_back(b); elements.push_back(c);
		}
	}

	normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
	for (int i = 0; i < elements.size(); i+=3)
	{
		GLushort ia = elements[i];
		GLushort ib = elements[i+1];
		GLushort ic = elements[i+2];
		glm::vec3 normal = glm::normalize(glm::cross(
		glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
		glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
		normals[ia] = normals[ib] = normals[ic] = normal;
	}
}

bool				Skeleton::isActive( void ) const {
	return _isActive;
}

void				Skeleton::infoRenderer(void) const {
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

bool				Skeleton::_exitHook( void ) const {
	if (_event.window.event == SDL_WINDOWEVENT_CLOSE ||
		(_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_ESCAPE))
			return (false);
	return (true);
}

std::string 		Skeleton::_loadFile(const char *filePath) const {
	std::string 	content;
	std::ifstream 	fileStream(filePath, std::ios::in);

	if (!fileStream.is_open()) {
		std::cerr << filePath << ": File does not exist." << std::endl;
		return "";
	}

	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}

GLuint				Skeleton::_setupShaders(const char *vertex_path, const char *fragment_path) const {
	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Read shaders
	std::string vertShaderStr = _loadFile(vertex_path);
	std::string fragShaderStr = _loadFile(fragment_path);

	const char *vertShaderSrc = vertShaderStr.c_str();
	const char *fragShaderSrc = fragShaderStr.c_str();

	GLint result = GL_FALSE;
	int logLength;

	// Compile vertex shader
	std::cout << "Compiling vertex shader." << std::endl;
	glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
	glCompileShader(vertShader);

	// Check vertex shader
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
	std::cout << &vertShaderError[0] << std::endl;

	// Compile fragment shader
	std::cout << "Compiling fragment shader." << std::endl;
	glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
	glCompileShader(fragShader);

	// Check fragment shader
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
	std::cout << &fragShaderError[0] << std::endl;

	std::cout << "Linking programID" << std::endl;
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertShader);
	glAttachShader(programID, fragShader);
	glLinkProgram(programID);

	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> programError( (logLength > 1) ? logLength : 1 );
	glGetProgramInfoLog(programID, logLength, NULL, &programError[0]);
	std::cout << &programError[0] << std::endl;

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
	return programID;
}

std::ostream &			operator<<(std::ostream & o, const glm::mat4 & src) {
	// need to use streams
	printf("%f, %f, %f, %f\n", src[0][0], src[0][1], src[0][2], src[0][3]);
	printf("%f, %f, %f, %f\n", src[1][0], src[1][1], src[1][2], src[1][3]);
	printf("%f, %f, %f, %f\n", src[2][0], src[2][1], src[2][2], src[2][3]);
	printf("%f, %f, %f, %f\n", src[3][0], src[3][1], src[3][2], src[3][3]);
	return o;
}
