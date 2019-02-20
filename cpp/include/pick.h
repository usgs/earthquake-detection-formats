/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_PICK_H
#define DETECTION_PICK_H

#include <string>
#include <vector>

#include "base.h" // NOLINT
#include "site.h" // NOLINT
#include "source.h" // NOLINT
#include "amplitude.h" // NOLINT
#include "filter.h" // NOLINT
#include "beam.h" // NOLINT
#include "association.h" // NOLINT
#include "classification.h" // NOLINT

namespace detectionformats {

/**
 * \brief detectionformats pick conversion class
 *
 * The detectionformats pick class is a conversion class used to create, parse,
 * and validate the pick data format.  The pick format uses the JSON standard 
 * (www.json.org)
 *
 * pick is intended for use in seismic data messaging between seismic
 * applications and organizations.
 *
 * pick uses the Source and Site common objects.
 */
class pick : public detectionbase {
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
	 * Initializes members to provided values.
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
	 * \param newfiltertype - A std::string containing the filter type, empty 
	 * string to omit, if not defined, type is assumed to be bandpass
	 * \param newhighpass - A double containing the high pass to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlowpass - A double containing the low pass to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newfilterunits - A std::string containing the filter units, empty
	 * string to omit, if not defined, units is assumed to be hertz
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
	 * \param newassociationphase - A std:string containing the association
	 * phase to use, empty string to omit
	 * \param newassociationdistance - A double containing the association
	 * distance to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociationazimuth - A double containing the association
	 * azimuth to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newassociationresidual - A double containing the association
	 * residual to use, -10000 to omit
	 * \param newassociationsigma - A double containing the association sigma
	 * to use, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newclassificationphase - A std::string containing the phase name 
	 * to use, empty string to omit
     * \param newclassificationphaseprob - A double containing the probability 
     * of the phase estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newclassificationdistance - A double containing the distance to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newclassificationdistanceprob - A double containing the 
     * probability of the distance estimate, 
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newclassificationazimuth - A double containing the azimuth to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newclassificationazimuthprob - A double containing the probability 
	 * of the azimuth estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newclassificationmagnitude - A double containing the magnitude to 
	 * use, std::numeric_limits<double>::quiet_NaN() to omit
     * \param newclassificationmagtype - A std::string containing the magnitude 
	 * type to use, empty string to omit
     * \param newclassificationmagprob - A double containing the probability of 
	 * the magnitude estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newclassificationdepth - A double containing the depth to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newclassificationdepthprob - A double containing the probability 
	 * of the depth estimate, std::numeric_limits<double>::quiet_NaN() to omit
     * \param newclassificationeventtype - A std::string containing the event 
	 * type to use, empty string to omit
	 * \param newclassificationeventtypecertainty - A std::string containing the 
	 * event type certainty to use, empty string to omit
     * \param newclassificationeventtypeprob - A double containing the 
	 * probability of the event type estimate, 
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newclassificationagencyid - A std::string containing the 
	 * classifying algorithm agencyid to use, empty string to omit
     * \param newclassificationauthor - A std::string containing the classifying 
	 * algorithm author to use, empty string to omit
	 */
	pick(std::string newid, std::string newstation, std::string newchannel,
			std::string newnetwork, std::string newlocation, double newtime,
			std::string newagencyid, std::string newauthor,
			std::string newphase, std::string newpolarity, std::string newonset,
			std::string newpicker, std::string newfiltertype, double newhighpass,
			double newlowpass, std::string newfilterunits,
			double newamplitude, double newperiod, double newsnr,
			double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror, std::string newassociationphase,
			double newassociationdistance, double newassociationazimuth,
			double newassociationresidual, double newassociationsigma,
			std::string newclassificationphase, double newclassificationphaseprob,
            double newclassificationdistance,
			double newclassificationdistanceprob,
			double newclassificationazimuth, double newclassificationazimuthprob,
			double newclassificationmagnitude, std::string newclassificationmagtype,
            double newclassificationmagprob, double newclassificationdepth,
			double newclassificationdepthprob,
			std::string newclassificationeventtype,
			std::string newclassificationeventtypecertainty,
            double newclassificationeventtypeprob,
			std::string newclassificationagencyid,
            std::string newclassificationauthor);

