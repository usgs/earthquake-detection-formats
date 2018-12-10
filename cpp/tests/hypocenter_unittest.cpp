#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::hypocenter hypoobject, std::string testinfo) {
	// check latitude
	double hypolatitude = hypoobject.latitude;
	double expectedlatitude = LATITUDE;
	ASSERT_EQ(hypolatitude, expectedlatitude);

	// check longitude
	double hypolongitude = hypoobject.longitude;
	double expectedlongitude = LONGITUDE;
	ASSERT_EQ(hypolongitude, expectedlongitude);

	// check time
	double hypotime = hypoobject.time;
	double expectedtime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	ASSERT_EQ(hypotime, expectedtime);

	// check depth
	double hypodepth = hypoobject.depth;
	double expecteddepth = DEPTH;
	ASSERT_EQ(hypodepth, expecteddepth);

	// check latitude error
	double hypolatitudeerror = hypoobject.latitudeerror;
	double expectedlatitudeerror = LATITUDEERROR;
	ASSERT_EQ(hypolatitudeerror, expectedlatitudeerror);

	// check longitude error
	double hypolongitudeerror = hypoobject.longitudeerror;
	double expectedlongitudeerror = LONGITUDEERROR;
	ASSERT_EQ(hypolongitudeerror, expectedlongitudeerror);

	// check time error
	double hypotimeerror = hypoobject.timeerror;
	double expectedtimeerror = TIMEERROR;
	ASSERT_EQ(hypotimeerror, expectedtimeerror);

	// check depth error
	double hypodeptherror = hypoobject.deptherror;
	double expecteddeptherror = DEPTHERROR;
	ASSERT_EQ(hypodeptherror, expecteddeptherror);
}

// tests to see if hypocenter can successfully
// write json output
TEST(HypoTest, WritesJSON) {
	detectionformats::hypocenter hypoobject;

	// build hypocenter object
	hypoobject.latitude = LATITUDE;
	hypoobject.longitude = LONGITUDE;
	hypoobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	hypoobject.depth = DEPTH;
	hypoobject.latitudeerror = LATITUDEERROR;
	hypoobject.longitudeerror = LONGITUDEERROR;
	hypoobject.timeerror = TIMEERROR;
	hypoobject.deptherror = DEPTHERROR;

	// build json string
	rapidjson::Document hypodocument;
	std::string hypojson = detectionformats::ToJSONString(
			hypoobject.tojson(hypodocument, hypodocument.GetAllocator()));

	// read it back in
	rapidjson::Document hypodocument2;
	detectionformats::hypocenter hypoobject2(
			detectionformats::FromJSONString(hypojson, hypodocument2));

	// check data values
	checkdata(hypoobject2, "");
}

// tests to see if hypocenter can successfully
// read json output
TEST(HypoTest, ReadsJSON) {
	// build associated object
	rapidjson::Document hypodocument;
	detectionformats::hypocenter hypoobject(
			detectionformats::FromJSONString(std::string(HYPOSTRING),
					hypodocument));

	// check data values
	checkdata(hypoobject, "");
}

// tests to see if hypocenter can successfully
// be constructed
TEST(HypoTest, Constructor) {
	// use constructor
	detectionformats::hypocenter hypoobject(LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			DEPTH,
			LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

	// check data values
	checkdata(hypoobject, "Tested Constructor");
}

// tests to see if hypocenter can successfully
// be copy constructed
TEST(HypoTest, CopyConstructor) {
	// use constructor
	detectionformats::hypocenter fromhypoobject(LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			DEPTH,
			LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR);

	detectionformats::hypocenter hypoobject(fromhypoobject);

	// check data values
	checkdata(hypoobject, "");
}

// tests to see if hypocenter can successfully
// validate
TEST(HypoTest, Validate) {
	detectionformats::hypocenter hypoobject;

	// build hypocenter object
	hypoobject.latitude = LATITUDE;
	hypoobject.longitude = LONGITUDE;
	hypoobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	hypoobject.depth = DEPTH;
	hypoobject.latitudeerror = LATITUDEERROR;
	hypoobject.longitudeerror = LONGITUDEERROR;
	hypoobject.timeerror = TIMEERROR;
	hypoobject.deptherror = DEPTHERROR;

	// successful validation
	bool result = hypoobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad hypocenter object
	detectionformats::hypocenter badhypoobject;
	badhypoobject.latitude = std::numeric_limits<double>::quiet_NaN();

	result = false;
	try {
		// call validation
		result = badhypoobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
