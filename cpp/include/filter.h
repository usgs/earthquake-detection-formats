/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_FILTER_H
#define DETECTION_FILTER_H

#include <string>
#include <exception>
#include <vector>

#include "base.h" // NOLINT

namespace detectionformats {
/**
 * \brief detectionformats filter conversion class
 *
 * The detectionformats filter class is a conversion class used to create, parse, and
 * validate filter data as part of detectionformats data.
 *
 */
class filter : public detectionbase {
 public:
	/**
	 * \brief filter constructor
	 *
	 * The constructor for the filter class.
	 * Initilizes members to null values.
	 */
	filter();

	/**
	 * \brief filter advanced constructor
	 *
	 * The advanced constructor for the filter class.
	 * Initializes members to provided values.
	 *
	 * \param newtype - A std::string containing the filter type, empty string
	 * to omit, if not defined, type is assumed to be bandpass
	 * \param newhighpass - A double containing the high pass to use, 
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlowpass - A double containing the low pass to use, 
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newunits - A std::string containing the filter units, empty string
	 * to omit, if not defined, units is assumed to be hertz
	 */
	filter(std::string newtype, double newhighpass, double newlowpass,
		std::string newunits);

	/**
	 * \brief filter advanced constructor
	 *
	 * The advanced constructor for the filter class.
	 * Converts the provided object from a rapidjson::Value, populating members
	 * \param json - A rapidjson::Value containing the parsed json.
	 */
	explicit filter(rapidjson::Value &json); // NOLINT

	/**
	 * \brief filter copy constructor
	 *
	 * The copy constructor for the filter class.
	 * Copies the provided object from a filter, populating members
	 * \param newfilter - A filter.
	 */
	filter(const filter & newfilter);

	/**
	 * \brief filter destructor
	 *
	 * The destructor for the filter class.
	 */
	~filter();

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
	 * \brief filter highpass
	 *
	 * An optional double containing the filter highpass
	 */
	double highpass;

	/**
	 * \brief filter lowpass
	 *
	 * An optional double containing the filter lowpass
	 */
	double lowpass;

	/**
	 * \brief filter units
	 *
	 * An optional std::string containing the filter units, if not specified, it
	 * is assumed to be "Hertz"
	 */
	std::string units;
};
}  // namespace detectionformats
#endif  // DETECTION_FILTER_H
