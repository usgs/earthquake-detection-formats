#include <stationInfoRequest.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define TYPE_KEY "Type"
#define SITE_KEY "Site"
#define SOURCE_KEY "Source"

namespace detectionformats {
stationInfoRequest::stationInfoRequest() {
	type = STATIONINFOREQUEST_TYPE;
	site = detectionformats::site();
	source = detectionformats::source();
}

stationInfoRequest::stationInfoRequest(std::string newstation,
										std::string newchannel,
										std::string newnetwork,
										std::string newlocation,
										std::string newagencyid,
										std::string newauthor) {
	type = STATIONINFOREQUEST_TYPE;
	site = detectionformats::site(newstation, newchannel, newnetwork,
									newlocation);
	source = detectionformats::source(newagencyid, newauthor);
}

stationInfoRequest::stationInfoRequest(detectionformats::site newsite,
										detectionformats::source newsource) {
	type = STATIONINFOREQUEST_TYPE;
	site = newsite;
	source = newsource;
}

stationInfoRequest::stationInfoRequest(rapidjson::Value &json) {
	// required values
	// type
	if ((json.HasMember(TYPE_KEY) == true)
			&& (json[TYPE_KEY].IsString() == true)) {
		type = std::string(json[TYPE_KEY].GetString(),
							json[TYPE_KEY].GetStringLength());
	} else {
		type = "";
	}

	// site
	if ((json.HasMember(SITE_KEY) == true)
			&& (json[SITE_KEY].IsObject() == true)) {
		rapidjson::Value & sitevalue = json["Site"];
		site = detectionformats::site(sitevalue);
	} else {
		site = detectionformats::site();
	}

	// source
	if ((json.HasMember(SOURCE_KEY) == true)
			&& (json[SOURCE_KEY].IsObject() == true)) {
		rapidjson::Value & sourcevalue = json[SOURCE_KEY];
		source = detectionformats::source(sourcevalue);
	} else {
		source = detectionformats::source();
	}
}

stationInfoRequest::stationInfoRequest(const stationInfoRequest &newstation) {
	type = STATIONINFOREQUEST_TYPE;
	site = newstation.site;
	source = newstation.source;
}

stationInfoRequest::~stationInfoRequest() {
}

rapidjson::Value & stationInfoRequest::tojson(
		rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// required values
	// type
	rapidjson::Value typevalue;
	typevalue.SetString(rapidjson::StringRef(type.c_str()), allocator);
	json.AddMember(TYPE_KEY, typevalue, allocator);

	// site
	rapidjson::Value sitevalue(rapidjson::kObjectType);
	site.tojson(sitevalue, allocator);
	json.AddMember(SITE_KEY, sitevalue, allocator);

	// source
	rapidjson::Value sourcevalue(rapidjson::kObjectType);
	source.tojson(sourcevalue, allocator);
	json.AddMember(SOURCE_KEY, sourcevalue, allocator);

	return (json);
}

std::vector<std::string> stationInfoRequest::geterrors() {
	std::vector<std::string> errorlist;

	// check for required data
	// Type
	if (type != STATIONINFOREQUEST_TYPE) {
		// wrong type
		errorlist.push_back(
				"Non-stationInfoRequest type in stationInfoRequest class.");
	}

	// site
	if (site.isvalid() != true) {
		// site not found
		errorlist.push_back(
				"Site object did not validate in stationInfoRequest class.");
	}

	// source
	if (source.isvalid() != true) {
		// bad source
		errorlist.push_back(
				"Source object did not validate in stationInfoRequest class.");
	}

	// return the list of errors
	return (errorlist);
}
}  // namespace detectionformats
