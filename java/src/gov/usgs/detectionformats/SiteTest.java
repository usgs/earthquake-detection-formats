package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import org.json.simple.parser.ParseException;
import org.junit.Test;

import static org.junit.Assert.*;

public class SiteTest {

	public static final String SITE_STRING = "{\"Station\":\"BMN\",\"Channel\":"
			+ "\"HHZ\",\"Network\":\"LB\",\"Location\":\"01\"}";
	public static final String STATION = "BMN";
	public static final String CHANNEL = "HHZ";
	public static final String NETWORK = "LB";
	public static final String LOCATION = "01";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
		Site SiteObject = new Site(STATION, CHANNEL, NETWORK, LOCATION);

		// write out to a string
		String jsonString = Utility.toJSONString(SiteObject.toJSON());

		// check the data
		try {
			CheckData(new Site(Utility.fromJSONString(jsonString)),
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
		// build Amplitude object
		try {
			CheckData(new Site(Utility.fromJSONString(SITE_STRING)),
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
		Site SiteObject = new Site(STATION, CHANNEL, NETWORK, LOCATION);

		// check data values
		CheckData(SiteObject, "Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Site emptyObject = new Site(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");	
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		Site siteObject = new Site(STATION, CHANNEL, NETWORK, LOCATION);

		// Successful validation
		boolean rc = siteObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Site object
		Site badSiteObject = new Site();

		// Unuccessful validation
		rc = badSiteObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 1", false, rc);

		// build bad source object
		Site badSiteObject2 = new Site("", null, "", null);

		rc = badSiteObject2.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 2", false, rc);
	}

	/**
	 * Checks the data in the class
	 */
	public void CheckData(Site SiteObject, String TestName) {
		// check SiteObject.Station
		if (SiteObject.getStation() != null) {
			assertEquals(TestName + " Station Equals", STATION,
				SiteObject.getStation());
		}

		// check SiteObject.Channel
		if (SiteObject.getChannel() != null) {
			assertEquals(TestName + " Channel Equals", CHANNEL,
				SiteObject.getChannel());
		}

		// check SiteObject.Network
		if (SiteObject.getNetwork() != null) {
			assertEquals(TestName + " Network Equals", NETWORK,
				SiteObject.getNetwork());
		}

		// check SiteObject.Location
		if (SiteObject.getLocation() != null) {
			assertEquals(TestName + " Location Equals", LOCATION,
				SiteObject.getLocation());
		}
	}
}
