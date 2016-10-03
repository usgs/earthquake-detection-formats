package gov.usgs.detectionformats;

import java.util.ArrayList;

import org.json.simple.*;

/**
 * a conversion class used to create, parse, and validate associated data as
 * part of detection data.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Associated implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String PHASE_KEY = "Phase";
	public static final String DISTANCE_KEY = "Distance";
	public static final String AZIMUTH_KEY = "Azimuth";
	public static final String RESIDUAL_KEY = "Residual";
	public static final String SIGMA_KEY = "Sigma";

	/**
	 * Optional String containing the associated phase name
	 */
	private final String phase;

	/**
	 * Optional double containing the associated distance
	 */
	private final Double distance;

	/**
	 * Optional double containing the associated azimuth
	 */
	private final Double azimuth;

	/**
	 * Optional double containing the associated residual
	 */
	private final Double residual;

	/**
	 * Optional double containing the associated sigma
	 */
	private final Double sigma;

	/**
	 * The constructor for the Associated class. Initializes members to null
	 * values.
	 */
	public Associated() {

		phase = null;
		distance = null;
		azimuth = null;
		residual = null;
		sigma = null;
	}

	/**
	 * The advanced constructor for the Associated class. Initializes members to
	 * provided values.
	 *
	 * @param newPhase
	 *            - A String containing the phase name to use (null omit)
	 * @param newDistance
	 *            - A double containing the distance to use (null omit)
	 * @param newAzimuth
	 *            - A double containing the azimuth to use (null omit)
	 * @param newResidual
	 *            - A double containing the residual to use (null omit)
	 * @param newSigma
	 *            - A double containing the sigma to use (null omit)
	 */
	public Associated(String newPhase, Double newDistance, Double newAzimuth,
			Double newResidual, Double newSigma) {

		phase = newPhase;
		distance = newDistance;
		azimuth = newAzimuth;
		residual = newResidual;
		sigma = newSigma;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 *
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Associated(JSONObject newJSONObject) {

		// optional values
		// phase
		if (newJSONObject.containsKey(PHASE_KEY)) {
			phase = (String) newJSONObject.get(PHASE_KEY);
		} else {
			phase = null;
		}

		// distance
		if (newJSONObject.containsKey(DISTANCE_KEY)) {
			distance = (double) newJSONObject.get(DISTANCE_KEY);
		} else {
			distance = null;
		}

		// azimuth
		if (newJSONObject.containsKey(AZIMUTH_KEY)) {
			azimuth = (double) newJSONObject.get(AZIMUTH_KEY);
		} else {
			azimuth = null;
		}

		// residual
		if (newJSONObject.containsKey(RESIDUAL_KEY)) {
			residual = (double) newJSONObject.get(RESIDUAL_KEY);
		} else {
			residual = null;
		}

		// sigma
		if (newJSONObject.containsKey(SIGMA_KEY)) {
			sigma = (double) newJSONObject.get(SIGMA_KEY);
		} else {
			sigma = null;
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

		String jsonPhase = getPhase();
		Double jsonDistance = getDistance();
		Double jsonAzimuth = getAzimuth();
		Double jsonResidual = getResidual();
		Double jsonSigma = getSigma();

		// optional values
		// phase
		if (jsonPhase != null) {
			newJSONObject.put(PHASE_KEY, jsonPhase);
		}

		// distance
		if (jsonDistance != null) {
			newJSONObject.put(DISTANCE_KEY, jsonDistance);
		}

		// azimuth
		if (jsonAzimuth != null) {
			newJSONObject.put(AZIMUTH_KEY, jsonAzimuth);
		}

		// residual
		if (jsonResidual != null) {
			newJSONObject.put(RESIDUAL_KEY, jsonResidual);
		}

		// sigma
		if (jsonSigma != null) {
			newJSONObject.put(SIGMA_KEY, jsonSigma);
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

		String jsonPhase = getPhase();
		Double jsonDistance = getDistance();
		Double jsonAzimuth = getAzimuth();

		ArrayList<String> errorList = new ArrayList<String>();

		// Optional Keys
		// phase
		if (jsonPhase != null) {
			// check phase string
			if (jsonPhase.isEmpty()) {
				// phase empty
				errorList.add("Empty Phase in Associated Class.");
			} else if (!Utility.isStringAlpha(jsonPhase)) {
				// invalid phase
				errorList.add("Phase did not validate in Associated class.");
			}
		}

		// distance
		if (jsonDistance != null) {
			// check distance
			if (jsonDistance < 0) {
				// distance negative (invalid)
				errorList.add("Invalid Distance in Associated Class.");
			}
		}

		// azimuth
		if (jsonAzimuth != null) {
			// check azimuth
			if (jsonAzimuth < 0) {
				// azimuth negative (invalid)
				errorList.add("Invalid Azimuth in Associated Class.");
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
		if (phase != null) {
			return (false);
		}
		if (distance != null) {
			return (false);
		}
		if (azimuth != null) {
			return (false);
		}
		if (residual != null) {
			return (false);
		}
		if (sigma != null) {
			return (false);
		}

		return (true);
	}

	/**
	 * @return the phase
	 */
	public String getPhase() {
		return phase;
	}

	/**
	 * @return the distance
	 */
	public Double getDistance() {
		return distance;
	}

	/**
	 * @return the azimuth
	 */
	public Double getAzimuth() {
		return azimuth;
	}

	/**
	 * @return the residual
	 */
	public Double getResidual() {
		return residual;
	}

	/**
	 * @return the sigma
	 */
	public Double getSigma() {
		return sigma;
	}
}
