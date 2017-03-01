/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef STATION_PICK_H
#define STATION_PICK_H

#include <string>

#include "site.h"

namespace detectionformats {

/**
 * \brief detectionformats station conversion class
 *
 * The detectionformats station class is a conversion class used to create,
 * parse, and validate the station data format.  The station format uses
 * the JSON standard (www.json.org)
 *
 * station is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * station uses the Site common object.
 */
class station: public detectionbase {
public:
	/**
	 * \brief station constructor
	 *
	 * The constructor for the station class.
	 * Initializes members to null values.
	 */
	station();

	/**
	 * \brief station advanced constructor
	 *
	 * The advanced constructor for the station class.
	 * Initializes members to provided values.
	 *
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 * \param newlatitude - A double containing the latitude to use
	 * \param newlongitude - A double containing the longitude to use
	 * \param newelevation - A double containing the elevation to use
	 * \param newquality - A double containing the quality to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newenable - A bool containing the enable flag to use
	 * \param newuseforteleseismic - A bool containing the use for teleseismic
	 * to use
	 */
	station(std::string newstation, std::string newchannel,
			std::string newnetwork, std::string newlocation, double newlatitude,
			double newlongitude, double newelevation, double newquality,
			bool newenable, bool newuseforteleseismic);

	/**
	 * \brief station alternate advanced constructor
	 *
	 * The alternate advanced constructor for the station class.
	 * Initializes members to provided values.
	 *
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newlatitude - A double containing the latitude to use
	 * \param newlongitude - A double containing the longitude to use
	 * \param newelevation - A double containing the elevation to use
	 * \param newquality - A double containing the quality to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newenable - A bool containing the enable flag to use
	 * \param newuseforteleseismic - A bool containing the use for teleseismic
	 * to use
	 */
	station(detectionformats::site newsite, double newlatitude,
			double newlongitude, double newelevation, double newquality,
			bool newenable, bool newuseforteleseismic);

	/**
	 * \brief station advanced constructor
	 *
	 * The advanced constructor for the station class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	station(rapidjson::Value &json);

	/**
	 * \brief station copy constructor
	 *
	 * The copy constructor for the station class.
	 * Copys members from provided station.
	 *
	 * \param newstation - A detectionformats::station to copy from
	 */
	station(const station &newstation);

	/**
	 * \brief station destructor
	 *
	 * The destructor for the station class.
	 */
	~station();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \return Returns a json::Object containing the class contents
	 */
	virtual rapidjson::Value & tojson(rapidjson::Value &json,
			rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator)
					override;

	/**
	 * \brief Gets any errors in the class
	 *
	 * Gets any formatting errors in the class
	 * \return Returns a std::vector<std::string> containing the errors
	 */
	virtual std::vector<std::string> geterrors() override;

	/**
	 * \brief station site
	 *
	 * A required detectionformats::site containing the site for this station
	 * message
	 */
	detectionformats::site site;

	/**
	 * \brief latitude value
	 *
	 * A required double defining the latitude of this station
	 */
	double latitude;

	/**
	 * \brief longitude value
	 *
	 * A required double defining the longitude of this station
	 */
	double longitude;

	/**
	 * \brief elevation value
	 *
	 * A required double containing the elevation for this station
	 */
	double elevation;

	/**
	 * \brief quality value
	 *
	 * An optional double containing the quality for this station
	 */
	double quality;

	/**
	 * \brief quality value
	 *
	 * An optional bool containing the enable flag for this station
	 */
	bool enable;

	/**
	 * \brief use for teleseismic value
	 *
	 * An optional bool containing the use for teleseismic flag for this station
	 */
	bool useforteleseismic;

protected:

};
}
#endif
