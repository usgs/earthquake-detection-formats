package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

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
	public void WritesJSON() {
		Source sourceObject = new Source(AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(sourceObject.toJSON());

		// check the data
		try {
			CheckData(new Source(Utility.fromJSONString(jsonString)),
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
		try {
			CheckData(new Source(Utility.fromJSONString(SOURCE_STRING)),
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
		Source sourceObject = new Source(AGENCYID, AUTHOR);
			
		// check data values
		CheckData(sourceObject, "Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Source emptyObject = new Source(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		// build source object
		Source sourceObject = new Source(AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = sourceObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad source object
		Source badSourceObject = new Source();

		rc = badSourceObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);

		// build bad source object
		Source badSourceObject2 = new Source("", "");

		rc = badSourceObject2.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 2", false, rc);
	}

	/**
	 * Empty check function
	 */
	@Test
	public void IsEmpty() {
		// empty object
		Source sourceObject = new Source();

		// checked for empty
		boolean rc = sourceObject.isEmpty();

		// check return code
		assertEquals("Tested for empty.", true, rc);

		// not empty object
		Source sourceObject2 = new Source(AGENCYID, AUTHOR);

		// checked for empty
		rc = sourceObject2.isEmpty();

		// check return code
		assertEquals("Tested for not empty.", false, rc);		
	}

	/**
	 * Checks the data in the class
	 */
	public void CheckData(Source SourceObject, String TestName) {
		// check SourceObject.AgencyID
		if (SourceObject.getAgencyID() != null) {
			assertEquals(TestName + " AgencyID Equals", AGENCYID,
				SourceObject.getAgencyID());
		}

		// check SourceObject.Author
		if (SourceObject.getAuthor() != null) {
			assertEquals(TestName + " Author Equals", AUTHOR,
				SourceObject.getAuthor());
		}
	}
}
