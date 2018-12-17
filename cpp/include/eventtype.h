/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_EVENTTYPE_H
#define DETECTION_EVENTTYPE_H

#include <base.h>

#include <string>
#include <exception>
#include <vector>

namespace detectionformats {
/**
 * \brief detectionformats eventtype conversion class
 *
 * The detectionformats eventtype class is a conversion class used to create,
 * parse, and validate eventtype data as part of detection  data.
 *
 */
class eventtype : public detectionbase {
 public:
	/**
	 * \brief eventtype constructor
	 *
	 * The constructor for the eventtype class.
	 * Initializes members to null values.
	 */
	eventtype();

	/**
	 * \brief eventtype advanced constructor
	 *
	 * The advanced constructor for the eventtype class.
	 * Initializes members to provided values.
	 *
	 * \param newtype - A std::string containing the event type to use
	 * \param newcertainty - A std::string containing the certainty to use
	 */
	eventtype(std::string newtype, std::string newcertainty);

	/**
	 * \brief eventtype advanced constructor
	 *
	 * The advanced constructor for the eventtype class.
	 * Converts the provided object from a rapidjson::Value, populating members
	 * \param json - A rapidjson::Value containing the parsed json.
	 */
	explicit eventtype(rapidjson::Value &json); // NOLINT

	/**
	 * \brief eventtype copy constructor
	 *
	 * The copy constructor for the eventtype class.
	 * Copies the provided object from a eventtype, populating members
	 * \param neweventtype - A eventtype.
	 */
	eventtype(const eventtype & neweventtype);

	/**
	 * \brief eventtype destructor
	 *
	 * The destructor for the eventtype class.
	 */
	~eventtype();

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
	 * \brief site autnor
	 *
	 * A required std::string containing the certainty for this eventtype.
	 */
	std::string certainty;
};
}  // namespace detectionformats
#endif  // DETECTION_EVENTTYPE_H
