#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define BEAMSTRING "{\"Type\":\"Beam\",\"ID\":\"12GFH48776857\",\"Site\":{\"SiteID\":\"BMN.HHZ.LB.01\",\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"StartTime\":\"2015-12-28T21:32:24.017Z\",\"EndTime\":\"2015-12-28T21:32:30.017Z\",\"BackAzimuth\":2.65,\"Slowness\":1.44,\"Power\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerError\":0.557,\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}"
#define ID "12GFH48776857"
#define STATION "BMN"
#define CHANNEL "HHZ"
#define NETWORK "LB"
#define LOCATION "01"
#define SITEID "BMN.HHZ.LB.01"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"
#define STARTTIME "2015-12-28T21:32:24.017Z"
#define ENDTIME "2015-12-28T21:32:30.017Z"
#define BACKAZIMUTH 2.65
#define BACKAZIMUTHERROR 3.8
#define SLOWNESS 1.44
#define SLOWNESSERROR 0.4
#define POWER 12.18
#define POWERERROR 0.557
#define ASSOCPHASE "P"
#define ASSOCDISTANCE 0.442559
#define ASSOCAZIMUTH 0.418479
#define ASSOCRESIDUAL -0.025393
#define ASSOCSIGMA 0.086333

void checkdata(detectionformats::beam beamobject, std::string testinfo) {
	// check id
	std::string beamid = beamobject.id;
	std::string expectedid = std::string(ID);
	ASSERT_STREQ(beamid.c_str(), expectedid.c_str());

	// check station
	std::string sitestation = beamobject.site.station;
	std::string expectedstation = std::string(STATION);
	ASSERT_STREQ(sitestation.c_str(), expectedstation.c_str());

	// check channel
	std::string sitechannel = beamobject.site.channel;
	std::string expectedchannel = std::string(CHANNEL);
	ASSERT_STREQ(sitechannel.c_str(), expectedchannel.c_str());

	// check network
	std::string sitenetwork = beamobject.site.network;
	std::string expectednetwork = std::string(NETWORK);
	ASSERT_STREQ(sitenetwork.c_str(), expectednetwork.c_str());

	// check location
	std::string sitelocation = beamobject.site.location;
	std::string expectedlocation = std::string(LOCATION);
	ASSERT_STREQ(sitelocation.c_str(), expectedlocation.c_str());

	// check siteid
	std::string sitesiteid = beamobject.site.siteid;
	std::string expectedsiteid = std::string(SITEID);
	ASSERT_STREQ(sitesiteid.c_str(), expectedsiteid.c_str());

	// check agencyid
	std::string sourceagencyid = beamobject.source.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());

	// check author
	std::string sourceauthor = beamobject.source.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());

	// check start time
	double beamstarttime = beamobject.starttime;
	double expectedstarttime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(STARTTIME));
	ASSERT_EQ(beamstarttime, expectedstarttime);

	// check end time
	double beamendtime = beamobject.endtime;
	double expectedendtime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(ENDTIME));
	ASSERT_EQ(beamendtime, expectedendtime);

	// check backazimuth
	double beambackazimuth = beamobject.backazimuth;
	double expectedbackazimuth = BACKAZIMUTH;
	ASSERT_EQ(beambackazimuth, expectedbackazimuth);

	// check backazimutherror
	double beambackazimutherror = beamobject.backazimutherror;
	double expectedbackazimutherror = BACKAZIMUTHERROR;
	ASSERT_EQ(beambackazimutherror, expectedbackazimutherror);

	// check slowness
	double beamslowness = beamobject.slowness;
	double expectedslowness = SLOWNESS;
	ASSERT_EQ(beamslowness, expectedslowness);

	// check slownesserror
	double beamslownesserrorr = beamobject.slownesserror;
	double expectedslownesserror = SLOWNESSERROR;
	ASSERT_EQ(beamslownesserrorr, expectedslownesserror);

	// check power
	double beampower = beamobject.power;
	double expectedpower = POWER;
	ASSERT_EQ(beampower, expectedpower);

	// check powererror
	double beampowererrorr = beamobject.powererror;
	double expectedpowererror = POWERERROR;
	ASSERT_EQ(beampowererrorr, expectedpowererror);

	// check phase
	std::string associatedphase = beamobject.associationinfo.phase;
	std::string expectedphase = std::string(ASSOCPHASE);
	ASSERT_STREQ(associatedphase.c_str(), expectedphase.c_str());

	// check distance
	double associateddistance = beamobject.associationinfo.distance;
	double expecteddistance = ASSOCDISTANCE;
	ASSERT_EQ(associateddistance, expecteddistance);

	// check azimuth
	double associatedazimuth = beamobject.associationinfo.azimuth;
	double expectedazimuth = ASSOCAZIMUTH;
	ASSERT_EQ(associatedazimuth, expectedazimuth);

	// check residual
	double associatedresidual = beamobject.associationinfo.residual;
	double expectedresidual = ASSOCRESIDUAL;
	ASSERT_EQ(associatedresidual, expectedresidual);

	// check sigma
	double associatedsigma = beamobject.associationinfo.sigma;
	double expectedsigma = ASSOCSIGMA;
	ASSERT_EQ(associatedsigma, expectedsigma);
}

