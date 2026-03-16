#ifndef X_MODEL_GENERATOR_H
#define X_MODEL_GENERATOR_H

#include <vector>
#include "X/Model/CubeModel.h"
#include "X/Model/PlaneModel.h"
#include "X/Math/Random.h"

namespace X::Model
{
	std::vector<X::Model::Model> GenerateCubeModels(int count, int scatter)
	{
		std::vector<X::Model::Model> models;

		for(int i = 0; i <= count; i++)
		{
			double rx = X::Math::Random::RandDouble(-scatter, scatter);
			double ry = X::Math::Random::RandDouble(-scatter, scatter);
			double rz = X::Math::Random::RandDouble(-scatter, scatter);

			double rot_x = X::Math::Random::RandDouble(0, 360);
			double rot_y = X::Math::Random::RandDouble(0, 360);
			double rot_z = X::Math::Random::RandDouble(0, 360);

			double rr = X::Math::Random::RandDouble(0,1);
			double rg = X::Math::Random::RandDouble(0,1);
			double rb = X::Math::Random::RandDouble(0,1);
			double ra = X::Math::Random::RandDouble(1,1);

			X::Model::CubeModel model { { rr,rg,rb,ra } };

			model.transform.position.x = rx;
			model.transform.position.y = ry;
			model.transform.position.z = rz;

			model.transform.rotation.x = rot_x;
			model.transform.rotation.y = rot_y;
			model.transform.rotation.z = rot_z;

			model.color.r = rr;
			model.color.g = rg;
			model.color.b = rb;
			model.color.a = ra;

			models.push_back(model);
		}

		return models;
	}
	std::vector<X::Model::Model> GeneratePlaneModels(int count, int scatter)
	{
		std::vector<X::Model::Model> models;

		for(int i = 0; i <= count; i++)
		{

			double rx = X::Math::Random::RandDouble(-scatter, scatter);
			double ry = X::Math::Random::RandDouble(-scatter, scatter);
			double rz = X::Math::Random::RandDouble(-scatter, scatter);

			double rot_x = X::Math::Random::RandDouble(0, 360);
			double rot_y = X::Math::Random::RandDouble(0, 360);
			double rot_z = X::Math::Random::RandDouble(0, 360);

			double rr = X::Math::Random::RandDouble(0,1);
			double rg = X::Math::Random::RandDouble(0,1);
			double rb = X::Math::Random::RandDouble(0,1);
			double ra = X::Math::Random::RandDouble(1,1);

			X::Model::PlaneModel model { { rr,rg,rb,ra } };

			model.transform.position.x = rx;
			model.transform.position.y = ry;
			model.transform.position.z = rz;

			model.transform.rotation.x = rot_x;
			model.transform.rotation.y = rot_y;
			model.transform.rotation.z = rot_z;

			model.color.r = rr;
			model.color.g = rg;
			model.color.b = rb;
			model.color.a = ra;

			models.push_back(model);
		}

		return models;
	}
}


#endif // X_MODEL_GENERATOR_H