	/**
	 * \brief pick advanced constructor
	 *
	 * The advanced constructor for the pick class.
	 * Initializes members to provided values.
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
	 * \param newfiltertype - A std::string containing the filter type, empty 
	 * string to omit, if not defined, type is assumed to be bandpass
	 * \param newhighpass - A double containing the high pass to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newlowpass - A double containing the low pass to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newfilterunits - A std::string containing the filter units, empty
	 * string to omit, if not defined, units is assumed to be hertz
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
			std::string newnetwork, std::string newlocation, double newtime,
			std::string newagencyid, std::string newauthor,
			std::string newphase, std::string newpolarity, std::string newonset,
			std::string newpicker, std::string newfiltertype, double newhighpass,
			double newlowpass, std::string newfilterunits,
			double newamplitude, double newperiod, double newsnr,
			double newbackazimuth, double newbackazimutherror,
			double newslowness, double newslownesserror, double newpowerratio,
			double newpowerratioerror);

	/**
	 * \brief pick alternate advanced constructor
	 *
	 * The alternate advanced constructor for the pick class.
	 * Initializes members to provided values.
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
	 * Initializes members to provided values.
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
	 * \param newclassification - A detectionformats::classification containing 
	 * the classification info to use
	 */
	pick(std::string newid, detectionformats::site newsite, double newtime,
			detectionformats::source newsource, std::string newphase,
			std::string newpolarity, std::string newonset,
			std::string newpicker,
			std::vector<detectionformats::filter> newfilterdata,
			detectionformats::amplitude newamplitude,
			detectionformats::beam newbeam,
			detectionformats::classification newclassification);

	/**
	 * \brief pick alternate advanced constructor
	 *
	 * The alternate advanced constructor for the pick class.
	 * Initializes members to provided values.
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
	 * \param newassociation - A detectionformats::association containing the
	 * association info to use
	 */
	pick(std::string newid, detectionformats::site newsite, double newtime,
			detectionformats::source newsource, std::string newphase,
			std::string newpolarity, std::string newonset,
			std::string newpicker,
			std::vector<detectionformats::filter> newfilterdata,
			detectionformats::amplitude newamplitude,
			detectionformats::beam newbeam,
			detectionformats::association newassociation);

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
	 * \param newassociation - A detectionformats::association containing the
	 * association info to use
	 * \param newclassification - A detectionformats::classification containing 
	 * the classification info to use
	 */
	pick(std::string newid, detectionformats::site newsite, double newtime,
			detectionformats::source newsource, std::string newphase,
			std::string newpolarity, std::string newonset,
			std::string newpicker,
			std::vector<detectionformats::filter> newfilterdata,
			detectionformats::amplitude newamplitude,
			detectionformats::beam newbeam,
			detectionformats::association newassociation,
			detectionformats::classification newclassification);

	/**
	 * \brief pick advanced constructor
	 *
	 * The advanced constructor for the pick class.
	 * Converts the provided object from a rapidjson::Value, populating members
	 * \param json - A rapidjson::Value containing the parsed json.
	 */
	explicit pick(rapidjson::Value &json); // NOLINT

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
	 * valid values are >up> or >down>
	 */
	std::string polarity;

	/**
	 * \brief pick onset
	 *
	 * An optional std::string containing the onset for this pick message
	 * valid values are >impulsive>, >emergent>, or >questionable>
	 */
	std::string onset;

	/**
	 * \brief pick picker type
	 *
	 * An optional std::string defining the picker that made this pick message
	 * valid values are >manual>, >raypicker>, >filterpicker>, >earthworm>, or
	 * >other>
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
	 * \brief pick association info
	 *
	 * Optional detectionformats::association containing the association
	 * information for this pick message
	 */
	detectionformats::association associationinfo;

	/**
	 * \brief pick classification info
	 *
	 * Optional detectionformats::classification containing the classification
	 * information for this pick message
	 */
	detectionformats::classification classificationinfo;
};
}  // namespace detectionformats
#endif  // DETECTION_PICK_H
