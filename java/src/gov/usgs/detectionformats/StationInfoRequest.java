package gov.usgs.detectionformats;

import java.util.ArrayList;

import org.json.simple.JSONObject;

/**
 * a conversion class used to create, parse, and validate a station information
 * request
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class StationInfoRequest {
	/**
	 * JSON Keys
	 */
	public static final String TYPE_KEY = "Type";
	public static final String SITE_KEY = "Site";
	public static final String SOURCE_KEY = "Source";

	/**
	 * Required type identifier for this StationInfo
	 */
	private final String type;

	/**
	 * Required site.
	 */
	private final Site site;

	/**
	 * Required source.
	 */
	private final Source source;

	/**
	 * The constructor for the StationInfoRequest class. Initializes members to
	 * null values.
	 */
	public StationInfoRequest() {

		type = "StationInfoRequest";
		site = null;
		source = null;
	}

	/**
	 * The advanced constructor for the StationInfoRequest class. Initializes
	 * members to provided values.
	 *
	 * @param newStation
	 *            - A String containing the station to use
	 * @param newChannel
	 *            - A String containing the channel to use
	 * @param newNetwork
	 *            - A String containing the network to use
	 * @param newLocation
	 *            - A String containing the location to use
	 * @param newAgencyID
	 *            - A String containing the agencyid to use, null to omit
	 * @param newAuthor
	 *            - A String containing the author to use, null to omit
	 */
	public StationInfoRequest(String newStation, String newChannel,
			String newNetwork, String newLocation, String newAgencyID,
			String newAuthor) {
		this(new Site(newStation, newChannel, newNetwork, newLocation),
				new Source(newAgencyID, newAuthor));
	}

	/**
	 * The alternate advanced constructor for the StationInfoRequest class.
	 * Initializes members to provided values.
	 *
	 * @param newSite
	 *            - A Site containing the site to use
	 * @param newSource
	 *            - A Source containing the source to use
	 */
	public StationInfoRequest(Site newSite, Source newSource) {
		type = "StationInfoRequest";
		site = newSite;
		source = newSource;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 *
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public StationInfoRequest(JSONObject newJSONObject) {
		// Required values
		// type
		if (newJSONObject.containsKey(TYPE_KEY)) {
			type = newJSONObject.get(TYPE_KEY).toString();
		} else {
			type = null;
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
		Site jsonSite = getSite();
		Source jsonSource = getSource();

		// Required values
		// Type
		newJSONObject.put(TYPE_KEY, jsonType);

		// site
		if (jsonSite != null) {
			newJSONObject.put(SITE_KEY, jsonSite.toJSON());
		}

		// informationRequestor
		if (jsonSource != null) {
			newJSONObject.put(SOURCE_KEY, jsonSource.toJSON());
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
		String jsonType = getType();
		Site jsonSite = getSite();
		Source jsonSource = getSource();

		ArrayList<String> errorList = new ArrayList<String>();

		// Required Keys
		// type
		if (jsonType == null) {
			// type not found
			errorList.add("No Type in StationInfoRequest Class.");
		} else if (jsonType.isEmpty()) {
			// type empty
			errorList.add("Empty Type in StationInfoRequest Class.");
		} else if (!jsonType.equals("StationInfoRequest")) {
			// wrong type
			errorList.add("Non-StationInfoRequest type in StationInfoRequest Class.");
		}

		// site
		if (jsonSite == null) {
			// site not found
			errorList.add("No Site in StationInfoRequest Class.");
		} else if (!jsonSite.isValid()) {
			// site invalid
			errorList.add("Invalid Site in StationInfoRequest Class.");
		}

		// source
		if (jsonSource == null) {
			// source not found
			errorList.add("No Source in StationInfoRequest Class.");
		} else if (!jsonSource.isValid()) {
			// source invalid
			errorList.add("Invalid Source in StationInfoRequest Class.");
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
}
