#include "origin.h"

// JSON Keys
#define TYPE_KEY "Type"
#define ID_KEY "ID"
#define SOURCE_KEY "Source"
#define HYPOCENTER_KEY "Hypocenter"
#define ORIGINTYPE_KEY "OriginType"
#define EVENTTYPE_KEY "EventType"
#define BAYES_KEY "Bayes"
#define MINIMUMDISTANCE_KEY "MinimumDistance"
#define RMS_KEY "RMS"
#define GAP_KEY "Gap"
#define DATA_KEY "Data"

namespace detectionformats {
origin::origin() {
	type = ORIGIN_TYPE;
	id = "";
	source = detectionformats::source();
	hypocenter = detectionformats::hypo();
	origintype = "";
	eventtype = "";
	bayes = std::numeric_limits<double>::quiet_NaN();
	minimumdistance = std::numeric_limits<double>::quiet_NaN();
	rms = std::numeric_limits<double>::quiet_NaN();
	gap = std::numeric_limits<double>::quiet_NaN();
	pickdata.clear();
	beamdata.clear();
	correlationdata.clear();
}

origin::origin(std::string newid, std::string newagencyid,
		std::string newauthor, double newlatitude, double newlongitude,
		double neworigintime, double newdepth, double newlatitudeerror,
		double newlongitudeerror, double newtimeerror, double newdeptherror,
		std::string neworigintype, std::string neweventtype, double newbayes,
		double newminimumdistance, double newrms, double newgap,
		std::vector<detectionformats::pick> newpickdata,
		std::vector<detectionformats::beam> newbeamdata,
		std::vector<detectionformats::correlation> newcorrelationdata) {
	type = ORIGIN_TYPE;
	id = newid;
	origin::source = detectionformats::source(newagencyid, newauthor);
	hypocenter = detectionformats::hypo(newlatitude, newlongitude,
			neworigintime, newdepth, newlatitudeerror, newlongitudeerror,
			newtimeerror, newdeptherror);
	origintype = neworigintype;
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

origin::origin(std::string newid, detectionformats::source newsource,
		detectionformats::hypo newhypocenter, std::string neworigintype,
		std::string neweventtype, double newbayes, double newminimumdistance,
		double newrms, double newgap,
		std::vector<detectionformats::pick> newpickdata,
		std::vector<detectionformats::beam> newbeamdata,
		std::vector<detectionformats::correlation> newcorrelationdata) {
	type = ORIGIN_TYPE;
	id = newid;
	origin::source = newsource;
	hypocenter = newhypocenter;
	origintype = neworigintype;
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

origin::origin(rapidjson::Value &json) {
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
	// origintype
	if ((json.HasMember(ORIGINTYPE_KEY) == true)
			&& (json[ORIGINTYPE_KEY].IsString() == true))
		origintype = std::string(json[ORIGINTYPE_KEY].GetString(),
				json[ORIGINTYPE_KEY].GetStringLength());
	else
		origintype = "";

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

origin::origin(const origin & neworigin) {
	type = ORIGIN_TYPE;
	id = neworigin.id;
	origin::source = neworigin.source;
	hypocenter = neworigin.hypocenter;
	origintype = neworigin.origintype;
	eventtype = neworigin.eventtype;
	bayes = neworigin.bayes;
	minimumdistance = neworigin.minimumdistance;
	rms = neworigin.rms;
	gap = neworigin.gap;

	// copy data
	pickdata.clear();
	for (int i = 0; i < (int) neworigin.pickdata.size(); i++) {
		pickdata.push_back(neworigin.pickdata[i]);
	}

	beamdata.clear();
	for (int i = 0; i < (int) neworigin.beamdata.size(); i++) {
		beamdata.push_back(neworigin.beamdata[i]);
	}

	correlationdata.clear();
	for (int i = 0; i < (int) neworigin.correlationdata.size(); i++) {
		correlationdata.push_back(neworigin.correlationdata[i]);
	}
}

origin::~origin() {
	pickdata.clear();
	beamdata.clear();
	correlationdata.clear();
}

rapidjson::Value & origin::tojson(rapidjson::Value &json,
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
	// origintype
	if (origintype != "") {
		rapidjson::Value origintypevalue;
		origintypevalue.SetString(rapidjson::StringRef(origintype.c_str()),
				allocator);
		json.AddMember(ORIGINTYPE_KEY, origintypevalue, allocator);
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

std::vector<std::string> origin::geterrors() {
	std::vector<std::string> errorlist;

	// check required data
	// Type
	if (type != ORIGIN_TYPE) {
		// wrong type
		errorlist.push_back("Non-origin type in origin class.");
	}

	// id
	if (id == "") {
		// empty id
		errorlist.push_back("Empty ID in origin class.");
	}

	// source
	if (source.isvalid() != true) {
		// bad source
		errorlist.push_back("Source object did not validate in origin class.");
	}

	// hypocenter
	if (hypocenter.isvalid() != true) {
		// hypocenter not found
		errorlist.push_back(
				"Hypo object did not validate in origin class.");
	}

	// optional keys
	// origintype
	if (eventtype != "") {
		bool match = false;
		// check all the valid types to see if this string matches
		for (int i = detectionformats::origintypeindex::neworigin;
				i < detectionformats::origintypeindex::origintypecount; i++) {
			if (origintype == detectionformats::origintypevalues[i]) {
				match = true;
				break;
			}
		}

		if (match == false) {
			errorlist.push_back("Invalid OriginType in origin class.");
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
			errorlist.push_back("Invalid EventType in origin class.");
		}
	}

	// bayes
	if (std::isnan(bayes) != true) {
		if (bayes < 0) {
			errorlist.push_back("Invalid Bayes in origin class.");
		}
	}

	// minimumdistance
	if (std::isnan(minimumdistance) != true) {
		if (minimumdistance < 0) {
			errorlist.push_back("Invalid MinimumDistance in origin class.");
		}
	}

	// rms
	if (std::isnan(rms) != true) {
		if (rms < -10000) {
			errorlist.push_back("Invalid RMS in origin class.");
		}
	}

	// gap
	if (std::isnan(gap) != true) {
		if ((gap < 0) || (gap > 360)) {
			errorlist.push_back("Invalid Gap in origin class.");
		}
	}

	// data
	// pickdata
	if (pickdata.size() > 0) {
		for (int i = 0; i < (int) pickdata.size(); i++) {
			if (pickdata[i].isvalid() != true) {
				// bad source
				errorlist.push_back("Invalid pick in origin class.");
			}
		}
	}

	// beamdata
	if (beamdata.size() > 0) {
		for (int i = 0; i < (int) beamdata.size(); i++) {
			if (beamdata[i].isvalid() != true) {
				// bad source
				errorlist.push_back("Invalid beam in origin class.");
			}
		}
	}

	// correlationdata
	if (correlationdata.size() > 0) {
		for (int i = 0; i < (int) correlationdata.size(); i++) {
			if (correlationdata[i].isvalid() != true) {
				// bad source
				errorlist.push_back("Invalid correlation in origin class.");
			}
		}
	}

	// return the list of errors
	return (errorlist);
}

}
