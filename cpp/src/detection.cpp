#include "detection.h"

// JSON Keys
#define TYPE_KEY "Type"
#define ID_KEY "ID"
#define SOURCE_KEY "Source"
#define HYPOCENTER_KEY "Hypocenter"
#define DETECTIONTYPE_KEY "DetectionType"
#define EVENTTYPE_KEY "EventType"
#define BAYES_KEY "Bayes"
#define MINIMUMDISTANCE_KEY "MinimumDistance"
#define RMS_KEY "RMS"
#define GAP_KEY "Gap"
#define DATA_KEY "Data"

namespace detectionformats {
detection::detection() {
	type = DETECTION_TYPE;
	id = "";
	source = detectionformats::source();
	hypocenter = detectionformats::hypo();
	detectiontype = "";
	eventtype = "";
	bayes = std::numeric_limits<double>::quiet_NaN();
	minimumdistance = std::numeric_limits<double>::quiet_NaN();
	rms = std::numeric_limits<double>::quiet_NaN();
	gap = std::numeric_limits<double>::quiet_NaN();
	pickdata.clear();
	beamdata.clear();
	correlationdata.clear();
}

detection::detection(std::string newid, std::string newagencyid,
		std::string newauthor, double newlatitude, double newlongitude,
		double newdetectiontime, double newdepth, double newlatitudeerror,
		double newlongitudeerror, double newtimeerror, double newdeptherror,
		std::string newdetectiontype, std::string neweventtype, double newbayes,
		double newminimumdistance, double newrms, double newgap,
		std::vector<detectionformats::pick> newpickdata,
		std::vector<detectionformats::beam> newbeamdata,
		std::vector<detectionformats::correlation> newcorrelationdata) {
	type = DETECTION_TYPE;
	id = newid;
	detection::source = detectionformats::source(newagencyid, newauthor);
	hypocenter = detectionformats::hypo(newlatitude, newlongitude,
			newdetectiontime, newdepth, newlatitudeerror, newlongitudeerror,
			newtimeerror, newdeptherror);
	detectiontype = newdetectiontype;
	eventtype = neweventtype;
	bayes = newbayes;
	minimumdistance = newminimumdistance;
	rms = newrms;
	gap = newgap;

	// copy data
	pickdata.clear();
	for (int i = 0; i < (int) newpickdata.size(); i++) {
		pickdata.push_back(newpickdata[i]);
	}

	beamdata.clear();
	for (int i = 0; i < (int) newbeamdata.size(); i++) {
		beamdata.push_back(newbeamdata[i]);
	}

	correlationdata.clear();
	for (int i = 0; i < (int) newcorrelationdata.size(); i++) {
		correlationdata.push_back(newcorrelationdata[i]);
	}
}

detection::detection(std::string newid, detectionformats::source newsource,
		detectionformats::hypo newhypocenter, std::string newdetectiontype,
		std::string neweventtype, double newbayes, double newminimumdistance,
		double newrms, double newgap,
		std::vector<detectionformats::pick> newpickdata,
		std::vector<detectionformats::beam> newbeamdata,
		std::vector<detectionformats::correlation> newcorrelationdata) {
	type = DETECTION_TYPE;
	id = newid;
	detection::source = newsource;
	hypocenter = newhypocenter;
	detectiontype = newdetectiontype;
	eventtype = neweventtype;
	bayes = newbayes;
	minimumdistance = newminimumdistance;
	rms = newrms;
	gap = newgap;

	// copy data
	pickdata.clear();
	for (int i = 0; i < (int) newpickdata.size(); i++) {
		pickdata.push_back(newpickdata[i]);
	}

	beamdata.clear();
	for (int i = 0; i < (int) newbeamdata.size(); i++) {
		beamdata.push_back(newbeamdata[i]);
	}

	correlationdata.clear();
	for (int i = 0; i < (int) newcorrelationdata.size(); i++) {
		correlationdata.push_back(newcorrelationdata[i]);
	}
}

detection::detection(rapidjson::Value &json) {
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

	// source
	if ((json.HasMember(SOURCE_KEY) == true)
			&& (json[SOURCE_KEY].IsObject() == true)) {
		rapidjson::Value & sourcevalue = json[SOURCE_KEY];
		source = detectionformats::source(sourcevalue);
	} else
		source = detectionformats::source();

	// hypocenter
	if ((json.HasMember(HYPOCENTER_KEY) == true)
			&& (json[HYPOCENTER_KEY].IsObject() == true)) {
		rapidjson::Value & hypocentervalue = json[HYPOCENTER_KEY];
		hypocenter = detectionformats::hypo(hypocentervalue);
	} else
		hypocenter = detectionformats::hypo();

	// optional values
	// detectiontype
	if ((json.HasMember(DETECTIONTYPE_KEY) == true)
			&& (json[DETECTIONTYPE_KEY].IsString() == true))
		detectiontype = std::string(json[DETECTIONTYPE_KEY].GetString(),
				json[DETECTIONTYPE_KEY].GetStringLength());
	else
		detectiontype = "";

	// eventtype
	if ((json.HasMember(EVENTTYPE_KEY) == true)
			&& (json[EVENTTYPE_KEY].IsString() == true))
		eventtype = std::string(json[EVENTTYPE_KEY].GetString(),
				json[EVENTTYPE_KEY].GetStringLength());
	else
		eventtype = "";

	// bayes
	if ((json.HasMember(BAYES_KEY) == true)
			&& (json[BAYES_KEY].IsNumber() == true)
			&& (json[BAYES_KEY].IsDouble() == true))
		bayes = json[BAYES_KEY].GetDouble();
	else
		bayes = std::numeric_limits<double>::quiet_NaN();

	// minimumdistance
	if ((json.HasMember(MINIMUMDISTANCE_KEY) == true)
			&& (json[MINIMUMDISTANCE_KEY].IsNumber() == true)
			&& (json[MINIMUMDISTANCE_KEY].IsDouble() == true))
		minimumdistance = json[MINIMUMDISTANCE_KEY].GetDouble();
	else
		minimumdistance = std::numeric_limits<double>::quiet_NaN();

	// rms
	if ((json.HasMember(RMS_KEY) == true) && (json[RMS_KEY].IsNumber() == true)
			&& (json[RMS_KEY].IsDouble() == true))
		rms = json[RMS_KEY].GetDouble();
	else
		rms = std::numeric_limits<double>::quiet_NaN();

	// gap
	if ((json.HasMember(GAP_KEY) == true) && (json[GAP_KEY].IsNumber() == true)
			&& (json[GAP_KEY].IsDouble() == true))
		gap = json[GAP_KEY].GetDouble();
	else
		gap = std::numeric_limits<double>::quiet_NaN();

	// data
	pickdata.clear();
	beamdata.clear();
	correlationdata.clear();

	if ((json.HasMember(DATA_KEY) == true)
			&& (json[DATA_KEY].IsArray() == true)) {
		rapidjson::Value dataarray;
		dataarray = json[DATA_KEY].GetArray();

		for (rapidjson::SizeType i = 0; i < dataarray.Size(); i++) {
			rapidjson::Value & datavalue = dataarray[i];
			if (datavalue.HasMember(TYPE_KEY) == false)
				continue;

			// route based on typestring
			std::string typestring = std::string(datavalue["Type"].GetString(),
					datavalue["Type"].GetStringLength());
			if (typestring == PICK_TYPE) {
				detectionformats::pick newpickdata(datavalue);

				// add to vector
				pickdata.push_back(newpickdata);
			} else if (typestring == BEAM_TYPE) {
				detectionformats::beam newbeamdata(datavalue);

				// add to vector
				beamdata.push_back(newbeamdata);
			} else if (typestring == CORRELATION_TYPE) {
				detectionformats::correlation newcorrelationdata(datavalue);

				// add to vector
				correlationdata.push_back(newcorrelationdata);
			} else
				continue;
		}
	}
}

detection::detection(const detection & newdetection) {
	type = DETECTION_TYPE;
	id = newdetection.id;
	detection::source = newdetection.source;
	hypocenter = newdetection.hypocenter;
	detectiontype = newdetection.detectiontype;
	eventtype = newdetection.eventtype;
	bayes = newdetection.bayes;
	minimumdistance = newdetection.minimumdistance;
	rms = newdetection.rms;
	gap = newdetection.gap;

	// copy data
	pickdata.clear();
	for (int i = 0; i < (int) newdetection.pickdata.size(); i++) {
		pickdata.push_back(newdetection.pickdata[i]);
	}

	beamdata.clear();
	for (int i = 0; i < (int) newdetection.beamdata.size(); i++) {
		beamdata.push_back(newdetection.beamdata[i]);
	}

	correlationdata.clear();
	for (int i = 0; i < (int) newdetection.correlationdata.size(); i++) {
		correlationdata.push_back(newdetection.correlationdata[i]);
	}
}

detection::~detection() {
	pickdata.clear();
	beamdata.clear();
	correlationdata.clear();
}

rapidjson::Value & detection::tojson(rapidjson::Value &json,
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

	// source
	rapidjson::Value sourcevalue(rapidjson::kObjectType);
	source.tojson(sourcevalue, allocator);
	json.AddMember(SOURCE_KEY, sourcevalue, allocator);

	// hypocenter
	rapidjson::Value hypocentervalue(rapidjson::kObjectType);
	hypocenter.tojson(hypocentervalue, allocator);
	json.AddMember(HYPOCENTER_KEY, hypocentervalue, allocator);

	// optional values
	// detectiontype
	if (detectiontype != "") {
		rapidjson::Value detectiontypevalue;
		detectiontypevalue.SetString(rapidjson::StringRef(detectiontype.c_str()),
				allocator);
		json.AddMember(DETECTIONTYPE_KEY, detectiontypevalue, allocator);
	}

	// eventtype
	if (eventtype != "") {
		rapidjson::Value eventtypevalue;
		eventtypevalue.SetString(rapidjson::StringRef(eventtype.c_str()),
				allocator);
		json.AddMember(EVENTTYPE_KEY, eventtypevalue, allocator);
	}

	// bayes
	if (std::isnan(bayes) != true)
		json.AddMember(BAYES_KEY, bayes, allocator);

	// minimumdistance
	if (std::isnan(minimumdistance) != true)
		json.AddMember(MINIMUMDISTANCE_KEY, minimumdistance, allocator);

	// rms
	if (std::isnan(rms) != true)
		json.AddMember(RMS_KEY, rms, allocator);

	// gap
	if (std::isnan(gap) != true)
		json.AddMember(GAP_KEY, gap, allocator);

	// data
	// build json array
	rapidjson::Value dataarray(rapidjson::kArrayType);

	// pickdata
	if (pickdata.size() > 0) {
		for (int i = 0; i < (int) pickdata.size(); i++) {
			rapidjson::Value pickvalue(rapidjson::kObjectType);
			pickdata[i].tojson(pickvalue, allocator);
			dataarray.PushBack(pickvalue, allocator);
		}
	}

	// beamdata
	if (beamdata.size() > 0) {
		for (int i = 0; i < (int) beamdata.size(); i++) {
			rapidjson::Value beamvalue(rapidjson::kObjectType);
			beamdata[i].tojson(beamvalue, allocator);
			dataarray.PushBack(beamvalue, allocator);
		}
	}

	// correlationdata
	if (correlationdata.size() > 0) {
		for (int i = 0; i < (int) correlationdata.size(); i++) {
			rapidjson::Value correlationvalue(rapidjson::kObjectType);
			correlationdata[i].tojson(correlationvalue, allocator);
			dataarray.PushBack(correlationvalue, allocator);
		}
	}

	if (dataarray.Size() > 0) {
		// data
		json.AddMember(DATA_KEY, dataarray, allocator);
	}

	// validate
	return (json);
}

std::vector<std::string> detection::geterrors() {
	std::vector<std::string> errorlist;

	// check required data
	// Type
	if (type != DETECTION_TYPE) {
		// wrong type
		errorlist.push_back("Non-detection type in detection class.");
	}

	// id
	if (id == "") {
		// empty id
		errorlist.push_back("Empty ID in detection class.");
	}

	// source
	if (source.isvalid() != true) {
		// bad source
		errorlist.push_back("Source object did not validate in detection class.");
	}

	// hypocenter
	if (hypocenter.isvalid() != true) {
		// hypocenter not found
		errorlist.push_back(
				"Hypo object did not validate in detection class.");
	}

	// optional keys
	// detectiontype
	if (detectiontype != "") {
		bool match = false;
		// check all the valid types to see if this string matches
		for (int i = detectionformats::detectiontypeindex::newdetection;
				i < detectionformats::detectiontypeindex::detectiontypecount; i++) {
			if (detectiontype == detectionformats::detectiontypevalues[i]) {
				match = true;
				break;
			}
		}

		if (match == false) {
			errorlist.push_back("Invalid DetectionType in detection class.");
		}
	}

	// eventtype
	if (eventtype != "") {
		bool match = false;
		// check all the valid types to see if this string matches
		for (int i = detectionformats::eventtypeindex::earthquake;
				i < detectionformats::eventtypeindex::eventtypecount; i++) {
			if (eventtype == eventtypevalues[i]) {
				match = true;
				break;
			}
		}

		if (match == false) {
			errorlist.push_back("Invalid EventType in detection class.");
		}
	}

	// bayes
	if (std::isnan(bayes) != true) {
		if (bayes < 0) {
			errorlist.push_back("Invalid Bayes in detection class.");
		}
	}

	// minimumdistance
	if (std::isnan(minimumdistance) != true) {
		if (minimumdistance < 0) {
			errorlist.push_back("Invalid MinimumDistance in detection class.");
		}
	}

	// rms
	if (std::isnan(rms) != true) {
		if (rms < -10000) {
			errorlist.push_back("Invalid RMS in detection class.");
		}
	}

	// gap
	if (std::isnan(gap) != true) {
		if ((gap < 0) || (gap > 360)) {
			errorlist.push_back("Invalid Gap in detection class.");
		}
	}

	// data
	// pickdata
	if (pickdata.size() > 0) {
		for (int i = 0; i < (int) pickdata.size(); i++) {
			if (pickdata[i].isvalid() != true) {
				// bad source
				errorlist.push_back("Invalid pick in detection class.");
			}
		}
	}

	// beamdata
	if (beamdata.size() > 0) {
		for (int i = 0; i < (int) beamdata.size(); i++) {
			if (beamdata[i].isvalid() != true) {
				// bad source
				errorlist.push_back("Invalid beam in detection class.");
			}
		}
	}

	// correlationdata
	if (correlationdata.size() > 0) {
		for (int i = 0; i < (int) correlationdata.size(); i++) {
			if (correlationdata[i].isvalid() != true) {
				// bad source
				errorlist.push_back("Invalid correlation in detection class.");
			}
		}
	}

	// return the list of errors
	return (errorlist);
}

}
