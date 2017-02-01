/*****************************************
* This file is documented for Doxygen.
* If you modify this file please update
* the comments so that Doxygen will still
* be able to work.
****************************************/
#ifndef DETECTION_AMPLITUDE_H
#define DETECTION_AMPLITUDE_H

#include <string>
#include <exception>

#include "base.h"

namespace detectionformats
{
	/**
	* \brief detectionformats amplitude conversion class
	*
	* The detectionformats amplitude class is a conversion class used to create, parse, and
	* validate amplitude data as part of detectionformats data.
	*
	*/
	class amplitude : public detectionbase
	{
	public:
		/**
		* \brief amplitude constructor
		*
		* The constructor for the amplitude class.
		* Initilizes members to null values.
		*/
		amplitude();

		/**
		* \brief amplitude advanced constructor
		*
		* The advanced constructor for the amplitude class.
		* Initilizes members to provided values.
		*
		* \param newampvalue - A double containing the amp value to use, std::numeric_limits<double>::quiet_NaN() to omit
		* \param newperiod - A double containing the period to use, std::numeric_limits<double>::quiet_NaN() to omit
		* \param newsnr - A double containing the snr to use, std::numeric_limits<double>::quiet_NaN() to omit
		*/
		amplitude(double newampvalue, double newperiod, double newsnr);

		/**
		* \brief amplitude advanced constructor
		*
		* The advanced constructor for the amplitude class.
		* Converts the provided object from a json::Object, populating members
		* \param jsondocument - A json document.
		*/
		amplitude(rapidjson::Value &json);

		/**
		* \brief amplitude copy constructor
		*
		* The copy constructor for the amplitude class.
		* Copies the provided object from a amplitude, populating members
		* \param newamplitude - A amplitude.
		*/
		amplitude(const amplitude & newamplitude);

		/**
		* \brief amplitude destructor
		*
		* The destructor for the amplitude class.
		*/
		~amplitude();

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
		* \brief amplitude ampvalue
		*
		* An optional double containing the amplitude ampvalue
		*/
		double ampvalue;

		/**
		* \brief amplitude period
		*
		* An optional double containing the amplitude period
		*/
		double period;

		/**
		* \brief amplitude snr
		*
		* An optional double containing the amplitude snr
		*/
		double snr;
	};
}
#endif
