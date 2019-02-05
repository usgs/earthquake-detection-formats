package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class AssociationTest {

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
	public void WritesJSON() {
		Association associationObject = new Association(PHASE, DISTANCE, AZIMUTH,
			RESIDUAL, SIGMA);

		// write out to a string
		String jsonString = Utility.toJSONString(associationObject.toJSON());

		// check the data
		try {
			CheckData(new Association(Utility.fromJSONString(jsonString)),
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
		// build Association object
		try {
			CheckData(
				new Association(Utility.fromJSONString(ASSOCIATED_STRING)),
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
		Association associationObject = new Association(PHASE, DISTANCE, AZIMUTH,
			RESIDUAL, SIGMA);

		// check data values
		CheckData(associationObject, "Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Association emptyObject = new Association(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");		
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {
		Association associationObject = new Association(PHASE, DISTANCE, AZIMUTH,
			RESIDUAL, SIGMA);

		// Successful validation
		boolean rc = associationObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Association object
		Association badAssociationObject = new Association("22", -99.0,
			-99.0, null, null);

		rc = badAssociationObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	/**
	 * Empty check function
	 */
	@Test
	public void IsEmpty() {
		// empty object
		Association associationObject = new Association();

		// checked for empty
		boolean rc = associationObject.isEmpty();

		// check return code
		assertEquals("Tested for empty.", true, rc);

		// not empty object
		Association associationObject2 = new Association(PHASE, DISTANCE, 
			AZIMUTH, RESIDUAL, SIGMA);

		// checked for empty
		rc = associationObject2.isEmpty();

		// check return code
		assertEquals("Tested for not empty.", false, rc);		
	}

	/**
	 * Checks the data in the class
	 */
	public void CheckData(Association AssociationObject, String TestName) {

		// check AssociationObject.Phase
		if (AssociationObject.getPhase() != null) {
			assertEquals(TestName + " Phase Equals", PHASE,
				AssociationObject.getPhase());
		}

		// check AssociationObject.Distance
		if (AssociationObject.getDistance() != null) {
			assertEquals(TestName + " Distance Equals", DISTANCE,
			AssociationObject.getDistance(), 0);
		}

		// check AssociationObject.Azimuth
		if (AssociationObject.getAzimuth() != null) {
			assertEquals(TestName + " Azimuth Equals", AZIMUTH,
				AssociationObject.getAzimuth(), 0);
		}

		// check AssociationObject.Residual
		if (AssociationObject.getResidual() != null) {
			assertEquals(TestName + " Residual Equals", RESIDUAL,
				AssociationObject.getResidual(), 0);
		}

		// check AssociationObject.Sigma
		if (AssociationObject.getSigma() != null) {
			assertEquals(TestName + " Sigma Equals", SIGMA,
				AssociationObject.getSigma(), 0);
		}
	}
}
