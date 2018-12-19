package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class RetractTest {
	public static String RETRACT_STRING = "{\"Type\":\"Retract\",\"Source\":{\"Author\":"
			+ "\"TestAuthor\",\"AgencyID\":\"US\"},\"ID\":\"12GFH48776857\"}";
	public static String ID = "12GFH48776857";
	public static String AGENCYID = "US";
	public static String AUTHOR = "TestAuthor";
	
	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
		Retract retractObject = new Retract(ID, AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(retractObject.toJSON());

		// check the data
		try {
			CheckData(new Retract(Utility.fromJSONString(jsonString)),
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
			CheckData(new Retract(Utility.fromJSONString(RETRACT_STRING)),
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
		// use constructor
		Retract retractObject = new Retract(ID, AGENCYID, AUTHOR);

		// check data values
		CheckData(retractObject, "Constructor");

		// use constructor
		Retract altRetractObject = new Retract(ID, new Source(AGENCYID, AUTHOR));

		// check data values
		CheckData(altRetractObject, "Alternate Constructor");	
		
		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Retract emptyObject = new Retract(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		Retract retractObject = new Retract(ID, AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = retractObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Retract object
		Retract badRetractObject = new Retract();

		rc = badRetractObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);

		// build bad Retract object
		Retract badRetractObject2= new Retract("", "", null);

		rc = badRetractObject2.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 2", false, rc);
	}

	public void CheckData(Retract retractObject, String TestName) {
		// check retractObject.ID
		if (retractObject.getID() != null) {
			assertEquals(TestName + " ID Equals", ID, retractObject.getID());
		}

		// check retractObject.Source
		if (retractObject.getSource() != null) {
			// check retractObject.Source.AgencyID
			if (retractObject.getSource().getAgencyID() != null) {
				assertEquals(TestName + " AgencyID Equals", AGENCYID,
					retractObject.getSource().getAgencyID());
			}

			// check retractObject.Source.Author
			if (retractObject.getSource().getAuthor() != null) {
				assertEquals(TestName + " Author Equals", AUTHOR,
					retractObject.getSource().getAuthor());
			}
		}
	}	
}
