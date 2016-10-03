package gov.usgs.detectionformats;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class AssociatedTest {

	public static final String ASSOCIATED_STRING = "{\"Distance\":0.442559,"
			+ "\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,"
			+ "\"Residual\":-0.025393}";
	public static final String PHASE = "P";
	public static final double DISTANCE = 0.442559;
	public static final double AZIMUTH = 0.418479;
	public static final double RESIDUAL = -0.025393;
	public static final double SIGMA = 0.086333;

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void writesJSON() {

		Associated associatedObject = new Associated(PHASE, DISTANCE, AZIMUTH,
				RESIDUAL, SIGMA);

		// write out to a string
		String jsonString = Utility.toJSONString(associatedObject.toJSON());

		// check the data
		try {
			checkData(new Associated(Utility.fromJSONString(jsonString)),
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

		// build Associated object
		try {

			checkData(
					new Associated(Utility.fromJSONString(ASSOCIATED_STRING)),
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

		Associated associatedObject = new Associated(PHASE, DISTANCE, AZIMUTH,
				RESIDUAL, SIGMA);

		// Successful validation
		boolean rc = associatedObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Associated object
		Associated badAssociatedObject = new Associated("22", DISTANCE,
				AZIMUTH, RESIDUAL, SIGMA);

		rc = badAssociatedObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	/**
	 * Checks the data in the class
	 */
	public void checkData(Associated AssociatedObject, String TestName) {

		// check AssociatedObject.Phase
		assertEquals(TestName + " Phase Equals", PHASE,
				AssociatedObject.getPhase());

		// check AssociatedObject.Distance
		assertEquals(TestName + " Distance Equals", DISTANCE,
				AssociatedObject.getDistance(), 0);

		// check AssociatedObject.Azimuth
		assertEquals(TestName + " Azimuth Equals", AZIMUTH,
				AssociatedObject.getAzimuth(), 0);

		// check AssociatedObject.Residual
		assertEquals(TestName + " Residual Equals", RESIDUAL,
				AssociatedObject.getResidual(), 0);

		// check AssociatedObject.Sigma
		assertEquals(TestName + " Sigma Equals", SIGMA,
				AssociatedObject.getSigma(), 0);
	}
}
