package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AmplitudeTest {

  public static final String AMPLITUDE_STRING =
      "{\"Period\":2.65," + "\"Amplitude\":1.05,\"SNR\":3.8}";
  public static final double AMPLITUDE = 1.05;
  public static final double PERIOD = 2.65;
  public static final double SNR = 3.8;

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {

    Amplitude amplitudeObject = new Amplitude(AMPLITUDE, PERIOD, SNR);

    // write out to a string
    String jsonString = Utility.toJSONString(amplitudeObject.toJSON());

    // check the data
    try {
      CheckData(new Amplitude(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {

    // build Amplitude object
    try {

      CheckData(new Amplitude(Utility.fromJSONString(AMPLITUDE_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    Amplitude amplitudeObject = new Amplitude(AMPLITUDE, PERIOD, SNR);

    // check data values
    CheckData(amplitudeObject, "Constructor");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Amplitude emptyObject = new Amplitude(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    Amplitude amplitudeObject = new Amplitude(AMPLITUDE, PERIOD, SNR);

    // Successful validation
    boolean rc = amplitudeObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad Pick object
    Amplitude badAmplitudeObject = new Amplitude(null, -9999.0, -9999.0);

    // Unuccessful validation
    rc = badAmplitudeObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 2");
  }

  /** Empty check function */
  @Test
  public void IsEmpty() {
    // empty object
    Amplitude amplitudeObject = new Amplitude();

    // checked for empty
    boolean rc = amplitudeObject.isEmpty();

    // check return code
    Assertions.assertEquals(true, rc, "Tested for empty.");

    // not empty object
    Amplitude amplitudeObject2 = new Amplitude(AMPLITUDE, PERIOD, SNR);

    // checked for empty
    rc = amplitudeObject2.isEmpty();

    // check return code
    Assertions.assertEquals(false, rc, "Tested for not empty.");
  }

  /** Checks the data in the class */
  public void CheckData(Amplitude AmplitudeObject, String TestName) {
    // check AmplitudeObject.Amplitude
    if (AmplitudeObject.getAmplitude() != null) {
      Assertions.assertEquals(
          AMPLITUDE, AmplitudeObject.getAmplitude(), 0, TestName + " Amplitude Equals");
    }

    // check AmplitudeObject.Period
    if (AmplitudeObject.getPeriod() != null) {
      Assertions.assertEquals(PERIOD, AmplitudeObject.getPeriod(), 0, TestName + " Period Equals");
    }

    // check AmplitudeObject.SNR
    if (AmplitudeObject.getSNR() != null) {
      Assertions.assertEquals(SNR, AmplitudeObject.getSNR(), 0, TestName + " SNR Equals");
    }
  }
}
