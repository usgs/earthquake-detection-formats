#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define ORIGINSTRING "{\"Type\":\"Origin\",\"ID\":\"12GFH48776857\",\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44,\"Time\":\"2015-12-28T21:32:24.017Z\",\"OriginType\":\"New\",\"EventType\":\"earthquake\",\"Bayes\":2.65,\"MinimumDistance\":2.14,\"RMS\":3.8,\"Gap\":33.67,\"Data\":[{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65}],\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}},{\"Type\":\"Beam\",\"ID\":\"12GFH48776857\",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"BackAzimuth\":2.65,\"Slowness\":1.44,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}},{\"Type\":\"Correlation\",\"ID\":\"12GFH48776857\",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Phase\":\"P\",\"Time\":\"2015-12-28T21:32:24.017Z\",\"Correlation\":2.65,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44,\"OriginTime\":\"2015-12-28T21:30:44.039Z\",\"EventType\":\"earthquake\",\"Magnitude\":2.14,\"SNR\":3.8,\"ZScore\":33.67,\"DetectionThreshold\":1.5,\"ThresholdType\":\"minimum\",\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}]}"
#define ID "12GFH48776857"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"
#define LATITUDE 40.3344
#define LONGITUDE -121.44
#define TIME "2015-12-28T21:32:24.017Z"
#define DEPTH 32.44
#define ORIGINTYPE "New"
#define EVENTTYPE "earthquake"
#define BAYES 2.65
#define MINIMUMDISTANCE 2.14
#define RMS 3.8
#define GAP 33.67
#define PICKDATA "{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65}],\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}"
#define BEAMDATA "{\"Type\":\"Beam\",\"ID\":\"12GFH48776857\",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"StartTime\":\"2015-12-28T21:32:24.017Z\",\"EndTime\":\"2015-12-28T21:32:30.017Z\",\"BackAzimuth\":2.65,\"Slowness\":1.44,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}"
#define CORRELATIONDATA "{\"Type\":\"Correlation\",\"ID\":\"12GFH48776857\",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Phase\":\"P\",\"Time\":\"2015-12-28T21:32:24.017Z\",\"Correlation\":2.65,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44,\"OriginTime\":\"2015-12-28T21:30:44.039Z\",\"EventType\":\"earthquake\",\"Magnitude\":2.14,\"SNR\":3.8,\"ZScore\":33.67,\"DetectionThreshold\":1.5,\"ThresholdType\":\"minimum\",\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}"

std::vector<detectionformats::pick> buildpickdata()
{
	std::vector<detectionformats::pick> newpickdata;

	// pick ?need one more?
	rapidjson::Document pickdocument;
	detectionformats::pick pickobject(detectionformats::FromJSONString(std::string(PICKDATA), pickdocument));
	newpickdata.push_back(pickobject);

	return(newpickdata);
}

std::vector<detectionformats::beam> buildbeamdata()
{
	std::vector<detectionformats::beam> newbeamdata;

	// beam ?need one more?
	rapidjson::Document beamdocument;
	detectionformats::beam beamobject(detectionformats::FromJSONString(std::string(BEAMDATA), beamdocument));
	newbeamdata.push_back(beamobject);

	return(newbeamdata);
}

std::vector<detectionformats::correlation> buildcorrleationdata()
{
	std::vector<detectionformats::correlation> newcorrelationdata;

	// correlation ?need one more?
	rapidjson::Document correlationdocument;
	detectionformats::correlation correlationobject(detectionformats::FromJSONString(std::string(CORRELATIONDATA), correlationdocument));
	newcorrelationdata.push_back(correlationobject);

	return(newcorrelationdata);
}

void checkdata(detectionformats::origin originobject, std::string testinfo)
{
	// check id
	std::string originid = originobject.id;
	std::string expectedid = std::string(ID);
	ASSERT_STREQ(originid.c_str(), expectedid.c_str());

	// check agencyid
	std::string sourceagencyid = originobject.source.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());

	// check author
	std::string sourceauthor = originobject.source.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());

	// check latitude
	double originlatitude = originobject.latitude;
	double expectedlatitude = LATITUDE;
	ASSERT_EQ(originlatitude, expectedlatitude);

	// check longitude
	double originlongitude = originobject.longitude;
	double expectedlongitude = LONGITUDE;
	ASSERT_EQ(originlongitude, expectedlongitude);

	// check time
	double origintime = originobject.time;
	double expectedtime = detectionformats::ConvertISO8601ToEpochTime(std::string(TIME));
	ASSERT_EQ(origintime, expectedtime);

	// check depth
	double origindepth = originobject.depth;
	double expecteddepth = DEPTH;
	ASSERT_EQ(origindepth, expecteddepth);

	// check origintype
	std::string originorigintype = originobject.origintype;
	std::string expecteddetectiontype = std::string(ORIGINTYPE);
	ASSERT_STREQ(originorigintype.c_str(), expecteddetectiontype.c_str());

	// check eventtype
	std::string origineventtype = originobject.eventtype;
	std::string expectedeventtype = std::string(EVENTTYPE);
	ASSERT_STREQ(origineventtype.c_str(), expectedeventtype.c_str());

	// check bayes
	double originbayes = originobject.bayes;
	double expectedbayes = BAYES;
	ASSERT_EQ(originbayes, expectedbayes);

	// check minimumdistance
	double originminimumdistance = originobject.minimumdistance;
	double expectedminimumdistancee = MINIMUMDISTANCE;
	ASSERT_EQ(originminimumdistance, expectedminimumdistancee);

	// check rms
	double originrms = originobject.rms;
	double expectedrms = RMS;
	ASSERT_EQ(originrms, expectedrms);

	// check gap
	double origingap = originobject.gap;
	double expectedgap = GAP;
	ASSERT_EQ(origingap, expectedgap);

	// need to check data still!!!!!!
	// somehow?


}

