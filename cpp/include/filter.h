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

#include "base.h"

namespace detectionformats
{
	/**
	* \brief detectionformats filter conversion class
	*
	* The detectionformats filter class is a conversion class used to create, parse, and
	* validate filter data as part of detectionformats data.
	*
	*/
	class filter : public detectionbase
	{
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
		* Initilizes members to provided values.
		*
		* \param newhighpass - A double containing the high pass to use, std::numeric_limits<double>::quiet_NaN() to omit
		* \param newlowpass - A double containing the low pass to use, std::numeric_limits<double>::quiet_NaN() to omit
		*/
		filter(double newhighpass, double newlowpass);

		/**
		* \brief filter advanced constructor
		*
		* The advanced constructor for the filter class.
		* Converts the provided object from a json::Object, populating members
		* \param jsondocument - A json document.
		*/
		filter(rapidjson::Value &json);

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
		* \param jsondocument - a reference to the json document to fill in with the class contents.
		* \return Returns rapidjson::Value & if successful
		*/
		virtual rapidjson::Value & tojson(rapidjson::Value &json, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) override;

		/**
		* \brief Gets any errors in the class
		*
		* Gets any formatting errors in the class
		* \return Returns a std::vector<std::string> containing the errors
		*/
		virtual std::vector<std::string> geterrors() override;

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
	};
}
#endif
