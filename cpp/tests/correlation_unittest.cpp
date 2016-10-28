#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define CORRELATIONSTRING "{\"ZScore\":33.67,\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\",\"Location\":\"01\",\"SiteID\":\"BMN.HHZ.LB.01\"},\"Magnitude\":2.14,\"Type\":\"Correlation\",\"Correlation\":2.65,\"EventType\":\"earthquake\",\"AssociationInfo\":{\"Distance\":0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":-0.025393},\"DetectionThreshold\":1.5,\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Hypocenter\":{\"TimeError\":1.984,\"Time\":\"2015-12-28T21:30:44.039Z\",\"LongitudeError\":22.64,\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44},\"SNR\":3.8,\"ID\":\"12GFH48776857\",\"ThresholdType\":\"minimum\",\"Phase\":\"P\"}"
#define ID "12GFH48776857"
#define STATION "BMN"
#define CHANNEL "HHZ"
#define NETWORK "LB"
#define LOCATION "01"
#define SITEID "BMN.HHZ.LB.01"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"
#define TIME "2015-12-28T21:32:24.017Z"
#define PHASE "P"
#define CORRELATION 2.65
#define LATITUDE 40.3344
#define LONGITUDE -121.44
#define ORIGINTIME "2015-12-28T21:30:44.039Z"
#define LATITUDEERROR 12.5
#define LONGITUDEERROR 22.64
#define DEPTHERROR 2.44
#define TIMEERROR 1.984
#define DEPTH 32.44
#define EVENTTYPE "earthquake"
#define MAGNITUDE 2.14
#define SNR 3.8
#define ZSCORE 33.67
#define DETECTIONTHRESHOLD 1.5
#define THRESHOLDTYPE "minimum"
#define ASSOCPHASE "P"
#define ASSOCDISTANCE 0.442559
#define ASSOCAZIMUTH 0.418479
#define ASSOCRESIDUAL -0.025393
#define ASSOCSIGMA 0.086333

