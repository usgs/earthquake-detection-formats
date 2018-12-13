/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_ASSOCIATED_H
#define DETECTION_ASSOCIATED_H

#include <base.h>

#include <string>
#include <exception>
#include <vector>

namespace detectionformats {
/**
 * \brief detectionformats associated conversion class
 *
 * The detectionformats associated class is a conversion class used to create,
 * parse, and validate associated data as part of detectionformats data.
 *
 */
class associated : public detectionbase {
 public:
	/**
	 * \brief associated constructor
	 *
	 * The constructor for the associated class.
	 * Initializes members to null values.
	 */
	associated();

	/**
	 * \brief associated advanced constructor
	 *
	 * The advanced constructor for the associated class.
	 * Initializes members to provided values.
	 *
	 * \param newphase - A std::string containing the phase name to use, empty
	 * string to omit
	 * \param newdistance - A double containing the distance to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newazimuth - A double containing the azimuth to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newresidual - A double containing the residual to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newsigma - A double containing the sigma to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 */
	associated(std::string newphase, double newdistance, double newazimuth,
				double newresidual, double newsigma);

	/**
	 * \brief associated advanced constructor
	 *
	 * The advanced constructor for the associated class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	explicit associated(rapidjson::Value &json); // NOLINT

	/**
	 * \brief associated copy constructor
	 *
	 * The copy constructor for the associated class.
	 * Copies the provided object from a associated, populating members
	 * \param newassociated - A associated.
	 */
	associated(const associated & newassociated);

	/**
	 * \brief associated destructor
	 *
	 * The destructor for the associated class.
	 */
	~associated();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \param jsondocument - a reference to the json document to fill in with
	 * the class contents.
	 * \return Returns rapidjson::Value & if successful
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
	 * \brief Empty check
	 *
	 * Checks to see if this object is empty
	 * \return Returns true if empty, false otherwise.
	 */
	bool isempty();

	/**
	 * \brief associated phase name
	 *
	 * An optional std::string containing associated phase name.
	 */
	std::string phase;

	/**
	 * \brief associated distance
	 *
	 * An optional double containing the associated distance
	 */
	double distance;

	/**
	 * \brief associated azimuth
	 *
	 * An optional double containing the associated azimuth
	 */
	double azimuth;

	/**
	 * \brief associated residual
	 *
	 * An optional double containing the associated residual
	 */
	double residual;

	/**
	 * \brief associated sigma
	 *
	 * An optional double containing the associated sigma
	 */
	double sigma;
};
}  // namespace detectionformats
#endif  // DETECTION_ASSOCIATED_H
