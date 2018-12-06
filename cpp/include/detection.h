/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_ORIGIN_H
#define DETECTION_ORIGIN_H

#include <source.h>
#include <hypocenter.h>
#include <pick.h>
#include <correlation.h>

#include <string>
#include <vector>

namespace detectionformats {
/**
 * \brief detectionformats detection conversion class
 *
 * The detectionformats detection class is a conversion class used to create,
 * parse, and validate the event detection data format detection.  The detection
 * format uses the JSON standard (www.json.org)
 *
 * detection is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * detection uses the Source and Site common objects.
 */
class detection : public detectionbase {
 public:
	/**
	 * \brief detection constructor
	 *
	 * The constructor for the detection class.
	 * Initilizes members to null values.
	 */
	detection();

	/**
	 * \brief detection advanced constructor
	 *
	 * The advanced constructor for the detection class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 * \param newlatitude - A double containing the latitude to use
	 * \param newlongitude - A double containing the longitude to use
	 * \param newtime - A double containing the new time to use
	 * \param newdepth - A double containing the depth to use
	 * \param newlatitudeerror - A double containing the latitude error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlongtiudeerror - A double containing the longitude error to
	 * 		use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newtimeerror - A double containing the time error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdeptherror - A double containing the depth error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdetectiontype - A std::string containing the detection type to
	 * 		use, empty string to omit
	 * \param newdetectiontime - A double containing the new time the detection
	 * was made, i.e. how quickly after origin time, use
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param neweventtype - A std::string containing the event type to use,
	 * 		empty string to omit
	 * \param newbayes - A double containing the bayes to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newminimumdistance - A double containing the minimum distance to
	 * 		use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newrms - A double containing the rms to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newgap - A double containing the gap to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpickdata - A std::vector<detectionformats::pickjson> newdata
	 * 		containing the data that went into this detection, empty vector to
	 * 		omit
	 * \param newcorrelationdata - A std::vector<detectionformats::correlationjson>
	 * 		newdata containing the data that went into this detection, empty
	 * 		vector to omit
	 */
	detection(std::string newid, std::string newagencyid, std::string newauthor,
				double newlatitude, double newlongitude, double newtime,
				double newdepth, double newlatitudeerror,
				double newlongitudeerror, double newtimeerror,
				double newdeptherror, std::string newdetectiontype,
				double newdetectiontime, std::string neweventtype,
				double newbayes, double newminimumdistance, double newrms,
				double newgap, std::vector<detectionformats::pick> newpickdata,
				std::vector<detectionformats::correlation> newcorrelationdata);

	/**
	 * \brief detection alternate advanced constructor
	 *
	 * The alternate advanced constructor for the detection class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsource - A detectionformats::source containing the source to
	 * 		use
	 * \param newhypocenter - A detectionformats::hypocenter containing the
	 * 		hypocenter to use
	 * \param newdetectiontype - A std::string containing the detection type to
	 * 		use, empty string to omit
	 * \param newdetectiontime - A double containing the new time the detection
	 * was made, i.e. how quickly after origin time, use
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param neweventtype - A std::string containing the event type to use,
	 * 		empty string to omit
	 * \param newbayes - A double containing the bayes to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newminimumdistance - A double containing the minimum distance to
	 * 		use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newrms - A double containing the rms to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newgap - A double containing the gap to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpickdata - A std::vector<detectionformats::pickjson> newdata
	 * 		containing the data that went into this detection, empty vector to
	 * 		omit
	 * \param newcorrelationdata - A std::vector<detectionformats::correlationjson>
	 * 		newdata containing the data that went into this detection, empty
	 * 		vector to omit
	 */
	detection(std::string newid, detectionformats::source newsource,
				detectionformats::hypocenter newhypocenter,
				std::string newdetectiontype, double newdetectiontime,
				std::string neweventtype, double newbayes,
				double newminimumdistance, double newrms, double newgap,
				std::vector<detectionformats::pick> newpickdata,
				std::vector<detectionformats::correlation> newcorrelationdata);

	/**
	 * \brief detection advanced constructor
	 *
	 * The advanced constructor for the detection class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	explicit detection(rapidjson::Value &json); // NOLINT

	/**
	 * \brief detection copy constructor
	 *
	 * The copy constructor for the detection class.
	 * Copies the provided object from a detection, populating members
	 * \param newdetection - A detection.
	 */
	detection(const detection & newdetection);

	/**
	 * \brief detection destructor
	 *
	 * The destructor for the detection class.
	 */
	~detection();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \return Returns a json::Object containing the class contents
	 */
	rapidjson::Value & tojson(
			rapidjson::Value &json, // NOLINT
			rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) // NOLINT
					override;

	/**
	 * \brief Gets any errors in the class
	 *
	 * Gets any formatting errors in the class
	 * \return Returns a std::vector<std::string> containing the errors
	 */
	std::vector<std::string> geterrors() override;

	/**
	 * \brief detection id
	 *
	 * A required std::string containing the id of this detection message
	 */
	std::string id;

	/**
	 * \brief detection source
	 *
	 * A required detectionformats::site containing the site for this detection
	 * message
	 */
	detectionformats::source source;

	/**
	 * \brief detection hypocenter
	 *
	 * A required detectionformats::hypocenter defining the hypocenter of this
	 * detection message
	 */
	detectionformats::hypocenter hypocenter;

	/**
	 * \brief detection type
	 *
	 * An optional std::string containing the detection type of this detection
	 * valid values are >New>, >Update>, >Final>, or >Retract>
	 */
	std::string detectiontype;

	/**
	 * \brief detection event type
	 *
	 * An optional std::string containing the event type of this detection
	 * valid values are >earthquake> or >blast>
	 */
	std::string eventtype;

	/**
	 * \brief bayes value
	 *
	 * An optional double defining the bayesian statistic for this detection
	 */
	double bayes;

	/**
	 * \brief minimum distance value
	 *
	 * A required double defining the minimum distance value for this detection
	 */
	double minimumdistance;

	/**
	 * \brief rms value
	 *
	 * A required double defining the rms value for this detection
	 */
	double rms;

	/**
	 * \brief gap value
	 *
	 * A required double defining the gap value for this detection
	 */
	double gap;

	/**
	 * \brief detectiontime value
	 *
	 * An optional double containing the time the detection was made, i.e.
	 * how quickly after origin time.
	 */
	double detectiontime;

	/**
	 * \brief pick data vector
	 *
	 * An optional vector of pick objects used to generate this detection
	 */
	std::vector<detectionformats::pick> pickdata;

	/**
	 * \brief correlation data vector
	 *
	 * An optional vector of correlation objects used to generate this detection
	 */
	std::vector<detectionformats::correlation> correlationdata;
};
}  // namespace detectionformats
#endif  // DETECTION_ORIGIN_H
