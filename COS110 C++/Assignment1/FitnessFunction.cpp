#include "FitnessFunction.h"
#include <iostream>
double FitnessFunction::calculateFitness(Chromosome* chromsome, int numGenes)
{
    double m = 0;
    for (int i = 0; i < numGenes; i++)
    {
        if (chromsome->getGenes()[i])
        {
            m++;
        }
    }
    return m/(double)numGenes;
}