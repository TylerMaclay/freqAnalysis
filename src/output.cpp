#include "output.h"
#include <string>
#include <iostream>
#include <fstream>

output::output(const std::string& oFile) { outFile.open(oFile); }
output::~output(){ if(outFile.is_open()) outFile.close(); }
CSVOutput::CSVOutput(const std::string& oFile) : output(oFile) {}
HTMLOutput::HTMLOutput(const std::string& oFile) : output(oFile) {outFile << "<TABLE>";}

CSVOutput::~CSVOutput() { outFile.flush(); outFile.close(); }
HTMLOutput::~HTMLOutput() { outFile << "</TABLE>"; outFile.flush(); outFile.close(); }

void CSVOutput::writeLine(const std::vector<std::string>& data) {
	if(!outFile.is_open())
		std::cerr<<"Warning! File Not Open for writing!" <<std::endl;
	for(auto i = data.begin(); i !=data.end(); i++) {
		outFile << *i;
		if((i+1) != data.end())
			outFile<<",";
	}
	outFile << "\n";
}

void HTMLOutput::writeLine(const std::vector<std::string>& data){
	if(!outFile.is_open())
		std::cerr<<"Warning! File Not Open for Writing!" << std::endl;
	outFile << "<TR>";
	for(auto i = data.begin(); i != data.end(); i++) {
		outFile << "<TD>" << *i << "</TD>";
	}
	outFile << "</TR>\n";
}
