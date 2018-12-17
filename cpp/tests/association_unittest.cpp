#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::association associationobject,
	std::string testinfo) {
	// check phase
	if (associationobject.phase.empty() != true) {
		std::string associationphase = associationobject.phase;
		std::string expectedphase = std::string(PHASE);
		ASSERT_STREQ(associationphase.c_str(), expectedphase.c_str());
	}

	// check distance
	if (std::isnan(associationobject.distance) != true) {
		double associationdistance = associationobject.distance;
		double expecteddistance = DISTANCE;
		ASSERT_EQ(associationdistance, expecteddistance);
	}

	// check azimuth
	if (std::isnan(associationobject.azimuth) != true) {
		double associationazimuth = associationobject.azimuth;
		double expectedazimuth = AZIMUTH;
		ASSERT_EQ(associationazimuth, expectedazimuth);
	}

	// check residual
	if (std::isnan(associationobject.residual) != true) {
		double associationresidual = associationobject.residual;
		double expectedresidual = RESIDUAL;
		ASSERT_EQ(associationresidual, expectedresidual);
	}

	// check sigma
	if (std::isnan(associationobject.sigma) != true) {
		double associationsigma = associationobject.sigma;
		double expectedsigma = SIGMA;
		ASSERT_EQ(associationsigma, expectedsigma);
	}
}

// tests to see if association can successfully
// write json output
TEST(AssociationTest, WritesJSON) {
	detectionformats::association associationobject;

	// build association object
	associationobject.phase = std::string(PHASE);
	associationobject.distance = DISTANCE;
	associationobject.azimuth = AZIMUTH;
	associationobject.residual = RESIDUAL;
	associationobject.sigma = SIGMA;

	// build json string
	rapidjson::Document associationdocument;
	std::string associationjson = detectionformats::ToJSONString(
			associationobject.tojson(associationdocument,
			associationdocument.GetAllocator()));

    // read it back in
    rapidjson::Document associationdocument2;
    detectionformats::association associationobject2(
			detectionformats::FromJSONString(associationjson,
			associationdocument2));

    // check data values
    checkdata(associationobject2, "");
}

// tests to see if association can successfully
// read json output
TEST(AssociationTest, ReadsJSON) {
	// build association object
	rapidjson::Document associationdocument;
	detectionformats::association associationobject(
		detectionformats::FromJSONString(std::string(ASSOCIATEDSTRING),
		associationdocument));

	// check data values
	checkdata(associationobject, "");
}

// tests to see if association can successfully
// be constructed
TEST(AssociationTest, Constructor) {
	// use constructor
	detectionformats::association associationobject(std::string(PHASE), DISTANCE,
		AZIMUTH, RESIDUAL, SIGMA);

	// check data values
	checkdata(associationobject, "");

	// json constructor (empty)
    rapidjson::Value emptyvalue(rapidjson::kObjectType);
    detectionformats::association associationobject2(emptyvalue);

    // check data values
	checkdata(associationobject2, "");
}

// tests to see if association can successfully
// be copied
TEST(AssociationTest, CopyConstructor) {
	// use constructor
	detectionformats::association associationobject(std::string(PHASE), DISTANCE,
		AZIMUTH, RESIDUAL, SIGMA);

	// copy constructor
    detectionformats::association associationobject2(associationobject);

    // check data values
	checkdata(associationobject2, "");
}

// tests to see if association can successfully
// validate
TEST(AssociationTest, Validate) {
	detectionformats::association associationobject;

	// build association object
	associationobject.phase = std::string(PHASE);
	associationobject.distance = DISTANCE;
	associationobject.azimuth = AZIMUTH;
	associationobject.residual = RESIDUAL;
	associationobject.sigma = SIGMA;

	// successful validation
	bool result = associationobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// build bad site object
	detectionformats::association badassociationobject;
	badassociationobject.phase = "22";

	result = false;
	try {
		// call validation
		result = badassociationobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false) << "Tested for unsuccessful validation.";
}

// tests the isempty function
TEST(AssociationTest, IsEmpty) {
	detectionformats::association associationobject;

	// check return
	ASSERT_TRUE(associationobject.isempty()) << "Tested for empty.";

	// build association object
	associationobject.phase = std::string(PHASE);

	// check return
	ASSERT_FALSE(associationobject.isempty()) << "Tested for not empty.";
}
