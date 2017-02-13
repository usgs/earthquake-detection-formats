package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import java.util.ArrayList;
import java.util.Date;

/**
 * a conversion class used to create, parse, and validate beam detection data
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Beam implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String TYPE_KEY = "Type";
	public static final String ID_KEY = "ID";
	public static final String SITE_KEY = "Site";
	public static final String SOURCE_KEY = "Source";
	public static final String STARTTIME_KEY = "StartTime";
	public static final String ENDTIME_KEY = "EndTime";
	public static final String BACKAZIMUTH_KEY = "BackAzimuth";
	public static final String SLOWNESS_KEY = "Slowness";
	public static final String BACKAZIMUTHERROR_KEY = "BackAzimuthError";
	public static final String POWERRATIO_KEY = "PowerRatio";
	public static final String POWERRATIOERROR_KEY = "PowerRatioError";
	public static final String SLOWNESSERROR_KEY = "SlownessError";
	public static final String ASSOCIATIONINFO_KEY = "AssociationInfo";

	/**
	 * Required type identifier for this Beam
	 */
	private final String type;

	/**
	 * Required unique identifier for this Beam
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
	 * Required starttime for this Beam
	 */
	private final Date startTime;

	/**
	 * Required endtime for this Beam
	 */
	private final Date endTime;

	/**
	 * Required Double containing the back azimuth
	 */
	private final Double backAzimuth;

	/**
	 * Optional Double containing the back azimuth error
	 */
	private final Double backAzimuthError;

	/**
	 * Required Double containing the slowness
	 */
	private final Double slowness;

	/**
	 * Optional Double containing the slowness error
	 */
	private final Double slownessError;

	/**
	 * Required Double containing the powerRatio
	 */
	private final Double powerRatio;

	/**
	 * Optional Double containing the powerRatio error
	 */
	private final Double powerRatioError;

	/**
	 * Optional associated information.
	 */
	private final Associated associationInfo;

	/**
	 * The constructor for the Beam class. Initializes members to null values.
	 */
	public Beam() {

		type = "Beam";
		site = null;
		source = null;
		id = null;
		startTime = null;
		endTime = null;
		backAzimuth = null;
		backAzimuthError = null;
		slowness = null;
		slownessError = null;
		powerRatio = null;
		powerRatioError = null;
		associationInfo = null;
	}

	/**
	 * The advanced constructor for the Beam Class. Initializes members to
	 * provided values.
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
	 * @param newStartTime
	 *            - A Date containing the start time to use
	 * @param newEndTime
	 *            - A Date containing the end time to use
	 * @param newBackAzimuth
	 *            - A Double containing the back azimuth to use
	 * @param newBackAzimutherror
	 *            - A Double containing the back azimuth error to use, null to
	 *            omit
	 * @param newSlowness
	 *            - A Double containing the slowness to use
	 * @param newSlownessError
	 *            - A Double containing the slowness error to use, null to omit
	 * @param newPowerRatio
	 *            - A Double containing the power ratio to use
	 * @param newPowerRatioError
	 *            - A Double containing the power ratio error to use, null to
	 *            omit
	 */
	public Beam(String newID, String newSiteID, String newStation,
			String newChannel, String newNetwork, String newLocation,
			String newAgencyID, String newAuthor, Date newStartTime,
			Date newEndTime, Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError, Double newPowerRatio,
			Double newPowerRatioError) {

		this(newID,
				new Site(newSiteID, newStation, newChannel, newNetwork,
						newLocation),
				new Source(newAgencyID, newAuthor), newStartTime, newEndTime,
				newBackAzimuth, newBackAzimutherror, newSlowness,
				newSlownessError, newPowerRatio, newPowerRatioError);
	}

	/**
	 * The advanced constructor for the Beam class. Initializes members to
	 * provided values.
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
	 * @param newStartTime
	 *            - A Date containing the start time to use
	 * @param newEndTime
	 *            - A Date containing the end time to use
	 * @param newBackAzimuth
	 *            - A Double containing the back azimuth to use
	 * @param newBackAzimutherror
	 *            - A Double containing the back azimuth error to use, null to
	 *            omit
	 * @param newSlowness
	 *            - A Double containing the slowness to use
	 * @param newSlownessError
	 *            - A Double containing the slowness error to use, null to omit
	 * @param newPowerRatio
	 *            - A Double containing the power ratio to use
	 * @param newPowerRatioError
	 *            - A Double containing the power ratio error to use, null to
	 *            omit
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
	public Beam(String newID, String newSiteID, String newStation,
			String newChannel, String newNetwork, String newLocation,
			String newAgencyID, String newAuthor, Date newStartTime,
			Date newEndTime, Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError, Double newPowerRatio,
			Double newPowerRatioError, String newAssociatedPhase,
			Double newAssociatedDistance, Double newAssociatedAzimuth,
			Double newAssociatedResidual, Double newAssociatedSigma) {

		this(newID,
				new Site(newSiteID, newStation, newChannel, newNetwork,
						newLocation),
				new Source(newAgencyID, newAuthor), newStartTime, newEndTime,
				newBackAzimuth, newBackAzimutherror, newSlowness,
				newSlownessError, newPowerRatio, newPowerRatioError,
				new Associated(newAssociatedPhase, newAssociatedDistance,
						newAssociatedAzimuth, newAssociatedResidual,
						newAssociatedSigma));
	}

	/**
	 * The alternate advanced constructor for the Beam class. Initializes
	 * members to provided values.
	 *
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSite
	 *            - A Site containing the site to use
	 * @param newSource
	 *            - A Source containing the source to use
	 * @param newStartTime
	 *            - A Date containing the start time to use
	 * @param newEndTime
	 *            - A Date containing the end time to use
	 * @param newBackAzimuth
	 *            - A Double containing the back azimuth to use
	 * @param newBackAzimutherror
	 *            - A Double containing the back azimuth error to use, null to
	 *            omit
	 * @param newPowerRatio
	 *            - A Double containing the power ratio to use
	 * @param newPowerRatioError
	 *            - A Double containing the power ratio error to use, null to
	 *            omit
	 * @param newSlowness
	 *            - A Double containing the slowness to use
	 * @param newSlownessError
	 *            - A Double containing the slowness error to use, null to omit
	 */
	public Beam(String newID, Site newSite, Source newSource, Date newStartTime,
			Date newEndTime, Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError, Double newPowerRatio,
			Double newPowerRatioError) {

		this(newID, newSite, newSource, newStartTime, newEndTime,
				newBackAzimuth, newBackAzimutherror, newSlowness,
				newSlownessError, newPowerRatio, newPowerRatioError,
				new Associated());
	}

	/**
	 * The alternate advanced constructor for the Beam class. Initializes
	 * members to provided values.
	 *
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSite
	 *            - A Site containing the site to use
	 * @param newSource
	 *            - A Source containing the source to use
	 * @param newStartTime
	 *            - A Date containing the start time to use
	 * @param newEndTime
	 *            - A Date containing the end time to use
	 * @param newBackAzimuth
	 *            - A Double containing the back azimuth to use
	 * @param newBackAzimutherror
	 *            - A Double containing the back azimuth error to use, null to
	 *            omit
	 * @param newSlowness
	 *            - A Double containing the slowness to use
	 * @param newSlownessError
	 *            - A Double containing the slowness error to use, null to omit
	 * @param newPowerRatio
	 *            - A Double containing the power ratio to use
	 * @param newPowerRatioError
	 *            - A Double containing the power ratio error to use, null to
	 *            omit
	 * @param newAssociated
	 *            - A Associated containing the associated to use, null to omit
	 */
	public Beam(String newID, Site newSite, Source newSource, Date newStartTime,
			Date newEndTime, Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError, Double newPowerRatio,
			Double newPowerRatioError, Associated newAssociated) {

		type = "Beam";
		id = newID;
		site = newSite;
		source = newSource;
		startTime = newStartTime;
		endTime = newEndTime;
		backAzimuth = newBackAzimuth;
		backAzimuthError = newBackAzimutherror;
		slowness = newSlowness;
		slownessError = newSlownessError;
		powerRatio = newPowerRatio;
		powerRatioError = newPowerRatioError;
		associationInfo = newAssociated;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 *
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Beam(JSONObject newJSONObject) {

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

		// startTime
		if (newJSONObject.containsKey(STARTTIME_KEY)) {
			startTime = Utility
					.getDate(newJSONObject.get(STARTTIME_KEY).toString());
		} else {
			startTime = null;
		}

		// endTime
		if (newJSONObject.containsKey(ENDTIME_KEY)) {
			endTime = Utility
					.getDate(newJSONObject.get(ENDTIME_KEY).toString());
		} else {
			endTime = null;
		}

		// backAzimuth
		if (newJSONObject.containsKey(BACKAZIMUTH_KEY)) {
			backAzimuth = (double) newJSONObject.get(BACKAZIMUTH_KEY);
		} else {
			backAzimuth = null;
		}

		// slowness
		if (newJSONObject.containsKey(SLOWNESS_KEY)) {
			slowness = (double) newJSONObject.get(SLOWNESS_KEY);
		} else {
			slowness = null;
		}

		// powerRatio
		if (newJSONObject.containsKey(POWERRATIO_KEY)) {
			powerRatio = (double) newJSONObject.get(POWERRATIO_KEY);
		} else {
			powerRatio = null;
		}

		// Optional values
		// backAzimuthError
		if (newJSONObject.containsKey(BACKAZIMUTHERROR_KEY)) {
			backAzimuthError = (double) newJSONObject.get(BACKAZIMUTHERROR_KEY);
		} else {
			backAzimuthError = null;
		}

		// slownessError
		if (newJSONObject.containsKey(SLOWNESSERROR_KEY)) {
			slownessError = (double) newJSONObject.get(SLOWNESSERROR_KEY);
		} else {
			slownessError = null;
		}

		// powerRatioError
		if (newJSONObject.containsKey(POWERRATIOERROR_KEY)) {
			powerRatioError = (double) newJSONObject.get(POWERRATIOERROR_KEY);
		} else {
			powerRatioError = null;
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
		Date jsonStartTime = getStartTime();
		Date jsonEndTime = getEndTime();
		Double jsonBackAzimuth = getBackAzimuth();
		Double jsonSlowness = getSlowness();
		Double jsonPowerRatio = getPowerRatio();
		Double jsonBackAzimuthError = getBackAzimuthError();
		Double jsonSlownessError = getSlownessError();
		Double jsonPowerRatioError = getPowerRatioError();
		Associated jsonAssociationInfo = getAssociationInfo();

		// Required values
		// type
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

		// startTime
		if (jsonStartTime != null) {
			newJSONObject.put(STARTTIME_KEY, Utility.formatDate(jsonStartTime));
		}

		// endTime
		if (jsonEndTime != null) {
			newJSONObject.put(ENDTIME_KEY, Utility.formatDate(jsonEndTime));
		}

		// backAzimuth
		if (jsonBackAzimuth != null) {
			newJSONObject.put(BACKAZIMUTH_KEY, jsonBackAzimuth);
		}

		// slowness
		if (jsonSlowness != null) {
			newJSONObject.put(SLOWNESS_KEY, jsonSlowness);
		}

		// powerRatio
		if (jsonPowerRatio != null) {
			newJSONObject.put(POWERRATIO_KEY, jsonPowerRatio);
		}

		// Optional values
		// backAzimuthError
		if (jsonBackAzimuthError != null) {
			newJSONObject.put(BACKAZIMUTHERROR_KEY, jsonBackAzimuthError);
		}

		// SlownessError
		if (jsonSlownessError != null) {
			newJSONObject.put(SLOWNESSERROR_KEY, jsonSlownessError);
		}

		// powerRatioError
		if (jsonPowerRatioError != null) {
			newJSONObject.put(POWERRATIOERROR_KEY, jsonPowerRatioError);
		}

		// associated
		if ((jsonAssociationInfo != null) && (!jsonAssociationInfo.isEmpty()))
			newJSONObject.put(ASSOCIATIONINFO_KEY,
					jsonAssociationInfo.toJSON());

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
		Date jsonStartTime = getStartTime();
		Date jsonEndTime = getEndTime();
		Double jsonBackAzimuth = getBackAzimuth();
		Double jsonSlowness = getSlowness();
		Double jsonPowerRatio = getPowerRatio();
		Double jsonBackAzimuthError = getBackAzimuthError();
		Double jsonSlownessError = getSlownessError();
		Double jsonPowerRatioError = getPowerRatioError();
		Associated jsonAssociationInfo = getAssociationInfo();

		ArrayList<String> errorList = new ArrayList<String>();

		// Required Keys
		// type
		if (jsonType == null) {
			// type not found
			errorList.add("No Type in Beam Class.");
		} else if (jsonType.isEmpty()) {
			// type empty
			errorList.add("Empty Type in Beam Class.");
		} else if (!jsonType.equals("Beam")) {
			// wrong type
			errorList.add("Non-Beam type in Beam Class.");
		}

		// id
		if (jsonID == null) {
			// id not found
			errorList.add("No ID in Beam Class.");
		} else if (jsonID.isEmpty()) {
			// id empty
			errorList.add("Empty ID in Beam Class.");
		}

		// site
		if (jsonSite == null) {
			// site not found
			errorList.add("No Site in Beam Class.");
		} else if (!jsonSite.isValid()) {
			// site invalid
			errorList.add("Invalid Site in Beam Class.");
		}

		// source
		if (jsonSource == null) {
			// source not found
			errorList.add("No Source in Beam Class.");
		} else if (!jsonSource.isValid()) {
			// source invalid
			errorList.add("Invalid Source in Beam Class.");
		}

		// startTime
		if (jsonStartTime == null) {
			// time not found
			errorList.add("No Start Time in Beam Class.");
		}

		// endTime
		if (jsonEndTime == null) {
			// time not found
			errorList.add("No End Time in Beam Class.");
		}

		// backAzimuth
		if (jsonBackAzimuth == null) {
			// backazimuth not found
			errorList.add("No BackAzimuth in Beam Class.");
		} else if (jsonBackAzimuth < 0) {
			// invalid backazimuth
			errorList.add("Invalid BackAzimuth in Beam Class.");
		}

		// slowness
		if (jsonSlowness == null) {
			// slowness not found
			errorList.add("No Slowness in Beam Class.");
		} else if (jsonSlowness < 0) {
			// invalid slowness
			errorList.add("Invalid Slowness in Beam Class.");
		}

		// powerRatio
		if (jsonPowerRatio == null) {
			// powerRatio not found
			errorList.add("No PowerRatio in Beam Class.");
		} else if (jsonPowerRatio < 0) {
			// invalid powerRatio
			errorList.add("Invalid PowerRatio in Beam Class.");
		}

		// Optional Keys
		// backAzimuthError
		if (jsonBackAzimuthError != null) {
			if (jsonBackAzimuthError < 0) {
				// invalid backAzimuthError
				errorList.add("Invalid BackAzimuthError in Beam Class.");
			}
		}

		// slownessError
		if (jsonSlownessError != null) {
			if (jsonSlownessError < 0) {
				// invalid slownessError
				errorList.add("Invalid SlownessError in Beam Class.");
			}
		}

		if (jsonSlownessError != null) {
			if (jsonSlownessError < 0) {
				// invalid slownessError
				errorList.add("Invalid SlownessError in Beam Class.");
			}
		}

		if (jsonPowerRatioError != null) {
			if (jsonPowerRatioError < 0) {
				// invalid powerRatioError
				errorList.add("Invalid PowerRatioError in Beam Class.");
			}
		}

		// associated
		if (jsonAssociationInfo != null) {
			if (!jsonAssociationInfo.isValid()) {
				// associationinfo invalid
				errorList.add("Invalid AssociationInfo in Beam Class.");
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
	 * @return the startTime
	 */
	public Date getStartTime() {
		return startTime;
	}

	/**
	 * @return the endTime
	 */
	public Date getEndTime() {
		return endTime;
	}

	/**
	 * @return the backAzimuth
	 */
	public Double getBackAzimuth() {
		return backAzimuth;
	}

	/**
	 * @return the backAzimuthError
	 */
	public Double getBackAzimuthError() {
		return backAzimuthError;
	}

	/**
	 * @return the slowness
	 */
	public Double getSlowness() {
		return slowness;
	}

	/**
	 * @return the powerRatio
	 */
	public Double getPowerRatio() {
		return powerRatio;
	}

	/**
	 * @return the slownessError
	 */
	public Double getSlownessError() {
		return slownessError;
	}

	/**
	 * @return the powerRatioError
	 */
	public Double getPowerRatioError() {
		return powerRatioError;
	}

	/**
	 * @return the associationInfo
	 */
	public Associated getAssociationInfo() {
		return associationInfo;
	}
}
