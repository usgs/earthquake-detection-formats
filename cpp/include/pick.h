/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_PICK_H
#define DETECTION_PICK_H

#include <string>

#include "site.h"
#include "source.h"
#include "amplitude.h"
#include "filter.h"
#include "beam.h"
#include "associated.h"

namespace detectionformats {

/**
 * \brief detectionformats pick conversion class
 *
 * The detectionformats pick class is a conversion class used to create, parse,
 * and validate the unassociated pick data format pick.  The pick format uses
 * the JSON standard (www.json.org)
 *
 * pick is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * pick uses the Source and Site common objects.
 */
class pick: public detectionbase {
public:
	/**
	 * \brief pick constructor
	 *
	 * The constructor for the pick class.
	 * Initializes members to null values.
	 */
	pick();

	/**
	 * \brief pick advanced constructor
	 *
	 * The advanced constructor for the pick class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 * \param newtime - A double containing the new time to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 * \param newphase - A std::string containing the phase to use, empty
	 * string to omit
	 * \param newpolarity - A std::string containing the polarity to use,
	 * empty string to omit
	 * \param newonset - A std::string containing the onset to use, empty
	 * string to omit
	 * \param newpicker - A std::string containing the picker to use, empty
	 * string to omit
	 * \param newhighpass - A double containing the high pass to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlowpass - A double containing the low pass to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newamplitude - A double containing the amplitude to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newperiod - A double containing the period to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newsnr - A double containing the snr to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newbackazimuth - A double containing the back azimuth to use
	 * \param newbackazimutherror - A double containing the back azimuth error
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newslowness - A double containing the slowness to use
	 * \param newslownesserror - A double containing the slowness error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpowerratio - A double containing the powerratio to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpowerratioerror - A double containing the powerratio error to
	 * use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedphase - A std:string containing the associated
	 * phase to use, empty string to omit
	 * \param newassociateddistance - A double containing the associated
	 * distance to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedazimuth - A double containing the associated
	 * azimuth to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedresidual - A double containing the associated
	 * residual to use, -10000 to omit
	 * \param newassociatedsigma - A double containing the associated sigma
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 */
	pick(std::string newid, std::string newstation, std::string newchannel,
			std::string newnetwork, std::string newlocation, double newtime,
			std::string newagencyid, std::string newauthor,
			std::string newphase, std::string newpolarity, std::string newonset,
			std::string newpicker, double newhighpass, double newlowpass,
			double newamplitude, double newperiod, double newsnr,
			double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror, std::string newassociatedphase,
			double newassociateddistance, double newassociatedazimuth,
			double newassociatedresidual, double newassociatedsigma);

	/**
	 * \brief pick advanced constructor
	 *
	 * The advanced constructor for the pick class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 * \param newtime - A double containing the new time to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 * \param newphase - A std::string containing the phase to use, empty
	 * string to omit
	 * \param newpolarity - A std::string containing the polarity to use, empty
	 * string to omit
	 * \param newonset - A std::string containing the onset to use, empty string
	 * to omit
	 * \param newpicker - A std::string containing the picker to use, empty
	 * string to omit
	 * \param newhighpass - A double containing the high pass to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlowpass - A double containing the low pass to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newamplitude - A double containing the amplitude to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newperiod - A double containing the period to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newsnr - A double containing the snr to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newbackazimuth - A double containing the back azimuth to use
	 * \param newbackazimutherror - A double containing the back azimuth error
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newslowness - A double containing the slowness to use
	 * \param newslownesserror - A double containing the slowness error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpowerratio - A double containing the powerratio to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpowerratioerror - A double containing the powerratio error to
	 * use, std::numeric_limits<double>::quiet_NaN() to omit
	 */
	pick(std::string newid, std::string newstation, std::string newchannel,
			std::string newnetwork, std::string newlocation, double,
			std::string newagencyid, std::string newauthor,
			std::string newphase, std::string newpolarity, std::string newonset,
			std::string newpicker, double newhighpass, double newlowpass,
			double newamplitude, double newperiod, double newsnr,
			double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror);

