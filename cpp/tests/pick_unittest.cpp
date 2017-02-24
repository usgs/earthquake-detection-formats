#include "detection-formats.h"
#include <gtest/gtest.h>

#include <string>

// test data
#define PICKSTRING "{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65},{\"HighPass\":2.10,\"LowPass\":3.58}],\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},\"Beam\":{\"BackAzimuth\":2.65,\"Slowness\":1.44,\"PowerRatio\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerRatioError\":0.557},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}"
#define PICKSTRINGNOFILTER "{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[],\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},\"Beam\":{\"BackAzimuth\":2.65,\"Slowness\":1.44,\"PowerRatio\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerRatioError\":0.557},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}"

#define ID "12GFH48776857"
#define STATION "BMN"
#define CHANNEL "HHZ"
#define NETWORK "LB"
#define LOCATION "01"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"
#define TIME "2015-12-28T21:32:24.017Z"
#define PHASE "P"
#define POLARITY "up"
#define ONSET "questionable"
#define PICKER "manual"
#define HIGHPASS 1.05
#define LOWPASS 2.65
#define HIGHPASS2 2.10
#define LOWPASS2 3.58
#define AMPLITUDEVALUE 21.5
#define PERIOD 2.65
#define SNR 3.8
#define BACKAZIMUTH 2.65
#define BACKAZIMUTHERROR 3.8
#define SLOWNESS 1.44
#define SLOWNESSERROR 0.4
#define POWERRATIO 12.18
#define POWERRATIOERROR 0.557
#define ASSOCPHASE "P"
#define ASSOCDISTANCE 0.442559
#define ASSOCAZIMUTH 0.418479
#define ASSOCRESIDUAL -0.025393
#define ASSOCSIGMA 0.086333

