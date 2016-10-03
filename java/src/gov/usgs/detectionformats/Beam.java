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
	public static final String TIME_KEY = "Time";
	public static final String BACKAZIMUTH_KEY = "BackAzimuth";
	public static final String SLOWNESS_KEY = "Slowness";
	public static final String BACKAZIMUTHERROR_KEY = "BackAzimuthError";
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
	 * Required time for this Beam
	 */
	private final Date time;

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
		time = null;
		backAzimuth = null;
		backAzimuthError = null;
		slowness = null;
		slownessError = null;
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
	 * @param newTime
	 *            - A Date containing the time to use
	 * @param newBackAzimuth
	 *            - A Double containing the back azimuth to use
	 * @param newBackAzimutherror
	 *            - A Double containing the back azimuth error to use, null to
	 *            omit
	 * @param newSlowness
	 *            - A Double containing the slowness to use
	 * @param newSlownessError
	 *            - A Double containing the slowness error to use, null to omit
	 */
	public Beam(String newID, String newSiteID, String newStation,
			String newChannel, String newNetwork, String newLocation,
			String newAgencyID, String newAuthor, Date newTime,
			Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError) {

		this(newID, new Site(newSiteID, newStation, newChannel, newNetwork,
				newLocation), new Source(newAgencyID, newAuthor), newTime,
				newBackAzimuth, newBackAzimutherror, newSlowness,
				newSlownessError);
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
	 * @param newTime
	 *            - A Date containing the time to use
	 * @param newBackAzimuth
	 *            - A Double containing the back azimuth to use
	 * @param newBackAzimutherror
	 *            - A Double containing the back azimuth error to use, null to
	 *            omit
	 * @param newSlowness
	 *            - A Double containing the slowness to use
	 * @param newSlownessError
	 *            - A Double containing the slowness error to use, null to omit
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
			String newAgencyID, String newAuthor, Date newTime,
			Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError,
			String newAssociatedPhase, Double newAssociatedDistance,
			Double newAssociatedAzimuth, Double newAssociatedResidual,
			Double newAssociatedSigma) {

		this(newID, new Site(newSiteID, newStation, newChannel, newNetwork,
				newLocation), new Source(newAgencyID, newAuthor), newTime,
				newBackAzimuth, newBackAzimutherror, newSlowness,
				newSlownessError, new Associated(newAssociatedPhase,
						newAssociatedDistance, newAssociatedAzimuth,
						newAssociatedResidual, newAssociatedSigma));
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
	 * @param newTime
	 *            - A Date containing the time to use
	 * @param newBackAzimuth
	 *            - A Double containing the back azimuth to use
	 * @param newBackAzimutherror
	 *            - A Double containing the back azimuth error to use, null to
	 *            omit
	 * @param newSlowness
	 *            - A Double containing the slowness to use
	 * @param newSlownessError
	 *            - A Double containing the slowness error to use, null to omit
	 */
	public Beam(String newID, Site newSite, Source newSource, Date newTime,
			Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError) {

		this(newID, newSite, newSource, newTime, newBackAzimuth,
				newBackAzimutherror, newSlowness, newSlownessError,
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
	 * @param newTime
	 *            - A Date containing the time to use
	 * @param newBackAzimuth
	 *            - A Double containing the back azimuth to use
	 * @param newBackAzimutherror
	 *            - A Double containing the back azimuth error to use, null to
	 *            omit
	 * @param newSlowness
	 *            - A Double containing the slowness to use
	 * @param newSlownessError
	 *            - A Double containing the slowness error to use, null to omit
	 * @param newAssociated
	 *            - A Associated containing the associated to use, null to omit
	 */
	public Beam(String newID, Site newSite, Source newSource, Date newTime,
			Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError,
			Associated newAssociated) {

		type = "Beam";
		id = newID;
		site = newSite;
		source = newSource;
		time = newTime;
		backAzimuth = newBackAzimuth;
		backAzimuthError = newBackAzimutherror;
		slowness = newSlowness;
		slownessError = newSlownessError;
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

		// time
		if (newJSONObject.containsKey(TIME_KEY)) {
			time = Utility.getDate(newJSONObject.get(TIME_KEY).toString());
		} else {
			time = null;
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
		Date jsonTime = getTime();
		Double jsonBackAzimuth = getBackAzimuth();
		Double jsonSlowness = getSlowness();
		Double jsonBackAzimuthError = getBackAzimuthError();
		Double jsonSlownessError = getSlownessError();
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

		// time
		if (jsonTime != null) {
			newJSONObject.put(TIME_KEY, Utility.formatDate(jsonTime));
		}

		// backAzimuth
		if (jsonBackAzimuth != null) {
			newJSONObject.put(BACKAZIMUTH_KEY, jsonBackAzimuth);
		}

		// slowness
		if (jsonSlowness != null) {
			newJSONObject.put(SLOWNESS_KEY, jsonSlowness);
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
		Date jsonTime = getTime();
		Double jsonBackAzimuth = getBackAzimuth();
		Double jsonSlowness = getSlowness();
		Double jsonBackAzimuthError = getBackAzimuthError();
		Double jsonSlownessError = getSlownessError();
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

		// time
		if (jsonTime == null) {
			// time not found
			errorList.add("No Time in Beam Class.");
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
	 * @return the time
	 */
	public Date getTime() {
		return time;
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
	 * @return the slownessError
	 */
	public Double getSlownessError() {
		return slownessError;
	}

	/**
	 * @return the associationInfo
	 */
	public Associated getAssociationInfo() {
		return associationInfo;
	}
}
