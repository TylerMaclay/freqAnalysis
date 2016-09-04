#ifndef _TM_OUTPUT_H
#define _TM_OUTPUT_H

#include <fstream>
#include <string>

class output {
	public:
		std::ofstream outFile;
		output(const std::string&);
		~output();
		virtual void writeLine(const std::string&, const std::string&)=0 ;
};

class CSVOutput : public output {
	public:
		CSVOutput(const std::string&);
		void writeLine(const std::string&, const std::string&) ;
};

class HTMLOutput : public output {
	public:
		HTMLOutput(const std::string&);
		void writeLine(const std::string&, const std::string&) ;
};

#endif
