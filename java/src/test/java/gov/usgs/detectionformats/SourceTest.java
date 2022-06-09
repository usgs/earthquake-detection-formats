package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SourceTest {
  public static final String SOURCE_STRING = "{\"Author\":" + "\"TestAuthor\",\"AgencyID\":\"US\"}";
  public static final String AGENCYID = "US";
  public static final String AUTHOR = "TestAuthor";

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    Source sourceObject = new Source(AGENCYID, AUTHOR);

    // write out to a string
    String jsonString = Utility.toJSONString(sourceObject.toJSON());

    // check the data
    try {
      CheckData(new Source(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {
    try {
      CheckData(new Source(Utility.fromJSONString(SOURCE_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
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

  /** Able to run validation function */
  @Test
  public void Validate() {
    // build source object
    Source sourceObject = new Source(AGENCYID, AUTHOR);

    // Successful validation
    boolean rc = sourceObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad source object
    Source badSourceObject = new Source();

    rc = badSourceObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation");

    // build bad source object
    Source badSourceObject2 = new Source("", "");

    rc = badSourceObject2.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 2");
  }

  /** Empty check function */
  @Test
  public void IsEmpty() {
    // empty object
    Source sourceObject = new Source();

    // checked for empty
    boolean rc = sourceObject.isEmpty();

    // check return code
    Assertions.assertEquals(true, rc, "Tested for empty.");

    // not empty object
    Source sourceObject2 = new Source(AGENCYID, AUTHOR);

    // checked for empty
    rc = sourceObject2.isEmpty();

    // check return code
    Assertions.assertEquals(false, rc, "Tested for not empty.");
  }

  /** Checks the data in the class */
  public void CheckData(Source SourceObject, String TestName) {
    // check SourceObject.AgencyID
    if (SourceObject.getAgencyID() != null) {
      Assertions.assertEquals(AGENCYID, SourceObject.getAgencyID(), TestName + " AgencyID Equals");
    }

    // check SourceObject.Author
    if (SourceObject.getAuthor() != null) {
      Assertions.assertEquals(AUTHOR, SourceObject.getAuthor(), TestName + " Author Equals");
    }
  }
}
