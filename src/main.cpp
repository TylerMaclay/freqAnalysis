#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "fileReader.h"

std::map<std::string, uint32_t> wordCount(const std::vector<std::string> words);

int main() {
	const std::string version = "V0.2";
	std::cout<<"Frequency Analysis Program " << version << std::endl;
	fileReader file("./test/testfile.txt");
	std::vector<std::string> testWords = file.getWords();
	std::map<std::string, uint32_t> testMap = wordCount(testWords);
	for(auto i : testMap)
		std::cout<<i.first<<" "<<i.second<<std::endl;

	return 0;

}

std::map<std::string, uint32_t> wordCount(const std::vector<std::string> words){
	std::map<std::string, uint32_t> wordMap;
	for(auto i = words.begin(); i != words.end(); i++){
		auto search = wordMap.find(*i);
		if(search != wordMap.end())
			search->second++;
		else {
			wordMap.insert(std::make_pair(*i,1));
		}
	}

	return wordMap;
}
