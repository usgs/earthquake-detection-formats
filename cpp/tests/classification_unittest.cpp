#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT


void checkdata(detectionformats::classification classificationobject,
	std::string testinfo) {
	// check phase
	std::string classificationphase = classificationobject.phase;
	std::string expectedphase = std::string(PHASE);
	ASSERT_STREQ(classificationphase.c_str(), expectedphase.c_str());

	// check phase probability
	double classificationphaseprob = classificationobject.phaseprobability;
	double expectedphaseprob = PHASEPROBABILITY;
	ASSERT_EQ(classificationphaseprob, expectedphaseprob);

	// check distance
	double classificationdistance = classificationobject.distance;
	double expecteddistance = DISTANCE;
	ASSERT_EQ(classificationdistance, expecteddistance);

    // check distance probability
	double classificationdistanceprob = classificationobject.distanceprobability;
	double expecteddistanceprob = DISTANCEPROBABILITY;
	ASSERT_EQ(classificationdistanceprob, expecteddistanceprob);

	// check azimuth
	double classificationazimuth = classificationobject.azimuth;
	double expectedazimuth = AZIMUTH;
	ASSERT_EQ(classificationazimuth, expectedazimuth);

    // check azimuth probability
	double classificationazimuthprob = classificationobject.azimuthprobability;
	double expectedazimuthprob = AZIMUTHPROBABILITY;
	ASSERT_EQ(classificationazimuthprob, expectedazimuthprob);

    // check magnitude
	double classificationmagnitude = classificationobject.magnitude;
	double expectedmagnitude = MAGNITUDE;
	ASSERT_EQ(classificationmagnitude, expectedmagnitude);

    // check magnitude type
	std::string classificationmagtype = classificationobject.magnitudetype;
	std::string expectedmagtype = std::string(MAGNITUDETYPE);
	ASSERT_STREQ(classificationmagtype.c_str(), expectedmagtype.c_str());

    // check magnitude probability
	double classificationmagnitudeprob = classificationobject.magnitudeprobability;
	double expectedmagnitudeprob = MAGNITUDEPROBABILITY;
	ASSERT_EQ(classificationmagnitudeprob, expectedmagnitudeprob);

	// check depth
	double classificationdepth = classificationobject.depth;
	double expecteddepth = DEPTH;
	ASSERT_EQ(classificationdepth, expecteddepth);

    // check depth probability
	double classificationdepthprob = classificationobject.depthprobability;
	double expecteddepthprob = DEPTHPROBABILITY;
	ASSERT_EQ(classificationdepthprob, expecteddepthprob);

    // check eventtype
	if (classificationobject.eventtype.type.compare("") != true) {
		std::string detectioneventtype = classificationobject.eventtype.type;
		std::string expectedeventtype = std::string(EVENTTYPE);
		ASSERT_STREQ(detectioneventtype.c_str(), expectedeventtype.c_str());
	}

	// check eventtype certainty
	if (classificationobject.eventtype.certainty.compare("") != true) {
		std::string detectioneventtypecertainty =
			classificationobject.eventtype.certainty;
		std::string expectedeventtypecertainty = std::string(CERTAINTY);
		ASSERT_STREQ(detectioneventtypecertainty.c_str(),
			expectedeventtypecertainty.c_str());
	}

    // check event type probability
	double classificationeventtypeprob = classificationobject.eventtypeprobability;
	double expectedeventtypeprob = EVENTTYPEPROBABILITY;
	ASSERT_EQ(classificationeventtypeprob, expectedeventtypeprob);

	// check agencyid
    if (classificationobject.source.agencyid.compare("") != true) {
        std::string sourceagencyid = classificationobject.source.agencyid;
        std::string expectedagencyid = std::string(AGENCYID);
        ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());
    }

	// check author
    if (classificationobject.source.author.compare("") != true) {
        std::string sourceauthor = classificationobject.source.author;
        std::string expectedauthor = std::string(AUTHOR);
        ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());
    }
}

