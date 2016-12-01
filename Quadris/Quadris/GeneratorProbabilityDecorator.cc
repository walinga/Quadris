#include "GeneratorProbabilityDecorator.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <memory>
#include <stdlib.h>

using namespace std;

GeneratorProbabilityDecorator::GeneratorProbabilityDecorator(
    std::shared_ptr<BlockGenerator> component, int randSeed, int randomNumberRange)
    : BlockGeneratorDecorator{component}, randSeed{randSeed}, randomNumberRange{randomNumberRange}
{
}

Block GeneratorProbabilityDecorator::generateBlock()
{
    srand(randSeed);
    //Generate a number between 0 to 99 when randomNumberRange set to 100
    int num = (rand() % randomNumberRange);

    double totProb = 0;
    int size = blockProbabilities.size();
    for (int i = 0; i != size; ++i)
    {
	totProb += blockProbabilities[i].second;
	if (num < totProb * randomNumberRange)
	{
	    return this->component->generateBlock(blockProbabilities[i].first);
	}
    }
}

GeneratorProbabilityDecorator::GeneratorProbabilityDecorator(std::shared_ptr<BlockGenerator> component,
							   std::vector<string> blocks, 
                               std::vector<double> probabilities, 
                               int randSeed, int randomNumberRange)
    : BlockGeneratorDecorator{component}, randSeed{randSeed}, randomNumberRange{randomNumberRange}
{
    setProbability(blocks, probabilities);
}

void GeneratorProbabilityDecorator::setProbability(vector<string> blocks,
						  vector<double> probabilities)
{

    int size = blocks.size();
    pair<string, double> item;

    if (blocks.size() != probabilities.size())
    {
	throw out_of_range("The list of blocks specified is not the same size as the list of probabilities specified");
    }

    for (int i = 0; i != size; ++i)
    {
	item.first = blocks[i];
	item.second = probabilities[i];
	this->blockProbabilities.emplace_back(item);
    }
}
