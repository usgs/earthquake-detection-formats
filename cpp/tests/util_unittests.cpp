#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

TEST(UtilTest, GetDetectionType) {
    // test successful correlation identification
    ASSERT_EQ(detectionformats::GetDetectionType(
        std::string(CORRELATIONSTRING)),
        detectionformats::formattypes::correlationtype);

	// test successful detection identification
    ASSERT_EQ(detectionformats::GetDetectionType(std::string(DETECTIONSTRING)),
        detectionformats::formattypes::detectiontype);

    // test successful pick identification
    ASSERT_EQ(detectionformats::GetDetectionType(std::string(PICKSTRING)),
        detectionformats::formattypes::picktype);

    // test successful retraction identification
    ASSERT_EQ(detectionformats::GetDetectionType(std::string(RETRACTSTRING)),
        detectionformats::formattypes::retracttype);

    // test successful stationinfo identification
    ASSERT_EQ(detectionformats::GetDetectionType(std::string(STATIONSTRING)),
        detectionformats::formattypes::stationinfotype);

    // test successful stationinforequest identification
    ASSERT_EQ(detectionformats::GetDetectionType(std::string(REQUESTSTRING)),
        detectionformats::formattypes::stationinforequesttype);

    // test unsuccessful identification 1
    ASSERT_EQ(detectionformats::GetDetectionType(std::string(BADMESSAGE)),
        detectionformats::formattypes::error);

    // test unsuccessful identification 2
    ASSERT_EQ(detectionformats::GetDetectionType(std::string(BADMESSAGE2)),
        detectionformats::formattypes::unknown);

    // test unsuccessful identification 3
    ASSERT_EQ(detectionformats::GetDetectionType(std::string("")),
        detectionformats::formattypes::error);
}

TEST(UtilTest, IsJSONValid) {
    // test invalid json
    ASSERT_EQ(detectionformats::IsJSONValid(std::string(BADMESSAGE)),
        false);

    // test valid json
    ASSERT_EQ(detectionformats::IsJSONValid(std::string(PICKSTRING)),
        true);
}

TEST(UtilTest, IsStringAlpha) {
    // success test
    ASSERT_TRUE(detectionformats::IsStringAlpha("abcdefg"));

    // failure test
    ASSERT_FALSE(detectionformats::IsStringAlpha("124abc"));

    // empty test
    ASSERT_FALSE(detectionformats::IsStringAlpha(""));
}

TEST(UtilTest, IsStringISO8601) {
    // success test
    ASSERT_TRUE(detectionformats::IsStringISO8601(std::string(TIME)));

    // failure tests
    ASSERT_FALSE(detectionformats::IsStringISO8601(std::string(EMPTYTIME)));
    ASSERT_FALSE(detectionformats::IsStringISO8601("124abc"));
    ASSERT_FALSE(detectionformats::IsStringISO8601(
        std::string(BADYEARISO8601TIME)));
    ASSERT_FALSE(detectionformats::IsStringISO8601(
        std::string(BADMONTHISO8601TIME)));
    ASSERT_FALSE(detectionformats::IsStringISO8601(
        std::string(BADDAYISO8601TIME)));
    ASSERT_FALSE(detectionformats::IsStringISO8601(
        std::string(BADHOURISO8601TIME)));
    ASSERT_FALSE(detectionformats::IsStringISO8601(
        std::string(BADMINUTEISO8601TIME)));
    ASSERT_FALSE(detectionformats::IsStringISO8601(
        std::string(BADSECONDISO8601TIME)));
    ASSERT_FALSE(detectionformats::IsStringISO8601(
        std::string(BADZISO8601TIME)));

    // empty test
    ASSERT_FALSE(detectionformats::IsStringISO8601(""));
}

TEST(UtilTest, ConvertISO8601ToEpochTime) {
    double ExpectedEpochTime = EPOCHTIME;
    double FailureTime = -1.0;

	// test ISO8601 to  epoch time conversion
	double ConvertedEpochTime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(ISO8601TIME));
	ASSERT_EQ(ConvertedEpochTime, ExpectedEpochTime);

    // failure cases
    ConvertedEpochTime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(EMPTYTIME));
	ASSERT_EQ(ConvertedEpochTime, FailureTime);

    ConvertedEpochTime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(BADISO8601TIME1));
	ASSERT_EQ(ConvertedEpochTime, FailureTime);

    ConvertedEpochTime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(BADISO8601TIME2));
	ASSERT_EQ(ConvertedEpochTime, FailureTime);
}

TEST(UtilTest, ConvertEpochTimeToISO8601) {
	std::string ExpectedISO8601 = std::string(ISO8601TIME);

	// test decimal epoch time to ISO8601 conversion
	double dEpochTime = EPOCHTIME;
	std::string ConvertedISO8601 =
			detectionformats::ConvertEpochTimeToISO8601(dEpochTime);
	ASSERT_STREQ(ConvertedISO8601.c_str(), ExpectedISO8601.c_str());

	// edge case 1
	double dEpochTime2 = EPOCHTIME2;
	ExpectedISO8601 = std::string(ISO8601TIME2);
	ConvertedISO8601 = detectionformats::ConvertEpochTimeToISO8601(
			dEpochTime2);
	ASSERT_STREQ(ConvertedISO8601.c_str(), ExpectedISO8601.c_str());

	// edge case 2
	double dEpochTime3 = EPOCHTIME3;
	ExpectedISO8601 = std::string(ISO8601TIME3);
	ConvertedISO8601 = detectionformats::ConvertEpochTimeToISO8601(
			dEpochTime3);
	ASSERT_STREQ(ConvertedISO8601.c_str(), ExpectedISO8601.c_str());

	// edge case 3
	double dEpochTime4 = EPOCHTIME4;
	ExpectedISO8601 = std::string(ISO8601TIME4);
	ConvertedISO8601 = detectionformats::ConvertEpochTimeToISO8601(
			dEpochTime4);
	ASSERT_STREQ(ConvertedISO8601.c_str(), ExpectedISO8601.c_str());
}

