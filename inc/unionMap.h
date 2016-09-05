#include <map>
#include <string>
#include <algorithm>

class unionMap{
	private:
		std::map<std::string, uint32_t> unionMap_m;

	public:
		unionMap(std::map<std::string, uint32_t>, std::map<std::string, uint32_t>);
		std::map<std::string, uint32_t> getUnionMap() const;
};
