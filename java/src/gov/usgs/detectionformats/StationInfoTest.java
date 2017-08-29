package gov.usgs.detectionformats;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class StationInfoTest {
	public static final String STATION_STRING = "{\"Site\":{\"Station\":\"BOZ\","
			+ "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},"
			+ "\"Enable\":true,\"Quality\":1.0,\"Type\":\"StationInfo\","
			+ "\"Elevation\":1589.0,\"UseForTeleseismic\":true,"
			+ "\"Latitude\":45.59697,\"Longitude\":-111.62967,"
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
	public static boolean USEFORTELESEISM = true;
	public static String AGENCYID = "US";
	public static String AUTHOR = "TestAuthor";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void writesJSON() {

		StationInfo stationObject = new StationInfo(STATION, CHANNEL, NETWORK,
				LOCATION, LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE,
				USEFORTELESEISM, AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(stationObject.toJSON());

		// check the data
		try {
			checkData(new StationInfo(Utility.fromJSONString(jsonString)),
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

		// build Correlation object
		try {

			checkData(new StationInfo(Utility.fromJSONString(STATION_STRING)),
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
		StationInfo stationObject = new StationInfo(
				new Site(STATION, CHANNEL, NETWORK, LOCATION), LATITUDE,
				LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM,
				new Source(AGENCYID, AUTHOR));

		// check data values
		checkData(stationObject, "Alternate Constructor 1");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		StationInfo stationObject = new StationInfo(STATION, CHANNEL, NETWORK,
				LOCATION, LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE,
				USEFORTELESEISM, AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = stationObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad StationInfo object
		StationInfo badStationObject = new StationInfo(null, CHANNEL, NETWORK,
				LOCATION, null, LONGITUDE, ELEVATION, QUALITY, ENABLE,
				USEFORTELESEISM, AGENCYID, AUTHOR);

		rc = badStationObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(StationInfo stationObject, String TestName) {

		// check stationObject.site.Station
		assertEquals(TestName + " Station Equals", STATION,
				stationObject.getSite().getStation());

		// check stationObject.site.Channel
		assertEquals(TestName + " Channel Equals", CHANNEL,
				stationObject.getSite().getChannel());

		// check stationObject.site.Network
		assertEquals(TestName + " Network Equals", NETWORK,
				stationObject.getSite().getNetwork());

		// check stationObject.site.Location
		assertEquals(TestName + " Location Equals", LOCATION,
				stationObject.getSite().getLocation());

		// check stationObject.Latitude
		assertEquals(TestName + " Latitude Equals", LATITUDE,
				stationObject.getLatitude(), 0);

		// check stationObject.Longitude
		assertEquals(TestName + " Longitude Equals", LONGITUDE,
				stationObject.getLongitude(), 0);

		// check stationObject.Depth
		assertEquals(TestName + " Elevation Equals", ELEVATION,
				stationObject.getElevation(), 0);

		// optional values
		// check hypoObject.quality
		if (stationObject.getQuality() != null) {
			assertEquals(TestName + " Quality Equals", QUALITY,
					stationObject.getQuality(), 0);
		}

		// check stationObject.enable
		if (stationObject.getEnable() != null) {
			assertEquals(TestName + " Enable Equals", ENABLE,
					stationObject.getEnable());
		}

		// check stationObject.useforteleseismic
		if (stationObject.getUseForTeleseismic() != null) {
			assertEquals(TestName + " UseForTeleseism Equals", USEFORTELESEISM,
					stationObject.getUseForTeleseismic());
		}
		// check stationObject.informationRequestor
		if (stationObject.getInformationRequestor() != null) {

			// check stationObject.InformationRequestor.AgencyID
			assertEquals(TestName + " AgencyID Equals", AGENCYID,
					stationObject.getInformationRequestor().getAgencyID());

			// check pickObject.Source.Author
			assertEquals(TestName + " Author Equals", AUTHOR,
					stationObject.getInformationRequestor().getAuthor());
		}

	}

}
