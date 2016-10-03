package gov.usgs.detectionformats;

import java.util.ArrayList;

import org.json.simple.JSONObject;

/**
 * a conversion class used to create, parse, and validate filter data as part of
 * detection data.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Filter implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String HIGHPASS_KEY = "HighPass";
	public static final String LOWPASS_KEY = "LowPass";

	/**
	 * Optional double containing the high pass
	 */
	private final Double highPass;

	/**
	 * Optional double containing the low pass
	 */
	private final Double lowPass;

	/**
	 * The constructor for the Filter class. Initializes members to null values.
	 */
	public Filter() {

		highPass = null;
		lowPass = null;
	}

	/**
	 * The advanced constructor for the Filter class. Initializes members to
	 * provided values.
	 *
	 * @param newHighPass
	 *            - A Double containing the highPass to use (null omit)
	 * @param newLowPass
	 *            - A Double containing the lowPass to use (null omit)
	 */
	public Filter(Double newHighPass, Double newLowPass) {

		highPass = newHighPass;
		lowPass = newLowPass;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 *
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Filter(JSONObject newJSONObject) {

		// optional values
		// highPass
		if (newJSONObject.containsKey(HIGHPASS_KEY)) {
			highPass = Double
					.valueOf(newJSONObject.get(HIGHPASS_KEY).toString());
		} else {
			highPass = null;
		}

		// lowPass
		if (newJSONObject.containsKey(LOWPASS_KEY)) {
			lowPass = Double.valueOf(newJSONObject.get(LOWPASS_KEY).toString());
		} else {
			lowPass = null;
		}
	}

	/**
	 * Converts the contents of the class to a JSON object
	 *
	 * @return Returns a JSONObject containing the class contents
	 */
	@SuppressWarnings("unchecked")
	public JSONObject toJSON() {

		JSONObject newJSONObject = new JSONObject();

		Double jsonHighPass = getHighPass();
		Double jsonLowPass = getLowPass();

		// optional values
		// highPass
		if (jsonHighPass != null) {
			newJSONObject.put(HIGHPASS_KEY, jsonHighPass);
		}

		// lowPass
		if (jsonLowPass != null) {
			newJSONObject.put(LOWPASS_KEY, jsonLowPass);
		}

		// return valid object
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
		// since all keys are optional and they're numbers...
		// success
		return (null);
	}

	/**
	 * Checks to see if this object is empty
	 *
	 * @return Returns true if empty, false otherwise.
	 */
	public boolean isEmpty() {
		if (getHighPass() != null) {
			return (false);
		}
		if (getLowPass() != null) {
			return (false);
		}

		return (true);
	}

	/**
	 * @return the highPass
	 */
	public Double getHighPass() {
		return highPass;
	}

	/**
	 * @return the lowPass
	 */
	public Double getLowPass() {
		return lowPass;
	}
}
