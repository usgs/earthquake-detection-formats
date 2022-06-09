package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class FilterTest {
  public static final String FILTER_STRING =
      "{\"Type\":\"BandPass\","
          + "\"HighPass\":1.05,"
          + "\"LowPass\":2.65,"
          + "\"Units\":\"Hertz\"}";
  public static final String TYPE = "BandPass";
  public static final double HIGHPASS = 1.05;
  public static final double LOWPASS = 2.65;
  public static final String UNITS = "Hertz";

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    Filter filterObject = new Filter(TYPE, HIGHPASS, LOWPASS, UNITS);

    // write out to a string
    String jsonString = Utility.toJSONString(filterObject.toJSON());

    // check the data
    try {
      CheckData(new Filter(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {
    // build Filter object
    try {
      CheckData(new Filter(Utility.fromJSONString(FILTER_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor tests */
  @Test
  public void Constructor() {
    Filter filterObject = new Filter(TYPE, HIGHPASS, LOWPASS, UNITS);

    // check the data
    CheckData(filterObject, "Constructor");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Filter emptyObject = new Filter(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    Filter filterObject = new Filter(TYPE, HIGHPASS, LOWPASS, UNITS);

    // Successful validation
    boolean rc = filterObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // Can't think of a way to make an invalid filter object
  }

  /** Empty check function */
  @Test
  public void IsEmpty() {
    // empty object
    Filter filterObject = new Filter();

    // checked for empty
    boolean rc = filterObject.isEmpty();

    // check return code
    Assertions.assertEquals(true, rc, "Tested for empty.");

    // not empty object
    Filter filterObject2 = new Filter(TYPE, HIGHPASS, LOWPASS, UNITS);

    // checked for empty
    rc = filterObject2.isEmpty();

    // check return code
    Assertions.assertEquals(false, rc, "Tested for not empty.");
  }

  public void CheckData(Filter FilterObject, String TestName) {
    // check FilterObject.type
    if (FilterObject.getType() != null) {
      Assertions.assertEquals(TYPE, FilterObject.getType(), TestName + " Type Equals");
    }

    // check FilterObject.highPass
    if (FilterObject.getHighPass() != null) {
      Assertions.assertEquals(
          HIGHPASS, FilterObject.getHighPass(), 0, TestName + " HighPass Equals");
    }

    // check FilterObject.lowPass
    if (FilterObject.getLowPass() != null) {
      Assertions.assertEquals(LOWPASS, FilterObject.getLowPass(), 0, TestName + " LowPass Equals");
    }

    // check FilterObject.units
    if (FilterObject.getUnits() != null) {
      Assertions.assertEquals(UNITS, FilterObject.getUnits(), TestName + " Units Equals");
    }
  }
}
