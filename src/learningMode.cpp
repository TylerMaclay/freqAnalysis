#include "learningMode.h"
#include <algorithm>
#include <iterator>

learningMode::learningMode(std::vector<std::string> uVec, std::map<std::string, int> cMap) :
	uselessWord(uVec), wordCountResult(cMap) { 
	for(auto it = cMap.begin(); it != cMap.end(); ++it){
		if(!checkAgainstList(it->first)){
			if(getResult("Would you like to add " + 
				it->first + " to the block list? (Y/N): ")){
				uselessWord.push_back(it->first);
			}
		}
	}
}

bool learningMode::getResult(const std::string& question) const {
	std::string answer;
	std::cout<<question;
	while(std::getline(std::cin, answer)){
		std::tolower(answer[0]);
		if(answer[0] != 'y' && answer[0] != 'n'){
			std::cout<<"Please enter a valid value..."<<std::endl;
			std::cout<<question;
		}
		else {
			if(std::tolower(answer[0]) == 'y')
				return true;
			else if(std::tolower(answer[0] == 'n'))
				return false;
		}
	}
	return false;
}

bool learningMode::checkAgainstList(const std::string& testString) const{
	auto test = std::find(std::begin(uselessWord), std::end(uselessWord), testString);
	if(test != uselessWord.end()){
		return true;
	}
	else{
		return false;
	}
}

std::vector<std::string> learningMode::getFullWords() const {
	return uselessWord;
}
