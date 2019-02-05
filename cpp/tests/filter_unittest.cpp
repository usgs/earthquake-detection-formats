#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::filter filterobject, std::string testinfo) {
	// check type
	if (filterobject.type.empty() != true) {
		std::string filtertype = filterobject.type;
		std::string expectedtype = std::string(FILTERTYPE);
		ASSERT_STREQ(filtertype.c_str(), expectedtype.c_str());
	}

	// check lowpass
	if (std::isnan(filterobject.lowpass) != true) {
		double filterlowpass = filterobject.lowpass;
		double expectedlowpass = LOWPASS;
		ASSERT_EQ(filterlowpass, expectedlowpass);
	}

	// check highpass
	if (std::isnan(filterobject.highpass) != true) {
		double filterhighpass = filterobject.highpass;
		double expectedhighpass = HIGHPASS;
		ASSERT_EQ(filterhighpass, expectedhighpass);
	}

	// check units
	if (filterobject.units.empty() != true) {
		std::string filterunits = filterobject.units;
		std::string expectedunits = std::string(FILTERUNITS);
		ASSERT_STREQ(filterunits.c_str(), expectedunits.c_str());
	}
}

// tests to see if filter can successfully
// write json output
TEST(FilterTest, WritesJSON) {
	detectionformats::filter filterobject;

	// build filter object
	filterobject.type = std::string(FILTERTYPE);
	filterobject.highpass = HIGHPASS;
	filterobject.lowpass = LOWPASS;
	filterobject.units = std::string(FILTERUNITS);

	// build json string
	rapidjson::Document filterdocument;
	std::string filterjson = detectionformats::ToJSONString(
		filterobject.tojson(filterdocument, filterdocument.GetAllocator()));

    // read it back in
    rapidjson::Document filterdocument2;
    detectionformats::filter filterobject2(detectionformats::FromJSONString(
		filterjson, filterdocument2));

    // check data values
    checkdata(filterobject2, "");
}

// tests to see if filter can successfully
// read json output
TEST(FilterTest, ReadsJSON) {
	// build filter object
	rapidjson::Document filterdocument;
	detectionformats::filter filterobject(detectionformats::FromJSONString(
		std::string(FILTERSTRING), filterdocument));

	// check data values
	checkdata(filterobject, "");
}

// tests to see if filter can successfully
// be constructed
TEST(FilterTest, Constructor) {
	// use constructor
	detectionformats::filter filterobject(FILTERTYPE, HIGHPASS, LOWPASS,
		FILTERUNITS);

	// check data values
	checkdata(filterobject, "");

	// json constructor (empty)
    rapidjson::Value emptyvalue(rapidjson::kObjectType);
    detectionformats::filter filterobject2(emptyvalue);

    // check data values
	checkdata(filterobject2, "");
}

// tests to see if filter can successfully
// be copied
TEST(FilterTest, CopyConstructor) {
	// use constructor
	detectionformats::filter filterobject(FILTERTYPE, HIGHPASS, LOWPASS,
		FILTERUNITS);

	// copy constructor
    detectionformats::filter filterobject2(filterobject);

    // check data values
	checkdata(filterobject2, "");
}

// tests to see if filter can successfully
// validate
TEST(FilterTest, Validate) {
	detectionformats::filter filterobject;

	// build filter object
	filterobject.type = std::string(FILTERTYPE);
	filterobject.highpass = HIGHPASS;
	filterobject.lowpass = LOWPASS;
	filterobject.units = std::string(FILTERUNITS);

	// successful validation
	bool result = filterobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// Can't think of a way to make a bad filter object
}

// tests the isempty function
TEST(FilterTest, IsEmpty) {
	detectionformats::filter filterobject;

	// check return
	ASSERT_TRUE(filterobject.isempty()) << "Tested for empty.";

	// build filter object
	filterobject.highpass = HIGHPASS;

	// check return
	ASSERT_FALSE(filterobject.isempty()) << "Tested for not empty.";
}
