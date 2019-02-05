/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef STATION_INFO_REQUEST_H
#define STATION_INFO_REQUEST_H

#include <site.h>
#include <source.h>

#include <string>
#include <exception>
#include <vector>

namespace detectionformats {

/**
 * \brief detectionformats stationInfoRequest conversion class
 *
 * The detectionformats stationInfoRequest class is a conversion class used to
 * create, parse, and validate station information requests.  The
 * stationInfoRequest format uses the JSON standard (www.json.org)
 *
 * stationInfoRequest is intended for use by seismic applications requesting
 * station information from a station information data service or services.
 *
 * stationInfoReqest uses the Site and Source common objects.
 */
class stationInfoRequest : public detectionbase {
 public:
	/**
	 * \brief stationInfo constructor
	 *
	 * The constructor for the stationInfoReqest class.
	 * Initializes members to null values.
	 */
	stationInfoRequest();

	/**
	 * \brief stationInfoRequest advanced constructor
	 *
	 * The advanced constructor for the stationInfoRequest class.
	 * Initializes members to provided values.
	 *
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 */
	stationInfoRequest(std::string newstation, std::string newchannel,
						std::string newnetwork, std::string newlocation,
						std::string newagencyid, std::string newauthor);

	/**
	 * \brief stationInfoRequest alternate advanced constructor
	 *
	 * The alternate advanced constructor for the stationInfoRequest class.
	 * Initializes members to provided values.
	 *
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newsource - A detectionformats::source containing the source to
	 * use
	 */
	stationInfoRequest(detectionformats::site newsite,
						detectionformats::source newsource);

	/**
	 * \brief stationInfoRequest advanced constructor
	 *
	 * The advanced constructor for the stationInfoRequest class.
	 * Converts the provided object from a rapidjson::Value, populating members
	 * \param json - A rapidjson::Value containing the parsed json.
	 */
	explicit stationInfoRequest(rapidjson::Value &json); // NOLINT

	/**
	 * \brief stationInfoRequest copy constructor
	 *
	 * The copy constructor for the stationInfoRequest class.
	 * Copies members from provided stationInfoRequest.
	 *
	 * \param newstation - A detectionformats::stationInfo to copy from
	 */
	stationInfoRequest(const stationInfoRequest &newstation);

	/**
	 * \brief stationInfoRequest destructor
	 *
	 * The destructor for the stationInfoRequest class.
	 */
	~stationInfoRequest();

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
	 * \brief stationInfoRequest site
	 *
	 * A required detectionformats::site containing the site for this
	 * stationInfoRequest message
	 */
	detectionformats::site site;

	/**
	 * \brief stationInfoRequest source
	 *
	 * A required detectionformats::source containing the source for this
	 * stationInfoRequest message
	 */
	detectionformats::source source;
};
}  // namespace detectionformats
#endif  // STATION_INFO_REQUEST_H
