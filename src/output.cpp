#include "output.h"
#include <string>
#include <fstream>

output::output(const std::string& oFile) { outFile.open(oFile); }
output::~output() { outFile.close();}

CSVOutput::CSVOutput(const std::string& oFile) : output(oFile) {}
HTMLOutput::HTMLOutput(const std::string& oFile) : output(oFile) {}

void CSVOutput::writeLine(const std::string& data1, const std::string& data2) {
	outFile << data1 << "," << data2 << "\n";
}

void HTMLOutput::writeLine(const std::string& data1, const std::string& data2){
	outFile << "<TR><TD>" << data1 << "</TD><TD>" << data2 << "</TD></TR>";
}
