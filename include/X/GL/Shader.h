
#include <string>
#include "glad/glad.h"

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

private:
	std::string vsh;
	std::string fsh;
	GLuint program;
};
}
