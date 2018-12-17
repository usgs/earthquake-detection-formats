package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class FilterTest {

	public static final String FILTER_STRING = "{\"Type\":\"BandPass\","
			+ "\"HighPass\":1.05,"
			+ "\"LowPass\":2.65,"
			+ "\"Units\":\"Hertz\"}";
	public static final String TYPE = "BandPass";
	public static final double HIGHPASS = 1.05;
	public static final double LOWPASS = 2.65;
	public static final String UNITS = "Hertz";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
		Filter filterObject = new Filter(TYPE, HIGHPASS, LOWPASS, UNITS);

		// write out to a string
		String jsonString = Utility.toJSONString(filterObject.toJSON());

		// check the data
		try {
			CheckData(new Filter(Utility.fromJSONString(jsonString)),
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
		// build Filter object
		try {
			CheckData(new Filter(Utility.fromJSONString(FILTER_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Constructor tests
	 */
	@Test
	public void Constructor() {
		Filter filterObject = new Filter(TYPE, HIGHPASS, LOWPASS, UNITS);

		// check the data
		CheckData(filterObject, "Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Filter emptyObject = new Filter(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		Filter filterObject = new Filter(TYPE, HIGHPASS, LOWPASS, UNITS);

		// Successful validation
		boolean rc = filterObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// Can't think of a way to make an invalid filter object
	}

	/**
	 * Empty check function
	 */
	@Test
	public void IsEmpty() {
		// empty object
		Filter filterObject = new Filter();

		// checked for empty
		boolean rc = filterObject.isEmpty();

		// check return code
		assertEquals("Tested for empty.", true, rc);

		// not empty object
		Filter filterObject2 = new Filter(TYPE, HIGHPASS, LOWPASS, UNITS);

		// checked for empty
		rc = filterObject2.isEmpty();

		// check return code
		assertEquals("Tested for not empty.", false, rc);		
	}

	public void CheckData(Filter FilterObject, String TestName) {
		// check FilterObject.type
		if (FilterObject.getType() != null) {
			assertEquals(TestName + " Type Equals", TYPE,
				FilterObject.getType());
		}

		// check FilterObject.highPass
		if (FilterObject.getHighPass() != null) {
			assertEquals(TestName + " HighPass Equals", HIGHPASS,
				FilterObject.getHighPass(), 0);
		}

		// check FilterObject.lowPass
		if (FilterObject.getLowPass() != null) {
			assertEquals(TestName + " LowPass Equals", LOWPASS,
				FilterObject.getLowPass(), 0);
		}

		// check FilterObject.units
		if (FilterObject.getUnits() != null) {
			assertEquals(TestName + " Units Equals", UNITS,
				FilterObject.getUnits());
		}
	}
}
