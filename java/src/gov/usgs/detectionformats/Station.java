package gov.usgs.detectionformats;

import java.util.ArrayList;

import org.json.simple.JSONObject;

/**
 * a conversion class used to create, parse, and validate station location and
 * quality data
 * 
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Station implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String TYPE_KEY = "Type";
	public static final String SITE_KEY = "Site";
	public static final String LATITUDE_KEY = "Latitude";
	public static final String LONGITUDE_KEY = "Longitude";
	public static final String ELEVATION_KEY = "Elevation";
	public static final String QUALITY_KEY = "Quality";
	public static final String ENABLE_KEY = "Enable";
	public static final String USEFORTELESEISMIC_KEY = "UseForTeleseismic";

	/**
	 * Required type identifier for this Station
	 */
	private final String type;

	/**
	 * Required site.
	 */
	private final Site site;

	/**
	 * Required Double containing the latitude
	 */
	private final Double latitude;

	/**
	 * Required Double containing the longitude
	 */
	private final Double longitude;

	/**
	 * Required Double containing the elevation
	 */
	private final Double elevation;

	/**
	 * Optional Double containing the quality
	 */
	private final Double quality;

	/**
	 * Optional Boolean containing enable flag
	 */
	private final Boolean enable;

	/**
	 * Optional Boolean containing the use for teleseismic flag
	 */
	private final Boolean useForTeleseismic;

	/**
	 * The constructor for the Station class. Initializes members to null
	 * values.
	 */
	public Station() {

		type = "Station";
		site = null;
		latitude = null;
		longitude = null;
		elevation = null;
		quality = null;
		enable = null;
		useForTeleseismic = null;
	}

	/**
	 * The advanced constructor for the Station class. Initializes members to
	 * provided values.
	 * 
	 * @param newStation
	 *            - A String containing the station to use
	 * @param newChannel
	 *            - A String containing the channel to use
	 * @param newNetwork
	 *            - A String containing the network to use
	 * @param newLocation
	 *            - A String containing the location to use
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newElevation
	 *            - A Double containing the elevation to use
	 * @param newQuality
	 *            - A Double containing the quality to use, null to omit
	 * @param newEnable
	 *            - A Boolean containing the enable flag to use, null to omit
	 * @param newUseForTeleseismic
	 *            - A Boolean containing the use for teleseismic flag to use,
	 *            null to omit
	 */
	public Station(String newStation, String newChannel, String newNetwork,
			String newLocation, Double newLatitude, Double newLongitude,
			Double newElevation, Double newQuality, Boolean newEnable,
			Boolean newUseForTeleseismic) {

		this(new Site(newStation, newChannel, newNetwork, newLocation),
				newLatitude, newLongitude, newElevation, newQuality, newEnable,
				newUseForTeleseismic);
	}

	/**
	 * The alternate advanced constructor for the Station class. Initializes
	 * members to provided values.
	 * 
	 * @param newSite
	 *            - A Site containing the site to use
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newElevation
	 *            - A Double containing the elevation to use
	 * @param newQuality
	 *            - A Double containing the quality to use, null to omit
	 * @param newEnable
	 *            - A Boolean containing the enable flag to use, null to omit
	 * @param newUseForTeleseismic
	 *            - A Boolean containing the use for teleseismic flag to use,
	 *            null to omit
	 */
	public Station(Site newSite, Double newLatitude, Double newLongitude,
			Double newElevation, Double newQuality, Boolean newEnable,
			Boolean newUseForTeleseismic) {

		type = "Station";
		site = newSite;
		latitude = newLatitude;
		longitude = newLongitude;
		elevation = newElevation;
		quality = newQuality;
		enable = newEnable;
		useForTeleseismic = newUseForTeleseismic;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 * 
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Station(JSONObject newJSONObject) {

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

		// elevation
		if (newJSONObject.containsKey(ELEVATION_KEY)) {
			elevation = (double) newJSONObject.get(ELEVATION_KEY);
		} else {
			elevation = null;
		}

		// Optional values
		// quality
		if (newJSONObject.containsKey(QUALITY_KEY)) {
			quality = (double) newJSONObject.get(QUALITY_KEY);
		} else {
			quality = null;
		}

		// enable
		if (newJSONObject.containsKey(ENABLE_KEY)) {
			enable = (boolean) newJSONObject.get(ENABLE_KEY);
		} else {
			enable = null;
		}

		// useforteleseimic
		if (newJSONObject.containsKey(USEFORTELESEISMIC_KEY)) {
			useForTeleseismic = (boolean) newJSONObject
					.get(USEFORTELESEISMIC_KEY);
		} else {
			useForTeleseismic = null;
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
		Double jsonLatitude = getLatitude();
		Double jsonLongitude = getLongitude();
		Double jsonElevation = getElevation();
		Double jsonQuality = getQuality();
		Boolean jsonEnable = getEnable();
		Boolean jsonUseForTeleseismic = getUseForTeleseismic();

		// Required values
		// Type
		newJSONObject.put(TYPE_KEY, jsonType);

		// site
		if (jsonSite != null) {
			newJSONObject.put(SITE_KEY, jsonSite.toJSON());
		}

		// latitude
		if (jsonLatitude != null) {
			newJSONObject.put(LATITUDE_KEY, jsonLatitude);
		}

		// longitude
		if (jsonLongitude != null) {
			newJSONObject.put(LONGITUDE_KEY, jsonLongitude);
		}

		// elevation
		if (jsonElevation != null) {
			newJSONObject.put(ELEVATION_KEY, jsonElevation);
		}
		
		// Optional values
		// quality
		if (jsonQuality != null) {
			newJSONObject.put(QUALITY_KEY, jsonQuality);
		}

		// enable
		if (jsonEnable != null) {
			newJSONObject.put(ENABLE_KEY, jsonEnable);
		}

		// useForTeleseismic
		if (jsonUseForTeleseismic != null) {
			newJSONObject.put(USEFORTELESEISMIC_KEY, jsonUseForTeleseismic);
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

		String jsonType = getType();
		Site jsonSite = getSite();
		Double jsonLatitude = getLatitude();
		Double jsonLongitude = getLongitude();
		Double jsonElevation = getElevation();
//		Double jsonQuality = getQuality();
//		Boolean jsonEnable = getEnable();
//		Boolean jsonUseForTeleseismic = getUseForTeleseismic();

		ArrayList<String> errorList = new ArrayList<String>();

		// Required Keys
		// type
		if (jsonType == null) {
			// type not found
			errorList.add("No Type in Station Class.");
		} else if (jsonType.isEmpty()) {
			// type empty
			errorList.add("Empty Type in Station Class.");
		} else if (!jsonType.equals("Station")) {
			// wrong type
			errorList.add("Non-Station type in Station Class.");
		}

		// site
		if (jsonSite == null) {
			// site not found
			errorList.add("No Site in Station Class.");
		} else if (!jsonSite.isValid()) {
			// site invalid
			errorList.add("Invalid Site in Station Class.");
		}

		// latitude
		if (jsonLatitude == null) {
			// latitude not found
			errorList.add("No Latitude in Station Class.");
		} else if ((jsonLatitude < -90) || (jsonLatitude > 90)) {
			// invalid latitude
			errorList.add(
					"Latitude in Station Class not in the range of -90 to 90.");
		}

		// longitude
		if (jsonLongitude == null) {
			// longitude not found
			errorList.add("No Longitude in Station Class.");
		} else if ((jsonLongitude < -180) || (jsonLongitude > 180)) {
			// invalid longitude
			errorList.add(
					"Longitude in Station Class not in the range of -180 to 180.");
		}
		
		// elevation
		if (jsonElevation == null) {
			// elevation not found
			errorList.add("No Elevation in Station Class.");
		} 
		

		// Optional Keys
		// Currently no validation criteria for optional values Quality,
		// Enable, and UseForTeleseismic.

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
	 * @return the elevation
	 */
	public Double getElevation() {
		return elevation;
	}

	/**
	 * @return the quality
	 */
	public Double getQuality() {
		return quality;
	}

	/**
	 * @return the enable
	 */
	public Boolean getEnable() {
		return enable;
	}

	/**
	 * @return the useForTeleseismic
	 */
	public Boolean getUseForTeleseismic() {
		return useForTeleseismic;
	}
	
	
}
