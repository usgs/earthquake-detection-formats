#include <base.h>
#include <string>
#include <vector>

namespace detectionformats {
detectionbase::detectionbase() {
	type = "";
}

detectionbase::~detectionbase() {
}

bool detectionbase::isvalid() {
	std::vector<std::string> errorlist = geterrors();
	std::string errorstring = "";

	if (errorlist.size() == 0) {
		// no errors
		return (true);
	} else {
		return (false);
	}
}
}  // namespace detectionformats
