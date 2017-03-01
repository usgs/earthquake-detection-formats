#include "station.h"

#include <limits>

// JSON Keys
#define TYPE_KEY "Type"
#define SITE_KEY "Site"
#define LATITUDE_KEY "Latitude"
#define LONGITUDE_KEY "Longitude"
#define ELEVATION_KEY "Elevation"
#define QUALITY_KEY "Quality"
#define ENABLE_KEY "Enable"
#define USEFORTELESEISMIC_KEY "UseForTeleseismic"

namespace detectionformats {
station::station() {
	type = STATION_TYPE;
	site = detectionformats::site();
	latitude = std::numeric_limits<double>::quiet_NaN();
	longitude = std::numeric_limits<double>::quiet_NaN();
	elevation = std::numeric_limits<double>::quiet_NaN();
	quality = std::numeric_limits<double>::quiet_NaN();
	enable = true;
	useforteleseismic = false;
}

station::station(std::string newstation, std::string newchannel,
		std::string newnetwork, std::string newlocation, double newlatitude,
		double newlongitude, double newelevation, double newquality,
		bool newenable, bool newuseforteleseismic) {
	type = STATION_TYPE;
	site = detectionformats::site(newstation, newchannel, newnetwork,
			newlocation);
	latitude = newlatitude;
	longitude = newlongitude;
	elevation = newelevation;
	quality = newquality;
	enable = newenable;
	useforteleseismic = newuseforteleseismic;
}

station::station(detectionformats::site newsite, double newlatitude,
		double newlongitude, double newelevation, double newquality,
		bool newenable, bool newuseforteleseismic) {
	type = STATION_TYPE;
	station::site = newsite;
	latitude = newlatitude;
	longitude = newlongitude;
	elevation = newelevation;
	quality = newquality;
	enable = newenable;
	useforteleseismic = newuseforteleseismic;
}

station::station(rapidjson::Value &json) {
	// required values
	// type
	if ((json.HasMember(TYPE_KEY) == true)
			&& (json[TYPE_KEY].IsString() == true))
		type = std::string(json[TYPE_KEY].GetString(),
				json[TYPE_KEY].GetStringLength());
	else
		type = "";

	// site
	if ((json.HasMember(SITE_KEY) == true)
			&& (json[SITE_KEY].IsObject() == true)) {
		rapidjson::Value & sitevalue = json["Site"];
		site = detectionformats::site(sitevalue);
	} else
		site = detectionformats::site();

	// latitude
	if ((json.HasMember(LATITUDE_KEY) == true)
			&& (json[LATITUDE_KEY].IsNumber() == true)
			&& (json[LATITUDE_KEY].IsDouble() == true))
		latitude = json[LATITUDE_KEY].GetDouble();
	else
		latitude = std::numeric_limits<double>::quiet_NaN();

	// longitude
	if ((json.HasMember(LONGITUDE_KEY) == true)
			&& (json[LONGITUDE_KEY].IsNumber() == true)
			&& (json[LONGITUDE_KEY].IsDouble() == true))
		longitude = json[LONGITUDE_KEY].GetDouble();
	else
		longitude = std::numeric_limits<double>::quiet_NaN();

	// elevation
	if ((json.HasMember(ELEVATION_KEY) == true)
			&& (json[ELEVATION_KEY].IsNumber() == true)
			&& (json[ELEVATION_KEY].IsDouble() == true))
		elevation = json[ELEVATION_KEY].GetDouble();
	else
		elevation = std::numeric_limits<double>::quiet_NaN();

	// optional values
	// quality
	if ((json.HasMember(QUALITY_KEY) == true)
			&& (json[QUALITY_KEY].IsNumber() == true)
			&& (json[QUALITY_KEY].IsDouble() == true))
		quality = json[QUALITY_KEY].GetDouble();
	else
		quality = std::numeric_limits<double>::quiet_NaN();

	// enable
	if ((json.HasMember(ENABLE_KEY) == true)
			&& (json[ENABLE_KEY].IsBool() == true))
		enable = json[ENABLE_KEY].GetBool();
	else
		enable = true;

	// useforteleseismic
	if ((json.HasMember(USEFORTELESEISMIC_KEY) == true)
			&& (json[USEFORTELESEISMIC_KEY].IsBool() == true))
		useforteleseismic = json[USEFORTELESEISMIC_KEY].GetBool();
	else
		useforteleseismic = false;
}

station::station(const station &newstation) {
	type = STATION_TYPE;
	site = newstation.site;
	latitude = newstation.latitude;
	longitude = newstation.longitude;
	elevation = newstation.elevation;
	quality = newstation.quality;
	enable = newstation.enable;
	useforteleseismic = newstation.useforteleseismic;
}

station::~station() {
}

rapidjson::Value & station::tojson(rapidjson::Value &json,
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

	// latitude
	if (std::isnan(latitude) != true)
		json.AddMember(LATITUDE_KEY, latitude, allocator);

	// longitude
	if (std::isnan(longitude) != true)
		json.AddMember(LONGITUDE_KEY, longitude, allocator);

	// elevation
	if (std::isnan(elevation) != true)
		json.AddMember(ELEVATION_KEY, elevation, allocator);

	// optional values
	// quality
	if (std::isnan(quality) != true)
		json.AddMember(QUALITY_KEY, quality, allocator);

	// enable
	json.AddMember(ENABLE_KEY, enable, allocator);

	// useforteleseismic
	json.AddMember(USEFORTELESEISMIC_KEY, useforteleseismic, allocator);

	return (json);
}

std::vector<std::string> station::geterrors() {
	std::vector<std::string> errorlist;

	// check for required data
	// Type
	if (type != STATION_TYPE) {
		// wrong type
		errorlist.push_back("Non-station type in station class.");
	}

	// site
	if (site.isvalid() != true) {
		// site not found
		errorlist.push_back("Site object did not validate in station class.");
	}

	// latitude
	if (std::isnan(latitude) == true) {
		// latitude not found
		errorlist.push_back("No Latitude in station class.");
	} else if ((latitude < -90) || (latitude > 90)) {
		errorlist.push_back("Invalid Latitude in station class.");
	}

	// longitude
	if (std::isnan(longitude) == true) {
		// longitude not found
		errorlist.push_back("No Longitude in station class.");
	} else if ((longitude < -180) || (longitude > 180)) {
		errorlist.push_back("Invalid Longitude in station class.");
	}

	// elevation
	if (std::isnan(elevation) == true) {
		// elevation not found
		errorlist.push_back("No Elevation in station class.");
	}

	// optional data
	// Currently no validation criteria for optional values Quality,
	// Enable, and UseForTeleseismic.

	// return the list of errors
	return (errorlist);
}

}
