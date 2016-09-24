#ifndef _TM_FILEREADER_H
#define _TM_FILEREADER_H

#include <string>
#include <vector>
#include <fstream>

class fileReader {
	private:
		std::string fileName;
		std::ifstream in;
	
	public:

		fileReader(const std::string& ifn);
		std::vector<std::string> getWords();
		void closeFile();
		void openFile();

};

#endif