void checkdata(detectionformats::pick pickobject, std::string testinfo) {
	// check id
	std::string pickid = pickobject.id;
	std::string expectedid = std::string(ID);
	ASSERT_STREQ(pickid.c_str(), expectedid.c_str())<< testinfo.c_str();

	// check station
	std::string sitestation = pickobject.site.station;
	std::string expectedstation = std::string(STATION);
	ASSERT_STREQ(sitestation.c_str(), expectedstation.c_str())<< testinfo.c_str();

	// check channel
	std::string sitechannel = pickobject.site.channel;
	std::string expectedchannel = std::string(CHANNEL);
	ASSERT_STREQ(sitechannel.c_str(), expectedchannel.c_str())<< testinfo.c_str();

	// check network
	std::string sitenetwork = pickobject.site.network;
	std::string expectednetwork = std::string(NETWORK);
	ASSERT_STREQ(sitenetwork.c_str(), expectednetwork.c_str())<< testinfo.c_str();

	// check location
	std::string sitelocation = pickobject.site.location;
	std::string expectedlocation = std::string(LOCATION);
	ASSERT_STREQ(sitelocation.c_str(), expectedlocation.c_str())<< testinfo.c_str();

	// check agencyid
	std::string sourceagencyid = pickobject.source.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str())<< testinfo.c_str();

	// check author
	std::string sourceauthor = pickobject.source.author;
	std::string expectedauthor = std::string(AUTHOR);
	ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str())<< testinfo.c_str();

	// check time
	double picktime = pickobject.time;
	double expectedtime = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	ASSERT_EQ(picktime, expectedtime)<< testinfo.c_str();

	// check phase
	if (pickobject.phase.compare("") != true) {
		std::string pickphase = pickobject.phase;
		std::string expectedphase = std::string(PHASE);
		ASSERT_STREQ(pickphase.c_str(), expectedphase.c_str())<< testinfo.c_str();
	}

	// check polarity
	if (pickobject.polarity.compare("") != true) {
		std::string pickpolarity = pickobject.polarity;
		std::string expectedpolarity = std::string(POLARITY);
		ASSERT_STREQ(pickpolarity.c_str(), expectedpolarity.c_str())<< testinfo.c_str();
	}

	// check onset
	if (pickobject.onset.compare("") != true) {
		std::string pickonset = pickobject.onset;
		std::string expectedonset = std::string(ONSET);
		ASSERT_STREQ(pickonset.c_str(), expectedonset.c_str())<< testinfo.c_str();
	}

	// check picker
	if (pickobject.picker.compare("") != true) {
		std::string pickpicker = pickobject.picker;
		std::string expectedpicker = std::string(PICKER);
		ASSERT_STREQ(pickpicker.c_str(), expectedpicker.c_str())<< testinfo.c_str();
	}

	// filter
	if (pickobject.filterdata.size() > 0) {
		// check lowpass
		if (std::isnan(pickobject.filterdata[0].lowpass) != true) {
			double filterlowpass = pickobject.filterdata[0].lowpass;
			double expectedlowpass = LOWPASS;
			ASSERT_EQ(filterlowpass, expectedlowpass)<< testinfo.c_str();
		}

		// check highpass
		if (std::isnan(pickobject.filterdata[0].highpass) != true) {
			double filterhighpass = pickobject.filterdata[0].highpass;
			double expectedhighpass = HIGHPASS;
			ASSERT_EQ(filterhighpass, expectedhighpass)<< testinfo.c_str();
		}

		if (pickobject.filterdata.size() > 1) {
			// check lowpass2
			if (std::isnan(pickobject.filterdata[1].lowpass) != true) {
				double filterlowpass2 = pickobject.filterdata[1].lowpass;
				double expectedlowpass2 = LOWPASS2;
				ASSERT_EQ(filterlowpass2, expectedlowpass2)<< testinfo.c_str();
			}

			// check highpass2
			if (std::isnan(pickobject.filterdata[1].highpass) != true) {
				double filterhighpass2 = pickobject.filterdata[1].highpass;
				double expectedhighpass2 = HIGHPASS2;
				ASSERT_EQ(filterhighpass2, expectedhighpass2)<< testinfo.c_str();
			}
		}
	}

	// amplitude
	if (pickobject.amplitude.isempty() == false) {
		// check period
		if (std::isnan(pickobject.amplitude.period) != true) {
			double amplitudeperiod = pickobject.amplitude.period;
			double expectedperiod = PERIOD;
			ASSERT_EQ(amplitudeperiod, expectedperiod)<< testinfo.c_str();
		}
		// check amplitude
		if (std::isnan(pickobject.amplitude.ampvalue) != true) {
			double amplitudeamplitude = pickobject.amplitude.ampvalue;
			double expectedamplitude = AMPLITUDEVALUE;
			ASSERT_EQ(amplitudeamplitude, expectedamplitude)<< testinfo.c_str();
		}
		// check snr
		if (std::isnan(pickobject.amplitude.snr) != true) {
			double amplitudesnr = pickobject.amplitude.snr;
			double expectedsnr = SNR;
			ASSERT_EQ(amplitudesnr, expectedsnr)<< testinfo.c_str();
		}
	}

	// beam
	if (pickobject.beam.isempty() == false) {

		// check backazimuth
		double beambackazimuth = pickobject.beam.backazimuth;
		double expectedbackazimuth = BACKAZIMUTH;
		ASSERT_EQ(beambackazimuth, expectedbackazimuth);

		// check backazimutherror
		if (std::isnan(pickobject.beam.backazimutherror) != true) {
			double beambackazimutherror = pickobject.beam.backazimutherror;
			double expectedbackazimutherror = BACKAZIMUTHERROR;
			ASSERT_EQ(beambackazimutherror, expectedbackazimutherror);
		}
		// check slowness
		double beamslowness = pickobject.beam.slowness;
		double expectedslowness = SLOWNESS;
		ASSERT_EQ(beamslowness, expectedslowness);

		// check slownesserror
		if (std::isnan(pickobject.beam.slownesserror) != true) {
			double beamslownesserrorr = pickobject.beam.slownesserror;
			double expectedslownesserror = SLOWNESSERROR;
			ASSERT_EQ(beamslownesserrorr, expectedslownesserror);
		}
		// check powerratio
		if (std::isnan(pickobject.beam.powerratio) != true) {
			double beampowerratio = pickobject.beam.powerratio;
			double expectedpowerratio = POWERRATIO;
			ASSERT_EQ(beampowerratio, expectedpowerratio);
		}

		// check powerratioerror
		if (std::isnan(pickobject.beam.powerratioerror) != true) {
			double beampowerratioerrorr = pickobject.beam.powerratioerror;
			double expectedpowerratioerror = POWERRATIOERROR;
			ASSERT_EQ(beampowerratioerrorr, expectedpowerratioerror);
		}
	}

	// associationinfo
	if (pickobject.associationinfo.isempty() == false) {

		// check phase
		if (pickobject.associationinfo.phase.compare("") != true) {
			std::string associatedphase = pickobject.associationinfo.phase;
			std::string expectedassociatedphase = std::string(ASSOCPHASE);
			ASSERT_STREQ(associatedphase.c_str(), expectedassociatedphase.c_str())<< testinfo.c_str();
		}
		// check distance
		if (std::isnan(pickobject.associationinfo.distance) != true) {
			double associateddistance = pickobject.associationinfo.distance;
			double expecteddistance = ASSOCDISTANCE;
			ASSERT_EQ(associateddistance, expecteddistance)<< testinfo.c_str();
		}

		// check azimuth
		if (std::isnan(pickobject.associationinfo.azimuth) != true) {
			double associatedazimuth = pickobject.associationinfo.azimuth;
			double expectedazimuth = ASSOCAZIMUTH;
			ASSERT_EQ(associatedazimuth, expectedazimuth)<< testinfo.c_str();
		}

		// check residual
		if (std::isnan(pickobject.associationinfo.residual) != true) {
			double associatedresidual = pickobject.associationinfo.residual;
			double expectedresidual = ASSOCRESIDUAL;
			ASSERT_EQ(associatedresidual, expectedresidual)<< testinfo.c_str();
		}

		// check sigma
		if (std::isnan(pickobject.associationinfo.sigma) != true) {
			double associatedsigma = pickobject.associationinfo.sigma;
			double expectedsigma = ASSOCSIGMA;
			ASSERT_EQ(associatedsigma, expectedsigma)<< testinfo.c_str();
		}
	}
}

