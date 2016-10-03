package gov.usgs.detectionformats;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class FilterTest {

	public static final String FILTER_STRING = "{\"HighPass\":1.05,"
			+ "\"LowPass\":2.65}";
	public static final double HIGHPASS = 1.05;
	public static final double LOWPASS = 2.65;

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {

		Filter filterObject = new Filter(HIGHPASS, LOWPASS);

		// write out to a string
		String jsonString = Utility.toJSONString(filterObject.toJSON());

		// check the data
		try {
			checkData(new Filter(Utility.fromJSONString(jsonString)),
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

			checkData(new Filter(Utility.fromJSONString(FILTER_STRING)),
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

		Filter filterObject = new Filter(HIGHPASS, LOWPASS);

		// Successful validation
		boolean rc = filterObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);
	}

	public void checkData(Filter FilterObject, String TestName) {

		// check FilterObject.HighPass
		assertEquals(TestName + " HighPass Equals", HIGHPASS,
				FilterObject.getHighPass(), 0);

		// check FilterObject.LowPass
		assertEquals(TestName + " Azimuth Equals", LOWPASS,
				FilterObject.getLowPass(), 0);

	}

}
