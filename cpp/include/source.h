/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_SOURCE_H
#define DETECTION_SOURCE_H

#include <base.h>

#include <string>
#include <exception>
#include <vector>

namespace detectionformats {
/**
 * \brief detectionformats source conversion class
 *
 * The detectionformats source class is a conversion class used to create,
 * parse, and validate source data as part of detection  data.
 *
 */
class source : public detectionbase {
 public:
	/**
	 * \brief source constructor
	 *
	 * The constructor for the source class.
	 * Initilizes members to null values.
	 */
	source();

	/**
	 * \brief source advanced constructor
	 *
	 * The advanced constructor for the source class.
	 * Initilizes members to provided values.
	 *
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 */
	source(std::string newagencyid, std::string newauthor);

	/**
	 * \brief source advanced constructor
	 *
	 * The advanced constructor for the source class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	explicit source(rapidjson::Value &json); // NOLINT

	/**
	 * \brief source copy constructor
	 *
	 * The copy constructor for the source class.
	 * Copies the provided object from a source, populating members
	 * \param newsource - A source.
	 */
	source(const source & newsource);

	/**
	 * \brief source destructor
	 *
	 * The destructor for the source class.
	 */
	~source();

	/**
	 * \brief Convert to json value function
	 *
	 * Converts the contents of the class to a json object
	 * \param jsondocument - a reference to the json document to fill in with
	 * 	the class contents.
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
	 * \brief source agency identifyer
	 *
	 * A required std::string containing an agency identifier for this source.
	 */
	std::string agencyid;

	/**
	 * \brief site autnor
	 *
	 * A required std::string containing the author for this source.
	 */
	std::string author;
};
}  // namespace detectionformats
#endif  // DETECTION_SOURCE_H
