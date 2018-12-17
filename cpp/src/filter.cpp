#include <filter.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define HIGHPASS_KEY "HighPass"
#define LOWPASS_KEY "LowPass"
#define UNITS_KEY "Units"

namespace detectionformats {
filter::filter() {
	type = "";
	highpass = std::numeric_limits<double>::quiet_NaN();
	lowpass = std::numeric_limits<double>::quiet_NaN();
	units = "";
}

filter::filter(std::string newtype, double newhighpass, double newlowpass,
		std::string newunits) {
	type = newtype;
	highpass = newhighpass;
	lowpass = newlowpass;
	units = newunits;
}

filter::filter(rapidjson::Value &json) {
	// optional values
	// type
	if ((json.HasMember(TYPE_KEY) == true)
			&& (json[TYPE_KEY].IsString() == true)) {
		type = std::string(json[TYPE_KEY].GetString(),
							json[TYPE_KEY].GetStringLength());
    } else {
		type = "";
    }

	// highpass
	if ((json.HasMember(HIGHPASS_KEY) == true)
			&& (json[HIGHPASS_KEY].IsNumber() == true)
			&& (json[HIGHPASS_KEY].IsDouble() == true)) {
		highpass = json[HIGHPASS_KEY].GetDouble();
	} else {
		highpass = std::numeric_limits<double>::quiet_NaN();
	}

	// lowpass
	if ((json.HasMember(LOWPASS_KEY) == true)
			&& (json[LOWPASS_KEY].IsNumber() == true)
			&& (json[LOWPASS_KEY].IsDouble() == true)) {
		lowpass = json[LOWPASS_KEY].GetDouble();
	} else {
		lowpass = std::numeric_limits<double>::quiet_NaN();
	}

	// units
	if ((json.HasMember(UNITS_KEY) == true)
			&& (json[UNITS_KEY].IsString() == true)) {
		units = std::string(json[UNITS_KEY].GetString(),
							json[UNITS_KEY].GetStringLength());
    } else {
		units = "";
    }
}

filter::filter(const filter & newfilter) {
	type = newfilter.type;
	highpass = newfilter.highpass;
	lowpass = newfilter.lowpass;
	units = newfilter.units;
}

filter::~filter() {
}

rapidjson::Value & filter::tojson(
		rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// optional values
	// type
	if (type.empty() == false) {
		rapidjson::Value typevalue;
		typevalue.SetString(rapidjson::StringRef(type.c_str()), allocator);
		json.AddMember(TYPE_KEY, typevalue, allocator);
	}

	// highpass
	if (std::isnan(highpass) != true) {
		json.AddMember(HIGHPASS_KEY, highpass, allocator);
	}

	// lowpass
	if (std::isnan(lowpass) != true) {
		json.AddMember(LOWPASS_KEY, lowpass, allocator);
	}

	// units
	if (units.empty() == false) {
		rapidjson::Value unitsvalue;
		unitsvalue.SetString(rapidjson::StringRef(units.c_str()), allocator);
		json.AddMember(UNITS_KEY, unitsvalue, allocator);
	}

	return (json);
}

std::vector<std::string> filter::geterrors() {
	// nothing to check
	return (std::vector<std::string>());
}

bool filter::isempty() {
	if (type.empty() == false) {
		return (false);
	}
	if (std::isnan(highpass) != true) {
		return (false);
	}
	if (std::isnan(lowpass) != true) {
		return (false);
	}
	if (units.empty() == false) {
		return (false);
	}
	return (true);
}
}  // namespace detectionformats
