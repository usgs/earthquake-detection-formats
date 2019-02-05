#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

std::vector<detectionformats::pick> buildpickdata() {
	std::vector<detectionformats::pick> newpickdata;

	// pick ?need one more?
	rapidjson::Document pickdocument;
	detectionformats::pick pickobject(
			detectionformats::FromJSONString(std::string(PICKSTRING),
					pickdocument));
	newpickdata.push_back(pickobject);

	return (newpickdata);
}

std::vector<detectionformats::correlation> buildcorrleationdata() {
	std::vector<detectionformats::correlation> newcorrelationdata;

	// correlation ?need one more?
	rapidjson::Document correlationdocument;
	detectionformats::correlation correlationobject(
			detectionformats::FromJSONString(std::string(CORRELATIONSTRING),
					correlationdocument));
	newcorrelationdata.push_back(correlationobject);

	return (newcorrelationdata);
}

void checkdata(detectionformats::detection detectionobject,
		std::string testinfo) {
	// check id
	if (detectionobject.id.empty() != true) {
		std::string detectionid = detectionobject.id;
		std::string expectedid = std::string(ID);
		ASSERT_STREQ(detectionid.c_str(), expectedid.c_str());
	}

	// check agencyid
	if (detectionobject.source.agencyid.empty() != true) {
		std::string sourceagencyid = detectionobject.source.agencyid;
		std::string expectedagencyid = std::string(AGENCYID);
		ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());
	}

	// check author
	if (detectionobject.source.author.empty() != true) {
		std::string sourceauthor = detectionobject.source.author;
		std::string expectedauthor = std::string(AUTHOR);
		ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());
	}

	// check latitude
	if (std::isnan(detectionobject.hypocenter.latitude) != true) {
		double latitude = detectionobject.hypocenter.latitude;
		double expectedlatitude = LATITUDE;
		ASSERT_EQ(latitude, expectedlatitude);
	}

	// check longitude
	if (std::isnan(detectionobject.hypocenter.longitude) != true) {
		double longitude = detectionobject.hypocenter.longitude;
		double expectedlongitude = LONGITUDE;
		ASSERT_EQ(longitude, expectedlongitude);
	}

	// check detectiontime
	if (std::isnan(detectionobject.hypocenter.time) != true) {
		double time = detectionobject.hypocenter.time;
		double expectedtime = detectionformats::ConvertISO8601ToEpochTime(
				std::string(TIME));
		ASSERT_NEAR(time, expectedtime, 0.0001);
	}

	// check depth
	if (std::isnan(detectionobject.hypocenter.depth) != true) {
		double depth = detectionobject.hypocenter.depth;
		double expecteddepth = DEPTH;
		ASSERT_EQ(depth, expecteddepth);
	}

	// check latitude error
	if (std::isnan(detectionobject.hypocenter.latitudeerror) != true) {
		double latitudeerror = detectionobject.hypocenter.latitudeerror;
		double expectedlatitudeerror = LATITUDEERROR;
		ASSERT_EQ(latitudeerror, expectedlatitudeerror);
	}

	// check longitude error
	if (std::isnan(detectionobject.hypocenter.longitudeerror) != true) {
		double longitdeerror = detectionobject.hypocenter.longitudeerror;
		double expectedlongitudeerror = LONGITUDEERROR;
		ASSERT_EQ(longitdeerror, expectedlongitudeerror);
	}

	// check time error
	if (std::isnan(detectionobject.hypocenter.timeerror) != true) {
		double timeerror = detectionobject.hypocenter.timeerror;
		double expectedtimeerror = TIMEERROR;
		ASSERT_EQ(timeerror, expectedtimeerror);
	}

	// check depth error
	if (std::isnan(detectionobject.hypocenter.deptherror) != true) {
		double deptherror = detectionobject.hypocenter.deptherror;
		double expecteddeptherror = DEPTHERROR;
		ASSERT_EQ(deptherror, expecteddeptherror);
	}

	// check detectiontype
	if (detectionobject.detectiontype.empty() != true) {
		std::string detectiondetectiontype = detectionobject.detectiontype;
		std::string expecteddetectiontype = std::string(DETECTIONTYPE);
		ASSERT_STREQ(detectiondetectiontype.c_str(),
				expecteddetectiontype.c_str());
	}

	// check detectiontime
	if (std::isnan(detectionobject.detectiontime) != true) {
		double detectiontime = detectionobject.detectiontime;
		double expecteddetectiontime =
				detectionformats::ConvertISO8601ToEpochTime(
						std::string(DETECTIONTIME));
		ASSERT_NEAR(detectiontime, expecteddetectiontime, 0.0001);
	}

	// check eventtype
	if (detectionobject.eventtype.type.empty() != true) {
		std::string detectioneventtype = detectionobject.eventtype.type;
		std::string expectedeventtype = std::string(EVENTTYPE);
		ASSERT_STREQ(detectioneventtype.c_str(), expectedeventtype.c_str());
	}

	// check eventtype certainty
	if (detectionobject.eventtype.certainty.empty() != true) {
		std::string detectioneventtypecertainty =
			detectionobject.eventtype.certainty;
		std::string expectedeventtypecertainty = std::string(CERTAINTY);
		ASSERT_STREQ(detectioneventtypecertainty.c_str(),
			expectedeventtypecertainty.c_str());
	}

	// check bayes
	if (std::isnan(detectionobject.bayes) != true) {
		double detectionbayes = detectionobject.bayes;
		double expectedbayes = BAYES;
		ASSERT_EQ(detectionbayes, expectedbayes);
	}

	// check minimumdistance
	if (std::isnan(detectionobject.minimumdistance) != true) {
		double detectionminimumdistance = detectionobject.minimumdistance;
		double expectedminimumdistancee = MINIMUMDISTANCE;
		ASSERT_EQ(detectionminimumdistance, expectedminimumdistancee);
	}

	// check rms
	if (std::isnan(detectionobject.rms) != true) {
		double detectionrms = detectionobject.rms;
		double expectedrms = RMS;
		ASSERT_EQ(detectionrms, expectedrms);
	}

	// check gap
	if (std::isnan(detectionobject.gap) != true) {
		double detectiongap = detectionobject.gap;
		double expectedgap = GAP;
		ASSERT_EQ(detectiongap, expectedgap);
	}

	// should check data still!!!!!!
	// somehow?
}

