#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define STATIONSTRING "{\"Site\":{\"Station\":\"BOZ\",\"Channel\":\"BHZ\",\"Network\":\"US\",\"Location\":\"00\"},\"Type\":\"StationInfoRequest\",\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}}"

#define STATION "BOZ"
#define CHANNEL "BHZ"
#define NETWORK "US"
#define LOCATION "00"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"

void checkdata(detectionformats::stationInfoRequest stationrequestobject,
		std::string testinfo) {

	// check station
	std::string sitestation = stationrequestobject.site.station;
	std::string expectedstation = std::string(STATION);
	ASSERT_STREQ(sitestation.c_str(), expectedstation.c_str())<< testinfo.c_str();

	// check channel
	std::string sitechannel = stationrequestobject.site.channel;
	std::string expectedchannel = std::string(CHANNEL);
	ASSERT_STREQ(sitechannel.c_str(), expectedchannel.c_str())<< testinfo.c_str();

	// check network
	std::string sitenetwork = stationrequestobject.site.network;
	std::string expectednetwork = std::string(NETWORK);
	ASSERT_STREQ(sitenetwork.c_str(), expectednetwork.c_str())<< testinfo.c_str();

	// check location
	std::string sitelocation = stationrequestobject.site.location;
	std::string expectedlocation = std::string(LOCATION);
	ASSERT_STREQ(sitelocation.c_str(), expectedlocation.c_str())<< testinfo.c_str();

	// check agencyid
	std::string sourceagencyid = stationrequestobject.source.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str())<< testinfo.c_str();

	// check author
	std::string sourceauthor = stationrequestobject.source.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str())<< testinfo.c_str();
}

// tests to see if pick can successfully
// write json output
TEST(StationInfoRequestTest, WritesJSON) {
	detectionformats::stationInfoRequest stationrequestobject;

	// build stationInfo object
	// site subobject
	stationrequestobject.site.station = std::string(STATION);
	stationrequestobject.site.channel = std::string(CHANNEL);
	stationrequestobject.site.network = std::string(NETWORK);
	stationrequestobject.site.location = std::string(LOCATION);

	// source subobject
	stationrequestobject.source.agencyid = std::string(AGENCYID);
	stationrequestobject.source.author = std::string(AUTHOR);

	// build json string
	rapidjson::Document stationdocument;
	std::string stationrequestjson = detectionformats::ToJSONString(
			stationrequestobject.tojson(stationdocument,
					stationdocument.GetAllocator()));

	// read it back in
	rapidjson::Document stationdocument2;
	detectionformats::stationInfoRequest stationobject2(
			detectionformats::FromJSONString(stationrequestjson,
					stationdocument2));

	// check data values
	checkdata(stationobject2, "");
}

// tests to see if pick can successfully
// read json output
TEST(StationInfoRequestTest, ReadsJSON) {
	// build pick object
	rapidjson::Document stationdocument;
	detectionformats::stationInfoRequest stationrequestobject(
			detectionformats::FromJSONString(std::string(STATIONSTRING),
					stationdocument));

	// check data values
	checkdata(stationrequestobject, "");
}

// tests to see if pick can successfully
// be constructed
TEST(StationInfoRequestTest, Constructor) {
	// use constructor
	detectionformats::stationInfoRequest stationrequestobject(
			std::string(STATION), std::string(CHANNEL), std::string(NETWORK),
			std::string(LOCATION), std::string(AGENCYID), std::string(AUTHOR));

	// check data values
	checkdata(stationrequestobject, "Tested Constructor");

	// use alternate constructor
	detectionformats::stationInfoRequest stationobject_altc(
			detectionformats::site(std::string(STATION), std::string(CHANNEL),
					std::string(NETWORK), std::string(LOCATION)),
			detectionformats::source(std::string(AGENCYID),
					std::string(AUTHOR)));

	// check data values
	checkdata(stationobject_altc, "Tested alternate constructor");
}

// tests to see if pick can successfully
// be copy constructed
TEST(StationInfoRequestTest, CopyConstructor) {
	// use constructor
	detectionformats::stationInfoRequest fromstationrequestobject(
			std::string(STATION), std::string(CHANNEL), std::string(NETWORK),
			std::string(LOCATION), std::string(AGENCYID), std::string(AUTHOR));

	detectionformats::stationInfoRequest stationrequestobject(
			fromstationrequestobject);

	// check data values
	checkdata(stationrequestobject, "");
}

// tests to see if pick can successfully
// validate
TEST(StationInfoRequestTest, Validate) {
	detectionformats::stationInfoRequest stationrequestobject;

	// build pick object
	// site subobject
	stationrequestobject.site.station = std::string(STATION);
	stationrequestobject.site.channel = std::string(CHANNEL);
	stationrequestobject.site.network = std::string(NETWORK);
	stationrequestobject.site.location = std::string(LOCATION);

	// source subobject
	stationrequestobject.source.agencyid = std::string(AGENCYID);
	stationrequestobject.source.author = std::string(AUTHOR);

	bool result = stationrequestobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad pick object
	detectionformats::stationInfoRequest badstationobject;
	stationrequestobject.site.station = "";

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
