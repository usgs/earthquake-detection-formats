package gov.usgs.detectionformats;

import org.json.simple.parser.ParseException;
import org.junit.Test;

import static org.junit.Assert.*;

public class SiteTest {

	public static final String SITE_STRING = "{\"Station\":\"BMN\",\"Channel\":"
			+ "\"HHZ\",\"Network\":\"LB\",\"Location\":\"01\",\"SiteID\":"
			+ "\"BMN.HHZ.LB.01\"}";
	public static final String STATION = "BMN";
	public static final String CHANNEL = "HHZ";
	public static final String NETWORK = "LB";
	public static final String LOCATION = "01";
	public static final String SITEID = "BMN.HHZ.LB.01";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void writesJSON() {

		Site SiteObject = new Site(SITEID, STATION, CHANNEL, NETWORK, LOCATION);

		// write out to a string
		String jsonString = Utility.toJSONString(SiteObject.toJSON());

		// check the data
		try {
			checkData(new Site(Utility.fromJSONString(jsonString)),
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

		// build Amplitude object
		try {

			checkData(new Site(Utility.fromJSONString(SITE_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		Site siteObject = new Site(SITEID, STATION, CHANNEL, NETWORK, LOCATION);

		// Successful validation
		boolean rc = siteObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad source object
		Site badSiteObject = new Site(SITEID, null, null, null, null);

		rc = badSiteObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	/**
	 * Checks the data in the class
	 */
	public void checkData(Site SiteObject, String TestName) {

		// check SiteObject.Station
		assertEquals(TestName + " Site Equals", STATION,
				SiteObject.getStation());

		// check SiteObject.Channel
		assertEquals(TestName + " Channel Equals", CHANNEL,
				SiteObject.getChannel());

		// check SiteObject.Network
		assertEquals(TestName + " Network Equals", NETWORK,
				SiteObject.getNetwork());

		// check SiteObject.Location
		assertEquals(TestName + " Location Equals", LOCATION,
				SiteObject.getLocation());

		// check SiteObject.SiteID
		assertEquals(TestName + " SiteID Equals", SITEID,
				SiteObject.getSiteID());

	}

}
