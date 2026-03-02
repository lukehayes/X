#pragma once

#include <vector>
#include "X/Mesh/QuadMesh.h"



namespace X::Mesh
{

X::Mesh::QuadMesh LoadCubeMesh()
{
	std::vector<float> cubeVertices =
		{
			// Position              // Color

			-0.5f, -0.5f, -0.5f,    0.5f, 0.5f, 0.5f , // 0
			0.5f, -0.5f, -0.5f,     0.5f, 0.5f, 0.5f , // 1
			0.5f,  0.5f, -0.5f,     0.5f, 0.5f, 0.5f , // 2
			-0.5f,  0.5f, -0.5f,    0.5f, 0.5f, 0.5f , // 3

			-0.5f, -0.5f,  0.5f,    0.2f, 0.2f, 0.2f , // 4
			0.5f, -0.5f,  0.5f,    	0.2f, 0.2f, 0.2f , // 5
			0.5f,  0.5f,  0.5f,    	0.2f, 0.2f, 0.2f , // 6
			-0.5f,  0.5f,  0.5f,    0.2f, 0.2f, 0.2f   // 7
		};

	std::vector<unsigned int> cubeIndices =
		{
			// Back face (-Z)
			0, 1, 2,
			2, 3, 0,

			// Front face (+Z)
			4, 5, 6,
			6, 7, 4,

			// Left face (-X)
			7, 3, 0,
			0, 4, 7,

			// Right face (+X)
			1, 2, 6,
			6, 5, 1,

			// Bottom face (-Y)
			0, 1, 5,
			5, 4, 0,

			// Top face (+Y)
			3, 2, 6,
			6, 7, 3
		};


	X::Mesh::QuadMesh cubeMesh { cubeVertices, cubeIndices };
	cubeMesh.BindVertexArray();
	cubeMesh.SetArrayBufferData(cubeVertices);
	cubeMesh.SetElementBufferData(cubeIndices);
	cubeMesh.SetAttribPointer(0,3,6,0);
	cubeMesh.SetAttribPointer(1,3,6,3);

	return cubeMesh;


}


X::Mesh::QuadMesh LoadQuadMesh()
{

	std::vector<float> quadVertices = {
		0.5f,  0.5f,  0.0f,  0.5f, 0.5f, 0.5f,
		0.5f, -0.5f,  0.0f,  0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.0f,  0.5f, 0.5f, 0.5f,
		-0.5f,  0.5f, 0.0f,  0.5f, 0.5f, 0.5f
	};

	std::vector<unsigned int> quadIndices = {
		0,1,3,
		1,2,3
	};

	X::Mesh::QuadMesh quadMesh { quadVertices, quadIndices };
	quadMesh.BindVertexArray();
	quadMesh.SetArrayBufferData(quadVertices);
	quadMesh.SetElementBufferData(quadIndices);
	quadMesh.SetAttribPointer(0,3,6,0);
	quadMesh.SetAttribPointer(1,3,6,3);

	return quadMesh;


}




}
