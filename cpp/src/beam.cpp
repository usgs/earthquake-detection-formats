#include <beam.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define BACKAZIMUTH_KEY "BackAzimuth"
#define SLOWNESS_KEY "Slowness"
#define POWERRATIO_KEY "PowerRatio"
#define BACKAZIMUTHERROR_KEY "BackAzimuthError"
#define SLOWNESSERROR_KEY "SlownessError"
#define POWERRATIOERROR_KEY "PowerRatioError"

namespace detectionformats {
beam::beam() {
	backazimuth = std::numeric_limits<double>::quiet_NaN();
	backazimutherror = std::numeric_limits<double>::quiet_NaN();
	slowness = std::numeric_limits<double>::quiet_NaN();
	slownesserror = std::numeric_limits<double>::quiet_NaN();
	powerratio = std::numeric_limits<double>::quiet_NaN();
	powerratioerror = std::numeric_limits<double>::quiet_NaN();
}

beam::beam(double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror) {
	backazimuth = newbackazimuth;
	backazimutherror = newbackazimutherror;
	slowness = newslowness;
	slownesserror = newslownesserror;
	powerratio = newpowerratio;
	powerratioerror = newpowerratioerror;
}

beam::beam(rapidjson::Value &json) {
	// required values
	// backazimuth
	if ((json.HasMember(BACKAZIMUTH_KEY) == true)
			&& (json[BACKAZIMUTH_KEY].IsNumber() == true)
			&& (json[BACKAZIMUTH_KEY].IsDouble() == true))
		backazimuth = json[BACKAZIMUTH_KEY].GetDouble();
	else
		backazimuth = std::numeric_limits<double>::quiet_NaN();

	// slowness
	if ((json.HasMember(SLOWNESS_KEY) == true)
			&& (json[SLOWNESS_KEY].IsNumber() == true)
			&& (json[SLOWNESS_KEY].IsDouble() == true))
		slowness = json[SLOWNESS_KEY].GetDouble();
	else
		slowness = std::numeric_limits<double>::quiet_NaN();

	// optional values
	// power ratio
	if ((json.HasMember(POWERRATIO_KEY) == true)
			&& (json[POWERRATIO_KEY].IsNumber() == true)
			&& (json[POWERRATIO_KEY].IsDouble() == true))
		powerratio = json[POWERRATIO_KEY].GetDouble();
	else
		powerratio = std::numeric_limits<double>::quiet_NaN();

	// backazimutherror
	if ((json.HasMember(BACKAZIMUTHERROR_KEY) == true)
			&& (json[BACKAZIMUTHERROR_KEY].IsNumber() == true)
			&& (json[BACKAZIMUTHERROR_KEY].IsDouble() == true))
		backazimutherror = json[BACKAZIMUTHERROR_KEY].GetDouble();
	else
		backazimutherror = std::numeric_limits<double>::quiet_NaN();

	// slownesserror
	if ((json.HasMember(SLOWNESSERROR_KEY) == true)
			&& (json[SLOWNESSERROR_KEY].IsNumber() == true)
			&& (json[SLOWNESSERROR_KEY].IsDouble() == true))
		slownesserror = json[SLOWNESSERROR_KEY].GetDouble();
	else
		slownesserror = std::numeric_limits<double>::quiet_NaN();

	// powerratioerror
	if ((json.HasMember(POWERRATIOERROR_KEY) == true)
			&& (json[POWERRATIOERROR_KEY].IsNumber() == true)
			&& (json[POWERRATIOERROR_KEY].IsDouble() == true))
		powerratioerror = json[POWERRATIOERROR_KEY].GetDouble();
	else
		powerratioerror = std::numeric_limits<double>::quiet_NaN();
}

beam::beam(const beam &newbeam) {
	backazimuth = newbeam.backazimuth;
	backazimutherror = newbeam.backazimutherror;
	slowness = newbeam.slowness;
	slownesserror = newbeam.slownesserror;
	powerratio = newbeam.powerratio;
	powerratioerror = newbeam.powerratioerror;
}

beam::~beam() {
}

rapidjson::Value & beam::tojson(
		rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// required values
	// backazimuth
	if (std::isnan(backazimuth) != true)
		json.AddMember(BACKAZIMUTH_KEY, backazimuth, allocator);

	// slowness
	if (std::isnan(slowness) != true)
		json.AddMember(SLOWNESS_KEY, slowness, allocator);

	// optional values
	// powerratio
	if (std::isnan(powerratio) != true)
		json.AddMember(POWERRATIO_KEY, powerratio, allocator);

	// backazimutherror
	if (std::isnan(backazimutherror) != true)
		json.AddMember(BACKAZIMUTHERROR_KEY, backazimutherror, allocator);

	// slownesserror
	if (std::isnan(slownesserror) != true)
		json.AddMember(SLOWNESSERROR_KEY, slownesserror, allocator);

	// powerratioerror
	if (std::isnan(powerratioerror) != true)
		json.AddMember(POWERRATIOERROR_KEY, powerratioerror, allocator);

	return (json);
}

std::vector<std::string> beam::geterrors() {
	std::vector<std::string> errorlist;

	// check required data
	// backazimuth
	if (std::isnan(backazimuth) == true) {
		// backazimuth not found
		errorlist.push_back("No BackAzimuth in beam class.");
	}
	if (backazimuth < 0) {
		errorlist.push_back("Invalid BackAzimuth in beam class.");
	}

	// slowness
	if (std::isnan(slowness) == true) {
		// slowness not found
		errorlist.push_back("No Slowness in beam class.");
	}
	if (slowness < 0) {
		errorlist.push_back("Invalid Slowness in beam class.");
	}

	// optional data
	// powerratio
	if (std::isnan(powerratio) != true) {
		if (powerratio < 0) {
			errorlist.push_back("Invalid PowerRatio in beam class.");
		}
	}

	// backazimutherror
	if (std::isnan(backazimutherror) != true) {
		if (backazimutherror < 0) {
			errorlist.push_back("Invalid BackAzimuthError in beam class.");
		}
	}
	// slownesserror
	if (std::isnan(slownesserror) != true) {
		if (slownesserror < 0) {
			errorlist.push_back("Invalid SlownessError in beam class.");
		}
	}
	// powerratioerror
	if (std::isnan(powerratioerror) != true) {
		if (powerratioerror < 0) {
			errorlist.push_back("Invalid PowerRatioError in beam class.");
		}
	}

	// return the list of errors
	return (errorlist);
}

bool beam::isempty() {
	if (std::isnan(backazimuth) != true)
		return (false);
	if (std::isnan(slowness) != true)
		return (false);
	if (std::isnan(powerratio) != true)
		return (false);
	if (std::isnan(backazimutherror) != true)
		return (false);
	if (std::isnan(slownesserror) != true)
		return (false);
	if (std::isnan(powerratioerror) != true)
		return (false);

	return (true);
}
}  // namespace detectionformats
