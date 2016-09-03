#include <iostream>
#include <string>
#include <vector>
#include "fileReader.h"

int main() {
	const std::string version = "V0.2";
	std::cout<<"Frequency Analysis Program " << version << std::endl;
	fileReader file("./test/testfile.txt");
	std::vector<std::string> testWords = file.getWords();
	for(auto i : testWords)
		std::cout<<i<<std::endl;

	return 0;

}
