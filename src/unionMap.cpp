#include "unionMap.h"
#include <map>
#include <string>
#include <algorithm>

unionMap::unionMap(std::map<std::string, uint32_t> map1, std::map<std::string, uint32_t> map2){
	//Populate unionMap
	auto i = map1.begin();
	auto j = map2.begin();

	while(i != map1.end() || j != map2.end()){
		int lexComp = (i->first).compare(j->first);
		while(lexComp < 0 ){
			unionMap_m[i->first] = i->second;
			i++;
			lexComp = (i->first).compare(j->first);
		}
		if(lexComp == 0) {
			unionMap_m[i->first] = ((i->second) - (j->second));
			i++;
			j++;
		}
		while(lexComp > 0){
			unionMap_m[i->first] = i->second;
			lexComp = (i->first).compare(j->first);
		}
	}
}

std::map<std::string, uint32_t> unionMap::getUnionMap() const {
	return unionMap_m;
}
