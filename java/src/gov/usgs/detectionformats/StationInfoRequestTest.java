package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class StationInfoRequestTest {
	public static final String STATION_STRING = "{\"Site\":{\"Station\":\"BOZ\","
			+ "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},"
			+ "\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},"
			+ "\"Type\":\"StationInfoRequest\"}";

	public static final String STATION = "BOZ";
	public static final String CHANNEL = "BHZ";
	public static final String NETWORK = "US";
	public static final String LOCATION = "00";
	public static String AGENCYID = "US";
	public static String AUTHOR = "TestAuthor";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
		StationInfoRequest stationRequestObject = new StationInfoRequest(
				STATION, CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(stationRequestObject.toJSON());

		// check the data
		try {
			CheckData(
					new StationInfoRequest(Utility.fromJSONString(jsonString)),
					"WritesJSON");
		} catch (ParseException e) {
			e.printStackTrace();
			fail("exception in WritesJSON");
		}
	}

	/**
	 * Able to read a JSON string
	 */
	@Test
	public void readsJSON() {
		// build StationInfoRequest object
		try {
			CheckData(
					new StationInfoRequest(
							Utility.fromJSONString(STATION_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
			fail("exception in ReadsJSON");
		}
	}

	/**
	 * Constructor fills in members correctly
	 */
	@Test
	public void Constructor() {
		StationInfoRequest stationRequestObject = new StationInfoRequest(
				STATION, CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR);

		// check data values
		CheckData(stationRequestObject, "Constructor");

		// use constructor
		StationInfoRequest altStationRequestObject = new StationInfoRequest(
				new Site(STATION, CHANNEL, NETWORK, LOCATION),
				new Source(AGENCYID, AUTHOR));

		// check data values
		CheckData(altStationRequestObject, "Alternate Constructor ");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		StationInfoRequest emptyObject = new StationInfoRequest(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");	
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		StationInfoRequest stationRequestObject = new StationInfoRequest(
				STATION, CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = stationRequestObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad StationInfoRequest object
		StationInfoRequest badStationRequestObject = new StationInfoRequest();

		// Unuccessful validation
		rc = badStationRequestObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 1", false, rc);

		// build bad StationInfoRequest object
		StationInfoRequest badStationRequestObject2 = new StationInfoRequest(
				"", null, "", null, "", null);

		rc = badStationRequestObject2.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 2", false, rc);
	}

	public void CheckData(StationInfoRequest stationRequestObject,
			String TestName) {
		// check stationRequestObject.Site
		if (stationRequestObject.getSite() != null) {
			// check stationRequestObject.site.Station
			if (stationRequestObject.getSite().getStation() != null) {
				assertEquals(TestName + " Station Equals", STATION,
					stationRequestObject.getSite().getStation());
			}

			// check stationRequestObject.site.Channel
			if (stationRequestObject.getSite().getChannel() != null) {
				assertEquals(TestName + " Channel Equals", CHANNEL,
					stationRequestObject.getSite().getChannel());
			}

			// check stationRequestObject.site.Network
			if (stationRequestObject.getSite().getNetwork() != null) {
				assertEquals(TestName + " Network Equals", NETWORK,
					stationRequestObject.getSite().getNetwork());
			}

			// check stationRequestObject.site.Location
			if (stationRequestObject.getSite().getLocation() != null) {
				assertEquals(TestName + " Location Equals", LOCATION,
					stationRequestObject.getSite().getLocation());
			}
		}

		// check stationRequestObject.Source
		if (stationRequestObject.getSource() != null) {
			// check stationRequestObject.Source.AgencyID
			if (stationRequestObject.getSource().getAgencyID() != null) {
				assertEquals(TestName + " AgencyID Equals", AGENCYID,
					stationRequestObject.getSource().getAgencyID());
			}

			// check stationRequestObject.Source.Author
			if (stationRequestObject.getSource().getAuthor() != null) {
				assertEquals(TestName + " Author Equals", AUTHOR,
					stationRequestObject.getSource().getAuthor());
			}
		}
	}
}