void checkdata(detectionformats::correlation correlationobject,
		std::string testinfo) {
	// check id
	std::string correlationid = correlationobject.id;
	std::string expectedid = std::string(ID);
	ASSERT_STREQ(correlationid.c_str(), expectedid.c_str());

	// check station
	std::string sitestation = correlationobject.site.station;
	std::string expectedstation = std::string(STATION);
	ASSERT_STREQ(sitestation.c_str(), expectedstation.c_str());

	// check channel
	std::string sitechannel = correlationobject.site.channel;
	std::string expectedchannel = std::string(CHANNEL);
	ASSERT_STREQ(sitechannel.c_str(), expectedchannel.c_str());

	// check network
	std::string sitenetwork = correlationobject.site.network;
	std::string expectednetwork = std::string(NETWORK);
	ASSERT_STREQ(sitenetwork.c_str(), expectednetwork.c_str());

	// check location
	std::string sitelocation = correlationobject.site.location;
	std::string expectedlocation = std::string(LOCATION);
	ASSERT_STREQ(sitelocation.c_str(), expectedlocation.c_str());

	// check siteid
	std::string sitesiteid = correlationobject.site.siteid;
	std::string expectedsiteid = std::string(SITEID);
	ASSERT_STREQ(sitesiteid.c_str(), expectedsiteid.c_str());

	// check agencyid
	std::string sourceagencyid = correlationobject.source.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());

	// check author
	std::string sourceauthor = correlationobject.source.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());

	// check phase
	std::string correlationphase = correlationobject.phase;
	std::string expectedphase = std::string(PHASE);
	ASSERT_STREQ(correlationphase.c_str(), expectedphase.c_str());

	// check time
	double correlationtime = correlationobject.time;
	double expectedtime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	ASSERT_EQ(correlationtime, expectedtime);

	// check correlation
	double correlationcorrelation = correlationobject.correlationvalue;
	double expectedcorrelation = CORRELATION;
	ASSERT_EQ(correlationcorrelation, expectedcorrelation);

	// check latitude
	double correlationlatitude = correlationobject.hypocenter.latitude;
	double expectedlatitude = LATITUDE;
	ASSERT_EQ(correlationlatitude, expectedlatitude);

	// check longitude
	double correlationlongitude = correlationobject.hypocenter.longitude;
	double expectedlongitude = LONGITUDE;
	ASSERT_EQ(correlationlongitude, expectedlongitude);

	// check origintime
	double correlationorigintime = correlationobject.hypocenter.time;
	double expectedorigintime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(ORIGINTIME));
	ASSERT_EQ(correlationorigintime, expectedorigintime);

	// check depth
	double correlationdepth = correlationobject.hypocenter.depth;
	double expecteddepth = DEPTH;
	ASSERT_EQ(correlationdepth, expecteddepth);

	// check latitude error
	double correlationlatitudeerror = correlationobject.hypocenter.latitudeerror;
	double expectedlatitudeerror = LATITUDEERROR;
	ASSERT_EQ(correlationlatitudeerror, expectedlatitudeerror);

	// check longitude error
	double correlationlongitdeerror =
			correlationobject.hypocenter.longitudeerror;
	double expectedlongitudeerror = LONGITUDEERROR;
	ASSERT_EQ(correlationlongitdeerror, expectedlongitudeerror);

	// check time error
	double correlationtimeerror = correlationobject.hypocenter.timeerror;
	double expectedtimeerror = TIMEERROR;
	ASSERT_EQ(correlationtimeerror, expectedtimeerror);

	// check depth error
	double correlationdeptherror = correlationobject.hypocenter.deptherror;
	double expecteddeptherror = DEPTHERROR;
	ASSERT_EQ(correlationdeptherror, expecteddeptherror);

	// check eventtype
	std::string correlationeventtype = correlationobject.eventtype;
	std::string expectedeventtype = std::string(EVENTTYPE);
	ASSERT_STREQ(correlationeventtype.c_str(), expectedeventtype.c_str());

	// check magnitude
	double correlationmagnitude = correlationobject.magnitude;
	double expectedmagnitude = MAGNITUDE;
	ASSERT_EQ(correlationmagnitude, expectedmagnitude);

	// check snr
	double correlationsnr = correlationobject.snr;
	double expectedsnr = SNR;
	ASSERT_EQ(correlationsnr, expectedsnr);

	// check zscore
	double correlationzscore = correlationobject.zscore;
	double expectedzscore = ZSCORE;
	ASSERT_EQ(correlationzscore, expectedzscore);

	// check detectionthreshold
	double correlationdetectionthreshold = correlationobject.detectionthreshold;
	double expecteddetectionthreshold = DETECTIONTHRESHOLD;
	ASSERT_EQ(correlationdetectionthreshold, expecteddetectionthreshold);

	// check thresholdtype
	std::string correlationthresholdtype = correlationobject.thresholdtype;
	std::string expectedthresholdtype = std::string(THRESHOLDTYPE);
	ASSERT_STREQ(correlationthresholdtype.c_str(),
			expectedthresholdtype.c_str());

	// check phase
	std::string associatedphase = correlationobject.associationinfo.phase;
	std::string expectedassociatedphase = std::string(ASSOCPHASE);
	ASSERT_STREQ(associatedphase.c_str(), expectedassociatedphase.c_str());

	// check distance
	double associateddistance = correlationobject.associationinfo.distance;
	double expecteddistance = ASSOCDISTANCE;
	ASSERT_EQ(associateddistance, expecteddistance);

	// check azimuth
	double associatedazimuth = correlationobject.associationinfo.azimuth;
	double expectedazimuth = ASSOCAZIMUTH;
	ASSERT_EQ(associatedazimuth, expectedazimuth);

	// check residual
	double associatedresidual = correlationobject.associationinfo.residual;
	double expectedresidual = ASSOCRESIDUAL;
	ASSERT_EQ(associatedresidual, expectedresidual);

	// check sigma
	double associatedsigma = correlationobject.associationinfo.sigma;
	double expectedsigma = ASSOCSIGMA;
	ASSERT_EQ(associatedsigma, expectedsigma);
}

