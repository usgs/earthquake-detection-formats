#include <eventtype.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define CERTAINTY_KEY "Certainty"

namespace detectionformats {
eventtype::eventtype() {
	type = "";
	certainty = "";
}

eventtype::eventtype(std::string newtype, std::string newcertainty) {
	type = newtype;
	certainty = newcertainty;
}

eventtype::eventtype(rapidjson::Value &json) {
	// required values
	// type
	if ((json.HasMember(TYPE_KEY) == true)
			&& (json[TYPE_KEY].IsString() == true)) {
		type = std::string(json[TYPE_KEY].GetString(),
								json[TYPE_KEY].GetStringLength());
	} else {
		type = "";
	}

	// author
	if ((json.HasMember(CERTAINTY_KEY) == true)
			&& (json[CERTAINTY_KEY].IsString() == true)) {
		certainty = std::string(json[CERTAINTY_KEY].GetString(),
								json[CERTAINTY_KEY].GetStringLength());
	} else {
		certainty = "";
	}
}

eventtype::eventtype(const eventtype & neweventtype) {
	type = neweventtype.type;
	certainty = neweventtype.certainty;
}

eventtype::~eventtype() {
}

rapidjson::Value & eventtype::tojson(
		rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// required values
	// type
	if (type != "") {
		rapidjson::Value typeidvalue;
		typeidvalue.SetString(rapidjson::StringRef(type.c_str()),
								allocator);
		json.AddMember(TYPE_KEY, typeidvalue, allocator);
	}

	// certainty
	if (certainty != "") {
		rapidjson::Value certaintyvalue;
		certaintyvalue.SetString(rapidjson::StringRef(certainty.c_str()),
            allocator);
		json.AddMember(CERTAINTY_KEY, certaintyvalue, allocator);
	}

	return (json);
}

std::vector<std::string> eventtype::geterrors() {
	std::vector<std::string> errorlist;

    // type
	if (type.empty() == false) {
		bool match = false;
		// check all the valid types to see if this string matches
		for (int i = detectionformats::eventtypeindex::earthquake;
				i < detectionformats::eventtypeindex::eventtypecount; i++) {
			if (type == eventtypevalues[i]) {
				match = true;
				break;
			}
		}

		if (match == false) {
			errorlist.push_back("Invalid Type in eventtype class.");
		}
	}

	// certainty
	if (certainty.empty() == false) {
		bool match = false;
		// check all the valid types to see if this string matches
		for (int i = detectionformats::eventtypecertaintyindex::suspected;
				i < detectionformats::eventtypecertaintyindex::eventtypecertaintycount; // NOLINT
                i++) {
			if (certainty == eventtypecertaintyvalues[i]) {
				match = true;
				break;
			}
		}

		if (match == false) {
			errorlist.push_back("Invalid Certainty in eventtype class.");
		}
	}

	// return the list of errors
	return (errorlist);
}

bool eventtype::isempty() {
	if (type.empty() == false)
		return (false);
	if (certainty.empty() == false)
		return (false);

	return (true);
}
}  // namespace detectionformats
