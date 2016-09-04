#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "fileReader.h"
#include "wordCounter.h"
#include "output.h"

int main() {
	const std::string version = "V0.21";
	std::cout<<"Frequency Analysis Program " << version << std::endl;
	fileReader file("./test/README");
	output* outputter;
	outputter = new CSVOutput("./test/output.txt");
	std::vector<std::string> testWords = file.getWords();
	wordCounter wordCountTest(testWords);
	std::map<std::string, uint32_t> testMap = wordCountTest.getCounts();
	for(auto i : testMap)
		outputter->writeLine(i.first,std::to_string(i.second));
	return 0;

}


