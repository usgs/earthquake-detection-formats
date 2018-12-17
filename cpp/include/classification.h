/*****************************************
 * This file is documented for Doxygen.
 * If you modify this file please update
 * the comments so that Doxygen will still
 * be able to work.
 ****************************************/
#ifndef DETECTION_CLASSIFICATION_H
#define DETECTION_CLASSIFICATION_H

#include <base.h>
#include <eventtype.h>
#include <source.h>

#include <string>
#include <exception>
#include <vector>

namespace detectionformats {
/**
 * \brief detectionformats classification conversion class
 *
 * The detectionformats classification class is a conversion class used to create,
 * parse, and validate classification data as part of detectionformats data.
 *
 */
class classification : public detectionbase {
 public:
	/**
	 * \brief classification constructor
	 *
	 * The constructor for the classification class.
	 * Initializes members to null values.
	 */
	classification();

	/**
	 * \brief classification advanced constructor
	 *
	 * The advanced constructor for the classification class.
	 * Initializes members to provided values.
	 *
	 * \param newphase - A std::string containing the phase name to use, empty
	 * string to omit
     * \param newphaseprob - A double containing the probability of the phase
     * estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdistance - A double containing the distance to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newdistanceprob - A double containing the probability of the 
     * distance estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newazimuth - A double containing the azimuth to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newazimuthprob - A double containing the probability of the azimuth
     * estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newmagnitude - A double containing the magnitude to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newmagtype - A std::string containing the magnitude type to use,
	 * empty string to omit
     * \param newmagprob - A double containing the probability of the magnitude
     * estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdepth - A double containing the depth to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newdepthprob - A double containing the probability of the depth
     * estimate, std::numeric_limits<double>::quiet_NaN() to omit
     * \param neweventtype - A std::string containing the event type to use,
	 * empty string to omit
	 * \param neweventtypecertainty - A std::string containing the event type 
	 * certainty to use, empty string to omit
     * \param neweventtypeprob - A double containing the probability of the event
     * type estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newagencyid - A std::string containing the classifying algorithm 
     * agencyid to use, empty string to omit
     * \param newauthor - A std::string containing the classifying algorithm 
     * author to use, empty string to omit
	 */
	classification(std::string newphase, double newphaseprob,
            double newdistance, double newdistanceprob, double newazimuth,
			double newazimuthprob, double newmagnitude, std::string newmagtype,
            double newmagprob, double newdepth, double newdepthprob,
            std::string neweventtype, std::string neweventtypecertainty,
            double neweventtypeprob, std::string newagencyid,
            std::string newauthor);

/**
	 * \brief classification advanced constructor
	 *
	 * The advanced constructor for the classification class.
	 * Initializes members to provided values.
	 *
	 * \param newphase - A std::string containing the phase name to use, empty
	 * string to omit
     * \param newphaseprob - A double containing the probability of the phase
     * estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdistance - A double containing the distance to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newdistanceprob - A double containing the probability of the 
     * distance estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newazimuth - A double containing the azimuth to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newazimuthprob - A double containing the probability of the azimuth
     * estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newmagnitude - A double containing the magnitude to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newmagtype - A std::string containing the magnitude type to use,
	 * empty string to omit
     * \param newmagprob - A double containing the probability of the magnitude
     * estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newdepth - A double containing the depth to use,
	 * std::numeric_limits<double>::quiet_NaN() to omit
     * \param newdepthprob - A double containing the probability of the depth
     * estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param neweventtype - A detectionformats::eventtype containing the event
	 * type to use
     * \param neweventtypeprob - A double containing the probability of the event
     * type estimate, std::numeric_limits<double>::quiet_NaN() to omit
	 * \param newsource - A detectionformats::source containing the classifying 
     * algorithm source to use
	 */
    classification(std::string newphase, double newphaseprob,
            double newdistance, double newdistanceprob, double newazimuth,
			double newazimuthprob, double newmagnitude, std::string newmagtype,
            double newmagprob, double newdepth, double newdepthprob,
            detectionformats::eventtype neweventtype, double neweventtypeprob,
            detectionformats::source newsource);

	/**
	 * \brief classification advanced constructor
	 *
	 * The advanced constructor for the classification class.
	 * Converts the provided object from a rapidjson::Value, populating members
	 * \param json - A rapidjson::Value containing the parsed json.
	 */
	explicit classification(rapidjson::Value &json); // NOLINT

	/**
	 * \brief classification copy constructor
	 *
	 * The copy constructor for the classification class.
	 * Copies the provided object from a classification, populating members
	 * \param newclassification - A classification.
	 */
	classification(const classification & newclassification);

	/**
	 * \brief classification destructor
	 *
	 * The destructor for the classification class.
	 */
	~classification();

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
	 * \brief Empty check
	 *
	 * Checks to see if this object is empty
	 * \return Returns true if empty, false otherwise.
	 */
	bool isempty();

	/**
	 * \brief classification phase name
	 *
	 * An optional std::string containing classification phase name.
	 */
	std::string phase;

	/**
	 * \brief classification phase name probability
	 *
	 * An optional double containing the probability of the classification phase
     * name
	 */
	double phaseprobability;

	/**
	 * \brief classification distance
	 *
	 * An optional double containing the classification distance
	 */
	double distance;

	/**
	 * \brief classification distance probability
	 *
	 * An optional double containing the probability of the classification 
     * distance
	 */
	double distanceprobability;

	/**
	 * \brief classification azimuth
	 *
	 * An optional double containing the classification azimuth
	 */
	double azimuth;

	/**
	 * \brief classification azimuth probability
	 *
	 * An optional double containing the probability of the classification 
     * azimuth
	 */
	double azimuthprobability;

	/**
	 * \brief classification magnitude
	 *
	 * An optional double containing the classification magnitude
	 */
	double magnitude;

    /**
	 * \brief classification magnitude type
	 *
	 * An optional std::string containing the classification magnitude type
	 */
    std::string magnitudetype;

	/**
	 * \brief classification magnitude probability
	 *
	 * An optional double containing the probability of the classification 
     * magnitude
	 */
	double magnitudeprobability;

	/**
	 * \brief classification depth
	 *
	 * An optional double containing the classification depth
	 */
	double depth;

    /**
	 * \brief classification depth probability
	 *
	 * An optional double containing the probability of the classification 
     * depth
	 */
	double depthprobability;

    /**
	 * \brief classification event type
	 *
	 * An optional detectionformats::eventtype containing the classification 
     * event type
	 */
	detectionformats::eventtype eventtype;

    /**
	 * \brief classification event type probability
	 *
	 * An optional double containing the probability of the classification 
     * event type
	 */
	double eventtypeprobability;

    /**
	 * \brief classification algorithm source
	 *
	 * An optional detectionformats::site containing the source of this 
     * classification information
	 */
	detectionformats::source source;
};
}  // namespace detectionformats
#endif  // DETECTION_CLASSIFICATION_H
