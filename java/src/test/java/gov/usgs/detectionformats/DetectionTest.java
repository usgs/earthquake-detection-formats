package gov.usgs.detectionformats;

import java.util.ArrayList;
import java.util.Date;
import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class DetectionTest {

  public static String DETECTION_STRING =
      "{\"Gap\":33.67,\"Source\":{\"Author\":"
          + "\"TestAuthor\",\"AgencyID\":\"US\"},\"Data\":[{\"Source\":"
          + "{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},\"Filter\":"
          + "[{\"HighPass\":1.05,\"LowPass\":2.65}],\"Onset\":"
          + "\"questionable\",\"Amplitude\":{\"Period\":2.65,\"Amplitude\":"
          + "21.5,\"SNR\":3.8},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Site\":"
          + "{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\","
          + "\"Location\":\"01\"},\"Type\":"
          + "\"Pick\",\"ID\":\"12GFH48776857\",\"Polarity\":\"up\",\"Phase\":"
          + "\"P\",\"Picker\":\"manual\",\"AssociationInfo\":{\"Distance\":"
          + "0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,"
          + "\"Residual\":-0.025393}},{\"ZScore\":33.67,"
          + "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":"
          + "\"LB\",\"Location\":\"01\"},"
          + "\"Magnitude\":2.14,\"Type\":\"Correlation\",\"Correlation\":2.65,"
          + "\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},"
          + "\"AssociationInfo\":{\"Distance\":"
          + "0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,"
          + "\"Residual\":-0.025393},\"DetectionThreshold\":1.5,\"Source\":"
          + "{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},\"Time\":"
          + "\"2015-12-28T21:32:24.017Z\",\"Hypocenter\":{\"TimeError\":1.984,"
          + "\"Time\":\"2015-12-28T21:30:44.039Z\",\"LongitudeError\":22.64,"
          + "\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,"
          + "\"Longitude\":-121.44,\"Depth\":32.44},\"SNR\":3.8,\"ID\":"
          + "\"12GFH48776857\",\"ThresholdType\":\"minimum\",\"Phase\":\"P\"}],"
          + "\"Hypocenter\":{\"TimeError\":1.984,\"Time\":"
          + "\"2015-12-28T21:32:24.017Z\",\"LongitudeError\":22.64,"
          + "\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,"
          + "\"Longitude\":-121.44,\"Depth\":32.44},\"Type\":\"Detection\","
          + "\"RMS\":3.8,\"Bayes\":2.65,\"DetectionType\":\"New\","
          + "\"DetectionTime\":\"2015-12-28T21:32:28.017Z\",\"ID\":"
          + "\"12GFH48776857\",\"EventType\":{\"Type\":\"Earthquake\","
          + "\"Certainty\":\"Suspected\"},\"MinimumDistance\":2.14,"
          + "\"Detector\":\"Global\"}";
  public static String ID = "12GFH48776857";
  public static String AGENCYID = "US";
  public static String AUTHOR = "TestAuthor";
  public static double LATITUDE = 40.3344;
  public static double LONGITUDE = -121.44;
  public static Date TIME = Utility.getDate("2015-12-28T21:32:24.017Z");
  public static double DEPTH = 32.44;
  public static double LATITUDEERROR = 12.5;
  public static double LONGITUDEERROR = 22.64;
  public static double DEPTHERROR = 2.44;
  public static double TIMEERROR = 1.984;
  public static String DETECTIONTYPE = "New";
  public static Date DETECTIONTIME = Utility.getDate("2015-12-28T21:32:28.017Z");
  public static String EVENTTYPE = "Earthquake";
  public static String CERTAINTY = "Suspected";
  public static double BAYES = 2.65;
  public static double MINIMUMDISTANCE = 2.14;
  public static double RMS = 3.8;
  public static double GAP = 33.67;
  public static String DETECTOR = "Global";
  public static String PICKDATA =
      "{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\""
          + ",\"Site\":{\"Station\":\"BMN\","
          + "\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},"
          + "\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},"
          + "\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\","
          + "\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":"
          + "\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65}],"
          + "\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},"
          + "\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,"
          + "\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}";
  public static String CORRELATIONDATA =
      "{\"ZScore\":33.67,"
          + "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\","
          + "\"Network\":\"LB\",\"Location\":\"01\"},\"Magnitude\":2.14,"
          + "\"Type\":\"Correlation\",\"Correlation\":2.65,"
          + "\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},"
          + "\"AssociationInfo\":{\"Distance\":0.442559,\"Azimuth\":0.418479,"
          + "\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":-0.025393},"
          + "\"DetectionThreshold\":1.5,"
          + "\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},"
          + "\"Time\":\"2015-12-28T21:32:24.017Z\","
          + "\"Hypocenter\":{\"TimeError\":1.984,"
          + "\"Time\":\"2015-12-28T21:30:44.039Z\",\"LongitudeError\":22.64,"
          + "\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,"
          + "\"Longitude\":-121.44,\"Depth\":32.44},\"SNR\":3.8,"
          + "\"ID\":\"12GFH48776857\",\"ThresholdType\":\"minimum\","
          + "\"Phase\":\"P\"}";

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    Detection detectionObject =
        new Detection(
            ID,
            AGENCYID,
            AUTHOR,
            LATITUDE,
            LONGITUDE,
            TIME,
            DEPTH,
            LATITUDEERROR,
            LONGITUDEERROR,
            TIMEERROR,
            DEPTHERROR,
            DETECTIONTYPE,
            DETECTIONTIME,
            EVENTTYPE,
            CERTAINTY,
            BAYES,
            MINIMUMDISTANCE,
            RMS,
            GAP,
            DETECTOR,
            buildPickData(),
            buildCorrelationData());

    // write out to a string
    String jsonString = Utility.toJSONString(detectionObject.toJSON());

    // check the data
    try {
      CheckData(new Detection(Utility.fromJSONString(jsonString)), "WritesJSON");
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
      CheckData(new Detection(Utility.fromJSONString(DETECTION_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    Detection detectionObject =
        new Detection(
            ID,
            AGENCYID,
            AUTHOR,
            LATITUDE,
            LONGITUDE,
            TIME,
            DEPTH,
            LATITUDEERROR,
            LONGITUDEERROR,
            TIMEERROR,
            DEPTHERROR,
            DETECTIONTYPE,
            DETECTIONTIME,
            EVENTTYPE,
            CERTAINTY,
            BAYES,
            MINIMUMDISTANCE,
            RMS,
            GAP,
            DETECTOR,
            buildPickData(),
            buildCorrelationData());

    // check data values
    CheckData(detectionObject, "Constructor");

    // use constructor
    Detection altDetectionObject =
        new Detection(
            ID,
            new Source(AGENCYID, AUTHOR),
            new Hypocenter(
                LATITUDE,
                LONGITUDE,
                TIME,
                DEPTH,
                LATITUDEERROR,
                LONGITUDEERROR,
                TIMEERROR,
                DEPTHERROR),
            DETECTIONTYPE,
            DETECTIONTIME,
            new EventType(EVENTTYPE, CERTAINTY),
            BAYES,
            MINIMUMDISTANCE,
            RMS,
            GAP,
            DETECTOR,
            buildPickData(),
            buildCorrelationData());

    // check data values
    CheckData(altDetectionObject, "Alternate Constructor 1");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Detection emptyObject = new Detection(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    Detection detectionObject =
        new Detection(
            ID,
            AGENCYID,
            AUTHOR,
            LATITUDE,
            LONGITUDE,
            TIME,
            DEPTH,
            LATITUDEERROR,
            LONGITUDEERROR,
            TIMEERROR,
            DEPTHERROR,
            DETECTIONTYPE,
            DETECTIONTIME,
            EVENTTYPE,
            CERTAINTY,
            BAYES,
            MINIMUMDISTANCE,
            RMS,
            GAP,
            DETECTOR,
            buildPickData(),
            buildCorrelationData());

    // Successful validation
    boolean rc = detectionObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad Detection object
    Detection badDetectionObject = new Detection();

    rc = badDetectionObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation");

    // build bad Detection object
    Detection badDetectionObject2 =
        new Detection(
            "",
            "",
            null,
            -999.0,
            -999.0,
            null,
            -99999.0,
            null,
            null,
            null,
            null,
            "??",
            null,
            "chair",
            "fjord",
            -99.0,
            -1.0,
            null,
            -99.0,
            "",
            buildPickData(),
            buildCorrelationData());

    rc = badDetectionObject2.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 2");
  }

  public void CheckData(Detection detectionObject, String TestName) {
    // check detectionObject.ID
    if (detectionObject.getID() != null) {
      Assertions.assertEquals(ID, detectionObject.getID(), TestName + " ID Equals");
    }

    // check detectionObject.Source
    if (detectionObject.getSource() != null) {
      // check detectionObject.Source.AgencyID
      if (detectionObject.getSource().getAgencyID() != null) {
        Assertions.assertEquals(
            AGENCYID, detectionObject.getSource().getAgencyID(), TestName + " AgencyID Equals");
      }

      // check detectionObject.Source.Author
      if (detectionObject.getSource().getAuthor() != null) {
        Assertions.assertEquals(
            AUTHOR, detectionObject.getSource().getAuthor(), TestName + " Author Equals");
      }
    }

    // check detectionObject.Hypocenter
    if (detectionObject.getHypocenter() != null) {
      // check detectionObject.hypocenter.Latitude
      if (detectionObject.getHypocenter().getLatitude() != null) {
        Assertions.assertEquals(
            LATITUDE,
            detectionObject.getHypocenter().getLatitude(),
            0,
            TestName + " Latitude Equals");
      }

      // check detectionObject.hypocenter.Longitude
      if (detectionObject.getHypocenter().getLongitude() != null) {
        Assertions.assertEquals(
            LONGITUDE,
            detectionObject.getHypocenter().getLongitude(),
            0,
            TestName + " Longitude Equals");
      }

      // check detectionObject.hypocenter.Depth
      if (detectionObject.getHypocenter().getDepth() != null) {
        Assertions.assertEquals(
            DEPTH, detectionObject.getHypocenter().getDepth(), 0, TestName + " Depth Equals");
      }

      // check detectionObject.hypocenter.Time
      if (detectionObject.getHypocenter().getTime() != null) {
        Assertions.assertEquals(
            TIME, detectionObject.getHypocenter().getTime(), TestName + " OriginTime Equals");
      }

      // check detectionObject.hypocenter.LatitudeError
      if (detectionObject.getHypocenter().getLatitudeError() != null) {
        Assertions.assertEquals(
            LATITUDEERROR,
            detectionObject.getHypocenter().getLatitudeError(),
            0,
            TestName + " LatitudeError Equals");
      }

      // check detectionObject.hypocenter.LongitudeError
      if (detectionObject.getHypocenter().getLongitudeError() != null) {
        Assertions.assertEquals(
            LONGITUDEERROR,
            detectionObject.getHypocenter().getLongitudeError(),
            0,
            TestName + " LongitudError Equals");
      }

      // check detectionObject.hypocenter.DepthError
      if (detectionObject.getHypocenter().getDepthError() != null) {
        Assertions.assertEquals(
            DEPTHERROR,
            detectionObject.getHypocenter().getDepthError(),
            0,
            TestName + " DepthError Equals");
      }

      // check detectionObject.hypocenter.TimeError
      if (detectionObject.getHypocenter().getTimeError() != null) {
        Assertions.assertEquals(
            TIMEERROR,
            detectionObject.getHypocenter().getTimeError(),
            0,
            TestName + " TimeError Equals");
      }
    }

    // check detectionObject.DetectionType
    if (detectionObject.getDetectionType() != null) {
      Assertions.assertEquals(
          DETECTIONTYPE, detectionObject.getDetectionType(), TestName + " DetectionType Equals");
    }

    // check detectionObject.detectionTime
    if (detectionObject.getDetectionTime() != null) {
      Assertions.assertEquals(
          DETECTIONTIME, detectionObject.getDetectionTime(), TestName + " DetectionTime Equals");
    }

    // check detectionObject.eventType
    if ((detectionObject.getEventType() != null) && (!detectionObject.getEventType().isEmpty())) {
      // check detectionObject.EventType.type
      if (detectionObject.getEventType().getType() != null) {
        Assertions.assertEquals(
            EVENTTYPE, detectionObject.getEventType().getType(), TestName + " Type Equals");
      }

      // check detectionObject.EventType.certainty
      if (detectionObject.getEventType().getCertainty() != null) {
        Assertions.assertEquals(
            CERTAINTY,
            detectionObject.getEventType().getCertainty(),
            TestName + " Certantity Equals");
      }
    }

    // check detectionObject.Bayes
    if (detectionObject.getBayes() != null) {
      Assertions.assertEquals(BAYES, detectionObject.getBayes(), 0, TestName + " Bayes Equals");
    }

    // check detectionObject.MinimumDistance
    if (detectionObject.getMinimumDistance() != null) {
      Assertions.assertEquals(
          MINIMUMDISTANCE,
          detectionObject.getMinimumDistance(),
          0,
          TestName + " MinimumDistance Equals");
    }

    // check detectionObject.RMS
    if (detectionObject.getRMS() != null) {
      Assertions.assertEquals(RMS, detectionObject.getRMS(), 0, TestName + " RMS Equals");
    }

    // check detectionObject.Gap
    if (detectionObject.getGap() != null) {
      Assertions.assertEquals(GAP, detectionObject.getGap(), 0, TestName + " Gap Equals");
    }

    // check detectionObject.detector
    if (detectionObject.getDetector() != null) {
      Assertions.assertEquals(
          DETECTOR, detectionObject.getDetector(), TestName + " detector Equals");
    }

    // should check data still!!!!!!
    // somehow?
  }

  public ArrayList<Pick> buildPickData() {
    ArrayList<Pick> newPickData = new ArrayList<Pick>();

    // Pick ?need one more?
    try {
      newPickData.add(new Pick(Utility.fromJSONString(PICKDATA)));
    } catch (ParseException e) {
      e.printStackTrace();
    }
    return (newPickData);
  }

  public ArrayList<Correlation> buildCorrelationData() {
    ArrayList<Correlation> newCorrelationData = new ArrayList<Correlation>();

    // Correlation ?need one more?
    try {
      newCorrelationData.add(new Correlation(Utility.fromJSONString(CORRELATIONDATA)));
    } catch (ParseException e) {
      e.printStackTrace();
    }
    return (newCorrelationData);
  }
}
