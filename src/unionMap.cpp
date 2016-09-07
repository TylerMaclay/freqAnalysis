#include "unionMap.h"
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

unionMap::unionMap(std::map<std::string, int> map1, std::map<std::string, int> map2){
	//Populate unionMap
	auto i = map1.begin();
	auto j = map2.begin();
	int lexComp = 0;

	while(i != map1.end() || j != map2.end()){
		if(!(i == map1.end() || j == map2.end()))
			lexComp = (i->first).compare(j->first);
		
		while(lexComp < 0 && i != map1.end()){
			unionMap_m[i->first] = i->second;
			//std::cout<<"Entered1: " << i->first << " " <<i->second << std::endl;
			++i;
			if(i != map1.end() && j != map2.end()){
				lexComp = (i->first).compare(j->first);
			}
			else if(i ==  map1.end()){
				lexComp = 1;
			}

		}
		if(lexComp == 0) {
			unionMap_m[i->first] = ((i->second) + (j->second));
			//std::cout<<"Entered2: " << i->first << " " << i->second - j->second <<std::endl;
			if(i != map1.end() && j != map2.end()){
				i++;
				j++;
				if(i == map1.end())
					lexComp = 1;
				else if(j == map2.end())
					lexComp = -1;
				else
					lexComp = (i->first).compare(j->first);
			}
			else if(i == map1.end()){
				lexComp = 1;
				j++;
			}
			else if(j == map2.end()){
				i++;
				lexComp = -1;
			}

		}
		while(lexComp > 0 && j != map2.end()){
			unionMap_m[j->first] = j->second;
			//std::cout<<"Entered3: " << j->first << " " << j->second << std::endl;
			j++;
			if(j != map2.end() && i != map1.end()){
				lexComp = (i->first).compare(j->first);
			}
			else if(j == map2.end()){
				lexComp = -1;
			}
		}
	}
}

std::map<std::string, int> unionMap::getUnionMap() const {
	return unionMap_m;
}
