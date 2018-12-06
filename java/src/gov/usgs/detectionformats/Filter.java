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
	public static final String TYPE_KEY = "Type";
	public static final String HIGHPASS_KEY = "HighPass";
	public static final String LOWPASS_KEY = "LowPass";
	public static final String UNITS_KEY = "Units";

	/**
	 * Optional string containing the type
	 */
	private final String type;

	/**
	 * Optional double containing the high pass
	 */
	private final Double highPass;

	/**
	 * Optional double containing the low pass
	 */
	private final Double lowPass;

	/**
	 * Optional string containing the units
	 */
	private final String units;

	/**
	 * The constructor for the Filter class. Initializes members to null values.
	 */
	public Filter() {

		type = null;
		highPass = null;
		lowPass = null;
		units = null;
	}

	/**
	 * The advanced constructor for the Filter class. Initializes members to
	 * provided values.
	 *
	 * @param newType
	 *            - A String containing the filter type to use (null omit)
	 * @param newHighPass
	 *            - A Double containing the highPass to use (null omit)
	 * @param newLowPass
	 *            - A Double containing the lowPass to use (null omit)
	 * @param newUnits
	 *            - A String containing the filter units to use (null omit)
	 */
	public Filter(String newType, Double newHighPass, Double newLowPass,
		String newUnits) {
		type = newType;
		highPass = newHighPass;
		lowPass = newLowPass;
		units = newUnits;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 *
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Filter(JSONObject newJSONObject) {

		// optional values
		// type
		if (newJSONObject.containsKey(TYPE_KEY)) {
			type = newJSONObject.get(TYPE_KEY).toString();
		} else {
			type = null;
		}

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

		// units
		if (newJSONObject.containsKey(UNITS_KEY)) {
			units = newJSONObject.get(UNITS_KEY).toString();
		} else {
			units = null;
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

		String jsonType = getType();
		Double jsonHighPass = getHighPass();
		Double jsonLowPass = getLowPass();
		String jsonUnits = getUnits();

		// optional values
		// type
		if (jsonType != null) {
			newJSONObject.put(TYPE_KEY, jsonType);
		}

		// highPass
		if (jsonHighPass != null) {
			newJSONObject.put(HIGHPASS_KEY, jsonHighPass);
		}

		// lowPass
		if (jsonLowPass != null) {
			newJSONObject.put(LOWPASS_KEY, jsonLowPass);
		}

		// units
		if (jsonUnits != null) {
			newJSONObject.put(UNITS_KEY, jsonUnits);
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
		if (getType() != null) {
			return (false);
		}
		if (getHighPass() != null) {
			return (false);
		}
		if (getLowPass() != null) {
			return (false);
		}
		if (getUnits() != null) {
			return (false);
		}

		return (true);
	}

	/**
	 * @return the type
	 */
	public String getType() {
		return type;
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

	/**
	 * @return the units
	 */
	public String getUnits() {
		return units;
	}
}
