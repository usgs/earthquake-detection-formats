#include "hypocenter.h"

#include <limits>

// JSON Keys
#define LATITUDE_KEY "Latitude"
#define LONGITUDE_KEY "Longitude"
#define DEPTH_KEY "Depth"
#define TIME_KEY "Time"
#define LATITUDE_ERROR_KEY "LatitudeError"
#define LONGITUDE_ERROR_KEY "LongitudeError"
#define DEPTH_ERROR_KEY "DepthError"
#define TIME_ERROR_KEY "TimeError"

namespace detectionformats {

hypocenter::hypocenter() {
	latitude = std::numeric_limits<double>::quiet_NaN();
	longitude = std::numeric_limits<double>::quiet_NaN();
	depth = std::numeric_limits<double>::quiet_NaN();
	time = std::numeric_limits<double>::quiet_NaN();
	latitudeerror = std::numeric_limits<double>::quiet_NaN();
	longitudeerror = std::numeric_limits<double>::quiet_NaN();
	deptherror = std::numeric_limits<double>::quiet_NaN();
	timeerror = std::numeric_limits<double>::quiet_NaN();

}

hypocenter::hypocenter(double newlatitude, double newlongitude, double newtime,
		double newdepth, double newlatitudeerror, double newlongitudeerror,
		double newtimeerror, double newdeptherror) {
	latitude = newlatitude;
	longitude = newlongitude;
	depth = newdepth;
	time = newtime;
	latitudeerror = newlatitudeerror;
	longitudeerror = newlongitudeerror;
	deptherror = newdeptherror;
	timeerror = newtimeerror;
}

hypocenter::hypocenter(rapidjson::Value &json) {
	// required values
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

	// time
	if ((json.HasMember(TIME_KEY) == true)
			&& (json[TIME_KEY].IsString() == true))
		time = detectionformats::ConvertISO8601ToEpochTime(
				std::string(json[TIME_KEY].GetString(),
						json[TIME_KEY].GetStringLength()));
	else
		time = std::numeric_limits<double>::quiet_NaN();

	// depth
	if ((json.HasMember(DEPTH_KEY) == true)
			&& (json[DEPTH_KEY].IsNumber() == true)
			&& (json[DEPTH_KEY].IsDouble() == true))
		depth = json[DEPTH_KEY].GetDouble();
	else
		depth = std::numeric_limits<double>::quiet_NaN();

	// optional values
	// latitude error
	if ((json.HasMember(LATITUDE_ERROR_KEY) == true)
			&& (json[LATITUDE_ERROR_KEY].IsNumber() == true)
			&& (json[LATITUDE_ERROR_KEY].IsDouble() == true))
		latitudeerror = json[LATITUDE_ERROR_KEY].GetDouble();
	else
		latitudeerror = std::numeric_limits<double>::quiet_NaN();

	// longitude error
	if ((json.HasMember(LONGITUDE_ERROR_KEY) == true)
			&& (json[LONGITUDE_ERROR_KEY].IsNumber() == true)
			&& (json[LONGITUDE_ERROR_KEY].IsDouble() == true))
		longitudeerror = json[LONGITUDE_ERROR_KEY].GetDouble();
	else
		longitudeerror = std::numeric_limits<double>::quiet_NaN();

	// time error
	if ((json.HasMember(TIME_ERROR_KEY) == true)
			&& (json[TIME_ERROR_KEY].IsNumber() == true)
			&& (json[TIME_ERROR_KEY].IsDouble() == true))
		timeerror = json[TIME_ERROR_KEY].GetDouble();
	else
		timeerror = std::numeric_limits<double>::quiet_NaN();

	// depth error
	if ((json.HasMember(DEPTH_ERROR_KEY) == true)
			&& (json[DEPTH_ERROR_KEY].IsNumber() == true)
			&& (json[DEPTH_ERROR_KEY].IsDouble() == true))
		deptherror = json[DEPTH_ERROR_KEY].GetDouble();
	else
		deptherror = std::numeric_limits<double>::quiet_NaN();
}

hypocenter::hypocenter(const hypocenter & newhypocenter) {
	latitude = newhypocenter.latitude;
	longitude = newhypocenter.longitude;
	depth = newhypocenter.depth;
	time = newhypocenter.time;
	latitudeerror = newhypocenter.latitudeerror;
	longitudeerror = newhypocenter.longitudeerror;
	deptherror = newhypocenter.deptherror;
	timeerror = newhypocenter.timeerror;
}

hypocenter::~hypocenter() {
}

rapidjson::Value & hypocenter::tojson(rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// required values
	// latitude
	if (std::isnan(latitude) != true)
		json.AddMember(LATITUDE_KEY, latitude, allocator);

	// longitude
	if (std::isnan(longitude) != true)
		json.AddMember(LONGITUDE_KEY, longitude, allocator);

	// time
	if (std::isnan(time) != true) {
		std::string timestring = detectionformats::ConvertEpochTimeToISO8601(
				time);
		rapidjson::Value timevalue;
		timevalue.SetString(rapidjson::StringRef(timestring.c_str()),
				allocator);
		json.AddMember(TIME_KEY, timevalue, allocator);
	}

	// depth
	if (std::isnan(depth) != true)
		json.AddMember(DEPTH_KEY, depth, allocator);

	// optional values
	// latitude error
	if (std::isnan(latitudeerror) != true)
		json.AddMember(LATITUDE_ERROR_KEY, latitudeerror, allocator);

	// longitude error
	if (std::isnan(longitudeerror) != true)
		json.AddMember(LONGITUDE_ERROR_KEY, longitudeerror, allocator);

	// time error
	if (std::isnan(timeerror) != true)
		json.AddMember(TIME_ERROR_KEY, timeerror, allocator);

	// depth error
	if (std::isnan(deptherror) != true)
		json.AddMember(DEPTH_ERROR_KEY, deptherror, allocator);

	return (json);
}

std::vector<std::string> hypocenter::geterrors() {
	std::vector<std::string> errorlist;

	// check required data
	// latitude
	if (std::isnan(latitude) == true) {
		// latitude not found
		errorlist.push_back("No Latitude in hypocenter class.");
	} else if ((latitude < -90) || (latitude > 90)) {
		errorlist.push_back("Invalid Latitude in hypocenter class.");
	}

	// longitude
	if (std::isnan(longitude) == true) {
		// longitude not found
		errorlist.push_back("No Longitude in hypocenter class.");
	} else if ((longitude < -180) || (longitude > 180)) {
		errorlist.push_back("Invalid Longitude in hypocenter class.");
	}

	// time
	if (std::isnan(time) == true) {
		errorlist.push_back("Time is missing in hypocenter class.");
	} else {
		try {
			if (detectionformats::IsStringISO8601(
					detectionformats::ConvertEpochTimeToISO8601(time))
					== false) {
				errorlist.push_back(
						"Time did not validate in hypocenter class.");
			}
		} catch (const std::exception & e) {
			errorlist.push_back(std::string(e.what()));
		}
	}

	// depth
	if (std::isnan(depth) == true) {
		// depth not found
		errorlist.push_back("No Depth in hypocenter class.");
	} else if ((depth < -100) || (depth > 1500)) {
		errorlist.push_back("Invalid Depth in hypocenter class.");
	}

	// optional keys
	// Currently no validation criteria for optional values LatitudeError,
	// LongitudeError, TimeError, and DepthError.

	// return the list of errors
	return (errorlist);
}

}
