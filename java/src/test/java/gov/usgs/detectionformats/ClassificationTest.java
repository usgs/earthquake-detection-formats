package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ClassificationTest {

  public static final String CLASSIFICATION_STRING =
      "{\"Phase\":\"P\","
          + "\"PhaseProbability\":0.22,\"Distance\":0.442559,"
          + "\"DistanceProbability\":22.5,\"Backazimuth\":0.418479,"
          + "\"BackazimuthProbability\":0.16,\"Magnitude\":2.14,"
          + "\"MagnitudeType\":\"Mb\",\"MagnitudeProbability\":0.55,"
          + "\"Depth\":32.44,\"DepthProbability\":11.2,"
          + "\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},"
          + "\"EventTypeProbability\":1.1,\"Source\":{\"AgencyID\":\"US\","
          + "\"Author\":\"TestAuthor\"}}";

  public static final String PHASE = "P";
  public static final double PHASEPROBABILITY = 0.22;
  public static final double DISTANCE = 0.442559;
  public static final double DISTANCEPROBABILITY = 22.5;
  public static final double BACKAZIMUTH = 0.418479;
  public static final double BACKAZIMUTHPROBABILITY = 0.16;
  public static final double MAGNITUDE = 2.14;
  public static final String MAGNITUDETYPE = "Mb";
  public static final double MAGNITUDEPROBABILITY = 0.55;
  public static final double DEPTH = 32.44;
  public static final double DEPTHPROBABILITY = 11.2;
  public static final String EVENTTYPE = "Earthquake";
  public static final String CERTAINTY = "Suspected";
  public static final double EVENTTYPEPROBABILITY = 1.1;
  public static final String AGENCYID = "US";
  public static final String AUTHOR = "TestAuthor";

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    Classification classificationObject =
        new Classification(
            PHASE,
            PHASEPROBABILITY,
            DISTANCE,
            DISTANCEPROBABILITY,
            BACKAZIMUTH,
            BACKAZIMUTHPROBABILITY,
            MAGNITUDE,
            MAGNITUDETYPE,
            MAGNITUDEPROBABILITY,
            DEPTH,
            DEPTHPROBABILITY,
            EVENTTYPE,
            CERTAINTY,
            EVENTTYPEPROBABILITY,
            AGENCYID,
            AUTHOR);

    // write out to a string
    String jsonString = Utility.toJSONString(classificationObject.toJSON());

    // check the data
    try {
      CheckData(new Classification(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {
    // build Classification object
    try {
      CheckData(new Classification(Utility.fromJSONString(CLASSIFICATION_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    Classification classificationObject =
        new Classification(
            PHASE,
            PHASEPROBABILITY,
            DISTANCE,
            DISTANCEPROBABILITY,
            BACKAZIMUTH,
            BACKAZIMUTHPROBABILITY,
            MAGNITUDE,
            MAGNITUDETYPE,
            MAGNITUDEPROBABILITY,
            DEPTH,
            DEPTHPROBABILITY,
            EVENTTYPE,
            CERTAINTY,
            EVENTTYPEPROBABILITY,
            AGENCYID,
            AUTHOR);

    // check data values
    CheckData(classificationObject, "Constructor");

    Classification classificationObject2 =
        new Classification(
            PHASE,
            PHASEPROBABILITY,
            DISTANCE,
            DISTANCEPROBABILITY,
            BACKAZIMUTH,
            BACKAZIMUTHPROBABILITY,
            MAGNITUDE,
            MAGNITUDETYPE,
            MAGNITUDEPROBABILITY,
            DEPTH,
            DEPTHPROBABILITY,
            new EventType(EVENTTYPE, CERTAINTY),
            EVENTTYPEPROBABILITY,
            new Source(AGENCYID, AUTHOR));

    // check data values
    CheckData(classificationObject2, "Alternate Constructor");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Classification emptyObject = new Classification(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void validate() {
    Classification classificationObject =
        new Classification(
            PHASE,
            PHASEPROBABILITY,
            DISTANCE,
            DISTANCEPROBABILITY,
            BACKAZIMUTH,
            BACKAZIMUTHPROBABILITY,
            MAGNITUDE,
            MAGNITUDETYPE,
            MAGNITUDEPROBABILITY,
            DEPTH,
            DEPTHPROBABILITY,
            EVENTTYPE,
            CERTAINTY,
            EVENTTYPEPROBABILITY,
            AGENCYID,
            AUTHOR);

    // Successful validation
    boolean rc = classificationObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad Classification object
    Classification badClassificationObject =
        new Classification(
            "22", null, -99.0, null, -99.0, null, -99.0, null, null, -9999.0, null, "chair", "bleh",
            null, "", "");

    rc = badClassificationObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation");
  }

  /** Empty check function */
  @Test
  public void IsEmpty() {
    // empty object
    Classification classificationObject = new Classification();

    // checked for empty
    boolean rc = classificationObject.isEmpty();

    // check return code
    Assertions.assertEquals(true, rc, "Tested for empty.");

    // not empty object
    Classification classificationObject2 =
        new Classification(
            PHASE,
            PHASEPROBABILITY,
            DISTANCE,
            DISTANCEPROBABILITY,
            BACKAZIMUTH,
            BACKAZIMUTHPROBABILITY,
            MAGNITUDE,
            MAGNITUDETYPE,
            MAGNITUDEPROBABILITY,
            DEPTH,
            DEPTHPROBABILITY,
            EVENTTYPE,
            CERTAINTY,
            EVENTTYPEPROBABILITY,
            AGENCYID,
            AUTHOR);

    // checked for empty
    rc = classificationObject2.isEmpty();

    // check return code
    Assertions.assertEquals(false, rc, "Tested for not empty.");
  }

  /** Checks the data in the class */
  public void CheckData(Classification ClassificationObject, String TestName) {
    // check ClassificationObject.phase
    if (ClassificationObject.getPhase() != null) {
      Assertions.assertEquals(PHASE, ClassificationObject.getPhase(), TestName + " Phase Equals");
    }

    // check ClassificationObject.phaseProbability
    if (ClassificationObject.getPhaseProbability() != null) {
      Assertions.assertEquals(
          PHASEPROBABILITY,
          ClassificationObject.getPhaseProbability(),
          0,
          TestName + " Phase Probability Equals");
    }

    // check ClassificationObject.distance
    if (ClassificationObject.getDistance() != null) {
      Assertions.assertEquals(
          DISTANCE, ClassificationObject.getDistance(), 0, TestName + " Distance Equals");
    }

    // check ClassificationObject.distanceProbability
    if (ClassificationObject.getDistanceProbability() != null) {
      Assertions.assertEquals(
          DISTANCEPROBABILITY,
          ClassificationObject.getDistanceProbability(),
          0,
          TestName + " Distance Probability Equals");
    }

    // check ClassificationObject.Backazimuth
    if (ClassificationObject.getBackazimuth() != null) {
      Assertions.assertEquals(
          BACKAZIMUTH, ClassificationObject.getBackazimuth(), 0, TestName + " Backazimuth Equals");
    }

    // check ClassificationObject.backazimuthProbability
    if (ClassificationObject.getBackazimuthProbability() != null) {
      Assertions.assertEquals(
          BACKAZIMUTHPROBABILITY,
          ClassificationObject.getBackazimuthProbability(),
          0,
          TestName + " Backazimuth Probability Equals");
    }

    // check ClassificationObject.magnitude
    if (ClassificationObject.getMagnitude() != null) {
      Assertions.assertEquals(
          MAGNITUDE, ClassificationObject.getMagnitude(), 0, TestName + " Magnitude Equals");
    }

    // check ClassificationObject.magnitudeType
    if (ClassificationObject.getMagnitudeType() != null) {
      Assertions.assertEquals(
          MAGNITUDETYPE,
          ClassificationObject.getMagnitudeType(),
          TestName + " Magnitude Type Equals");
    }

    // check ClassificationObject.magnitudeProbability
    if (ClassificationObject.getMagnitudeProbability() != null) {
      Assertions.assertEquals(
          MAGNITUDEPROBABILITY,
          ClassificationObject.getMagnitudeProbability(),
          0,
          TestName + " Magnitude Probability Equals");
    }

    // check ClassificationObject.depth
    if (ClassificationObject.getDepth() != null) {
      Assertions.assertEquals(
          DEPTH, ClassificationObject.getDepth(), 0, TestName + " Depth Equals");
    }

    // check ClassificationObject.depthProbability
    if (ClassificationObject.getDepthProbability() != null) {
      Assertions.assertEquals(
          DEPTHPROBABILITY,
          ClassificationObject.getDepthProbability(),
          0,
          TestName + " Depth Probability Equals");
    }

    // check ClassificationObject.eventType
    if (ClassificationObject.getEventType() != null) {
      // check ClassificationObject.EventType.type
      if (ClassificationObject.getEventType().getType() != null) {
        Assertions.assertEquals(
            EVENTTYPE, ClassificationObject.getEventType().getType(), TestName + " Type Equals");
      }

      // check ClassificationObject.EventType.certainty
      if (ClassificationObject.getEventType().getCertainty() != null) {
        Assertions.assertEquals(
            CERTAINTY,
            ClassificationObject.getEventType().getCertainty(),
            TestName + " Certantity Equals");
      }
    }

    // check ClassificationObject.eventTypeProbability
    if (ClassificationObject.getEventTypeProbability() != null) {
      Assertions.assertEquals(
          EVENTTYPEPROBABILITY,
          ClassificationObject.getEventTypeProbability(),
          0,
          TestName + " Event Type Probability Equals");
    }

    // check ClassificationObject.source
    if (ClassificationObject.getSource() != null) {
      // check ClassificationObject.Source.AgencyID
      if (ClassificationObject.getSource().getAgencyID() != null) {
        Assertions.assertEquals(
            AGENCYID,
            ClassificationObject.getSource().getAgencyID(),
            TestName + " AgencyID Equals");
      }

      // check ClassificationObject.Source.Author
      if (ClassificationObject.getSource().getAuthor() != null) {
        Assertions.assertEquals(
            AUTHOR, ClassificationObject.getSource().getAuthor(), TestName + " Author Equals");
      }
    }
  }
}