// tests to see if correlation can successfully
// write json output
TEST(CorrelationTest, WritesJSON) {
	detectionformats::correlation correlationobject;

	// build correlation object
	correlationobject.id = std::string(ID);

	// site subobject
	correlationobject.site.siteid = std::string(SITEID);
	correlationobject.site.station = std::string(STATION);
	correlationobject.site.channel = std::string(CHANNEL);
	correlationobject.site.network = std::string(NETWORK);
	correlationobject.site.location = std::string(LOCATION);

	// source subobject
	correlationobject.source.agencyid = std::string(AGENCYID);
	correlationobject.source.author = std::string(AUTHOR);

	correlationobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	correlationobject.phase = std::string(PHASE);
	correlationobject.correlationvalue = CORRELATION;
	correlationobject.hypocenter.latitude = LATITUDE;
	correlationobject.hypocenter.longitude = LONGITUDE;
	correlationobject.hypocenter.time =
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(ORIGINTIME));
	correlationobject.hypocenter.depth = DEPTH;
	correlationobject.hypocenter.latitudeerror = LATITUDEERROR;
	correlationobject.hypocenter.longitudeerror = LONGITUDEERROR;
	correlationobject.hypocenter.timeerror = TIMEERROR;
	correlationobject.hypocenter.deptherror = DEPTHERROR;
	correlationobject.eventtype = std::string(EVENTTYPE);
	correlationobject.magnitude = MAGNITUDE;
	correlationobject.snr = SNR;
	correlationobject.zscore = ZSCORE;
	correlationobject.detectionthreshold = DETECTIONTHRESHOLD;
	correlationobject.thresholdtype = std::string(THRESHOLDTYPE);

	// association subobject
	correlationobject.associationinfo.phase = std::string(ASSOCPHASE);
	correlationobject.associationinfo.distance = ASSOCDISTANCE;
	correlationobject.associationinfo.azimuth = ASSOCAZIMUTH;
	correlationobject.associationinfo.residual = ASSOCRESIDUAL;
	correlationobject.associationinfo.sigma = ASSOCSIGMA;

	// build json string
	rapidjson::Document correlationdocument;
	std::string correlationjson = detectionformats::ToJSONString(
			correlationobject.tojson(correlationdocument,
					correlationdocument.GetAllocator()));

	// read it back in
	rapidjson::Document correlationdocument2;
	detectionformats::correlation correlationobject2(
			detectionformats::FromJSONString(correlationjson,
					correlationdocument2));

	// check data values
	checkdata(correlationobject2, "");
}

// tests to see if correlation can successfully
// read json output
TEST(CorrelationTest, ReadsJSON) {
	// build associated object
	rapidjson::Document correlationdocument;
	detectionformats::correlation correlationobject(
			detectionformats::FromJSONString(std::string(CORRELATIONSTRING),
					correlationdocument));

	// check data values
	checkdata(correlationobject, "");
}

// tests to see if correlation can successfully
// be constructed
TEST(CorrelationTest, Constructor) {
	// use constructor
	detectionformats::correlation correlationobject(std::string(ID),
			std::string(SITEID), std::string(STATION), std::string(CHANNEL),
			std::string(NETWORK), std::string(LOCATION), std::string(AGENCYID),
			std::string(AUTHOR), std::string(PHASE),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			CORRELATION, LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(ORIGINTIME)), DEPTH, LATITUDEERROR,
			LONGITUDEERROR, TIMEERROR, DEPTHERROR, std::string(EVENTTYPE),
			MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
			std::string(THRESHOLDTYPE), std::string(ASSOCPHASE), ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

	// check data values
	checkdata(correlationobject, "Tested Constructor");

	detectionformats::correlation correlationobject_altc(std::string(ID),
			detectionformats::site(std::string(SITEID), std::string(STATION),
					std::string(CHANNEL), std::string(NETWORK),
					std::string(LOCATION)),
			detectionformats::source(std::string(AGENCYID),
					std::string(AUTHOR)), std::string(PHASE),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			CORRELATION,
			detectionformats::hypo(LATITUDE, LONGITUDE,
					detectionformats::ConvertISO8601ToEpochTime(
							std::string(ORIGINTIME)), DEPTH, LATITUDEERROR,
					LONGITUDEERROR, TIMEERROR, DEPTHERROR),
			std::string(EVENTTYPE),
			MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
			std::string(THRESHOLDTYPE),
			detectionformats::associated(std::string(ASSOCPHASE), ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA));

	// check data values
	checkdata(correlationobject_altc, "Tested Alternate Constructor");
}

