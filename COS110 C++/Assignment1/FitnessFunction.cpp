#include "FitnessFunction.h"

double FitnessFunction::calculateFitness(Chromosome* chromsome, int numGenes)
{
    double m = 0;
    for (size_t i = 0; i < numGenes; i++)
    {
        if (chromsome->getGenes()[i] == true)
        {
            m++;
        }
    }
    return m/numGenes;
}