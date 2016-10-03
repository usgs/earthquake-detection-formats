#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define FILTERSTRING "{\"HighPass\":1.05,\"LowPass\":2.65}"
#define HIGHPASS 1.05
#define LOWPASS 2.65

void checkdata(detectionformats::filter filterobject, std::string testinfo)
{
	// check lowpass
	double filterlowpass = filterobject.lowpass;
	double expectedlowpass = LOWPASS;
	ASSERT_EQ(filterlowpass, expectedlowpass);

	// check highpass
	double filterhighpass = filterobject.highpass;
	double expectedhighpass = HIGHPASS;
	ASSERT_EQ(filterhighpass, expectedhighpass);
}

// tests to see if filter can successfully
// write json output
TEST(FilterTest, WritesJSON)
{
	detectionformats::filter filterobject;

	// build filter object
	filterobject.highpass = HIGHPASS;
	filterobject.lowpass = LOWPASS;

	// build json string
	rapidjson::Document filterdocument;
	std::string filterjson = detectionformats::ToJSONString(filterobject.tojson(filterdocument, filterdocument.GetAllocator()));

    // read it back in
    rapidjson::Document filterdocument2;
    detectionformats::filter filterobject2(detectionformats::FromJSONString(filterjson, filterdocument2));
    
    // check data values
    checkdata(filterobject2, "");
}

// tests to see if filter can successfully
// read json output
TEST(FilterTest, ReadsJSON)
{
	// build filter object
	rapidjson::Document filterdocument;
	detectionformats::filter filterobject(detectionformats::FromJSONString(std::string(FILTERSTRING), filterdocument));

	// check data values
	checkdata(filterobject, "");
}

// tests to see if filter can successfully
// be constructed
TEST(FilterTest, Constructor)
{
	// use constructor
	detectionformats::filter filterobject(HIGHPASS, LOWPASS);

	// check data values
	checkdata(filterobject, "");
}

// tests to see if filter can successfully
// validate
TEST(FilterTest, Validate)
{
	detectionformats::filter filterobject;

	// build filter object
	filterobject.highpass = HIGHPASS;
	filterobject.lowpass = LOWPASS;

	// successful validation
	bool result = filterobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// Can't think of a way to make a bad filter object
}