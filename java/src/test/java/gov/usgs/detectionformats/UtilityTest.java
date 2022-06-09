package gov.usgs.detectionformats;

import java.util.Date;
import java.util.GregorianCalendar;
import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class UtilityTest {
  public static String JSON_STRING = "{\"Key\":\"Value\"}";
  public static String KEY = "Key";
  public static String VALUE = "Value";
  public static String LETTERS = "abcEFghijklmnoP";
  public static String NUMBERS = "-111.5";
  public static String BOTH = "aaaa-111.5ddddczx";
  public static String TIME = "2015-12-28T21:32:24.017Z";
  public static long TIMEMILI = 1451338344017L;
  public static Date DATE = new Date(TIMEMILI);

  public static String CORRELATION_STRING =
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
          + "\"Certainty\":\"Suspected\"},\"MinimumDistance\":2.14}";
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
          + "\"DistanceProbability\":22.5,\"Backazimuth\":0.418479,"
          + "\"BackazimuthProbability\":0.16,\"Magnitude\":2.14,"
          + "\"MagnitudeType\":\"Mb\",\"MagnitudeProbability\":0.55,"
          + "\"Depth\":32.44,\"DepthProbability\":11.2,"
          + "\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},"
          + "\"EventTypeProbability\":1.1,\"Source\":{\"AgencyID\":\"US\","
          + "\"Author\":\"TestAuthor\"}}}";
  public static String RETRACT_STRING =
      "{\"Type\":\"Retract\",\"Source\":{\"Author\":"
          + "\"TestAuthor\",\"AgencyID\":\"US\"},\"ID\":\"12GFH48776857\"}";
  public static final String STATION_STRING =
      "{\"Site\":{\"Station\":\"BOZ\","
          + "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},"
          + "\"Enable\":true,\"Quality\":1.0,\"Type\":\"StationInfo\","
          + "\"Use\":true,\"Elevation\":1589.0,\"UseForTeleseismic\":true,"
          + "\"Latitude\":45.59697,\"Longitude\":-111.62967,"
          + "\"InformationRequestor\":{\"Author\":\"TestAuthor\","
          + "\"AgencyID\":\"US\"}}";
  public static final String REQUEST_STRING =
      "{\"Site\":{\"Station\":\"BOZ\","
          + "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},"
          + "\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},"
          + "\"Type\":\"StationInfoRequest\"}";
  public static String BAD_MESSAGE = "non-json formatted string";
  public static String BAD_MESSAGE2 = "{\"Type\":\"MadeUp\",\"Key\":\"Value\"}";

  /** Check getDetectionType */
  @Test
  public void getDetectionType() {
    // test successful correlation identification
    Assertions.assertEquals(
        Utility.getDetectionType(CORRELATION_STRING),
        FormatTypes.Correlation,
        "successful correlation identification");

    // test successful detection identification
    Assertions.assertEquals(
        Utility.getDetectionType(DETECTION_STRING),
        FormatTypes.Detection,
        "successful detection identification");

    // test successful pick identification
    Assertions.assertEquals(
        Utility.getDetectionType(PICK_STRING), FormatTypes.Pick, "successful pick identification");

    // test successful retraction identification
    Assertions.assertEquals(
        Utility.getDetectionType(RETRACT_STRING),
        FormatTypes.Retract,
        "successful retraction identification");

    // test successful stationinfo identification
    Assertions.assertEquals(
        Utility.getDetectionType(STATION_STRING),
        FormatTypes.StationInfo,
        "successful stationinfo identification");

    // test successful stationinforequest identification
    Assertions.assertEquals(
        Utility.getDetectionType(REQUEST_STRING),
        FormatTypes.StationInfoRequest,
        "successful stationinforequest identification");

    // test unsuccessful identification 1
    Assertions.assertEquals(
        Utility.getDetectionType(BAD_MESSAGE), FormatTypes.Error, "unsuccessful identification 1");

    // test unsuccessful identification 2
    Assertions.assertEquals(
        Utility.getDetectionType(BAD_MESSAGE2),
        FormatTypes.Unknown,
        "unsuccessful identification 2");

    // test unsuccessful identification 3
    Assertions.assertEquals(
        Utility.getDetectionType(""), FormatTypes.Error, "unsuccessful identification 3");
  }

  /** Check isJSONValid */
  @Test
  public void isJSONValid() {

    // test invalid json
    Assertions.assertEquals(Utility.isJSONValid(BAD_MESSAGE), false, "invalid json");

    // test valid json
    Assertions.assertEquals(Utility.isJSONValid(PICK_STRING), true, "valid json");
  }

  /** Able to convert from a JSON string */
  @Test
  @SuppressWarnings("unchecked")
  public void FromJSONString() {
    try {
      CheckData(Utility.fromJSONString(JSON_STRING), "FromJSONString");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in FromJSONString");
    }
  }

  /** Able to convert to a JSON string */
  @Test
  @SuppressWarnings("unchecked")
  public void ToJSONString() {
    JSONObject aJSONObject = new JSONObject();
    aJSONObject.put(KEY, VALUE);
    try {
      CheckData(Utility.fromJSONString(Utility.toJSONString(aJSONObject)), "ToJSONString");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ToJSONString");
    }
  }

  /** Check isStringAlpha */
  @Test
  public void IsStringAlpha() {
    Assertions.assertEquals(true, Utility.isStringAlpha(LETTERS), "Is Alpha");

    Assertions.assertEquals(false, Utility.isStringAlpha(NUMBERS), "Is Not Alpha");

    Assertions.assertEquals(false, Utility.isStringAlpha(BOTH), "Is Not Alpha (both)");
  }

  /** Check isStringNumber */
  @Test
  public void IsStringNumber() {
    Assertions.assertEquals(true, Utility.isStringNumber(NUMBERS), "Is Number");

    Assertions.assertEquals(false, Utility.isStringNumber(LETTERS), "Is Not Number");

    Assertions.assertEquals(false, Utility.isStringAlpha(BOTH), "Is Not Number (both)");
  }

  /** Check formatDate */
  @Test
  public void FormatDate() {
    Assertions.assertEquals(TIME, Utility.formatDate(Utility.getDate(TIME)), "Format Date");

    Assertions.assertEquals(null, Utility.formatDate(null), "Format Date null");
  }

  /** Check formatGregorianCalendar */
  @Test
  public void FormatGregorianCalendar() {
    GregorianCalendar calendar = new GregorianCalendar();
    calendar.setTimeInMillis(Utility.getDate(TIME).getTime());

    Assertions.assertEquals(
        TIME, Utility.formatGregorianCalendar(calendar), "Format Gregorian Calendar");

    Assertions.assertEquals(
        null, Utility.formatGregorianCalendar(null), "Format Gregorian Calendar null");
  }

  /** Check getXMLGregorianCalendar */
  @Test
  public void getXMLGregorianCalendar() {
    Assertions.assertNotSame(
        null, Utility.getXMLGregorianCalendar(TIME), "getXMLGregorianCalendar");

    Assertions.assertEquals(
        null, Utility.getXMLGregorianCalendar(null), "getXMLGregorianCalendar null");
  }

  /** Check formatGregorianCalendar */
  @Test
  public void getDate() {
    Assertions.assertEquals(DATE, Utility.getDate(TIME), "Get Date");

    Assertions.assertEquals(null, Utility.getDate((String) null), "Get Date null");

    // Assertions.assertEquals("Get Date", DATE,
    //     Utility.getDate(Utility.getXMLGregorianCalendar(TIME)));
  }

  public void CheckData(JSONObject aJSONObject, String TestName) {
    // key/value
    if (aJSONObject.containsKey(KEY)) {
      Assertions.assertEquals(VALUE, aJSONObject.get(KEY).toString(), TestName + " Value Equals");
    } else {
      Assertions.fail("Key not found");
    }
  }
}
