package gov.usgs.detectionformats;

import java.util.Date;
import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class HypocenterTest {
  public static final String HYPO_STRING =
      "{\"TimeError\":1.984,"
          + "\"Time\":\"2015-12-28T21:32:24.017Z\",\"LongitudeError\":22.64,"
          + "\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,"
          + "\"Longitude\":-121.44,\"Depth\":32.44}";

  public static double LATITUDE = 40.3344;
  public static double LONGITUDE = -121.44;
  public static Date TIME = Utility.getDate("2015-12-28T21:32:24.017Z");
  public static double DEPTH = 32.44;
  public static double LATITUDEERROR = 12.5;
  public static double LONGITUDEERROR = 22.64;
  public static double DEPTHERROR = 2.44;
  public static double TIMEERROR = 1.984;

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    Hypocenter hypoObject =
        new Hypocenter(
            LATITUDE, LONGITUDE, TIME, DEPTH, LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

    // write out to a string
    String jsonString = Utility.toJSONString(hypoObject.toJSON());

    // check the data
    try {
      CheckData(new Hypocenter(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {
    // build Correlation object
    try {
      CheckData(new Hypocenter(Utility.fromJSONString(HYPO_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    Hypocenter hypoObject =
        new Hypocenter(
            LATITUDE, LONGITUDE, TIME, DEPTH, LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

    // check data values
    CheckData(hypoObject, "Constructor");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Hypocenter emptyObject = new Hypocenter(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    Hypocenter hypoObject =
        new Hypocenter(
            LATITUDE, LONGITUDE, TIME, DEPTH, LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

    // Successful validation
    boolean rc = hypoObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad source object
    Hypocenter badHypoObject = new Hypocenter();

    rc = badHypoObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 1");

    // build bad Hypo object
    Hypocenter badHypoObject2 =
        new Hypocenter(-9999.0, 9999.0, null, 2000.0, null, null, null, null);

    rc = badHypoObject2.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 2");
  }

  public void CheckData(Hypocenter hypoObject, String TestName) {
    // check hypoObject.Latitude
    if (hypoObject.getLatitude() != null) {
      Assertions.assertEquals(LATITUDE, hypoObject.getLatitude(), 0, TestName + " Latitude Equals");
    }

    // check hypoObject.Longitude
    if (hypoObject.getLongitude() != null) {
      Assertions.assertEquals(
          LONGITUDE, hypoObject.getLongitude(), 0, TestName + " Longitude Equals");
    }

    // check hypoObject.Depth
    if (hypoObject.getDepth() != null) {
      Assertions.assertEquals(DEPTH, hypoObject.getDepth(), 0, TestName + " Depth Equals");
    }

    // check hypoObject.Time
    if (hypoObject.getTime() != null) {
      Assertions.assertEquals(TIME, hypoObject.getTime(), TestName + " Time Equals");
    }

    // check hypoObject.LatitudeError
    if (hypoObject.getLatitudeError() != null) {
      Assertions.assertEquals(
          LATITUDEERROR, hypoObject.getLatitudeError(), 0, TestName + " LatitudeError Equals");
    }

    // check hypoObject.LongitudeError
    if (hypoObject.getLongitudeError() != null) {
      Assertions.assertEquals(
          LONGITUDEERROR, hypoObject.getLongitudeError(), 0, TestName + " LongitudError Equals");
    }

    // check hypoObject.DepthError
    if (hypoObject.getDepthError() != null) {
      Assertions.assertEquals(
          DEPTHERROR, hypoObject.getDepthError(), 0, TestName + " DepthError Equals");
    }

    // check hypoObject.TimeError
    if (hypoObject.getTimeError() != null) {
      Assertions.assertEquals(
          TIMEERROR, hypoObject.getTimeError(), 0, TestName + " TimeError Equals");
    }
  }
}
