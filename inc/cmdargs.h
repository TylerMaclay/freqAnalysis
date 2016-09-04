#ifndef _TM_CMDARGS_H
#define _TM_CMDARGS_H

#include <string>
#include <vector>

class cmdargs {
	private:
		std::vector<std::string> args;
		std::vector<std::string>::iterator it;

	public:
		cmdargs(const int argc,  char** argv);
		std::string nextArg() ;
};

#endif
