package gov.usgs.detectionformats;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class PickTest {
  public static String PICK_STRING =
      "{\"Source\":{\"Author\":\"TestAuthor\","
          + "\"AgencyID\":\"US\"},\"Filter\":[{\"Type\":\"BandPass\",\"HighPass\":1.05,\"LowPass\":"
          + "2.65,\"Units\":\"Hertz\"}],\"Onset\":\"questionable\",\"Amplitude\":{\"Period\":2.65,"
          + "\"Amplitude\":21.5,\"SNR\":3.8},\"Time\":\"2015-12-28T21:32:24.017Z\","
          + "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\","
          + "\"Location\":\"01\"},\"Type\":\"Pick\",\"Beam\":{\"BackAzimuth\":2.65,"
          + "\"BackAzimuthError\":3.8,\"Slowness\":1.44,\"SlownessError\":0.4,"
          + "\"PowerRatio\":12.18,\"PowerRatioError\":0.557},"
          + "\"ID\":\"12GFH48776857\",\"Polarity\":\"up\",\"Phase\":\"P\","
          + "\"Picker\":\"manual\",\"AssociationInfo\":{\"Distance\":0.442559,"
          + "\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":"
          + "-0.025393},\"ClassificationInfo\":{\"Phase\":\"P\","
          + "\"PhaseProbability\":0.22,\"Distance\":0.442559,"
          + "\"DistanceProbability\":22.5,\"BackAzimuth\":0.418479,"
          + "\"BackAzimuthProbability\":0.16,\"Magnitude\":2.14,"
          + "\"MagnitudeType\":\"Mb\",\"MagnitudeProbability\":0.55,"
          + "\"Depth\":32.44,\"DepthProbability\":11.2,"
          + "\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},"
          + "\"EventTypeProbability\":1.1,\"Source\":{\"AgencyID\":\"US\","
          + "\"Author\":\"TestAuthor\"}}}";
  public static String ID = "12GFH48776857";
  public static String STATION = "BMN";
  public static String CHANNEL = "HHZ";
  public static String NETWORK = "LB";
  public static String LOCATION = "01";
  public static String AGENCYID = "US";
  public static String AUTHOR = "TestAuthor";
  public static Date TIME = Utility.getDate("2015-12-28T21:32:24.017Z");
  public static String PHASE = "P";
  public static String POLARITY = "up";
  public static String ONSET = "questionable";
  public static String PICKER = "manual";
  public static String TYPE = "BandPass";
  public static double HIGHPASS = 1.05;
  public static double LOWPASS = 2.65;
  public static String UNITS = "Hertz";
  public static double AMPLITUDE = 21.5;
  public static double PERIOD = 2.65;
  public static double SNR = 3.8;
  public static double BACKAZIMUTH = 2.65;
  public static double BACKAZIMUTHERROR = 3.8;
  public static double SLOWNESS = 1.44;
  public static double SLOWNESSERROR = 0.4;
  public static double POWERRATIO = 12.18;
  public static double POWERRATIOERROR = 0.557;
  public static String ASSOCPHASE = "P";
  public static double ASSOCDISTANCE = 0.442559;
  public static double ASSOCAZIMUTH = 0.418479;
  public static double ASSOCRESIDUAL = -0.025393;
  public static double ASSOCSIGMA = 0.086333;
  public static String CLASSPHASE = "P";
  public static double CLASSPHASEPROBABILITY = 0.22;
  public static double CLASSDISTANCE = 0.442559;
  public static double CLASSDISTANCEPROBABILITY = 22.5;
  public static double CLASSBACKAZIMUTH = 0.418479;
  public static double CLASSBACKAZIMUTHPROBABILITY = 0.16;
  public static double CLASSMAGNITUDE = 2.14;
  public static String CLASSMAGNITUDETYPE = "Mb";
  public static double CLASSMAGNITUDEPROBABILITY = 0.55;
  public static double CLASSDEPTH = 32.44;
  public static double CLASSDEPTHPROBABILITY = 11.2;
  public static String CLASSEVENTTYPE = "Earthquake";
  public static String CLASSCERTAINTY = "Suspected";
  public static double CLASSEVENTTYPEPROBABILITY = 1.1;
  public static String CLASSAGENCYID = "US";
  public static String CLASSAUTHOR = "TestAuthor";

  /** Able to write a JSON string */
  @Test
  public void writesJSON() {
    Pick pickObject =
        new Pick(
            ID,
            STATION,
            CHANNEL,
            NETWORK,
            LOCATION,
            TIME,
            AGENCYID,
            AUTHOR,
            PHASE,
            POLARITY,
            ONSET,
            PICKER,
            TYPE,
            HIGHPASS,
            LOWPASS,
            UNITS,
            AMPLITUDE,
            PERIOD,
            SNR,
            BACKAZIMUTH,
            BACKAZIMUTHERROR,
            SLOWNESS,
            SLOWNESSERROR,
            POWERRATIO,
            POWERRATIOERROR,
            ASSOCPHASE,
            ASSOCDISTANCE,
            ASSOCAZIMUTH,
            ASSOCRESIDUAL,
            ASSOCSIGMA,
            CLASSPHASE,
            CLASSPHASEPROBABILITY,
            CLASSDISTANCE,
            CLASSDISTANCEPROBABILITY,
            CLASSBACKAZIMUTH,
            CLASSBACKAZIMUTHPROBABILITY,
            CLASSMAGNITUDE,
            CLASSMAGNITUDETYPE,
            CLASSMAGNITUDEPROBABILITY,
            CLASSDEPTH,
            CLASSDEPTHPROBABILITY,
            CLASSEVENTTYPE,
            CLASSCERTAINTY,
            CLASSEVENTTYPEPROBABILITY,
            CLASSAGENCYID,
            CLASSAUTHOR);

    // write out to a string
    String jsonString = Utility.toJSONString(pickObject.toJSON());

    // check the data
    try {
      CheckData(new Pick(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {
    // build Pick object
    try {
      CheckData(new Pick(Utility.fromJSONString(PICK_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    Pick pickObject =
        new Pick(
            ID,
            STATION,
            CHANNEL,
            NETWORK,
            LOCATION,
            TIME,
            AGENCYID,
            AUTHOR,
            PHASE,
            POLARITY,
            ONSET,
            PICKER,
            TYPE,
            HIGHPASS,
            LOWPASS,
            UNITS,
            AMPLITUDE,
            PERIOD,
            SNR,
            BACKAZIMUTH,
            BACKAZIMUTHERROR,
            SLOWNESS,
            SLOWNESSERROR,
            POWERRATIO,
            POWERRATIOERROR,
            ASSOCPHASE,
            ASSOCDISTANCE,
            ASSOCAZIMUTH,
            ASSOCRESIDUAL,
            ASSOCSIGMA,
            CLASSPHASE,
            CLASSPHASEPROBABILITY,
            CLASSDISTANCE,
            CLASSDISTANCEPROBABILITY,
            CLASSBACKAZIMUTH,
            CLASSBACKAZIMUTHPROBABILITY,
            CLASSMAGNITUDE,
            CLASSMAGNITUDETYPE,
            CLASSMAGNITUDEPROBABILITY,
            CLASSDEPTH,
            CLASSDEPTHPROBABILITY,
            CLASSEVENTTYPE,
            CLASSCERTAINTY,
            CLASSEVENTTYPEPROBABILITY,
            CLASSAGENCYID,
            CLASSAUTHOR);

    // check data values
    CheckData(pickObject, "Constructor");

    // use constructor
    Pick altPickObject =
        new Pick(
            ID,
            STATION,
            CHANNEL,
            NETWORK,
            LOCATION,
            TIME,
            AGENCYID,
            AUTHOR,
            PHASE,
            POLARITY,
            ONSET,
            PICKER,
            TYPE,
            HIGHPASS,
            LOWPASS,
            UNITS,
            AMPLITUDE,
            PERIOD,
            SNR,
            BACKAZIMUTH,
            BACKAZIMUTHERROR,
            SLOWNESS,
            SLOWNESSERROR,
            POWERRATIO,
            POWERRATIOERROR);

    // check data values
    CheckData(altPickObject, "Alternate Constructor 1");

    // use constructor
    Pick altAltPickObject =
        new Pick(
            ID,
            new Site(STATION, CHANNEL, NETWORK, LOCATION),
            TIME,
            new Source(AGENCYID, AUTHOR),
            PHASE,
            POLARITY,
            ONSET,
            PICKER,
            new ArrayList<Filter>(Arrays.asList(new Filter(TYPE, HIGHPASS, LOWPASS, UNITS))),
            new Amplitude(AMPLITUDE, PERIOD, SNR),
            new Beam(
                BACKAZIMUTH,
                BACKAZIMUTHERROR,
                SLOWNESS,
                SLOWNESSERROR,
                POWERRATIO,
                POWERRATIOERROR));

    // check data values
    CheckData(altAltPickObject, "Alternate Constructor 2");

    // use constructor
    Pick altAltAltPickObject =
        new Pick(
            ID,
            new Site(STATION, CHANNEL, NETWORK, LOCATION),
            TIME,
            new Source(AGENCYID, AUTHOR),
            PHASE,
            POLARITY,
            ONSET,
            PICKER,
            new ArrayList<Filter>(Arrays.asList(new Filter(TYPE, HIGHPASS, LOWPASS, UNITS))),
            new Amplitude(AMPLITUDE, PERIOD, SNR),
            new Beam(
                BACKAZIMUTH,
                BACKAZIMUTHERROR,
                SLOWNESS,
                SLOWNESSERROR,
                POWERRATIO,
                POWERRATIOERROR),
            new Association(ASSOCPHASE, ASSOCDISTANCE, ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA),
            new Classification(
                CLASSPHASE,
                CLASSPHASEPROBABILITY,
                CLASSDISTANCE,
                CLASSDISTANCEPROBABILITY,
                CLASSBACKAZIMUTH,
                CLASSBACKAZIMUTHPROBABILITY,
                CLASSMAGNITUDE,
                CLASSMAGNITUDETYPE,
                CLASSMAGNITUDEPROBABILITY,
                CLASSDEPTH,
                CLASSDEPTHPROBABILITY,
                CLASSEVENTTYPE,
                CLASSCERTAINTY,
                CLASSEVENTTYPEPROBABILITY,
                CLASSAGENCYID,
                CLASSAUTHOR));

    // check data values
    CheckData(altAltAltPickObject, "Alternate Constructor 3");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Pick emptyObject = new Pick(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    Pick pickObject =
        new Pick(
            ID,
            STATION,
            CHANNEL,
            NETWORK,
            LOCATION,
            TIME,
            AGENCYID,
            AUTHOR,
            PHASE,
            POLARITY,
            ONSET,
            PICKER,
            TYPE,
            HIGHPASS,
            LOWPASS,
            UNITS,
            AMPLITUDE,
            PERIOD,
            SNR,
            BACKAZIMUTH,
            BACKAZIMUTHERROR,
            SLOWNESS,
            SLOWNESSERROR,
            POWERRATIO,
            POWERRATIOERROR,
            ASSOCPHASE,
            ASSOCDISTANCE,
            ASSOCAZIMUTH,
            ASSOCRESIDUAL,
            ASSOCSIGMA,
            CLASSPHASE,
            CLASSPHASEPROBABILITY,
            CLASSDISTANCE,
            CLASSDISTANCEPROBABILITY,
            CLASSBACKAZIMUTH,
            CLASSBACKAZIMUTHPROBABILITY,
            CLASSMAGNITUDE,
            CLASSMAGNITUDETYPE,
            CLASSMAGNITUDEPROBABILITY,
            CLASSDEPTH,
            CLASSDEPTHPROBABILITY,
            CLASSEVENTTYPE,
            CLASSCERTAINTY,
            CLASSEVENTTYPEPROBABILITY,
            CLASSAGENCYID,
            CLASSAUTHOR);

    // Successful validation
    boolean rc = pickObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad Pick object
    Pick badPickObject = new Pick();

    // Unuccessful validation
    rc = badPickObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 1");

    // build bad Pick object
    Pick badPickObject2 =
        new Pick(
            null, null, null, null, null, null, null, null, "22", "22", "22", "22", null, null,
            null, null, -99.0, null, null, -99.0, null, null, null, null, null, "22", null, null,
            null, null, "22", null, null, null, null, null, null, null, null, null, null, null,
            null, null, null, null);

    // Unuccessful validation
    rc = badPickObject2.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 2");
  }

  public void CheckData(Pick pickObject, String TestName) {
    // check pickObject.ID
    if (pickObject.getID() != null) {
      Assertions.assertEquals(ID, pickObject.getID(), TestName + " ID Equals");
    }

    // check pickObject.Site
    if (pickObject.getSite() != null) {
      // check pickObject.site.Station
      if (pickObject.getSite().getStation() != null) {
        Assertions.assertEquals(
            STATION, pickObject.getSite().getStation(), TestName + " Station Equals");
      }

      // check pickObject.site.Channel
      if (pickObject.getSite().getChannel() != null) {
        Assertions.assertEquals(
            CHANNEL, pickObject.getSite().getChannel(), TestName + " Channel Equals");
      }

      // check pickObject.site.Network
      if (pickObject.getSite().getNetwork() != null) {
        Assertions.assertEquals(
            NETWORK, pickObject.getSite().getNetwork(), TestName + " Network Equals");
      }

      // check pickObject.site.Location
      if (pickObject.getSite().getLocation() != null) {
        Assertions.assertEquals(
            LOCATION, pickObject.getSite().getLocation(), TestName + " Location Equals");
      }
    }

    // check pickObject.Source
    if (pickObject.getSource() != null) {
      // check pickObject.Source.AgencyID
      if (pickObject.getSource().getAgencyID() != null) {
        Assertions.assertEquals(
            AGENCYID, pickObject.getSource().getAgencyID(), TestName + " AgencyID Equals");
      }

      // check pickObject.Source.Author
      if (pickObject.getSource().getAuthor() != null) {
        Assertions.assertEquals(
            AUTHOR, pickObject.getSource().getAuthor(), TestName + " Author Equals");
      }
    }

    // check pickObject.Time
    if (pickObject.getTime() != null) {
      Assertions.assertEquals(TIME, pickObject.getTime(), TestName + " Time Equals");
    }

    // check pickObject.Phase
    if (pickObject.getPhase() != null) {
      Assertions.assertEquals(PHASE, pickObject.getPhase(), TestName + " Phase Equals");
    }

    // check pickObject.Polarity
    if (pickObject.getPolarity() != null) {
      Assertions.assertEquals(POLARITY, pickObject.getPolarity(), TestName + " Polarity Equals");
    }

    // check pickObject.Onset
    if (pickObject.getOnset() != null) {
      Assertions.assertEquals(ONSET, pickObject.getOnset(), TestName + " Onset Equals");
    }

    // check pickObject.Picker
    if (pickObject.getPicker() != null) {
      Assertions.assertEquals(PICKER, pickObject.getPicker(), TestName + " Picker Equals");
    }

    // check pickObject.FilterList
    if (pickObject.getFilterList() != null) {
      ArrayList<Filter> filterList = pickObject.getFilterList();
      if (!filterList.isEmpty()) {
        // get the first filter in the list
        Filter aFilter = filterList.get(0);

        // check aFilter.type
        if (aFilter.getType() != null) {
          Assertions.assertEquals(TYPE, aFilter.getType(), TestName + " Type Equals");
        }

        // check aFilter.highPass
        if (aFilter.getHighPass() != null) {
          Assertions.assertEquals(
              HIGHPASS, aFilter.getHighPass(), 0, TestName + " HighPass Equals");
        }

        // check aFilter.lowPass
        if (aFilter.getLowPass() != null) {
          Assertions.assertEquals(LOWPASS, aFilter.getLowPass(), 0, TestName + " LowPass Equals");
        }

        // check aFilter.units
        if (aFilter.getUnits() != null) {
          Assertions.assertEquals(UNITS, aFilter.getUnits(), TestName + " Units Equals");
        }
      }
    }

    // check pickObject.Amplitude
    if ((pickObject.getAmplitude() != null) && (!pickObject.getAmplitude().isEmpty())) {
      // check pickObject.Amplitude.Amplitude
      if (pickObject.getAmplitude().getAmplitude() != null) {
        Assertions.assertEquals(
            AMPLITUDE, pickObject.getAmplitude().getAmplitude(), 0, TestName + " Amplitude Equals");
      }

      // check pickObject.Amplitude.Period
      if (pickObject.getAmplitude().getPeriod() != null) {
        Assertions.assertEquals(
            PERIOD, pickObject.getAmplitude().getPeriod(), 0, TestName + " Period Equals");
      }

      // check pickObject.Amplitude.SNR
      if (pickObject.getAmplitude().getSNR() != null) {
        Assertions.assertEquals(
            SNR, pickObject.getAmplitude().getSNR(), 0, TestName + " SNR Equals");
      }
    }

    // check pickObject.Beam
    if (pickObject.getBeam() != null) {
      // check pickObject.getBeam().BackAzimuth
      if (pickObject.getBeam().getBackAzimuth() != null) {
        Assertions.assertEquals(
            BACKAZIMUTH,
            pickObject.getBeam().getBackAzimuth(),
            0,
            TestName + " BackAzimuth Equals");
      }

      // check pickObject.getBeam().BackAzimuthError
      if (pickObject.getBeam().getBackAzimuthError() != null) {
        Assertions.assertEquals(
            BACKAZIMUTHERROR,
            pickObject.getBeam().getBackAzimuthError(),
            0,
            TestName + " BackAzimuthError Equals");
      }

      // check pickObject.getBeam().Slowness
      if (pickObject.getBeam().getSlowness() != null) {
        Assertions.assertEquals(
            SLOWNESS, pickObject.getBeam().getSlowness(), 0, TestName + " Slowness Equals");
      }

      // check pickObject.getBeam().SlownessError
      if (pickObject.getBeam().getSlownessError() != null) {
        Assertions.assertEquals(
            SLOWNESSERROR,
            pickObject.getBeam().getSlownessError(),
            0,
            TestName + " SlownessError Equals");
      }

      // check pickObject.getBeam().PowerRatio
      if (pickObject.getBeam().getPowerRatio() != null) {
        Assertions.assertEquals(
            POWERRATIO, pickObject.getBeam().getPowerRatio(), 0, TestName + " PowerRatio Equals");
      }

      // check pickObject.getBeam().PowerRatioError
      if (pickObject.getBeam().getPowerRatioError() != null) {
        Assertions.assertEquals(
            POWERRATIOERROR,
            pickObject.getBeam().getPowerRatioError(),
            0,
            TestName + " PowerRatioError Equals");
      }
    }

    // check pickObject.AssociationInfo
    if ((pickObject.getAssociationInfo() != null) && !pickObject.getAssociationInfo().isEmpty()) {
      // check pickObject.Association.Phase
      if (pickObject.getAssociationInfo().getPhase() != null) {
        Assertions.assertEquals(
            ASSOCPHASE, pickObject.getAssociationInfo().getPhase(), TestName + " Phase Equals");
      }

      // check pickObject.Association.Distance
      if (pickObject.getAssociationInfo().getPhase() != null) {
        Assertions.assertEquals(
            ASSOCDISTANCE,
            pickObject.getAssociationInfo().getDistance(),
            0,
            TestName + " Distance Equals");
      }

      // check pickObject.Association.Azimuth
      if (pickObject.getAssociationInfo().getPhase() != null) {
        Assertions.assertEquals(
            ASSOCAZIMUTH,
            pickObject.getAssociationInfo().getAzimuth(),
            0,
            TestName + " Azimuth Equals");
      }

      // check pickObject.Association.Residual
      if (pickObject.getAssociationInfo().getPhase() != null) {
        Assertions.assertEquals(
            ASSOCRESIDUAL,
            pickObject.getAssociationInfo().getResidual(),
            0,
            TestName + " Residual Equals");
      }

      // check pickObject.Association.Sigma
      if (pickObject.getAssociationInfo().getSigma() != null) {
        Assertions.assertEquals(
            ASSOCSIGMA, pickObject.getAssociationInfo().getSigma(), 0, TestName + " Sigma Equals");
      }
    }

    // check pickObject.ClassificationInfo
    if ((pickObject.getClassificationInfo() != null)
        && !pickObject.getClassificationInfo().isEmpty()) {
      // check pickObject.getClassificationInfo().phase
      if (pickObject.getClassificationInfo().getPhase() != null) {
        Assertions.assertEquals(
            CLASSPHASE, pickObject.getClassificationInfo().getPhase(), TestName + " Phase Equals");
      }

      // check pickObject.getClassificationInfo().phaseProbability
      if (pickObject.getClassificationInfo().getPhaseProbability() != null) {
        Assertions.assertEquals(
            CLASSPHASEPROBABILITY,
            pickObject.getClassificationInfo().getPhaseProbability(),
            0,
            TestName + " Phase Probability Equals");
      }

      // check pickObject.getClassificationInfo().distance
      if (pickObject.getClassificationInfo().getDistance() != null) {
        Assertions.assertEquals(
            CLASSDISTANCE,
            pickObject.getClassificationInfo().getDistance(),
            0,
            TestName + " Distance Equals");
      }

      // check pickObject.getClassificationInfo().distanceProbability
      if (pickObject.getClassificationInfo().getDistanceProbability() != null) {
        Assertions.assertEquals(
            CLASSDISTANCEPROBABILITY,
            pickObject.getClassificationInfo().getDistanceProbability(),
            0,
            TestName + " Distance Probability Equals");
      }

      // check pickObject.getClassificationInfo().Backazimuth
      if (pickObject.getClassificationInfo().getBackazimuth() != null) {
        Assertions.assertEquals(
            CLASSBACKAZIMUTH,
            pickObject.getClassificationInfo().getBackazimuth(),
            0,
            TestName + " Backazimuth Equals");
      }

      // check pickObject.getClassificationInfo().backazimuthProbability
      if (pickObject.getClassificationInfo().getBackazimuthProbability() != null) {
        Assertions.assertEquals(
            CLASSBACKAZIMUTHPROBABILITY,
            pickObject.getClassificationInfo().getBackazimuthProbability(),
            0,
            TestName + " Backazimuth Probability Equals");
      }

      // check pickObject.getClassificationInfo().magnitude
      if (pickObject.getClassificationInfo().getMagnitude() != null) {
        Assertions.assertEquals(
            CLASSMAGNITUDE,
            pickObject.getClassificationInfo().getMagnitude(),
            0,
            TestName + " Magnitude Equals");
      }

      // check pickObject.getClassificationInfo().magnitudeType
      if (pickObject.getClassificationInfo().getMagnitudeType() != null) {
        Assertions.assertEquals(
            CLASSMAGNITUDETYPE,
            pickObject.getClassificationInfo().getMagnitudeType(),
            TestName + " Magnitude Type Equals");
      }

      // check pickObject.getClassificationInfo().magnitudeProbability
      if (pickObject.getClassificationInfo().getMagnitudeProbability() != null) {
        Assertions.assertEquals(
            CLASSMAGNITUDEPROBABILITY,
            pickObject.getClassificationInfo().getMagnitudeProbability(),
            0,
            TestName + " Magnitude Probability Equals");
      }

      // check pickObject.getClassificationInfo().depth
      if (pickObject.getClassificationInfo().getDepth() != null) {
        Assertions.assertEquals(
            CLASSDEPTH,
            pickObject.getClassificationInfo().getDepth(),
            0,
            TestName + " Depth Equals");
      }

      // check pickObject.getClassificationInfo().depthProbability
      if (pickObject.getClassificationInfo().getDepthProbability() != null) {
        Assertions.assertEquals(
            CLASSDEPTHPROBABILITY,
            pickObject.getClassificationInfo().getDepthProbability(),
            0,
            TestName + " Depth Probability Equals");
      }

      // check pickObject.getClassificationInfo().eventType
      if (pickObject.getClassificationInfo().getEventType() != null) {
        // check pickObject.getClassificationInfo().EventType.type
        if (pickObject.getClassificationInfo().getEventType().getType() != null) {
          Assertions.assertEquals(
              CLASSEVENTTYPE,
              pickObject.getClassificationInfo().getEventType().getType(),
              TestName + " Type Equals");
        }

        // check pickObject.getClassificationInfo().EventType.certainty
        if (pickObject.getClassificationInfo().getEventType().getCertainty() != null) {
          Assertions.assertEquals(
              CLASSCERTAINTY,
              pickObject.getClassificationInfo().getEventType().getCertainty(),
              TestName + " Certantity Equals");
        }
      }

      // check pickObject.getClassificationInfo().eventTypeProbability
      if (pickObject.getClassificationInfo().getEventTypeProbability() != null) {
        Assertions.assertEquals(
            CLASSEVENTTYPEPROBABILITY,
            pickObject.getClassificationInfo().getEventTypeProbability(),
            0,
            TestName + " Event Type Probability Equals");
      }

      // check pickObject.getClassificationInfo().source
      if (pickObject.getClassificationInfo().getSource() != null) {
        // check pickObject.getClassificationInfo().Source.AgencyID
        if (pickObject.getClassificationInfo().getSource().getAgencyID() != null) {
          Assertions.assertEquals(
              CLASSAGENCYID,
              pickObject.getClassificationInfo().getSource().getAgencyID(),
              TestName + " AgencyID Equals");
        }

        // check pickObject.getClassificationInfo().Source.Author
        if (pickObject.getClassificationInfo().getSource().getAuthor() != null) {
          Assertions.assertEquals(
              CLASSAUTHOR,
              pickObject.getClassificationInfo().getSource().getAuthor(),
              TestName + " Author Equals");
        }
      }
    }
  }
}
