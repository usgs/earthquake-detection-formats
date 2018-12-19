package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import java.util.Date;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class CorrelationTest {

	public static String CORRELATION_STRING = "{\"ZScore\":33.67,"
			+ "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\","
			+ "\"Network\":\"LB\",\"Location\":\"01\"},\"Magnitude\":2.14,"
			+ "\"Type\":\"Correlation\",\"Correlation\":2.65,"
			+ "\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},"
			+ "\"AssociationInfo\":{\"Distance\":0.442559,\"Azimuth\":0.418479,"
			+ "\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":-0.025393},"
			+ "\"DetectionThreshold\":1.5,"
			+ "\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},"
			+ "\"Time\":\"2015-12-28T21:32:24.017Z\","
			+ "\"Hypocenter\":{\"TimeError\":1.984,"
			+ "\"Time\":\"2015-12-28T21:30:44.039Z\",\"LongitudeError\":22.64,"
			+ "\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,"
			+ "\"Longitude\":-121.44,\"Depth\":32.44},\"SNR\":3.8,"
			+ "\"ID\":\"12GFH48776857\",\"ThresholdType\":\"minimum\","
			+ "\"Phase\":\"P\"}";

	public static String ID = "12GFH48776857";
	public static String STATION = "BMN";
	public static String CHANNEL = "HHZ";
	public static String NETWORK = "LB";
	public static String LOCATION = "01";
	public static String AGENCYID = "US";
	public static String AUTHOR = "TestAuthor";
	public static Date TIME = Utility.getDate("2015-12-28T21:32:24.017Z");
	public static String PHASE = "P";
	public static double CORRELATION = 2.65;
	public static double LATITUDE = 40.3344;
	public static double LONGITUDE = -121.44;
	public static Date ORIGINTIME = Utility.getDate("2015-12-28T21:30:44.039Z");
	public static double DEPTH = 32.44;
	public static double LATITUDEERROR = 12.5;
	public static double LONGITUDEERROR = 22.64;
	public static double DEPTHERROR = 2.44;
	public static double TIMEERROR = 1.984;
    public static String EVENTTYPE = "Earthquake";
    public static String CERTAINTY = "Suspected";
	public static double MAGNITUDE = 2.14;
	public static double SNR = 3.8;
	public static double ZSCORE = 33.67;
	public static double DETECTIONTHRESHOLD = 1.5;
	public static String THRESHOLDTYPE = "minimum";
	public static String ASSOCPHASE = "P";
	public static double ASSOCDISTANCE = 0.442559;
	public static double ASSOCAZIMUTH = 0.418479;
	public static double ASSOCRESIDUAL = -0.025393;
	public static double ASSOCSIGMA = 0.086333;

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
		Correlation correlationObject = new Correlation(ID, STATION, CHANNEL,
			NETWORK, LOCATION, AGENCYID, AUTHOR, PHASE, TIME, CORRELATION,
			LATITUDE, LONGITUDE, ORIGINTIME, DEPTH, LATITUDEERROR,
			LONGITUDEERROR, TIMEERROR, DEPTHERROR, EVENTTYPE, CERTAINTY, 
			MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD, THRESHOLDTYPE, 
			ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL, 
			ASSOCSIGMA);

		// write out to a string
		String jsonString = Utility.toJSONString(correlationObject.toJSON());

		// check the data
		try {
			CheckData(new Correlation(Utility.fromJSONString(jsonString)),
					"WritesJSON");
		} catch (ParseException e) {
			e.printStackTrace();
			fail("exception in WritesJSON");
		}
	}

	/**
	 * Able to read a JSON string
	 */
	@Test
	public void ReadsJSON() {
		// build Correlation object
		try {
			CheckData(
					new Correlation(Utility.fromJSONString(CORRELATION_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
			fail("exception in ReadsJSON");
		}
	}

	/**
	 * Constructor fills in members correctly
	 */
	@Test
	public void Constructor() {
		// use constructor
		Correlation correlationObject = new Correlation(ID, STATION, CHANNEL,
			NETWORK, LOCATION, AGENCYID, AUTHOR, PHASE, TIME, CORRELATION,
			LATITUDE, LONGITUDE, ORIGINTIME, DEPTH, LATITUDEERROR,
			LONGITUDEERROR, TIMEERROR, DEPTHERROR, EVENTTYPE, CERTAINTY, 
			MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD, THRESHOLDTYPE, 
			ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL, 
			ASSOCSIGMA);

		// check data values
		CheckData(correlationObject, "Constructor");

		// use constructor
		Correlation altCorrelationObject = new Correlation(ID, STATION, CHANNEL,
			NETWORK, LOCATION, AGENCYID, AUTHOR, PHASE, TIME, CORRELATION,
			LATITUDE, LONGITUDE, ORIGINTIME, DEPTH, LATITUDEERROR,
			LONGITUDEERROR, TIMEERROR, DEPTHERROR, EVENTTYPE, CERTAINTY, 
			MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD, THRESHOLDTYPE);

		// check data values
		CheckData(altCorrelationObject, "Alternate Constructor 1");

		// use constructor
		Correlation altAltCorrelationObject = new Correlation(ID,
			new Site(STATION, CHANNEL, NETWORK, LOCATION),
			new Source(AGENCYID, AUTHOR), PHASE, TIME, CORRELATION,
			new Hypocenter(LATITUDE, LONGITUDE, ORIGINTIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR),
			new EventType(EVENTTYPE, CERTAINTY), MAGNITUDE, SNR, ZSCORE, 
			DETECTIONTHRESHOLD, THRESHOLDTYPE);

		// check data values
		CheckData(altAltCorrelationObject, "Alternate Constructor 2");

		// use constructor
		Correlation altAltAltCorrelationObject = new Correlation(ID,
			new Site(STATION, CHANNEL, NETWORK, LOCATION),
			new Source(AGENCYID, AUTHOR), PHASE, TIME, CORRELATION,
			new Hypocenter(LATITUDE, LONGITUDE, ORIGINTIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR),
			new EventType(EVENTTYPE, CERTAINTY), MAGNITUDE, SNR, ZSCORE, 
			DETECTIONTHRESHOLD, THRESHOLDTYPE, new Association(ASSOCPHASE, 
				ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA));

		// check data values
		CheckData(altAltAltCorrelationObject, "Alternate Constructor 3");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Correlation emptyObject = new Correlation(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");	
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		Correlation correlationObject = new Correlation(ID, STATION, CHANNEL,
				NETWORK, LOCATION, AGENCYID, AUTHOR, PHASE, TIME, CORRELATION,
				LATITUDE, LONGITUDE, ORIGINTIME, DEPTH, LATITUDEERROR,
				LONGITUDEERROR, TIMEERROR, DEPTHERROR, EVENTTYPE, CERTAINTY, 
				MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD, THRESHOLDTYPE, 
				ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL, 
				ASSOCSIGMA);

		// Successful validation
		boolean rc = correlationObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Correlation object
		Correlation badCorrelationObject = new Correlation();

		// Unuccessful validation
		rc = badCorrelationObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 1", false, rc);

		// build bad Correlation object
		Correlation badCorrelationObject2 = new Correlation("", "", null,
				null, null, "", null, "22", null, -99.0,
				-999.0, 999.0, null, -99999.0, null,
				null, null, null, "chair", "bleh", -9.0,
				null, null, null, "", "22",
				null, null, null, null);

		rc = badCorrelationObject2.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 2", false, rc);
	}

	public void CheckData(Correlation correlationObject, String TestName) {
		// check correlationObject.ID
		if (correlationObject.getID() != null) {
			assertEquals(TestName + " ID Equals", ID, correlationObject.getID());
		}

		// check correlationObject.Site
		if (correlationObject.getSite() != null) {
			// check correlationObject.site.Station
			if (correlationObject.getSite().getStation() != null) {
				assertEquals(TestName + " Station Equals", STATION,
					correlationObject.getSite().getStation());
			}

			// check correlationObject.site.Channel
			if (correlationObject.getSite().getChannel() != null) {
				assertEquals(TestName + " Channel Equals", CHANNEL,
					correlationObject.getSite().getChannel());
			}

			// check correlationObject.site.Network
			if (correlationObject.getSite().getNetwork() != null) {
				assertEquals(TestName + " Network Equals", NETWORK,
					correlationObject.getSite().getNetwork());
			}

			// check correlationObject.site.Location
			if (correlationObject.getSite().getLocation() != null) {
				assertEquals(TestName + " Location Equals", LOCATION,
					correlationObject.getSite().getLocation());
			}
		}

		// check correlationObject.Source
		if (correlationObject.getSource() != null) {
			// check correlationObject.Source.AgencyID
			if (correlationObject.getSource().getAgencyID() != null) {
				assertEquals(TestName + " AgencyID Equals", AGENCYID,
					correlationObject.getSource().getAgencyID());
			}

			// check correlationObject.Source.Author
			if (correlationObject.getSource().getAuthor() != null) {
				assertEquals(TestName + " Author Equals", AUTHOR,
					correlationObject.getSource().getAuthor());
			}
		}

		// check correlationObject.Time
		if (correlationObject.getTime() != null) {
			assertEquals(TestName + " Time Equals", TIME, 
				correlationObject.getTime());
		}

		// check correlationObject.Phase
		if (correlationObject.getPhase() != null) {
			assertEquals(TestName + " Phase Equals", PHASE, 
				correlationObject.getPhase());
		}

		// check correlationObject.Correlation
		if (correlationObject.getCorrelation() != null) {
			assertEquals(TestName + " Correlation Equals", CORRELATION,
				correlationObject.getCorrelation(), 0);
		}

		// check correlationObject.Hypocenter
		if (correlationObject.getHypocenter() != null) {
			// check correlationObject.hypocenter.Latitude
			if (correlationObject.getHypocenter().getLatitude() != null) {
				assertEquals(TestName + " Latitude Equals", LATITUDE,
					correlationObject.getHypocenter().getLatitude(), 0);
			}

			// check correlationObject.hypocenter.Longitude
			if (correlationObject.getHypocenter().getLongitude() != null) {
				assertEquals(TestName + " Longitude Equals", LONGITUDE,
					correlationObject.getHypocenter().getLongitude(), 0);
			}

			// check correlationObject.hypocenter.Depth
			if (correlationObject.getHypocenter().getDepth() != null) {
				assertEquals(TestName + " Depth Equals", DEPTH,
					correlationObject.getHypocenter().getDepth(), 0);
			}

			// check correlationObject.hypocenter.Time
			if (correlationObject.getHypocenter().getTime() != null) {
				assertEquals(TestName + " OriginTime Equals", ORIGINTIME,
					correlationObject.getHypocenter().getTime());
			}

			// check correlationObject.hypocenter.LatitudeError
			if (correlationObject.getHypocenter().getLatitudeError() != null) {
				assertEquals(TestName + " LatitudeError Equals", LATITUDEERROR,
					correlationObject.getHypocenter().getLatitudeError(), 0);
			}

			// check correlationObject.hypocenter.LongitudeError
			if (correlationObject.getHypocenter().getLongitudeError() != null) {
				assertEquals(TestName + " LongitudError Equals", LONGITUDEERROR,
					correlationObject.getHypocenter().getLongitudeError(), 0);
			}

			// check correlationObject.hypocenter.DepthError
			if (correlationObject.getHypocenter().getDepthError() != null) {
				assertEquals(TestName + " DepthError Equals", DEPTHERROR,
					correlationObject.getHypocenter().getDepthError(), 0);
			}

			// check correlationObject.hypocenter.TimeError
			if (correlationObject.getHypocenter().getTimeError() != null) {
				assertEquals(TestName + " TimeError Equals", TIMEERROR,
					correlationObject.getHypocenter().getTimeError(), 0);
			}
		}

		// check correlationObject.eventType
		if ((correlationObject.getEventType() != null) && 
			(!correlationObject.getEventType().isEmpty())) {
			// check correlationObject.EventType.type
			if (correlationObject.getEventType().getType() != null) {
				assertEquals(TestName + " Type Equals", EVENTTYPE,
					correlationObject.getEventType().getType());
			}

			// check correlationObject.EventType.certainty
			if (correlationObject.getEventType().getCertainty() != null) {
				assertEquals(TestName + " Certantity Equals", CERTAINTY,
				correlationObject.getEventType().getCertainty());
			}
		}

		// check correlationObject.Magnitude
		if (correlationObject.getMagnitude() != null) {
			assertEquals(TestName + " Magnitude Equals", MAGNITUDE,
				correlationObject.getMagnitude(), 0);
		}

		// check correlationObject.SNR
		if (correlationObject.getSNR() != null) {
			assertEquals(TestName + " SNR Equals", SNR, 
				correlationObject.getSNR(), 0);
		}

		// check correlationObject.ZScore
		if (correlationObject.getZScore() != null) {
			assertEquals(TestName + " ZScore Equals", ZSCORE,
				correlationObject.getZScore(), 0);
		}

		// check correlationObject.DetectionThreshold
		if (correlationObject.getDetectionThreshold() != null) {
			assertEquals(TestName + " DetectionThreshold Equals",
				DETECTIONTHRESHOLD, correlationObject.getDetectionThreshold(),
					0);
		}

		// check correlationObject.ThresholdType
		if (correlationObject.getThresholdType() != null) {
			assertEquals(TestName + " ThresholdType Equals", THRESHOLDTYPE,
				correlationObject.getThresholdType());
		}

		// check correlationObject.AssociationInfo
		if ((correlationObject.getAssociationInfo() != null) && 
			!correlationObject.getAssociationInfo().isEmpty()) {
			// check correlationObject.Association.Phase
			if (correlationObject.getAssociationInfo().getPhase() != null) {
				assertEquals(TestName + " Phase Equals", ASSOCPHASE,
					correlationObject.getAssociationInfo().getPhase());
			}

			// check correlationObject.Association.Distance
			if (correlationObject.getAssociationInfo().getPhase() != null) {
				assertEquals(TestName + " Distance Equals", ASSOCDISTANCE,
					correlationObject.getAssociationInfo().getDistance(), 0);
			}

			// check correlationObject.Association.Azimuth
			if (correlationObject.getAssociationInfo().getPhase() != null) {
				assertEquals(TestName + " Azimuth Equals", ASSOCAZIMUTH,
					correlationObject.getAssociationInfo().getAzimuth(), 0);
			}

			// check correlationObject.Association.Residual
			if (correlationObject.getAssociationInfo().getPhase() != null) {
				assertEquals(TestName + " Residual Equals", ASSOCRESIDUAL,
					correlationObject.getAssociationInfo().getResidual(), 0);
			}

			// check correlationObject.Association.Sigma
			if (correlationObject.getAssociationInfo().getSigma() != null) {
				assertEquals(TestName + " Sigma Equals", ASSOCSIGMA,
					correlationObject.getAssociationInfo().getSigma(), 0);
			}
		}
	}
}
