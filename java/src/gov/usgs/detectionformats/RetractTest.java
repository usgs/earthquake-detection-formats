package gov.usgs.detectionformats;

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
	public void writesJSON() {

		Retract retractObject = new Retract(ID, AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(retractObject.toJSON());

		// check the data
		try {
			checkData(new Retract(Utility.fromJSONString(jsonString)),
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

			checkData(new Retract(Utility.fromJSONString(RETRACT_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Constructor fills in members correctly
	 */
	@Test
	public void altConstructors() {

		// use constructor
		Retract retractObject = new Retract(ID, AGENCYID, AUTHOR);

		// check data values
		checkData(retractObject, "Alternate Constructor 1");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		Retract retractObject = new Retract(ID, AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = retractObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Retract object
		Retract badRetractObject = new Retract("", AGENCYID, null);

		rc = badRetractObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(Retract retractObject, String TestName) {

		// check originObject.ID
		assertEquals(TestName + " ID Equals", ID, retractObject.getID());

		// check originObject.Source.AgencyID
		assertEquals(TestName + " AgencyID Equals", AGENCYID, retractObject
				.getSource().getAgencyID());

		// check originObject.Source.Author
		assertEquals(TestName + " Author Equals", AUTHOR, retractObject
				.getSource().getAuthor());
	}	
}
