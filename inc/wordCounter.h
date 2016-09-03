#ifndef _TM_WORDCOUNTER_H
#define _TM_WORDCOUNTER_H

#include <vector>
#include <map>
#include <string>

class wordCounter {
	private:
		std::map<std::string, uint32_t> wordMap;
	public:
		wordCounter(const std::vector<std::string>& words);
		std::map<std::string, uint32_t> getCounts() const;
};

#endif
