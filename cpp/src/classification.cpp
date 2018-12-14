#include <classification.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define PHASE_KEY "Phase"
#define PHASEPROB_KEY "PhaseProbability"
#define DISTANCE_KEY "Distance"
#define DISTANCEPROB_KEY "DistanceProbability"
#define AZIMUTH_KEY "Azimuth"
#define AZIMUTHPROB_KEY "AzimuthProbability"
#define MAGNITUDE_KEY "Magnitude"
#define MAGNITUDETYPE_KEY "MagnitudeType"
#define MAGNITUDEPROB_KEY "MagnitudeProbability"
#define DEPTH_KEY "Depth"
#define DEPTHPROB_KEY "DepthProbability"
#define EVENTTYPE_KEY "EventType"
#define EVENTTYPEPROB_KEY "EventTypeProbability"
#define SOURCE_KEY "Source"

namespace detectionformats {
classification::classification() {
    phase = "";
    phaseprobability = std::numeric_limits<double>::quiet_NaN();
	distance = std::numeric_limits<double>::quiet_NaN();
    distanceprobability = std::numeric_limits<double>::quiet_NaN();
	azimuth = std::numeric_limits<double>::quiet_NaN();
    azimuthprobability = std::numeric_limits<double>::quiet_NaN();
	magnitude = std::numeric_limits<double>::quiet_NaN();
    magnitudetype = "";
    magnitudeprobability = std::numeric_limits<double>::quiet_NaN();
	depth = std::numeric_limits<double>::quiet_NaN();
    depthprobability = std::numeric_limits<double>::quiet_NaN();
    eventtype = detectionformats::eventtype();
    eventtypeprobability = std::numeric_limits<double>::quiet_NaN();
    classification::source = detectionformats::source();
}

classification::classification(std::string newphase, double newphaseprob,
            double newdistance, double newdistanceprob, double newazimuth,
			double newazimuthprob, double newmagnitude, std::string newmagtype,
            double newmagprob, double newdepth, double newdepthprob,
            std::string neweventtype, std::string neweventtypecertainty,
            double neweventtypeprob, std::string newagencyid,
            std::string newauthor) {
	phase = newphase;
    phaseprobability = newphaseprob;
	distance = newdistance;
    distanceprobability = newdistanceprob;
	azimuth = newazimuth;
    azimuthprobability = newazimuthprob;
	magnitude = newmagnitude;
    magnitudetype = newmagtype;
    magnitudeprobability = newmagprob;
	depth = newdepth;
    depthprobability = newdepthprob;
    eventtype = detectionformats::eventtype(neweventtype,
        neweventtypecertainty);
    eventtypeprobability = neweventtypeprob;
    classification::source = detectionformats::source(newagencyid, newauthor);
}

classification::classification(std::string newphase, double newphaseprob,
            double newdistance, double newdistanceprob, double newazimuth,
			double newazimuthprob, double newmagnitude, std::string newmagtype,
            double newmagprob, double newdepth, double newdepthprob,
            detectionformats::eventtype neweventtype, double neweventtypeprob,
            detectionformats::source newsource) {
	phase = newphase;
    phaseprobability = newphaseprob;
	distance = newdistance;
    distanceprobability = newdistanceprob;
	azimuth = newazimuth;
    azimuthprobability = newazimuthprob;
	magnitude = newmagnitude;
    magnitudetype = newmagtype;
    magnitudeprobability = newmagprob;
	depth = newdepth;
    depthprobability = newdepthprob;
    eventtype = neweventtype;
    eventtypeprobability = neweventtypeprob;
    classification::source = newsource;
}

classification::classification(rapidjson::Value &json) {
	// optional values
	// phase
	if ((json.HasMember(PHASE_KEY) == true)
			&& (json[PHASE_KEY].IsString() == true)) {
		phase = std::string(json[PHASE_KEY].GetString(),
							json[PHASE_KEY].GetStringLength());
    } else {
		phase = "";
    }

    // phase probability
	if ((json.HasMember(PHASEPROB_KEY) == true)
			&& (json[PHASEPROB_KEY].IsNumber() == true)
			&& (json[PHASEPROB_KEY].IsDouble() == true)) {
		phaseprobability = json[PHASEPROB_KEY].GetDouble();
    } else {
		phaseprobability = std::numeric_limits<double>::quiet_NaN();
    }

	// distance
	if ((json.HasMember(DISTANCE_KEY) == true)
			&& (json[DISTANCE_KEY].IsNumber() == true)
			&& (json[DISTANCE_KEY].IsDouble() == true)) {
		distance = json[DISTANCE_KEY].GetDouble();
	} else {
		distance = std::numeric_limits<double>::quiet_NaN();
	}

    // distance probability
	if ((json.HasMember(DISTANCEPROB_KEY) == true)
			&& (json[DISTANCEPROB_KEY].IsNumber() == true)
			&& (json[DISTANCEPROB_KEY].IsDouble() == true)) {
		distanceprobability = json[DISTANCEPROB_KEY].GetDouble();
    } else {
		distanceprobability = std::numeric_limits<double>::quiet_NaN();
    }

	// azimuth
	if ((json.HasMember(AZIMUTH_KEY) == true)
			&& (json[AZIMUTH_KEY].IsNumber() == true)
			&& (json[AZIMUTH_KEY].IsDouble() == true)) {
		azimuth = json[AZIMUTH_KEY].GetDouble();
	} else {
		azimuth = std::numeric_limits<double>::quiet_NaN();
	}

    // azimuth probability
	if ((json.HasMember(AZIMUTHPROB_KEY) == true)
			&& (json[AZIMUTHPROB_KEY].IsNumber() == true)
			&& (json[AZIMUTHPROB_KEY].IsDouble() == true)) {
		azimuthprobability = json[AZIMUTHPROB_KEY].GetDouble();
    } else {
		azimuthprobability = std::numeric_limits<double>::quiet_NaN();
    }

	// magnitude
	if ((json.HasMember(MAGNITUDE_KEY) == true)
			&& (json[MAGNITUDE_KEY].IsNumber() == true)
			&& (json[MAGNITUDE_KEY].IsDouble() == true)) {
		magnitude = json[MAGNITUDE_KEY].GetDouble();
	} else {
		magnitude = std::numeric_limits<double>::quiet_NaN();
	}

	// magnitude type
	if ((json.HasMember(MAGNITUDETYPE_KEY) == true)
			&& (json[MAGNITUDETYPE_KEY].IsString() == true)) {
		magnitudetype = std::string(json[MAGNITUDETYPE_KEY].GetString(),
							json[MAGNITUDETYPE_KEY].GetStringLength());
    } else {
		magnitudetype = "";
    }

    // magnitude probability
	if ((json.HasMember(MAGNITUDEPROB_KEY) == true)
			&& (json[MAGNITUDEPROB_KEY].IsNumber() == true)
			&& (json[MAGNITUDEPROB_KEY].IsDouble() == true)) {
		magnitudeprobability = json[MAGNITUDEPROB_KEY].GetDouble();
    } else {
		magnitudeprobability = std::numeric_limits<double>::quiet_NaN();
    }

	// depth
	if ((json.HasMember(DEPTH_KEY) == true)
			&& (json[DEPTH_KEY].IsNumber() == true)
			&& (json[DEPTH_KEY].IsDouble() == true)) {
		depth = json[DEPTH_KEY].GetDouble();
	} else {
		depth = std::numeric_limits<double>::quiet_NaN();
	}

	// depth probability
	if ((json.HasMember(DEPTHPROB_KEY) == true)
			&& (json[DEPTHPROB_KEY].IsNumber() == true)
			&& (json[DEPTHPROB_KEY].IsDouble() == true)) {
		depthprobability = json[DEPTHPROB_KEY].GetDouble();
    } else {
		depthprobability = std::numeric_limits<double>::quiet_NaN();
    }

	// eventtype
	if ((json.HasMember(EVENTTYPE_KEY) == true)
			&& (json[EVENTTYPE_KEY].IsObject() == true)) {
		rapidjson::Value & eventtypevalue = json[EVENTTYPE_KEY];
		eventtype = detectionformats::eventtype(eventtypevalue);
	} else {
		eventtype = detectionformats::eventtype();
	}

	// event type probability
	if ((json.HasMember(EVENTTYPEPROB_KEY) == true)
			&& (json[EVENTTYPEPROB_KEY].IsNumber() == true)
			&& (json[EVENTTYPEPROB_KEY].IsDouble() == true))
		eventtypeprobability = json[EVENTTYPEPROB_KEY].GetDouble();
	else
		eventtypeprobability = std::numeric_limits<double>::quiet_NaN();

	// source
	if ((json.HasMember(SOURCE_KEY) == true)
			&& (json[SOURCE_KEY].IsObject() == true)) {
		rapidjson::Value & sourcevalue = json[SOURCE_KEY];
		source = detectionformats::source(sourcevalue);
	} else {
		source = detectionformats::source();
	}
}

classification::classification(const classification & newclassification) {
    phase = newclassification.phase;
    phaseprobability = newclassification.phaseprobability;
	distance = newclassification.distance;
    distanceprobability = newclassification.distanceprobability;
	azimuth = newclassification.azimuth;
    azimuthprobability = newclassification.azimuthprobability;
	magnitude = newclassification.magnitude;
    magnitudetype = newclassification.magnitudetype;
    magnitudeprobability = newclassification.magnitudeprobability;
	depth = newclassification.depth;
    depthprobability = newclassification.depthprobability;
    eventtype = newclassification.eventtype;
    eventtypeprobability = newclassification.eventtypeprobability;
    classification::source = newclassification.source;
}

classification::~classification() {
}

rapidjson::Value & classification::tojson(
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

	// phaseprobability
	if (std::isnan(phaseprobability) != true) {
		json.AddMember(PHASEPROB_KEY, phaseprobability, allocator);
	}

	// distance
	if (std::isnan(distance) != true) {
		json.AddMember(DISTANCE_KEY, distance, allocator);
	}

	// distanceprobability
	if (std::isnan(distanceprobability) != true) {
		json.AddMember(DISTANCEPROB_KEY, distanceprobability, allocator);
	}

	// azimuth
	if (std::isnan(azimuth) != true) {
		json.AddMember(AZIMUTH_KEY, azimuth, allocator);
	}

	// azimuthprobability
	if (std::isnan(azimuthprobability) != true) {
		json.AddMember(AZIMUTHPROB_KEY, azimuthprobability, allocator);
	}

	// magnitude
	if (std::isnan(magnitude) != true) {
		json.AddMember(MAGNITUDE_KEY, magnitude, allocator);
	}

	// magnitude type
	if (magnitudetype != "") {
		rapidjson::Value magnitudetypevalue;
		magnitudetypevalue.SetString(rapidjson::StringRef(magnitudetype.c_str()),
			allocator);
		json.AddMember(MAGNITUDETYPE_KEY, magnitudetypevalue, allocator);
	}

	// magnitudeprobability
	if (std::isnan(magnitudeprobability) != true) {
		json.AddMember(MAGNITUDEPROB_KEY, magnitudeprobability, allocator);
	}

	// depth
	if (std::isnan(depth) != true) {
		json.AddMember(DEPTH_KEY, depth, allocator);
	}

	// depthprobability
	if (std::isnan(depthprobability) != true) {
		json.AddMember(DEPTHPROB_KEY, depthprobability, allocator);
	}

	// eventtype
	if (eventtype.isempty() == false) {
		rapidjson::Value eventtypevalue(rapidjson::kObjectType);
		eventtype.tojson(eventtypevalue, allocator);
		json.AddMember(EVENTTYPE_KEY, eventtypevalue, allocator);
	}

	// eventtypeprobability
	if (std::isnan(eventtypeprobability) != true) {
		json.AddMember(EVENTTYPEPROB_KEY, eventtypeprobability, allocator);
	}

	// source
	if (source.isempty() == false) {
		rapidjson::Value sourcevalue(rapidjson::kObjectType);
		source.tojson(sourcevalue, allocator);
		json.AddMember(SOURCE_KEY, sourcevalue, allocator);
	}

	return (json);
}

std::vector<std::string> classification::geterrors() {
	std::vector<std::string> errorlist;

	// optional keys
	// phase
	if ((phase != "") && (detectionformats::IsStringAlpha(phase) == false)) {
		errorlist.push_back("Invalid phase in classification object.");
	}

	// distance
	if (std::isnan(distance) == false) {
		if ((distance < 0) || (distance >= 180)) {
			errorlist.push_back("Invalid distance in classification object.");
		}
	}

	// azimuth
	if (std::isnan(azimuth) == false) {
		if ((azimuth < 0) || (azimuth >= 360)) {
			errorlist.push_back("Invalid azimuth in classification object.");
		}
	}

	// magnitude
	if (std::isnan(magnitude) == false) {
		if ((magnitude < -2) || (magnitude > 10)) {
			errorlist.push_back("Invalid magnitude in classification object.");
		}
	}

	// depth
	if (std::isnan(depth) == false) {
		if ((depth < -100) || (depth > 1500)) {
			errorlist.push_back("Invalid depth in classification object.");
		}
	}

	// eventtype
	if (eventtype.isempty() == false) {
		if (eventtype.isvalid() != true) {
			std::vector<std::string> eventtypeErrors = eventtype.geterrors();

			std::string errorString =
					"EventType object did not validate in classification object:";

			for (int i = 0; i < eventtypeErrors.size(); i++) {
				errorString += " " + eventtypeErrors[i];
			}

			// bad eventtype
			errorlist.push_back(errorString);
		}
	}

	// source
	if (source.isempty() == false) {
		if (source.isvalid() != true) {
			std::vector<std::string> sourceErrors = source.geterrors();

			std::string errorString =
					"Source object did not validate in classification object:";

			for (int i = 0; i < sourceErrors.size(); i++) {
				errorString += " " + sourceErrors[i];
			}

			// bad source
			errorlist.push_back(errorString);
		}
	}
	// return the list of errors
	return (errorlist);
}

bool classification::isempty() {
	if (phase != "") {
		return (false);
	}
	if (std::isnan(phaseprobability) != true) {
		return (false);
	}
	if (std::isnan(distance) != true) {
		return (false);
	}
	if (std::isnan(distanceprobability) != true) {
		return (false);
	}
	if (std::isnan(azimuth) != true) {
		return (false);
	}
	if (std::isnan(azimuthprobability) != true) {
		return (false);
	}
	if (std::isnan(magnitude) != true) {
		return (false);
	}
	if (magnitudetype != "") {
		return (false);
	}
	if (std::isnan(magnitudeprobability) != true) {
		return (false);
	}
	if (std::isnan(depth) != true) {
		return (false);
	}
	if (std::isnan(depthprobability) != true) {
		return (false);
	}
	if (eventtype.isempty() == false) {
		return(false);
	}
	if (std::isnan(eventtypeprobability) != true) {
		return (false);
	}
	if (source.isempty() == false) {
		return(false);
	}

	return (true);
}
}  // namespace detectionformats
