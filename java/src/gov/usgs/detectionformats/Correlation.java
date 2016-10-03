package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import java.util.ArrayList;
import java.util.Date;

/**
 * a conversion class used to create, parse, and validate correlation detection
 * data
 * 
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Correlation implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String TYPE_KEY = "Type";
	public static final String ID_KEY = "ID";
	public static final String SITE_KEY = "Site";
	public static final String SOURCE_KEY = "Source";
	public static final String PHASE_KEY = "Phase";
	public static final String TIME_KEY = "Time";
	public static final String CORRELATION_KEY = "Correlation";
	public static final String LATITUDE_KEY = "Latitude";
	public static final String LONGITUDE_KEY = "Longitude";
	public static final String DEPTH_KEY = "Depth";
	public static final String ORIGINTIME_KEY = "OriginTime";
	public static final String EVENTTYPE_KEY = "EventType";
	public static final String MAGNITUDE_KEY = "Magnitude";
	public static final String SNR_KEY = "SNR";
	public static final String ZSCORE_KEY = "ZScore";
	public static final String DETECTIONTHRESHOLD_KEY = "DetectionThreshold";
	public static final String THRESHOLDTYPE_KEY = "ThresholdType";
	public static final String ASSOCIATIONINFO_KEY = "AssociationInfo";

	/**
	 * Required type identifier for this Correlation
	 */
	private final String type;

	/**
	 * Required unique identifier for this Correlation
	 */
	private final String id;

	/**
	 * Required site.
	 */
	private final Site site;

	/**
	 * Required source.
	 */
	private final Source source;

	/**
	 * Required String containing the Correlation phase name
	 */
	private final String phase;

	/**
	 * Required time for this Correlation
	 */
	private final Date time;

	/**
	 * Required Double containing the Correlation value
	 */
	private final Double correlation;

	/**
	 * Required Double containing the Correlation latitude
	 */
	private final Double latitude;

	/**
	 * Required Double containing the Correlation longitude
	 */
	private final Double longitude;

	/**
	 * Required Double containing the Correlation depth
	 */
	private final Double depth;

	/**
	 * Required origin time for this Correlation
	 */
	private final Date originTime;

	/**
	 * Optional String containing the event type of this Correlation valid
	 * values are "earthquake" or "blast"
	 */
	private final String eventType;

	/**
	 * Optional Double containing the Correlation magnitude
	 */
	private final Double magnitude;

	/**
	 * Optional Double containing the Correlation snr
	 */
	private final Double snr;

	/**
	 * Optional Double containing the Correlation zscore
	 */
	private final Double zScore;

	/**
	 * Optional Double containing the Correlation detection threshold
	 */
	private final Double detectionThreshold;

	/**
	 * Optional String containing the threshold type of this Correlation
	 */
	private final String thresholdType;

	/**
	 * Optional associated information.
	 */
	private final Associated associationInfo;

	/**
	 * The constructor for the Correlation class. Initializes members to null
	 * values.
	 */
	public Correlation() {

		type = "Correlation";
		id = null;
		site = null;
		source = null;
		phase = null;
		time = null;
		correlation = null;
		latitude = null;
		longitude = null;
		depth = null;
		originTime = null;
		eventType = null;
		magnitude = null;
		snr = null;
		zScore = null;
		detectionThreshold = null;
		thresholdType = null;
		associationInfo = null;
	}

	/**
	 * Advanced constructor
	 * 
	 * The advanced constructor for the Correlation class. Initializes members
	 * to provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSiteID
	 *            - A String containing the siteid to use
	 * @param newStation
	 *            - A String containing the station to use
	 * @param newChannel
	 *            - A String containing the channel to use
	 * @param newNetwork
	 *            - A String containing the network to use
	 * @param newLocation
	 *            - A String containing the location to use
	 * @param newAgencyID
	 *            - A String containing the agencyid to use
	 * @param newAuthor
	 *            - A String containing the author to use
	 * @param newPhase
	 *            - A String containing the phase to use
	 * @param newTime
	 *            - A Date containing the phase time string to use
	 * @param newCorrelation
	 *            - A Double containing the correlation value to use
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newDepth
	 *            - A Double containing the depth to use
	 * @param newOrigintime
	 *            - A Date containing the origin time string to use
	 * @param newEventtype
	 *            - A String containing the event type to use, null to omit
	 * @param newMagnitude
	 *            - A Double containing the magnitude to use, null to omit
	 * @param newSNR
	 *            - A Double containing the snr to use, null to omit
	 * @param newZScore
	 *            - A Double containing the zscore to use, null to omit
	 * @param newDetectionThreshold
	 *            - A Double containing the detection threshold to use, null to
	 *            omit
	 * @param newThresholdType
	 *            - A String containing the threshold type to use, null to omit
	 */
	public Correlation(String newID, String newSiteID, String newStation,
			String newChannel, String newNetwork, String newLocation,
			String newAgencyID, String newAuthor, String newPhase,
			Date newTime, Double newCorrelation, Double newLatitude,
			Double newLongitude, Double newDepth, Date newOrigintime,
			String newEventtype, Double newMagnitude, Double newSNR,
			Double newZScore, Double newDetectionThreshold,
			String newThresholdType) {

		this(newID, new Site(newSiteID, newStation, newChannel, newNetwork,
				newLocation), new Source(newAgencyID, newAuthor), newPhase,
				newTime, newCorrelation, newLatitude, newLongitude, newDepth,
				newOrigintime, newEventtype, newMagnitude, newSNR, newZScore,
				newDetectionThreshold, newThresholdType, new Associated());
	}

	/**
	 * Alternate advanced constructor
	 * 
	 * The advanced constructor for the Correlation class. Initializes members
	 * to provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSiteID
	 *            - A String containing the siteid to use
	 * @param newStation
	 *            - A String containing the station to use
	 * @param newChannel
	 *            - A String containing the channel to use
	 * @param newNetwork
	 *            - A String containing the network to use
	 * @param newLocation
	 *            - A String containing the location to use
	 * @param newAgencyID
	 *            - A String containing the agencyid to use
	 * @param newAuthor
	 *            - A String containing the author to use
	 * @param newPhase
	 *            - A String containing the phase to use
	 * @param newTime
	 *            - A Date containing the phase time string to use
	 * @param newCorrelation
	 *            - A Double containing the correlation value to use
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newDepth
	 *            - A Double containing the depth to use
	 * @param newOrigintime
	 *            - A Date containing the origin time string to use
	 * @param newEventtype
	 *            - A String containing the event type to use, null to omit
	 * @param newMagnitude
	 *            - A Double containing the magnitude to use, null to omit
	 * @param newSNR
	 *            - A Double containing the snr to use, null to omit
	 * @param newZScore
	 *            - A Double containing the zscore to use, null to omit
	 * @param newDetectionThreshold
	 *            - A Double containing the detection threshold to use, null to
	 *            omit
	 * @param newThresholdType
	 *            - A String containing the threshold type to use, null to omit
	 * @param newAssociatedPhase
	 *            - A std:string containing the associated phase to use, null to
	 *            omit
	 * @param newAssociatedDistance
	 *            - A Double containing the associated distance to use, null to
	 *            omit
	 * @param newAssociatedAzimuth
	 *            - A Double containing the associated azimuth to use, null to
	 *            omit
	 * @param newAssociatedResidual
	 *            - A Double containing the associated residual to use, null to
	 *            omit
	 * @param newAssociatedSigma
	 *            - A Double containing the associated sigma to use, null to
	 *            omit
	 */
	public Correlation(String newID, String newSiteID, String newStation,
			String newChannel, String newNetwork, String newLocation,
			String newAgencyID, String newAuthor, String newPhase,
			Date newTime, Double newCorrelation, Double newLatitude,
			Double newLongitude, Double newDepth, Date newOrigintime,
			String newEventtype, Double newMagnitude, Double newSNR,
			Double newZScore, Double newDetectionThreshold,
			String newThresholdType, String newAssociatedPhase,
			Double newAssociatedDistance, Double newAssociatedAzimuth,
			Double newAssociatedResidual, Double newAssociatedSigma) {

		this(newID, new Site(newSiteID, newStation, newChannel, newNetwork,
				newLocation), new Source(newAgencyID, newAuthor), newPhase,
				newTime, newCorrelation, newLatitude, newLongitude, newDepth,
				newOrigintime, newEventtype, newMagnitude, newSNR, newZScore,
				newDetectionThreshold, newThresholdType, new Associated(
						newAssociatedPhase, newAssociatedDistance,
						newAssociatedAzimuth, newAssociatedResidual,
						newAssociatedSigma));
	}

	/**
	 * Alternate advanced constructor
	 * 
	 * The alternate advanced constructor for the Correlation class. Initializes
	 * members to provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSite
	 *            - A Site containing the site to use
	 * @param newSource
	 *            - A Source containing the source to use
	 * @param newPhase
	 *            - A String containing the phase to use
	 * @param newTime
	 *            - A Date containing the phase time string to use
	 * @param newCorrelation
	 *            - A Double containing the correlation value to use
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newDepth
	 *            - A Double containing the depth to use
	 * @param newOrigintime
	 *            - A Date containing the origin time string to use
	 * @param newEventtype
	 *            - A String containing the event type to use, null to omit
	 * @param newMagnitude
	 *            - A Double containing the magnitude to use, null to omit
	 * @param newSNR
	 *            - A Double containing the snr to use, null to omit
	 * @param newZScore
	 *            - A Double containing the zscore to use, null to omit
	 * @param newDetectionThreshold
	 *            - A Double containing the detection threshold to use, null to
	 *            omit
	 * @param newThresholdType
	 *            - A String containing the threshold type to use, null to omit
	 */
	public Correlation(String newID, Site newSite, Source newSource,
			String newPhase, Date newTime, Double newCorrelation,
			Double newLatitude, Double newLongitude, Double newDepth,
			Date newOrigintime, String newEventtype, Double newMagnitude,
			Double newSNR, Double newZScore, Double newDetectionThreshold,
			String newThresholdType) {

		this(newID, newSite, newSource, newPhase, newTime, newCorrelation,
				newLatitude, newLongitude, newDepth, newOrigintime,
				newEventtype, newMagnitude, newSNR, newZScore,
				newDetectionThreshold, newThresholdType, new Associated());
	}

	/**
	 * Alternate advanced constructor
	 * 
	 * The alternate advanced constructor for the Correlation class. Initializes
	 * members to provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSite
	 *            - A Site containing the site to use
	 * @param newSource
	 *            - A Source containing the source to use
	 * @param newPhase
	 *            - A String containing the phase to use
	 * @param newTime
	 *            - A Date containing the phase time string to use
	 * @param newCorrelation
	 *            - A Double containing the correlation value to use
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newDepth
	 *            - A Double containing the depth to use
	 * @param newOrigintime
	 *            - A Date containing the origin time string to use
	 * @param newEventtype
	 *            - A String containing the event type to use, null to omit
	 * @param newMagnitude
	 *            - A Double containing the magnitude to use, null to omit
	 * @param newSNR
	 *            - A Double containing the snr to use, null to omit
	 * @param newZScore
	 *            - A Double containing the zscore to use, null to omit
	 * @param newDetectionThreshold
	 *            - A Double containing the detection threshold to use, null to
	 *            omit
	 * @param newThresholdType
	 *            - A String containing the threshold type to use, null to omit
	 * @param newAssociated
	 *            - A Associated containing the associated to use null to omit
	 */
	public Correlation(String newID, Site newSite, Source newSource,
			String newPhase, Date newTime, Double newCorrelation,
			Double newLatitude, Double newLongitude, Double newDepth,
			Date newOrigintime, String newEventtype, Double newMagnitude,
			Double newSNR, Double newZScore, Double newDetectionThreshold,
			String newThresholdType, Associated newAssociated) {

		type = "Correlation";
		id = newID;
		site = newSite;
		source = newSource;
		phase = newPhase;
		time = newTime;
		correlation = newCorrelation;
		latitude = newLatitude;
		longitude = newLongitude;
		depth = newDepth;
		originTime = newOrigintime;
		eventType = newEventtype;
		magnitude = newMagnitude;
		snr = newSNR;
		zScore = newZScore;
		detectionThreshold = newDetectionThreshold;
		thresholdType = newThresholdType;
		associationInfo = newAssociated;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 * 
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Correlation(JSONObject newJSONObject) {

		// Required values
		// type
		if (newJSONObject.containsKey(TYPE_KEY)) {
			type = newJSONObject.get(TYPE_KEY).toString();
		} else {
			type = null;
		}

		// id
		if (newJSONObject.containsKey(ID_KEY)) {
			id = newJSONObject.get(ID_KEY).toString();
		} else {
			id = null;
		}

		// site
		if (newJSONObject.containsKey(SITE_KEY)) {
			site = new Site((JSONObject) newJSONObject.get(SITE_KEY));
		} else {
			site = null;
		}

		// source
		if (newJSONObject.containsKey(SOURCE_KEY)) {
			source = new Source((JSONObject) newJSONObject.get(SOURCE_KEY));
		} else {
			source = null;
		}

		// phase
		if (newJSONObject.containsKey(PHASE_KEY)) {
			phase = newJSONObject.get(PHASE_KEY).toString();
		} else {
			phase = null;
		}

		// time
		if (newJSONObject.containsKey(TIME_KEY)) {
			time = Utility.getDate(newJSONObject.get(TIME_KEY).toString());
		} else {
			time = null;
		}

		// correlation
		if (newJSONObject.containsKey(CORRELATION_KEY)) {
			correlation = (double) newJSONObject.get(CORRELATION_KEY);
		} else {
			correlation = null;
		}

		// latitude
		if (newJSONObject.containsKey(LATITUDE_KEY)) {
			latitude = (double) newJSONObject.get(LATITUDE_KEY);
		} else {
			latitude = null;
		}

		// longitude
		if (newJSONObject.containsKey(LONGITUDE_KEY)) {
			longitude = (double) newJSONObject.get(LONGITUDE_KEY);
		} else {
			longitude = null;
		}

		// depth
		if (newJSONObject.containsKey(DEPTH_KEY)) {
			depth = (double) newJSONObject.get(DEPTH_KEY);
		} else {
			depth = null;
		}

		// originTime
		if (newJSONObject.containsKey(ORIGINTIME_KEY)) {
			originTime = Utility.getDate(newJSONObject.get(ORIGINTIME_KEY)
					.toString());
		} else {
			originTime = null;
		}

		// Optional values
		// eventType
		if (newJSONObject.containsKey(EVENTTYPE_KEY)) {
			eventType = (String) newJSONObject.get(EVENTTYPE_KEY);
		} else {
			eventType = null;
		}

		// magnitude
		if (newJSONObject.containsKey(MAGNITUDE_KEY)) {
			magnitude = (double) newJSONObject.get(MAGNITUDE_KEY);
		} else {
			magnitude = null;
		}

		// snr
		if (newJSONObject.containsKey(SNR_KEY)) {
			snr = (double) newJSONObject.get(SNR_KEY);
		} else {
			snr = null;
		}

		// zScore
		if (newJSONObject.containsKey(ZSCORE_KEY)) {
			zScore = (double) newJSONObject.get(ZSCORE_KEY);
		} else {
			zScore = null;
		}

		// detectionThreshold
		if (newJSONObject.containsKey(DETECTIONTHRESHOLD_KEY)) {
			detectionThreshold = (double) newJSONObject
					.get(DETECTIONTHRESHOLD_KEY);
		} else {
			detectionThreshold = null;
		}

		// thresholdType
		if (newJSONObject.containsKey(THRESHOLDTYPE_KEY)) {
			thresholdType = (String) newJSONObject.get(THRESHOLDTYPE_KEY);
		} else {
			thresholdType = null;
		}

		// associated
		if (newJSONObject.containsKey(ASSOCIATIONINFO_KEY)) {
			associationInfo = new Associated(
					(JSONObject) newJSONObject.get(ASSOCIATIONINFO_KEY));
		} else {
			associationInfo = null;
		}
	}

	/**
	 * Converts the contents of the class to a json object Overridden from
	 * DetectionBase.
	 * 
	 * @return Returns a JSONObject containing the class contents
	 */
	@SuppressWarnings("unchecked")
	public JSONObject toJSON() {

		JSONObject newJSONObject = new JSONObject();

		String jsonType = getType();
		String jsonID = getID();
		Site jsonSite = getSite();
		Source jsonSource = getSource();
		String jsonPhase = getPhase();
		Date jsonTime = getTime();
		Double jsonCorrelation = getCorrelation();
		Double jsonLatitude = getLatitude();
		Double jsonLongitude = getLongitude();
		Double jsonDepth = getDepth();
		Date jsonOriginTime = getOriginTime();
		String jsonEventType = getEventType();
		Double jsonMagnitude = getMagnitude();
		Double jsonSNR = getSNR();
		Double jsonZScore = getZScore();
		Double jsonDetectionThreshold = getDetectionThreshold();
		String jsonThresholdType = getThresholdType();
		Associated jsonAssociationInfo = getAssociationInfo();

		// Required values
		// Type
		newJSONObject.put(TYPE_KEY, jsonType);

		// id
		if (jsonID != null) {
			newJSONObject.put(ID_KEY, jsonID);
		}

		// site
		if (jsonSite != null) {
			newJSONObject.put(SITE_KEY, jsonSite.toJSON());
		}

		// source
		if (jsonSource != null) {
			newJSONObject.put(SOURCE_KEY, jsonSource.toJSON());
		}

		// phase
		if (jsonPhase != null) {
			newJSONObject.put(PHASE_KEY, jsonPhase);
		}

		// time
		if (jsonTime != null) {
			newJSONObject.put(TIME_KEY, Utility.formatDate(jsonTime));
		}

		// Correlation
		if (jsonCorrelation != null) {
			newJSONObject.put(CORRELATION_KEY, jsonCorrelation);
		}

		// latitude
		if (jsonLatitude != null) {
			newJSONObject.put(LATITUDE_KEY, jsonLatitude);
		}

		// longitude
		if (jsonLongitude != null) {
			newJSONObject.put(LONGITUDE_KEY, jsonLongitude);
		}

		// depth
		if (jsonDepth != null) {
			newJSONObject.put(DEPTH_KEY, jsonDepth);
		}

		// originTime
		if (jsonOriginTime != null) {
			newJSONObject.put(ORIGINTIME_KEY,
					Utility.formatDate(jsonOriginTime));
		}

		// Optional values
		// eventType
		if (jsonEventType != null) {
			newJSONObject.put(EVENTTYPE_KEY, jsonEventType);
		}

		// magnitude
		if (jsonMagnitude != null) {
			newJSONObject.put(MAGNITUDE_KEY, jsonMagnitude);
		}

		// snr
		if (jsonSNR != null) {
			newJSONObject.put(SNR_KEY, jsonSNR);
		}

		// zScore
		if (jsonZScore != null) {
			newJSONObject.put(ZSCORE_KEY, jsonZScore);
		}

		// detectionThreshold
		if (jsonDetectionThreshold != null) {
			newJSONObject.put(DETECTIONTHRESHOLD_KEY, jsonDetectionThreshold);
		}

		// thresholdType
		if (jsonThresholdType != null) {
			newJSONObject.put(THRESHOLDTYPE_KEY, jsonThresholdType);
		}

		// associated
		if ((jsonAssociationInfo != null) && (!jsonAssociationInfo.isEmpty()))
			newJSONObject
					.put(ASSOCIATIONINFO_KEY, jsonAssociationInfo.toJSON());

		return (newJSONObject);
	}

	/**
	 * Validates the class.
	 * 
	 * @return Returns true if successful
	 */
	public boolean isValid() {
		if (getErrors() == null) {
			return (true);
		} else if (getErrors().size() == 0) {
			return (true);
		} else {
			return (false);
		}
	}

	/**
	 * Gets any validation errors in the class.
	 * 
	 * @return Returns a List&lt;String&gt; of any errors found
	 */
	public ArrayList<String> getErrors() {

		String jsonType = getType();
		String jsonID = getID();
		Site jsonSite = getSite();
		Source jsonSource = getSource();
		String jsonPhase = getPhase();
		Date jsonTime = getTime();
		Double jsonCorrelation = getCorrelation();
		Double jsonLatitude = getLatitude();
		Double jsonLongitude = getLongitude();
		Double jsonDepth = getDepth();
		Date jsonOriginTime = getOriginTime();
		String jsonEventType = getEventType();
		Double jsonMagnitude = getMagnitude();
		String jsonThresholdType = getThresholdType();
		Associated jsonAssociationInfo = getAssociationInfo();

		ArrayList<String> errorList = new ArrayList<String>();

		// Required Keys
		// type
		if (jsonType == null) {
			// type not found
			errorList.add("No Type in Correlation Class.");
		} else if (jsonType.isEmpty()) {
			// type empty
			errorList.add("Empty Type in Correlation Class.");
		} else if (!jsonType.equals("Correlation")) {
			// wrong type
			errorList.add("Non-Correlation type in Correlation Class.");
		}

		// id
		if (jsonID == null) {
			// id not found
			errorList.add("No ID in Correlation Class.");
		} else if (jsonID.isEmpty()) {
			// id empty
			errorList.add("Empty ID in Correlation Class.");
		}

		// site
		if (jsonSite == null) {
			// site not found
			errorList.add("No Site in Correlation Class.");
		} else if (!jsonSite.isValid()) {
			// site invalid
			errorList.add("Invalid Site in Correlation Class.");
		}

		// source
		if (jsonSource == null) {
			// source not found
			errorList.add("No Source in Correlation Class.");
		} else if (!jsonSource.isValid()) {
			// source invalid
			errorList.add("Invalid Source in Correlation Class.");
		}

		// phase
		if (jsonPhase == null) {
			// phase not found
			errorList.add("No Phase in Correlation Class.");
		} else if (jsonPhase.isEmpty()) {
			// phase empty
			errorList.add("Empty Phase in Correlation Class.");
		} else if (!Utility.isStringAlpha(jsonPhase)) {
			// invalid phase
			errorList.add("Invalid Phase in Correlation Class.");
		}

		// time
		if (jsonTime == null) {
			// time not found
			errorList.add("No Time in Correlation Class.");
		}

		// correlation
		if (jsonCorrelation == null) {
			// latitude not found
			errorList.add("No Correlation in Correlation Class.");
		} else if (jsonCorrelation < 0) {
			// invalid latitude
			errorList
					.add("Correaltion in Correlation Class not in greater than 0.");
		}

		// latitude
		if (jsonLatitude == null) {
			// latitude not found
			errorList.add("No Latitude in Correlation Class.");
		} else if ((jsonLatitude < -90) || (jsonLatitude > 90)) {
			// invalid latitude
			errorList
					.add("Latitude in Correlation Class not in the range of -90 to 90.");
		}

		// longitude
		if (jsonLongitude == null) {
			// longitude not found
			errorList.add("No Longitude in Correlation Class.");
		} else if ((jsonLongitude < -180) || (jsonLongitude > 180)) {
			// invalid longitude
			errorList
					.add("Longitude in Correlation Class not in the range of -180 to 180.");
		}

		// depth
		if (jsonDepth == null) {
			// depth not found
			errorList.add("No Depth in Correlation Class.");
		} else if ((jsonDepth < -100) || (jsonDepth > 1500)) {
			// invalid depth
			errorList
					.add("Depth in Correlation Class not in the range of -100 to 1500.");
		}

		// originTime
		if (jsonOriginTime == null) {
			// origin time not found
			errorList.add("No Origin Time in Correlation Class.");
		}

		// Optional Keys
		// eventType
		if (jsonEventType != null) {

			boolean match = false;
			if (jsonEventType.equals("earthquake")) {
				match = true;
			} else if (jsonEventType.equals("blast")) {
				match = true;
			} else {
				match = false;
			}

			if (!match) {
				// invalid eventType
				errorList.add("Invalid EventType in Correlation Class.");
			}
		}

		// magnitude
		if (jsonMagnitude != null) {
			if ((jsonMagnitude < -2) || (jsonMagnitude > 10)) {
				// invalid Magnitude
				errorList
						.add("Magnitude in Correlation Class not in the range of -1 to 10.");
			}
		}

		// thresholdType
		if (jsonThresholdType != null) {
			if (jsonThresholdType.isEmpty()) {
				// thresholdType empty
				errorList.add("Empty ThresholdType in Correlation Class.");
			}
		}

		// associated
		if (jsonAssociationInfo != null) {
			if (!jsonAssociationInfo.isValid()) {
				// associationinfo invalid
				errorList.add("Invalid AssociationInfo in Correlation Class.");
			}
		}

		// success
		return (errorList);
	}

	/**
	 * @return the type
	 */
	public String getType() {
		return type;
	}

	/**
	 * @return the id
	 */
	public String getID() {
		return id;
	}

	/**
	 * @return the site
	 */
	public Site getSite() {
		return site;
	}

	/**
	 * @return the source
	 */
	public Source getSource() {
		return source;
	}

	/**
	 * @return the phase
	 */
	public String getPhase() {
		return phase;
	}

	/**
	 * @return the time
	 */
	public Date getTime() {
		return time;
	}

	/**
	 * @return the correlation
	 */
	public Double getCorrelation() {
		return correlation;
	}

	/**
	 * @return the latitude
	 */
	public Double getLatitude() {
		return latitude;
	}

	/**
	 * @return the longitude
	 */
	public Double getLongitude() {
		return longitude;
	}

	/**
	 * @return the depth
	 */
	public Double getDepth() {
		return depth;
	}

	/**
	 * @return the originTime
	 */
	public Date getOriginTime() {
		return originTime;
	}

	/**
	 * @return the eventType
	 */
	public String getEventType() {
		return eventType;
	}

	/**
	 * @return the magnitude
	 */
	public Double getMagnitude() {
		return magnitude;
	}

	/**
	 * @return the snr
	 */
	public Double getSNR() {
		return snr;
	}

	/**
	 * @return the zScore
	 */
	public Double getZScore() {
		return zScore;
	}

	/**
	 * @return the detectionThreshold
	 */
	public Double getDetectionThreshold() {
		return detectionThreshold;
	}

	/**
	 * @return the thresholdType
	 */
	public String getThresholdType() {
		return thresholdType;
	}

	/**
	 * @return the associationInfo
	 */
	public Associated getAssociationInfo() {
		return associationInfo;
	}
}
