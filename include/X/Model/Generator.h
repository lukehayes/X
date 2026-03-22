#ifndef X_MODEL_GENERATOR_H
#define X_MODEL_GENERATOR_H

#include "X/Math/Random.h"
#include "X/Model/CubeModel.h"
#include "X/Model/PlaneModel.h"
#include <vector>

namespace X::Model {
std::vector<X::Model::Model> GenerateCubeModels(int count, int scatter) {
  std::vector<X::Model::Model> models;
  float bias = 0.1;

  for (int i = 0; i <= count; i++) {
    double rx = X::Math::Random::RandDouble(-scatter, scatter);
    double ry = X::Math::Random::RandDouble(-scatter, scatter);
    double rz = X::Math::Random::RandDouble(-scatter, scatter);

    double rot_x = X::Math::Random::RandDouble(0, 360);
    double rot_y = X::Math::Random::RandDouble(0, 360);
    double rot_z = X::Math::Random::RandDouble(0, 360);

    double rr = X::Math::Random::RandDouble(0, 1);
    double rg = X::Math::Random::RandDouble(0.7, 1);
    double rb = X::Math::Random::RandDouble(0.7, 1);
    double ra = X::Math::Random::RandDouble(1, 1);

    X::Model::CubeModel model{{rr, rg, rb, ra}};

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

std::vector<X::Model::Model> GeneratePlaneModels(int count, int scatter) {
  std::vector<X::Model::Model> models;

  for (int i = 0; i <= count; i++) {

    double rx = X::Math::Random::RandDouble(-scatter, scatter);
    double ry = X::Math::Random::RandDouble(-scatter, scatter);
    double rz = X::Math::Random::RandDouble(-scatter, scatter);

    double rot_x = X::Math::Random::RandDouble(0, 360);
    double rot_y = X::Math::Random::RandDouble(0, 360);
    double rot_z = X::Math::Random::RandDouble(0, 360);

    double rr = X::Math::Random::RandDouble(0, 1);
    double rg = X::Math::Random::RandDouble(0, 1);
    double rb = X::Math::Random::RandDouble(0, 1);
    double ra = X::Math::Random::RandDouble(1, 1);

    X::Model::PlaneModel model{{rr, rg, rb, ra}};

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

/**
 * Generate a three dimensional chunk.
 *
 * @param int  count    The number of entities to generate
 * @param int  scatter    The distance apart each entity will be
 */
std::vector<X::Model::Model> GenerateChunk(int count, int scatter) {
  std::vector<X::Model::Model> models;

  for (int x = 0; x <= count; x++) {
    for (int y = 0; y <= count; y++) {
      for (int z = 0; z <= count; z++) {
        X::Model::CubeModel model{{0, 0, 0, 0}};

        model.transform.position.x = x * scatter;
        model.transform.position.y = y * scatter;
        model.transform.position.z = z * scatter;

        models.push_back(model);
      }
    }
  }

  return models;
}

} // namespace X::Model

#endif // X_MODEL_GENERATOR_H
