package gov.usgs.detectionformats;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class StationTest {
	public static final String STATION_STRING = "{\"Site\":{\"Station\":\"BOZ\","
			+ "\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},"
			+ "\"Enable\":true,\"Quality\":1.0,\"Type\":\"Station\","
			+ "\"Elevation\":1589.0,\"UseForTeleseismic\":true,"
			+ "\"Latitude\":45.59697,\"Longitude\":-111.62967}";

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

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void writesJSON() {

		Station stationObject = new Station(STATION, CHANNEL, NETWORK, LOCATION,
				LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE,
				USEFORTELESEISM);

		// write out to a string
		String jsonString = Utility.toJSONString(stationObject.toJSON());

		// check the data
		try {
			checkData(new Station(Utility.fromJSONString(jsonString)),
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

			checkData(new Station(Utility.fromJSONString(STATION_STRING)),
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
		Station stationObject = new Station(
				new Site(STATION, CHANNEL, NETWORK, LOCATION), LATITUDE,
				LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM);

		// check data values
		checkData(stationObject, "Alternate Constructor 1");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		Station stationObject = new Station(STATION, CHANNEL, NETWORK, LOCATION,
				LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE,
				USEFORTELESEISM);

		// Successful validation
		boolean rc = stationObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Station object
		Station badStationObject = new Station(null, CHANNEL, NETWORK, LOCATION,
				null, LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM);

		rc = badStationObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(Station stationObject, String TestName) {

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
	}

}