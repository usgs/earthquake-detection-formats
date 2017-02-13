#include "beam.h"

#include <limits>

// JSON Keys
#define TYPE_KEY "Type"
#define ID_KEY "ID"
#define SITE_KEY "Site"
#define SOURCE_KEY "Source"
#define STARTTIME_KEY "StartTime"
#define ENDTIME_KEY "EndTime"
#define BACKAZIMUTH_KEY "BackAzimuth"
#define SLOWNESS_KEY "Slowness"
#define POWERRATIO_KEY "PowerRatio"
#define BACKAZIMUTHERROR_KEY "BackAzimuthError"
#define SLOWNESSERROR_KEY "SlownessError"
#define POWERRATIOERROR_KEY "PowerRatioError"
#define ASSOCIATIONINFO_KEY "AssociationInfo"

namespace detectionformats {
beam::beam() {
	type = BEAM_TYPE;
	id = "";
	site = detectionformats::site();
	source = detectionformats::source();
	starttime = std::numeric_limits<double>::quiet_NaN();
	endtime = std::numeric_limits<double>::quiet_NaN();
	backazimuth = std::numeric_limits<double>::quiet_NaN();
	backazimutherror = std::numeric_limits<double>::quiet_NaN();
	slowness = std::numeric_limits<double>::quiet_NaN();
	slownesserror = std::numeric_limits<double>::quiet_NaN();
	powerratio = std::numeric_limits<double>::quiet_NaN();
	powerratioerror = std::numeric_limits<double>::quiet_NaN();
	associationinfo = detectionformats::associated();
}

beam::beam(std::string newid, std::string newsiteid, std::string newstation,
		std::string newchannel, std::string newnetwork, std::string newlocation,
		std::string newagencyid, std::string newauthor, double newstarttime,
		double newendtime, double newbackazimuth, double newbackazimutherror,
		double newslowness, double newslownesserror, double newpowerratio,
		double newpowerratioerror) {
	type = BEAM_TYPE;
	id = newid;
	site = detectionformats::site(newsiteid, newstation, newchannel, newnetwork,
			newlocation);
	source = detectionformats::source(newagencyid, newauthor);
	starttime = newstarttime;
	endtime = newendtime;
	backazimuth = newbackazimuth;
	backazimutherror = newbackazimutherror;
	slowness = newslowness;
	slownesserror = newslownesserror;
	powerratio = newpowerratio;
	powerratioerror = newpowerratioerror;
	associationinfo = detectionformats::associated();
}

beam::beam(std::string newid, std::string newsiteid, std::string newstation,
		std::string newchannel, std::string newnetwork, std::string newlocation,
		std::string newagencyid, std::string newauthor, double newstarttime,
		double newendtime, double newbackazimuth, double newbackazimutherror,
		double newslowness, double newslownesserror, double newpowerratio,
		double newpowerratioerror, std::string newassociatedphase,
		double newassociateddistance, double newassociatedazimuth,
		double newassociatedresidual, double newassociatedsigma) {
	type = BEAM_TYPE;
	id = newid;
	site = detectionformats::site(newsiteid, newstation, newchannel, newnetwork,
			newlocation);
	source = detectionformats::source(newagencyid, newauthor);
	starttime = newstarttime;
	endtime = newendtime;
	backazimuth = newbackazimuth;
	backazimutherror = newbackazimutherror;
	slowness = newslowness;
	slownesserror = newslownesserror;
	powerratio = newpowerratio;
	powerratioerror = newpowerratioerror;
	associationinfo = detectionformats::associated(newassociatedphase,
			newassociateddistance, newassociatedazimuth, newassociatedresidual,
			newassociatedsigma);
}

beam::beam(std::string newid, detectionformats::site newsite,
		detectionformats::source newsource, double newstarttime,
		double newendtime, double newbackazimuth, double newbackazimutherror,
		double newslowness, double newslownesserror, double newpowerratio,
		double newpowerratioerror) {
	type = BEAM_TYPE;
	id = newid;
	site = newsite;
	source = newsource;
	starttime = newstarttime;
	endtime = newendtime;
	backazimuth = newbackazimuth;
	backazimutherror = newbackazimutherror;
	slowness = newslowness;
	slownesserror = newslownesserror;
	powerratio = newpowerratio;
	powerratioerror = newpowerratioerror;
	associationinfo = detectionformats::associated();
}

beam::beam(std::string newid, detectionformats::site newsite,
		detectionformats::source newsource, double newstarttime,
		double newendtime, double newbackazimuth, double newbackazimutherror,
		double newslowness, double newslownesserror, double newpowerratio,
		double newpowerratioerror, detectionformats::associated newassociated) {
	type = BEAM_TYPE;
	id = newid;
	site = newsite;
	source = newsource;
	starttime = newstarttime;
	endtime = newendtime;
	backazimuth = newbackazimuth;
	backazimutherror = newbackazimutherror;
	slowness = newslowness;
	slownesserror = newslownesserror;
	powerratio = newpowerratio;
	powerratioerror = newpowerratioerror;
	associationinfo = newassociated;
}

beam::beam(rapidjson::Value &json) {
	// required values
	// type
	if ((json.HasMember(TYPE_KEY) == true)
			&& (json[TYPE_KEY].IsString() == true))
		type = std::string(json[TYPE_KEY].GetString(),
				json[TYPE_KEY].GetStringLength());
	else
		type = "";

	// id
	if ((json.HasMember(ID_KEY) == true) && (json[ID_KEY].IsString() == true))
		id = std::string(json[ID_KEY].GetString(),
				json[ID_KEY].GetStringLength());
	else
		id = "";

	// site
	if ((json.HasMember(SITE_KEY) == true)
			&& (json[SITE_KEY].IsObject() == true)) {
		rapidjson::Value & sitevalue = json["Site"];
		site = detectionformats::site(sitevalue);
	} else
		site = detectionformats::site();

	// source
	if ((json.HasMember(SOURCE_KEY) == true)
			&& (json[SOURCE_KEY].IsObject() == true)) {
		rapidjson::Value & sourcevalue = json[SOURCE_KEY];
		source = detectionformats::source(sourcevalue);
	} else
		source = detectionformats::source();

	// starttime
	if ((json.HasMember(STARTTIME_KEY) == true)
			&& (json[STARTTIME_KEY].IsString() == true))
		starttime = detectionformats::ConvertISO8601ToEpochTime(
				std::string(json[STARTTIME_KEY].GetString(),
						json[STARTTIME_KEY].GetStringLength()));
	else
		starttime = std::numeric_limits<double>::quiet_NaN();

	// endtime
	if ((json.HasMember(ENDTIME_KEY) == true)
			&& (json[ENDTIME_KEY].IsString() == true))
		endtime = detectionformats::ConvertISO8601ToEpochTime(
				std::string(json[ENDTIME_KEY].GetString(),
						json[ENDTIME_KEY].GetStringLength()));
	else
		endtime = std::numeric_limits<double>::quiet_NaN();

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

	// slowness
	if ((json.HasMember(POWERRATIO_KEY) == true)
			&& (json[POWERRATIO_KEY].IsNumber() == true)
			&& (json[POWERRATIO_KEY].IsDouble() == true))
		powerratio = json[POWERRATIO_KEY].GetDouble();
	else
		powerratio = std::numeric_limits<double>::quiet_NaN();

	// optional values
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

	// associated
	if ((json.HasMember(ASSOCIATIONINFO_KEY) == true)
			&& (json[ASSOCIATIONINFO_KEY].IsObject() == true)) {
		rapidjson::Value & associatedvalue = json[ASSOCIATIONINFO_KEY];
		associationinfo = detectionformats::associated(associatedvalue);
	} else
		associationinfo = detectionformats::associated();
}

beam::beam(const beam &newbeam) {
	type = BEAM_TYPE;
	id = newbeam.id;
	site = newbeam.site;
	source = newbeam.source;
	starttime = newbeam.starttime;
	endtime = newbeam.endtime;
	backazimuth = newbeam.backazimuth;
	backazimutherror = newbeam.backazimutherror;
	slowness = newbeam.slowness;
	slownesserror = newbeam.slownesserror;
	powerratio = newbeam.powerratio;
	powerratioerror = newbeam.powerratioerror;
	associationinfo = newbeam.associationinfo;
}

beam::~beam() {
}

rapidjson::Value & beam::tojson(rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// required values
	// type
	rapidjson::Value typevalue;
	typevalue.SetString(rapidjson::StringRef(type.c_str()), allocator);
	json.AddMember(TYPE_KEY, typevalue, allocator);

	// id
	if (id != "") {
		rapidjson::Value idvalue;
		idvalue.SetString(rapidjson::StringRef(id.c_str()), allocator);
		json.AddMember(ID_KEY, idvalue, allocator);
	}

	// site
	rapidjson::Value sitevalue(rapidjson::kObjectType);
	site.tojson(sitevalue, allocator);
	json.AddMember(SITE_KEY, sitevalue, allocator);

	// source
	rapidjson::Value sourcevalue(rapidjson::kObjectType);
	source.tojson(sourcevalue, allocator);
	json.AddMember(SOURCE_KEY, sourcevalue, allocator);

	// starttime
	if (std::isnan(starttime) != true) {
		std::string timestring = detectionformats::ConvertEpochTimeToISO8601(
				starttime);
		rapidjson::Value timevalue;
		timevalue.SetString(rapidjson::StringRef(timestring.c_str()),
				allocator);
		json.AddMember(STARTTIME_KEY, timevalue, allocator);
	}

	// endtime
	if (std::isnan(endtime) != true) {
		std::string timestring = detectionformats::ConvertEpochTimeToISO8601(
				endtime);
		rapidjson::Value timevalue;
		timevalue.SetString(rapidjson::StringRef(timestring.c_str()),
				allocator);
		json.AddMember(ENDTIME_KEY, timevalue, allocator);
	}

	// backazimuth
	if (std::isnan(backazimuth) != true)
		json.AddMember(BACKAZIMUTH_KEY, backazimuth, allocator);

	// slowness
	if (std::isnan(slowness) != true)
		json.AddMember(SLOWNESS_KEY, slowness, allocator);

	// powerratio
	if (std::isnan(powerratio) != true)
		json.AddMember(POWERRATIO_KEY, powerratio, allocator);

	// optional values
	// backazimutherror
	if (std::isnan(backazimutherror) != true)
		json.AddMember(BACKAZIMUTHERROR_KEY, backazimutherror, allocator);

	// slownesserror
	if (std::isnan(slownesserror) != true)
		json.AddMember(SLOWNESSERROR_KEY, slownesserror, allocator);

	// powerratioerror
	if (std::isnan(powerratioerror) != true)
		json.AddMember(POWERRATIOERROR_KEY, powerratioerror, allocator);

	// associated
	if (associationinfo.isempty() == false) {
		rapidjson::Value associatedvalue(rapidjson::kObjectType);
		associationinfo.tojson(associatedvalue, allocator);
		json.AddMember(ASSOCIATIONINFO_KEY, associatedvalue, allocator);
	}

	return (json);
}

std::vector<std::string> beam::geterrors() {
	std::vector < std::string > errorlist;

	// check required data
	// Type
	if (type != BEAM_TYPE) {
		// wrong type
		errorlist.push_back("Non-beam type in beam class.");
	}

	// id
	if (id == "") {
		// empty id
		errorlist.push_back("Empty ID in beam class.");
	}

	// site
	if (site.isvalid() != true) {
		// site not found
		errorlist.push_back("Site object did not validate in beam class.");
	}

	// source
	if (source.isvalid() != true) {
		// bad source
		errorlist.push_back("Source object did not validate in beam class.");
	}

	// starttime
	if (std::isnan(starttime) == true) {
		errorlist.push_back("Start Time is missing in beam class.");
	} else {
		try {
			if (detectionformats::IsStringISO8601(
					detectionformats::ConvertEpochTimeToISO8601(starttime))
					== false) {
				errorlist.push_back("Start Time did not validate in beam class.");
			}
		} catch (const std::exception & e) {
			errorlist.push_back(std::string(e.what()));
		}
	}

	// endtime
	if (std::isnan(endtime) == true) {
		errorlist.push_back("End Time is missing in beam class.");
	} else {
		try {
			if (detectionformats::IsStringISO8601(
					detectionformats::ConvertEpochTimeToISO8601(endtime))
					== false) {
				errorlist.push_back("End Time did not validate in beam class.");
			}
		} catch (const std::exception & e) {
			errorlist.push_back(std::string(e.what()));
		}
	}

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

	// powerratio
	if (std::isnan(powerratio) == true) {
		// powerratio not found
		errorlist.push_back("No PowerRatio in beam class.");
	}
	if (powerratio < 0) {
		errorlist.push_back("Invalid PowerRatio in beam class.");
	}

	// optional data
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

	// associated
	if (associationinfo.isempty() == false) {
		if (associationinfo.isvalid() != true) {
			// site not found
			errorlist.push_back(
					"AssociationInfo object did not validate in beam class.");
		}
	}

	// return the list of errors
	return (errorlist);
}

}
