/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_HYPOCENTER_H
#define DETECTION_HYPOCENTER_H

#include <base.h>

#include <string>
#include <exception>
#include <vector>

namespace detectionformats {
/**
 * \brief detectionformats hypocenter conversion class
 *
 * The detectionformats hypo class is a conversion class used to create, parse,
 * and validate hypocenter data as part of detectionformats data.
 *
 */
class hypocenter : public detectionbase {
 public:
	/**
	 * \brief hypocenter constructor
	 *
	 * The constructor for the hypocenter class.
	 * Initilizes members to null values.
	 */
	hypocenter();

	/**
	 * \brief hypocenter advanced constructor
	 *
	 * The advanced constructor for the hypocenter class.
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
	hypocenter(double newlatitude, double newlongitude, double newtime,
				double newdepth, double newlatitudeerror,
				double newlongitudeerror, double newtimeerror,
				double newdeptherror);

	/**
	 * \brief hypocenter advanced constructor
	 *
	 * The advanced constructor for the hypocenter class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	explicit hypocenter(rapidjson::Value &json);

	/**
	 * \brief hypocenter copy constructor
	 *
	 * The copy constructor for the hypocenter class.
	 * Copies the provided object from a hypocenter, populating members
	 * \param newhypo - A hypocenter.
	 */
	hypocenter(const hypocenter & newhypo);

	/**
	 * \brief hypocenter destructor
	 *
	 * The destructor for the hypocenter class.
	 */
	~hypocenter();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \param jsondocument - a reference to the json document to fill in with
	 * 		the class contents.
	 * \return Returns rapidjson::Value & if successful
	 */
	rapidjson::Value & tojson(
			rapidjson::Value &json,
			rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator)
					override;

	/**
	 * \brief Gets any errors in the class
	 *
	 * Gets any formatting errors in the class
	 * \return Returns a std::vector<std::string> containing the errors
	 */
	std::vector<std::string> geterrors() override;

	/**
	 * \brief latitude value
	 *
	 * A required double defining the latitude of this hypocenter
	 */
	double latitude;

	/**
	 * \brief longitude value
	 *
	 * A required double defining the longitude of this hypocenter
	 */
	double longitude;

	/**
	 * \brief time value
	 *
	 * A required double containing the time for this hypocenter
	 */
	double time;

	/**
	 * \brief depth value
	 *
	 * A required double defining the depth of this hypocenter
	 */
	double depth;

	/**
	 * \brief latitude value
	 *
	 * An optional double defining the latitude error of this hypocenter
	 */
	double latitudeerror;

	/**
	 * \brief longitude value
	 *
	 * An optional double defining the longitude error of this hypocenter
	 */
	double longitudeerror;

	/**
	 * \brief hypocenter time
	 *
	 * An optional double containing the time error for this hypocenter
	 */
	double timeerror;

	/**
	 * \brief depth value
	 *
	 * An optional double defining the depth error of this hypocenter
	 */
	double deptherror;
};
}  // namespace detectionformats
#endif  // DETECTION_HYPOCENTER_H
