package gov.usgs.detectionformats;

import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class StationInfoRequestTest {
  public static final String STATION_STRING =
      "{\"Site\":{\"Station\":\"BOZ\","
          + "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},"
          + "\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},"
          + "\"Type\":\"StationInfoRequest\"}";

  public static final String STATION = "BOZ";
  public static final String CHANNEL = "BHZ";
  public static final String NETWORK = "US";
  public static final String LOCATION = "00";
  public static String AGENCYID = "US";
  public static String AUTHOR = "TestAuthor";

  /** Able to write a JSON string */
  @Test
  public void WritesJSON() {
    StationInfoRequest stationRequestObject =
        new StationInfoRequest(STATION, CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR);

    // write out to a string
    String jsonString = Utility.toJSONString(stationRequestObject.toJSON());

    // check the data
    try {
      CheckData(new StationInfoRequest(Utility.fromJSONString(jsonString)), "WritesJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in WritesJSON");
    }
  }

  /** Able to read a JSON string */
  @Test
  public void readsJSON() {
    // build StationInfoRequest object
    try {
      CheckData(new StationInfoRequest(Utility.fromJSONString(STATION_STRING)), "ReadsJSON");
    } catch (ParseException e) {
      e.printStackTrace();
      Assertions.fail("exception in ReadsJSON");
    }
  }

  /** Constructor fills in members correctly */
  @Test
  public void Constructor() {
    StationInfoRequest stationRequestObject =
        new StationInfoRequest(STATION, CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR);

    // check data values
    CheckData(stationRequestObject, "Constructor");

    // use constructor
    StationInfoRequest altStationRequestObject =
        new StationInfoRequest(
            new Site(STATION, CHANNEL, NETWORK, LOCATION), new Source(AGENCYID, AUTHOR));

    // check data values
    CheckData(altStationRequestObject, "Alternate Constructor ");

    // empty constructor
    JSONObject emptyJSONObject = new JSONObject();
    StationInfoRequest emptyObject = new StationInfoRequest(emptyJSONObject);

    // check the data
    CheckData(emptyObject, "Empty Constructor");
  }

  /** Able to run validation function */
  @Test
  public void Validate() {
    StationInfoRequest stationRequestObject =
        new StationInfoRequest(STATION, CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR);

    // Successful validation
    boolean rc = stationRequestObject.isValid();

    // check return code
    Assertions.assertEquals(true, rc, "Successful Validation");

    // build bad StationInfoRequest object
    StationInfoRequest badStationRequestObject = new StationInfoRequest();

    // Unuccessful validation
    rc = badStationRequestObject.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 1");

    // build bad StationInfoRequest object
    StationInfoRequest badStationRequestObject2 =
        new StationInfoRequest("", null, "", null, "", null);

    rc = badStationRequestObject2.isValid();

    // check return code
    Assertions.assertEquals(false, rc, "Unsuccessful Validation 2");
  }

  public void CheckData(StationInfoRequest stationRequestObject, String TestName) {
    // check stationRequestObject.Site
    if (stationRequestObject.getSite() != null) {
      // check stationRequestObject.site.Station
      if (stationRequestObject.getSite().getStation() != null) {
        Assertions.assertEquals(
            STATION, stationRequestObject.getSite().getStation(), TestName + " Station Equals");
      }

      // check stationRequestObject.site.Channel
      if (stationRequestObject.getSite().getChannel() != null) {
        Assertions.assertEquals(
            CHANNEL, stationRequestObject.getSite().getChannel(), TestName + " Channel Equals");
      }

      // check stationRequestObject.site.Network
      if (stationRequestObject.getSite().getNetwork() != null) {
        Assertions.assertEquals(
            NETWORK, stationRequestObject.getSite().getNetwork(), TestName + " Network Equals");
      }

      // check stationRequestObject.site.Location
      if (stationRequestObject.getSite().getLocation() != null) {
        Assertions.assertEquals(
            LOCATION, stationRequestObject.getSite().getLocation(), TestName + " Location Equals");
      }
    }

    // check stationRequestObject.Source
    if (stationRequestObject.getSource() != null) {
      // check stationRequestObject.Source.AgencyID
      if (stationRequestObject.getSource().getAgencyID() != null) {
        Assertions.assertEquals(
            AGENCYID,
            stationRequestObject.getSource().getAgencyID(),
            TestName + " AgencyID Equals");
      }

      // check stationRequestObject.Source.Author
      if (stationRequestObject.getSource().getAuthor() != null) {
        Assertions.assertEquals(
            AUTHOR, stationRequestObject.getSource().getAuthor(), TestName + " Author Equals");
      }
    }
  }
}
