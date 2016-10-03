#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define SOURCESTRING "{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"

// tests to see if source can successfully
// write json output
TEST(SourceTest, WritesJSON)
{
	detectionformats::source sourceobject;

	// build source object
	sourceobject.agencyid = std::string(AGENCYID);
	sourceobject.author = std::string(AUTHOR);

	// build json string
	rapidjson::Document sourcedocument;
	std::string sourcejson = detectionformats::ToJSONString(sourceobject.tojson(sourcedocument, sourcedocument.GetAllocator()));

    // read it back in
    rapidjson::Document sourcedocument2;
    detectionformats::source sourceobject2(detectionformats::FromJSONString(sourcejson, sourcedocument2));
    
    // check agencyid
    std::string sourceagencyid = sourceobject2.agencyid;
    std::string expectedagencyid = std::string(AGENCYID);
    ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());
    
    // check author
    std::string sourceauthor = sourceobject2.author;
    std::string expectedauthor = std::string(AUTHOR);
    ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());
}

// tests to see if source can successfully
// read json output
TEST(SourceTest, ReadsJSON)
{
	// build associated object
	rapidjson::Document sourcedocument;
	detectionformats::source sourceobject(detectionformats::FromJSONString(std::string(SOURCESTRING), sourcedocument));

	// check agencyid
	std::string sourceagencyid = sourceobject.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());

	// check author
	std::string sourceauthor = sourceobject.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());
}

// tests to see if source can successfully
// be constructed
TEST(SourceTest, Constructor)
{
	// use constructor
	detectionformats::source sourceobject(AGENCYID, AUTHOR);

	// check agencyid
	std::string sourceagencyid = sourceobject.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());

	// check author
	std::string sourceauthor = sourceobject.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());
}

// tests to see if source can successfully
// validate
TEST(SourceTest, Validate)
{
	detectionformats::source sourceobject;

	// build source object
	sourceobject.agencyid = std::string(AGENCYID);
	sourceobject.author = std::string(AUTHOR);

	// successful validation
	bool result = sourceobject.isvalid();
	
	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// build bad source object
	detectionformats::source badsourceobject;
	badsourceobject.agencyid = std::string(AGENCYID);

	result = false;
	try
	{
		// call validation
		result = badsourceobject.isvalid();
	}
	catch (const std::exception &)
	{
		// don't care
	}

	// check return code
	ASSERT_EQ(result, false) << "Tested for unsuccessful validation.";
}