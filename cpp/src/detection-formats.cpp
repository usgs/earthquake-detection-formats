#include <detection-formats.h>

#include <detection.h>
#include <retract.h>
#include <pick.h>
#include <correlation.h>
#include <stationInfo.h>
#include <stationInfoRequest.h>

#include <string>

namespace detectionformats {
////////////// functions //////////////

bool ValidateJSON(std::string jsonstring) {
	rapidjson::Document jsondocument;

	// parse the json into a document
	if (jsondocument.Parse(jsonstring.c_str()).HasParseError()) {
		return (false);
	}

	int type = GetDetectionType(jsondocument);

	if (type == formattypes::unknown) {
		return(false);
	}

	if (type == formattypes::picktype) {
        detectionformats::pick testpick(jsondocument);
        return(testpick.isvalid());
	} else if (type == formattypes::correlationtype) {
        detectionformats::correlation testcorrelation(jsondocument);
        return(testcorrelation.isvalid());
	} else if (type == formattypes::detectiontype) {
        detectionformats::detection testdetection(jsondocument);
        return(testdetection.isvalid());
	} else if (type == formattypes::retracttype) {
        detectionformats::retract testretract(jsondocument);
        return(testretract.isvalid());
	} else if (type == formattypes::stationinfotype) {
        detectionformats::stationInfo teststationinfo(jsondocument);
        return(teststationinfo.isvalid());
	} else if (type == formattypes::stationinforequesttype) {
        detectionformats::stationInfoRequest testrequest(jsondocument);
        return(testrequest.isvalid());
	}

	return(false);
}
}  // namespace detectionformats
