package gov.usgs.detectionformats;

import java.util.*;

import org.json.simple.JSONObject;
import org.json.simple.JSONArray;

/**
 * a conversion class used to create, parse, and validate origin detection data
 * 
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Origin implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String TYPE_KEY = "Type";
	public static final String ID_KEY = "ID";
	public static final String SOURCE_KEY = "Source";
	public static final String LATITUDE_KEY = "Latitude";
	public static final String LONGITUDE_KEY = "Longitude";
	public static final String TIME_KEY = "Time";
	public static final String DEPTH_KEY = "Depth";
	public static final String ORIGINTYPE_KEY = "OriginType";
	public static final String EVENTTYPE_KEY = "EventType";
	public static final String BAYES_KEY = "Bayes";
	public static final String MINIMUMDISTANCE_KEY = "MinimumDistance";
	public static final String RMS_KEY = "RMS";
	public static final String GAP_KEY = "Gap";
	public static final String DATA_KEY = "Data";

	/**
	 * Required type identifier for this Origin
	 */
	private final String type;

	/**
	 * Required unique identifier for this Origin
	 */
	private final String id;

	/**
	 * Required source.
	 */
	private final Source source;

	/**
	 * Required Double containing the Origin latitude
	 */
	private final Double latitude;

	/**
	 * Required Double containing the Origin longitude
	 */
	private final Double longitude;

	/**
	 * Required time for this Origin
	 */
	private final Date time;

	/**
	 * Required Double containing the Origin depth
	 */
	private final Double depth;

	/**
	 * Optional String containing the origin type of this Origin valid values
	 * are "new" "Update", "Final", or "Retract"
	 */
	private final String originType;

	/**
	 * Optional String containing the event type of this Origin valid values are
	 * "earthquake" or "blast"
	 */
	private final String eventType;

	/**
	 * Required Double containing the Origin bayesian statistic
	 */
	private final Double bayes;

	/**
	 * Required Double containing the Origin minimum distance
	 */
	private final Double minimumDistance;

	/**
	 * Required Double containing the Origin rms
	 */
	private final Double rms;

	/**
	 * Required Double containing the Origin gap
	 */
	private final Double gap;

	/**
	 * An optional vector of Pick objects used to generate this origin
	 */
	private final ArrayList<Pick> pickData;

	/**
	 * An optional vector of Beam objects used to generate this origin
	 */
	private final ArrayList<Beam> beamData;

	/**
	 * An optional vector of Origin objects used to generate this origin
	 */
	private final ArrayList<Correlation> correlationData;

	/**
	 * The constructor for the Pick class. Initializes members to null values.
	 */
	public Origin() {

		type = "Origin";
		source = null;
		id = null;
		latitude = null;
		longitude = null;
		depth = null;
		time = null;
		originType = null;
		eventType = null;
		bayes = null;
		minimumDistance = null;
		rms = null;
		gap = null;
		pickData = null;
		beamData = null;
		correlationData = null;
	}

	/**
	 * Advanced constructor
	 * 
	 * The advanced constructor for the Origin class. Initializes members to
	 * provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newAgencyID
	 *            - A String containing the agencyid to use
	 * @param newAuthor
	 *            - A String containing the author to use
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newTime
	 *            - A Date containing the origin time string to use
	 * @param newDepth
	 *            - A Double containing the depth to use
	 * @param newOriginType
	 *            - A String containing the origin type to use, null to omit
	 * @param newEventType
	 *            - A String containing the event type to use, null to omit
	 * @param newBayes
	 *            - A Double containing the bayes to use, null to omit
	 * @param newMinimumDistance
	 *            - A Double containing the minimum distance to use, null to
	 *            omit
	 * @param newRMS
	 *            - A Double containing the rms to use, null to omit
	 * @param newGap
	 *            - A Double containing the gap to use, null to omit
	 * @param newPickData
	 *            - A ArrayList&lt;Pick&gt; newPickData containing the data that
	 *            went into this origin, null to omit
	 * @param newBeamData
	 *            - A ArrayList&lt;Beam&gt; newBeamData containing the data that
	 *            went into this origin, null to omit
	 * @param newCorrelationData
	 *            - A ArrayList&lt;Origin&gt; newCorrelationData containing the
	 *            data that went into this origin, null to omit
	 */
	public Origin(String newID, String newAgencyID, String newAuthor,
			Double newLatitude, Double newLongitude, Date newTime,
			Double newDepth, String newOriginType, String newEventType,
			Double newBayes, Double newMinimumDistance, Double newRMS,
			Double newGap, ArrayList<Pick> newPickData,
			ArrayList<Beam> newBeamData,
			ArrayList<Correlation> newCorrelationData) {

		this(newID, new Source(newAgencyID, newAuthor), newLatitude,
				newLongitude, newTime, newDepth, newOriginType, newEventType,
				newBayes, newMinimumDistance, newRMS, newGap, newPickData,
				newBeamData, newCorrelationData);
	}

	/**
	 * Alternate advanced constructor
	 * 
	 * The alternate advanced constructor for the Origin class. Initializes
	 * members to provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSource
	 *            - A Source Object containing the source to use
	 * @param newLatitude
	 *            - A Double containing the latitude to use
	 * @param newLongitude
	 *            - A Double containing the longitude to use
	 * @param newTime
	 *            - A Date containing the new origin time string to use
	 * @param newDepth
	 *            - A Double containing the depth to use
	 * @param newOriginType
	 *            - A String containing the origin type to use, null to omit
	 * @param newEventType
	 *            - A String containing the event type to use, null to omit
	 * @param newBayes
	 *            - A Double containing the bayes to use, null to omit
	 * @param newMinimumDistance
	 *            - A Double containing the minimum distance to use, null to
	 *            omit
	 * @param newRMS
	 *            - A Double containing the rms to use, null to omit
	 * @param newGap
	 *            - A Double containing the gap to use, null to omit
	 * @param newPickData
	 *            - A Vector&lt;Pick&gt; newPickData containing the data that
	 *            went into this origin, null to omit
	 * @param newBeamData
	 *            - A Vector&lt;Beam&gt; newBeamData containing the data that
	 *            went into this origin, null to omit
	 * @param newCorrelationData
	 *            - A Vector&lt;Origin&gt; newCorrelationData containing the
	 *            data that went into this origin, null to omit
	 */
	public Origin(String newID, Source newSource, Double newLatitude,
			Double newLongitude, Date newTime, Double newDepth,
			String newOriginType, String newEventType, Double newBayes,
			Double newMinimumDistance, Double newRMS, Double newGap,
			ArrayList<Pick> newPickData, ArrayList<Beam> newBeamData,
			ArrayList<Correlation> newCorrelationData) {

		type = "Origin";
		id = newID;
		source = newSource;
		latitude = newLatitude;
		longitude = newLongitude;
		depth = newDepth;
		time = newTime;
		originType = newOriginType;
		eventType = newEventType;
		bayes = newBayes;
		minimumDistance = newMinimumDistance;
		rms = newRMS;
		gap = newGap;

		pickData = newPickData;
		beamData = newBeamData;
		correlationData = newCorrelationData;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 * 
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Origin(JSONObject newJSONObject) {

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

		// source
		if (newJSONObject.containsKey(SOURCE_KEY)) {
			source = new Source((JSONObject) newJSONObject.get(SOURCE_KEY));
		} else {
			source = null;
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

		// time
		if (newJSONObject.containsKey(TIME_KEY)) {
			time = Utility.getDate(newJSONObject.get(TIME_KEY).toString());
		} else {
			time = null;
		}

		// Optional values
		// originType
		if (newJSONObject.containsKey(ORIGINTYPE_KEY)) {
			originType = (String) newJSONObject.get(ORIGINTYPE_KEY);
		} else {
			originType = null;
		}

		// eventType
		if (newJSONObject.containsKey(EVENTTYPE_KEY)) {
			eventType = (String) newJSONObject.get(EVENTTYPE_KEY);
		} else {
			eventType = null;
		}

		// bayes
		if (newJSONObject.containsKey(BAYES_KEY)) {
			bayes = (double) newJSONObject.get(BAYES_KEY);
		} else {
			bayes = null;
		}

		// minimumDistance
		if (newJSONObject.containsKey(MINIMUMDISTANCE_KEY)) {
			minimumDistance = (double) newJSONObject.get(MINIMUMDISTANCE_KEY);
		} else {
			minimumDistance = null;
		}

		// rms
		if (newJSONObject.containsKey(RMS_KEY)) {
			rms = (double) newJSONObject.get(RMS_KEY);
		} else {
			rms = null;
		}

		// gap
		if (newJSONObject.containsKey(GAP_KEY)) {
			gap = (double) newJSONObject.get(GAP_KEY);
		} else {
			gap = null;
		}

		// Data
		if (newJSONObject.containsKey(DATA_KEY)) {

			pickData = new ArrayList<Pick>();
			beamData = new ArrayList<Beam>();
			correlationData = new ArrayList<Correlation>();

			// get the array
			JSONArray dataArray = (JSONArray) newJSONObject.get(DATA_KEY);

			if ((dataArray != null) && (!dataArray.isEmpty())) {

				// go through the whole array
				for (int i = 0; i < dataArray.size(); i++) {

					// get the object
					JSONObject dataObject = (JSONObject) dataArray.get(i);

					// check for type
					if (dataObject.containsKey(TYPE_KEY)) {

						// Route based on type
						String TypeString = (String) dataObject.get(TYPE_KEY);
						if (TypeString.equals("Pick")) {

							// add to vector
							pickData.add(new Pick(dataObject));
						} else if (TypeString.equals("Beam")) {

							// add to vector
							beamData.add(new Beam(dataObject));
						} else if (TypeString.equals("Correlation")) {

							// add to vector
							correlationData.add(new Correlation(dataObject));

						}
					}
				}
			}
		} else {
			pickData = null;
			beamData = null;
			correlationData = null;
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

		String jsonType = getType();
		String jsonID = getID();
		Source jsonSource = getSource();
		Double jsonLatitude = getLatitude();
		Double jsonLongitude = getLongitude();
		Double jsonDepth = getDepth();
		Date jsonTime = getTime();
		String jsonOriginType = getOriginType();
		String jsonEventType = getEventType();
		Double jsonBayes = getBayes();
		Double jsonMinimumDistance = getMinimumDistance();
		Double jsonRMS = getRMS();
		Double jsonGap = getGap();
		ArrayList<Pick> jsonPickData = getPickData();
		ArrayList<Beam> jsonBeamData = getBeamData();
		ArrayList<Correlation> jsonCorrelationData = getCorrelationData();

		// Required values
		// Type
		newJSONObject.put(TYPE_KEY, jsonType);

		// id
		if (jsonID != null) {
			newJSONObject.put(ID_KEY, jsonID);
		}

		// source
		if (jsonSource != null) {
			newJSONObject.put(SOURCE_KEY, jsonSource.toJSON());
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

		// time
		if (jsonTime != null) {
			newJSONObject.put(TIME_KEY, Utility.formatDate(jsonTime));
		}

		// Optional values
		// originType
		if (jsonOriginType != null) {
			newJSONObject.put(ORIGINTYPE_KEY, jsonOriginType);
		}

		// eventType
		if (jsonEventType != null) {
			newJSONObject.put(EVENTTYPE_KEY, jsonEventType);
		}

		// bayes
		if (jsonBayes != null) {
			newJSONObject.put(BAYES_KEY, jsonBayes);
		}

		// minimumDistance
		if (jsonMinimumDistance != null) {
			newJSONObject.put(MINIMUMDISTANCE_KEY, jsonMinimumDistance);
		}

		// rms
		if (jsonRMS != null) {
			newJSONObject.put(RMS_KEY, jsonRMS);
		}

		// gap
		if (jsonGap != null) {
			newJSONObject.put(GAP_KEY, jsonGap);
		}

		// Data
		JSONArray dataArray = new JSONArray();

		// Picks
		if ((jsonPickData != null) && (!jsonPickData.isEmpty())) {

			// enumerate through the whole arraylist
			for (Iterator<Pick> pickIterator = jsonPickData
					.iterator(); pickIterator.hasNext();) {

				// convert pick to JSON object
				JSONObject pickObject = ((Pick) pickIterator.next()).toJSON();

				dataArray.add(pickObject);
			}
		}

		// Beams
		if ((jsonBeamData != null) && (!jsonBeamData.isEmpty())) {

			// enumerate through the whole arraylist
			for (Iterator<Beam> beamIterator = jsonBeamData
					.iterator(); beamIterator.hasNext();) {

				// convert beam to JSON object
				JSONObject beamObject = ((Beam) beamIterator.next()).toJSON();

				dataArray.add(beamObject);
			}
		}

		// Correlation
		if ((jsonCorrelationData != null) && (!jsonCorrelationData.isEmpty())) {

			// enumerate through the whole arraylist
			for (Iterator<Correlation> correlationIterator = jsonCorrelationData
					.iterator(); correlationIterator.hasNext();) {

				// convert beam to JSON object
				JSONObject correlationObject = ((Correlation) correlationIterator
						.next()).toJSON();

				dataArray.add(correlationObject);
			}
		}

		if (!dataArray.isEmpty()) {
			newJSONObject.put(DATA_KEY, dataArray);
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
		String jsonID = getID();
		Source jsonSource = getSource();
		Double jsonLatitude = getLatitude();
		Double jsonLongitude = getLongitude();
		Double jsonDepth = getDepth();
		Date jsonTime = getTime();
		String jsonOriginType = getOriginType();
		String jsonEventType = getEventType();
		Double jsonBayes = getBayes();
		Double jsonMinimumDistance = getMinimumDistance();
		Double jsonGap = getGap();
		ArrayList<Pick> jsonPickData = getPickData();
		ArrayList<Beam> jsonBeamData = getBeamData();
		ArrayList<Correlation> jsonCorrelationData = getCorrelationData();

		ArrayList<String> errorList = new ArrayList<String>();

		// Required Keys
		// type
		if (jsonType == null) {
			// type not found
			errorList.add("No Type in Origin Class.");
		} else if (jsonType.isEmpty()) {
			// type empty
			errorList.add("Empty Type in Origin Class.");
		} else if (!jsonType.equals("Origin")) {
			// wrong type
			errorList.add("Non-Origin type in Origin Class.");
		}

		// id
		if (jsonID == null) {
			// id not found
			errorList.add("No ID in Origin Class.");
		} else if (jsonID.isEmpty()) {
			// id empty
			errorList.add("Empty ID in Origin Class.");
		}

		// source
		if (jsonSource == null) {
			// source not found
			errorList.add("No Source in Origin Class.");
		} else if (!jsonSource.isValid()) {
			// source invalid
			errorList.add("Invalid Source in Origin Class.");
		}

		// latitude
		if (jsonLatitude == null) {
			// latitude not found
			errorList.add("No Latitude in Origin Class.");
		} else if ((jsonLatitude < -90) || (jsonLatitude > 90)) {
			// invalid latitude
			errorList.add(
					"Latitude in Origin Class not in the range of -90 to 90.");
		}

		// longitude
		if (jsonLongitude == null) {
			// longitude not found
			errorList.add("No Longitude in Origin Class.");
		} else if ((jsonLongitude < -180) || (jsonLongitude > 180)) {
			// invalid longitude
			errorList.add(
					"Longitude in Origin Class not in the range of -180 to 180.");
		}

		// depth
		if (jsonDepth == null) {
			// depth not found
			errorList.add("No Depth in Origin Class.");
		} else if ((jsonDepth < -100) || (jsonDepth > 1500)) {
			// invalid depth
			errorList.add(
					"Depth in Origin Class not in the range of -100 to 1500.");
		}

		// time
		if (jsonTime == null) {
			// time not found
			errorList.add("No Time in Origin Class.");
		}

		// Optional Keys
		// originType
		if (jsonOriginType != null) {

			boolean match = false;
			if (jsonOriginType.equals("New")) {
				match = true;
			} else if (jsonOriginType.equals("Update")) {
				match = true;
			} else if (jsonOriginType.equals("Final")) {
				match = true;
			} else if (jsonOriginType.equals("Retract")) {
				match = true;
			} else {
				match = false;
			}

			if (!match) {
				// invalid originType
				errorList.add("Invalid OriginType in Origin Class.");
			}
		}

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
				errorList.add("Invalid EventType in Origin Class.");
			}
		}

		// bayes
		if (jsonBayes != null) {
			if (jsonBayes < 0) {
				// invalid bayes
				errorList.add("Bayes in Origin Class is not greater than 0.");
			}
		}

		// minimumDistance
		if (jsonMinimumDistance != null) {
			if (jsonMinimumDistance < 0) {
				// invalid minimum distance
				errorList.add(
						"MinimumDistance in Origin Class  is not greater than 0.");
			}
		}

		// gap
		if (jsonGap != null) {
			if ((jsonGap < 0) || (jsonGap > 360)) {
				// invalid Magnitude
				errorList.add(
						"Gap in Origin Class not in the range of 0 to 360.");
			}
		}

		// Data
		// Picks
		if ((jsonPickData != null) && (!jsonPickData.isEmpty())) {

			// enumerate through the whole arraylist
			for (Iterator<Pick> pickIterator = jsonPickData
					.iterator(); pickIterator.hasNext();) {

				// convert pick to JSON object
				Pick jsonPick = ((Pick) pickIterator.next());

				if (!jsonPick.isValid()) {
					errorList.add("Invalid Pick in PickData in Origin Class");
					break;
				}
			}
		}

		// Beams
		if ((jsonBeamData != null) && (!jsonBeamData.isEmpty())) {

			// enumerate through the whole arraylist
			for (Iterator<Beam> beamIterator = jsonBeamData
					.iterator(); beamIterator.hasNext();) {

				// convert beam to JSON object
				Beam jsonBeam = ((Beam) beamIterator.next());

				if (!jsonBeam.isValid()) {
					errorList.add("Invalid Beam in BeamData in Origin Class");
					break;
				}
			}
		}

		// Correlation
		if ((jsonCorrelationData != null) && (!jsonCorrelationData.isEmpty())) {

			// enumerate through the whole arraylist
			for (Iterator<Correlation> correlationIterator = jsonCorrelationData
					.iterator(); correlationIterator.hasNext();) {

				// convert beam to JSON object
				Correlation jsonCorrelation = ((Correlation) correlationIterator
						.next());

				if (!jsonCorrelation.isValid()) {
					errorList.add(
							"Invalid Correlation in CorrelationData in Origin Class");
					break;
				}
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
	 * @return the source
	 */
	public Source getSource() {
		return source;
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
	 * @return the originType
	 */
	public String getOriginType() {
		return originType;
	}

	/**
	 * @return the eventType
	 */
	public String getEventType() {
		return eventType;
	}

	/**
	 * @return the bayes
	 */
	public Double getBayes() {
		return bayes;
	}

	/**
	 * @return the minimumDistance
	 */
	public Double getMinimumDistance() {
		return minimumDistance;
	}

	/**
	 * @return the rms
	 */
	public Double getRMS() {
		return rms;
	}

	/**
	 * @return the gap
	 */
	public Double getGap() {
		return gap;
	}

	/**
	 * @return the pickData
	 */
	public ArrayList<Pick> getPickData() {
		return pickData;
	}

	/**
	 * @return the beamData
	 */
	public ArrayList<Beam> getBeamData() {
		return beamData;
	}

	/**
	 * @return the correlationData
	 */
	public ArrayList<Correlation> getCorrelationData() {
		return correlationData;
	}

}
