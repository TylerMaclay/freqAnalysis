#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "fileReader.h"
#include "wordCounter.h"


int main() {
	const std::string version = "V0.21";
	std::cout<<"Frequency Analysis Program " << version << std::endl;
	fileReader file("./test/README");
	std::vector<std::string> testWords = file.getWords();
	wordCounter wordCountTest(testWords);
	std::map<std::string, uint32_t> testMap = wordCountTest.getCounts();
	for(auto i : testMap)
		std::cout<<i.first<<" "<<i.second<<std::endl;

	return 0;

}