// tests to see if detection can successfully
// write json output
TEST(DetectionTest, WritesJSON) {
	detectionformats::detection detectionobject;

	// build detection object
	detectionobject.id = std::string(ID);

	// source subobject
	detectionobject.source.agencyid = std::string(AGENCYID);
	detectionobject.source.author = std::string(AUTHOR);

	detectionobject.hypocenter.latitude = LATITUDE;
	detectionobject.hypocenter.longitude = LONGITUDE;
	detectionobject.hypocenter.time =
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME));
	detectionobject.hypocenter.depth = DEPTH;
	detectionobject.hypocenter.latitudeerror = LATITUDEERROR;
	detectionobject.hypocenter.longitudeerror = LONGITUDEERROR;
	detectionobject.hypocenter.timeerror = TIMEERROR;
	detectionobject.hypocenter.deptherror = DEPTHERROR;

	detectionobject.detectiontype = std::string(DETECTIONTYPE);
	detectionobject.detectiontime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(DETECTIONTIME));
	detectionobject.eventtype.type = std::string(EVENTTYPE);
	detectionobject.eventtype.certainty = std::string(CERTAINTY);
	detectionobject.bayes = BAYES;
	detectionobject.minimumdistance = MINIMUMDISTANCE;
	detectionobject.rms = RMS;
	detectionobject.gap = GAP;

	// data
	detectionobject.pickdata = buildpickdata();
	detectionobject.correlationdata = buildcorrleationdata();

	// build json string
	rapidjson::Document detectiondocument;
	std::string detectionjson = detectionformats::ToJSONString(
			detectionobject.tojson(detectiondocument,
					detectiondocument.GetAllocator()));

	// read it back in
	rapidjson::Document detectiondocument2;
	detectionformats::detection detectionobject2(
			detectionformats::FromJSONString(detectionjson,
					detectiondocument2));

	// check data values
	checkdata(detectionobject2, "");
}

// tests to see if detection can successfully
// read json output
TEST(DetectionTest, ReadsJSON) {
	// build associated object
	rapidjson::Document detectiondocument;
	detectionformats::detection detectionobject(
			detectionformats::FromJSONString(std::string(DETECTIONSTRING),
					detectiondocument));

	// check data values
	checkdata(detectionobject, "");
}

