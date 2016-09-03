#include "wordCounter.h"
#include <vector>
#include <map>
#include <string>

wordCounter::wordCounter(const std::vector<std::string>& words){
	for(auto i = words.begin(); i != words.end(); i++){
		auto search = wordMap.find(*i);
		if(search != wordMap.end())
			search->second++;
		else {
			wordMap.insert(std::make_pair(*i,1));
		}
	}
}

std::map<std::string, uint32_t> wordCounter::getCounts() const {
	return wordMap;
}
