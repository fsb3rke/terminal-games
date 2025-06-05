#ifndef RANDOM_UTILS_HPP
#define RANDOM_UTILS_HPP

#include <random>

std::mt19937& _get_random_engine();
int randint(int min, int max);

#endif
