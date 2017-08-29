package gov.usgs.detectionformats;

import static org.junit.Assert.assertEquals;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class StationInfoRequestTest {
	public static final String STATION_STRING = "{\"Site\":{\"Station\":\"BOZ\","
			+ "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},"
			+ "\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},"
			+ "\"Type\":\"StationInfoRequest\",}";

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
	public void writesJSON() {

		StationInfoRequest stationRequestObject = new StationInfoRequest(
				STATION, CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(stationRequestObject.toJSON());

		// check the data
		try {
			checkData(
					new StationInfoRequest(Utility.fromJSONString(jsonString)),
					"WritesJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Able to read a JSON string
	 */
	@Test
	public void readsJSON() {

		// build StationInfoRequest object
		try {

			checkData(
					new StationInfoRequest(
							Utility.fromJSONString(STATION_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Constructor fills in members correctly
	 */
	@Test
	public void altConstructors() {

		// use constructor
		StationInfoRequest stationRequestObject = new StationInfoRequest(
				new Site(STATION, CHANNEL, NETWORK, LOCATION),
				new Source(AGENCYID, AUTHOR));

		// check data values
		checkData(stationRequestObject, "Alternate Constructor 1");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		StationInfoRequest stationRequestObject = new StationInfoRequest(
				STATION, CHANNEL, NETWORK, LOCATION, AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = stationRequestObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad StationInfoRequest object
		StationInfoRequest badStationRequestObject = new StationInfoRequest(
				null, CHANNEL, NETWORK, LOCATION, AGENCYID, null);

		rc = badStationRequestObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(StationInfoRequest stationRequestObject,
			String TestName) {

		// check stationObject.site.Station
		assertEquals(TestName + " Station Equals", STATION,
				stationRequestObject.getSite().getStation());

		// check stationObject.site.Channel
		assertEquals(TestName + " Channel Equals", CHANNEL,
				stationRequestObject.getSite().getChannel());

		// check stationObject.site.Network
		assertEquals(TestName + " Network Equals", NETWORK,
				stationRequestObject.getSite().getNetwork());

		// check stationObject.site.Location
		assertEquals(TestName + " Location Equals", LOCATION,
				stationRequestObject.getSite().getLocation());

		// check stationObject.Source.AgencyID
		assertEquals(TestName + " AgencyID Equals", AGENCYID,
				stationRequestObject.getSource().getAgencyID());

		// check stationObject.Source.Author
		assertEquals(TestName + " Author Equals", AUTHOR,
				stationRequestObject.getSource().getAuthor());

	}
}
