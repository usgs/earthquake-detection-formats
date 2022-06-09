package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class BeamTest {

  public static String BEAM_STRING =
      "{\"Source\":{\"Author\":\"TestAuthor\","
          + "\"AgencyID\":\"US\"},\"StartTime\":\"2015-12-28T21:32:24.017Z\","
          + "\"EndTime\":\"2015-12-28T21:32:30.017Z\","
          + "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":"
          + "\"LB\",\"Location\":\"01\",\"SiteID\":\"BMN.HHZ.LB.01\"},"
          + "\"Type\":\"Beam\",\"BackAzimuth\":2.65,\"ID\":\"12GFH48776857\","
          + "\"BackAzimuthError\":3.8,\"Slowness\":1.44,\"AssociationInfo\":"
          + "{\"Distance\":0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\","
          + "\"Sigma\":0.086333,\"Residual\":-0.025393},\"SlownessError\":0.4"
          + "\"PowerRatio\":12.18,\"PowerRatioError\":0.557}";

  public static double BACKAZIMUTH = 2.65;
  public static double BACKAZIMUTHERROR = 3.8;
  public static double SLOWNESS = 1.44;
  public static double SLOWNESSERROR = 0.4;
  public static double POWERRATIO = 12.18;
  public static double POWERRATIOERROR = 0.557;

  /** Able to write a JSON string */
  @Test
  public void writesJSON() {
    Beam beamObject =
        new Beam(
            BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

    // write out to a string
    String jsonString = Utility.toJSONString(beamObject.toJSON());

    // check the data
    try {
      CheckData(new Beam(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void readsJSON() {
    // build Beam object
    try {

      CheckData(new Beam(Utility.fromJSONString(BEAM_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    Beam beamObject =
        new Beam(
            BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

    // check data values
    CheckData(beamObject, "Constructor");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Beam emptyObject = new Beam(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    Beam beamObject =
        new Beam(
            BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

    // Successful validation
    boolean rc = beamObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad Beam object
    Beam badBeamObject = new Beam();

    rc = badBeamObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation");

    // build bad Beam object
    Beam badBeamObject2 = new Beam(-99.0, -99.0, -99.0, -99.0, -99.0, -99.0);

    rc = badBeamObject2.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation");
  }

  /** Empty check function */
  @Test
  public void IsEmpty() {
    // empty object
    Beam beamObject = new Beam();

    // checked for empty
    boolean rc = beamObject.isEmpty();

    // check return code
    Assertions.assertEquals(true, rc, "Tested for empty.");

    // not empty object
    Beam beamObject2 =
        new Beam(
            BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

    // checked for empty
    rc = beamObject2.isEmpty();

    // check return code
    Assertions.assertEquals(false, rc, "Tested for not empty.");
  }

  public void CheckData(Beam beamObject, String TestName) {
    // check beamObject.BackAzimuth
    if (beamObject.getBackAzimuth() != null) {
      Assertions.assertEquals(
          BACKAZIMUTH, beamObject.getBackAzimuth(), 0, TestName + " BackAzimuth Equals");
    }

    // check beamObject.BackAzimuthError
    if (beamObject.getBackAzimuthError() != null) {
      Assertions.assertEquals(
          BACKAZIMUTHERROR,
          beamObject.getBackAzimuthError(),
          0,
          TestName + " BackAzimuthError Equals");
    }

    // check beamObject.Slowness
    if (beamObject.getSlowness() != null) {
      Assertions.assertEquals(SLOWNESS, beamObject.getSlowness(), 0, TestName + " Slowness Equals");
    }

    // check beamObject.SlownessError
    if (beamObject.getSlownessError() != null) {
      Assertions.assertEquals(
          SLOWNESSERROR, beamObject.getSlownessError(), 0, TestName + " SlownessError Equals");
    }

    // check beamObject.PowerRatio
    if (beamObject.getPowerRatio() != null) {
      Assertions.assertEquals(
          POWERRATIO, beamObject.getPowerRatio(), 0, TestName + " PowerRatio Equals");
    }

    // check beamObject.PowerRatioError
    if (beamObject.getPowerRatioError() != null) {
      Assertions.assertEquals(
          POWERRATIOERROR,
          beamObject.getPowerRatioError(),
          0,
          TestName + " PowerRatioError Equals");
    }
  }
}
