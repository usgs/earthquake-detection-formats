#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define STATIONSTRING "{\"Site\":{\"Station\":\"BOZ\",\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},\"Enable\":true,\"Quality\":1.0,\"Type\":\"Station\",\"Elevation\":1589.0,\"UseForTeleseismic\":true,\"Latitude\":45.59697,\"Longitude\":-111.62967}"

#define STATION "BOZ"
#define CHANNEL "BHZ"
#define NETWORK "US"
#define LOCATION "00"
#define LATITUDE 45.596970
#define LONGITUDE -111.629670
#define ELEVATION 1589.000000
#define QUALITY 1.0
#define ENABLE true
#define USEFORTELESEISM true

void checkdata(detectionformats::station stationobject, std::string testinfo) {

	// check station
	std::string sitestation = stationobject.site.station;
	std::string expectedstation = std::string(STATION);
	ASSERT_STREQ(sitestation.c_str(), expectedstation.c_str())<< testinfo.c_str();

	// check channel
	std::string sitechannel = stationobject.site.channel;
	std::string expectedchannel = std::string(CHANNEL);
	ASSERT_STREQ(sitechannel.c_str(), expectedchannel.c_str())<< testinfo.c_str();

	// check network
	std::string sitenetwork = stationobject.site.network;
	std::string expectednetwork = std::string(NETWORK);
	ASSERT_STREQ(sitenetwork.c_str(), expectednetwork.c_str())<< testinfo.c_str();

	// check location
	std::string sitelocation = stationobject.site.location;
	std::string expectedlocation = std::string(LOCATION);
	ASSERT_STREQ(sitelocation.c_str(), expectedlocation.c_str())<< testinfo.c_str();

	// check latitude
	double stationlatitude = stationobject.latitude;
	double expectedlatitude = LATITUDE;
	ASSERT_EQ(stationlatitude, expectedlatitude);

	// check longitude
	double stationlongitude = stationobject.longitude;
	double expectedlongitude = LONGITUDE;
	ASSERT_EQ(stationlongitude, expectedlongitude);

	// check elevation
	double stationelevation = stationobject.elevation;
	double expectedelevation = ELEVATION;
	ASSERT_EQ(stationelevation, expectedelevation);

	// check quality
	if (std::isnan(stationobject.quality) != true) {
		double stationquality = stationobject.quality;
		double expectedquality = QUALITY;
		ASSERT_EQ(stationquality, expectedquality)<< testinfo.c_str();
	}

	// check enable
	bool stationenabled = stationobject.enable;
	bool expectedenabled = ENABLE;
	ASSERT_EQ(stationenabled, expectedenabled);

	// check useforteleseismic
	bool stationuseforteleseismic = stationobject.useforteleseismic;
	bool expecteduseforteleseismic = USEFORTELESEISM;
	ASSERT_EQ(stationuseforteleseismic, expecteduseforteleseismic);
}

// tests to see if pick can successfully
// write json output
TEST(StationTest, WritesJSON) {
	detectionformats::station stationobject;

	// build station object
	// site subobject
	stationobject.site.station = std::string(STATION);
	stationobject.site.channel = std::string(CHANNEL);
	stationobject.site.network = std::string(NETWORK);
	stationobject.site.location = std::string(LOCATION);

	stationobject.latitude = LATITUDE;
	stationobject.longitude = LONGITUDE;
	stationobject.elevation = ELEVATION;

	stationobject.quality = QUALITY;
	stationobject.enable = ENABLE;
	stationobject.useforteleseismic = USEFORTELESEISM;

	// build json string
	rapidjson::Document stationdocument;
	std::string pickjson = detectionformats::ToJSONString(
			stationobject.tojson(stationdocument,
					stationdocument.GetAllocator()));

	// read it back in
	rapidjson::Document stationdocument2;
	detectionformats::station stationobject2(
			detectionformats::FromJSONString(pickjson, stationdocument2));

	// check data values
	checkdata(stationobject2, "");
}

// tests to see if pick can successfully
// read json output
TEST(StationTest, ReadsJSON) {
	// build pick object
	rapidjson::Document stationdocument;
	detectionformats::station stationobject(
			detectionformats::FromJSONString(std::string(STATIONSTRING),
					stationdocument));

	// check data values
	checkdata(stationobject, "");
}

// tests to see if pick can successfully
// be constructed
TEST(StationTest, Constructor) {
	// use constructor
	detectionformats::station stationobject(std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM);

	// check data values
	checkdata(stationobject, "Tested Constructor");

	// use alternate constructor
	detectionformats::station stationobject_altc(
			detectionformats::site(std::string(STATION), std::string(CHANNEL),
					std::string(NETWORK), std::string(LOCATION)),
			LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM);

	// check data values
	checkdata(stationobject_altc, "Tested alternate constructor");
}

// tests to see if pick can successfully
// be copy constructed
TEST(StationTest, CopyConstructor) {
	// use constructor
	detectionformats::station fromstationobject(std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM);

	detectionformats::station stationobject(fromstationobject);

	// check data values
	checkdata(stationobject, "");
}

// tests to see if pick can successfully
// validate
TEST(StationTest, Validate) {
	detectionformats::station stationobject;

	// build pick object
	// site subobject
	stationobject.site.station = std::string(STATION);
	stationobject.site.channel = std::string(CHANNEL);
	stationobject.site.network = std::string(NETWORK);
	stationobject.site.location = std::string(LOCATION);

	stationobject.latitude = LATITUDE;
	stationobject.longitude = LONGITUDE;
	stationobject.elevation = ELEVATION;

	stationobject.quality = QUALITY;
	stationobject.enable = ENABLE;
	stationobject.useforteleseismic = USEFORTELESEISM;

	// successful validation
	bool result = stationobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad pick object
	detectionformats::station badstationobject;
	stationobject.site.station = "";

	result = false;
	try {
		// call validation
		result = badstationobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
