#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int seed) 
{
    srand(seed);
    this->seed = seed;
}
bool RandomGenerator::randomBool()
{
    return rand() % 2;
}