// tests to see if classification can successfully
// write json output
TEST(ClassificationTest, WritesJSON) {
	detectionformats::classification classificationobject;

	// build classification object
	classificationobject.phase = std::string(PHASE);
	classificationobject.phaseprobability = PHASEPROBABILITY;
    classificationobject.distance = DISTANCE;
	classificationobject.distanceprobability = DISTANCEPROBABILITY;
    classificationobject.azimuth = AZIMUTH;
    classificationobject.azimuthprobability = AZIMUTHPROBABILITY;
    classificationobject.magnitude = MAGNITUDE;
    classificationobject.magnitudetype = std::string(MAGNITUDETYPE);
    classificationobject.magnitudeprobability = MAGNITUDEPROBABILITY;
    classificationobject.depth = DEPTH;
    classificationobject.depthprobability = DEPTHPROBABILITY;
	classificationobject.eventtype.type = std::string(EVENTTYPE);
    classificationobject.eventtype.certainty = std::string(CERTAINTY);
    classificationobject.eventtypeprobability = EVENTTYPEPROBABILITY;
    classificationobject.source.agencyid = AGENCYID;
	classificationobject.source.author = AUTHOR;

	// build json string
	rapidjson::Document classificationdocument;
	std::string classificationjson = detectionformats::ToJSONString(
            classificationobject.tojson(classificationdocument,
            classificationdocument.GetAllocator()));

    // read it back in
    rapidjson::Document classificationdocument2;
    detectionformats::classification classificationobject2(
            detectionformats::FromJSONString(classificationjson,
            classificationdocument2));

    // check data values
    checkdata(classificationobject2, "");
}

// tests to see if classification can successfully
// read json output
TEST(ClassificationTest, ReadsJSON) {
	// build classification object
	rapidjson::Document classificationdocument;
	detectionformats::classification classificationobject(
            detectionformats::FromJSONString(std::string(CLASSIFICATIONSTRING),
            classificationdocument));

	// check data values
	checkdata(classificationobject, "");
}

// tests to see if classification can successfully
// be constructed
TEST(ClassificationTest, Constructor) {
	// use constructor
	detectionformats::classification classificationobject(std::string(PHASE),
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH,
            AZIMUTHPROBABILITY, MAGNITUDE, std::string(MAGNITUDETYPE),
            MAGNITUDEPROBABILITY, DEPTH, DEPTHPROBABILITY, EVENTTYPE, CERTAINTY,
            EVENTTYPEPROBABILITY, AGENCYID, AUTHOR);

	// check data values
	checkdata(classificationobject, "");

    // alternate constructor
	detectionformats::classification classificationobject2(std::string(PHASE),
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH,
            AZIMUTHPROBABILITY, MAGNITUDE, std::string(MAGNITUDETYPE),
            MAGNITUDEPROBABILITY, DEPTH, DEPTHPROBABILITY,
            detectionformats::eventtype(EVENTTYPE, CERTAINTY),
            EVENTTYPEPROBABILITY, detectionformats::source(AGENCYID, AUTHOR));

	// check data values
	checkdata(classificationobject2, "");
}

// tests to see if classification can successfully
// validate
TEST(ClassificationTest, Validate) {
	detectionformats::classification classificationobject;

	// build classification object
	classificationobject.phase = std::string(PHASE);
	classificationobject.phaseprobability = PHASEPROBABILITY;
    classificationobject.distance = DISTANCE;
	classificationobject.distanceprobability = PHASEPROBABILITY;
    classificationobject.azimuth = AZIMUTH;
    classificationobject.azimuthprobability = AZIMUTHPROBABILITY;
    classificationobject.magnitude = MAGNITUDE;
    classificationobject.magnitudetype = std::string(MAGNITUDETYPE);
    classificationobject.magnitudeprobability = MAGNITUDEPROBABILITY;
    classificationobject.depth = DEPTH;
    classificationobject.depthprobability = DEPTHPROBABILITY;
	classificationobject.eventtype.type = std::string(EVENTTYPE);
    classificationobject.eventtype.certainty = std::string(CERTAINTY);
    classificationobject.eventtypeprobability = EVENTTYPEPROBABILITY;
    classificationobject.source.agencyid = AGENCYID;
	classificationobject.source.author = AUTHOR;

	// successful validation
	bool result = classificationobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// build bad site object
	detectionformats::classification badclassificationobject;
	badclassificationobject.phase = "22";

	result = false;
	try {
		// call validation
		result = badclassificationobject.isvalid();
	}
	catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false) << "Tested for unsuccessful validation.";
}

// tests the isempty function
TEST(ClassificationTest, IsEmpty) {
	detectionformats::classification classificationobject;

	// check return
	ASSERT_TRUE(classificationobject.isempty()) << "Tested for empty.";

	// build filter object
	classificationobject.phase = std::string(PHASE);

	// check return
	ASSERT_FALSE(classificationobject.isempty()) << "Tested for not empty.";
}
