/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_SITE_H
#define DETECTION_SITE_H

#include <string>
#include <exception>

#include "base.h"

namespace detectionformats {
/**
 * \brief detectionformats site conversion class
 *
 * The detectionformats site class is a conversion class used to create, parse,
 * and validate site data as part of detection data.
 *
 */
class site: public detectionbase {
public:
	/**
	 * \brief site constructor
	 *
	 * The constructor for the site class.
	 * Initilizes members to null values.
	 */
	site();

	/**
	 * \brief site advanced constructor
	 *
	 * The advanced constructor for the source class.
	 * Initilizes members to provided values.
	 *
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 */
	site(std::string newstation, std::string newchannel, std::string newnetwork,
			std::string newlocation);

	/**
	 * \brief site advanced constructor
	 *
	 * The advanced constructor for the site class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	site(rapidjson::Value &json);

	/**
	 * \brief site copy constructor
	 *
	 * The copy constructor for the site class.
	 * Copies the provided object from a site, populating members
	 * \param newsite - A site.
	 */
	site(const site & newsite);

	/**
	 * \brief site destructor
	 *
	 * The destructor for the site class.
	 */
	~site();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
	 * \param jsondocument - a reference to the json document to fill in with
	 * the class contents.
	 * \return Returns rapidjson::Value & if successful
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
	 * \brief site station code
	 *
	 * A required std::string containing the station code for this site.
	 */
	std::string station;

	/**
	 * \brief site channel code
	 *
	 * An optional std::string containing the channel code for this site.
	 */
	std::string channel;

	/**
	 * \brief site network code
	 *
	 * A required std::string containing the network code for this site.
	 */
	std::string network;

	/**
	 * \brief site location code
	 *
	 * An optional std::string containing the location code for this site.
	 */
	std::string location;
};
}
#endif
