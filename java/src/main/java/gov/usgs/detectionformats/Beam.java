package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import java.util.ArrayList;

/**
 * a conversion class used to create, parse, and validate beam detection data
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Beam implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String BACKAZIMUTH_KEY = "BackAzimuth";
	public static final String SLOWNESS_KEY = "Slowness";
	public static final String BACKAZIMUTHERROR_KEY = "BackAzimuthError";
	public static final String POWERRATIO_KEY = "PowerRatio";
	public static final String POWERRATIOERROR_KEY = "PowerRatioError";
	public static final String SLOWNESSERROR_KEY = "SlownessError";

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
	 * Optional Double containing the powerRatio
	 */
	private final Double powerRatio;

	/**
	 * Optional Double containing the powerRatio error
	 */
	private final Double powerRatioError;

	/**
	 * The constructor for the Beam class. Initializes members to null values.
	 */
	public Beam() {

		backAzimuth = null;
		backAzimuthError = null;
		slowness = null;
		slownessError = null;
		powerRatio = null;
		powerRatioError = null;
	}

	/**
	 * The advanced constructor for the Beam class. Initializes members to
	 * provided values.
	 *
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
	 *            - A Double containing the power ratio to use, null to omit
	 * @param newPowerRatioError
	 *            - A Double containing the power ratio error to use, null to
	 *            omit
	 */
	public Beam(Double newBackAzimuth, Double newBackAzimutherror,
			Double newSlowness, Double newSlownessError, Double newPowerRatio,
			Double newPowerRatioError) {
		backAzimuth = newBackAzimuth;
		backAzimuthError = newBackAzimutherror;
		slowness = newSlowness;
		slownessError = newSlownessError;
		powerRatio = newPowerRatio;
		powerRatioError = newPowerRatioError;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 *
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Beam(JSONObject newJSONObject) {
		// Required values
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
		// powerRatio
		if (newJSONObject.containsKey(POWERRATIO_KEY)) {
			powerRatio = (double) newJSONObject.get(POWERRATIO_KEY);
		} else {
			powerRatio = null;
		}

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

		Double jsonBackAzimuth = getBackAzimuth();
		Double jsonSlowness = getSlowness();
		Double jsonPowerRatio = getPowerRatio();
		Double jsonBackAzimuthError = getBackAzimuthError();
		Double jsonSlownessError = getSlownessError();
		Double jsonPowerRatioError = getPowerRatioError();

		// Required values
		// backAzimuth
		if (jsonBackAzimuth != null) {
			newJSONObject.put(BACKAZIMUTH_KEY, jsonBackAzimuth);
		}

		// slowness
		if (jsonSlowness != null) {
			newJSONObject.put(SLOWNESS_KEY, jsonSlowness);
		}

		// Optional values
		// powerRatio
		if (jsonPowerRatio != null) {
			newJSONObject.put(POWERRATIO_KEY, jsonPowerRatio);
		}

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

		return (newJSONObject);
	}

	/**
	 * Validates the class.
	 *
	 * @return Returns true if successful
	 */
	public boolean isValid() {
		if (getErrors().size() == 0) {
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
		Double jsonBackAzimuth = getBackAzimuth();
		Double jsonSlowness = getSlowness();
		Double jsonPowerRatio = getPowerRatio();
		Double jsonBackAzimuthError = getBackAzimuthError();
		Double jsonSlownessError = getSlownessError();
		Double jsonPowerRatioError = getPowerRatioError();

		ArrayList<String> errorList = new ArrayList<String>();

		// Required Keys
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
		// powerRatio
		if (jsonPowerRatio != null) {
			if (jsonPowerRatio < 0) {
				// invalid powerRatio
				errorList.add("Invalid PowerRatio in Beam Class.");
			}
		}

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

		// success
		return (errorList);
	}

	/**
	 * Checks to see if this object is empty
	 * 
	 * @return Returns true if empty, false otherwise.
	 */
	public boolean isEmpty() {
		if (getBackAzimuth() != null) {
			return (false);
		}
		if (getBackAzimuthError() != null) {
			return (false);
		}
		if (getSlowness() != null) {
			return (false);
		}
		if (getSlownessError() != null) {
			return (false);
		}
		if (getPowerRatio() != null) {
			return (false);
		}
		if (getPowerRatioError() != null) {
			return (false);
		}
		return (true);
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
}
