#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::hypocenter hypoobject, std::string testinfo) {
	// check latitude
	if (std::isnan(hypoobject.latitude) != true) {
		double hypolatitude = hypoobject.latitude;
		double expectedlatitude = LATITUDE;
		ASSERT_EQ(hypolatitude, expectedlatitude);
	}

	// check longitude
	if (std::isnan(hypoobject.longitude) != true) {
		double hypolongitude = hypoobject.longitude;
		double expectedlongitude = LONGITUDE;
		ASSERT_EQ(hypolongitude, expectedlongitude);
	}

	// check time
	if (std::isnan(hypoobject.time) != true) {
		double hypotime = hypoobject.time;
		double expectedtime = detectionformats::ConvertISO8601ToEpochTime(
				std::string(TIME));
		ASSERT_EQ(hypotime, expectedtime);
	}

	// check depth
	if (std::isnan(hypoobject.depth) != true) {
		double hypodepth = hypoobject.depth;
		double expecteddepth = DEPTH;
		ASSERT_EQ(hypodepth, expecteddepth);
	}

	// check latitude error
	if (std::isnan(hypoobject.latitudeerror) != true) {
		double hypolatitudeerror = hypoobject.latitudeerror;
		double expectedlatitudeerror = LATITUDEERROR;
		ASSERT_EQ(hypolatitudeerror, expectedlatitudeerror);
	}

	// check longitude error
	if (std::isnan(hypoobject.longitudeerror) != true) {
		double hypolongitudeerror = hypoobject.longitudeerror;
		double expectedlongitudeerror = LONGITUDEERROR;
		ASSERT_EQ(hypolongitudeerror, expectedlongitudeerror);
	}

	// check time error
	if (std::isnan(hypoobject.timeerror) != true) {
		double hypotimeerror = hypoobject.timeerror;
		double expectedtimeerror = TIMEERROR;
		ASSERT_EQ(hypotimeerror, expectedtimeerror);
	}

	// check depth error
	if (std::isnan(hypoobject.deptherror) != true) {
		double hypodeptherror = hypoobject.deptherror;
		double expecteddeptherror = DEPTHERROR;
		ASSERT_EQ(hypodeptherror, expecteddeptherror);
	}
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

	// json constructor (empty)
    rapidjson::Value emptyvalue(rapidjson::kObjectType);
    detectionformats::hypocenter hypoobject2(emptyvalue);

    // check data values
	checkdata(hypoobject2, "");
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

	result = false;
	try {
		// call validation
		result = badhypoobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";

	// build bad hypocenter object
	detectionformats::hypocenter badhypoobject2;
	badhypoobject2.latitude = 999;
	badhypoobject2.longitude = -999;
	badhypoobject2.time = -10000000000000000;
	badhypoobject2.depth = -1000;

	result = false;
	try {
		// call validation
		result = badhypoobject2.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";

}
