#include "Chromosome.h"
#include "FitnessFunction.h"
#include "RandomGenerator.h"
#include <string>
Chromosome::Chromosome(int numGenes, RandomGenerator* rand)
{
    if(numGenes < 0)
        this->numGenes = 0;
    else
        this->numGenes = numGenes;
    genes = new bool[this->numGenes];
    if(rand == NULL)
    {
        for(int i = 0; i < this->numGenes; i++)
        {
            genes[i] = false;
        }
    }
    else
    {
        for(int i = 0; i < this->numGenes; i++)
        {
            genes[i] = rand->randomBool();
        }
    }
}
Chromosome::Chromosome(Chromosome* chromosome)
{
    if(chromosome == NULL)
    {
        this->numGenes = 0;
        genes = new bool[0];
    }
    else
    {
        this->numGenes = chromosome->getNumGenes();
        genes = new bool[numGenes];

        for(int i = 0; i < this->numGenes; i++)
        {
            this->genes[i] = chromosome->getGenes()[i];
        }
    } 
}
Chromosome::Chromosome(bool* genes, int numGenes)
{
    if(numGenes < 0)
    {
        this->numGenes = 0;
        this->genes = new bool[0];
    }
    else
    {
        this->numGenes = numGenes;
        this->genes = new bool[numGenes];
        if(genes == NULL)
        {
            for (int i = 0; i < numGenes; i++)
            {
                this->genes[i] = false;
            }
        }
        else
        {
            for(int i = 0; i < numGenes; i++)
            {
                this->genes[i] = genes[i];
            }
        }
    }
}
Chromosome::~Chromosome()
{
    delete[] genes;
}
double Chromosome::fitness(FitnessFunction* fitnessFunction, Chromosome* chromosome, int numGenes)
{
    if(fitnessFunction == NULL || chromosome == NULL || numGenes <=0)
    {
        return 0;
    }
    return fitnessFunction->calculateFitness(chromosome, numGenes);
}
int Chromosome::getNumGenes()
{
    return numGenes;
}
Chromosome* Chromosome::crossOver(Chromosome* c2)
{
    double crossOverPoint = 0;
    if(c2 == NULL || c2->getNumGenes() <= 0)
    {
        Chromosome* tempChromosome = new Chromosome(this);
        return tempChromosome;
    }
    else
    {
        crossOverPoint = floor(c2->getNumGenes()/2);
        bool* nGenes = new bool[numGenes];
        for (int i = 0; i < crossOverPoint; i++)
        {
            nGenes[i] = this->genes[i];
        }
        for (int i = crossOverPoint; i < numGenes; i++)
        {
            nGenes[i] = c2->genes[i];
        }
        Chromosome* c3 = new Chromosome(nGenes, numGenes);
        delete [] nGenes;
        return c3;
    }
    
}
Chromosome* Chromosome::mutate()
{
    bool* nGenes = new bool[numGenes];
    for (int i = 0; i < numGenes; i++)
    {
        if (genes[i] == true)
        {
            nGenes[i] = false;
        }
        else
        {
            nGenes[i] = true;
        }
    }
    Chromosome* c3 = new Chromosome(nGenes, numGenes);
    delete [] nGenes;
    return c3;
}
std::string Chromosome::toString()
{
    std::string out = "";
    for (int i = 0; i < numGenes; i++)
    {
        if(genes[i] == true)
        {
            out += "1";
        }
        else
        {
            out += "0";
        }
    }
    return out;
}
bool* Chromosome::getGenes()
{
    return genes;
}