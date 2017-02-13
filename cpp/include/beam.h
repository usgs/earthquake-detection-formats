/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_BEAM_H
#define DETECTION_BEAM_H

#include <string>

#include "site.h"
#include "source.h"
#include "associated.h"

namespace detectionformats {

/**
 * \brief detectionformats beam conversion class
 *
 * The detectionformats beam class is a conversion class used to create, parse,
 * and validate the unassociated beam data format beam.  The beam format uses
 * the JSON standard (www.json.org)
 *
 * beam is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * beam uses the Source and Site common objects.
 */
class beam: public detectionbase {
public:
	/**
	 * \brief beam constructor
	 *
	 * The constructor for the beam class.
	 * Initilizes members to null values.
	 */
	beam();

	/**
	 * \brief beam advanced constructor
	 *
	 * The advanced constructor for the beam class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsiteid - A std::string containing the siteid to use
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 * \param newstarttime - A double containing the new start time to use
	 * \param newendtime - A double containing the new end time to use
	 * \param newbackazimuth - A double containing the back azimuth to use
	 * \param newbackazimutherror - A double containing the back azimuth error
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newslowness - A double containing the slowness to use
	 * \param newslownesserror - A double containing the slowness error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpowerratio - A double containing the powerratio to use
	 * \param newpowerratioerror - A double containing the powerratio error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 */
	beam(std::string newid, std::string newsiteid, std::string newstation,
			std::string newchannel, std::string newnetwork,
			std::string newlocation, std::string newagencyid,
			std::string newauthor, double newstarttime, double newendtime,
			double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror);

	/**
	 * \brief beam advanced constructor
	 *
	 * The advanced constructor for the beam class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsiteid - A std::string containing the siteid to use
	 * \param newstation - A std::string containing the station to use
	 * \param newchannel - A std::string containing the channel to use
	 * \param newnetwork - A std::string containing the network to use
	 * \param newlocation - A std::string containing the location to use
	 * \param newagencyid - A std::string containing the agencyid to use
	 * \param newauthor - A std::string containing the author to use
	 * \param newstarttime - A double containing the new start time to use
	 * \param newendtime - A double containing the new end time to use
	 * \param newbackazimuth - A double containing the back azimuth to use
	 * \param newbackazimutherror - A double containing the back azimuth error
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newslowness - A double containing the slowness to use
	 * \param newslownesserror - A double containing the slowness error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpowerratio - A double containing the powerratio to use
	 * \param newpowerratioerror - A double containing the powerratio error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedphase - A std:string containing the associated phase
	 * to use, empty string to omit
	 * \param newassociateddistance - A double containing the associated
	 * distance to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedazimuth - A double containing the associated azimuth
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedresidual - A double containing the associated
	 * residual to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociatedsigma - A double containing the associated sigma to
	 * use, std::numeric_limits<double>::quiet_NaN() to omit
	 */
	beam(std::string newid, std::string newsiteid, std::string newstation,
			std::string newchannel, std::string newnetwork,
			std::string newlocation, std::string newagencyid,
			std::string newauthor, double newstarttime, double newendtime,
			double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror,  std::string newassociatedphase,
			double newassociateddistance, double newassociatedazimuth,
			double newassociatedresidual, double newassociatedsigma);

	/**
	 * \brief beam alternate advanced constructor
	 *
	 * The alternate advanced constructor for the beam class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newsource - A detectionformats::source containing the source to
	 * use
	 * \param newstarttime - A double containing the new start time to use
	 * \param newendtime - A double containing the new end time to use
	 * \param newbackazimuth - A double containing the back azimuth to use
	 * \param newbackazimutherror - A double containing the back azimuth error
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newslowness - A double containing the slowness to use
	 * \param newslownesserror - A double containing the slowness error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpowerratio - A double containing the powerratio to use
	 * \param newpowerratioerror - A double containing the powerratio error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 */
	beam(std::string newid, detectionformats::site newsite,
			detectionformats::source newsource, double newstarttime,
			double newendtime, double newbackazimuth,
			double newbackazimutherror, double newslowness,
			double newslownesserror, double newpowerratio, double newpowerratioerror);

	/**
	 * \brief beam alternate advanced constructor
	 *
	 * The alternate advanced constructor for the beam class.
	 * Initilizes members to provided values.
	 *
	 * \param newid - A std::string containing the id to use
	 * \param newsite - A detectionformats::site containing the site to use
	 * \param newsource - A detectionformats::source containing the source to
	 * use
	 * \param newstarttime - A double containing the new start time to use
	 * \param newendtime - A double containing the new end time to use
	 * \param newbackazimuth - A double containing the back azimuth to use
	 * \param newbackazimutherror - A double containing the back azimuth error
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newslowness - A double containing the slowness to use
	 * \param newslownesserror - A double containing the slowness error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newpowerratio - A double containing the powerratio to use
	 * \param newpowerratioerror - A double containing the powerratio error to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociated - A detectionformats::associated containing the
	 * associated to use
	 */
	beam(std::string newid, detectionformats::site newsite,
			detectionformats::source newsource, double newstarttime,
			double newendtime, double newbackazimuth,
			double newbackazimutherror, double newslowness,
			double newslownesserror, double newpowerratio, double newpowerratioerror,
			detectionformats::associated newassociated);

	/**
	 * \brief beam advanced constructor
	 *
	 * The advanced constructor for the beam class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	beam(rapidjson::Value &json);

	/**
	 * \brief beam copy constructor
	 *
	 * The copy constructor for the beam class.
	 * Copys members from provided beam.
	 *
	 * \param newbeam - A detectionformats::beam to copy from
	 */
	beam(const beam &newbeam);

	/**
	 * \brief beam destructor
	 *
	 * The destructor for the beam class.
	 */
	~beam();

	/**
	 * \brief Convert to json object function
	 *
	 * Converts the contents of the class to a json object
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
	 * \brief beam id
	 *
	 * A required std::string containing the id of this beam message
	 */
	std::string id;

	/**
	 * \brief beam site
	 *
	 * A required detectionformats::site containing the site for this beam
	 * message
	 */
	detectionformats::site site;

	/**
	 * \brief beam source
	 *
	 * A required detectionformats::source containing the source for this beam
	 * message
	 */
	detectionformats::source source;

	/**
	 * \brief beam start time
	 *
	 * A required double containing the starting time for this beam message
	 */
	double starttime;

	/**
	 * \brief beam end time
	 *
	 * A required double containing the ending time for this beam message
	 */
	double endtime;

	/**
	 * \brief beam back azimuth
	 *
	 * A required double defining the beam back azimuth for this beam message
	 */
	double backazimuth;

	/**
	 * \brief beam back azimuth error value
	 *
	 * An optional double defining the back azimuth error of this beam message
	 */
	double backazimutherror;

	/**
	 * \brief beam slowness
	 *
	 * A required double defining the slowness of this beam message
	 */
	double slowness;

	/**
	 * \brief beam slowness error value
	 *
	 * An optional double defining the slowness error of this beam message
	 */
	double slownesserror;

	/**
	 * \brief beam powerratio
	 *
	 * A required double defining the powerratio of this beam message
	 */
	double powerratio;

	/**
	 * \brief beam powerratio error value
	 *
	 * An optional double defining the powerratio error of this beam message
	 */
	double powerratioerror;

	/**
	 * \brief beam associated
	 *
	 * Optional detectionformats::associated containing the associated
	 * information for this beam message
	 */
	detectionformats::associated associationinfo;

protected:

};
}
#endif
