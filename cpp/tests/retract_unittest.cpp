#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define RETRACTSTRING "{\"Type\":\"Retract\",\"ID\":\"12GFH48776857\",\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}}"
#define ID "12GFH48776857"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"

void checkdata(detectionformats::retract retractobject, std::string testinfo)
{
	// check id
	std::string id = retractobject.id;
	std::string expectedid = std::string(ID);
	ASSERT_STREQ(id.c_str(), expectedid.c_str());

	// check agencyid
	std::string sourceagencyid = retractobject.source.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());

	// check author
	std::string sourceauthor = retractobject.source.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());
}

// tests to see if origin can successfully
// write json output
TEST(RetractTest, WritesJSON)
{
	detectionformats::retract retractobject;

	// build origin object
	retractobject.id = std::string(ID);

	// source subobject
	retractobject.source.agencyid = std::string(AGENCYID);
	retractobject.source.author = std::string(AUTHOR);

	// build json string
	rapidjson::Document retractdocument;
	std::string retractjson = detectionformats::ToJSONString(retractobject.tojson(retractdocument, retractdocument.GetAllocator()));
    
    // read it back in
    rapidjson::Document retractdocument2;
    detectionformats::retract retractobject2(detectionformats::FromJSONString(retractjson, retractdocument2));
    
    // check data values
    checkdata(retractobject2, "");
}

// tests to see if origin can successfully
// read json output
TEST(RetractTest, ReadsJSON)
{
	// build retract object
	rapidjson::Document retractdocument;
	detectionformats::retract retractobject(detectionformats::FromJSONString(std::string(RETRACTSTRING), retractdocument));

	// check data values
	checkdata(retractobject, "");
}

// tests to see if origin can successfully
// be constructed
TEST(RetractTest, Constructor)
{
	// use constructor
	detectionformats::retract retractobject(std::string(ID), std::string(AGENCYID), std::string(AUTHOR));

	// check data values
	checkdata(retractobject, "Tested Constructor");

	detectionformats::retract retractobject_altc(std::string(ID), detectionformats::source(std::string(AGENCYID), std::string(AUTHOR)));

	// check data values
	checkdata(retractobject_altc, "Tested Alternate Constructor");
}

// tests to see if origin can successfully
// be copy constructed
TEST(RetractTest, CopyConstructor)
{
	// use constructor
	detectionformats::retract fromretractobject(std::string(ID), std::string(AGENCYID), std::string(AUTHOR));

	detectionformats::retract retractobject(fromretractobject);

	// check data values
	checkdata(retractobject, "");
}

// tests to see if origin can successfully
// validate
TEST(RetractTest, Validate)
{
	detectionformats::retract retractobject;

	// build origin object
	retractobject.id = std::string(ID);

	// source subobject
	retractobject.source.agencyid = std::string(AGENCYID);
	retractobject.source.author = std::string(AUTHOR);

	// successful validation
	bool result = retractobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// build bad origin object
	detectionformats::retract badretractobject;
	retractobject.id = "";

	result = false;
	try
	{
		// call validation
		result = badretractobject.isvalid();
	}
	catch (const std::exception &)
	{
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false) << "Tested for unsuccessful validation.";
}