// tests to see if origin can successfully
// write json output
TEST(OriginTest, WritesJSON)
{
	detectionformats::origin originobject;

	// build origin object
	originobject.id = std::string(ID);

	// source subobject
	originobject.source.agencyid = std::string(AGENCYID);
	originobject.source.author = std::string(AUTHOR);

	originobject.latitude = LATITUDE;
	originobject.longitude = LONGITUDE;
	originobject.time = detectionformats::ConvertISO8601ToEpochTime(std::string(TIME));
	originobject.depth = DEPTH;
	originobject.origintype = std::string(ORIGINTYPE);
	originobject.eventtype = std::string(EVENTTYPE);
	originobject.bayes = BAYES;
	originobject.minimumdistance = MINIMUMDISTANCE;
	originobject.rms = RMS;
	originobject.gap = GAP;

	// data
	originobject.pickdata = buildpickdata();
	originobject.beamdata = buildbeamdata();
	originobject.correlationdata = buildcorrleationdata();

	// build json string
	rapidjson::Document origindocument;
	std::string originjson = detectionformats::ToJSONString(originobject.tojson(origindocument, origindocument.GetAllocator()));

    // read it back in
    rapidjson::Document origindocument2;
    detectionformats::origin originobject2(detectionformats::FromJSONString(originjson, origindocument2));

    // check data values
    checkdata(originobject2, "");
}

// tests to see if origin can successfully
// read json output
TEST(OriginTest, ReadsJSON)
{
	// build associated object
	rapidjson::Document origindocument;
	detectionformats::origin originobject(detectionformats::FromJSONString(std::string(ORIGINSTRING), origindocument));

	// check data values
	checkdata(originobject, "");
}

// tests to see if origin can successfully
// be constructed
TEST(OriginTest, Constructor)
{
	// use constructor
	detectionformats::origin originobject(std::string(ID), std::string(AGENCYID), std::string(AUTHOR), LATITUDE, LONGITUDE, detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),  DEPTH, std::string(ORIGINTYPE), std::string(EVENTTYPE),
		BAYES, MINIMUMDISTANCE, RMS, GAP, buildpickdata(), buildbeamdata(), buildcorrleationdata());

	// check data values
	checkdata(originobject, "Tested Constructor");

	detectionformats::origin originobject_altc(std::string(ID), detectionformats::source(std::string(AGENCYID), std::string(AUTHOR)), LATITUDE, LONGITUDE, detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)), DEPTH, std::string(ORIGINTYPE),
		std::string(EVENTTYPE), BAYES, MINIMUMDISTANCE, RMS, GAP, buildpickdata(), buildbeamdata(), buildcorrleationdata());

	// check data values
	checkdata(originobject_altc, "Tested Alternate Constructor");
}

// tests to see if origin can successfully
// be copy constructed
TEST(OriginTest, CopyConstructor)
{
	// use constructor
	detectionformats::origin fromoriginobject(std::string(ID), std::string(AGENCYID), std::string(AUTHOR), LATITUDE, LONGITUDE, detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)), DEPTH, std::string(ORIGINTYPE), std::string(EVENTTYPE),
		BAYES, MINIMUMDISTANCE, RMS, GAP, buildpickdata(), buildbeamdata(), buildcorrleationdata());

	detectionformats::origin originobject(fromoriginobject);

	// check data values
	checkdata(originobject, "");
}

// tests to see if origin can successfully
// validate
TEST(OriginTest, Validate)
{
	detectionformats::origin originobject;

	// build origin object
	originobject.id = std::string(ID);

	// source subobject
	originobject.source.agencyid = std::string(AGENCYID);
	originobject.source.author = std::string(AUTHOR);

	originobject.latitude = LATITUDE;
	originobject.longitude = LONGITUDE;
	originobject.time = detectionformats::ConvertISO8601ToEpochTime(std::string(TIME));
	originobject.depth = DEPTH;
	originobject.origintype = std::string(ORIGINTYPE);
	originobject.eventtype = std::string(EVENTTYPE);
	originobject.bayes = BAYES;
	originobject.minimumdistance = MINIMUMDISTANCE;
	originobject.rms = RMS;
	originobject.gap = GAP;

	// data
	originobject.pickdata = buildpickdata();
	originobject.beamdata = buildbeamdata();
	originobject.correlationdata = buildcorrleationdata();

	// successful validation
	bool result = originobject.isvalid();

	// check return code
	ASSERT_EQ(result, true) << "Tested for successful validation.";

	// build bad origin object
	detectionformats::origin badoriginobject;
	badoriginobject.id = "";

	result = false;
	try
	{
		// call validation
		result = badoriginobject.isvalid();
	}
	catch (const std::exception &)
	{
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false) << "Tested for unsuccessful validation.";
}
