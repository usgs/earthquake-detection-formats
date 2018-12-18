package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import org.json.simple.parser.ParseException;
import org.junit.Test;

public class PickTest {
	public static String PICK_STRING = "{\"Source\":{\"Author\":\"TestAuthor\","
			+ "\"AgencyID\":\"US\"},\"Filter\":[{\"Type\":\"BandPass\",\"HighPass\":1.05,\"LowPass\":"
			+ "2.65,\"Units\":\"Hertz\"}],\"Onset\":\"questionable\",\"Amplitude\":{\"Period\":2.65,"
			+ "\"Amplitude\":21.5,\"SNR\":3.8},\"Time\":\"2015-12-28T21:32:24.017Z\","
			+ "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\","
			+ "\"Location\":\"01\"},\"Type\":\"Pick\",\"Beam\":{\"BackAzimuth\":2.65,"
			+ "\"BackAzimuthError\":3.8,\"Slowness\":1.44,\"SlownessError\":0.4,"
			+ "\"PowerRatio\":12.18,\"PowerRatioError\":0.557},"
			+ "\"ID\":\"12GFH48776857\",\"Polarity\":\"up\",\"Phase\":\"P\","
			+ "\"Picker\":\"manual\",\"AssociationInfo\":{\"Distance\":0.442559,"
			+ "\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":"
			+ "-0.025393}}";
	public static String ID = "12GFH48776857";
	public static String STATION = "BMN";
	public static String CHANNEL = "HHZ";
	public static String NETWORK = "LB";
	public static String LOCATION = "01";
	public static String AGENCYID = "US";
	public static String AUTHOR = "TestAuthor";
	public static Date TIME = Utility.getDate("2015-12-28T21:32:24.017Z");
	public static String PHASE = "P";
	public static String POLARITY = "up";
	public static String ONSET = "questionable";
	public static String PICKER = "manual";
	public static String TYPE = "BandPass";
	public static double HIGHPASS = 1.05;
	public static double LOWPASS = 2.65;
	public static String UNITS = "Hertz";
	public static double AMPLITUDE = 21.5;
	public static double PERIOD = 2.65;
	public static double SNR = 3.8;
	public static double BACKAZIMUTH = 2.65;
	public static double BACKAZIMUTHERROR = 3.8;
	public static double SLOWNESS = 1.44;
	public static double SLOWNESSERROR = 0.4;
	public static double POWERRATIO = 12.18;
	public static double POWERRATIOERROR = 0.557;
	public static String ASSOCPHASE = "P";
	public static double ASSOCDISTANCE = 0.442559;
	public static double ASSOCAZIMUTH = 0.418479;
	public static double ASSOCRESIDUAL = -0.025393;
	public static double ASSOCSIGMA = 0.086333;

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void writesJSON() {
		Pick pickObject = new Pick(ID, STATION, CHANNEL, NETWORK, LOCATION,
			TIME, AGENCYID, AUTHOR, PHASE, POLARITY, ONSET, PICKER,
			TYPE, HIGHPASS, LOWPASS, UNITS, AMPLITUDE, PERIOD, SNR, 
			BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, 
			POWERRATIO, POWERRATIOERROR, ASSOCPHASE, ASSOCDISTANCE, 
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

		// write out to a string
		String jsonString = Utility.toJSONString(pickObject.toJSON());

		// check the data
		try {
			CheckData(new Pick(Utility.fromJSONString(jsonString)),
					"WritesJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Able to read a JSON string
	 */
	@Test
	public void ReadsJSON() {
		// build Correlation object
		try {
			CheckData(new Pick(Utility.fromJSONString(PICK_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Constructor fills in members correctly
	 */
	@Test
	public void Constructor() {
		Pick pickObject = new Pick(ID, STATION, CHANNEL, NETWORK, LOCATION,
			TIME, AGENCYID, AUTHOR, PHASE, POLARITY, ONSET, PICKER,
			TYPE, HIGHPASS, LOWPASS, UNITS, AMPLITUDE, PERIOD, SNR, 
			BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, 
			POWERRATIO, POWERRATIOERROR, ASSOCPHASE, ASSOCDISTANCE, 
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

		// check data values
		CheckData(pickObject, "Constructor");

		// use constructor
		Pick altPickObject = new Pick(ID, STATION, CHANNEL, NETWORK, LOCATION,
			TIME, AGENCYID, AUTHOR, PHASE, POLARITY, ONSET, PICKER, TYPE, 
			HIGHPASS, LOWPASS, UNITS, AMPLITUDE, PERIOD, SNR, BACKAZIMUTH,
			BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO,
			POWERRATIOERROR);

		// check data values
		CheckData(altPickObject, "Alternate Constructor 1");

		// use constructor
		Pick altAltPickObject = new Pick(ID,
			new Site(STATION, CHANNEL, NETWORK, LOCATION), TIME,
			new Source(AGENCYID, AUTHOR), PHASE, POLARITY, ONSET, PICKER,
			new ArrayList<Filter>(
				Arrays.asList(new Filter(TYPE, HIGHPASS, LOWPASS, UNITS))),
			new Amplitude(AMPLITUDE, PERIOD, SNR),
			new Beam(BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR,
				POWERRATIO, POWERRATIOERROR));

		// check data values
		CheckData(altAltPickObject, "Alternate Constructor 2");

		// use constructor
		Pick altAltAltPickObject = new Pick(ID,
			new Site(STATION, CHANNEL, NETWORK, LOCATION), TIME,
			new Source(AGENCYID, AUTHOR), PHASE, POLARITY, ONSET, PICKER,
			new ArrayList<Filter>(
				Arrays.asList(new Filter(TYPE, HIGHPASS, LOWPASS, UNITS))),
			new Amplitude(AMPLITUDE, PERIOD, SNR),
			new Beam(BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR,
				POWERRATIO, POWERRATIOERROR),
			new Association(ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH,
				ASSOCRESIDUAL, ASSOCSIGMA));

		// check data values
		CheckData(altAltAltPickObject, "Alternate Constructor 3");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Pick emptyObject = new Pick(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");	
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		Pick pickObject = new Pick(ID, STATION, CHANNEL, NETWORK, LOCATION,
			TIME, AGENCYID, AUTHOR, PHASE, POLARITY, ONSET, PICKER, TYPE, 
			HIGHPASS, LOWPASS, UNITS, AMPLITUDE, PERIOD, SNR, BACKAZIMUTH,
			BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO,
			POWERRATIOERROR, ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH,
			ASSOCRESIDUAL, ASSOCSIGMA);

		// Successful validation
		boolean rc = pickObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Pick object
		Pick badPickObject = new Pick();

		// Unuccessful validation
		rc = badPickObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 1", false, rc);

		// build bad Pick object
		Pick badPickObject2 = new Pick(null, null, null, null, null, null, null, 
			null, "22", "22", "22", "22", null, null, null, null, -99.0, 
			null, null, -99.0, null, null, null, null, null, "22", null, 
			null, null, null);

		// Unuccessful validation
		rc = badPickObject2.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 2", false, rc);
	}

	public void CheckData(Pick pickObject, String TestName) {
		// check pickObject.ID
		if (pickObject.getID() != null) {
			assertEquals(TestName + " ID Equals", ID, pickObject.getID());
		}

		// check pickObject.Site
		if (pickObject.getSite() != null) {
			// check pickObject.site.Station
			if (pickObject.getSite().getStation() != null) {
				assertEquals(TestName + " Station Equals", STATION,
					pickObject.getSite().getStation());
			}

			// check pickObject.site.Channel
			if (pickObject.getSite().getChannel() != null) {
				assertEquals(TestName + " Channel Equals", CHANNEL,
					pickObject.getSite().getChannel());
			}

			// check pickObject.site.Network
			if (pickObject.getSite().getNetwork() != null) {
				assertEquals(TestName + " Network Equals", NETWORK,
					pickObject.getSite().getNetwork());
			}

			// check pickObject.site.Location
			if (pickObject.getSite().getLocation() != null) {
				assertEquals(TestName + " Location Equals", LOCATION,
					pickObject.getSite().getLocation());
			}
		}

		// check pickObject.Source
		if (pickObject.getSource() != null) {
			// check pickObject.Source.AgencyID
			if (pickObject.getSource().getAgencyID() != null) {
				assertEquals(TestName + " AgencyID Equals", AGENCYID,
					pickObject.getSource().getAgencyID());
			}

			// check pickObject.Source.Author
			if (pickObject.getSource().getAuthor() != null) {
				assertEquals(TestName + " Author Equals", AUTHOR,
					pickObject.getSource().getAuthor());
			}
		}

		// check pickObject.Time
		if (pickObject.getTime() != null) {
			assertEquals(TestName + " Time Equals", TIME, pickObject.getTime());
		}

		// check pickObject.Phase
		if (pickObject.getPhase() != null) {
			assertEquals(TestName + " Phase Equals", PHASE, 
				pickObject.getPhase());
		}

		// check pickObject.Polarity
		if (pickObject.getPolarity() != null) {
			assertEquals(TestName + " Polarity Equals", POLARITY,
				pickObject.getPolarity());
		}

		// check pickObject.Onset
		if (pickObject.getOnset() != null) {
			assertEquals(TestName + " Onset Equals", ONSET, 
				pickObject.getOnset());
		}

		// check pickObject.Picker
		if (pickObject.getPicker() != null) {
			assertEquals(TestName + " Picker Equals", PICKER,
				pickObject.getPicker());
		}

		// check pickObject.FilterList
		if (pickObject.getFilterList() != null) {
			ArrayList<Filter> filterList = pickObject.getFilterList();
			if (!filterList.isEmpty()) {
				// get the first filter in the list
				Filter aFilter = filterList.get(0);

				// check aFilter.type
				if (aFilter.getType() != null) {
					assertEquals(TestName + " Type Equals", TYPE,
						aFilter.getType());
				}

				// check aFilter.highPass
				if (aFilter.getHighPass() != null) {
					assertEquals(TestName + " HighPass Equals", HIGHPASS,
						aFilter.getHighPass(), 0);
				}

				// check aFilter.lowPass
				if (aFilter.getLowPass() != null) {
					assertEquals(TestName + " LowPass Equals", LOWPASS,
						aFilter.getLowPass(), 0);
				}

				// check aFilter.units
				if (aFilter.getUnits() != null) {
					assertEquals(TestName + " Units Equals", UNITS,
						aFilter.getUnits());
				}
			}
		}

		// check pickObject.Amplitude
		if ((pickObject.getAmplitude() != null)
				&& (!pickObject.getAmplitude().isEmpty())) {
			// check pickObject.Amplitude.Amplitude
			if (pickObject.getAmplitude().getAmplitude() != null) {
				assertEquals(TestName + " Amplitude Equals", AMPLITUDE,
					pickObject.getAmplitude().getAmplitude(), 0);
			}

			// check pickObject.Amplitude.Period
			if (pickObject.getAmplitude().getPeriod() != null) {
				assertEquals(TestName + " Period Equals", PERIOD,
					pickObject.getAmplitude().getPeriod(), 0);
			}

			// check pickObject.Amplitude.SNR
			if (pickObject.getAmplitude().getSNR() != null) {
				assertEquals(TestName + " SNR Equals", SNR,
					pickObject.getAmplitude().getSNR(), 0);
			}
		}

		// check pickObject.Beam
		if (pickObject.getBeam() != null) {
			// check pickObject.getBeam().BackAzimuth
			if (pickObject.getBeam().getBackAzimuth() != null) {
				assertEquals(TestName + " BackAzimuth Equals", BACKAZIMUTH,
					pickObject.getBeam().getBackAzimuth(), 0);
			}

			// check pickObject.getBeam().BackAzimuthError
			if (pickObject.getBeam().getBackAzimuthError() != null) {
				assertEquals(TestName + " BackAzimuthError Equals",
					BACKAZIMUTHERROR, pickObject.getBeam().getBackAzimuthError(), 
					0);
			}

			// check pickObject.getBeam().Slowness
			if (pickObject.getBeam().getSlowness() != null) {
				assertEquals(TestName + " Slowness Equals", SLOWNESS,
					pickObject.getBeam().getSlowness(), 0);
			}

			// check pickObject.getBeam().SlownessError
			if (pickObject.getBeam().getSlownessError() != null) {
				assertEquals(TestName + " SlownessError Equals", SLOWNESSERROR,
					pickObject.getBeam().getSlownessError(), 0);
			}

			// check pickObject.getBeam().PowerRatio
			if (pickObject.getBeam().getPowerRatio() != null) {
				assertEquals(TestName + " PowerRatio Equals", POWERRATIO,
					pickObject.getBeam().getPowerRatio(), 0);
			}

			// check pickObject.getBeam().PowerRatioError
			if (pickObject.getBeam().getPowerRatioError() != null) {
				assertEquals(TestName + " PowerRatioError Equals",
					POWERRATIOERROR, pickObject.getBeam().getPowerRatioError(), 
					0);
			}
		}

		// check pickObject.AssociationInfo
		if ((pickObject.getAssociationInfo() != null) && 
			!pickObject.getAssociationInfo().isEmpty()) {
			// check pickObject.Association.Phase
			if (pickObject.getAssociationInfo().getPhase() != null) {
				assertEquals(TestName + " Phase Equals", ASSOCPHASE,
					pickObject.getAssociationInfo().getPhase());
			}

			// check pickObject.Association.Distance
			if (pickObject.getAssociationInfo().getPhase() != null) {
				assertEquals(TestName + " Distance Equals", ASSOCDISTANCE,
					pickObject.getAssociationInfo().getDistance(), 0);
			}

			// check pickObject.Association.Azimuth
			if (pickObject.getAssociationInfo().getPhase() != null) {
				assertEquals(TestName + " Azimuth Equals", ASSOCAZIMUTH,
					pickObject.getAssociationInfo().getAzimuth(), 0);
			}

			// check pickObject.Association.Residual
			if (pickObject.getAssociationInfo().getPhase() != null) {
				assertEquals(TestName + " Residual Equals", ASSOCRESIDUAL,
					pickObject.getAssociationInfo().getResidual(), 0);
			}

			// check pickObject.Association.Sigma
			if (pickObject.getAssociationInfo().getSigma() != null) {
				assertEquals(TestName + " Sigma Equals", ASSOCSIGMA,
					pickObject.getAssociationInfo().getSigma(), 0);
			}
		}
	}
}
