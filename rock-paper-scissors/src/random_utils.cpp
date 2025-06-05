#include <chrono>
#include <random_utils.hpp>
#include <random>

std::mt19937& _get_random_engine() {
    static std::random_device rd;
    static std::mt19937 engine(std::chrono::high_resolution_clock::now().time_since_epoch().count());

    return engine;
}

int randint(int min, int max) {
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(_get_random_engine());
}
