package gov.usgs.detectionformats;

import static org.junit.Assert.*;
import java.util.Date;
import org.json.simple.parser.ParseException;
import org.junit.Test;

public class BeamTest {

	public static String BEAM_STRING = "{\"Source\":{\"Author\":\"TestAuthor\","
			+ "\"AgencyID\":\"US\"},\"StartTime\":\"2015-12-28T21:32:24.017Z\","
			+ "\"EndTime\":\"2015-12-28T21:32:30.017Z\","
			+ "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":"
			+ "\"LB\",\"Location\":\"01\",\"SiteID\":\"BMN.HHZ.LB.01\"},"
			+ "\"Type\":\"Beam\",\"BackAzimuth\":2.65,\"ID\":\"12GFH48776857\","
			+ "\"BackAzimuthError\":3.8,\"Slowness\":1.44,\"AssociationInfo\":"
			+ "{\"Distance\":0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\","
			+ "\"Sigma\":0.086333,\"Residual\":-0.025393},\"SlownessError\":0.4"
			+ "\"Power\":12.18,\"PowerError\":0.557}";
	public static String ID = "12GFH48776857";
	public static String STATION = "BMN";
	public static String CHANNEL = "HHZ";
	public static String NETWORK = "LB";
	public static String LOCATION = "01";
	public static String SITEID = "BMN.HHZ.LB.01";
	public static String AGENCYID = "US";
	public static String AUTHOR = "TestAuthor";
	public static Date STARTTIME = Utility.getDate("2015-12-28T21:32:24.017Z");
	public static Date ENDTIME = Utility.getDate("2015-12-28T21:32:30.017Z");
	public static double BACKAZIMUTH = 2.65;
	public static double BACKAZIMUTHERROR = 3.8;
	public static double SLOWNESS = 1.44;
	public static double SLOWNESSERROR = 0.4;
	public static double POWER = 12.18;
	public static double POWERERROR = 0.557;
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

