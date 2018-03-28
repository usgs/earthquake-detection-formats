#include <filter.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define HIGHPASS_KEY "HighPass"
#define LOWPASS_KEY "LowPass"

namespace detectionformats {
filter::filter() {
	highpass = std::numeric_limits<double>::quiet_NaN();
	lowpass = std::numeric_limits<double>::quiet_NaN();
}

filter::filter(double newhighpass, double newlowpass) {
	highpass = newhighpass;
	lowpass = newlowpass;
}

filter::filter(rapidjson::Value &json) {
	// optional values
	// highpass
	if ((json.HasMember(HIGHPASS_KEY) == true)
			&& (json[HIGHPASS_KEY].IsNumber() == true)
			&& (json[HIGHPASS_KEY].IsDouble() == true))
		highpass = json[HIGHPASS_KEY].GetDouble();
	else
		highpass = std::numeric_limits<double>::quiet_NaN();

	// lowpass
	if ((json.HasMember(LOWPASS_KEY) == true)
			&& (json[LOWPASS_KEY].IsNumber() == true)
			&& (json[LOWPASS_KEY].IsDouble() == true))
		lowpass = json[LOWPASS_KEY].GetDouble();
	else
		lowpass = std::numeric_limits<double>::quiet_NaN();
}

filter::filter(const filter & newfilter) {
	highpass = newfilter.highpass;
	lowpass = newfilter.lowpass;
}

filter::~filter() {
}

rapidjson::Value & filter::tojson(
		rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// optional values
	// highpass
	if (std::isnan(highpass) != true)
		json.AddMember(HIGHPASS_KEY, highpass, allocator);

	// lowpass
	if (std::isnan(lowpass) != true)
		json.AddMember(LOWPASS_KEY, lowpass, allocator);

	return (json);
}

std::vector<std::string> filter::geterrors() {
	// nothing to check
	return (std::vector<std::string>());
}

bool filter::isempty() {
	if (std::isnan(highpass) != true)
		return (false);
	if (std::isnan(lowpass) != true)
		return (false);

	return (true);
}
}  // namespace detectionformats
