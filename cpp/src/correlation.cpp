#include <correlation.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define TYPE_KEY "Type"
#define ID_KEY "ID"
#define SITE_KEY "Site"
#define SOURCE_KEY "Source"
#define PHASE_KEY "Phase"
#define TIME_KEY "Time"
#define CORRELATION_KEY "Correlation"
#define HYPOCENTER_KEY "Hypocenter"
#define EVENTTYPE_KEY "EventType"
#define MAGNITUDE_KEY "Magnitude"
#define SNR_KEY "SNR"
#define ZSCORE_KEY "ZScore"
#define DETECTIONTHRESHOLD_KEY "DetectionThreshold"
#define THRESHOLDTYPE_KEY "ThresholdType"
#define ASSOCIATIONINFO_KEY "AssociationInfo"

namespace detectionformats {
correlation::correlation() {
	type = CORRELATION_TYPE;
	id = "";
	site = detectionformats::site();
	source = detectionformats::source();
	phase = "";
	time = std::numeric_limits<double>::quiet_NaN();
	correlationvalue = std::numeric_limits<double>::quiet_NaN();
	hypocenter = detectionformats::hypocenter();
	eventtype = detectionformats::eventtype();
	magnitude = std::numeric_limits<double>::quiet_NaN();
	snr = std::numeric_limits<double>::quiet_NaN();
	zscore = std::numeric_limits<double>::quiet_NaN();
	detectionthreshold = std::numeric_limits<double>::quiet_NaN();
	thresholdtype = "";
	associationinfo = detectionformats::associated();
}

correlation::correlation(std::string newid, std::string newstation,
							std::string newchannel, std::string newnetwork,
							std::string newlocation, std::string newagencyid,
							std::string newauthor, std::string newphase,
							double newtime, double newcorrelation,
							double newlatitude, double newlongitude,
							double neworigintime, double newdepth,
							double newlatitudeerror, double newlongitudeerror,
							double newtimeerror, double newdeptherror,
							std::string neweventtype,
							std::string neweventtypecertainty,
							double newmagnitude,
							double newsnr, double newzscore,
							double newdetectionthreshold,
							std::string newthresholdtype) {
	type = CORRELATION_TYPE;
	id = newid;
	site = detectionformats::site(newstation, newchannel, newnetwork,
									newlocation);
	source = detectionformats::source(newagencyid, newauthor);
	phase = newphase;
	time = newtime;
	correlationvalue = newcorrelation;
	hypocenter = detectionformats::hypocenter(newlatitude, newlongitude,
												neworigintime, newdepth,
												newlatitudeerror,
												newlongitudeerror, newtimeerror,
												newdeptherror);
	eventtype = detectionformats::eventtype(neweventtype, neweventtypecertainty);
	magnitude = newmagnitude;
	snr = newsnr;
	zscore = newzscore;
	detectionthreshold = newdetectionthreshold;
	thresholdtype = newthresholdtype;
	associationinfo = detectionformats::associated();
}

correlation::correlation(std::string newid, std::string newstation,
							std::string newchannel, std::string newnetwork,
							std::string newlocation, std::string newagencyid,
							std::string newauthor, std::string newphase,
							double newtime, double newcorrelation,
							double newlatitude, double newlongitude,
							double neworigintime, double newdepth,
							double newlatitudeerror, double newlongitudeerror,
							double newtimeerror, double newdeptherror,
							std::string neweventtype,
							std::string neweventtypecertainty,
							double newmagnitude,
							double newsnr, double newzscore,
							double newdetectionthreshold,
							std::string newthresholdtype,
							std::string newassociatedphase,
							double newassociateddistance,
							double newassociatedazimuth,
							double newassociatedresidual,
							double newassociatedsigma) {
	type = CORRELATION_TYPE;
	id = newid;
	site = detectionformats::site(newstation, newchannel, newnetwork,
									newlocation);
	source = detectionformats::source(newagencyid, newauthor);
	phase = newphase;
	time = newtime;
	correlationvalue = newcorrelation;
	hypocenter = detectionformats::hypocenter(newlatitude, newlongitude,
												neworigintime, newdepth,
												newlatitudeerror,
												newlongitudeerror, newtimeerror,
												newdeptherror);
	eventtype = detectionformats::eventtype(neweventtype, neweventtypecertainty);
	magnitude = newmagnitude;
	snr = newsnr;
	zscore = newzscore;
	detectionthreshold = newdetectionthreshold;
	thresholdtype = newthresholdtype;
	associationinfo = detectionformats::associated(newassociatedphase,
													newassociateddistance,
													newassociatedazimuth,
													newassociatedresidual,
													newassociatedsigma);
}

correlation::correlation(std::string newid, detectionformats::site newsite,
							detectionformats::source newsource,
							std::string newphase, double newtime,
							double newcorrelation,
							detectionformats::hypocenter newhypocenter,
							detectionformats::eventtype neweventtype,
							double newmagnitude, double newsnr, double newzscore,
							double newdetectionthreshold,
							std::string newthresholdtype) {
	type = CORRELATION_TYPE;
	id = newid;
	site = newsite;
	source = newsource;
	phase = newphase;
	time = newtime;
	correlationvalue = newcorrelation;
	hypocenter = newhypocenter;
	eventtype = neweventtype;
	magnitude = newmagnitude;
	snr = newsnr;
	zscore = newzscore;
	detectionthreshold = newdetectionthreshold;
	thresholdtype = newthresholdtype;
	associationinfo = detectionformats::associated();
}

correlation::correlation(std::string newid, detectionformats::site newsite,
							detectionformats::source newsource,
							std::string newphase, double newtime,
							double newcorrelation,
							detectionformats::hypocenter newhypocenter,
							detectionformats::eventtype neweventtype,
							double newmagnitude, double newsnr, double newzscore,
							double newdetectionthreshold,
							std::string newthresholdtype,
							detectionformats::associated newassociated) {
	type = CORRELATION_TYPE;
	id = newid;
	site = newsite;
	source = newsource;
	phase = newphase;
	time = newtime;
	correlationvalue = newcorrelation;
	hypocenter = newhypocenter;
	eventtype = neweventtype;
	magnitude = newmagnitude;
	snr = newsnr;
	zscore = newzscore;
	detectionthreshold = newdetectionthreshold;
	thresholdtype = newthresholdtype;
	associationinfo = newassociated;
}

correlation::correlation(rapidjson::Value &json) {
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

	// phase
	if ((json.HasMember(PHASE_KEY) == true)
			&& (json[PHASE_KEY].IsString() == true)) {
		phase = std::string(json[PHASE_KEY].GetString(),
							json[PHASE_KEY].GetStringLength());
	} else {
		phase = "";
	}

	// time
	if ((json.HasMember(TIME_KEY) == true)
			&& (json[TIME_KEY].IsString() == true)) {
		time = detectionformats::ConvertISO8601ToEpochTime(
				std::string(json[TIME_KEY].GetString(),
							json[TIME_KEY].GetStringLength()));
	} else {
		time = std::numeric_limits<double>::quiet_NaN();
	}

	// correlation
	if ((json.HasMember(CORRELATION_KEY) == true)
			&& (json[CORRELATION_KEY].IsNumber() == true)
			&& (json[CORRELATION_KEY].IsDouble() == true)) {
		correlationvalue = json[CORRELATION_KEY].GetDouble();
	} else {
		correlationvalue = std::numeric_limits<double>::quiet_NaN();
	}

	// hypocenter
	if ((json.HasMember(HYPOCENTER_KEY) == true)
			&& (json[HYPOCENTER_KEY].IsObject() == true)) {
		rapidjson::Value & hypocentervalue = json[HYPOCENTER_KEY];
		hypocenter = detectionformats::hypocenter(hypocentervalue);
	} else {
		hypocenter = detectionformats::hypocenter();
	}

	// optional values
	// eventtype
	if ((json.HasMember(EVENTTYPE_KEY) == true)
			&& (json[EVENTTYPE_KEY].IsObject() == true)) {
		rapidjson::Value & eventtypevalue = json[EVENTTYPE_KEY];
		eventtype = detectionformats::eventtype(eventtypevalue);
	} else {
		eventtype = detectionformats::eventtype();
	}

	// magnitude
	if ((json.HasMember(MAGNITUDE_KEY) == true)
			&& (json[MAGNITUDE_KEY].IsNumber() == true)
			&& (json[MAGNITUDE_KEY].IsDouble() == true)) {
		magnitude = json[MAGNITUDE_KEY].GetDouble();
	} else {
		magnitude = std::numeric_limits<double>::quiet_NaN();
	}

	// snr
	if ((json.HasMember(SNR_KEY) == true) && (json[SNR_KEY].IsNumber() == true)
			&& (json[SNR_KEY].IsDouble() == true)) {
		snr = json[SNR_KEY].GetDouble();
	} else {
		snr = std::numeric_limits<double>::quiet_NaN();
	}

	// zscore
	if ((json.HasMember(ZSCORE_KEY) == true)
			&& (json[ZSCORE_KEY].IsNumber() == true)
			&& (json[ZSCORE_KEY].IsDouble() == true)) {
		zscore = json[ZSCORE_KEY].GetDouble();
	} else {
		zscore = std::numeric_limits<double>::quiet_NaN();
	}

	// detectionthreshold
	if ((json.HasMember(DETECTIONTHRESHOLD_KEY) == true)
			&& (json[DETECTIONTHRESHOLD_KEY].IsNumber() == true)
			&& (json[DETECTIONTHRESHOLD_KEY].IsDouble() == true)) {
		detectionthreshold = json[DETECTIONTHRESHOLD_KEY].GetDouble();
	} else {
		detectionthreshold = std::numeric_limits<double>::quiet_NaN();
	}

	// thresholdtype
	if ((json.HasMember(THRESHOLDTYPE_KEY) == true)
			&& (json[THRESHOLDTYPE_KEY].IsString() == true)) {
		thresholdtype = std::string(json[THRESHOLDTYPE_KEY].GetString(),
									json[THRESHOLDTYPE_KEY].GetStringLength());
	} else {
		thresholdtype = "";
	}

	// associated
	if ((json.HasMember(ASSOCIATIONINFO_KEY) == true)
			&& (json[ASSOCIATIONINFO_KEY].IsObject() == true)) {
		rapidjson::Value & associatedvalue = json[ASSOCIATIONINFO_KEY];
		associationinfo = detectionformats::associated(associatedvalue);
	} else {
		associationinfo = detectionformats::associated();
	}
}

correlation::correlation(const correlation &newcorrelation) {
	type = CORRELATION_TYPE;
	id = newcorrelation.id;
	site = newcorrelation.site;
	source = newcorrelation.source;
	phase = newcorrelation.phase;
	time = newcorrelation.time;
	correlationvalue = newcorrelation.correlationvalue;
	hypocenter = newcorrelation.hypocenter;
	eventtype = newcorrelation.eventtype;
	magnitude = newcorrelation.magnitude;
	snr = newcorrelation.snr;
	zscore = newcorrelation.zscore;
	detectionthreshold = newcorrelation.detectionthreshold;
	thresholdtype = newcorrelation.thresholdtype;
	associationinfo = newcorrelation.associationinfo;
}

correlation::~correlation() {
}

rapidjson::Value & correlation::tojson(
		rapidjson::Value &json,
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

	// phase
	if (phase != "") {
		rapidjson::Value phasevalue;
		phasevalue.SetString(rapidjson::StringRef(phase.c_str()), allocator);
		json.AddMember(PHASE_KEY, phasevalue, allocator);
	}

	// time
	if (std::isnan(time) != true) {
		std::string timestring = detectionformats::ConvertEpochTimeToISO8601(
				time);
		rapidjson::Value timevalue;
		timevalue.SetString(rapidjson::StringRef(timestring.c_str()),
							allocator);
		json.AddMember(TIME_KEY, timevalue, allocator);
	}

	// correlation
	if (std::isnan(correlationvalue) != true)
		json.AddMember(CORRELATION_KEY, correlationvalue, allocator);

	// hypocenter
	rapidjson::Value hypocentervalue(rapidjson::kObjectType);
	hypocenter.tojson(hypocentervalue, allocator);
	json.AddMember(HYPOCENTER_KEY, hypocentervalue, allocator);

	// optional values
	// eventtype
	if (eventtype.isempty() == false) {
		rapidjson::Value eventtypevalue(rapidjson::kObjectType);
		eventtype.tojson(eventtypevalue, allocator);
		json.AddMember(EVENTTYPE_KEY, eventtypevalue, allocator);
	}

	// magnitude
	if (std::isnan(magnitude) != true)
		json.AddMember(MAGNITUDE_KEY, magnitude, allocator);

	// snr
	if (std::isnan(snr) != true)
		json.AddMember(SNR_KEY, snr, allocator);

	// zscore
	if (std::isnan(zscore) != true)
		json.AddMember(ZSCORE_KEY, zscore, allocator);

	// detectionthreshold
	if (std::isnan(detectionthreshold) != true)
		json.AddMember(DETECTIONTHRESHOLD_KEY, detectionthreshold, allocator);

	// thresholdtype
	if (thresholdtype != "") {
		rapidjson::Value thresholdtypevalue;
		thresholdtypevalue.SetString(
				rapidjson::StringRef(thresholdtype.c_str()), allocator);
		json.AddMember(THRESHOLDTYPE_KEY, thresholdtypevalue, allocator);
	}

	// associated
	if (associationinfo.isempty() == false) {
		rapidjson::Value associatedvalue(rapidjson::kObjectType);
		associationinfo.tojson(associatedvalue, allocator);
		json.AddMember(ASSOCIATIONINFO_KEY, associatedvalue, allocator);
	}

	return (json);
}

std::vector<std::string> correlation::geterrors() {
	std::vector<std::string> errorlist;

	// check required data
	// Type
	if (type != CORRELATION_TYPE) {
		// wrong type
		errorlist.push_back("Non-correlation type in correlation class.");
	}

	// id
	if (id == "") {
		// empty id
		errorlist.push_back("Empty ID in correlation class.");
	}

	// site
	if (site.isvalid() != true) {
		// site not found
		errorlist.push_back(
				"Site object did not validate in correlation class.");
	}

	// source
	if (source.isvalid() != true) {
		// bad source
		errorlist.push_back(
				"Source object did not validate in correlation class.");
	}

	// phase
	if (phase == "") {
		errorlist.push_back("Empty Phase in correlation class.");
	}
	if (detectionformats::IsStringAlpha(phase) == false) {
		errorlist.push_back("Phase did not validate in correlation class.");
	}

	// time
	if (std::isnan(time) == true) {
		errorlist.push_back("Time is missing in correlation class.");
	} else {
		try {
			if (detectionformats::IsStringISO8601(
					detectionformats::ConvertEpochTimeToISO8601(time))
					== false) {
				errorlist.push_back(
						"Time did not validate in correlation class.");
			}
		} catch (const std::exception & e) {
			errorlist.push_back(std::string(e.what()));
		}
	}

	// correlationvalue
	if (std::isnan(correlationvalue) == true) {
		// correlationvalue not found
		errorlist.push_back("No Correlation in correlation class.");
	}
	if (correlationvalue < 0) {
		errorlist.push_back("Invalid Correlation in correlation class.");
	}

	// hypocenter
	if (hypocenter.isvalid() != true) {
		// hypocenter not found
		errorlist.push_back(
				"hypocenter object did not validate in correlation class.");
	}

	// optional data
	// eventtype
	if (eventtype.isempty() == false) {
		if (eventtype.isvalid() != true) {
			std::vector<std::string> eventtypeErrors = eventtype.geterrors();

			std::string errorString =
					"EventType object did not validate in detection class:";

			for (int i = 0; i < eventtypeErrors.size(); i++) {
				errorString += " " + eventtypeErrors[i];
			}

			// bad eventtype
			errorlist.push_back(errorString);
		}
	}

	// magnitude
	if (std::isnan(magnitude) != true) {
		if ((magnitude < -2) || (magnitude > 10)) {
			errorlist.push_back("Invalid Magnitude in correlation class.");
		}
	}

	if (std::isnan(snr) != true) {
		// Limit SNR to between 0 and 10 digits after the decimal point
		if ((snr < 0) || (snr > 9999999999.999)) {
			errorlist.push_back(
					"SNR in correlation class is not in the valid range of 0 to "
					"9999999999.999");
		}
	}

	// associated
	if (associationinfo.isempty() == false) {
		if (associationinfo.isvalid() != true) {
			// site not found
			errorlist.push_back(
					"AssociationInfo object did not validate in correlation class.");
		}
	}

	// since thresholdtype is a free text string, and snr, zscore, and
	// detectionthreshold are numaric values no further validation is required.
	// NOTE: Further validation COULD be done to confirm that thresholdtype is
	// valid, and that snr, zscore, and detectionthreshold were within expected
	// bounds.

	// return the list of errors
	return (errorlist);
}
}  // namespace detectionformats