// tests to see if correlation can successfully
// be copy constructed
TEST(CorrelationTest, CopyConstructor) {
	// use constructor
	detectionformats::correlation fromcorrelationobject(std::string(ID),
			std::string(SITEID), std::string(STATION), std::string(CHANNEL),
			std::string(NETWORK), std::string(LOCATION), std::string(AGENCYID),
			std::string(AUTHOR), std::string(PHASE),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			CORRELATION, LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(ORIGINTIME)), DEPTH, LATITUDEERROR,
			LONGITUDEERROR, TIMEERROR, DEPTHERROR, std::string(EVENTTYPE),
			MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
			std::string(THRESHOLDTYPE), std::string(ASSOCPHASE), ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

	detectionformats::correlation correlationobject(fromcorrelationobject);

	// check data values
	checkdata(correlationobject, "");
}

// tests to see if correlation can successfully
// validate
TEST(CorrelationTest, Validate) {
	detectionformats::correlation correlationobject;

	// build correlation object
	correlationobject.id = std::string(ID);

	// site subobject
	correlationobject.site.siteid = std::string(SITEID);
	correlationobject.site.station = std::string(STATION);
	correlationobject.site.channel = std::string(CHANNEL);
	correlationobject.site.network = std::string(NETWORK);
	correlationobject.site.location = std::string(LOCATION);

	// source subobject
	correlationobject.source.agencyid = std::string(AGENCYID);
	correlationobject.source.author = std::string(AUTHOR);

	correlationobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	correlationobject.phase = std::string(PHASE);
	correlationobject.correlationvalue = CORRELATION;
	correlationobject.hypocenter.latitude = LATITUDE;
	correlationobject.hypocenter.longitude = LONGITUDE;
	correlationobject.hypocenter.time =
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(ORIGINTIME));
	correlationobject.hypocenter.depth = DEPTH;
	correlationobject.hypocenter.latitudeerror = LATITUDEERROR;
	correlationobject.hypocenter.longitudeerror = LONGITUDEERROR;
	correlationobject.hypocenter.timeerror = TIMEERROR;
	correlationobject.hypocenter.deptherror = DEPTHERROR;
	correlationobject.eventtype = std::string(EVENTTYPE);
	correlationobject.magnitude = MAGNITUDE;
	correlationobject.snr = SNR;
	correlationobject.zscore = ZSCORE;
	correlationobject.detectionthreshold = DETECTIONTHRESHOLD;
	correlationobject.thresholdtype = std::string(THRESHOLDTYPE);

	// association subobject
	correlationobject.associationinfo.phase = std::string(ASSOCPHASE);
	correlationobject.associationinfo.distance = ASSOCDISTANCE;
	correlationobject.associationinfo.azimuth = ASSOCAZIMUTH;
	correlationobject.associationinfo.residual = ASSOCRESIDUAL;
	correlationobject.associationinfo.sigma = ASSOCSIGMA;

	// successful validation
	bool result = correlationobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad correlation object
	detectionformats::correlation badcorrelationobject;
	badcorrelationobject.id = "";

	result = false;
	try {
		// call validation
		result = badcorrelationobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