// tests to see if detection can successfully
// be constructed
TEST(DetectionTest, Constructor) {
	// use constructor
	detectionformats::detection detectionobject(std::string(ID),
			std::string(AGENCYID), std::string(AUTHOR), LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME)),
			DEPTH, LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR,
			std::string(DETECTIONTYPE),
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(DETECTIONTIME)),
			std::string(EVENTTYPE), std::string(CERTAINTY),
			BAYES, MINIMUMDISTANCE, RMS, GAP, buildpickdata(),
			buildcorrleationdata());

	// check data values
	checkdata(detectionobject, "Tested Constructor");

	detectionformats::detection detectionobject_altc(std::string(ID),
			detectionformats::source(std::string(AGENCYID),
					std::string(AUTHOR)),
			detectionformats::hypocenter(LATITUDE, LONGITUDE,
					detectionformats::ConvertISO8601ToEpochTime(
							std::string(TIME)), DEPTH, LATITUDEERROR,
					LONGITUDEERROR, TIMEERROR, DEPTHERROR),
			std::string(DETECTIONTYPE),
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(DETECTIONTIME)),
			detectionformats::eventtype(std::string(EVENTTYPE), std::string(CERTAINTY)),
			BAYES, MINIMUMDISTANCE, RMS, GAP, buildpickdata(),
			buildcorrleationdata());

	// check data values
	checkdata(detectionobject_altc, "Tested Alternate Constructor");

	// json constructor (empty)
    rapidjson::Value emptyvalue(rapidjson::kObjectType);
    detectionformats::detection detectionobject2(emptyvalue);

    // check data values
	checkdata(detectionobject2, "");
}

// tests to see if detection can successfully
// be copy constructed
TEST(DetectionTest, CopyConstructor) {
	// use constructor
	detectionformats::detection fromdetectionobject(std::string(ID),
			std::string(AGENCYID), std::string(AUTHOR), LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME)),
			DEPTH, LATITUDEERROR, LONGITUDEERROR, TIMEERROR, DEPTHERROR,
			std::string(DETECTIONTYPE),
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(DETECTIONTIME)),
			std::string(EVENTTYPE), std::string(CERTAINTY),
			BAYES, MINIMUMDISTANCE, RMS, GAP, buildpickdata(),
			buildcorrleationdata());

	detectionformats::detection detectionobject(fromdetectionobject);

	// check data values
	checkdata(detectionobject, "");
}

// tests to see if detection can successfully
// validate
TEST(DetectionTest, Validate) {
	detectionformats::detection detectionobject;

	// build detection object
	detectionobject.id = std::string(ID);

	// source subobject
	detectionobject.source.agencyid = std::string(AGENCYID);
	detectionobject.source.author = std::string(AUTHOR);

	detectionobject.hypocenter.latitude = LATITUDE;
	detectionobject.hypocenter.longitude = LONGITUDE;
	detectionobject.hypocenter.time =
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME));
	detectionobject.hypocenter.depth = DEPTH;
	detectionobject.hypocenter.latitudeerror = LATITUDEERROR;
	detectionobject.hypocenter.longitudeerror = LONGITUDEERROR;
	detectionobject.hypocenter.timeerror = TIMEERROR;
	detectionobject.hypocenter.deptherror = DEPTHERROR;

	detectionobject.detectiontype = std::string(DETECTIONTYPE);
	detectionobject.detectiontime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(DETECTIONTIME));
	detectionobject.eventtype.type = std::string(EVENTTYPE);
	detectionobject.eventtype.certainty = std::string(CERTAINTY);
	detectionobject.bayes = BAYES;
	detectionobject.minimumdistance = MINIMUMDISTANCE;
	detectionobject.rms = RMS;
	detectionobject.gap = GAP;

	// data
	detectionobject.pickdata = buildpickdata();
	detectionobject.correlationdata = buildcorrleationdata();

	// successful validation
	bool result = detectionobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad detection object
	detectionformats::detection baddetectionobject;

	result = false;
	try {
		// call validation
		result = baddetectionobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";

	// build bad detection object
	detectionformats::detection baddetectionobject2;
	baddetectionobject2.detectiontype = "not";
	baddetectionobject2.detectiontime = -1000000000000;
	baddetectionobject2.eventtype.type = "fjyord";
	baddetectionobject2.eventtype.certainty = "nah";
	baddetectionobject2.bayes = -99;
	baddetectionobject2.minimumdistance = -99;
	baddetectionobject2.rms = -99999;
	baddetectionobject2.gap = -1;

	result = false;
	try {
		// call validation
		result = baddetectionobject2.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
