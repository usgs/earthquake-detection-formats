/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_ASSOCIATED_H
#define DETECTION_ASSOCIATED_H

#include <string>
#include <exception>
#include <vector>

#include "base.h" // NOLINT

namespace detectionformats {
/**
 * \brief detectionformats association conversion class
 *
 * The detectionformats association class is a conversion class used to create,
 * parse, and validate association data as part of detectionformats data.
 *
 */
class association : public detectionbase {
 public:
	/**
	 * \brief association constructor
	 *
	 * The constructor for the association class.
	 * Initializes members to null values.
	 */
	association();

	/**
	 * \brief association advanced constructor
	 *
	 * The advanced constructor for the association class.
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
	association(std::string newphase, double newdistance, double newazimuth,
				double newresidual, double newsigma);

	/**
	 * \brief association advanced constructor
	 *
	 * The advanced constructor for the association class.
	 * Converts the provided object from a rapidjson::Value, populating members
	 * \param json - A rapidjson::Value containing the parsed json.
	 */
	explicit association(rapidjson::Value &json); // NOLINT

	/**
	 * \brief association copy constructor
	 *
	 * The copy constructor for the association class.
	 * Copies the provided object from a association, populating members
	 * \param newassociation - A association.
	 */
	association(const association & newassociation);

	/**
	 * \brief association destructor
	 *
	 * The destructor for the association class.
	 */
	~association();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \param json - a reference to the rapidjson::Value document to fill in with
	 * the class contents.
	 * \param allocator - a rapidjson::MemoryPoolAllocator to use during the 
	 * conversion
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
	 * \brief association phase name
	 *
	 * An optional std::string containing association phase name.
	 */
	std::string phase;

	/**
	 * \brief association distance
	 *
	 * An optional double containing the association distance
	 */
	double distance;

	/**
	 * \brief association azimuth
	 *
	 * An optional double containing the association azimuth
	 */
	double azimuth;

	/**
	 * \brief association residual
	 *
	 * An optional double containing the association residual
	 */
	double residual;

	/**
	 * \brief association sigma
	 *
	 * An optional double containing the association sigma
	 */
	double sigma;
};
}  // namespace detectionformats
#endif  // DETECTION_ASSOCIATED_H
