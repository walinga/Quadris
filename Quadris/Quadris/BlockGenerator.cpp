#include "BlockGenerator.h"
#include "BlockParser.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

std::vector<Block> BlockGenerator::getParsedBlocks()
{	
	return this->blockParser.parseBlocks();
}

std::vector<Block> BlockGenerator::getParsedBlocksBase()
{	
	vector<Block> blocks = this->blockParser.parseBlocks();
	
	if(!checkBaseBlocksExist(blocks)){
		throw out_of_range("Base blocks did not exist to be parsed so cannot get base blocks");
	}
	
	int baseBlocksSize = baseBlocks.size();
	int parsedBlocksSize = blocks.size();

	vector<Block> base = vector<Block>{};
	for(int i = 0; i!= baseBlocksSize; ++i){
		for(int j = 0; j!= parsedBlocksSize; ++j){
			if(baseBlocks[i] == blocks[j].getName() ){
				base.emplace_back(blocks[j]);
				break;
			}
		}
	}
	return base;
}

Block BlockGenerator::generateBlock(std::string name){
vector<Block> blocks = this->getParsedBlocks();
int blockLen = blocks.size();

for(int i = 0; i != blockLen; ++i){
	if(blocks[i].getName() == name){		
		//cerr << blocks[i].getName();
		return blocks[i];
	}
}
if(name == ""){
	std::cout << "empty shit rite here" << endl;
}
	std::cout << name << endl << endl << endl;
	throw out_of_range("THat blcok did not exist to be parsed");
}

BlockGenerator::BlockGenerator(){
	this->baseBlocks = 
	vector<string>{"BLOCK-I", "BLOCK-Z", "BLOCK-T", "BLOCK-S", "BLOCK-O", "BLOCK-J", "BLOCK-L"};
	blockParser = BlockParser{};
}
	
bool BlockGenerator::checkBaseBlocksExist(std::vector<Block> blocks){
int size = baseBlocks.size();
for(int i = 0; i != size ; ++i ){
	if(std::find(baseBlocks.begin(), baseBlocks.end(), blocks[i].getName()) == baseBlocks.end()){
		return false;
	}
}
	return true;
}