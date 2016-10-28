/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_HYPO_H
#define DETECTION_HYPO_H

#include <string>
#include <exception>

#include "base.h"

namespace detectionformats {
/**
 * \brief detectionformats hypocenter conversion class
 *
 * The detectionformats hypo class is a conversion class used to create, parse,
 * and validate hypocenter data as part of detectionformats data.
 *
 */
class hypo: public detectionbase {
public:
	/**
	 * \brief hypo constructor
	 *
	 * The constructor for the hypo class.
	 * Initilizes members to null values.
	 */
	hypo();

	/**
	 * \brief hypo advanced constructor
	 *
	 * The advanced constructor for the hypo class.
	 * Initilizes members to provided values.
	 *
	 * \param newlatitude - A double containing the latitude to use
	 * \param newlongitude - A double containing the longitude to use
	 * \param newtime - A double containing the new time to use
	 * \param newdepth - A double containing the depth to use
	 * \param newlatitudeerror - A double containing the latitude error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlongitudeerror - A double containing the longitude error to
	 * 		use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newtimeerror - A double containing the new time error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdeptherror - A double containing the depth error to use,
	 * 		std::numeric_limits<double>::quiet_NaN() to omit
	 */
	hypo(double newlatitude, double newlongitude, double newtime,
			double newdepth, double newlatitudeerror, double newlongitudeerror,
			double newtimeerror, double newdeptherror);

	/**
	 * \brief hypo advanced constructor
	 *
	 * The advanced constructor for the hypo class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	hypo(rapidjson::Value &json);

	/**
	 * \brief hypo copy constructor
	 *
	 * The copy constructor for the hypo class.
	 * Copies the provided object from a hypo, populating members
	 * \param newfilter - A hypo.
	 */
	hypo(const hypo & newfilter);

	/**
	 * \brief hypo destructor
	 *
	 * The destructor for the hypo class.
	 */
	~hypo();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \param jsondocument - a reference to the json document to fill in with
	 * 		the class contents.
	 * \return Returns rapidjson::Value & if successful
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
	 * \brief latitude value
	 *
	 * A required double defining the latitude of this hypo
	 */
	double latitude;

	/**
	 * \brief longitude value
	 *
	 * A required double defining the longitude of this hypo
	 */
	double longitude;

	/**
	 * \brief time value
	 *
	 * A required double containing the time for this hypo
	 */
	double time;

	/**
	 * \brief depth value
	 *
	 * A required double defining the depth of this hypo
	 */
	double depth;

	/**
	 * \brief latitude value
	 *
	 * An optional double defining the latitude error of this hypo
	 */
	double latitudeerror;

	/**
	 * \brief longitude value
	 *
	 * An optional double defining the longitude error of this hypo
	 */
	double longitudeerror;

	/**
	 * \brief hypo time
	 *
	 * An optional double containing the time error for this hypo
	 */
	double timeerror;

	/**
	 * \brief depth value
	 *
	 * An optional double defining the depth error of this hypo
	 */
	double deptherror;

};

}

#endif
