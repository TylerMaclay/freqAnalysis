#include "fileReader.h"
#include <string>
#include <vector>
#include <fstream>

fileReader::fileReader(const std::string& ifn) : fileName(ifn) {
	in.open(fileName);
}

std::vector<std::string> fileReader::getWords() {
	std::vector<std::string> words;
	if(!in.is_open())
		return std::vector<std::string>();
	std::string tmp;
	while(getline(in,tmp,' ')){
		words.push_back(tmp);
	}

	return words;
}
