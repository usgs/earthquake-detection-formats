package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SiteTest {

  public static String SITE_STRING =
      "{\"Station\":\"BOZ\",\"Channel\":"
          + "\"BHZ\",\"Network\":\"US\",\"Location\":\"00\","
          + "\"Latitude\":45.59697,\"Longitude\":-111.62967,"
          + "\"Elevation\":1589.0}";
  public static String STATION = "BOZ";
  public static String CHANNEL = "BHZ";
  public static String NETWORK = "US";
  public static String LOCATION = "00";
  public static double LATITUDE = 45.596970;
  public static double LONGITUDE = -111.629670;
  public static double ELEVATION = 1589.000000;

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    Site SiteObject = new Site(STATION, CHANNEL, NETWORK, LOCATION, LATITUDE, LONGITUDE, ELEVATION);

    // write out to a string
    String jsonString = Utility.toJSONString(SiteObject.toJSON());

    // check the data
    try {
      CheckData(new Site(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {
    // build Site object
    try {
      CheckData(new Site(Utility.fromJSONString(SITE_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    Site SiteObject = new Site(STATION, CHANNEL, NETWORK, LOCATION);

    // check data values
    CheckData(SiteObject, "Constructor 1");

    Site SiteObject2 =
        new Site(STATION, CHANNEL, NETWORK, LOCATION, LATITUDE, LONGITUDE, ELEVATION);

    // check data values
    CheckData(SiteObject2, "Constructor 2");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    Site emptyObject = new Site(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    Site siteObject = new Site(STATION, CHANNEL, NETWORK, LOCATION, LATITUDE, LONGITUDE, ELEVATION);

    // Successful validation
    boolean rc = siteObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad Site object
    Site badSiteObject = new Site();

    // Unuccessful validation
    rc = badSiteObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 1");

    // build bad source object
    Site badSiteObject2 = new Site("", null, "", null);

    rc = badSiteObject2.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 2");
  }

  /** Checks the data in the class */
  public void CheckData(Site SiteObject, String TestName) {
    // check SiteObject.Station
    if (SiteObject.getStation() != null) {
      Assertions.assertEquals(STATION, SiteObject.getStation(), TestName + " Station Equals");
    }

    // check SiteObject.Channel
    if (SiteObject.getChannel() != null) {
      Assertions.assertEquals(CHANNEL, SiteObject.getChannel(), TestName + " Channel Equals");
    }

    // check SiteObject.Network
    if (SiteObject.getNetwork() != null) {
      Assertions.assertEquals(NETWORK, SiteObject.getNetwork(), TestName + " Network Equals");
    }

    // check SiteObject.Location
    if (SiteObject.getLocation() != null) {
      Assertions.assertEquals(LOCATION, SiteObject.getLocation(), TestName + " Location Equals");
    }

    // check SiteObject.Latitude
    if (SiteObject.getLatitude() != null) {
      Assertions.assertEquals(LATITUDE, SiteObject.getLatitude(), 0, TestName + " Latitude Equals");
    }

    // check SiteObject.Longitude
    if (SiteObject.getLongitude() != null) {
      Assertions.assertEquals(
          LONGITUDE, SiteObject.getLongitude(), 0, TestName + " Longitude Equals");
    }

    // check SiteObject.Elevation
    if (SiteObject.getElevation() != null) {
      Assertions.assertEquals(
          ELEVATION, SiteObject.getElevation(), 0, TestName + " Elevation Equals");
    }
  }
}
