#include <map>
#include <string>
#include <algorithm>

class unionMap{
	private:
		std::map<std::string, int> unionMap_m;

	public:
		unionMap(std::map<std::string, int>, std::map<std::string, int>);
		std::map<std::string, int> getUnionMap() const;
};
