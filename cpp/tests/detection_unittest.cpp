#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define DETECTIONSTRING "{\"Type\":\"Detection\",\"ID\":\"12GFH48776857\",\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Hypocenter\":{\"TimeError\":1.984,\"Time\":\"2015-12-28T21:32:24.017Z\",\"LongitudeError\":22.64,\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44},\"DetectionType\":\"New\",\"DetectionTime\":\"2015-12-28T21:32:28.017Z\",\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},\"Bayes\":2.65,\"MinimumDistance\":2.14,\"RMS\":3.8,\"Gap\":33.67,\"Data\":[{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65}],\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},\"Beam\":{\"BackAzimuth\":2.65,\"Slowness\":1.44,\"PowerRatio\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerRatioError\":0.557},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}},{\"Type\":\"Correlation\",\"ID\":\"12GFH48776857\",\"Site\":{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Phase\":\"P\",\"Time\":\"2015-12-28T21:32:24.017Z\",\"Correlation\":2.65,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44,\"OriginTime\":\"2015-12-28T21:30:44.039Z\",\"EventType\":\"earthquake\",\"Magnitude\":2.14,\"SNR\":3.8,\"ZScore\":33.67,\"DetectionThreshold\":1.5,\"ThresholdType\":\"minimum\",\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}]}" // NOLINT
#define ID "12GFH48776857"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"
#define LATITUDE 40.3344
#define LONGITUDE -121.44
#define ORIGINTIME "2015-12-28T21:32:24.017Z"
#define DEPTH 32.44
#define LATITUDEERROR 12.5
#define LONGITUDEERROR 22.64
#define DEPTHERROR 2.44
#define TIMEERROR 1.984
#define DETECTIONTYPE "New"
#define DETECTIONTIME "2015-12-28T21:32:28.017Z"
#define EVENTTYPE "Earthquake"
#define CERTAINTY "Suspected"
#define BAYES 2.65
#define MINIMUMDISTANCE 2.14
#define RMS 3.8
#define GAP 33.67
#define PICKDATA "{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65},{\"HighPass\":2.10,\"LowPass\":3.58}],\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333},\"Beam\":{\"BackAzimuth\":2.65,\"Slowness\":1.44,\"PowerRatio\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerRatioError\":0.557}}" // NOLINT
#define CORRELATIONDATA "{\"ZScore\":33.67,\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\",\"Location\":\"01\"},\"Magnitude\":2.14,\"Type\":\"Correlation\",\"Correlation\":2.65,\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},\"AssociationInfo\":{\"Distance\":0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":-0.025393},\"DetectionThreshold\":1.5,\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Hypocenter\":{\"TimeError\":1.984,\"Time\":\"2015-12-28T21:30:44.039Z\",\"LongitudeError\":22.64,\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44},\"SNR\":3.8,\"ID\":\"12GFH48776857\",\"ThresholdType\":\"minimum\",\"Phase\":\"P\"}" // NOLINT

std::vector<detectionformats::pick> buildpickdata() {
	std::vector<detectionformats::pick> newpickdata;

	// pick ?need one more?
	rapidjson::Document pickdocument;
	detectionformats::pick pickobject(
			detectionformats::FromJSONString(std::string(PICKDATA),
					pickdocument));
	newpickdata.push_back(pickobject);

	return (newpickdata);
}

std::vector<detectionformats::correlation> buildcorrleationdata() {
	std::vector<detectionformats::correlation> newcorrelationdata;

	// correlation ?need one more?
	rapidjson::Document correlationdocument;
	detectionformats::correlation correlationobject(
			detectionformats::FromJSONString(std::string(CORRELATIONDATA),
					correlationdocument));
	newcorrelationdata.push_back(correlationobject);

	return (newcorrelationdata);
}

void checkdata(detectionformats::detection detectionobject,
		std::string testinfo) {
	// check id
	std::string detectionid = detectionobject.id;
	std::string expectedid = std::string(ID);
	ASSERT_STREQ(detectionid.c_str(), expectedid.c_str());

	// check agencyid
	std::string sourceagencyid = detectionobject.source.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());

	// check author
	std::string sourceauthor = detectionobject.source.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());

	// check latitude
	double latitude = detectionobject.hypocenter.latitude;
	double expectedlatitude = LATITUDE;
	ASSERT_EQ(latitude, expectedlatitude);

	// check longitude
	double longitude = detectionobject.hypocenter.longitude;
	double expectedlongitude = LONGITUDE;
	ASSERT_EQ(longitude, expectedlongitude);

	// check detectiontime
	double time = detectionobject.hypocenter.time;
	double expectedtime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(ORIGINTIME));
	ASSERT_NEAR(time, expectedtime, 0.0001);

	// check depth
	double depth = detectionobject.hypocenter.depth;
	double expecteddepth = DEPTH;
	ASSERT_EQ(depth, expecteddepth);

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
	if (detectionobject.detectiontype.compare("") != true) {
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
	if (detectionobject.eventtype.type.compare("") != true) {
		std::string detectioneventtype = detectionobject.eventtype.type;
		std::string expectedeventtype = std::string(EVENTTYPE);
		ASSERT_STREQ(detectioneventtype.c_str(), expectedeventtype.c_str());
	}

	// check eventtype certainty
	if (detectionobject.eventtype.certainty.compare("") != true) {
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
	double detectionminimumdistance = detectionobject.minimumdistance;
	double expectedminimumdistancee = MINIMUMDISTANCE;
	ASSERT_EQ(detectionminimumdistance, expectedminimumdistancee);

	// check rms
	double detectionrms = detectionobject.rms;
	double expectedrms = RMS;
	ASSERT_EQ(detectionrms, expectedrms);

	// check gap
	double detectiongap = detectionobject.gap;
	double expectedgap = GAP;
	ASSERT_EQ(detectiongap, expectedgap);

	// need to check data still!!!!!!
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
					std::string(ORIGINTIME));
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
					std::string(ORIGINTIME)),
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
							std::string(ORIGINTIME)), DEPTH, LATITUDEERROR,
					LONGITUDEERROR, TIMEERROR, DEPTHERROR),
			std::string(DETECTIONTYPE),
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(DETECTIONTIME)),
			detectionformats::eventtype(std::string(EVENTTYPE), std::string(CERTAINTY)),
			BAYES, MINIMUMDISTANCE, RMS, GAP, buildpickdata(),
			buildcorrleationdata());

	// check data values
	checkdata(detectionobject_altc, "Tested Alternate Constructor");
}

// tests to see if detection can successfully
// be copy constructed
TEST(DetectionTest, CopyConstructor) {
	// use constructor
	detectionformats::detection fromdetectionobject(std::string(ID),
			std::string(AGENCYID), std::string(AUTHOR), LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(ORIGINTIME)),
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
					std::string(ORIGINTIME));
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
	baddetectionobject.id = "";

	result = false;
	try {
		// call validation
		result = baddetectionobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
