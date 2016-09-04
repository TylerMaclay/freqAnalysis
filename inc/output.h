#ifndef _TM_OUTPUT_H
#define _TM_OUTPUT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class output {
	public:
		std::ofstream outFile;
		output(const std::string&);
		virtual ~output();
		virtual void writeLine(const std::vector<std::string>&)=0 ;
};

class CSVOutput : public output {
	public:
		CSVOutput(const std::string&);
		void writeLine(const std::vector<std::string>&);
		~CSVOutput();
};

class HTMLOutput : public output {
	public:
		HTMLOutput(const std::string&);
		void writeLine(const std::vector<std::string>&);
		~HTMLOutput();
};

#endif
