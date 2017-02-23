package gov.usgs.detectionformats;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;

/**
 * a conversion class used to create, parse, and validate pick detection data
 * 
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Pick implements DetectionInt {

	/**
	 * JSON Keys
	 */
	public static final String TYPE_KEY = "Type";
	public static final String ID_KEY = "ID";
	public static final String SITE_KEY = "Site";
	public static final String SOURCE_KEY = "Source";
	public static final String TIME_KEY = "Time";
	public static final String PHASE_KEY = "Phase";
	public static final String POLARITY_KEY = "Polarity";
	public static final String ONSET_KEY = "Onset";
	public static final String PICKER_KEY = "Picker";
	public static final String FILTER_KEY = "Filter";
	public static final String AMPLITUDE_KEY = "Amplitude";
	public static final String BEAM_KEY = "Beam";
	public static final String ASSOCIATIONINFO_KEY = "AssociationInfo";

	/**
	 * Required type identifier for this Pick
	 */
	private final String type;

	/**
	 * Required unique identifier for this Pick
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
	 * Required time for this Pick
	 */
	private final Date time;

	/**
	 * Optional String containing the Pick phase name
	 */
	private final String phase;

	/**
	 * Optional String containing the Pick polarity
	 */
	private final String polarity;

	/**
	 * Optional String containing the Pick onSet
	 */
	private final String onset;

	/**
	 * Optional String containing the Pick picker
	 */
	private final String picker;

	/**
	 * Optional filter information.
	 */
	private final ArrayList<Filter> filterList;

	/**
	 * Optional amplitude information.
	 */
	private final Amplitude amplitude;

	/**
	 * Optional beam information.
	 */
	private final Beam beam;

	/**
	 * Optional associated information.
	 */
	private final Associated associationInfo;

	/**
	 * The constructor for the Pick class. Initializes members to null values.
	 */
	public Pick() {

		type = "Pick";
		id = null;
		site = null;
		source = null;
		time = null;
		phase = null;
		polarity = null;
		onset = null;
		picker = null;
		filterList = null;
		amplitude = null;
		beam = null;
		associationInfo = null;
	}

	/**
	 * The advanced constructor for the Pick class. Initializes members to
	 * provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newStation
	 *            - A String containing the station to use
	 * @param newChannel
	 *            - A String containing the channel to use
	 * @param newNetwork
	 *            - A String containing the network to use
	 * @param newLocation
	 *            - A String containing the location to use
	 * @param newTime
	 *            - A Date containing the time to use
	 * @param newAgencyID
	 *            - A String containing the agencyid to use
	 * @param newAuthor
	 *            - A String containing the author to use
	 * @param newPhase
	 *            - A String containing the phase to use, null to omit
	 * @param newPolarity
	 *            - A String containing the polarity to use, empty String to
	 *            omit
	 * @param newOnset
	 *            - A String containing the onset to use, null to omit
	 * @param newPicker
	 *            - A String containing the picker to use, null to omit
	 * @param newHighPass
	 *            - A Double containing the high pass to use, null to omit
	 * @param newLowPass
	 *            - A Double containing the low pass to use, null to omit
	 * @param newAmplitude
	 *            - A Double containing the amplitude to use, null to omit
	 * @param newPeriod
	 *            - A Double containing the period to use, null to omit
	 * @param newSNR
	 *            - A Double containing the snr to use, null to omit
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
	 * @param newAssociatedPhase
	 *            - A std:Stringcontaining the associated phase to use, null to
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
	public Pick(String newID, String newStation, String newChannel,
			String newNetwork, String newLocation, Date newTime,
			String newAgencyID, String newAuthor, String newPhase,
			String newPolarity, String newOnset, String newPicker,
			Double newHighPass, Double newLowPass, Double newAmplitude,
			Double newPeriod, Double newSNR, Double newBackAzimuth,
			Double newBackAzimutherror, Double newSlowness,
			Double newSlownessError, Double newPowerRatio,
			Double newPowerRatioError, String newAssociatedPhase,
			Double newAssociatedDistance, Double newAssociatedAzimuth,
			Double newAssociatedResidual, Double newAssociatedSigma) {

		this(newID, new Site(newStation, newChannel, newNetwork, newLocation),
				newTime, new Source(newAgencyID, newAuthor), newPhase,
				newPolarity, newOnset, newPicker,
				new ArrayList<Filter>(
						Arrays.asList(new Filter(newHighPass, newLowPass))),
				new Amplitude(newAmplitude, newPeriod, newSNR),
				new Beam(newBackAzimuth, newBackAzimutherror, newSlowness,
						newSlownessError, newPowerRatio, newPowerRatioError),
				new Associated(newAssociatedPhase, newAssociatedDistance,
						newAssociatedAzimuth, newAssociatedResidual,
						newAssociatedSigma));
	}

	/**
	 * The advanced constructor for the Pick class. Initializes members to
	 * provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newStation
	 *            - A String containing the station to use
	 * @param newChannel
	 *            - A String containing the channel to use
	 * @param newNetwork
	 *            - A String containing the network to use
	 * @param newLocation
	 *            - A String containing the location to use
	 * @param newTime
	 *            - A Date containing the time to use
	 * @param newAgencyID
	 *            - A String containing the agencyid to use
	 * @param newAuthor
	 *            - A String containing the author to use
	 * @param newPhase
	 *            - A String containing the phase to use, null to omit
	 * @param newPolarity
	 *            - A String containing the polarity to use, null to omit
	 * @param newOnset
	 *            - A String containing the onset to use, null to omit
	 * @param newPicker
	 *            - A String containing the picker to use, null to omit
	 * @param newHighPass
	 *            - A Double containing the high pass to use, null to omit
	 * @param newLowPass
	 *            - A Double containing the low pass to use, null to omit
	 * @param newAmplitude
	 *            - A Double containing the amplitude to use, null to omit
	 * @param newPeriod
	 *            - A Double containing the period to use, null to omit
	 * @param newSNR
	 *            - A Double containing the snr to use, null to omit
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
	public Pick(String newID, String newStation, String newChannel,
			String newNetwork, String newLocation, Date newTime,
			String newAgencyID, String newAuthor, String newPhase,
			String newPolarity, String newOnset, String newPicker,
			Double newHighPass, Double newLowPass, Double newAmplitude,
			Double newPeriod, Double newSNR, Double newBackAzimuth,
			Double newBackAzimutherror, Double newSlowness,
			Double newSlownessError, Double newPowerRatio,
			Double newPowerRatioError) {

		this(newID, new Site(newStation, newChannel, newNetwork, newLocation),
				newTime, new Source(newAgencyID, newAuthor), newPhase,
				newPolarity, newOnset, newPicker,
				new ArrayList<Filter>(
						Arrays.asList(new Filter(newHighPass, newLowPass))),
				new Amplitude(newAmplitude, newPeriod, newSNR),
				new Beam(newBackAzimuth, newBackAzimutherror, newSlowness,
						newSlownessError, newPowerRatio, newPowerRatioError));
	}

	/**
	 * The alternate advanced constructor for the Pick class. Initializes
	 * members to provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSite
	 *            - A Site containing the site to use
	 * @param newTime
	 *            - A Date containing the time to use
	 * @param newSource
	 *            - A Source containing the source to use
	 * @param newPhase
	 *            - A String containing the phase to use, null to omit
	 * @param newPolarity
	 *            - A String containing the polarity to use, empty String to
	 *            omit
	 * @param newOnset
	 *            - A String containing the onset to use, null to omit
	 * @param newPicker
	 *            - A String containing the picker to use, null to omit
	 * @param newFilter
	 *            - An ArrayList&lt;Filter&gt; objects containing the filters to
	 *            use, null to omit
	 * @param newAmplitude
	 *            - An Amplitude object containing the amplitude to us, null to
	 *            omit
	 * @param newBeam
	 *            - A Double containing the amplitude to us, null to omit
	 */
	public Pick(String newID, Site newSite, Date newTime, Source newSource,
			String newPhase, String newPolarity, String newOnset,
			String newPicker, ArrayList<Filter> newFilter,
			Amplitude newAmplitude, Beam newBeam) {

		this(newID, newSite, newTime, newSource, newPhase, newPolarity,
				newOnset, newPicker, newFilter, newAmplitude, newBeam,
				new Associated());
	}

	/**
	 * The alternate advanced constructor for the Pick class. Initializes
	 * members to provided values.
	 * 
	 * @param newID
	 *            - A String containing the id to use
	 * @param newSite
	 *            - A Site containing the site to use
	 * @param newTime
	 *            - A Date containing the time to use
	 * @param newSource
	 *            - A Source containing the source to use
	 * @param newPhase
	 *            - A String containing the phase to use, null to omit
	 * @param newPolarity
	 *            - A String containing the polarity to use, empty String to
	 *            omit
	 * @param newOnset
	 *            - A String containing the onset to use, null to omit
	 * @param newPicker
	 *            - A String containing the picker to use, null to omit
	 * @param newFilter
	 *            - A Double containing the filter to use, null to omit
	 * @param newAmplitude
	 *            - An Amplitude object containing the amplitude to us, null to
	 *            omit
	 * @param newBeam
	 *            - A Double containing the amplitude to us, null to omit
	 * @param newAssociated
	 *            - A Associated containing the associated to use, null to omit
	 */
	public Pick(String newID, Site newSite, Date newTime, Source newSource,
			String newPhase, String newPolarity, String newOnset,
			String newPicker, ArrayList<Filter> newFilter,
			Amplitude newAmplitude, Beam newBeam, Associated newAssociated) {

		type = "Pick";
		id = newID;
		site = newSite;
		time = newTime;
		source = newSource;
		phase = newPhase;
		polarity = newPolarity;
		onset = newOnset;
		picker = newPicker;
		filterList = newFilter;
		amplitude = newAmplitude;
		beam = newBeam;
		associationInfo = newAssociated;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 * 
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Pick(JSONObject newJSONObject) {

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

		// Optional values
		// phase
		if (newJSONObject.containsKey(PHASE_KEY)) {
			phase = newJSONObject.get(PHASE_KEY).toString();
		} else {
			phase = null;
		}

		// polarity
		if (newJSONObject.containsKey(POLARITY_KEY)) {
			polarity = newJSONObject.get(POLARITY_KEY).toString();
		} else {
			polarity = null;
		}

		// onset
		if (newJSONObject.containsKey(ONSET_KEY)) {
			onset = newJSONObject.get(ONSET_KEY).toString();
		} else {
			onset = null;
		}

		// picker
		if (newJSONObject.containsKey(PICKER_KEY)) {
			picker = newJSONObject.get(PICKER_KEY).toString();
		} else {
			picker = null;
		}

		// filterList
		if (newJSONObject.containsKey(FILTER_KEY)) {

			filterList = new ArrayList<Filter>();

			// get the array
			JSONArray dataArray = (JSONArray) newJSONObject.get(FILTER_KEY);

			// is there anything in the array
			if ((dataArray != null) && (!dataArray.isEmpty())) {

				// go through the whole array
				for (int i = 0; i < dataArray.size(); i++) {

					// get the object
					JSONObject dataObject = (JSONObject) dataArray.get(i);

					// add to vector
					filterList.add(new Filter(dataObject));
				}
			}
		} else {
			filterList = null;
		}

		// amplitude
		if (newJSONObject.containsKey(AMPLITUDE_KEY)) {
			amplitude = new Amplitude(
					(JSONObject) newJSONObject.get(AMPLITUDE_KEY));
		} else {
			amplitude = null;
		}

		// beam
		if (newJSONObject.containsKey(BEAM_KEY)) {
			beam = new Beam(
					(JSONObject) newJSONObject.get(BEAM_KEY));
		} else {
			beam = null;
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
		String jsonPhase = getPhase();
		String jsonPolarity = getPolarity();
		String jsonOnset = getOnset();
		String jsonPicker = getPicker();
		ArrayList<Filter> jsonFilterList = getFilterList();
		Amplitude jsonAmplitude = getAmplitude();
		Beam jsonBeam = getBeam();
		Associated jsonAssociationInfo = getAssociationInfo();

		// Required values
		// Type
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

		// Optional values
		// phase
		if (jsonPhase != null) {
			newJSONObject.put(PHASE_KEY, jsonPhase);
		}

		// polarity
		if (jsonPolarity != null) {
			newJSONObject.put(POLARITY_KEY, jsonPolarity);
		}

		// onset
		if (jsonOnset != null) {
			newJSONObject.put(ONSET_KEY, jsonOnset);
		}

		// picker
		if (jsonPicker != null) {
			newJSONObject.put(PICKER_KEY, jsonPicker);
		}

		// filter
		if (jsonFilterList != null) {

			JSONArray dataArray = new JSONArray();

			for (Filter filter : jsonFilterList) {
				JSONObject jsonFilter = filter.toJSON();
				dataArray.add(jsonFilter);
			}

			newJSONObject.put(FILTER_KEY, dataArray);
		}

		// amplitude
		if ((jsonAmplitude != null) && (!jsonAmplitude.isEmpty()))
			newJSONObject.put(AMPLITUDE_KEY, jsonAmplitude.toJSON());

		// beam
		if (jsonBeam != null) 
			newJSONObject.put(BEAM_KEY, jsonBeam.toJSON());		
		
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
		Date jsonTime = getTime();
		String jsonPhase = getPhase();
		String jsonPolarity = getPolarity();
		String jsonOnset = getOnset();
		String jsonPicker = getPicker();
		ArrayList<Filter> jsonFilterList = getFilterList();
		Amplitude jsonAmplitude = getAmplitude();
		Beam jsonBeam = getBeam();
		Associated jsonAssociationInfo = getAssociationInfo();

		ArrayList<String> errorList = new ArrayList<String>();

		// Required Keys
		// type
		if (jsonType == null) {
			// type not found
			errorList.add("No Type in Pick Class.");
		} else if (jsonType.isEmpty()) {
			// type empty
			errorList.add("Empty Type in Pick Class.");
		} else if (!jsonType.equals("Pick")) {
			// wrong type
			errorList.add("Non-Beam type in Pick Class.");
		}

		// id
		if (jsonID == null) {
			// id not found
			errorList.add("No ID in Pick Class.");
		} else if (jsonID.isEmpty()) {
			// id empty
			errorList.add("Empty ID in Pick Class.");
		}

		// site
		if (jsonSite == null) {
			// site not found
			errorList.add("No Site in Pick Class.");
		} else if (!jsonSite.isValid()) {
			// site invalid
			errorList.add("Invalid Site in Pick Class.");
		}

		// source
		if (jsonSource == null) {
			// source not found
			errorList.add("No Source in Pick Class.");
		} else if (!jsonSource.isValid()) {
			// source invalid
			errorList.add("Invalid Source in Pick Class.");
		}

		// time
		if (jsonTime == null) {
			// time not found
			errorList.add("No Time in Pick Class.");
		}

		// Optional Keys
		// phase
		// phase
		if (jsonPhase != null) {
			if (jsonPhase.isEmpty()) {
				// phase empty
				errorList.add("Empty Phase in Pick Class.");
			} else if (!Utility.isStringAlpha(jsonPhase)) {
				// invalid phase
				errorList.add("Invalid Phase in Pick Class.");
			}
		}
		// polarity
		if (jsonPolarity != null) {

			boolean match = false;
			if (jsonPolarity.equals("up")) {
				match = true;
			} else if (jsonPolarity.equals("down")) {
				match = true;
			} else {
				match = false;
			}

			if (!match) {
				// invalid polarity
				errorList.add("Invalid Polarity in Pick Class.");
			}
		}

		// onset
		if (jsonOnset != null) {

			boolean match = false;
			if (jsonOnset.equals("impulsive")) {
				match = true;
			} else if (jsonOnset.equals("emergent")) {
				match = true;
			} else if (jsonOnset.equals("questionable")) {
				match = true;
			} else {
				match = false;
			}

			if (match == false) {
				// invalid onset
				errorList.add("Invalid Onset in Pick Class.");
			}
		}

		// picker
		if (jsonPicker != null) {

			boolean match = false;
			if (jsonPicker.equals("manual")) {
				match = true;
			} else if (jsonPicker.equals("raypicker")) {
				match = true;
			} else if (jsonPicker.equals("filterpicker")) {
				match = true;
			} else if (jsonPicker.equals("earthworm")) {
				match = true;
			} else if (jsonPicker.equals("other")) {
				match = true;
			} else {
				match = false;
			}

			if (match == false) {
				// invalid Picker
				errorList.add("Invalid Picker in Pick Class.");
			}
		}

		// Picks
		if (jsonFilterList != null) {
			// enumerate through the whole arraylist
			for (Filter jsonFilter : jsonFilterList) {
				if (!jsonFilter.isValid()) {
					errorList.add("Invalid Filter in Pick Class.");
					break;
				}
			}
		}

		// amplitude
		if (jsonAmplitude != null) {
			if (!jsonAmplitude.isValid()) {
				// amplitude invalid
				errorList.add("Invalid Amplitude in Pick Class.");
			}
		}

		// beam
		if (jsonBeam != null) {
			if (!jsonBeam.isValid()) {
				// beam invalid
				errorList.add("Invalid Beam in Pick Class.");
			}
		}		
		
		// associated
		if (jsonAssociationInfo != null) {
			if (!jsonAssociationInfo.isValid()) {
				// associationinfo invalid
				errorList.add("Invalid AssociationInfo in Pick Class.");
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
	 * @return the phase
	 */
	public String getPhase() {
		return phase;
	}

	/**
	 * @return the polarity
	 */
	public String getPolarity() {
		return polarity;
	}

	/**
	 * @return the onset
	 */
	public String getOnset() {
		return onset;
	}

	/**
	 * @return the picker
	 */
	public String getPicker() {
		return picker;
	}

	/**
	 * @return the filterList
	 */
	public ArrayList<Filter> getFilterList() {
		return filterList;
	}

	/**
	 * @return the amplitude
	 */
	public Amplitude getAmplitude() {
		return amplitude;
	}

	/**
	 * @return the beam
	 */
	public Beam getBeam() {
		return beam;
	}

	/**
	 * @return the associationInfo
	 */
	public Associated getAssociationInfo() {
		return associationInfo;
	}
}
