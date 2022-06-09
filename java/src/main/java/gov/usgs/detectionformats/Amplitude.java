package gov.usgs.detectionformats;

import java.util.ArrayList;
import org.json.simple.JSONObject;

/**
 * a conversion class used to create, parse, and validate amplitude data as part of detection data.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Amplitude implements DetectionInt {

  /** JSON Keys */
  public static final String AMPLITUDE_KEY = "Amplitude";

  public static final String PERIOD_KEY = "Period";
  public static final String SNR_KEY = "SNR";

  /** Optional double containing the Amplitude */
  private final Double amplitude;

  /** Optional double containing the Period */
  private final Double period;

  /** Optional double containing the SNR */
  private final Double snr;

  /** The constructor for the Amplitude class. Initializes members to null values. */
  public Amplitude() {

    amplitude = null;
    period = null;
    snr = null;
  }

  /**
   * The advanced constructor for the Amplitude class. Initializes members to provided values.
   *
   * @param newAmplitude - A double containing the Amplitude to use (null omit)
   * @param newPeriod - A double containing the Period to use (null omit)
   * @param newSNR - A double containing the SNR to use (null omit)
   */
  public Amplitude(final Double newAmplitude, final Double newPeriod, final Double newSNR) {

    amplitude = newAmplitude;
    period = newPeriod;
    snr = newSNR;
  }

  /**
   * Constructs the class from a JSONObject, populating members
   *
   * @param newJSONObject - A JSONObject.
   */
  public Amplitude(JSONObject newJSONObject) {

    // optional values
    // amplitude
    if (newJSONObject.containsKey(AMPLITUDE_KEY)) {
      amplitude = Double.valueOf(newJSONObject.get(AMPLITUDE_KEY).toString());
    } else {
      amplitude = null;
    }

    // period
    if (newJSONObject.containsKey(PERIOD_KEY)) {
      period = Double.valueOf(newJSONObject.get(PERIOD_KEY).toString());
    } else {
      period = null;
    }

    // snr
    if (newJSONObject.containsKey(SNR_KEY)) {
      snr = Double.valueOf(newJSONObject.get(SNR_KEY).toString());
    } else {
      snr = null;
    }
  }

  /**
   * Converts the contents of the class to a JSON object
   *
   * @return Returns a JSONObject containing the class contents
   */
  @SuppressWarnings("unchecked")
  public JSONObject toJSON() {

    JSONObject newJSONObject = new JSONObject();

    Double jsonAmplitude = getAmplitude();
    Double jsonPeriod = getPeriod();
    Double jsonSnr = getSNR();

    // optional values
    // amplitude
    if (jsonAmplitude != null) {
      newJSONObject.put(AMPLITUDE_KEY, jsonAmplitude);
    }

    // period
    if (jsonPeriod != null) {
      newJSONObject.put(PERIOD_KEY, jsonPeriod);
    }

    // snr
    if (jsonSnr != null) {
      newJSONObject.put(SNR_KEY, jsonSnr);
    }

    // return valid object
    return (newJSONObject);
  }

  /**
   * Validates the class.
   *
   * @return Returns true if successful
   */
  public boolean isValid() {
    if (getErrors().size() == 0) {
      return (true);
    } else {
      return (false);
    }
  }

  /**
   * Gets any validation errors in the class.
   *
   * @return Returns a List&lt;String&gt; of any errors found
   */
  public ArrayList<String> getErrors() {
    Double jsonPeriod = getPeriod();
    Double jsonSNR = getSNR();

    ArrayList<String> errorList = new ArrayList<String>();

    // optional data
    // period
    if (jsonPeriod != null) {
      if (jsonPeriod < 0) {
        errorList.add("Invalid Period in Amplitude class.");
      }
    }

    // SNR
    if (jsonSNR != null) {
      if ((jsonSNR < 0) || (jsonSNR > 9999999999.999)) {
        errorList.add(
            "SNR in Amplitude Class is not in the valid " + "range of 0 to 9999999999.999");
      }
    }

    // success
    return (errorList);
  }

  /**
   * Checks to see if this object is empty
   *
   * @return Returns true if empty, false otherwise.
   */
  public boolean isEmpty() {
    if (getAmplitude() != null) {
      return (false);
    }
    if (getPeriod() != null) {
      return (false);
    }
    if (getSNR() != null) {
      return (false);
    }

    return (true);
  }

  /** @return the amplitude */
  public Double getAmplitude() {
    return amplitude;
  }

  /** @return the period */
  public Double getPeriod() {
    return period;
  }

  /** @return the snr */
  public Double getSNR() {
    return snr;
  }
}
