#include <detection-formats.h>

#include <detection.h>
#include <retract.h>
#include <pick.h>
#include <correlation.h>
#include <stationInfo.h>
#include <stationInfoRequest.h>

#include <string>
#include <vector>

namespace detectionformats {
////////////// functions //////////////

bool ValidateJSON(const std::string & jsonstring) {
    std::string errorstring = ValidateJSONErrors(jsonstring);

	if (errorstring.length() == 0) {
        return(true);
    } else {
        return(false);
    }
}

std::string ValidateJSONErrors(const std::string & jsonstring) {
    rapidjson::Document jsondocument;

	// parse the json into a document
	if (jsondocument.Parse(jsonstring.c_str()).HasParseError()) {
		return ("Parse Error");
	}

	int type = GetDetectionType(jsondocument);

	if (type == formattypes::unknown) {
		return("Unknown Format");
	}

    std::vector<std::string> errorlist;
    std::string errorstring = "";

	if (type == formattypes::picktype) {
        detectionformats::pick testpick(jsondocument);
        errorlist = testpick.geterrors();
	} else if (type == formattypes::correlationtype) {
        detectionformats::correlation testcorrelation(jsondocument);
        errorlist = testcorrelation.geterrors();
	} else if (type == formattypes::detectiontype) {
        detectionformats::detection testdetection(jsondocument);
        errorlist = testdetection.geterrors();
	} else if (type == formattypes::retracttype) {
        detectionformats::retract testretract(jsondocument);
        errorlist = testretract.geterrors();
	} else if (type == formattypes::stationinfotype) {
        detectionformats::stationInfo teststationinfo(jsondocument);
        errorlist = teststationinfo.geterrors();
	} else if (type == formattypes::stationinforequesttype) {
        detectionformats::stationInfoRequest testrequest(jsondocument);
        errorlist = testrequest.geterrors();
	}

    // no errors
    if (errorlist.size() == 0) {
		return ("");
	}

    for (int i = 0; i < errorlist.size(); i++) {
        errorstring += " " + errorlist[i];
    }

    return(errorstring);
}

}  // namespace detectionformats
