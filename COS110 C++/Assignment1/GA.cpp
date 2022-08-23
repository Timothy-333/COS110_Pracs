#include "GA.h"
#include "Chromosome.h"
#include "RandomGenerator.h"
#include "FitnessFunction.h"
#include <string>
#include <iostream>
GA::GA(int populationSize, RandomGenerator* rand, int numGenes, int selectionSize)
{
    this->populationSize = populationSize;
    this->selectionSize = selectionSize;
    population = new Chromosome*[populationSize];
    for (int i = 0; i < populationSize; i++)
    {
        population[i] = new Chromosome(numGenes, rand);
    }
}
GA::GA(GA* geneticAlgorithm)
{
    this->populationSize = geneticAlgorithm->populationSize;
    this->selectionSize = geneticAlgorithm->selectionSize;
    population = new Chromosome*[populationSize];
    for (int i = 0; i < populationSize; i++)
    {
        population[i] = new Chromosome(geneticAlgorithm->population[i]);
    }
}
GA::~GA()
{
    for (int i = 0; i < populationSize; i++)
    {
        delete population[i];
    }
    delete [] population;
}
Chromosome** GA::selection(FitnessFunction* fitnessFunction)
{
    Chromosome** selection = new Chromosome*[populationSize];
    for (int i = 0; i < populationSize; i++)
    {
        selection[i] = new Chromosome(population[i]);
    }
    for (int i = 0; i < populationSize-1; i++)
    {
        for (int j = 0; j < populationSize-i-1; j++)
        {
            if(selection[j]->fitness(fitnessFunction,selection[j],selection[j]->getNumGenes()) < selection[j+1]->fitness(fitnessFunction,selection[j+1],selection[j+1]->getNumGenes()))
            {
                Chromosome* temp = selection[j];
                selection[j] = selection[j+1];
                selection[j+1] = temp;
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
    for (int i = 0; i < populationSize-1; i++)
    {
        for (int j = 0; j < populationSize-i-1; j++)
        {
            if(inverseSelection[j]->fitness(fitnessFunction,inverseSelection[j],inverseSelection[j]->getNumGenes()) > inverseSelection[j+1]->fitness(fitnessFunction,inverseSelection[j+1],inverseSelection[j+1]->getNumGenes()))
            {
                Chromosome* temp = inverseSelection[j];
                inverseSelection[j] = inverseSelection[j+1];
                inverseSelection[j+1] = temp;
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
        avgFitness += Chromosome::fitness(fitnessFunction,population[i],population[i]->getNumGenes());
    }
    avgFitness /= (double)populationSize;
    return avgFitness;
}
double GA::calculateStd(FitnessFunction* fitnessFunction)
{
    double avgFitness = calculateAvgAccuracy(fitnessFunction);
    double std = 0;
    for(int i = 0; i < populationSize; i++)
    {
        std += pow((Chromosome::fitness(fitnessFunction,population[i],population[i]->getNumGenes()) - avgFitness), 2);
    }
    std = sqrt(std/(double)populationSize);
    return std;
}
double GA::calculateVariance()
{
    double uniqueChromosomes = 0;
    for (int i = 0; i < populationSize; i++)
    {
        bool isCopy = false;
        for (int j = 0; j < i; j++)
        {
            if(population[i]->toString() == population[j]->toString())
                isCopy = true;
        }
        if(!isCopy)
            uniqueChromosomes++;
    }
    return (uniqueChromosomes/ (double) populationSize);
}
void GA::setPopulation(Chromosome** p)
{
    for (int i = 0; i < populationSize; i++)
    {
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
        offsprings[i] = new Chromosome(nChromosomes[0]);
        offsprings[i+1] = new Chromosome(nChromosomes[1]);
        i++;
    }
    delete nChromosomes[0];
    delete nChromosomes[1];
    delete [] nChromosomes;
    for (int i = 0; i < selectionSize; i++)
    {
        offsprings[i + 2*selectionSize] = mutate(winners[i+2*selectionSize]);
    }
    for (int i = 0; i < populationSize; i++)
    {
        P[i] = population[i];
    }
    for (int i = 0; i < 3*selectionSize; i++)
    {
        Chromosome* dyingChromosome = new Chromosome(losers[i]);
        bool isFound = false;
        int u = 0;
        while(!isFound && u < populationSize)
        {
            if(dyingChromosome->toString() == P[u]->toString())
            {
                isFound = true;
                P[u] = new Chromosome(offsprings[i]);
            }
            u++;
        }
        delete offsprings[i];
    }
    for (int i = 0; i < populationSize; i++)
    {
        delete winners[i];
        delete losers[i];
    }
    
    delete [] winners;
    delete [] losers;
    delete [] offsprings;
    return P;
}
double** GA::run(FitnessFunction* fitnessFunction, int numGenerations)
{
    double** results = new double*[numGenerations];
    for (int i = 0; i < numGenerations; i++)
    {
        Chromosome** p = run(fitnessFunction);
        setPopulation(p);
        results[i] = new double[3];
        results[i][0] = calculateAvgAccuracy(fitnessFunction);
        results[i][1] = calculateStd(fitnessFunction);
        results[i][2] = calculateVariance();
    }
    return results;
}