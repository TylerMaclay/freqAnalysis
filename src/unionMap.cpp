#include "unionMap.h"
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

unionMap::unionMap(std::map<std::string, uint32_t> map1, std::map<std::string, uint32_t> map2){
	//Populate unionMap
	auto i = map1.begin();
	auto j = map2.begin();
	int lexComp = 0;

	while(i != map1.end() || j != map2.end()){
		if(!(i == map1.end() || j == map2.end()))
			lexComp = (i->first).compare(j->first);
		
		while(lexComp < 0 && i != map1.end()){
			unionMap_m[i->first] = i->second;
			++i;
			if(i != map1.end() && j != map2.end()){
				lexComp = (i->first).compare(j->first);
			}
			else if(i ==  map1.end()){
				lexComp = 1;
			}

		}
		if(lexComp == 0) {
			unionMap_m[i->first] = ((i->second) - (j->second));
			if(i != map1.end() && j != map2.end()){
				i++;
				j++;
			}
			else if(i == map1.end())
				j++;
			else if(j == map2.end())
				i++;

		}
		while(lexComp > 0 && j != map2.end()){
			unionMap_m[j->first] = j->second;
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

std::map<std::string, uint32_t> unionMap::getUnionMap() const {
	return unionMap_m;
}
