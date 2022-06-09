package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class StationInfoTest {
  public static final String STATION_STRING =
      "{\"Site\":{\"Station\":\"BOZ\","
          + "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\","
          + "\"Latitude\":45.59697,\"Longitude\":-111.62967,\"Elevation\":1589.0},"
          + "\"Enable\":true,\"Quality\":1.0,\"Type\":\"StationInfo\","
          + "\"Use\":true,\"UseForTeleseismic\":true,"
          + "\"InformationRequestor\":{\"Author\":\"TestAuthor\","
          + "\"AgencyID\":\"US\"}}";

  public static final String STATION = "BOZ";
  public static final String CHANNEL = "BHZ";
  public static final String NETWORK = "US";
  public static final String LOCATION = "00";
  public static double LATITUDE = 45.596970;
  public static double LONGITUDE = -111.629670;
  public static double ELEVATION = 1589.000000;
  public static double QUALITY = 1.0;
  public static boolean ENABLE = true;
  public static boolean USE = true;
  public static boolean USEFORTELESEISM = true;
  public static String AGENCYID = "US";
  public static String AUTHOR = "TestAuthor";

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    StationInfo stationObject =
        new StationInfo(
            STATION,
            CHANNEL,
            NETWORK,
            LOCATION,
            LATITUDE,
            LONGITUDE,
            ELEVATION,
            QUALITY,
            ENABLE,
            USE,
            USEFORTELESEISM,
            AGENCYID,
            AUTHOR);

    // write out to a string
    String jsonString = Utility.toJSONString(stationObject.toJSON());

    // check the data
    try {
      CheckData(new StationInfo(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void ReadsJSON() {
    // build StationInfo object
    try {
      CheckData(new StationInfo(Utility.fromJSONString(STATION_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    // use constructor
    StationInfo stationObject =
        new StationInfo(
            STATION,
            CHANNEL,
            NETWORK,
            LOCATION,
            LATITUDE,
            LONGITUDE,
            ELEVATION,
            QUALITY,
            ENABLE,
            USE,
            USEFORTELESEISM,
            AGENCYID,
            AUTHOR);

    // check data values
    CheckData(stationObject, "Constructor");

    // use constructor
    StationInfo altStationObject =
        new StationInfo(
            new Site(STATION, CHANNEL, NETWORK, LOCATION, LATITUDE, LONGITUDE, ELEVATION),
            QUALITY,
            ENABLE,
            USE,
            USEFORTELESEISM,
            new Source(AGENCYID, AUTHOR));

    // check data values
    CheckData(altStationObject, "Alternate Constructor");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    StationInfo emptyObject = new StationInfo(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    StationInfo stationObject =
        new StationInfo(
            STATION,
            CHANNEL,
            NETWORK,
            LOCATION,
            LATITUDE,
            LONGITUDE,
            ELEVATION,
            QUALITY,
            ENABLE,
            USE,
            USEFORTELESEISM,
            AGENCYID,
            AUTHOR);

    // Successful validation
    boolean rc = stationObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad StationInfo object
    StationInfo badStationInfoObject = new StationInfo();

    // Unsuccessful validation
    rc = badStationInfoObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 1");

    // build bad StationInfo object
    StationInfo badStationInfoObject2 =
        new StationInfo(
            "", null, "", null, -9999.0, 9999.0, 1000000.0, null, null, null, null, "", "");

    rc = badStationInfoObject2.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation");
  }

  public void CheckData(StationInfo stationObject, String TestName) {
    // check stationObject.Site
    if (stationObject.getSite() != null) {
      // check stationObject.site.Station
      if (stationObject.getSite().getStation() != null) {
        Assertions.assertEquals(
            STATION, stationObject.getSite().getStation(), TestName + " Station Equals");
      }

      // check stationObject.site.Channel
      if (stationObject.getSite().getChannel() != null) {
        Assertions.assertEquals(
            CHANNEL, stationObject.getSite().getChannel(), TestName + " Channel Equals");
      }

      // check stationObject.site.Network
      if (stationObject.getSite().getNetwork() != null) {
        Assertions.assertEquals(
            NETWORK, stationObject.getSite().getNetwork(), TestName + " Network Equals");
      }

      // check stationObject.site.Location
      if (stationObject.getSite().getLocation() != null) {
        Assertions.assertEquals(
            LOCATION, stationObject.getSite().getLocation(), TestName + " Location Equals");
      }

      // check stationObject.site.Latitude
      if (stationObject.getSite().getLatitude() != null) {
        Assertions.assertEquals(
            LATITUDE, stationObject.getSite().getLatitude(), 0, TestName + " Latitude Equals");
      }

      // check stationObject.site.Longitude
      if (stationObject.getSite().getLongitude() != null) {
        Assertions.assertEquals(
            LONGITUDE, stationObject.getSite().getLongitude(), 0, TestName + " Longitude Equals");
      }

      // check stationObject.site.Elevation
      if (stationObject.getSite().getElevation() != null) {
        Assertions.assertEquals(
            ELEVATION, stationObject.getSite().getElevation(), 0, TestName + " Elevation Equals");
      }
    }

    // optional values
    // check hypoObject.quality
    if (stationObject.getQuality() != null) {
      Assertions.assertEquals(QUALITY, stationObject.getQuality(), 0, TestName + " Quality Equals");
    }

    // check stationObject.enable
    if (stationObject.getEnable() != null) {
      Assertions.assertEquals(ENABLE, stationObject.getEnable(), TestName + " Enable Equals");
    }

    // check stationObject.use
    if (stationObject.getUse() != null) {
      Assertions.assertEquals(USE, stationObject.getUse(), TestName + " Use Equals");
    }

    // check stationObject.useforteleseismic
    if (stationObject.getUseForTeleseismic() != null) {
      Assertions.assertEquals(
          USEFORTELESEISM,
          stationObject.getUseForTeleseismic(),
          TestName + " UseForTeleseism Equals");
    }
    // check stationObject.informationRequestor
    // check stationObject.Source
    if (stationObject.getInformationRequestor() != null) {
      // check stationObject.InformationRequestor.AgencyID
      if (stationObject.getInformationRequestor().getAgencyID() != null) {
        Assertions.assertEquals(
            AGENCYID,
            stationObject.getInformationRequestor().getAgencyID(),
            TestName + " AgencyID Equals");
      }

      // check stationObject.InformationRequestor.Author
      if (stationObject.getInformationRequestor().getAuthor() != null) {
        Assertions.assertEquals(
            AUTHOR,
            stationObject.getInformationRequestor().getAuthor(),
            TestName + " Author Equals");
      }
    }
  }
}
