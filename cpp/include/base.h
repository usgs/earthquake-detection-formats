/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_BASE_H
#define DETECTION_BASE_H

#include <string>
#include <vector>
#include <cmath>

#include "util.h" // NOLINT

namespace detectionformats {
class detectionbase {
 public:
	/**
	 * \brief detectionbase constructor
	 *
	 * The constructor for the detectionbase class.
	 * Initializes members to null values.
	 */
	detectionbase();

	/**
	 * \brief site destructor
	 *
	 * The destructor for the detectionbase class.
	 */
	~detectionbase();

	/**
	 * \brief Convert to json value function
	 *
	 * Converts the contents of the class to a json object
	 * \param json - a reference to the rapidjson::Value document to fill in with
	 * the class contents.
	 * \param allocator - a rapidjson::MemoryPoolAllocator to use during the 
	 * conversion
	 * \return Returns rapidjson::Value & if successful
	 */
	virtual rapidjson::Value & tojson(
			rapidjson::Value &json, // NOLINT
			rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) = 0; // NOLINT

	/**
	 * \brief Validates the values in the class
	 *
	 * Validates the values contained in the class
	 * \return Returns 1 if successful, 0 otherwise
	 */
	virtual bool isvalid();

	/**
	 * \brief Gets any errors in the class
	 *
	 * Gets any formatting errors in the class
	 * \return Returns a std::vector<std::string> containing the errors
	 */
	virtual std::vector<std::string> geterrors() = 0;

	/**
	 * \brief type identifier
	 *
	 * A required std::string containing the type of this message.
	 */
	std::string type;
};
}  // namespace detectionformats
#endif  // DETECTION_BASE_H
