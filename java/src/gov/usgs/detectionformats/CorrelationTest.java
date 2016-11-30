package gov.usgs.detectionformats;

import static org.junit.Assert.*;

import java.util.Date;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class CorrelationTest {

	public static String CORRELATION_STRING = "{\"ZScore\":33.67,"
			+ "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\","
			+ "\"Network\":\"LB\",\"Location\":\"01\","
			+ "\"SiteID\":\"BMN.HHZ.LB.01\"},\"Magnitude\":2.14,"
			+ "\"Type\":\"Correlation\",\"Correlation\":2.65,"
			+ "\"EventType\":\"earthquake\","
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
	public static String SITEID = "BMN.HHZ.LB.01";
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
	public static String EVENTTYPE = "earthquake";
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
	public void writesJSON() {

		Correlation correlationObject = new Correlation(ID, SITEID, STATION,
				CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR, PHASE, TIME,
				CORRELATION, LATITUDE, LONGITUDE, ORIGINTIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR, EVENTTYPE,
				MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD, THRESHOLDTYPE,
				ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL,
				ASSOCSIGMA);

		// write out to a string
		String jsonString = Utility.toJSONString(correlationObject.toJSON());

		// check the data
		try {
			checkData(new Correlation(Utility.fromJSONString(jsonString)),
					"WritesJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}

	}

	/**
	 * Able to read a JSON string
	 */
	@Test
	public void readsJSON() {

		// build Correlation object
		try {

			checkData(
					new Correlation(Utility.fromJSONString(CORRELATION_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Constructor fills in members correctly
	 */
	@Test
	public void altConstructors() {

		// use constructor
		Correlation correlationObject = new Correlation(ID, SITEID, STATION,
				CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR, PHASE, TIME,
				CORRELATION, LATITUDE, LONGITUDE, ORIGINTIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR, EVENTTYPE,
				MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD, THRESHOLDTYPE,
				ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL,
				ASSOCSIGMA);

		// check data values
		checkData(correlationObject, "Alternate Constructor 1");

		// use constructor
		Correlation altCorrelationObject = new Correlation(ID,
				new Site(SITEID, STATION, CHANNEL, NETWORK, LOCATION),
				new Source(AGENCYID, AUTHOR), PHASE, TIME, CORRELATION,
				new Hypocenter(LATITUDE, LONGITUDE, ORIGINTIME, DEPTH, LATITUDEERROR,
						LONGITUDEERROR, TIMEERROR, DEPTHERROR),
				EVENTTYPE, MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
				THRESHOLDTYPE);

		// check data values
		checkData(altCorrelationObject, "Alternate Constructor 2");

		// use constructor
		Correlation altAltCorrelationObject = new Correlation(ID,
				new Site(SITEID, STATION, CHANNEL, NETWORK, LOCATION),
				new Source(AGENCYID, AUTHOR), PHASE, TIME, CORRELATION,
				new Hypocenter(LATITUDE, LONGITUDE, ORIGINTIME, DEPTH, LATITUDEERROR,
						LONGITUDEERROR, TIMEERROR, DEPTHERROR),
				EVENTTYPE, MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
				THRESHOLDTYPE, new Associated(ASSOCPHASE, ASSOCDISTANCE,
						ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA));

		// check data values
		checkData(altAltCorrelationObject, "Alternate Constructor 3");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		Correlation correlationObject = new Correlation(ID, SITEID, STATION,
				CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR, PHASE, TIME,
				CORRELATION, LATITUDE, LONGITUDE, ORIGINTIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR, EVENTTYPE,
				MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD, THRESHOLDTYPE,
				ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL,
				ASSOCSIGMA);

		// Successful validation
		boolean rc = correlationObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Correlation object
		Correlation badCorrelationObject = new Correlation("", null, "",
				CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR, PHASE, TIME,
				CORRELATION, LATITUDE, LONGITUDE, ORIGINTIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR, EVENTTYPE,
				MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD, THRESHOLDTYPE,
				ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL,
				ASSOCSIGMA);

		rc = badCorrelationObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(Correlation correlationObject, String TestName) {

		// check correlationObject.ID
		assertEquals(TestName + " ID Equals", ID, correlationObject.getID());

		// check correlationObject.site.Station
		assertEquals(TestName + " Station Equals", STATION,
				correlationObject.getSite().getStation());

		// check correlationObject.site.Channel
		assertEquals(TestName + " Channel Equals", CHANNEL,
				correlationObject.getSite().getChannel());

		// check correlationObject.site.Network
		assertEquals(TestName + " Network Equals", NETWORK,
				correlationObject.getSite().getNetwork());

		// check correlationObject.site.Location
		assertEquals(TestName + " Location Equals", LOCATION,
				correlationObject.getSite().getLocation());

		// check correlationObject.site.SiteID
		assertEquals(TestName + " SiteID Equals", SITEID,
				correlationObject.getSite().getSiteID());

		// check correlationObject.Source.AgencyID
		assertEquals(TestName + " AgencyID Equals", AGENCYID,
				correlationObject.getSource().getAgencyID());

		// check correlationObject.Source.Author
		assertEquals(TestName + " Author Equals", AUTHOR,
				correlationObject.getSource().getAuthor());

		// check correlationObject.Time
		assertEquals(TestName + " Time Equals", TIME,
				correlationObject.getTime());

		// check correlationObject.Phase
		assertEquals(TestName + " Phase Equals", PHASE,
				correlationObject.getPhase());

		// check correlationObject.Correlation
		assertEquals(TestName + " Correlation Equals", CORRELATION,
				correlationObject.getCorrelation(), 0);

		// check correlationObject.hypocenter.Latitude
		assertEquals(TestName + " Latitude Equals", LATITUDE,
				correlationObject.getHypocenter().getLatitude(), 0);

		// check correlationObject.hypocenter.Longitude
		assertEquals(TestName + " Longitude Equals", LONGITUDE,
				correlationObject.getHypocenter().getLongitude(), 0);

		// check correlationObject.hypocenter.Depth
		assertEquals(TestName + " Depth Equals", DEPTH,
				correlationObject.getHypocenter().getDepth(), 0);

		// check correlationObject.hypocenter.Time
		assertEquals(TestName + " OriginTime Equals", ORIGINTIME,
				correlationObject.getHypocenter().getTime());

		// check correlationObject.hypocenter.LatitudeError
		assertEquals(TestName + " LatitudeError Equals", LATITUDEERROR,
				correlationObject.getHypocenter().getLatitudeError(), 0);

		// check correlationObject.hypocenter.LongitudeError
		assertEquals(TestName + " LongitudError Equals", LONGITUDEERROR,
				correlationObject.getHypocenter().getLongitudeError(), 0);

		// check correlationObject.hypocenter.DepthError
		assertEquals(TestName + " DepthError Equals", DEPTHERROR,
				correlationObject.getHypocenter().getDepthError(), 0);

		// check correlationObject.hypocenter.TimeError
		assertEquals(TestName + " TimeError Equals", TIMEERROR,
				correlationObject.getHypocenter().getTimeError(), 0);

		// check correlationObject.EventType
		assertEquals(TestName + " EventType Equals", EVENTTYPE,
				correlationObject.getEventType());

		// check correlationObject.Magnitude
		assertEquals(TestName + " Magnitude Equals", MAGNITUDE,
				correlationObject.getMagnitude(), 0);

		// check correlationObject.SNR
		assertEquals(TestName + " SNR Equals", SNR, correlationObject.getSNR(),
				0);

		// check correlationObject.ZScore
		assertEquals(TestName + " ZScore Equals", ZSCORE,
				correlationObject.getZScore(), 0);

		// check correlationObject.DetectionThreshold
		assertEquals(TestName + " DetectionThreshold Equals",
				DETECTIONTHRESHOLD, correlationObject.getDetectionThreshold(),
				0);

		// check correlationObject.ThresholdType
		assertEquals(TestName + " ThresholdType Equals", THRESHOLDTYPE,
				correlationObject.getThresholdType());

		if (!correlationObject.getAssociationInfo().isEmpty()) {
			// check correlationObject.Associated.Phase
			assertEquals(TestName + " Phase Equals", ASSOCPHASE,
					correlationObject.getAssociationInfo().getPhase());

			// check correlationObject.Associated.Distance
			assertEquals(TestName + " Distance Equals", ASSOCDISTANCE,
					correlationObject.getAssociationInfo().getDistance(), 0);

			// check correlationObject.Associated.Azimuth
			assertEquals(TestName + " Azimuth Equals", ASSOCAZIMUTH,
					correlationObject.getAssociationInfo().getAzimuth(), 0);

			// check correlationObject.Associated.Residual
			assertEquals(TestName + " Residual Equals", ASSOCRESIDUAL,
					correlationObject.getAssociationInfo().getResidual(), 0);

			// check correlationObject.Associated.Sigma
			assertEquals(TestName + " Sigma Equals", ASSOCSIGMA,
					correlationObject.getAssociationInfo().getSigma(), 0);
		}

	}

}