	/**
	 * \brief pick alternate advanced constructor
	 *
	 * The alternate advanced constructor for the pick class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newtime - A double containing the new time to use
	 * \param newsource - A detectionformats::source containing the source to
	 * use
	 * \param newphase - A std::string containing the phase to use, empty string
	 * to omit
	 * \param newpolarity - A std::string containing the polarity to use, empty
	 * string to omit
	 * \param newonset - A std::string containing the onset to use, empty string
	 * to omit
	 * \param newpicker - A std::string containing the picker to use, empty
	 * string to omit
	 * \param newfilterdata -A std::vector<detectionformats::filter> containing
	 * the filters that were used
	 * \param newamplitude - A detectionformats::amplitude containing the
	 * amplitude to use
	 * \param newbeam - A detectionformats::beam containing the beam to use
	 */
	pick(std::string newid, detectionformats::site newsite, double newtime,
			detectionformats::source newsource, std::string newphase,
			std::string newpolarity, std::string newonset,
			std::string newpicker,
			std::vector<detectionformats::filter> newfilterdata,
			detectionformats::amplitude newamplitude,
			detectionformats::beam newbeam);

	/**
	 * \brief pick alternate advanced constructor
	 *
	 * The alternate advanced constructor for the pick class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newtime - A double containing the new time to use
	 * \param newsource - A detectionformats::source containing the source to
	 * use
	 * \param newphase - A std::string containing the phase to use, empty string
	 * to omit
	 * \param newpolarity - A std::string containing the polarity to use, empty
	 * string to omit
	 * \param newonset - A std::string containing the onset to use, empty string
	 * to omit
	 * \param newpicker - A std::string containing the picker to use, empty
	 * string to omit
	 * \param newfilterdata -A std::vector<detectionformats::filter> containing
	 * the filters that were used
	 * \param newamplitude - A detectionformats::amplitude containing the the
	 * amplitude to use
	 * \param newbeam - A detectionformats::beam containing the beam to use
	 * \param newassociated - A detectionformats::associated containing the
	 * associated to use
	 */
	pick(std::string newid, detectionformats::site newsite, double newtime,
			detectionformats::source newsource, std::string newphase,
			std::string newpolarity, std::string newonset,
			std::string newpicker,
			std::vector<detectionformats::filter> newfilterdata,
			detectionformats::amplitude newamplitude,
			detectionformats::beam newbeam,
			detectionformats::associated newassociated);

	/**
	 * \brief pick advanced constructor
	 *
	 * The advanced constructor for the pick class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	pick(rapidjson::Value &json);

	/**
	 * \brief pick copy constructor
	 *
	 * The copy constructor for the pick class.
	 * Copys members from provided pick.
	 *
	 * \param newpick - A detectionformats::pick to copy from
	 */
	pick(const pick &newpick);

	/**
	 * \brief pick destructor
	 *
	 * The destructor for the pick class.
	 */
	 ~pick();

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
	 * \brief pick id
	 *
	 * A required std::string containing the id of this pick message
	 */
	std::string id;

	/**
	 * \brief pick site
	 *
	 * A required detectionformats::site containing the site for this pick
	 * message
	 */
	detectionformats::site site;

	/**
	 * \brief pick time
	 *
	 * A required double containing the time for this pick message
	 */
	double time;

	/**
	 * \brief pick source
	 *
	 * A required detectionformats::source containing the source for this pick
	 * message
	 */
	detectionformats::source source;

	/**
	 * \brief pick phase
	 *
	 * An optional std::string containing the phase for this pick message
	 */
	std::string phase;

	/**
	 * \brief pick polarity
	 *
	 * An optional std::string containing the polarity for this pick message
	 * valid values are "up" or "down"
	 */
	std::string polarity;

	/**
	 * \brief pick onset
	 *
	 * An optional std::string containing the onset for this pick message
	 * valid values are "impulsive", "emergent", or "questionable"
	 */
	std::string onset;

	/**
	 * \brief pick picker type
	 *
	 * An optional std::string defining the picker that made this pick message
	 * valid values are "manual", "raypicker", "filterpicker", "earthworm", or
	 * "other"
	 */
	std::string picker;

	/**
	 * \brief pick filter data
	 *
	 *An optional vector of detectionformats::filter objects containing the
	 *An filters for this pick message
	 */
	std::vector<detectionformats::filter> filterdata;

	/**
	 * \brief pick amplitude
	 *
	 * An optional detectionformats::amplitude containing the amplitude for this
	 * pick message
	 */
	detectionformats::amplitude amplitude;

	/**
	 * \brief pick beam
	 *
	 * An optional detectionformats::beam containing the beam information for
	 * this pick message
	 */
	detectionformats::beam beam;

	/**
	 * \brief pick associated
	 *
	 * Optional detectionformats::associated containing the associated
	 * information for this pick message
	 */
	detectionformats::associated associationinfo;

protected:

};
}
#endif
