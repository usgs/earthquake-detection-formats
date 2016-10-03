package gov.usgs.detectionformats;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class SourceTest {

	public static final String SOURCE_STRING = "{\"Author\":"
			+ "\"TestAuthor\",\"AgencyID\":\"US\"}";
	public static final String AGENCYID = "US";
	public static final String AUTHOR = "TestAuthor";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void writesJSON() {

		Source sourceObject = new Source(AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(sourceObject.toJSON());

		// check the data
		try {
			checkData(new Source(Utility.fromJSONString(jsonString)),
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

		try {

			checkData(new Source(Utility.fromJSONString(SOURCE_STRING)),
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

		// build source object
		Source sourceObject = new Source(AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = sourceObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad source object
		Source badSourceObject = new Source(AGENCYID, null);

		rc = badSourceObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	/**
	 * Checks the data in the class
	 */
	public void checkData(Source SourceObject, String TestName) {

		// check SourceObject.AgencyID
		assertEquals(TestName + " AgencyID Equals", AGENCYID,
				SourceObject.getAgencyID());

		// check SourceObject.Author
		assertEquals(TestName + " Author Equals", AUTHOR,
				SourceObject.getAuthor());

	}
}
