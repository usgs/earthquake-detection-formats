package gov.usgs.detectionformats;

import java.util.ArrayList;
import java.util.Date;

import org.json.simple.JSONObject;

/**
 * a conversion class used to create, parse, and validate hypocenter data as
 * part of detection data.
 * 
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Hypo implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String LATITUDE_KEY = "Latitude";
	public static final String LONGITUDE_KEY = "Longitude";
	public static final String DEPTH_KEY = "Depth";
	public static final String TIME_KEY = "Time";
	public static final String LATITUDE_ERROR_KEY = "LatitudeError";
	public static final String LONGITUDE_ERROR_KEY = "LongitudeError";
	public static final String DEPTH_ERROR_KEY = "DepthError";
	public static final String TIME_ERROR_KEY = "TimeError";

	/**
	 * Required Double containing the latitude
	 */
	private final Double latitude;

	/**
	 * Required Double containing the longitude
	 */
	private final Double longitude;

	/**
	 * Required time for this hypo
	 */
	private final Date time;

	/**
	 * Required Double containing the depth
	 */
	private final Double depth;

	/**
	 * Optional Double containing the latitude error
	 */
	private final Double latitudeError;

	/**
	 * Optional Double containing the longitude error
	 */
	private final Double longitudeError;

	/**
	 * Optional Double containing the time error
	 */
	private final Double timeError;

	/**
	 * Optional Double containing the depth error
	 */
	private final Double depthError;

	/**
	 * The constructor for the Hypo class. Initializes members to null values.
	 */
	public Hypo() {

		latitude = null;
		longitude = null;
		time = null;
		depth = null;
		latitudeError = null;
		longitudeError = null;
		timeError = null;
		depthError = null;
	}

	/**
	 * Advanced constructor
	 * 
	 * The alternate advanced constructor for the Origin class. Initializes
	 * members to provided values.
	 * 
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newTime
	 *            - A Date containing the new origin time to use
	 * @param newDepth
	 *            - A Double containing the depth to use
	 * @param newLatitudeError
	 *            - A Double containing the latitude error to use, null to omit
	 * @param newLongitudeError
	 *            - A Double containing the longitude error to use, null to omit
	 * @param newTimeError
	 *            - A Double containing the new time error to use, null to omit
	 * @param newDepthError
	 *            - A Double containing the depth error to use, null to omit
	 */
	public Hypo(Double newLatitude, Double newLongitude, Date newTime,
			Double newDepth, Double newLatitudeError, Double newLongitudeError,
			double newTimeError, Double newDepthError) {

		latitude = newLatitude;
		longitude = newLongitude;
		time = newTime;
		depth = newDepth;
		latitudeError = newLatitudeError;
		longitudeError = newLongitudeError;
		timeError = newTimeError;
		depthError = newDepthError;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 * 
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Hypo(JSONObject newJSONObject) {

		// Required values
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

		// time
		if (newJSONObject.containsKey(TIME_KEY)) {
			time = Utility.getDate(newJSONObject.get(TIME_KEY).toString());
		} else {
			time = null;
		}

		// depth
		if (newJSONObject.containsKey(DEPTH_KEY)) {
			depth = (double) newJSONObject.get(DEPTH_KEY);
		} else {
			depth = null;
		}

		// optional values
		// latitude error
		if (newJSONObject.containsKey(LATITUDE_ERROR_KEY)) {
			latitudeError = (double) newJSONObject.get(LATITUDE_ERROR_KEY);
		} else {
			latitudeError = null;
		}

		// longitude error
		if (newJSONObject.containsKey(LONGITUDE_ERROR_KEY)) {
			longitudeError = (double) newJSONObject.get(LONGITUDE_ERROR_KEY);
		} else {
			longitudeError = null;
		}

		// time error
		if (newJSONObject.containsKey(TIME_ERROR_KEY)) {
			timeError = (double) newJSONObject.get(TIME_ERROR_KEY);
		} else {
			timeError = null;
		}

		// depth error
		if (newJSONObject.containsKey(DEPTH_ERROR_KEY)) {
			depthError = (double) newJSONObject.get(DEPTH_ERROR_KEY);
		} else {
			depthError = null;
		}
	}

	/**
	 * Converts the contents of the class to a json object
	 * 
	 * @return Returns a JSONObject containing the class contents
	 */
	@SuppressWarnings("unchecked")
	public JSONObject toJSON() {

		JSONObject newJSONObject = new JSONObject();

		Double jsonLatitude = getLatitude();
		Double jsonLongitude = getLongitude();
		Date jsonTime = getTime();
		Double jsonDepth = getDepth();
		Double jsonLatitudeError = getLatitudeError();
		Double jsonLongitudeError = getLongitudeError();
		Double jsonTimeError = getTimeError();
		Double jsonDepthError = getDepthError();

		// Required values
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

		// time
		if (jsonTime != null) {
			newJSONObject.put(TIME_KEY, Utility.formatDate(jsonTime));
		}

		// Optional values
		// latitude error
		if (jsonLatitudeError != null) {
			newJSONObject.put(LATITUDE_ERROR_KEY, jsonLatitudeError);
		}

		// longitude error
		if (jsonLongitudeError != null) {
			newJSONObject.put(LONGITUDE_ERROR_KEY, jsonLongitudeError);
		}

		// depth error
		if (jsonDepthError != null) {
			newJSONObject.put(DEPTH_ERROR_KEY, jsonDepthError);
		}

		// time error
		if (jsonTimeError != null) {
			newJSONObject.put(TIME_ERROR_KEY, jsonTimeError);
		}

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

		Double jsonLatitude = getLatitude();
		Double jsonLongitude = getLongitude();
		Date jsonTime = getTime();
		Double jsonDepth = getDepth();
		Double jsonLatitudeError = getLatitudeError();
		Double jsonLongitudeError = getLongitudeError();
		Double jsonTimeError = getTimeError();
		Double jsonDepthError = getDepthError();

		ArrayList<String> errorList = new ArrayList<String>();

		// Required Keys
		// latitude
		if (jsonLatitude == null) {
			// latitude not found
			errorList.add("No Latitude in Hypo Class.");
		} else if ((jsonLatitude < -90) || (jsonLatitude > 90)) {
			// invalid latitude
			errorList.add(
					"Latitude in Hypo Class not in the range of -90 to 90.");
		}

		// longitude
		if (jsonLongitude == null) {
			// longitude not found
			errorList.add("No Longitude in Hypo Class.");
		} else if ((jsonLongitude < -180) || (jsonLongitude > 180)) {
			// invalid longitude
			errorList.add(
					"Longitude in Hypo Class not in the range of -180 to 180.");
		}

		// time
		if (jsonTime == null) {
			// time not found
			errorList.add("No Time in Hypo Class.");
		}

		// depth
		if (jsonDepth == null) {
			// depth not found
			errorList.add("No Depth in Hypo Class.");
		} else if ((jsonDepth < -100) || (jsonDepth > 1500)) {
			// invalid depth
			errorList.add(
					"Depth in Hypo Class not in the range of -100 to 1500.");
		}

		// Optional Keys
		// Currently no validation criteria for optional values LatitudeError,
		// LongitudeError, TimeError, and DepthError.

		// success
		return (errorList);
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
	 * @return the time
	 */
	public Date getTime() {
		return time;
	}

	/**
	 * @return the depth
	 */
	public Double getDepth() {
		return depth;
	}

	/**
	 * @return the latitudeError
	 */
	public Double getLatitudeError() {
		return latitudeError;
	}

	/**
	 * @return the longitudeError
	 */
	public Double getLongitudeError() {
		return longitudeError;
	}

	/**
	 * @return the timeError
	 */
	public Double getTimeError() {
		return timeError;
	}

	/**
	 * @return the depthError
	 */
	public Double getDepthError() {
		return depthError;
	}

}