// tests to see if pick can successfully
// write json output
TEST(PickTest, WritesJSON) {
	detectionformats::pick pickobject;

	// build pick object
	pickobject.id = std::string(ID);

	// site subobject
	pickobject.site.station = std::string(STATION);
	pickobject.site.channel = std::string(CHANNEL);
	pickobject.site.network = std::string(NETWORK);
	pickobject.site.location = std::string(LOCATION);

	// source subobject
	pickobject.source.agencyid = std::string(AGENCYID);
	pickobject.source.author = std::string(AUTHOR);

	pickobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	pickobject.phase = std::string(PHASE);
	pickobject.polarity = std::string(POLARITY);
	pickobject.onset = std::string(ONSET);
	pickobject.picker = std::string(PICKER);

	// filter
	detectionformats::filter filterobject;
	filterobject.highpass = HIGHPASS;
	filterobject.lowpass = LOWPASS;
	pickobject.filterdata.push_back(filterobject);

	detectionformats::filter filterobject2;
	filterobject2.highpass = HIGHPASS2;
	filterobject2.lowpass = LOWPASS2;
	pickobject.filterdata.push_back(filterobject2);

	// amplitude
	pickobject.amplitude.ampvalue = AMPLITUDEVALUE;
	pickobject.amplitude.period = PERIOD;
	pickobject.amplitude.snr = SNR;

	// beam
	pickobject.beam.backazimuth = BACKAZIMUTH;
	pickobject.beam.backazimutherror = BACKAZIMUTHERROR;
	pickobject.beam.slowness = SLOWNESS;
	pickobject.beam.slownesserror = SLOWNESSERROR;
	pickobject.beam.powerratio = POWERRATIO;
	pickobject.beam.powerratioerror = POWERRATIOERROR;

	// association subobject
	pickobject.associationinfo.phase = std::string(ASSOCPHASE);
	pickobject.associationinfo.distance = ASSOCDISTANCE;
	pickobject.associationinfo.azimuth = ASSOCAZIMUTH;
	pickobject.associationinfo.residual = ASSOCRESIDUAL;
	pickobject.associationinfo.sigma = ASSOCSIGMA;

	// build json string
	rapidjson::Document pickdocument;
	std::string pickjson = detectionformats::ToJSONString(
			pickobject.tojson(pickdocument, pickdocument.GetAllocator()));

	// read it back in
	rapidjson::Document pickdocument2;
	detectionformats::pick pickobject2(
			detectionformats::FromJSONString(pickjson, pickdocument2));

	// check data values
	checkdata(pickobject2, "");
}

