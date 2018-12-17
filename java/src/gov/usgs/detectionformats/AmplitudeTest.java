package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class AmplitudeTest {

	public static final String AMPLITUDE_STRING = "{\"Period\":2.65,"
			+ "\"Amplitude\":1.05,\"SNR\":3.8}";
	public static final double AMPLITUDE = 1.05;
	public static final double PERIOD = 2.65;
	public static final double SNR = 3.8;

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {

		Amplitude amplitudeObject = new Amplitude(AMPLITUDE, PERIOD, SNR);

		// write out to a string
		String jsonString = Utility.toJSONString(amplitudeObject.toJSON());

		// check the data
		try {
			CheckData(new Amplitude(Utility.fromJSONString(jsonString)),
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

		// build Amplitude object
		try {

			CheckData(new Amplitude(Utility.fromJSONString(AMPLITUDE_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Constructor fills in members correctly
	 */
	@Test
	public void Constructor() {
		Amplitude amplitudeObject = new Amplitude(AMPLITUDE, PERIOD, SNR);

		// check data values
		CheckData(amplitudeObject, "Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Amplitude emptyObject = new Amplitude(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");	
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		Amplitude amplitudeObject = new Amplitude(AMPLITUDE, PERIOD, SNR);

		// Successful validation
		boolean rc = amplitudeObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Pick object
		Amplitude badAmplitudeObject = new Amplitude(null, -9999.0, -9999.0);

		// Unuccessful validation
		rc = badAmplitudeObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 2", false, rc);		
	}

	/**
	 * Empty check function
	 */
	@Test
	public void IsEmpty() {
		// empty object
		Amplitude amplitudeObject = new Amplitude();

		// checked for empty
		boolean rc = amplitudeObject.isEmpty();

		// check return code
		assertEquals("Tested for empty.", true, rc);

		// not empty object
		Amplitude amplitudeObject2 = new Amplitude(AMPLITUDE, PERIOD, SNR);

		// checked for empty
		rc = amplitudeObject2.isEmpty();

		// check return code
		assertEquals("Tested for not empty.", false, rc);		
	}

	/**
	 * Checks the data in the class
	 */
	public void CheckData(Amplitude AmplitudeObject, String TestName) {
		// check AmplitudeObject.Amplitude
		if (AmplitudeObject.getAmplitude() != null) {
			assertEquals(TestName + " Amplitude Equals", AMPLITUDE,
				AmplitudeObject.getAmplitude(), 0);
		}

		// check AmplitudeObject.Period
		if (AmplitudeObject.getPeriod() != null) {
			assertEquals(TestName + " Period Equals", PERIOD,
				AmplitudeObject.getPeriod(), 0);
		}

		// check AmplitudeObject.SNR
		if (AmplitudeObject.getSNR() != null) {
			assertEquals(TestName + " SNR Equals", SNR, 
				AmplitudeObject.getSNR(), 0);
		}
	}
}
