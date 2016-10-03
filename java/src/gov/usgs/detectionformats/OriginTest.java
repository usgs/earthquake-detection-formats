package gov.usgs.detectionformats;

import static org.junit.Assert.*;
import java.util.Date;
import java.util.ArrayList;
import org.json.simple.parser.ParseException;
import org.junit.Test;

public class OriginTest {

	public static String ORIGIN_STRING = "{\"Gap\":33.67,\"Type\":\"Origin\","
			+ "\"RMS\":3.8,\"OriginType\":\"New\",\"Bayes\":2.65,\"EventType\":"
			+ "\"earthquake\",\"Depth\":32.44,\"Source\":{\"Author\":"
			+ "\"TestAuthor\",\"AgencyID\":\"US\"},\"Data\":[{\"Source\":"
			+ "{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},\"Filter\":"
			+ "[{\"HighPass\":1.05,\"LowPass\":2.65}],\"Onset\":\"questionable\","
			+ "\"Amplitude\":{\"Period\":2.65,\"Amplitude\":21.5,\"SNR\":3.8},"
			+ "\"Time\":\"2015-12-28T21:32:24.017Z\",\"Site\":{\"Station\":"
			+ "\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\",\"Location\":"
			+ "\"01\",\"SiteID\":\"BMN.HHZ.LB.01\"},\"Type\":\"Pick\",\"ID\":"
			+ "\"12GFH48776857\",\"Polarity\":\"up\",\"Phase\":\"P\",\"Picker\":"
			+ "\"manual\",\"AssociationInfo\":{\"Distance\":0.442559,\"Azimuth\":"
			+ "0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":-0.025393}},"
			+ "{\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},"
			+ "\"Time\":\"2015-12-28T21:32:24.017Z\",\"Site\":{\"Station\":"
			+ "\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\",\"Location\":"
			+ "\"01\",\"SiteID\":\"BMN.HHZ.LB.01\"},\"Type\":\"Beam\","
			+ "\"BackAzimuth\":2.65,\"ID\":\"12GFH48776857\",\"BackAzimuthError\":"
			+ "3.8,\"Slowness\":1.44,\"AssociationInfo\":{\"Distance\":0.442559,"
			+ "\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":"
			+ "-0.025393},\"SlownessError\":0.4},{\"ZScore\":33.67,\"Magnitude\":"
			+ "2.14,\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":"
			+ "\"LB\",\"Location\":\"01\",\"SiteID\":\"BMN.HHZ.LB.01\"},\"Type\":"
			+ "\"Correlation\",\"Correlation\":2.65,\"EventType\":\"earthquake\","
			+ "\"Depth\":32.44,\"AssociationInfo\":{\"Distance\":0.442559,"
			+ "\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":"
			+ "-0.025393},\"DetectionThreshold\":1.5,\"Source\":{\"Author\":"
			+ "\"TestAuthor\",\"AgencyID\":\"US\"},\"Time\":"
			+ "\"2015-12-28T21:32:24.017Z\",\"SNR\":3.8,\"OriginTime\":"
			+ "\"2015-12-28T21:30:44.039Z\",\"ID\":\"12GFH48776857\",\"Latitude\":"
			+ "40.3344,\"Longitude\":-121.44,\"ThresholdType\":\"minimum\","
			+ "\"Phase\":\"P\"}],\"Time\":\"2015-12-28T21:32:24.017Z\",\"ID\":"
			+ "\"12GFH48776857\",\"Latitude\":40.3344,\"Longitude\":-121.44,"
			+ "\"MinimumDistance\":2.14}";
	public static String ID = "12GFH48776857";
	public static String AGENCYID = "US";
	public static String AUTHOR = "TestAuthor";
	public static double LATITUDE = 40.3344;
	public static double LONGITUDE = -121.44;
	public static Date TIME = Utility.getDate("2015-12-28T21:32:24.017Z");
	public static double DEPTH = 32.44;
	public static String ORIGINTYPE = "New";
	public static String EVENTTYPE = "earthquake";
	public static double BAYES = 2.65;
	public static double MINIMUMDISTANCE = 2.14;
	public static double RMS = 3.8;
	public static double GAP = 33.67;
	public static String PICKDATA = "{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\""
			+ ",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\","
			+ "\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},"
			+ "\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},"
			+ "\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\","
			+ "\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":"
			+ "\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65}],"
			+ "\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},"
			+ "\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,"
			+ "\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}";
	public static String BEAMDATA = "{\"Type\":\"Beam\",\"ID\":\"12GFH48776857\""
			+ ",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\","
			+ "\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},"
			+ "\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},"
			+ "\"Time\":\"2015-12-28T21:32:24.017Z\",\"BackAzimuth\":2.65,"
			+ "\"Slowness\":1.44,\"BackAzimuthError\":3.8,\"SlownessError\":"
			+ "0.4,\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,"
			+ "\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}";
	public static String CORRELATIONDATA = "{\"Type\":\"Correlation\",\"ID\":"
			+ "\"12GFH48776857\",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\","
			+ "\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\","
			+ "\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":"
			+ "\"TestAuthor\"},\"Phase\":\"P\","
			+ "\"Time\":\"2015-12-28T21:32:24.017Z\",\"Correlation\":2.65,"
			+ "\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44,"
			+ "\"OriginTime\":\"2015-12-28T21:30:44.039Z\",\"EventType\":"
			+ "\"earthquake\",\"Magnitude\":2.14,\"SNR\":3.8,\"ZScore\":33.67,"
			+ "\"DetectionThreshold\":1.5,\"ThresholdType\":\"minimum\","
			+ "\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,"
			+ "\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void writesJSON() {

		Origin originObject = new Origin(ID, AGENCYID, AUTHOR, LATITUDE,
				LONGITUDE, TIME, DEPTH, ORIGINTYPE, EVENTTYPE, BAYES,
				MINIMUMDISTANCE, RMS, GAP, buildPickData(), buildBeamData(),
				buildCorrelationData());

		// write out to a string
		String jsonString = Utility.toJSONString(originObject.toJSON());

		// check the data
		try {
			checkData(new Origin(Utility.fromJSONString(jsonString)),
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

			checkData(new Origin(Utility.fromJSONString(ORIGIN_STRING)),
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
		Origin originObject = new Origin(ID, new Source(AGENCYID, AUTHOR),
				LATITUDE, LONGITUDE, TIME, DEPTH, ORIGINTYPE, EVENTTYPE, BAYES,
				MINIMUMDISTANCE, RMS, GAP, buildPickData(), buildBeamData(),
				buildCorrelationData());

		// check data values
		checkData(originObject, "Alternate Constructor 1");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		Origin originObject = new Origin(ID, AGENCYID, AUTHOR, LATITUDE,
				LONGITUDE, TIME, DEPTH, ORIGINTYPE, EVENTTYPE, BAYES,
				MINIMUMDISTANCE, RMS, GAP, buildPickData(), buildBeamData(),
				buildCorrelationData());

		// Successful validation
		boolean rc = originObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Origin object
		Origin badOriginObject = new Origin("", AGENCYID, null, LATITUDE,
				LONGITUDE, null, DEPTH, ORIGINTYPE, EVENTTYPE, BAYES,
				MINIMUMDISTANCE, RMS, GAP, buildPickData(), buildBeamData(),
				buildCorrelationData());

		rc = badOriginObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(Origin originObject, String TestName) {

		// check originObject.ID
		assertEquals(TestName + " ID Equals", ID, originObject.getID());

		// check originObject.Source.AgencyID
		assertEquals(TestName + " AgencyID Equals", AGENCYID,
				originObject.getSource().getAgencyID());

		// check originObject.Source.Author
		assertEquals(TestName + " Author Equals", AUTHOR,
				originObject.getSource().getAuthor());

		// check originObject.Latitude
		assertEquals(TestName + " Latitude Equals", LATITUDE,
				originObject.getLatitude(), 0);

		// check originObject.Longitude
		assertEquals(TestName + " Longitude Equals", LONGITUDE,
				originObject.getLongitude(), 0);

		// check originObject.Time
		assertEquals(TestName + " Time Equals", TIME, originObject.getTime());

		// check originObject.Depth
		assertEquals(TestName + " Depth Equals", DEPTH, originObject.getDepth(),
				0);

		// check OriginObject.OriginType
		assertEquals(TestName + " OriginType Equals", ORIGINTYPE,
				originObject.getOriginType());

		// check originObject.EventType
		assertEquals(TestName + " EventType Equals", EVENTTYPE,
				originObject.getEventType());

		// check OriginObject.Bayes
		assertEquals(TestName + " Bayes Equals", BAYES, originObject.getBayes(),
				0);

		// check OriginObject.MinimumDistance
		assertEquals(TestName + " MinimumDistance Equals", MINIMUMDISTANCE,
				originObject.getMinimumDistance(), 0);

		// check OriginObject.RMS
		assertEquals(TestName + " RMS Equals", RMS, originObject.getRMS(), 0);

		// check OriginObject.Gap
		assertEquals(TestName + " Gap Equals", GAP, originObject.getGap(), 0);

		// need to check data still!!!!!!
		// somehow?
	}

	public ArrayList<Pick> buildPickData() {
		ArrayList<Pick> newPickData = new ArrayList<Pick>();

		// Pick ?need one more?
		try {
			newPickData.add(new Pick(Utility.fromJSONString(PICKDATA)));
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return (newPickData);
	}

	public ArrayList<Beam> buildBeamData() {
		ArrayList<Beam> newBeamData = new ArrayList<Beam>();

		// Beam ?need one more?
		try {
			newBeamData.add(new Beam(Utility.fromJSONString(BEAMDATA)));
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return (newBeamData);
	}

	public ArrayList<Correlation> buildCorrelationData() {
		ArrayList<Correlation> newCorrelationData = new ArrayList<Correlation>();

		// Correlation ?need one more?
		try {
			newCorrelationData.add(
					new Correlation(Utility.fromJSONString(CORRELATIONDATA)));
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return (newCorrelationData);
	}

}
