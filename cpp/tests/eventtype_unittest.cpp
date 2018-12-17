#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::eventtype eventtypeobject,
	std::string testinfo) {
    // check type
	if (eventtypeobject.type.empty() != true) {
		std::string eventtypetype = eventtypeobject.type;
		std::string expectedtype = std::string(EVENTTYPE);
		ASSERT_STREQ(eventtypetype.c_str(), expectedtype.c_str());
	}

    // check certainty
	if (eventtypeobject.certainty.empty() != true) {
		std::string eventtypecertainty = eventtypeobject.certainty;
		std::string expectedcertainty = std::string(CERTAINTY);
		ASSERT_STREQ(eventtypecertainty.c_str(), expectedcertainty.c_str());
	}
}


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

    checkdata(eventtypeobject2, "");
}

// tests to see if eventtype can successfully
// read json output
TEST(EventTypeTest, ReadsJSON) {
	// build associated object
	rapidjson::Document eventtypedocument;
	detectionformats::eventtype eventtypeobject(detectionformats::FromJSONString(std::string(EVENTTYPESTRING), eventtypedocument)); // NOLINT

	checkdata(eventtypeobject, "");
}

// tests to see if eventtype can successfully
// be constructed
TEST(EventTypeTest, Constructor) {
	// use constructor
	detectionformats::eventtype eventtypeobject(EVENTTYPE, CERTAINTY);

	checkdata(eventtypeobject, "");

	// json constructor (empty)
    rapidjson::Value emptyvalue(rapidjson::kObjectType);
    detectionformats::eventtype eventtypeobject2(emptyvalue);

	checkdata(eventtypeobject2, "");
}

// tests to see if eventtype can successfully
// be copied
TEST(EventTypeTest, CopyConstructor) {
	// use constructor
	detectionformats::eventtype eventtypeobject(EVENTTYPE, CERTAINTY);

	// copy constructor
    detectionformats::eventtype eventtypeobject2(eventtypeobject);

    // check data values
	checkdata(eventtypeobject2, "");
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

// tests the isempty function
TEST(EventTypeTest, IsEmpty) {
	detectionformats::eventtype eventtypeobject;

	// check return
	ASSERT_TRUE(eventtypeobject.isempty()) << "Tested for empty.";

	// build event type object
	eventtypeobject.type = std::string(EVENTTYPE);

	// check return
	ASSERT_FALSE(eventtypeobject.isempty()) << "Tested for not empty.";
}
