package gov.usgs.detectionformats;

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
	public void writesJSON() {

		Hypocenter hypoObject = new Hypocenter(LATITUDE, LONGITUDE, TIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

		// write out to a string
		String jsonString = Utility.toJSONString(hypoObject.toJSON());

		// check the data
		try {
			checkData(new Hypocenter(Utility.fromJSONString(jsonString)),
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

			checkData(new Hypocenter(Utility.fromJSONString(HYPO_STRING)),
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

		Hypocenter hypoObject = new Hypocenter(LATITUDE, LONGITUDE, TIME, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

		// Successful validation
		boolean rc = hypoObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Hypo object
		Hypocenter badHypoObject = new Hypocenter(null, LONGITUDE, null, DEPTH,
				LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

		rc = badHypoObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(Hypocenter hypoObject, String TestName) {

		// check hypoObject.Latitude
		assertEquals(TestName + " Latitude Equals", LATITUDE,
				hypoObject.getLatitude(), 0);

		// check hypoObject.Longitude
		assertEquals(TestName + " Longitude Equals", LONGITUDE,
				hypoObject.getLongitude(), 0);

		// check hypoObject.Depth
		assertEquals(TestName + " Depth Equals", DEPTH, hypoObject.getDepth(),
				0);

		// check hypoObject.Time
		assertEquals(TestName + " Time Equals", TIME, hypoObject.getTime());

		// check hypoObject.LatitudeError
		assertEquals(TestName + " LatitudeError Equals", LATITUDEERROR,
				hypoObject.getLatitudeError(), 0);

		// check hypoObject.LongitudeError
		assertEquals(TestName + " LongitudError Equals", LONGITUDEERROR,
				hypoObject.getLongitudeError(), 0);

		// check hypoObject.DepthError
		assertEquals(TestName + " DepthError Equals", DEPTHERROR,
				hypoObject.getDepthError(), 0);

		// check hypoObject.TimeError
		assertEquals(TestName + " TimeError Equals", TIMEERROR,
				hypoObject.getTimeError(), 0);

	}

}
