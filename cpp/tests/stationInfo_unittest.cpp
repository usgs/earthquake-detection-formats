#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define STATIONSTRING "{\"Site\":{\"Station\":\"BOZ\",\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},\"Enable\":true,\"Quality\":1.0,\"Type\":\"StationInfo\",\"Elevation\":1589.0,\"UseForTeleseismic\":true,\"Latitude\":45.59697,\"Longitude\":-111.62967,\"InformationRequestor\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}}"

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
#define AGENCYID "US"
#define AUTHOR "TestAuthor"

void checkdata(detectionformats::stationInfo stationobject,
		std::string testinfo) {

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

	// check informationRequestor
	if (stationobject.informationRequestor.isempty() != true) {

		// check agencyid
		std::string sourceagencyid = stationobject.informationRequestor.agencyid;
		std::string expectedagencyid = std::string(AGENCYID);
		ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str())<< testinfo.c_str();

		// check author
		std::string sourceauthor = stationobject.informationRequestor.author;
		std::string expectedauthor = std::string(AUTHOR);
		ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str())<< testinfo.c_str();

	}
}

// tests to see if pick can successfully
// write json output
TEST(StationInfoTest, WritesJSON) {
	detectionformats::stationInfo stationobject;

	// build stationInfo object
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

	// source informationRequestor
	stationobject.informationRequestor.agencyid = std::string(AGENCYID);
	stationobject.informationRequestor.author = std::string(AUTHOR);

	// build json string
	rapidjson::Document stationdocument;
	std::string pickjson = detectionformats::ToJSONString(
			stationobject.tojson(stationdocument,
					stationdocument.GetAllocator()));

	// read it back in
	rapidjson::Document stationdocument2;
	detectionformats::stationInfo stationobject2(
			detectionformats::FromJSONString(pickjson, stationdocument2));

	// check data values
	checkdata(stationobject2, "");
}

// tests to see if pick can successfully
// read json output
TEST(StationInfoTest, ReadsJSON) {
	// build pick object
	rapidjson::Document stationdocument;
	detectionformats::stationInfo stationobject(
			detectionformats::FromJSONString(std::string(STATIONSTRING),
					stationdocument));

	// check data values
	checkdata(stationobject, "");
}

// tests to see if pick can successfully
// be constructed
TEST(StationInfoTest, Constructor) {
	// use constructor
	detectionformats::stationInfo stationobject(std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM,
			std::string(AGENCYID), std::string(AUTHOR));

	// check data values
	checkdata(stationobject, "Tested Constructor");

	// use constructor
	detectionformats::stationInfo stationobject2(std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM,
			"", "");

	// check data values
	checkdata(stationobject2, "Tested Constructor (without informationRequestor");

	// use alternate constructor
	detectionformats::stationInfo stationobject_altc(
			detectionformats::site(std::string(STATION), std::string(CHANNEL),
					std::string(NETWORK), std::string(LOCATION)),
			LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM,
			detectionformats::source(std::string(AGENCYID),
					std::string(AUTHOR)));

	// check data values
	checkdata(stationobject_altc, "Tested alternate constructor");
}

// tests to see if pick can successfully
// be copy constructed
TEST(StationInfoTest, CopyConstructor) {
	// use constructor
	detectionformats::stationInfo fromstationobject(std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			LATITUDE, LONGITUDE, ELEVATION, QUALITY, ENABLE, USEFORTELESEISM,
			std::string(AGENCYID), std::string(AUTHOR));

	detectionformats::stationInfo stationobject(fromstationobject);

	// check data values
	checkdata(stationobject, "");
}

// tests to see if pick can successfully
// validate
TEST(StationInfoTest, Validate) {
	detectionformats::stationInfo stationobject;

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
	ASSERT_EQ(result, true)<< "Tested for successful validation (Without informationRequestor).";

	// source informationRequestor
	stationobject.informationRequestor.agencyid = std::string(AGENCYID);
	stationobject.informationRequestor.author = std::string(AUTHOR);

	result = false;
	result = stationobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation (With informationRequestor).";

	// build bad pick object
	detectionformats::stationInfo badstationobject;
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
