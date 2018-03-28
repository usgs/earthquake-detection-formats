#include <associated.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define PHASE_KEY "Phase"
#define DISTANCE_KEY "Distance"
#define AZIMUTH_KEY "Azimuth"
#define RESIDUAL_KEY "Residual"
#define SIGMA_KEY "Sigma"

namespace detectionformats {
associated::associated() {
	phase = "";
	distance = std::numeric_limits<double>::quiet_NaN();
	azimuth = std::numeric_limits<double>::quiet_NaN();
	residual = std::numeric_limits<double>::quiet_NaN();
	sigma = std::numeric_limits<double>::quiet_NaN();
}

associated::associated(std::string newphase, double newdistance,
						double newazimuth, double newresidual,
						double newsigma) {
	phase = newphase;
	distance = newdistance;
	azimuth = newazimuth;
	residual = newresidual;
	sigma = newsigma;
}

associated::associated(rapidjson::Value &json) {
	// optional values
	// phase
	if ((json.HasMember(PHASE_KEY) == true)
			&& (json[PHASE_KEY].IsString() == true))
		phase = std::string(json[PHASE_KEY].GetString(),
							json[PHASE_KEY].GetStringLength());
	else
		phase = "";

	// distance
	if ((json.HasMember(DISTANCE_KEY) == true)
			&& (json[DISTANCE_KEY].IsNumber() == true)
			&& (json[DISTANCE_KEY].IsDouble() == true))
		distance = json[DISTANCE_KEY].GetDouble();
	else
		distance = std::numeric_limits<double>::quiet_NaN();

	// azimuth
	if ((json.HasMember(AZIMUTH_KEY) == true)
			&& (json[AZIMUTH_KEY].IsNumber() == true)
			&& (json[AZIMUTH_KEY].IsDouble() == true))
		azimuth = json[AZIMUTH_KEY].GetDouble();
	else
		azimuth = std::numeric_limits<double>::quiet_NaN();

	// residual
	if ((json.HasMember(RESIDUAL_KEY) == true)
			&& (json[RESIDUAL_KEY].IsNumber() == true)
			&& (json[RESIDUAL_KEY].IsDouble() == true))
		residual = json[RESIDUAL_KEY].GetDouble();
	else
		residual = std::numeric_limits<double>::quiet_NaN();

	// sigma
	if ((json.HasMember(SIGMA_KEY) == true)
			&& (json[SIGMA_KEY].IsNumber() == true)
			&& (json[SIGMA_KEY].IsDouble() == true))
		sigma = json[SIGMA_KEY].GetDouble();
	else
		sigma = std::numeric_limits<double>::quiet_NaN();
}

associated::associated(const associated & newassociated) {
	phase = newassociated.phase;
	distance = newassociated.distance;
	azimuth = newassociated.azimuth;
	residual = newassociated.residual;
	sigma = newassociated.sigma;
}

associated::~associated() {
}

rapidjson::Value & associated::tojson(
		rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// optional values
	// phase
	if (phase != "") {
		rapidjson::Value phasevalue;
		phasevalue.SetString(rapidjson::StringRef(phase.c_str()), allocator);
		json.AddMember(PHASE_KEY, phasevalue, allocator);
	}

	// distance
	if (std::isnan(distance) != true)
		json.AddMember(DISTANCE_KEY, distance, allocator);

	// azimuth
	if (std::isnan(azimuth) != true)
		json.AddMember(AZIMUTH_KEY, azimuth, allocator);

	// residual
	if (std::isnan(residual) != true)
		json.AddMember(RESIDUAL_KEY, residual, allocator);

	// sigma
	if (std::isnan(sigma) != true)
		json.AddMember(SIGMA_KEY, sigma, allocator);

	return (json);
}

std::vector<std::string> associated::geterrors() {
	std::vector<std::string> errorlist;

	// optional keys
	// phase
	if ((phase != "") && (detectionformats::IsStringAlpha(phase) == false)) {
		errorlist.push_back("Phase did not validate in associated object.");
	}

	// return the list of errors
	return (errorlist);
}

bool associated::isempty() {
	if (phase != "")
		return (false);
	if (std::isnan(distance) != true)
		return (false);
	if (std::isnan(azimuth) != true)
		return (false);
	if (std::isnan(residual) != true)
		return (false);
	if (std::isnan(sigma) != true)
		return (false);

	return (true);
}
}  // namespace detectionformats