		Beam beamObject = new Beam(ID, SITEID, STATION, CHANNEL, NETWORK,
				LOCATION, AGENCYID, AUTHOR, STARTTIME, ENDTIME, BACKAZIMUTH,
				BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWER, POWERERROR,
				ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

		// write out to a string
		String jsonString = Utility.toJSONString(beamObject.toJSON());

		// check the data
		try {
			checkData(new Beam(Utility.fromJSONString(jsonString)),
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

		// build Beam object
		try {

			checkData(new Beam(Utility.fromJSONString(BEAM_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}

	}

	/**
	 * Constructors fills in members correctly
	 */
	@Test
	public void altConstructors() {

		// use constructor
		Beam beamObject = new Beam(ID, SITEID, STATION, CHANNEL, NETWORK,
				LOCATION, AGENCYID, AUTHOR, STARTTIME, ENDTIME, BACKAZIMUTH,
				BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWER, POWERERROR);

		// check data values
		checkData(beamObject, "Alternate Constructor 1");

		// use constructor
		Beam altBeamObject = new Beam(ID,
				new Site(SITEID, STATION, CHANNEL, NETWORK, LOCATION),
				new Source(AGENCYID, AUTHOR), STARTTIME, ENDTIME, BACKAZIMUTH,
				BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWER, POWERERROR);

		// check data values
		checkData(altBeamObject, "Alternate Constructor 2");

		// use constructor
		Beam altAltBeamObject = new Beam(ID,
				new Site(SITEID, STATION, CHANNEL, NETWORK, LOCATION),
				new Source(AGENCYID, AUTHOR), STARTTIME, ENDTIME, BACKAZIMUTH,
				BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWER, POWERERROR,
				new Associated(ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH,
						ASSOCRESIDUAL, ASSOCSIGMA));

		// check data values
		checkData(altAltBeamObject, "Alternate Constructor 3");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		Beam beamObject = new Beam(ID, SITEID, STATION, CHANNEL, NETWORK,
				LOCATION, AGENCYID, AUTHOR, STARTTIME, ENDTIME, BACKAZIMUTH,
				BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWER, POWERERROR,
				ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

		// Successful validation
		boolean rc = beamObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Beam object
		Beam badBeamObject = new Beam("", null, "", CHANNEL, NETWORK, LOCATION,
				AGENCYID, AUTHOR, STARTTIME, ENDTIME, null, BACKAZIMUTHERROR,
				SLOWNESS, SLOWNESSERROR, POWER, POWERERROR, ASSOCPHASE, ASSOCDISTANCE,
				ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

		rc = badBeamObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(Beam beamObject, String TestName) {

		// check beamObject.ID
		assertEquals(TestName + " ID Equals", ID, beamObject.getID());

		// check beamObject.site.Station
		assertEquals(TestName + " Station Equals", STATION,
				beamObject.getSite().getStation());

		// check beamObject.site.Channel
		assertEquals(TestName + " Channel Equals", CHANNEL,
				beamObject.getSite().getChannel());

		// check beamObject.site.Network
		assertEquals(TestName + " Network Equals", NETWORK,
				beamObject.getSite().getNetwork());

		// check beamObject.site.Location
		assertEquals(TestName + " Location Equals", LOCATION,
				beamObject.getSite().getLocation());

		// check beamObject.site.SiteID
		assertEquals(TestName + " SiteID Equals", SITEID,
				beamObject.getSite().getSiteID());

		// check beamObject.Source.AgencyID
		assertEquals(TestName + " AgencyID Equals", AGENCYID,
				beamObject.getSource().getAgencyID());

		// check beamObject.Source.Author
		assertEquals(TestName + " Author Equals", AUTHOR,
				beamObject.getSource().getAuthor());

		// check beamObject.startTime
		assertEquals(TestName + " Start Time Equals", STARTTIME,
				beamObject.getStartTime());

		// check beamObject.endTime
		assertEquals(TestName + " End Time Equals", ENDTIME,
				beamObject.getEndTime());

		// check beamObject.BackAzimuth
		assertEquals(TestName + " BackAzimuth Equals", BACKAZIMUTH,
				beamObject.getBackAzimuth(), 0);

		// check beamObject.BackAzimuthError
		assertEquals(TestName + " BackAzimuthError Equals", BACKAZIMUTHERROR,
				beamObject.getBackAzimuthError(), 0);

		// check beamObject.Slowness
		assertEquals(TestName + " Slowness Equals", SLOWNESS,
				beamObject.getSlowness(), 0);

		// check beamObject.SlownessError
		assertEquals(TestName + " SlownessError Equals", SLOWNESSERROR,
				beamObject.getSlownessError(), 0);

		// check beamObject.Power
		assertEquals(TestName + " Slowness Equals", POWER,
				beamObject.getPower(), 0);

		// check beamObject.PowerError
		assertEquals(TestName + " SlownessError Equals", POWERERROR,
				beamObject.getPowerError(), 0);

		if (!beamObject.getAssociationInfo().isEmpty()) {
			// check beamObject.Associated.Phase
			assertEquals(TestName + " Phase Equals", ASSOCPHASE,
					beamObject.getAssociationInfo().getPhase());

			// check beamObject.Associated.Distance
			assertEquals(TestName + " Distance Equals", ASSOCDISTANCE,
					beamObject.getAssociationInfo().getDistance(), 0);

			// check beamObject.Associated.Azimuth
			assertEquals(TestName + " Azimuth Equals", ASSOCAZIMUTH,
					beamObject.getAssociationInfo().getAzimuth(), 0);

			// check beamObject.Associated.Residual
			assertEquals(TestName + " Residual Equals", ASSOCRESIDUAL,
					beamObject.getAssociationInfo().getResidual(), 0);

			// check beamObject.Associated.Sigma
			assertEquals(TestName + " Sigma Equals", ASSOCSIGMA,
					beamObject.getAssociationInfo().getSigma(), 0);
		}
	}
}
