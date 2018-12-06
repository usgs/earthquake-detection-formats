/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_UTIL_H
#define DETECTION_UTIL_H

#include <exception>
#include <string>

// needed to disable rapidjson warnings for clang
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexpansion-to-defined"
#include "document.h" // NOLINT
#include "writer.h" // NOLINT
#include "stringbuffer.h"  // NOLINT
#pragma clang diagnostic pop

#define DETECTIONEXTENSION "jsondetect"
#define RETRACTEXTENSION "jsonrtct"
#define PICKEXTENSION "jsonpick"
#define CORRELATIONEXTENSION "jsoncorl"
#define STATIONINFOEXTENSION "jsonsta"
#define STATIONINFOREQUESTEXTENSION "jsonstareq"

#define DETECTION_TYPE "Detection"
#define CORRELATION_TYPE "Correlation"
#define PICK_TYPE "Pick"
#define RETRACT_TYPE "Retract"
#define STATIONINFO_TYPE "StationInfo"
#define STATIONINFOREQUEST_TYPE "StationInfoRequest"

/**
 * @namespace detectionformats
 * The namespace containing a collection of classes and functions that
 * convert to/from the USGS json detection formats.
 */
namespace detectionformats {
/**
 * \brief detectionformats valid event type index enum
 */
enum eventtypeindex {
	earthquake = 0,
	blast = 1,
	eventtypecount = 2
};

/**
 * \brief detectionformats valid event type values
 */
static const char *eventtypevalues[] = { "earthquake", "blast", "" };

/**
 * \brief detectionformats valid pick polarity index enum
 */
enum polarityindex {
	up = 0,
	down = 1,
	polaritycount = 2
};

/**
 * \brief detectionformats valid pick polarity values
 */
static const char *polarityvalues[] = { "up", "down", "" };

/**
 * \brief detectionformats valid pick onset index enum
 */
enum onsetindex {
	impulsive = 0,
	emergent = 1,
	questionable = 2,
	onsetcount = 3
};

/**
 * \brief detectionformats valid pick onset values
 */
static const char *onsetvalues[] =
		{ "impulsive", "emergent", "questionable", "" };

/**
 * \brief detectionformats valid picker index enum
 */
enum pickerindex {
	manual = 0,
	raypicker = 1,
	filterpicker = 2,
	earthworm = 3,
	other = 4,
	pickercount = 5
};

/**
 * \brief detectionformats valid picker values
 */
static const char *pickervalues[] = { "manual", "raypicker", "filterpicker",
		"earthworm", "other", "" };

/**
 * \brief detectionformats valid detection type index enum
 */
enum detectiontypeindex {
	newdetection = 0,
	update = 1,
	final = 2,
	retractdetection = 3,
	detectiontypecount = 4
};

/**
 * \brief detectionformats valid detection type values
 */
static const char *detectiontypevalues[] = { "New", "Update", "Final",
		"Retract", "" };

/**
 * \brief detectionformats format types
 */
enum formattypes {
	picktype = 0,
	correlationtype = 1,
	detectiontype = 2,
	retracttype = 3,
	stationinfotype = 4,
	stationinforequesttype = 5,
	unknown = -1
};

/**
 * \brief detectionformats function to get the detection type for a provided
 * json formatted string
 */
int GetDetectionType(std::string jsonstring);

/**
 * \brief detectionformats function to validate that a string contains just
 * characters
 */
bool IsStringAlpha(const std::string &s);

/**
 * \brief detectionformats function to validate that a string contains an
 * iso8601 time
 */
bool IsStringISO8601(const std::string &s);

/**
 * \brief Convert iso8601 time string to decimal epoch seconds
 *
 * Converts the provided iso8601 string to decimal epoch seconds
 * \return Returns a double containing the decimal epoch seconds
 */
double ConvertISO8601ToEpochTime(std::string TimeString);

/**
 * \brief Convert decimal epoch seconds to iso8601 time string
 *
 * Converts the  decimal epoch seconds to iso8601 time string
 * \return Returns a std::string containing iso8601 time string
 */
std::string ConvertEpochTimeToISO8601(double epochtime);

/**
 * \brief Convert to json string function
 *
 * Converts the contents of the class to a serialized json string
 * \return Returns a std::string containing the serialized json string
 */
std::string ToJSONString(rapidjson::Value &json); // NOLINT

/**
 * \brief Convert from json string function
 *
 * Converts the provided string from a serialized json string, populating
 * members
 * \param jsonstring - A std::string containing the serialized json
 * \return Returns 1 if successful, 0 otherwise
 */
rapidjson::Document & FromJSONString(std::string jsonstring,
										rapidjson::Document & jsondocument); // NOLINT
}  // namespace detectionformats
#endif  // DETECTION_UTIL_H