// tests to see if beam can successfully
// write json output
TEST(BeamTest, WritesJSON) {
	detectionformats::beam beamobject;

	// build beam object
	beamobject.id = std::string(ID);

	// site subobject
	beamobject.site.siteid = std::string(SITEID);
	beamobject.site.station = std::string(STATION);
	beamobject.site.channel = std::string(CHANNEL);
	beamobject.site.network = std::string(NETWORK);
	beamobject.site.location = std::string(LOCATION);

	// source subobject
	beamobject.source.agencyid = std::string(AGENCYID);
	beamobject.source.author = std::string(AUTHOR);

	beamobject.starttime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(STARTTIME));
	beamobject.endtime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(ENDTIME));
	beamobject.backazimuth = BACKAZIMUTH;
	beamobject.backazimutherror = BACKAZIMUTHERROR;
	beamobject.slowness = SLOWNESS;
	beamobject.slownesserror = SLOWNESSERROR;
	beamobject.power = POWER;
	beamobject.powererror = POWERERROR;

	// association subobject
	beamobject.associationinfo.phase = std::string(ASSOCPHASE);
	beamobject.associationinfo.distance = ASSOCDISTANCE;
	beamobject.associationinfo.azimuth = ASSOCAZIMUTH;
	beamobject.associationinfo.residual = ASSOCRESIDUAL;
	beamobject.associationinfo.sigma = ASSOCSIGMA;

	// build json string
	rapidjson::Document beamdocument;
	std::string beamjson = detectionformats::ToJSONString(
			beamobject.tojson(beamdocument, beamdocument.GetAllocator()));

	// read it back in
	rapidjson::Document beamdocument2;
	detectionformats::beam beamobject2(
			detectionformats::FromJSONString(beamjson, beamdocument2));

	// check data values
	checkdata(beamobject2, "");
}

// tests to see if beam can successfully
// read json output
TEST(BeamTest, ReadsJSON) {
	// build beam object
	rapidjson::Document beamdocument;
	detectionformats::beam beamobject(
			detectionformats::FromJSONString(std::string(BEAMSTRING),
					beamdocument));

	// check data values
	checkdata(beamobject, "");
}

// tests to see if beam can successfully
// be constructed
TEST(BeamTest, Constructor) {
	// use constructor
	detectionformats::beam beamobject(std::string(ID), std::string(SITEID),
			std::string(STATION), std::string(CHANNEL), std::string(NETWORK),
			std::string(LOCATION), std::string(AGENCYID), std::string(AUTHOR),
			detectionformats::ConvertISO8601ToEpochTime(std::string(STARTTIME)),
			detectionformats::ConvertISO8601ToEpochTime(std::string(ENDTIME)),
			BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWER,
			POWERERROR,
			std::string(ASSOCPHASE), ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

	// check data values
	checkdata(beamobject, "Tested constructor.");

	// use alternate constructor
	detectionformats::beam beamobject_altc(std::string(ID),
			detectionformats::site(std::string(SITEID), std::string(STATION),
					std::string(CHANNEL), std::string(NETWORK),
					std::string(LOCATION)),
			detectionformats::source(std::string(AGENCYID),
					std::string(AUTHOR)),
			detectionformats::ConvertISO8601ToEpochTime(std::string(STARTTIME)),
			detectionformats::ConvertISO8601ToEpochTime(std::string(ENDTIME)),
			BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWER, POWERERROR,
			detectionformats::associated(std::string(ASSOCPHASE), ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA));

	// check data values
	checkdata(beamobject_altc, "Tested alternate constructor.");
}

// tests to see if beam can successfully
// be copy constructed
TEST(BeamTest, CopyConstructor) {
	// use constructor
	detectionformats::beam frombeamobject(std::string(ID), std::string(SITEID),
			std::string(STATION), std::string(CHANNEL), std::string(NETWORK),
			std::string(LOCATION), std::string(AGENCYID), std::string(AUTHOR),
			detectionformats::ConvertISO8601ToEpochTime(std::string(STARTTIME)),
			detectionformats::ConvertISO8601ToEpochTime(std::string(ENDTIME)),
			BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWER, POWERERROR,
			std::string(ASSOCPHASE), ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

	detectionformats::beam beamobject(frombeamobject);

	// check data values
	checkdata(beamobject, "");
}

// tests to see if beam can successfully
// validate
TEST(BeamTest, Validate) {
	detectionformats::beam beamobject;

	// build beam object
	beamobject.id = std::string(ID);

	// site subobject
	beamobject.site.siteid = std::string(SITEID);
	beamobject.site.station = std::string(STATION);
	beamobject.site.channel = std::string(CHANNEL);
	beamobject.site.network = std::string(NETWORK);
	beamobject.site.location = std::string(LOCATION);

	// source subobject
	beamobject.source.agencyid = std::string(AGENCYID);
	beamobject.source.author = std::string(AUTHOR);

	beamobject.starttime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(STARTTIME));
	beamobject.endtime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(ENDTIME));
	beamobject.backazimuth = BACKAZIMUTH;
	beamobject.backazimutherror = BACKAZIMUTHERROR;
	beamobject.slowness = SLOWNESS;
	beamobject.slownesserror = SLOWNESSERROR;
	beamobject.power = POWER;
	beamobject.powererror = POWERERROR;

	// association subobject
	beamobject.associationinfo.phase = std::string(ASSOCPHASE);
	beamobject.associationinfo.distance = ASSOCDISTANCE;
	beamobject.associationinfo.azimuth = ASSOCAZIMUTH;
	beamobject.associationinfo.residual = ASSOCRESIDUAL;
	beamobject.associationinfo.sigma = ASSOCSIGMA;

	// successful validation
	bool result = beamobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad beam object
	detectionformats::beam badbeamobject;
	beamobject.id = "";

	result = false;
	try {
		// call validation
		result = badbeamobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
