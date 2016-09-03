#include "fileReader.h"
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <sstream>

fileReader::fileReader(const std::string& ifn) : fileName(ifn) {
	in.open(fileName);
}

std::vector<std::string> fileReader::getWords() {
	/* The Point of this function is to parse a file for words containing alpha-numeric
	characters only. All whitespace is ignored. */
	std::vector<std::string> words;
	if(!in.is_open())
		return std::vector<std::string>();
	std::string line;
	std::stringstream iss;
	while(std::getline(in,line)){
		iss << line;
		std::string tmp;
		while(std::getline(iss,tmp,' ')){
			std::string toAdd = "";
			for(auto i = tmp.begin(); i != tmp.end(); i++){
				if(!std::isspace(*i) && !std::ispunct(*i))
					toAdd.push_back(*i);
			}
			if(toAdd.empty())
				continue;
			words.push_back(toAdd);
		}
		iss.clear();
	}

	return words;
}
