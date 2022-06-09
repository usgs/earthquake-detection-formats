package gov.usgs.detectionformats;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class DetectionFormatsTest {
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
          + "\"DistanceProbability\":22.5,\"BackAzimuth\":0.418479,"
          + "\"BackAzimuthProbability\":0.16,\"Magnitude\":2.14,"
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
          + "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\","
          + "\"Latitude\":45.59697,\"Longitude\":-111.62967,\"Elevation\":1589.0},"
          + "\"Enable\":true,\"Quality\":1.0,\"Type\":\"StationInfo\","
          + "\"Use\":true,\"UseForTeleseismic\":true,"
          + "\"InformationRequestor\":{\"Author\":\"TestAuthor\","
          + "\"AgencyID\":\"US\"}}";
  public static final String REQUEST_STRING =
      "{\"Site\":{\"Station\":\"BOZ\","
          + "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},"
          + "\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},"
          + "\"Type\":\"StationInfoRequest\"}";
  public static String BAD_MESSAGE = "non-json formatted string";
  public static String BAD_MESSAGE2 = "{\"Type\":\"MadeUp\",\"Key\":\"Value\"}";

  /** Check validateJSON */
  @Test
  public void validateJSON() {
    // test successful correlation validation
    Assertions.assertEquals(
        DetectionFormats.validateJSON(CORRELATION_STRING),
        true,
        "successful correlation validation");

    // test successful detection validation
    Assertions.assertEquals(
        DetectionFormats.validateJSON(DETECTION_STRING), true, "successful detection validation");

    // test successful pick validation
    Assertions.assertEquals(
        DetectionFormats.validateJSON(PICK_STRING), true, "successful pick validation");

    // test successful retraction validation
    Assertions.assertEquals(
        DetectionFormats.validateJSON(RETRACT_STRING), true, "successful retraction validation");

    // test successful stationinfo validation
    Assertions.assertEquals(
        DetectionFormats.validateJSON(STATION_STRING), true, "successful stationinfo validation");

    // test successful stationinforequest validation
    Assertions.assertEquals(
        DetectionFormats.validateJSON(REQUEST_STRING),
        true,
        "successful stationinforequest validation");

    // test unsuccessful validation 1
    Assertions.assertEquals(
        DetectionFormats.validateJSON(BAD_MESSAGE), false, "unsuccessful validation 1");

    // test unsuccessful validation 2
    Assertions.assertEquals(
        DetectionFormats.validateJSON(BAD_MESSAGE2), false, "unsuccessful validation 2");

    // test unsuccessful validation 3
    Assertions.assertEquals(DetectionFormats.validateJSON(""), false, "unsuccessful validation 3");
  }
}