TEST(PickTest, WritesJSONNoFilter) {
	detectionformats::pick pickobject;

	// build pick object
	pickobject.id = std::string(ID);

	// site subobject
	pickobject.site.station = std::string(STATION);
	pickobject.site.channel = std::string(CHANNEL);
	pickobject.site.network = std::string(NETWORK);
	pickobject.site.location = std::string(LOCATION);

	// source subobject
	pickobject.source.agencyid = std::string(AGENCYID);
	pickobject.source.author = std::string(AUTHOR);

	pickobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	pickobject.phase = std::string(PHASE);
	pickobject.polarity = std::string(POLARITY);
	pickobject.onset = std::string(ONSET);
	pickobject.picker = std::string(PICKER);

	// no filters for this test

	// amplitude
	pickobject.amplitude.ampvalue = AMPLITUDEVALUE;
	pickobject.amplitude.period = PERIOD;
	pickobject.amplitude.snr = SNR;

	// beam
	pickobject.beam.backazimuth = BACKAZIMUTH;
	pickobject.beam.backazimutherror = BACKAZIMUTHERROR;
	pickobject.beam.slowness = SLOWNESS;
	pickobject.beam.slownesserror = SLOWNESSERROR;
	pickobject.beam.powerratio = POWERRATIO;
	pickobject.beam.powerratioerror = POWERRATIOERROR;

	// association subobject
	pickobject.associationinfo.phase = std::string(ASSOCPHASE);
	pickobject.associationinfo.distance = ASSOCDISTANCE;
	pickobject.associationinfo.azimuth = ASSOCAZIMUTH;
	pickobject.associationinfo.residual = ASSOCRESIDUAL;
	pickobject.associationinfo.sigma = ASSOCSIGMA;

	// build json string
	rapidjson::Document pickdocument;
	std::string pickjson = detectionformats::ToJSONString(
			pickobject.tojson(pickdocument, pickdocument.GetAllocator()));

	// read it back in
	rapidjson::Document pickdocument2;
	detectionformats::pick pickobject2(
			detectionformats::FromJSONString(pickjson, pickdocument2));

	// check data values
	checkdata(pickobject2, "");
}

// tests to see if pick can successfully
// read json output
TEST(PickTest, ReadsJSON) {
	// build pick object
	rapidjson::Document pickdocument;
	detectionformats::pick pickobject(
			detectionformats::FromJSONString(std::string(PICKSTRING),
					pickdocument));

	// check data values
	checkdata(pickobject, "");
}

// tests to see if pick can successfully
// read json output
TEST(PickTest, ReadsJSONNoFilter) {
	// build pick object
	rapidjson::Document pickdocument;
	detectionformats::pick pickobject(
			detectionformats::FromJSONString(std::string(PICKSTRINGNOFILTER),
					pickdocument));

	// check data values
	checkdata(pickobject, "");
}

