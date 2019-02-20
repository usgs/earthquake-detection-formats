/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef STATION_INFO_H
#define STATION_INFO_H

#include <string>
#include <exception>
#include <vector>

#include "base.h" // NOLINT
#include "site.h" // NOLINT
#include "source.h" // NOLINT

namespace detectionformats {

/**
 * \brief detectionformats stationInfo conversion class
 *
 * The detectionformats stationInfo class is a conversion class used to create,
 * parse, and validate the stationInfo data format.  The stationInfo format uses
 * the JSON standard (www.json.org)
 *
 * stationInfo is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * stationInfo uses the Site and Source common objects.
 */
class stationInfo : public detectionbase {
 public:
	/**
	 * \brief stationInfo constructor
	 *
	 * The constructor for the stationInfo class.
	 * Initializes members to null values.
	 */
	stationInfo();

	/**
	 * \brief stationInfo advanced constructor
	 *
	 * The advanced constructor for the stationInfo class.
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
	 * \param newuse - A bool containing the use flag to use
	 * \param newuseforteleseismic - A bool containing the use for teleseismic
	 * to use
	 * \param newagencyid - A std::string containing the agencyid to use, empty
	 * string to omit
	 * \param newauthor - A std::string containing the author to use, empty
	 * string to omit
	 */
	stationInfo(std::string newstation, std::string newchannel,
				std::string newnetwork, std::string newlocation,
				double newlatitude, double newlongitude, double newelevation,
				double newquality, bool newenable, bool newuse,
				bool newuseforteleseismic, std::string newagencyid,
				std::string newauthor);

	/**
	 * \brief stationInfo alternate advanced constructor
	 *
	 * The alternate advanced constructor for the stationInfo class.
	 * Initializes members to provided values.
	 *
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newlatitude - A double containing the latitude to use
	 * \param newlongitude - A double containing the longitude to use
	 * \param newelevation - A double containing the elevation to use
	 * \param newquality - A double containing the quality to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newenable - A bool containing the enable flag to use
	 * \param newuse - A bool containing the use flag to use
	 * \param newuseforteleseismic - A bool containing the use for teleseismic
	 * to use
	 * \param newinformationrequestor - A detectionformats::source containing
	 * the information requestor to use
	 */
	stationInfo(detectionformats::site newsite, double newlatitude,
				double newlongitude, double newelevation, double newquality,
				bool newenable, bool newuse, bool newuseforteleseismic,
				detectionformats::source newinformationrequestor);

	/**
	 * \brief stationInfo advanced constructor
	 *
	 * The advanced constructor for the stationInfo class.
	 * Converts the provided object from a rapidjson::Value, populating members
	 * \param json - A rapidjson::Value containing the parsed json.
	 */
	explicit stationInfo(rapidjson::Value &json); // NOLINT

	/**
	 * \brief stationInfo copy constructor
	 *
	 * The copy constructor for the stationInfo class.
	 * Copies members from provided stationInfo.
	 *
	 * \param newstation - A detectionformats::stationInfo to copy from
	 */
	stationInfo(const stationInfo &newstation);

	/**
	 * \brief stationInfo destructor
	 *
	 * The destructor for the stationInfo class.
	 */
	~stationInfo();

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
	 * \brief stationInfo site
	 *
	 * A required detectionformats::site containing the site for this
	 * stationInfo message
	 */
	detectionformats::site site;

	/**
	 * \brief latitude value
	 *
	 * A required double defining the latitude of this stationInfo
	 */
	double latitude;

	/**
	 * \brief longitude value
	 *
	 * A required double defining the longitude of this stationInfo
	 */
	double longitude;

	/**
	 * \brief elevation value
	 *
	 * A required double containing the elevation for this stationInfo
	 */
	double elevation;

	/**
	 * \brief quality value
	 *
	 * An optional double containing the quality for this stationInfo
	 */
	double quality;

	/**
	 * \brief enable value
	 *
	 * An optional bool containing the enable flag for this stationInfo
	 */
	bool enable;

	/**
	 * \brief use value
	 *
	 * An optional bool containing the use flag for this stationInfo
	 */
	bool use;

	/**
	 * \brief use for teleseismic value
	 *
	 * An optional bool containing the use for teleseismic flag for this
	 * stationInfo
	 */
	bool useforteleseismic;

	/**
	 * \brief pick requestor
	 *
	 * An optional detectionformats::source containing the requestor for this
	 * stationInfo
	 */
	detectionformats::source informationRequestor;
};
}  // namespace detectionformats
#endif  // STATION_INFO_H
