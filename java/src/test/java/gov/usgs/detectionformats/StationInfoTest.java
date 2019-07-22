package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class StationInfoTest {
	public static final String STATION_STRING = "{\"Site\":{\"Station\":\"BOZ\","
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

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
		StationInfo stationObject = new StationInfo(STATION, CHANNEL, NETWORK,
				LOCATION, LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE,
				USE, USEFORTELESEISM, AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(stationObject.toJSON());

		// check the data
		try {
			CheckData(new StationInfo(Utility.fromJSONString(jsonString)),
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
	public void ReadsJSON() {
		// build StationInfo object
		try {
			CheckData(new StationInfo(Utility.fromJSONString(STATION_STRING)),
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
		// use constructor
		StationInfo stationObject = new StationInfo(STATION, CHANNEL, NETWORK,
			LOCATION, LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE,
			USE, USEFORTELESEISM, AGENCYID, AUTHOR);

		// check data values
		CheckData(stationObject, "Constructor");

		// use constructor
		StationInfo altStationObject = new StationInfo(
			new Site(STATION, CHANNEL, NETWORK, LOCATION, LATITUDE, LONGITUDE, 
				ELEVATION), QUALITY, ENABLE, USE, USEFORTELESEISM,
			new Source(AGENCYID, AUTHOR));

		// check data values
		CheckData(altStationObject, "Alternate Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		StationInfo emptyObject = new StationInfo(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");	
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		StationInfo stationObject = new StationInfo(STATION, CHANNEL, NETWORK,
				LOCATION, LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE, USE,
				USEFORTELESEISM, AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = stationObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad StationInfo object
		StationInfo badStationInfoObject = new StationInfo();

		// Unsuccessful validation
		rc = badStationInfoObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation 1", false, rc);

		// build bad StationInfo object
		StationInfo badStationInfoObject2 = new StationInfo("", null, "",
				null, -9999.0, 9999.0, 1000000.0, null, null, null,
				null, "", "");

		rc = badStationInfoObject2.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void CheckData(StationInfo stationObject, String TestName) {
		// check stationObject.Site
		if (stationObject.getSite() != null) {
			// check stationObject.site.Station
			if (stationObject.getSite().getStation() != null) {
				assertEquals(TestName + " Station Equals", STATION,
					stationObject.getSite().getStation());
			}

			// check stationObject.site.Channel
			if (stationObject.getSite().getChannel() != null) {
				assertEquals(TestName + " Channel Equals", CHANNEL,
					stationObject.getSite().getChannel());
			}

			// check stationObject.site.Network
			if (stationObject.getSite().getNetwork() != null) {
				assertEquals(TestName + " Network Equals", NETWORK,
					stationObject.getSite().getNetwork());
			}

			// check stationObject.site.Location
			if (stationObject.getSite().getLocation() != null) {
				assertEquals(TestName + " Location Equals", LOCATION,
					stationObject.getSite().getLocation());
			}

			// check stationObject.site.Latitude
			if (stationObject.getSite().getLatitude() != null) {
				assertEquals(TestName + " Latitude Equals", LATITUDE,
					stationObject.getSite().getLatitude(), 0);
			}

			// check stationObject.site.Longitude
			if (stationObject.getSite().getLongitude() != null) {
				assertEquals(TestName + " Longitude Equals", LONGITUDE,
					stationObject.getSite().getLongitude(), 0);
			}

			// check stationObject.site.Elevation
			if (stationObject.getSite().getElevation() != null) {
				assertEquals(TestName + " Elevation Equals", ELEVATION,
					stationObject.getSite().getElevation(), 0);
			}
		}

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

		// check stationObject.use
		if (stationObject.getUse() != null) {
			assertEquals(TestName + " Use Equals", USE,
					stationObject.getUse());
		}

		// check stationObject.useforteleseismic
		if (stationObject.getUseForTeleseismic() != null) {
			assertEquals(TestName + " UseForTeleseism Equals", USEFORTELESEISM,
					stationObject.getUseForTeleseismic());
		}
		// check stationObject.informationRequestor
		// check stationObject.Source
		if (stationObject.getInformationRequestor() != null) {
			// check stationObject.InformationRequestor.AgencyID
			if (stationObject.getInformationRequestor().getAgencyID() != null) {
				assertEquals(TestName + " AgencyID Equals", AGENCYID,
					stationObject.getInformationRequestor().getAgencyID());
			}

			// check stationObject.InformationRequestor.Author
			if (stationObject.getInformationRequestor().getAuthor() != null) {
				assertEquals(TestName + " Author Equals", AUTHOR,
					stationObject.getInformationRequestor().getAuthor());
			}
		}		
	}
}
