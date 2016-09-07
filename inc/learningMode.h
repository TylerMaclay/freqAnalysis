#ifndef _TM_LEARNINGMODE_H
#define _TM_LEARNINGMODE_H

#include <map>
#include <vector>
#include <string>
#include <iostream>


class learningMode {
	private:
		std::vector<std::string> uselessWord;
		std::map<std::string, int> wordCountResult;
		bool getResult(const std::string&) const;
		bool checkAgainstList(const std::string&) const;

	public:
		learningMode(std::vector<std::string>, std::map<std::string, int>);
		std::vector<std::string> getFullWords() const;
};

#endif
