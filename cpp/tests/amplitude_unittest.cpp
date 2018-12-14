#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::amplitude amplitudeobject,
	std::string testinfo)
{
	// check period
	double amplitudeperiod = amplitudeobject.period;
	double expectedperiod = PERIOD;
	ASSERT_EQ(amplitudeperiod, expectedperiod);

	// check amplitude
	double amplitudeamplitude = amplitudeobject.ampvalue;
	double expectedamplitude = AMPLITUDEVALUE;
	ASSERT_EQ(amplitudeamplitude, expectedamplitude);

	// check snr
	double amplitudesnr = amplitudeobject.snr;
	double expectedsnr = SNR;
	ASSERT_EQ(amplitudesnr, expectedsnr);
}

// tests to see if amplitude can successfully
// write json output
TEST(AmplitudeTest, WritesJSON)
{
	detectionformats::amplitude amplitudeobject;

	// build amplitude object
	amplitudeobject.ampvalue = AMPLITUDEVALUE;
	amplitudeobject.period = PERIOD;
	amplitudeobject.snr = SNR;

	// build json string
	rapidjson::Document amplitudedocument;
	std::string amplitudejson = detectionformats::ToJSONString(
		amplitudeobject.tojson(amplitudedocument,
		amplitudedocument.GetAllocator()));

    // read it back in
    rapidjson::Document amplitudedocument2;
    detectionformats::amplitude amplitudeobject2(
		detectionformats::FromJSONString(amplitudejson, amplitudedocument2));

    // check data values
    checkdata(amplitudeobject2, "");
}

// tests to see if amplitude can successfully
// read json output
TEST(AmplitudeTest, ReadsJSON) {
	// build amplitude object
	rapidjson::Document amplitudedocument;
	detectionformats::amplitude amplitudeobject(
			detectionformats::FromJSONString(std::string(AMPLITUDESTRING),
			amplitudedocument));

	// check data values
	checkdata(amplitudeobject, "");
}

// tests to see if amplitude can successfully
// be constructed
TEST(AmplitudeTest, Constructor) {
	// use constructor
	detectionformats::amplitude amplitudeobject(AMPLITUDEVALUE, PERIOD, SNR);

	// check data values
	checkdata(amplitudeobject, "");
}

// tests to see if amplitude can successfully
// validate
TEST(AmplitudeTest, Validate) {
	detectionformats::amplitude amplitudeobject;

	// build amplitude object
	amplitudeobject.ampvalue = AMPLITUDEVALUE;
	amplitudeobject.period = PERIOD;
	amplitudeobject.snr = SNR;

	// successful validation
	bool result = amplitudeobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// Can't think of a way to make a bad amplitude object
}

// tests the isempty function
TEST(AmplitudeTest, IsEmpty) {
	detectionformats::amplitude amplitudeobject;

	// check return
	ASSERT_TRUE(amplitudeobject.isempty()) << "Tested for empty.";

	// build amplitude object
	amplitudeobject.ampvalue = AMPLITUDEVALUE;

	// check return
	ASSERT_FALSE(amplitudeobject.isempty()) << "Tested for not empty.";
}
