#include "GA.h"

GA::GA(int populationSize, RandomGenerator* rand, int numGenes, int selectionSize)
{
    this->populationSize = populationSize;
    this->selectionSize = selectionSize;
    Chromosome** population = new Chromosome*[populationSize];
    for (int i = 0; i < populationSize; i++)
    {
        population[i] = new Chromosome(numGenes, rand);
    }
}
GA::GA(GA* geneticAlgorithm)
{
    
}
GA::~GA()
{
    delete [] population;
}
Chromosome** GA::selection(FitnessFunction* fitnessFunction)
{
    for (int i = 0; i < populationSize; i++)
    {
        for (int j = i + 1; j < populationSize; j++)
        {
            if(fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes()) < fitnessFunction->calculateFitness(population[j], population[i]->getNumGenes()))
            {
                Chromosome* temp = population[i];
                population[i] = population[j];
                population[j] = temp;
            }
        }
    }
}
Chromosome** GA::inverseSelection(FitnessFunction* fitnessFunction)
{
    for (int i = 0; i < populationSize; i++)
    {
        for (int j = i + 1; j < populationSize; j++)
        {
            if(fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes()) >= fitnessFunction->calculateFitness(population[j], population[i]->getNumGenes()))
            {
                Chromosome* temp = population[i];
                population[i] = population[j];
                population[j] = temp;
            }
        }
    }
}
Chromosome** GA::crossOver(Chromosome* c1, Chromosome* c2)
{
    Chromosome** c3 = new Chromosome*[2];
    c3[0] = c1->crossOver(c2);
    c3[1] = c2->crossOver(c1);
}
Chromosome* GA::mutate(Chromosome* c1)
{
    return c1->mutate();
}
double GA::calculateAvgAccuracy(FitnessFunction* fitnessFunction)
{
    double avgFitness = 0;
    for(int i = 0; i < populationSize; i++)
    {
        avgFitness += fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes());
    }
    avgFitness /= populationSize;
    return avgFitness;
}
double GA::calculateStd(FitnessFunction* fitnessFunction)
{
    double avgFitness = calculateAvgAccuracy(fitnessFunction);
    double std = 0;
    for(int i = 0; i < populationSize; i++)
    {
        std += pow(fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes()) - avgFitness, 2);
    }
    std = sqrt(std/populationSize);
    return std;
}
double GA::calculateVariance()
{
    double uniqueChromosomes = 0;
    for (int i = 0; i < populationSize; i++)
    {
        bool isCopy = false;
        for (int j = 0; i < populationSize; i++)
        {
            if(population[i]->toString() == population[j]->toString())
                isCopy = true;
        }
        if(isCopy)
            uniqueChromosomes++;
    }
    return uniqueChromosomes/populationSize;
    
}
void GA::setPopulation(Chromosome** p)
{
    
}
Chromosome** GA::run(FitnessFunction* fitnessFunction)
{

}
double** GA::run(FitnessFunction* fitnessFunction, int numGenerations)
{

}