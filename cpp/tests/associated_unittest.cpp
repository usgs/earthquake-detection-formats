#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define ASSOCIATEDSTRING "{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}"
#define PHASE "P"
#define DISTANCE 0.442559
#define AZIMUTH 0.418479
#define RESIDUAL -0.025393
#define SIGMA 0.086333

void checkdata(detectionformats::associated associatedobject, std::string testinfo)
{
	// check phase
	std::string associatedphase = associatedobject.phase;
	std::string expectedphase = std::string(PHASE);
	ASSERT_STREQ(associatedphase.c_str(), expectedphase.c_str());

	// check distance
	double associateddistance = associatedobject.distance;
	double expecteddistance = DISTANCE;
	ASSERT_EQ(associateddistance, expecteddistance);

	// check azimuth
	double associatedazimuth = associatedobject.azimuth;
	double expectedazimuth = AZIMUTH;
	ASSERT_EQ(associatedazimuth, expectedazimuth);

	// check residual
	double associatedresidual = associatedobject.residual;
	double expectedresidual = RESIDUAL;
	ASSERT_EQ(associatedresidual, expectedresidual);

	// check sigma
	double associatedsigma = associatedobject.sigma;
	double expectedsigma = SIGMA;
	ASSERT_EQ(associatedsigma, expectedsigma);
}

// tests to see if associated can successfully
// write json output
TEST(AssociatedTest, WritesJSON)
{
	detectionformats::associated associatedobject;

	// build associated object
	associatedobject.phase = std::string(PHASE);
	associatedobject.distance = DISTANCE;
	associatedobject.azimuth = AZIMUTH;
	associatedobject.residual = RESIDUAL;
	associatedobject.sigma = SIGMA;

	// build json string
	rapidjson::Document associateddocument;
	std::string associatedjson = detectionformats::ToJSONString(associatedobject.tojson(associateddocument, associateddocument.GetAllocator()));

    // read it back in
    rapidjson::Document associateddocument2;
    detectionformats::associated associatedobject2(detectionformats::FromJSONString(associatedjson, associateddocument2));
    
    // check data values
    checkdata(associatedobject2, "");
}

// tests to see if associated can successfully
// read json output
TEST(AssociatedTest, ReadsJSON)
{
	// build associated object
	rapidjson::Document associateddocument;
	detectionformats::associated associatedobject(detectionformats::FromJSONString(std::string(ASSOCIATEDSTRING), associateddocument));

	// check data values
	checkdata(associatedobject, "");
}

// tests to see if associated can successfully
// be constructed
TEST(AssociatedTest, Constructor)
{
	// use constructor
	detectionformats::associated associatedobject(std::string(PHASE), DISTANCE, AZIMUTH, RESIDUAL, SIGMA);

	// check data values
	checkdata(associatedobject, "");
}

// tests to see if associated can successfully
// validate
TEST(AssociatedTest, Validate)
{
	detectionformats::associated associatedobject;

	// build associated object
	associatedobject.phase = std::string(PHASE);
	associatedobject.distance = DISTANCE;
	associatedobject.azimuth = AZIMUTH;
	associatedobject.residual = RESIDUAL;
	associatedobject.sigma = SIGMA;

	// successful validation
	bool result = associatedobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// build bad site object
	detectionformats::associated badassociatedobject;
	badassociatedobject.phase = "22";

	result = false;
	try
	{
		// call validation
		result = badassociatedobject.isvalid();
	}
	catch (const std::exception &)
	{
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false) << "Tested for unsuccessful validation.";
}