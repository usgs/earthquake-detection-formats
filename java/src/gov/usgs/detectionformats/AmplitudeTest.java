package gov.usgs.detectionformats;

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
	public void writesJSON() {

		Amplitude amplitudeObject = new Amplitude(AMPLITUDE, PERIOD, SNR);

		// write out to a string
		String jsonString = Utility.toJSONString(amplitudeObject.toJSON());

		// check the data
		try {
			checkData(new Amplitude(Utility.fromJSONString(jsonString)),
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

			checkData(new Amplitude(Utility.fromJSONString(AMPLITUDE_STRING)),
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

		Amplitude amplitudeObject = new Amplitude(AMPLITUDE, PERIOD, SNR);

		// Successful validation
		boolean rc = amplitudeObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);
	}

	/**
	 * Checks the data in the class
	 */
	public void checkData(Amplitude AmplitudeObject, String TestName) {

		// check AmplitudeObject.Amplitude
		assertEquals(TestName + " Amplitude Equals", AMPLITUDE,
				AmplitudeObject.getAmplitude(), 0);

		// check AmplitudeObject.Period
		assertEquals(TestName + " Period Equals", PERIOD,
				AmplitudeObject.getPeriod(), 0);

		// check AmplitudeObject.SNR
		assertEquals(TestName + " SNR Equals", SNR, AmplitudeObject.getSNR(), 0);
	}
}
