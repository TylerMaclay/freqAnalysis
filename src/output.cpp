#include "output.h"
#include <string>
#include <fstream>

output::output(const std::string& oFile) { outFile.open(oFile); }
output::~output() { outFile.close();}

CSVOutput::CSVOutput(const std::string& oFile) : output(oFile) {}
HTMLOutput::HTMLOutput(const std::string& oFile) : output(oFile) {}

void CSVOutput::writeLine(const std::vector<std::string>& data) {
	for(auto i : data) {
		outFile << i << ",";
	}
	outFile << "\n";
}

void HTMLOutput::writeLine(const std::vector<std::string>& data){
	outFile << "<TR>";
	for(auto i : data) {
		outFile << "<TD>" << i << "</TD>";
	}
	outFile << "</TR>\n";
}
