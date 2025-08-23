#ifndef X_MATH_RANDOM_H
#define X_MATH_RANDOM_H

#include <random>
#include <ctime>

namespace X::Math {

class Random
{
public:

    static int RandInt(int from, int to)
    {
        std::random_device device;
        std::uniform_int_distribution<int> dist(from, to);
        return dist(device);
    }
    static double RandDouble(double from, double to)
    {
        std::random_device device;
        std::uniform_real_distribution<double> dist(from, to);
        return dist(device);
    }

private:
    std::mt19937 m_generator;
    std::random_device m_device;
};

inline size_t rand(size_t min, size_t max)
{
    std::srand(std::time({}));
    return min + std::rand() % max;
}

}

#endif
