#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::beam beamobject, std::string testinfo) {
	// check backazimuth
	if (std::isnan(beamobject.backazimuth) != true) {
		double beambackazimuth = beamobject.backazimuth;
		double expectedbackazimuth = BACKAZIMUTH;
		ASSERT_EQ(beambackazimuth, expectedbackazimuth);
	}

	// check backazimutherror
	if (std::isnan(beamobject.backazimutherror) != true) {
		double beambackazimutherror = beamobject.backazimutherror;
		double expectedbackazimutherror = BACKAZIMUTHERROR;
		ASSERT_EQ(beambackazimutherror, expectedbackazimutherror);
	}
	// check slowness
	if (std::isnan(beamobject.slowness) != true) {
		double beamslowness = beamobject.slowness;
		double expectedslowness = SLOWNESS;
		ASSERT_EQ(beamslowness, expectedslowness);
	}

	// check slownesserror
	if (std::isnan(beamobject.slownesserror) != true) {
		double beamslownesserrorr = beamobject.slownesserror;
		double expectedslownesserror = SLOWNESSERROR;
		ASSERT_EQ(beamslownesserrorr, expectedslownesserror);
	}
	// check powerratio
	if (std::isnan(beamobject.powerratio) != true) {
		double beampowerratio = beamobject.powerratio;
		double expectedpowerratio = POWERRATIO;
		ASSERT_EQ(beampowerratio, expectedpowerratio);
	}

	// check powerratioerror
	if (std::isnan(beamobject.powerratioerror) != true) {
		double beampowerratioerrorr = beamobject.powerratioerror;
		double expectedpowerratioerror = POWERRATIOERROR;
		ASSERT_EQ(beampowerratioerrorr, expectedpowerratioerror);
	}
}

// tests to see if beam can successfully
// write json output
TEST(BeamTest, WritesJSON) {
	detectionformats::beam beamobject;

	beamobject.backazimuth = BACKAZIMUTH;
	beamobject.backazimutherror = BACKAZIMUTHERROR;
	beamobject.slowness = SLOWNESS;
	beamobject.slownesserror = SLOWNESSERROR;
	beamobject.powerratio = POWERRATIO;
	beamobject.powerratioerror = POWERRATIOERROR;

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
	detectionformats::beam beamobject(BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS,
	SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

	// check data values
	checkdata(beamobject, "Tested constructor.");

	// json constructor (empty)
    rapidjson::Value emptyvalue(rapidjson::kObjectType);
    detectionformats::beam beamobject2(emptyvalue);

    // check data values
	checkdata(beamobject2, "");
}

// tests to see if beam can successfully
// be copy constructed
TEST(BeamTest, CopyConstructor) {
	// use constructor
	detectionformats::beam frombeamobject(BACKAZIMUTH, BACKAZIMUTHERROR,
	SLOWNESS, SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

	detectionformats::beam beamobject(frombeamobject);

	// check data values
	checkdata(beamobject, "");
}

// tests to see if beam can successfully
// validate
TEST(BeamTest, Validate) {
	detectionformats::beam beamobject;

	beamobject.backazimuth = BACKAZIMUTH;
	beamobject.backazimutherror = BACKAZIMUTHERROR;
	beamobject.slowness = SLOWNESS;
	beamobject.slownesserror = SLOWNESSERROR;
	beamobject.powerratio = POWERRATIO;
	beamobject.powerratioerror = POWERRATIOERROR;

	// successful validation
	bool result = beamobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad beam object
	detectionformats::beam badbeamobject1;

	result = false;
	try {
		// call validation
		result = badbeamobject1.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation 1.";

	// build bad beam object
	detectionformats::beam badbeamobject2;
	badbeamobject2.backazimuth = -1;
	badbeamobject2.slowness = -1;
	badbeamobject2.powerratio = -1;
	badbeamobject2.backazimutherror = -1;
	badbeamobject2.slownesserror = -1;
	badbeamobject2.powerratioerror = -1;

	result = false;
	try {
		// call validation
		result = badbeamobject2.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation 2.";

}

// tests the isempty function
TEST(BeamTest, IsEmpty) {
	detectionformats::beam beamobject;

	// check return
	ASSERT_TRUE(beamobject.isempty()) << "Tested for empty.";

	// build beam object
	beamobject.backazimuth = BACKAZIMUTH;

	// check return
	ASSERT_FALSE(beamobject.isempty()) << "Tested for not empty.";
}
