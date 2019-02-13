/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_RETRACT_H
#define DETECTION_RETRACT_H

#include <string>
#include <vector>

#include "base.h" // NOLINT
#include "source.h" // NOLINT

namespace detectionformats {
/**
 * \brief detectionformats retract conversion class
 *
 * The detectionformats retract class is a conversion class used to create, parse, and
 * validate the event retraction data format retract.  The retract format uses
 * the JSON standard (www.json.org)
 *
 * retract is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * retract uses the Source common object.
 */
class retract : public detectionbase {
 public:
	/**
	 * \brief retract constructor
	 *
	 * The constructor for the retract class.
	 * Initializes members to null values.
	 */
	retract();

	/**
	 * \brief retract advanced constructor
	 *
	 * The advanced constructor for the retract class.
	 * Initializes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 */
	retract(std::string newid, std::string newagencyid, std::string newauthor);

	/**
	 * \brief retract alternate advanced constructor
	 *
	 * The alternate advanced constructor for the retract class.
	 * Initializes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsource - A detectionformats::source containing the source to use
	 */
	retract(std::string newid, detectionformats::source newsource);

	/**
	 * \brief retract advanced constructor
	 *
	 * The advanced constructor for the retract class.
	 * Converts the provided object from a rapidjson::Value, populating members
	 * \param json - A rapidjson::Value containing the parsed json.
	 */
	explicit retract(rapidjson::Value &json); // NOLINT

	/**
	 * \brief retract copy constructor
	 *
	 * The retract constructor for the retract class.
	 * Copies the provided object from a retract, populating members
	 * \param newretract - A retract.
	 */
	retract(const retract & newretract);

	/**
	 * \brief retract destructor
	 *
	 * The destructor for the retract class.
	 */
	~retract();

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
	 * \brief origin id
	 *
	 * A required std::string containing the id of this origin message
	 */
	std::string id;

	/**
	 * \brief origin source
	 *
	 * A required detectionformats::site containing the site for this origin message
	 */
	detectionformats::source source;
};
}  // namespace detectionformats
#endif  // DETECTION_RETRACT_H
