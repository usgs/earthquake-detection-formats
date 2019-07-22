#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::site siteobject, std::string testinfo) {
	// check station
	std::string sitestation = siteobject.station;
	std::string expectedstation = std::string(STATION);
	ASSERT_STREQ(sitestation.c_str(), expectedstation.c_str());

	// check channel
	std::string sitechannel = siteobject.channel;
	std::string expectedchannel = std::string(CHANNEL);
	ASSERT_STREQ(sitechannel.c_str(), expectedchannel.c_str());

	// check network
	std::string sitenetwork = siteobject.network;
	std::string expectednetwork = std::string(NETWORK);
	ASSERT_STREQ(sitenetwork.c_str(), expectednetwork.c_str());

	// check location
	std::string sitelocation = siteobject.location;
	std::string expectedlocation = std::string(LOCATION);
	ASSERT_STREQ(sitelocation.c_str(), expectedlocation.c_str());

	// check latitude
	if (std::isnan(siteobject.latitude) != true) {
		double stationlatitude = siteobject.latitude;
		double expectedlatitude = LATITUDE;
		ASSERT_EQ(stationlatitude, expectedlatitude);
	}

	// check longitude
	if (std::isnan(siteobject.longitude) != true) {
		double stationlongitude = siteobject.longitude;
		double expectedlongitude = LONGITUDE;
		ASSERT_EQ(stationlongitude, expectedlongitude);
	}

	// check elevation
	if (std::isnan(siteobject.elevation) != true) {
		double stationelevation = siteobject.elevation;
		double expectedelevation = ELEVATION;
		ASSERT_EQ(stationelevation, expectedelevation);
	}
}

// tests to see if site can successfully
// write json output
TEST(SiteTest, WritesJSON) {
	detectionformats::site siteobject;

	// build site object
	siteobject.station = std::string(STATION);
	siteobject.channel = std::string(CHANNEL);
	siteobject.network = std::string(NETWORK);
	siteobject.location = std::string(LOCATION);

	siteobject.latitude = LATITUDE;
	siteobject.longitude = LONGITUDE;
	siteobject.elevation = ELEVATION;

	// build json string
	rapidjson::Document sitedocument;
	std::string sitejson = detectionformats::ToJSONString(
			siteobject.tojson(sitedocument, sitedocument.GetAllocator()));

	// read it back in
	rapidjson::Document sitedocument2;
	detectionformats::site siteobject2(
			detectionformats::FromJSONString(sitejson, sitedocument2));

	// check data values
	checkdata(siteobject2, "");
}

// tests to see if site can successfully
// read json output
TEST(SiteTest, ReadsJSON) {
	// build site object
	rapidjson::Document sitedocument;
	detectionformats::site siteobject(
			detectionformats::FromJSONString(std::string(SITESTRING),
					sitedocument));

	// check data values
	checkdata(siteobject, "");
}

// tests to see if site can successfully
// be constructed
TEST(SiteTest, Constructor) {
	// use constructor
	detectionformats::site siteobject(STATION, CHANNEL, NETWORK, LOCATION);

	// check data values
	checkdata(siteobject, "");

	// use constructor
	detectionformats::site siteobject2(STATION, CHANNEL, NETWORK, LOCATION,
			LATITUDE, LONGITUDE, ELEVATION);

	// check data values
	checkdata(siteobject2, "");
}

// tests to see if site can successfully
// validate
TEST(SiteTest, Validate) {
	detectionformats::site siteobject;

	// build site object
	siteobject.station = std::string(STATION);
	siteobject.channel = std::string(CHANNEL);
	siteobject.network = std::string(NETWORK);
	siteobject.location = std::string(LOCATION);
	siteobject.latitude = LATITUDE;
	siteobject.longitude = LONGITUDE;
	siteobject.elevation = ELEVATION;

	// successful validation
	bool result = siteobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad site object
	detectionformats::site badsiteobject;
	badsiteobject.location = std::string(LOCATION);

	result = false;
	try {
		// call validation
		result = badsiteobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
