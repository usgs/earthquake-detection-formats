/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_BEAM_H
#define DETECTION_BEAM_H

#include <site.h>
#include <source.h>

#include <string>
#include <vector>

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
class beam : public detectionbase {
 public:
	/**
	 * \brief beam constructor
	 *
	 * The constructor for the beam class.
	 * Initializes members to null values.
	 */
	beam();

	/**
	 * \brief beam advanced constructor
	 *
	 * The advanced constructor for the beam class.
	 * Initilizes members to provided values.
	 *
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
	beam(double newbackazimuth, double newbackazimutherror, double newslowness,
			double newslownesserror, double newpowerratio,
			double newpowerratioerror);

	/**
	 * \brief beam advanced constructor
	 *
	 * The advanced constructor for the beam class.
	 * Converts the provided object from a json::Object, populating members
	 * \param jsondocument - A json document.
	 */
	explicit beam(rapidjson::Value &json); // NOLINT

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
	 * An optional double defining the powerratio of this beam message
	 */
	double powerratio;

	/**
	 * \brief beam powerratio error value
	 *
	 * An optional double defining the powerratio error of this beam message
	 */
	double powerratioerror;
};
}  // namespace detectionformats
#endif  // DETECTION_BEAM_H
