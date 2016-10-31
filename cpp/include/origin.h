/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_ORIGIN_H
#define DETECTION_ORIGIN_H

#include <string>
#include <vector>
#include "pick.h"
#include "beam.h"
#include "correlation.h"

namespace detectionformats {
/**
 * \brief detectionformats origin conversion class
 *
 * The detectionformats origin class is a conversion class used to create, parse,
 * and validate the event origin data format origin.  The origin format uses
 * the JSON standard (www.json.org)
 *
 * origin is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * origin uses the Source and Site common objects.
 */
class origin: public detectionbase {
public:
	/**
	 * \brief origin constructor
	 *
	 * The constructor for the origin class.
	 * Initilizes members to null values.
	 */
	origin();

	/**
	 * \brief origin advanced constructor
	 *
	 * The advanced constructor for the origin class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 * \param newlatitude - A double containing the latitude to use
	 * \param newlongitude - A double containing the longitude to use
	 * \param neworigintime - A double containing the new origin time to use
	 * \param newdepth - A double containing the depth to use
	 * \param newlatitudeerror - A double containing the latitude error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlongtiudeerror - A double containing the longitude error to
	 * 		use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newtimeerror - A double containing the time error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdeptherror - A double containing the depth error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
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
	 * 		containing the data that went into this origin, empty vector to omit
	 * \param newbeamdata - A std::vector<detectionformats::beamjson> newdata
	 * 		containing the data that went into this origin, empty vector to omit
	 * \param newcorrelationdata - A std::vector<detectionformats::correlationjson>
	 * 		newdata containing the data that went into this origin, empty vector
	 * 		to omit
	 */
	origin(std::string newid, std::string newagencyid, std::string newauthor,
			double newlatitude, double newlongitude, double neworigintime,
			double newdepth, double newlatitudeerror, double newlongitudeerror,
			double newtimeerror, double newdeptherror,
			std::string neworigintype, std::string neweventtype,
			double newbayes, double newminimumdistance, double newrms,
			double newgap, std::vector<detectionformats::pick> newpickdata,
			std::vector<detectionformats::beam> newbeamdata,
			std::vector<detectionformats::correlation> newcorrelationdata);

	/**
	 * \brief origin alternate advanced constructor
	 *
	 * The alternate advanced constructor for the origin class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsource - A detectionformats::source containing the source to
	 * 		use
	 * \param newhypocenter - A detectionformats::hypo containing the hypocenter
	 * 		to use
	 * \param neworigintype - A std::string containing the origin type to use,
	 * 		empty string to omit
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
	 * 		containing the data that went into this origin, empty vector to omit
	 * \param newbeamdata - A std::vector<detectionformats::beamjson> newdata
	 * 		containing the data that went into this origin, empty vector to omit
	 * \param newcorrelationdata - A std::vector<detectionformats::correlationjson>
	 * 		newdata containing the data that went into this origin, empty vector
	 * 		to omit
	 */
	origin(std::string newid, detectionformats::source newsource,
			detectionformats::hypo newhypocenter, std::string neworigintype,
			std::string neweventtype, double newbayes,
			double newminimumdistance, double newrms, double newgap,
			std::vector<detectionformats::pick> newpickdata,
			std::vector<detectionformats::beam> newbeamdata,
			std::vector<detectionformats::correlation> newcorrelationdata);

	/**
	 * \brief origin advanced constructor
	 *
	 * The advanced constructor for the origin class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	origin(rapidjson::Value &json);

	/**
	 * \brief origin copy constructor
	 *
	 * The copy constructor for the origin class.
	 * Copies the provided object from a origin, populating members
	 * \param neworigin - A origin.
	 */
	origin(const origin & neworigin);

	/**
	 * \brief origin destructor
	 *
	 * The destructor for the origin class.
	 */
	~origin();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \return Returns a json::Object containing the class contents
	 */
	virtual rapidjson::Value & tojson(rapidjson::Value &json,
			rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator)
					override;

	/**
	 * \brief Gets any errors in the class
	 *
	 * Gets any formatting errors in the class
	 * \return Returns a std::vector<std::string> containing the errors
	 */
	virtual std::vector<std::string> geterrors() override;

	/**
	 * \brief origin id
	 *
	 * A required std::string containing the id of this origin message
	 */
	std::string id;

	/**
	 * \brief origin source
	 *
	 * A required detectionformats::site containing the site for this origin
	 * message
	 */
	detectionformats::source source;

	/**
	 * \brief correlation hypocenter
	 *
	 * A required detectionformats::hypo defining the hypocenter of this
	 * origin message
	 */
	detectionformats::hypo hypocenter;

	/**
	 * \brief origin type
	 *
	 * An optional std::string containing the origin type of this origin
	 * valid values are "New", "Update", "Final", or "Retract"
	 */
	std::string origintype;

	/**
	 * \brief origin event type
	 *
	 * An optional std::string containing the event type of this origin
	 * valid values are "earthquake" or "blast"
	 */
	std::string eventtype;

	/**
	 * \brief bayes value
	 *
	 * An optional double defining the bayesian statistic for this origin
	 */
	double bayes;

	/**
	 * \brief minimum distance value
	 *
	 * A required double defining the minimum distance value for this origin
	 */
	double minimumdistance;

	/**
	 * \brief rms value
	 *
	 * A required double defining the rms value for this origin
	 */
	double rms;

	/**
	 * \brief gap value
	 *
	 * A required double defining the gap value for this origin
	 */
	double gap;

	/**
	 * \brief pick data vector
	 *
	 * An optional vector of pick objects used to generate this origin
	 */
	std::vector<detectionformats::pick> pickdata;

	/**
	 * \brief beam data vector
	 *
	 * An optional vector of beam objects used to generate this origin
	 */
	std::vector<detectionformats::beam> beamdata;

	/**
	 * \brief correlation data vector
	 *
	 * An optional vector of correlation objects used to generate this origin
	 */
	std::vector<detectionformats::correlation> correlationdata;

protected:

};
}
#endif
