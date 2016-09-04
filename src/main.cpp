#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "fileReader.h"
#include "wordCounter.h"
#include "output.h"
#include "cmdargs.h"

int main(int argc, char** argv) {
	cmdargs arguments(argc,argv);
	const std::string version = "V0.3";
	std::cout<<"Frequency Analysis Program " << version << std::endl;
	fileReader file("./test/README");
	output* outputter;
	outputter = new CSVOutput("./test/output.txt");
	std::vector<std::string> testWords = file.getWords();
	wordCounter wordCountTest(testWords);
	std::map<std::string, uint32_t> testMap = wordCountTest.getCounts();
	for(auto i : testMap){
		std::vector<std::string> vec;
		vec.push_back(i.first);
		vec.push_back(std::to_string(i.second));
		outputter->writeLine(vec);
	}
	return 0;

}


