package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AssociationTest {

  public static final String ASSOCIATED_STRING =
      "{\"Distance\":0.442559,"
          + "\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,"
          + "\"Residual\":-0.025393}";
  public static final String PHASE = "P";
  public static final double DISTANCE = 0.442559;
  public static final double AZIMUTH = 0.418479;
  public static final double RESIDUAL = -0.025393;
  public static final double SIGMA = 0.086333;

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    Association associationObject = new Association(PHASE, DISTANCE, AZIMUTH, RESIDUAL, SIGMA);

    // write out to a string
    String jsonString = Utility.toJSONString(associationObject.toJSON());

    // check the data
    try {
      CheckData(new Association(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {
    // build Association object
    try {
      CheckData(new Association(Utility.fromJSONString(ASSOCIATED_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    Association associationObject = new Association(PHASE, DISTANCE, AZIMUTH, RESIDUAL, SIGMA);

    // check data values
    CheckData(associationObject, "Constructor");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Association emptyObject = new Association(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void validate() {
    Association associationObject = new Association(PHASE, DISTANCE, AZIMUTH, RESIDUAL, SIGMA);

    // Successful validation
    boolean rc = associationObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad Association object
    Association badAssociationObject = new Association("22", -99.0, -99.0, null, null);

    rc = badAssociationObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation");
  }

  /** Empty check function */
  @Test
  public void IsEmpty() {
    // empty object
    Association associationObject = new Association();

    // checked for empty
    boolean rc = associationObject.isEmpty();

    // check return code
    Assertions.assertEquals(true, rc, "Tested for empty.");

    // not empty object
    Association associationObject2 = new Association(PHASE, DISTANCE, AZIMUTH, RESIDUAL, SIGMA);

    // checked for empty
    rc = associationObject2.isEmpty();

    // check return code
    Assertions.assertEquals(false, rc, "Tested for not empty.");
  }

  /** Checks the data in the class */
  public void CheckData(Association AssociationObject, String TestName) {

    // check AssociationObject.Phase
    if (AssociationObject.getPhase() != null) {
      Assertions.assertEquals(PHASE, AssociationObject.getPhase(), TestName + " Phase Equals");
    }

    // check AssociationObject.Distance
    if (AssociationObject.getDistance() != null) {
      Assertions.assertEquals(
          DISTANCE, AssociationObject.getDistance(), 0, TestName + " Distance Equals");
    }

    // check AssociationObject.Azimuth
    if (AssociationObject.getAzimuth() != null) {
      Assertions.assertEquals(
          AZIMUTH, AssociationObject.getAzimuth(), 0, TestName + " Azimuth Equals");
    }

    // check AssociationObject.Residual
    if (AssociationObject.getResidual() != null) {
      Assertions.assertEquals(
          RESIDUAL, AssociationObject.getResidual(), 0, TestName + " Residual Equals");
    }

    // check AssociationObject.Sigma
    if (AssociationObject.getSigma() != null) {
      Assertions.assertEquals(SIGMA, AssociationObject.getSigma(), 0, TestName + " Sigma Equals");
    }
  }
}
