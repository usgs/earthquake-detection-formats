#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

// tests to see if filter can successfully
// write json output
TEST(DetectionFormatsTest, ValidateJSON) {
	// test successful correlation validation
    ASSERT_EQ(detectionformats::ValidateJSON(std::string(CORRELATIONSTRING)),
        true);

	// test successful detection validation
    ASSERT_EQ(detectionformats::ValidateJSON(std::string(DETECTIONSTRING)),
        true);

    // test successful pick validation
    ASSERT_EQ(detectionformats::ValidateJSON(std::string(PICKSTRING)), true);

    // test successful retraction validation
    ASSERT_EQ(detectionformats::ValidateJSON(std::string(RETRACTSTRING)), true);

    // test successful stationinfo validation
    ASSERT_EQ(detectionformats::ValidateJSON(std::string(STATIONSTRING)), true);

    // test successful stationinforequest validation
    ASSERT_EQ(detectionformats::ValidateJSON(std::string(REQUESTSTRING)), true);

    // test unsuccessful validation 1
    ASSERT_EQ(detectionformats::ValidateJSON(std::string(BADMESSAGE)), false);

    // test unsuccessful validation 2
    ASSERT_EQ(detectionformats::ValidateJSON(std::string(BADMESSAGE2)), false);
}