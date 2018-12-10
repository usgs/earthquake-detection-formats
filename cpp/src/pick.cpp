#include <pick.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define ID_KEY "ID"
#define SITE_KEY "Site"
#define SOURCE_KEY "Source"
#define TIME_KEY "Time"
#define PHASE_KEY "Phase"
#define POLARITY_KEY "Polarity"
#define ONSET_KEY "Onset"
#define PICKER_KEY "Picker"
#define FILTER_KEY "Filter"
#define AMPLITUDE_KEY "Amplitude"
#define BEAM_KEY "Beam"
#define ASSOCIATIONINFO_KEY "AssociationInfo"

namespace detectionformats {
pick::pick() {
	type = PICK_TYPE;
	id = "";
	site = detectionformats::site();
	time = std::numeric_limits<double>::quiet_NaN();
	source = detectionformats::source();
	phase = "";
	polarity = "";
	onset = "";
	picker = "";
	filterdata.clear();
	amplitude = detectionformats::amplitude();
	beam = detectionformats::beam();
	associationinfo = detectionformats::associated();
}

pick::pick(std::string newid, std::string newstation, std::string newchannel,
			std::string newnetwork, std::string newlocation, double newtime,
			std::string newagencyid, std::string newauthor,
			std::string newphase, std::string newpolarity, std::string newonset,
			std::string newpicker, double newhighpass, double newlowpass,
			double newamplitude, double newperiod, double newsnr,
			double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror, std::string newassociatedphase,
			double newassociateddistance, double newassociatedazimuth,
			double newassociatedresidual, double newassociatedsigma) {
	type = PICK_TYPE;
	id = newid;
	site = detectionformats::site(newstation, newchannel, newnetwork,
									newlocation);
	time = newtime;
	source = detectionformats::source(newagencyid, newauthor);
	phase = newphase;
	polarity = newpolarity;
	onset = newonset;
	picker = newpicker;

	filterdata.clear();
	filterdata.push_back(detectionformats::filter(newhighpass, newlowpass));

	amplitude = detectionformats::amplitude(newamplitude, newperiod, newsnr);

	beam = detectionformats::beam(newbackazimuth, newbackazimutherror,
									newslowness, newslownesserror,
									newpowerratio, newpowerratioerror);

	associationinfo = detectionformats::associated(newassociatedphase,
													newassociateddistance,
													newassociatedazimuth,
													newassociatedresidual,
													newassociatedsigma);
}

pick::pick(std::string newid, std::string newstation, std::string newchannel,
			std::string newnetwork, std::string newlocation, double newtime,
			std::string newagencyid, std::string newauthor,
			std::string newphase, std::string newpolarity, std::string newonset,
			std::string newpicker, double newhighpass, double newlowpass,
			double newamplitude, double newperiod, double newsnr,
			double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror) {
	type = PICK_TYPE;
	id = newid;
	site = detectionformats::site(newstation, newchannel, newnetwork,
									newlocation);
	time = newtime;
	source = detectionformats::source(newagencyid, newauthor);
	phase = newphase;
	polarity = newpolarity;
	onset = newonset;
	picker = newpicker;

	filterdata.clear();
	filterdata.push_back(detectionformats::filter(newhighpass, newlowpass));

	amplitude = detectionformats::amplitude(newamplitude, newperiod, newsnr);

	beam = detectionformats::beam(newbackazimuth, newbackazimutherror,
									newslowness, newslownesserror,
									newpowerratio, newpowerratioerror);

	associationinfo = detectionformats::associated();
}

pick::pick(std::string newid, detectionformats::site newsite, double newtime,
			detectionformats::source newsource, std::string newphase,
			std::string newpolarity, std::string newonset,
			std::string newpicker,
			std::vector<detectionformats::filter> newfilterdata,
			detectionformats::amplitude newamplitude,
			detectionformats::beam newbeam) {
	type = PICK_TYPE;
	id = newid;
	pick::site = newsite;
	time = newtime;
	pick::source = newsource;
	phase = newphase;
	polarity = newpolarity;
	onset = newonset;
	picker = newpicker;

	filterdata.clear();
	for (int i = 0; i < static_cast<int>(newfilterdata.size()); i++) {
		filterdata.push_back(newfilterdata[i]);
	}

	pick::amplitude = newamplitude;

	pick::beam = newbeam;

	pick::associationinfo = detectionformats::associated();
}

pick::pick(std::string newid, detectionformats::site newsite, double newtime,
			detectionformats::source newsource, std::string newphase,
			std::string newpolarity, std::string newonset,
			std::string newpicker,
			std::vector<detectionformats::filter> newfilterdata,
			detectionformats::amplitude newamplitude,
			detectionformats::beam newbeam,
			detectionformats::associated newassociated) {
	type = PICK_TYPE;
	id = newid;
	site = newsite;
	time = newtime;
	source = newsource;
	phase = newphase;
	polarity = newpolarity;
	onset = newonset;
	picker = newpicker;

	filterdata.clear();
	for (int i = 0; i < static_cast<int>(newfilterdata.size()); i++) {
		filterdata.push_back(newfilterdata[i]);
	}

	amplitude = newamplitude;

	pick::beam = newbeam;

	associationinfo = newassociated;
}

pick::pick(rapidjson::Value &json) {
	// required values
	// type
	if ((json.HasMember(TYPE_KEY) == true)
			&& (json[TYPE_KEY].IsString() == true)) {
		type = std::string(json[TYPE_KEY].GetString(),
							json[TYPE_KEY].GetStringLength());
	} else {
		type = "";
	}

	// id
	if ((json.HasMember(ID_KEY) == true) && (json[ID_KEY].IsString() == true)) {
		id = std::string(json[ID_KEY].GetString(),
							json[ID_KEY].GetStringLength());
	} else {
		id = "";
	}

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

	// time
	if ((json.HasMember(TIME_KEY) == true)
			&& (json[TIME_KEY].IsString() == true)) {
		time = detectionformats::ConvertISO8601ToEpochTime(
				std::string(json[TIME_KEY].GetString(),
							json[TIME_KEY].GetStringLength()));
	} else {
		time = std::numeric_limits<double>::quiet_NaN();
	}

	// optional values
	// phase
	if ((json.HasMember(PHASE_KEY) == true)
			&& (json[PHASE_KEY].IsString() == true)) {
		phase = std::string(json[PHASE_KEY].GetString(),
							json[PHASE_KEY].GetStringLength());
	} else {
		phase = "";
	}

	// polarity
	if ((json.HasMember(POLARITY_KEY) == true)
			&& (json[POLARITY_KEY].IsString() == true)) {
		polarity = std::string(json[POLARITY_KEY].GetString(),
								json[POLARITY_KEY].GetStringLength());
	} else {
		polarity = "";
	}

	// onset
	if ((json.HasMember(ONSET_KEY) == true)
			&& (json[ONSET_KEY].IsString() == true)) {
		onset = std::string(json[ONSET_KEY].GetString(),
							json[ONSET_KEY].GetStringLength());
	} else {
		onset = "";
	}

	// picker
	if ((json.HasMember(PICKER_KEY) == true)
			&& (json[PICKER_KEY].IsString() == true)) {
		picker = std::string(json[PICKER_KEY].GetString(),
								json[PICKER_KEY].GetStringLength());
	} else {
		picker = "";
	}

	// filter
	filterdata.clear();
	if ((json.HasMember(FILTER_KEY) == true)
			&& (json[FILTER_KEY].IsArray() == true)) {
		rapidjson::Value dataarray;
		dataarray = json[FILTER_KEY].GetArray();

		for (rapidjson::SizeType i = 0; i < dataarray.Size(); i++) {
			// parse
			rapidjson::Value & datavalue = dataarray[i];
			detectionformats::filter newfilter(datavalue);

			// add to vector
			filterdata.push_back(newfilter);
		}
	}

	// amplitude
	if ((json.HasMember(AMPLITUDE_KEY) == true)
			&& (json[AMPLITUDE_KEY].IsObject() == true)) {
		rapidjson::Value & amplitudevalue = json[AMPLITUDE_KEY];
		amplitude = detectionformats::amplitude(amplitudevalue);
	} else {
		amplitude = detectionformats::amplitude();
	}

	// beam
	if ((json.HasMember(BEAM_KEY) == true)
			&& (json[BEAM_KEY].IsObject() == true)) {
		rapidjson::Value & beamvalue = json[BEAM_KEY];
		beam = detectionformats::beam(beamvalue);
	} else {
		beam = detectionformats::beam();
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

pick::pick(const pick &newpick) {
	type = PICK_TYPE;
	id = newpick.id;
	site = newpick.site;
	time = newpick.time;
	source = newpick.source;
	phase = newpick.phase;
	polarity = newpick.polarity;
	onset = newpick.onset;
	picker = newpick.picker;

	filterdata.clear();
	for (int i = 0; i < static_cast<int>(newpick.filterdata.size()); i++) {
		filterdata.push_back(newpick.filterdata[i]);
	}

	amplitude = newpick.amplitude;

	beam = newpick.beam;

	associationinfo = newpick.associationinfo;
}

pick::~pick() {
}

rapidjson::Value & pick::tojson(
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

	// time
	if (std::isnan(time) != true) {
		std::string timestring = detectionformats::ConvertEpochTimeToISO8601(
				time);
		rapidjson::Value timevalue;
		timevalue.SetString(rapidjson::StringRef(timestring.c_str()),
							allocator);
		json.AddMember(TIME_KEY, timevalue, allocator);
	}

	// optional values
	// phase
	if (phase != "") {
		rapidjson::Value phasevalue;
		phasevalue.SetString(rapidjson::StringRef(phase.c_str()), allocator);
		json.AddMember(PHASE_KEY, phasevalue, allocator);
	}

	// polarity
	if (polarity != "") {
		rapidjson::Value polarityvalue;
		polarityvalue.SetString(rapidjson::StringRef(polarity.c_str()),
								allocator);
		json.AddMember(POLARITY_KEY, polarityvalue, allocator);
	}

	// onset
	if (onset != "") {
		rapidjson::Value onsetvalue;
		onsetvalue.SetString(rapidjson::StringRef(onset.c_str()), allocator);
		json.AddMember(ONSET_KEY, onsetvalue, allocator);
	}

	// picker
	if (picker != "") {
		rapidjson::Value pickervalue;
		pickervalue.SetString(rapidjson::StringRef(picker.c_str()), allocator);
		json.AddMember(PICKER_KEY, pickervalue, allocator);
	}

	// filter
	if (filterdata.size() > 0) {
		// build json array
		rapidjson::Value dataarray(rapidjson::kArrayType);

		for (int i = 0; i < static_cast<int>(filterdata.size()); i++) {
			rapidjson::Value filtervalue(rapidjson::kObjectType);
			filterdata[i].tojson(filtervalue, allocator);
			dataarray.PushBack(filtervalue, allocator);
		}

		if (dataarray.Size() > 0) {
			json.AddMember(FILTER_KEY, dataarray, allocator);
		}
	}

	// amplitude
	if (pick::amplitude.isempty() == false) {
		rapidjson::Value amplitudevalue(rapidjson::kObjectType);
		amplitude.tojson(amplitudevalue, allocator);
		json.AddMember(AMPLITUDE_KEY, amplitudevalue, allocator);
	}

	// beam
	if (pick::beam.isempty() == false) {
		rapidjson::Value beamvalue(rapidjson::kObjectType);
		amplitude.tojson(beamvalue, allocator);
		json.AddMember(BEAM_KEY, beamvalue, allocator);
	}

	// associated
	if (associationinfo.isempty() == false) {
		rapidjson::Value associatedvalue(rapidjson::kObjectType);
		associationinfo.tojson(associatedvalue, allocator);
		json.AddMember(ASSOCIATIONINFO_KEY, associatedvalue, allocator);
	}

	return (json);
}

std::vector<std::string> pick::geterrors() {
	std::vector<std::string> errorlist;

	// check for requried data
	// Type
	if (type != PICK_TYPE) {
		// wrong type
		errorlist.push_back("Non-pick type in pick class.");
	}

	// id
	if (id == "") {
		// empty id
		errorlist.push_back("Empty ID in pick class.");
	}

	// site
	if (site.isvalid() != true) {
		std::vector<std::string> siteErrors = site.geterrors();

		std::string errorString = "Site object did not validate in pick class:";

		for (int i = 0; i < siteErrors.size(); i++) {
			errorString += " " + siteErrors[i];
		}

		// bad site
		errorlist.push_back(errorString);
	}

	// source
	if (source.isvalid() != true) {
		std::vector<std::string> sourceErrors = source.geterrors();

		std::string errorString =
				"Source object did not validate in pick class:";

		for (int i = 0; i < sourceErrors.size(); i++) {
			errorString += " " + sourceErrors[i];
		}

		// bad source
		errorlist.push_back(errorString);
	}

	// time
	if (std::isnan(time) == true) {
		errorlist.push_back("Time is missing in pick class.");
	} else {
		try {
			if (detectionformats::IsStringISO8601(
					detectionformats::ConvertEpochTimeToISO8601(time))
					== false) {
				errorlist.push_back("Time did not validate in pick class.");
			}
		} catch (const std::exception & e) {
			errorlist.push_back(std::string(e.what()));
		}
	}

	// optional data
	// phase
	if (phase != "") {
		if (detectionformats::IsStringAlpha(phase) == false) {
			errorlist.push_back("Phase did not validate in pick class.");
		}
	}

	// polarity
	if (polarity != "") {
		bool match = false;
		// check all the valid types to see if this string matches
		for (int i = detectionformats::polarityindex::up;
				i < detectionformats::polarityindex::polaritycount; i++) {
			if (polarity == polarityvalues[i]) {
				match = true;
				break;
			}
		}

		if (match == false) {
			errorlist.push_back("Invalid Polarity in pick class.");
		}
	}

	// onset
	if (onset != "") {
		bool match = false;
		// check all the valid types to see if this string matches
		for (int i = detectionformats::onsetindex::impulsive;
				i < detectionformats::onsetindex::onsetcount; i++) {
			if (onset == onsetvalues[i]) {
				match = true;
				break;
			}
		}

		if (match == false) {
			errorlist.push_back("Invalid Onset in pick class.");
		}
	}

	// picker
	if (picker != "") {
		bool match = false;
		// check all the valid types to see if this string matches
		for (int i = detectionformats::pickerindex::manual;
				i < detectionformats::pickerindex::pickercount; i++) {
			if (picker == pickervalues[i]) {
				match = true;
				break;
			}
		}

		if (match == false) {
			errorlist.push_back("Invalid Picker in pick class.");
		}
	}

	// filter
	if (filterdata.size() > 0) {
		for (int i = 0; i < static_cast<int>(filterdata.size()); i++) {
			if (filterdata[i].isvalid() != true) {
				std::vector<std::string> filterErrors =
						filterdata[i].geterrors();

				std::string errorString = "Invalid filter object in pick class:";

				for (int j = 0; j < filterErrors.size(); j++) {
					errorString += " " + filterErrors[j];
				}

				// bad filter
				errorlist.push_back(errorString);
			}
		}
	}

	// amplitude
	if (amplitude.isempty() == false) {
		if (amplitude.isvalid() != true) {
			std::vector<std::string> ampErrors = amplitude.geterrors();

			std::string errorString =
					"Amplitude object did not validate in pick class:";

			for (int i = 0; i < ampErrors.size(); i++) {
				errorString += " " + ampErrors[i];
			}

			// bad amplitude
			errorlist.push_back(errorString);
		}
	}

	// beam
	if (beam.isempty() == false) {
		if (beam.isvalid() != true) {
			std::vector<std::string> beamErrors = beam.geterrors();

			std::string errorString =
					"Beam object did not validate in pick class:";

			for (int i = 0; i < beamErrors.size(); i++) {
				errorString += " " + beamErrors[i];
			}

			// bad beam
			errorlist.push_back(errorString);
		}
	}

	// associated
	if (associationinfo.isempty() == false) {
		if (associationinfo.isvalid() != true) {
			std::vector<std::string> assocErrors = associationinfo.geterrors();

			std::string errorString =
					"AssociationInfo object did not validate in pick class:";

			for (int i = 0; i < assocErrors.size(); i++) {
				errorString += " " + assocErrors[i];
			}

			// bad associated
			errorlist.push_back(errorString);
		}
	}

	// since id and phase are free text strings, no further validation is
	// required.
	// NOTE: Further validation COULD be done to confirm that phase is a valid
	// phase name

	// return the list of errors
	return (errorlist);
}
}  // namespace detectionformats
