//STL includes

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <locale>

//Project-specific includes
#include "fileReader.h"
#include "wordCounter.h"
#include "output.h"
#include "cmdargs.h"
#include "unionMap.h"
#include "learningMode.h"

output* setUpOutput(const std::string& outputFileName);
void invertValues(std::map<std::string, int>& rMap);
enum class mode { LM, MM, NS }; //LM = learningMode, MM = mainMode, NS = No Mode Set

int main(int argc, char** argv) {
	mode m = mode::NS;
	cmdargs arguments(argc,argv);
	std::string resumeFileName="";
	std::string descriptionName="";
	std::string outputFile="";
	std::string ignoreFile="";
	std::string settingsFile = "./settings.ini";
	const std::string version = "V0.6";
	std::cout<<"Frequency Analysis Program " << version << std::endl;
	std::cout<<"Populating internal variables based on arguments..."
		<< std::endl;
	std::string currentArg="";
	//First attempt to resolve command-line arguments
	do {
		currentArg = arguments.nextArg();
		if(currentArg.empty())
			break;
		if((currentArg) == "-r"){
			resumeFileName = arguments.nextArg();
			std::cout<<"Setting resumeFileName to: "
			<< resumeFileName << std::endl;
		}
		else if((currentArg) == "-d"){
			descriptionName = arguments.nextArg();
			std::cout<<"Setting descriptionName to: "
			<< descriptionName << std::endl;
		}
		else if((currentArg) == "-s"){
			settingsFile = arguments.nextArg();
		}
		else if((currentArg) == "-o") {
			outputFile = arguments.nextArg();
			std::cout<<"Setting output file to: " 
			<<outputFile << std::endl;
		}
		else if((currentArg) == "-l") {
			m = mode::LM;
			std::cout<<"Entering learning mode." <<std::endl;
		}
		else if((currentArg) == "-m"){
			m = mode::MM;
			std::cout<<"Entering main mode." <<std::endl;
		}
		else if((currentArg) == "-i"){
			ignoreFile = arguments.nextArg();
			std::cout<<"Ignore Words file is: " << ignoreFile << std::endl;
		}
		else {
			std::cerr<<"Unknown Parameter: " << currentArg
			<<"\nPlease consult usage guide.";
			return -1;
		}
	} while(!currentArg.empty());
	//After going through command-line arguments, fill in gaps from settings file.
	std::cout<<"Going with defaults for unspecified options..."<<std::endl;
	std::ifstream inSettings(settingsFile);
	if(!inSettings.is_open()){
		std::cerr<<"Error: Missing or corrupted settings file!" <<std::endl;
		return -1;
	}
	std::string settingsLine;
	while(std::getline(inSettings,settingsLine)){
		auto splitter = settingsLine.find('=');
		std::string option = settingsLine.substr(0,splitter);
		std::string value = settingsLine.substr(splitter+1);
		if(option == "DEFAULTRESUME" && resumeFileName.empty()) {
			resumeFileName = value;
		}
		else if(option == "DEFAULTDESCRIPTION" && descriptionName.empty()){
			descriptionName = value;
		}
		else if(option == "DEFAULTWRITEFILE" && outputFile.empty()) {
			outputFile = value;
		}
		else if(option =="IGNOREFILE" && ignoreFile.empty()){
			ignoreFile = value;
		}
	}
	std::cout<<"All Settings are now set. "<<std::endl;
	while(m == mode::NS) {
		char choice;
		std::cout<<"Which mode would you like to use? (l)earning mode, (m)ain mode: ";
		std::cin>>choice;
		switch(choice) {
			case 'l':
			case 'L':
				m = mode::LM;
				std::cout<<"Setting learning mode." <<std::endl;
				std::cin.ignore(
				std::numeric_limits<std::streamsize>::max(),'\n');
				break;

			case 'm':
			case 'M':
				m = mode::MM;
				std::cout<<"Setting main mode."<<std::endl;
				std::cin.ignore(
				std::numeric_limits<std::streamsize>::max(),'\n');
				break;
			default :
				std::cout<<"Please enter a valid choice: ";
		}
	}
	std::cout<<"Setting up resume file...";
	fileReader resume(resumeFileName);
	std::cout<<"done. Using: "<< resumeFileName <<std::endl;
	
	std::cout<<"Setting up description file...";	
	fileReader description(descriptionName); 
	std::cout<<"done. Using: " <<descriptionName <<std::endl;
	
	std::cout<<"Setting up word blacklist file...";
	fileReader wordsToIgnore(ignoreFile);
	std::cout<<"done. Using: "<<ignoreFile<<std::endl;

	std::cout<<"Getting Word List from Resume...";
	std::vector<std::string> resumeWords = resume.getWords();
	std::cout<<"done." <<std::endl;
	resume.closeFile();

	std::cout<<"Getting Word List from Description...";
	std::vector<std::string> descriptionWords = description.getWords();
	std::cout<<"done." <<std::endl;
	description.closeFile();

	std::cout<<"Getting Word List from blacklist file...";
	std::vector<std::string> blackListWords = wordsToIgnore.getWords();
	std::cout<<"done."<<std::endl;
	wordsToIgnore.closeFile();

	std::cout<<"Setting up Word Counter for description words...";
	wordCounter descriptionCounter(descriptionWords);
	std::cout<<"done."<<std::endl;

	std::cout<<"Setting up Word Counter for resume words...";
	wordCounter resumeCounter(resumeWords);
	std::cout<<"done."<<std::endl;

	if(m == mode::MM){
		std::cout<<outputFile;
		output* outputter = setUpOutput(outputFile);
		std::map<std::string, int> resumeMap = resumeCounter.getCounts();
		std::map<std::string, int> descriptionMap = descriptionCounter.getCounts();
		std::cout<<"Inverting resume values...";
		invertValues(resumeMap);
		std::cout<<"Done!"<<std::endl;
		unionMap uMap(resumeMap, descriptionMap);
		std::map<std::string, int> testUMap = uMap.getUnionMap();
		for(auto k : testUMap){
			if((std::find(blackListWords.begin(), blackListWords.end(), k.first)) != blackListWords.end())
				continue;
			std::cout<<"Union Map Element: " << k.first << " " << k.second << std::endl;
			std::vector<std::string> v;
			v.push_back(k.first);
			v.push_back(std::to_string(k.second));
			outputter->writeLine(v);
		}
		delete outputter;
	}
	else if(m == mode::LM){
		learningMode learn(blackListWords, descriptionCounter.getCounts());
		std::ofstream out(ignoreFile);
		std::vector<std::string> v = learn.getFullWords();
		for(auto i : v)
			out<<i<<'\n';
	}
	return 0;

}

output* setUpOutput(const std::string& outputFileName) {
	std::string extension = outputFileName.substr(outputFileName.rfind('.')+1);
	std::cout<<"File Extension: " <<extension <<std::endl;
	if(extension == "csv"){
		return (new CSVOutput(outputFileName));
	}
	else if(extension == "html"){
		return (new HTMLOutput(outputFileName));
	}
	else {
		std::cout<<"Unknown file-type extension, defaulting to CSV-style file..."
		<< std::endl;
		return (new CSVOutput(outputFileName));
	}
}

void invertValues(std::map<std::string, int>& uMap){
	for(auto it = uMap.begin(); it != uMap.end(); ++it){
		it->second = -1*(it->second);
	}
}
