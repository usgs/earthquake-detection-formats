package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import java.util.Date;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class HypocenterTest {
	public static final String HYPO_STRING = "{\"TimeError\":1.984,"
			+ "\"Time\":\"2015-12-28T21:32:24.017Z\",\"LongitudeError\":22.64,"
			+ "\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,"
			+ "\"Longitude\":-121.44,\"Depth\":32.44}";

	public static double LATITUDE = 40.3344;
	public static double LONGITUDE = -121.44;
	public static Date TIME = Utility.getDate("2015-12-28T21:32:24.017Z");
	public static double DEPTH = 32.44;
	public static double LATITUDEERROR = 12.5;
	public static double LONGITUDEERROR = 22.64;
	public static double DEPTHERROR = 2.44;
	public static double TIMEERROR = 1.984;

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
		Hypocenter hypoObject = new Hypocenter(LATITUDE, LONGITUDE, TIME, DEPTH,
			LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

		// write out to a string
		String jsonString = Utility.toJSONString(hypoObject.toJSON());

		// check the data
		try {
			CheckData(new Hypocenter(Utility.fromJSONString(jsonString)),
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
			CheckData(new Hypocenter(Utility.fromJSONString(HYPO_STRING)),
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
		Hypocenter hypoObject = new Hypocenter(LATITUDE, LONGITUDE, TIME, DEPTH,
			LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);
			
		// check data values
		CheckData(hypoObject, "Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Hypocenter emptyObject = new Hypocenter(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		Hypocenter hypoObject = new Hypocenter(LATITUDE, LONGITUDE, TIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

		// Successful validation
		boolean rc = hypoObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad source object
		Hypocenter badHypoObject = new Hypocenter();

		rc = badHypoObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 1", false, rc);

		// build bad Hypo object
		Hypocenter badHypoObject2 = new Hypocenter(-9999.0, 9999.0, null, 2000.0,
				null, null, null, null);

		rc = badHypoObject2.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 2", false, rc);
	}

	public void CheckData(Hypocenter hypoObject, String TestName) {
		// check hypoObject.Latitude
		if (hypoObject.getLatitude() != null) {
			assertEquals(TestName + " Latitude Equals", LATITUDE,
				hypoObject.getLatitude(), 0);
		}

		// check hypoObject.Longitude
		if (hypoObject.getLongitude() != null) {
			assertEquals(TestName + " Longitude Equals", LONGITUDE,
				hypoObject.getLongitude(), 0);
		}

		// check hypoObject.Depth
		if (hypoObject.getDepth() != null) {
			assertEquals(TestName + " Depth Equals", DEPTH, 
				hypoObject.getDepth(), 0);
		}

		// check hypoObject.Time
		if (hypoObject.getTime() != null) {
			assertEquals(TestName + " Time Equals", TIME, hypoObject.getTime());
		}

		// check hypoObject.LatitudeError
		if (hypoObject.getLatitudeError() != null) {
			assertEquals(TestName + " LatitudeError Equals", LATITUDEERROR,
				hypoObject.getLatitudeError(), 0);
		}

		// check hypoObject.LongitudeError
		if (hypoObject.getLongitudeError() != null) {
			assertEquals(TestName + " LongitudError Equals", LONGITUDEERROR,
				hypoObject.getLongitudeError(), 0);
		}

		// check hypoObject.DepthError
		if (hypoObject.getDepthError() != null) {
			assertEquals(TestName + " DepthError Equals", DEPTHERROR,
				hypoObject.getDepthError(), 0);
		}

		// check hypoObject.TimeError
		if (hypoObject.getTimeError() != null) {
			assertEquals(TestName + " TimeError Equals", TIMEERROR,
				hypoObject.getTimeError(), 0);
		}
	}
}
