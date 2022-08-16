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
    Chromosome** selection = new Chromosome*[populationSize];
    for (int i = 0; i < populationSize; i++)
    {
        selection[i] = new Chromosome(population[i]);
    }
    for (int i = 0; i < populationSize; i++)
    {
        for (int j = i + 1; j < populationSize; j++)
        {
            if(fitnessFunction->calculateFitness(selection[i], selection[i]->getNumGenes()) < fitnessFunction->calculateFitness(selection[j], selection[i]->getNumGenes()))
            {
                Chromosome* temp = selection[i];
                selection[i] = selection[j];
                selection[j] = temp;
            }
        }
    }
    return selection;
}
Chromosome** GA::inverseSelection(FitnessFunction* fitnessFunction)
{
    Chromosome** inverseSelection = new Chromosome*[populationSize];
    for (int i = 0; i < populationSize; i++)
    {
        inverseSelection[i] = new Chromosome(population[i]);
    }
    for (int i = 0; i < populationSize; i++)
    {
        for (int j = i + 1; j < populationSize; j++)
        {
            if(fitnessFunction->calculateFitness(inverseSelection[i], inverseSelection[i]->getNumGenes()) >= fitnessFunction->calculateFitness(inverseSelection[j], inverseSelection[i]->getNumGenes()))
            {
                Chromosome* temp = inverseSelection[i];
                inverseSelection[i] = inverseSelection[j];
                inverseSelection[j] = temp;
            }
        }
    }
    return inverseSelection;
}
Chromosome** GA::crossOver(Chromosome* c1, Chromosome* c2)
{
    Chromosome** c3 = new Chromosome*[2];
    c3[0] = c1->crossOver(c2);
    c3[1] = c2->crossOver(c1);
    return c3;
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
    for (int i = 0; i < populationSize; i++)
    {
        delete population[i];
        population[i] = new Chromosome(p[i]);
    }
}
Chromosome** GA::run(FitnessFunction* fitnessFunction)
{
    Chromosome** winners = selection(fitnessFunction);
    Chromosome** losers = inverseSelection(fitnessFunction);
    Chromosome** offsprings = new Chromosome*[3*selectionSize];
    Chromosome** nChromosomes = new Chromosome*[2];
    Chromosome** P = new Chromosome*[populationSize];
    for(int i = 0; i < selectionSize*2; i++)
    {
        nChromosomes = crossOver(winners[i], winners[i+1]);
        offsprings[i] = nChromosomes[0];
        offsprings[i+1] = nChromosomes[1];
    }
    for (int i = 0; i < selectionSize; i++)
    {
        offsprings[i + 2*selectionSize] = winners[i+2*selectionSize]->mutate();
    }
    for (int i = 0; i < populationSize; i++)
    {
        P[i] = population[i];
    }
    
    for (int i = 0; i < 3*selectionSize; i++)
    {
        Chromosome* dyingChromosome = new Chromosome(losers[i]);
        for (int j = 0; j < populationSize; j++)
        {
            if(dyingChromosome->toString() == P[j]->toString())
            {
                P[j] = offsprings[i];
            }
        }
    }
    delete [] winners;
    delete [] losers;
    delete [] offsprings;
    delete [] nChromosomes;
    return P;
    
}
double** GA::run(FitnessFunction* fitnessFunction, int numGenerations)
{
    double** results = new double*[numGenerations];
    for (int i = 0; i < numGenerations; i++)
    {
        results[i] = new double[2];
    }
    for (int i = 0; i < numGenerations; i++)
    {
        Chromosome** P = run(fitnessFunction);
        population = P;
        results[i][0] = calculateAvgAccuracy(fitnessFunction);
        results[i][1] = calculateStd(fitnessFunction);
        results[i][2] = calculateVariance();
    }
    return results;
}