#include "cmdargs.h"
#include <string>
#include <vector>

cmdargs::cmdargs(const int argc,  char** argv) {
	for(int i=1; i < argc; i++){
		args.push_back(std::string(argv[i]));
	}
	it = args.begin();
}

std::string cmdargs::nextArg() {
	std::string returnValue;
	if(it != args.end()){
		returnValue = *it;
		it++;
	}
	else {
		returnValue = "";
	}
	return returnValue;
}
