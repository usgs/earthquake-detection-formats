#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

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
	ASSERT_STREQ(sitelocation.c_str(),
		expectedlocation.c_str())<< testinfo.c_str();

	// check agencyid
	std::string sourceagencyid = pickobject.source.agencyid;
	std::string expectedagencyid = std::string(AGENCYID);
	ASSERT_STREQ(sourceagencyid.c_str(),
		expectedagencyid.c_str())<< testinfo.c_str();

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
		ASSERT_STREQ(pickpolarity.c_str(),
			expectedpolarity.c_str())<< testinfo.c_str();
	}

	// check onset
	if (pickobject.onset.compare("") != true) {
		std::string pickonset = pickobject.onset;
		std::string expectedonset = std::string(ONSET);
		ASSERT_STREQ(pickonset.c_str(),
			expectedonset.c_str())<< testinfo.c_str();
	}

	// check picker
	if (pickobject.picker.compare("") != true) {
		std::string pickpicker = pickobject.picker;
		std::string expectedpicker = std::string(PICKER);
		ASSERT_STREQ(pickpicker.c_str(),
			expectedpicker.c_str())<< testinfo.c_str();
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
			std::string associationphase = pickobject.associationinfo.phase;
			std::string expectedassociationphase = std::string(PHASE);
			ASSERT_STREQ(associationphase.c_str(),
				expectedassociationphase.c_str())<< testinfo.c_str();
		}
		// check distance
		if (std::isnan(pickobject.associationinfo.distance) != true) {
			double associationdistance = pickobject.associationinfo.distance;
			double expecteddistance = DISTANCE;
			ASSERT_EQ(associationdistance, expecteddistance)<< testinfo.c_str();
		}

		// check azimuth
		if (std::isnan(pickobject.associationinfo.azimuth) != true) {
			double associationazimuth = pickobject.associationinfo.azimuth;
			double expectedazimuth = AZIMUTH;
			ASSERT_EQ(associationazimuth, expectedazimuth)<< testinfo.c_str();
		}

		// check residual
		if (std::isnan(pickobject.associationinfo.residual) != true) {
			double associationresidual = pickobject.associationinfo.residual;
			double expectedresidual = RESIDUAL;
			ASSERT_EQ(associationresidual, expectedresidual)<< testinfo.c_str();
		}

		// check sigma
		if (std::isnan(pickobject.associationinfo.sigma) != true) {
			double associationsigma = pickobject.associationinfo.sigma;
			double expectedsigma = SIGMA;
			ASSERT_EQ(associationsigma, expectedsigma)<< testinfo.c_str();
		}
	}

	// classificationinfo
	if (pickobject.classificationinfo.isempty() == false) {
		// check phase
		std::string classificationphase = pickobject.classificationinfo.phase;
		std::string expectedphase = std::string(PHASE);
		ASSERT_STREQ(classificationphase.c_str(), expectedphase.c_str());

		// check phase probability
		double classificationphaseprob =
			pickobject.classificationinfo.phaseprobability;
		double expectedphaseprob = PHASEPROBABILITY;
		ASSERT_EQ(classificationphaseprob, expectedphaseprob);

		// check distance
		double classificationdistance = pickobject.classificationinfo.distance;
		double expecteddistance = DISTANCE;
		ASSERT_EQ(classificationdistance, expecteddistance);

		// check distance probability
		double classificationdistanceprob =
			pickobject.classificationinfo.distanceprobability;
		double expecteddistanceprob = DISTANCEPROBABILITY;
		ASSERT_EQ(classificationdistanceprob, expecteddistanceprob);

		// check azimuth
		double classificationazimuth = pickobject.classificationinfo.azimuth;
		double expectedazimuth = AZIMUTH;
		ASSERT_EQ(classificationazimuth, expectedazimuth);

		// check azimuth probability
		double classificationazimuthprob =
			pickobject.classificationinfo.azimuthprobability;
		double expectedazimuthprob = AZIMUTHPROBABILITY;
		ASSERT_EQ(classificationazimuthprob, expectedazimuthprob);

		// check magnitude
		double classificationmagnitude = pickobject.classificationinfo.magnitude;
		double expectedmagnitude = MAGNITUDE;
		ASSERT_EQ(classificationmagnitude, expectedmagnitude);

		// check magnitude type
		std::string classificationmagtype =
			pickobject.classificationinfo.magnitudetype;
		std::string expectedmagtype = std::string(MAGNITUDETYPE);
		ASSERT_STREQ(classificationmagtype.c_str(), expectedmagtype.c_str());

		// check magnitude probability
		double classificationmagnitudeprob =
			pickobject.classificationinfo.magnitudeprobability;
		double expectedmagnitudeprob = MAGNITUDEPROBABILITY;
		ASSERT_EQ(classificationmagnitudeprob, expectedmagnitudeprob);

		// check depth
		double classificationdepth = pickobject.classificationinfo.depth;
		double expecteddepth = DEPTH;
		ASSERT_EQ(classificationdepth, expecteddepth);

		// check depth probability
		double classificationdepthprob =
			pickobject.classificationinfo.depthprobability;
		double expecteddepthprob = DEPTHPROBABILITY;
		ASSERT_EQ(classificationdepthprob, expecteddepthprob);

		// check eventtype
		if (pickobject.classificationinfo.eventtype.type.compare("") != true) {
			std::string detectioneventtype =
				pickobject.classificationinfo.eventtype.type;
			std::string expectedeventtype = std::string(EVENTTYPE);
			ASSERT_STREQ(detectioneventtype.c_str(), expectedeventtype.c_str());
		}

		// check eventtype certainty
		if (pickobject.classificationinfo.eventtype.certainty.compare("") != true) {
			std::string detectioneventtypecertainty =
				pickobject.classificationinfo.eventtype.certainty;
			std::string expectedeventtypecertainty = std::string(CERTAINTY);
			ASSERT_STREQ(detectioneventtypecertainty.c_str(),
				expectedeventtypecertainty.c_str());
		}

		// check event type probability
		double classificationeventtypeprob =
			pickobject.classificationinfo.eventtypeprobability;
		double expectedeventtypeprob = EVENTTYPEPROBABILITY;
		ASSERT_EQ(classificationeventtypeprob, expectedeventtypeprob);

		// check agencyid
		if (pickobject.classificationinfo.source.agencyid.compare("") != true) {
			std::string sourceagencyid = pickobject.classificationinfo.source.agencyid;
			std::string expectedagencyid = std::string(AGENCYID);
			ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());
		}

		// check author
		if (pickobject.classificationinfo.source.author.compare("") != true) {
			std::string sourceauthor = pickobject.classificationinfo.source.author;
			std::string expectedauthor = std::string(AUTHOR);
			ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());
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
	pickobject.associationinfo.phase = std::string(PHASE);
	pickobject.associationinfo.distance = DISTANCE;
	pickobject.associationinfo.azimuth = AZIMUTH;
	pickobject.associationinfo.residual = RESIDUAL;
	pickobject.associationinfo.sigma = SIGMA;

	// classification subobject
	pickobject.classificationinfo.phase = std::string(PHASE);
	pickobject.classificationinfo.phaseprobability = PHASEPROBABILITY;
    pickobject.classificationinfo.distance = DISTANCE;
	pickobject.classificationinfo.distanceprobability = DISTANCEPROBABILITY;
    pickobject.classificationinfo.azimuth = AZIMUTH;
    pickobject.classificationinfo.azimuthprobability = AZIMUTHPROBABILITY;
    pickobject.classificationinfo.magnitude = MAGNITUDE;
    pickobject.classificationinfo.magnitudetype = std::string(MAGNITUDETYPE);
    pickobject.classificationinfo.magnitudeprobability = MAGNITUDEPROBABILITY;
    pickobject.classificationinfo.depth = DEPTH;
    pickobject.classificationinfo.depthprobability = DEPTHPROBABILITY;
	pickobject.classificationinfo.eventtype.type = std::string(EVENTTYPE);
    pickobject.classificationinfo.eventtype.certainty = std::string(CERTAINTY);
    pickobject.classificationinfo.eventtypeprobability = EVENTTYPEPROBABILITY;
    pickobject.classificationinfo.source.agencyid = AGENCYID;
	pickobject.classificationinfo.source.author = AUTHOR;

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
	pickobject.associationinfo.phase = std::string(PHASE);
	pickobject.associationinfo.distance = DISTANCE;
	pickobject.associationinfo.azimuth = AZIMUTH;
	pickobject.associationinfo.residual = RESIDUAL;
	pickobject.associationinfo.sigma = SIGMA;

	// classification subobject
	pickobject.classificationinfo.phase = std::string(PHASE);
	pickobject.classificationinfo.phaseprobability = PHASEPROBABILITY;
    pickobject.classificationinfo.distance = DISTANCE;
	pickobject.classificationinfo.distanceprobability = DISTANCEPROBABILITY;
    pickobject.classificationinfo.azimuth = AZIMUTH;
    pickobject.classificationinfo.azimuthprobability = AZIMUTHPROBABILITY;
    pickobject.classificationinfo.magnitude = MAGNITUDE;
    pickobject.classificationinfo.magnitudetype = std::string(MAGNITUDETYPE);
    pickobject.classificationinfo.magnitudeprobability = MAGNITUDEPROBABILITY;
    pickobject.classificationinfo.depth = DEPTH;
    pickobject.classificationinfo.depthprobability = DEPTHPROBABILITY;
	pickobject.classificationinfo.eventtype.type = std::string(EVENTTYPE);
    pickobject.classificationinfo.eventtype.certainty = std::string(CERTAINTY);
    pickobject.classificationinfo.eventtypeprobability = EVENTTYPEPROBABILITY;
    pickobject.classificationinfo.source.agencyid = AGENCYID;
	pickobject.classificationinfo.source.author = AUTHOR;

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
	std::vector<detectionformats::filter> newfilterdata;
	newfilterdata.push_back(detectionformats::filter(std::string(FILTERTYPE),
		HIGHPASS, LOWPASS, std::string(FILTERUNITS)));

	// use constructor
	detectionformats::pick pickobject(std::string(ID), std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			std::string(AGENCYID), std::string(AUTHOR), std::string(PHASE),
			std::string(POLARITY), std::string(ONSET), std::string(PICKER),
			std::string(FILTERTYPE), HIGHPASS, LOWPASS, std::string(FILTERUNITS),
			AMPLITUDEVALUE, PERIOD, SNR, BACKAZIMUTH,
			BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO,
			POWERRATIOERROR, std::string(PHASE), DISTANCE, AZIMUTH,
			RESIDUAL, SIGMA, std::string(PHASE),
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH,
            AZIMUTHPROBABILITY, MAGNITUDE, std::string(MAGNITUDETYPE),
            MAGNITUDEPROBABILITY, DEPTH, DEPTHPROBABILITY, EVENTTYPE, CERTAINTY,
            EVENTTYPEPROBABILITY, AGENCYID, AUTHOR);

	// check data values
	checkdata(pickobject, "Tested Constructor");

	// use alternate constructor 1
	detectionformats::pick pickobject_altc1(std::string(ID), std::string(STATION),
			std::string(CHANNEL), std::string(NETWORK), std::string(LOCATION),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			std::string(AGENCYID), std::string(AUTHOR), std::string(PHASE),
			std::string(POLARITY), std::string(ONSET), std::string(PICKER),
			std::string(FILTERTYPE), HIGHPASS, LOWPASS, std::string(FILTERUNITS),
			AMPLITUDEVALUE, PERIOD, SNR, BACKAZIMUTH,
			BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO,
			POWERRATIOERROR);

	// check data values
	checkdata(pickobject_altc1, "Tested alternate constructor 1");

	// use alternate constructor 2
	detectionformats::pick pickobject_altc2(std::string(ID),
			detectionformats::site(std::string(STATION), std::string(CHANNEL),
				std::string(NETWORK), std::string(LOCATION)),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			detectionformats::source(std::string(AGENCYID),
				std::string(AUTHOR)), std::string(PHASE),
			std::string(POLARITY), std::string(ONSET), std::string(PICKER),
			newfilterdata,
			detectionformats::amplitude(AMPLITUDEVALUE, PERIOD, SNR),
			detectionformats::beam(BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS,
			SLOWNESSERROR, POWERRATIO, POWERRATIOERROR));

	// check data values
	checkdata(pickobject_altc2, "Tested alternate constructor 2");

	// use alternate constructor 3
	detectionformats::pick pickobject_altc3(std::string(ID),
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
			detectionformats::classification(std::string(PHASE),
            	PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH,
            	AZIMUTHPROBABILITY, MAGNITUDE, std::string(MAGNITUDETYPE),
            	MAGNITUDEPROBABILITY, DEPTH, DEPTHPROBABILITY, EVENTTYPE,
            	CERTAINTY, EVENTTYPEPROBABILITY, AGENCYID, AUTHOR));

	// check data values
	checkdata(pickobject_altc3, "Tested alternate constructor 3");

	// use alternate constructor 4
	detectionformats::pick pickobject_altc4(std::string(ID),
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
			detectionformats::association(std::string(PHASE), DISTANCE,
				AZIMUTH, RESIDUAL, SIGMA));

	// check data values
	checkdata(pickobject_altc4, "Tested alternate constructor 4");

	// use alternate constructor 5
	detectionformats::pick pickobject_altc5(std::string(ID),
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
			detectionformats::association(std::string(PHASE), DISTANCE,
				AZIMUTH, RESIDUAL, SIGMA),
			detectionformats::classification(std::string(PHASE),
            	PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH,
            	AZIMUTHPROBABILITY, MAGNITUDE, std::string(MAGNITUDETYPE),
            	MAGNITUDEPROBABILITY, DEPTH, DEPTHPROBABILITY, EVENTTYPE,
            	CERTAINTY, EVENTTYPEPROBABILITY, AGENCYID, AUTHOR));

	// check data values
	checkdata(pickobject_altc5, "Tested alternate constructor 5");
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
			std::string(FILTERTYPE), HIGHPASS, LOWPASS, std::string(FILTERUNITS),
			AMPLITUDEVALUE, PERIOD, SNR, BACKAZIMUTH,
			BACKAZIMUTHERROR, SLOWNESS, SLOWNESSERROR, POWERRATIO,
			POWERRATIOERROR, std::string(PHASE), DISTANCE, AZIMUTH,
			RESIDUAL, SIGMA, std::string(PHASE),
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH,
            AZIMUTHPROBABILITY, MAGNITUDE, std::string(MAGNITUDETYPE),
            MAGNITUDEPROBABILITY, DEPTH, DEPTHPROBABILITY, EVENTTYPE, CERTAINTY,
            EVENTTYPEPROBABILITY, AGENCYID, AUTHOR);

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
	pickobject.associationinfo.phase = std::string(PHASE);
	pickobject.associationinfo.distance = DISTANCE;
	pickobject.associationinfo.azimuth = AZIMUTH;
	pickobject.associationinfo.residual = RESIDUAL;
	pickobject.associationinfo.sigma = SIGMA;

	// classification subobject
	pickobject.classificationinfo.phase = std::string(PHASE);
	pickobject.classificationinfo.phaseprobability = PHASEPROBABILITY;
    pickobject.classificationinfo.distance = DISTANCE;
	pickobject.classificationinfo.distanceprobability = DISTANCEPROBABILITY;
    pickobject.classificationinfo.azimuth = AZIMUTH;
    pickobject.classificationinfo.azimuthprobability = AZIMUTHPROBABILITY;
    pickobject.classificationinfo.magnitude = MAGNITUDE;
    pickobject.classificationinfo.magnitudetype = std::string(MAGNITUDETYPE);
    pickobject.classificationinfo.magnitudeprobability = MAGNITUDEPROBABILITY;
    pickobject.classificationinfo.depth = DEPTH;
    pickobject.classificationinfo.depthprobability = DEPTHPROBABILITY;
	pickobject.classificationinfo.eventtype.type = std::string(EVENTTYPE);
    pickobject.classificationinfo.eventtype.certainty = std::string(CERTAINTY);
    pickobject.classificationinfo.eventtypeprobability = EVENTTYPEPROBABILITY;
    pickobject.classificationinfo.source.agencyid = AGENCYID;
	pickobject.classificationinfo.source.author = AUTHOR;

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
