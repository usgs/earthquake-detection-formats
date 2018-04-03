#include <source.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define AGENCYID_KEY "AgencyID"
#define AUTHOR_KEY "Author"

namespace detectionformats {
source::source() {
	agencyid = "";
	author = "";
}

source::source(std::string newagencyid, std::string newauthor) {
	agencyid = newagencyid;
	author = newauthor;
}

source::source(rapidjson::Value &json) {
	// required values
	// agencyid
	if ((json.HasMember(AGENCYID_KEY) == true)
			&& (json[AGENCYID_KEY].IsString() == true)) {
		agencyid = std::string(json[AGENCYID_KEY].GetString(),
								json[AGENCYID_KEY].GetStringLength());
	} else {
		agencyid = "";
	}

	// author
	if ((json.HasMember(AUTHOR_KEY) == true)
			&& (json[AUTHOR_KEY].IsString() == true)) {
		author = std::string(json[AUTHOR_KEY].GetString(),
								json[AUTHOR_KEY].GetStringLength());
	} else {
		author = "";
	}
}

source::source(const source & newsource) {
	agencyid = newsource.agencyid;
	author = newsource.author;
}

source::~source() {
}

rapidjson::Value & source::tojson(
		rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// required values
	// siteid
	if (agencyid != "") {
		rapidjson::Value agencyidvalue;
		agencyidvalue.SetString(rapidjson::StringRef(agencyid.c_str()),
								allocator);
		json.AddMember(AGENCYID_KEY, agencyidvalue, allocator);
	}

	// author
	if (author != "") {
		rapidjson::Value authorvalue;
		authorvalue.SetString(rapidjson::StringRef(author.c_str()), allocator);
		json.AddMember(AUTHOR_KEY, authorvalue, allocator);
	}

	return (json);
}

std::vector<std::string> source::geterrors() {
	std::vector<std::string> errorlist;

	if (agencyid == "") {
		// empty agencyid
		errorlist.push_back("Empty AgencyID in source class.");
	}

	if (author == "") {
		// empty author
		errorlist.push_back("Empty Author in source class.");
	}

	// since agencyid and author are free text strings, no further validation is
	// required.

	// return the list of errors
	return (errorlist);
}

bool source::isempty() {
	if (agencyid != "")
		return (false);
	if (author != "")
		return (false);

	return (true);
}
}  // namespace detectionformats
