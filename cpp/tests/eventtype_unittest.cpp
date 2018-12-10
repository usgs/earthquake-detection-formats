#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

// tests to see if eventtype can successfully
// write json output
TEST(EventTypeTest, WritesJSON) {
	detectionformats::eventtype eventtypeobject;

	// build eventtype object
	eventtypeobject.type = std::string(EVENTTYPE);
	eventtypeobject.certainty = std::string(CERTAINTY);

	// build json string
	rapidjson::Document eventtypedocument;
	std::string eventtypejson =
        detectionformats::ToJSONString(eventtypeobject.tojson(eventtypedocument,
            eventtypedocument.GetAllocator()));

    // read it back in
    rapidjson::Document eventtypedocument2;
    detectionformats::eventtype eventtypeobject2(detectionformats::FromJSONString(eventtypejson, // NOLINT
        eventtypedocument2));

    // check type
    std::string eventtypetype = eventtypeobject2.type;
    std::string expectedtype = std::string(EVENTTYPE);
    ASSERT_STREQ(eventtypetype.c_str(), expectedtype.c_str());

    // check certainty
    std::string eventtypecertainty = eventtypeobject2.certainty;
    std::string expectedcertainty = std::string(CERTAINTY);
    ASSERT_STREQ(eventtypecertainty.c_str(), expectedcertainty.c_str());
}

// tests to see if eventtype can successfully
// read json output
TEST(EventTypeTest, ReadsJSON) {
	// build associated object
	rapidjson::Document eventtypedocument;
	detectionformats::eventtype eventtypeobject(detectionformats::FromJSONString(std::string(EVENTTYPESTRING), eventtypedocument)); // NOLINT

	// check type
	std::string eventtypetype = eventtypeobject.type;
	std::string expectedtype = std::string(EVENTTYPE);
	ASSERT_STREQ(eventtypetype.c_str(), expectedtype.c_str());

	// check certainty
	std::string eventtypecertainty = eventtypeobject.certainty;
	std::string expectedcertainty = std::string(CERTAINTY);
	ASSERT_STREQ(eventtypecertainty.c_str(), expectedcertainty.c_str());
}

// tests to see if eventtype can successfully
// be constructed
TEST(EventTypeTest, Constructor) {
	// use constructor
	detectionformats::eventtype eventtypeobject(EVENTTYPE, CERTAINTY);

	// check type
	std::string eventtypetype = eventtypeobject.type;
	std::string expectedtype = std::string(EVENTTYPE);
	ASSERT_STREQ(eventtypetype.c_str(), expectedtype.c_str());

	// check certainty
	std::string eventtypecertainty = eventtypeobject.certainty;
	std::string expectedcertainty = std::string(CERTAINTY);
	ASSERT_STREQ(eventtypecertainty.c_str(), expectedcertainty.c_str());
}

// tests to see if eventtype can successfully
// validate
TEST(EventTypeTest, Validate) {
	detectionformats::eventtype eventtypeobject;

	// build eventtype object
	eventtypeobject.type = std::string(EVENTTYPE);
	eventtypeobject.certainty = std::string(CERTAINTY);

	// successful validation
	bool result = eventtypeobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// build bad eventtype object
	detectionformats::eventtype badeventtypeobject;
	badeventtypeobject.type = std::string(BADEVENTTYPE);

	result = false;
	try {
		// call validation
		result = badeventtypeobject.isvalid();
	}
	catch (const std::exception &) {
		// don't care
	}

	// check return code
	ASSERT_EQ(result, false) << "Tested for unsuccessful validation.";
}
