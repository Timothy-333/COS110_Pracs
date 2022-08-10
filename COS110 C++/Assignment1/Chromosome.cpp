#include "Chromosome.h"

Chromosome::Chromosome(int numGenes, RandomGenerator* rand)
{
    this->numGenes = numGenes;
    bool* genes = new bool[numGenes];
    for (int i = 0 ; i < numGenes; i++) 
    {
        genes[i] = rand->randomBool();
    }
}
Chromosome::Chromosome(Chromosome* chromosome)
{
    this->numGenes = chromosome->numGenes;
}
Chromosome::Chromosome(bool* genes, int numGenes)
{
    this->numGenes = numGenes;
    this->genes = genes;
}
Chromosome::~Chromosome()
{
    delete[] genes;
}
double Chromosome::fitness(FitnessFunction* fitnessFunction, Chromosome* chromosome, int numGenes)
{
    
}
int Chromosome::getNumGenes()
{
    return numGenes;
}
Chromosome* Chromosome::crossOver(Chromosome* c2)
{

}
Chromosome* Chromosome::mutate()
{

}
std::string Chromosome::toString()
{
    
}
bool* Chromosome::getGenes()
{
    return genes;
}