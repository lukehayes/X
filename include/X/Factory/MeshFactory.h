#ifndef X_FACTORY_MESH_FACTORY_H
#define X_FACTORY_MESH_FACTORY_H

#include "X/Mesh/Mesh.h"
#include "X/Model/Model.h"
#include <vector>
#include <string>
#include <unordered_map>
#include "X/Math/GLM.h"


namespace std
{
template<>
struct hash<X::Mesh::Mesh>
{
    size_t operator()(X::Mesh::Mesh& mesh)
    {
        return std::hash<size_t>()(mesh.GetVertexCount() + mesh.GetIndexCount());
    }
};
}

namespace X::Factory
{


class MeshFactory
{
public:
	MeshFactory ();
	~MeshFactory ();

	/**
	 * Add a mesh instance into the factory
	 *
	 * @param const std::string& key
	 * @param X::Mesh::Mesh* mesh
	 *
	 * @return X::Mesh::Mesh* A reference to the newly inserted mesh.
	 */
	X::Mesh::Mesh* AddMesh(const std::string& key, X::Mesh::Mesh* mesh);

	/**
	 * Get mesh instance from Factory.
	 *
	 * @param const std::string& key
	 *
	 * @return X::Mesh::Mesh* A reference to the newly inserted mesh.
	 */
	X::Mesh::Mesh* GetMesh(const std::string& key);

        X::Mesh::Mesh* CreatePlaneMesh();

        X::Mesh::Mesh* CreateCubeMesh();

private:
	std::unordered_map<std::string, X::Mesh::Mesh*> meshes;
};




/**
* Generate randomized entites for quick testing.
*
* @static
*
* @param int count The anount if entities to draw.
*
* @param int space The space between each entity.
*
* @return std::vector<Entity>
*/
static std::vector<X::Model::Model> GenerateEntities(int count, int space = 10)
{
	std::vector<X::Model::Model> positions;


	for (int i = 0; i<= count; i++)
	{
		float rx = -std::rand() % space + std::rand() % space;
		float ry = -std::rand() % space + std::rand() % space;
		float rz = -std::rand() % space + std::rand() % space;

		float rr = (-std::rand() % 1 + std::rand() % 10)/10.0;
		float rg = (-std::rand() % 1 + std::rand() % 10)/10.0;
		float rb = (-std::rand() % 1 + std::rand() % 10)/10.0;
		float ra = (-std::rand() % 1 + std::rand() % 10)/10.0;

		glm::vec3 pos{rx,ry,rz};
		glm::vec4 color{rr,rg,rb,ra};

		X::Model::Model m;
		m.transform.position = {rx,ry,rz};
		m.color = {rr,rg,rb,ra};

		positions.push_back(m);

	}

	return positions;
}

}

#endif // !X_FACTORY_MESH_FACTORY_H
