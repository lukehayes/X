#include <string>
#include "glad/glad.h"
#include "X/GL/BufferType.h"
#include "X/GL/ShaderType.h"
#include "X/Math/GLM.h"


namespace X::GL
{
class Shader
{
public:
	Shader(const char* vsh, const char* fsh);

	Shader(
		const std::string& vsh,
		const std::string& fsh
	);

	Shader(const Shader& rhs);
	Shader(const Shader&& rhs);

	Shader& operator=(Shader& rhs);
	Shader& operator=(Shader&& rhs);

	void use() const;

	~Shader();

	void checkCompileErrors(unsigned int shader, std::string type);

	/**
	* ----------------------------------------------------------------------------
	*  Uniform Methods
	* --------------------------------------------------------------------------*/
	void SetUniformMat4(glm::mat4 matrix, const char* name);
	void setUniformFloat(float val, const char* name);


//protected:
	void compile(const std::string& source, const std::string& name, ShaderType type);
	void link();
	void build();


private:
	std::string vshSource;
	std::string fshSource;
	GLuint vshProgram;
	GLuint fshProgram;
	GLuint program;
};
}