// tests to see if pick can successfully
// be constructed
TEST(PickTest, Constructor) {
	// use constructor
	detectionformats::pick pickobject(std::string(ID), std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			std::string(AGENCYID), std::string(AUTHOR), std::string(PHASE),
			std::string(POLARITY), std::string(ONSET), std::string(PICKER),
			HIGHPASS, LOWPASS, AMPLITUDEVALUE, PERIOD, SNR, BACKAZIMUTH,
			BACKAZIMUTHERROR, SLOWNESS,
			SLOWNESSERROR, POWERRATIO, POWERRATIOERROR, std::string(ASSOCPHASE),
			ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

	// check data values
	checkdata(pickobject, "Tested Constructor");

	// use alternate constructor
	std::vector<detectionformats::filter> newfilterdata;
	newfilterdata.push_back(detectionformats::filter(HIGHPASS, LOWPASS));

	detectionformats::pick pickobject_altc(std::string(ID),
			detectionformats::site(std::string(STATION), std::string(CHANNEL),
					std::string(NETWORK), std::string(LOCATION)),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			detectionformats::source(std::string(AGENCYID),
					std::string(AUTHOR)), std::string(PHASE),
			std::string(POLARITY), std::string(ONSET), std::string(PICKER),
			newfilterdata,
			detectionformats::amplitude(AMPLITUDEVALUE, PERIOD, SNR),
			detectionformats::beam(BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS,
			SLOWNESSERROR, POWERRATIO, POWERRATIOERROR),
			detectionformats::associated(std::string(ASSOCPHASE), ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA));

	// check data values
	checkdata(pickobject_altc, "Tested alternate constructor");
}

// tests to see if pick can successfully
// be copy constructed
TEST(PickTest, CopyConstructor) {
	// use constructor
	detectionformats::pick frompickobject(std::string(ID), std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			std::string(AGENCYID), std::string(AUTHOR), std::string(PHASE),
			std::string(POLARITY), std::string(ONSET), std::string(PICKER),
			HIGHPASS, LOWPASS, AMPLITUDEVALUE, PERIOD, SNR, BACKAZIMUTH,
			BACKAZIMUTHERROR, SLOWNESS,
			SLOWNESSERROR, POWERRATIO, POWERRATIOERROR, std::string(ASSOCPHASE),
			ASSOCDISTANCE,
			ASSOCAZIMUTH, ASSOCRESIDUAL, ASSOCSIGMA);

	detectionformats::pick pickobject(frompickobject);

	// check data values
	checkdata(pickobject, "");
}

// tests to see if pick can successfully
// validate
TEST(PickTest, Validate) {
	detectionformats::pick pickobject;

	// build pick object
	pickobject.id = std::string(ID);

	// site subobject
	pickobject.site.station = std::string(STATION);
	pickobject.site.channel = std::string(CHANNEL);
	pickobject.site.network = std::string(NETWORK);
	pickobject.site.location = std::string(LOCATION);

	// source subobject
	pickobject.source.agencyid = std::string(AGENCYID);
	pickobject.source.author = std::string(AUTHOR);

	pickobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	pickobject.phase = std::string(PHASE);
	pickobject.polarity = std::string(POLARITY);
	pickobject.onset = std::string(ONSET);
	pickobject.picker = std::string(PICKER);

	// filter
	detectionformats::filter filterobject;
	filterobject.highpass = HIGHPASS;
	filterobject.lowpass = LOWPASS;
	pickobject.filterdata.push_back(filterobject);

	// amplitude
	pickobject.amplitude.ampvalue = AMPLITUDEVALUE;
	pickobject.amplitude.period = PERIOD;
	pickobject.amplitude.snr = SNR;

	// beam
	pickobject.beam.backazimuth = BACKAZIMUTH;
	pickobject.beam.backazimutherror = BACKAZIMUTHERROR;
	pickobject.beam.slowness = SLOWNESS;
	pickobject.beam.slownesserror = SLOWNESSERROR;
	pickobject.beam.powerratio = POWERRATIO;
	pickobject.beam.powerratioerror = POWERRATIOERROR;

	// association subobject
	pickobject.associationinfo.phase = std::string(ASSOCPHASE);
	pickobject.associationinfo.distance = ASSOCDISTANCE;
	pickobject.associationinfo.azimuth = ASSOCAZIMUTH;
	pickobject.associationinfo.residual = ASSOCRESIDUAL;
	pickobject.associationinfo.sigma = ASSOCSIGMA;

	// successful validation
	bool result = pickobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad pick object
	detectionformats::pick badpickobject;
	badpickobject.id = "";

	result = false;
	try {
		// call validation
		result = badpickobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
