#!/usr/bin/env python

#package imports
import detectionformats.pick
import detectionformats.site
import detectionformats.source
import detectionformats.filter
import detectionformats.amplitude
import detectionformats.beam
import detectionformats.association
import detectionformats.classification
import detectionformats.eventtype

#stdlib imports
import unittest
import datetime

class TestPick(unittest.TestCase):
    ID = '123456789'
    SITE = detectionformats.site.Site('BOZ', 'BHZ', 'US', '00')
    SOURCE = detectionformats.source.Source('testAgency', 'testAuthor')
    TIME = datetime.datetime(2018, 2, 6, 12, 30, 59, 0)
    PHASE = 'P'
    POLARITY = 'up'
    ONSET = 'impulsive'
    PICKER = 'other'
    aFilter = detectionformats.filter.Filter('BandPass', 1.2, 0.2, 'Hertz')
    FILTERLIST = [ aFilter ]
    FILTERLISTDICT = [ aFilter.toDict() ]
    AMPLITUDE = detectionformats.amplitude.Amplitude(5.5, 1.5, 6.2)
    BEAM = detectionformats.beam.Beam(22.5, 1.2, 4.6, 1.2, 3.5, 2.1)
    ASSOCIATIONINFO = detectionformats.association.Association('P', 12.5, 255.0,
        3.2, 4.8)
    EVENTTYPE = detectionformats.eventtype.EventType('Earthquake', 'Suspected')
    CLASSIFICATIONINFO = detectionformats.classification.Classification('P', 
        12.5, 22.0, 88.2, 45.0, 67.0, 1.2, 'Mb', 33.33, 12.5, 50.2, EVENTTYPE, 
        22.0, SOURCE)

    JSONSTRING = '{"Type": "Pick", "ID": "123456789", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Time": "2018-02-06T12:30:59.000Z", "Phase": "P", "Polarity": "up", "Onset": "impulsive", "Picker": "other", "Filter": [{"Type": "BandPass", "HighPass": 1.2, "LowPass": 0.2, "Units": "Hertz"}], "Amplitude": {"Amplitude": 5.5, "Period": 1.5, "SNR": 6.2}, "Beam": {"BackAzimuth": 22.5, "Slowness": 1.2, "PowerRatio": 4.6, "BackAzimuthError": 1.2, "SlownessError": 3.5, "PowerRatioError": 2.1}, "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}, "ClassificationInfo": {"Phase": "P", "PhaseProbability": 12.5, "Distance": 22.0, "DistanceProbability": 88.2, "Backazimuth": 45.0, "BackazimuthProbability": 67.0, "Magnitude": 1.2, "MagnitudeType": "Mb", "MagnitudeProbability": 33.33, "Depth": 12.5, "DepthProbability": 50.2, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "EventTypeProbability": 22.0, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}}'
    DICT = {"Type": "Pick", "ID": "123456789", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Time": "2018-02-06T12:30:59.000Z", "Phase": "P", "Polarity": "up", "Onset": "impulsive", "Picker": "other", "Amplitude": {"Amplitude": 5.5, "Period": 1.5, "SNR": 6.2}, "Beam": {"BackAzimuth": 22.5, "Slowness": 1.2, "PowerRatio": 4.6, "BackAzimuthError": 1.2, "SlownessError": 3.5, "PowerRatioError": 2.1}, "Filter": [{"Type": "BandPass", "HighPass": 1.2, "LowPass": 0.2, "Units": "Hertz"}], "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}, "ClassificationInfo": {"Phase": "P", "PhaseProbability": 12.5, "Distance": 22.0, "DistanceProbability": 88.2, "Backazimuth": 45.0, "BackazimuthProbability": 67.0, "Magnitude": 1.2, "MagnitudeType": "Mb", "MagnitudeProbability": 33.33, "Depth": 12.5, "DepthProbability": 50.2, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "EventTypeProbability": 22.0, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}}

    def test_init(self):
        # Empty init
        pick = detectionformats.pick.Pick()

        self.assertFalse(hasattr(pick, 'id'))
        self.assertFalse(hasattr(pick.site, 'station'))
        self.assertFalse(hasattr(pick.site, 'channel'))
        self.assertFalse(hasattr(pick.site, 'network'))
        self.assertFalse(hasattr(pick.site, 'location'))
        self.assertFalse(hasattr(pick.source, 'agencyID'))
        self.assertFalse(hasattr(pick.source, 'author'))
        self.assertFalse(hasattr(pick, 'time'))
        self.assertFalse(hasattr(pick, 'phase'))
        self.assertFalse(hasattr(pick, 'polarity'))
        self.assertFalse(hasattr(pick, 'onset'))
        self.assertFalse(hasattr(pick, 'picker'))
        # not sure how to handle filterList
        self.assertFalse(hasattr(pick.amplitude, 'amplitude'))
        self.assertFalse(hasattr(pick.amplitude, 'period'))
        self.assertFalse(hasattr(pick.amplitude, 'snr'))
        self.assertFalse(hasattr(pick.beam, 'backAzimuth'))
        self.assertFalse(hasattr(pick.beam, 'slowness'))
        self.assertFalse(hasattr(pick.beam, 'powerRatio'))
        self.assertFalse(hasattr(pick.beam, 'backAzimuthError'))
        self.assertFalse(hasattr(pick.beam, 'slownessError'))
        self.assertFalse(hasattr(pick.beam, 'powerRatioError'))
        self.assertFalse(hasattr(pick.associationInfo, 'phase'))
        self.assertFalse(hasattr(pick.associationInfo, 'distance'))
        self.assertFalse(hasattr(pick.associationInfo, 'azimuth'))
        self.assertFalse(hasattr(pick.associationInfo, 'residual'))
        self.assertFalse(hasattr(pick.associationInfo, 'sigma'))
        self.assertFalse(hasattr(pick.classificationInfo, 'phase'))
        self.assertFalse(hasattr(pick.classificationInfo, 'phaseProbability'))
        self.assertFalse(hasattr(pick.classificationInfo, 'distance'))
        self.assertFalse(hasattr(pick.classificationInfo, 'distanceProbability'))
        self.assertFalse(hasattr(pick.classificationInfo, 'backazimuth'))
        self.assertFalse(hasattr(pick.classificationInfo, 'backazimuthProbability'))
        self.assertFalse(hasattr(pick.classificationInfo, 'magnitude'))
        self.assertFalse(hasattr(pick.classificationInfo, 'magnitudeType'))
        self.assertFalse(hasattr(pick.classificationInfo, 'magnitudeProbability'))
        self.assertFalse(hasattr(pick.classificationInfo, 'depth'))
        self.assertFalse(hasattr(pick.classificationInfo, 'depthProbability'))
        self.assertFalse(hasattr(pick.classificationInfo.eventType, 'type'))
        self.assertFalse(hasattr(pick.classificationInfo.eventType, 'certainty'))
        self.assertFalse(hasattr(pick.classificationInfo, 'eventTypeProbability'))
        self.assertFalse(hasattr(pick.classificationInfo.source, 'agencyID'))
        self.assertFalse(hasattr(pick.classificationInfo.source, 'author'))
        
        pick = detectionformats.pick.Pick(self.ID,
            self.SITE, self.SOURCE, self.TIME, self.PHASE, self.POLARITY,
            self.ONSET, self.PICKER, self.FILTERLIST, self.AMPLITUDE, self.BEAM,
            self.ASSOCIATIONINFO, self.CLASSIFICATIONINFO)

        self.assertTrue(hasattr(pick, 'id'))
        self.assertTrue(hasattr(pick.site, 'station'))
        self.assertTrue(hasattr(pick.site, 'channel'))
        self.assertTrue(hasattr(pick.site, 'network'))
        self.assertTrue(hasattr(pick.site, 'location'))
        self.assertTrue(hasattr(pick.source, 'agencyID'))
        self.assertTrue(hasattr(pick.source, 'author'))
        self.assertTrue(hasattr(pick, 'time'))
        self.assertTrue(hasattr(pick, 'phase'))
        self.assertTrue(hasattr(pick, 'polarity'))
        self.assertTrue(hasattr(pick, 'onset'))
        self.assertTrue(hasattr(pick, 'picker'))
        # not sure how to handle filterList
        self.assertTrue(hasattr(pick.amplitude, 'amplitude'))
        self.assertTrue(hasattr(pick.amplitude, 'period'))
        self.assertTrue(hasattr(pick.amplitude, 'snr'))
        self.assertTrue(hasattr(pick.beam, 'backAzimuth'))
        self.assertTrue(hasattr(pick.beam, 'slowness'))
        self.assertTrue(hasattr(pick.beam, 'powerRatio'))
        self.assertTrue(hasattr(pick.beam, 'backAzimuthError'))
        self.assertTrue(hasattr(pick.beam, 'slownessError'))
        self.assertTrue(hasattr(pick.beam, 'powerRatioError'))
        self.assertTrue(hasattr(pick.associationInfo, 'phase'))
        self.assertTrue(hasattr(pick.associationInfo, 'distance'))
        self.assertTrue(hasattr(pick.associationInfo, 'azimuth'))
        self.assertTrue(hasattr(pick.associationInfo, 'residual'))
        self.assertTrue(hasattr(pick.associationInfo, 'sigma'))
        self.assertTrue(hasattr(pick.classificationInfo, 'phase'))
        self.assertTrue(hasattr(pick.classificationInfo, 'phaseProbability'))
        self.assertTrue(hasattr(pick.classificationInfo, 'distance'))
        self.assertTrue(hasattr(pick.classificationInfo, 'distanceProbability'))
        self.assertTrue(hasattr(pick.classificationInfo, 'backazimuth'))
        self.assertTrue(hasattr(pick.classificationInfo, 'backazimuthProbability'))
        self.assertTrue(hasattr(pick.classificationInfo, 'magnitude'))
        self.assertTrue(hasattr(pick.classificationInfo, 'magnitudeType'))
        self.assertTrue(hasattr(pick.classificationInfo, 'magnitudeProbability'))
        self.assertTrue(hasattr(pick.classificationInfo, 'depth'))
        self.assertTrue(hasattr(pick.classificationInfo, 'depthProbability'))
        self.assertTrue(hasattr(pick.classificationInfo.eventType, 'type'))
        self.assertTrue(hasattr(pick.classificationInfo.eventType, 'certainty'))
        self.assertTrue(hasattr(pick.classificationInfo, 'eventTypeProbability'))
        self.assertTrue(hasattr(pick.classificationInfo.source, 'agencyID'))
        self.assertTrue(hasattr(pick.classificationInfo.source, 'author'))

        self.assertEqual(pick.id, self.ID)
        self.assertEqual(pick.site.station, self.SITE.station)
        self.assertEqual(pick.site.channel, self.SITE.channel)
        self.assertEqual(pick.site.network, self.SITE.network)
        self.assertEqual(pick.site.location, self.SITE.location)
        self.assertEqual(pick.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(pick.source.author, self.SOURCE.author)
        self.assertEqual(pick.time, self.TIME)
        self.assertEqual(pick.phase, self.PHASE)
        self.assertEqual(pick.polarity, self.POLARITY)
        self.assertEqual(pick.onset, self.ONSET)
        self.assertEqual(pick.picker, self.PICKER)
        self.assertEqual(pick.filterList, self.FILTERLIST)
        self.assertEqual(pick.amplitude.amplitude, self.AMPLITUDE.amplitude)
        self.assertEqual(pick.amplitude.period, self.AMPLITUDE.period)
        self.assertEqual(pick.amplitude.snr, self.AMPLITUDE.snr)
        self.assertEqual(pick.beam.backAzimuth, self.BEAM.backAzimuth)
        self.assertEqual(pick.beam.slowness, self.BEAM.slowness)
        self.assertEqual(pick.beam.powerRatio, self.BEAM.powerRatio)
        self.assertEqual(pick.beam.backAzimuthError, self.BEAM.backAzimuthError)
        self.assertEqual(pick.beam.slownessError, self.BEAM.slownessError)
        self.assertEqual(pick.beam.powerRatioError, self.BEAM.powerRatioError)
        self.assertEqual(pick.associationInfo.phase, self.ASSOCIATIONINFO.phase)
        self.assertEqual(pick.associationInfo.distance, self.ASSOCIATIONINFO.distance)
        self.assertEqual(pick.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth)
        self.assertEqual(pick.associationInfo.residual, self.ASSOCIATIONINFO.residual)
        self.assertEqual(pick.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)
        self.assertEqual(pick.classificationInfo.phase, self.CLASSIFICATIONINFO.phase)
        self.assertEqual(pick.classificationInfo.phaseProbability, self.CLASSIFICATIONINFO.phaseProbability)
        self.assertEqual(pick.classificationInfo.distance, self.CLASSIFICATIONINFO.distance)
        self.assertEqual(pick.classificationInfo.distanceProbability, self.CLASSIFICATIONINFO.distanceProbability)
        self.assertEqual(pick.classificationInfo.backazimuth, self.CLASSIFICATIONINFO.backazimuth)
        self.assertEqual(pick.classificationInfo.backazimuthProbability, self.CLASSIFICATIONINFO.backazimuthProbability)        
        self.assertEqual(pick.classificationInfo.magnitude, self.CLASSIFICATIONINFO.magnitude)
        self.assertEqual(pick.classificationInfo.magnitudeType, self.CLASSIFICATIONINFO.magnitudeType)
        self.assertEqual(pick.classificationInfo.magnitudeProbability, self.CLASSIFICATIONINFO.magnitudeProbability)
        self.assertEqual(pick.classificationInfo.depth, self.CLASSIFICATIONINFO.depth)
        self.assertEqual(pick.classificationInfo.depthProbability, self.CLASSIFICATIONINFO.depthProbability)  
        self.assertEqual(pick.classificationInfo.eventType.type, self.CLASSIFICATIONINFO.eventType.type)  
        self.assertEqual(pick.classificationInfo.eventType.certainty, self.CLASSIFICATIONINFO.eventType.certainty)  
        self.assertEqual(pick.classificationInfo.eventTypeProbability, self.CLASSIFICATIONINFO.eventTypeProbability)   
        self.assertEqual(pick.classificationInfo.source.agencyID, self.SOURCE.agencyID)  
        self.assertEqual(pick.classificationInfo.source.author, self.SOURCE.author) 

    def test_toJSON(self):
        pick = detectionformats.pick.Pick(self.ID,
            self.SITE, self.SOURCE, self.TIME, self.PHASE, self.POLARITY,
            self.ONSET, self.PICKER, self.FILTERLIST, self.AMPLITUDE, self.BEAM,
            self.ASSOCIATIONINFO, self.CLASSIFICATIONINFO)
        self.maxDiff = None
        self.assertEqual(pick.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        pick = detectionformats.pick.Pick()
        pick.fromJSONString(self.JSONSTRING)

        self.assertEqual(pick.id, self.ID)
        self.assertEqual(pick.site.station, self.SITE.station)
        self.assertEqual(pick.site.channel, self.SITE.channel)
        self.assertEqual(pick.site.network, self.SITE.network)
        self.assertEqual(pick.site.location, self.SITE.location)
        self.assertEqual(pick.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(pick.source.author, self.SOURCE.author)
        self.assertEqual(pick.time, self.TIME)
        self.assertEqual(pick.phase, self.PHASE)
        self.assertEqual(pick.polarity, self.POLARITY)
        self.assertEqual(pick.onset, self.ONSET)
        self.assertEqual(pick.picker, self.PICKER)
        # self.assertEqual(pick.filterList, self.FILTERLIST)
        self.assertEqual(pick.amplitude.amplitude, self.AMPLITUDE.amplitude)
        self.assertEqual(pick.amplitude.period, self.AMPLITUDE.period)
        self.assertEqual(pick.amplitude.snr, self.AMPLITUDE.snr)
        self.assertEqual(pick.beam.backAzimuth, self.BEAM.backAzimuth)
        self.assertEqual(pick.beam.slowness, self.BEAM.slowness)
        self.assertEqual(pick.beam.powerRatio, self.BEAM.powerRatio)
        self.assertEqual(pick.beam.backAzimuthError, self.BEAM.backAzimuthError)
        self.assertEqual(pick.beam.slownessError, self.BEAM.slownessError)
        self.assertEqual(pick.beam.powerRatioError, self.BEAM.powerRatioError)
        self.assertEqual(pick.associationInfo.phase, self.ASSOCIATIONINFO.phase)
        self.assertEqual(pick.associationInfo.distance, self.ASSOCIATIONINFO.distance)
        self.assertEqual(pick.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth)
        self.assertEqual(pick.associationInfo.residual, self.ASSOCIATIONINFO.residual)
        self.assertEqual(pick.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)
        self.assertEqual(pick.classificationInfo.phase, self.PHASE)
        self.assertEqual(pick.classificationInfo.phase, self.CLASSIFICATIONINFO.phase)
        self.assertEqual(pick.classificationInfo.phaseProbability, self.CLASSIFICATIONINFO.phaseProbability)
        self.assertEqual(pick.classificationInfo.distance, self.CLASSIFICATIONINFO.distance)
        self.assertEqual(pick.classificationInfo.distanceProbability, self.CLASSIFICATIONINFO.distanceProbability)
        self.assertEqual(pick.classificationInfo.backazimuth, self.CLASSIFICATIONINFO.backazimuth)
        self.assertEqual(pick.classificationInfo.backazimuthProbability, self.CLASSIFICATIONINFO.backazimuthProbability) 
        self.assertEqual(pick.classificationInfo.magnitude, self.CLASSIFICATIONINFO.magnitude)
        self.assertEqual(pick.classificationInfo.magnitudeType, self.CLASSIFICATIONINFO.magnitudeType)
        self.assertEqual(pick.classificationInfo.magnitudeProbability, self.CLASSIFICATIONINFO.magnitudeProbability)
        self.assertEqual(pick.classificationInfo.depth, self.CLASSIFICATIONINFO.depth)
        self.assertEqual(pick.classificationInfo.depthProbability, self.CLASSIFICATIONINFO.depthProbability) 
        self.assertEqual(pick.classificationInfo.eventType.type, self.CLASSIFICATIONINFO.eventType.type)
        self.assertEqual(pick.classificationInfo.eventType.certainty, self.CLASSIFICATIONINFO.eventType.certainty)    
        self.assertEqual(pick.classificationInfo.eventTypeProbability, self.CLASSIFICATIONINFO.eventTypeProbability)   
        self.assertEqual(pick.classificationInfo.source.agencyID, self.CLASSIFICATIONINFO.source.agencyID)
        self.assertEqual(pick.classificationInfo.source.author, self.CLASSIFICATIONINFO.source.author)   

    def test_toDict(self):
        pick = detectionformats.pick.Pick(self.ID,
            self.SITE, self.SOURCE, self.TIME, self.PHASE, self.POLARITY,
            self.ONSET, self.PICKER, self.FILTERLIST, self.AMPLITUDE, self.BEAM,
            self.ASSOCIATIONINFO, self.CLASSIFICATIONINFO)
        self.maxDiff = None
        self.assertEqual(pick.toDict(), self.DICT)

    def test_fromDict(self):
        pick = detectionformats.pick.Pick()
        pick.fromDict(self.DICT)

        self.assertEqual(pick.id, self.ID)
        self.assertEqual(pick.site.station, self.SITE.station)
        self.assertEqual(pick.site.channel, self.SITE.channel)
        self.assertEqual(pick.site.network, self.SITE.network)
        self.assertEqual(pick.site.location, self.SITE.location)
        self.assertEqual(pick.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(pick.source.author, self.SOURCE.author)
        self.assertEqual(pick.time, self.TIME)
        self.assertEqual(pick.phase, self.PHASE)
        self.assertEqual(pick.polarity, self.POLARITY)
        self.assertEqual(pick.onset, self.ONSET)
        self.assertEqual(pick.picker, self.PICKER)
        # self.assertEqual(pick.filterList, self.FILTERLIST)
        self.assertEqual(pick.amplitude.amplitude, self.AMPLITUDE.amplitude)
        self.assertEqual(pick.amplitude.period, self.AMPLITUDE.period)
        self.assertEqual(pick.amplitude.snr, self.AMPLITUDE.snr)
        self.assertEqual(pick.beam.backAzimuth, self.BEAM.backAzimuth)
        self.assertEqual(pick.beam.slowness, self.BEAM.slowness)
        self.assertEqual(pick.beam.powerRatio, self.BEAM.powerRatio)
        self.assertEqual(pick.beam.backAzimuthError, self.BEAM.backAzimuthError)
        self.assertEqual(pick.beam.slownessError, self.BEAM.slownessError)
        self.assertEqual(pick.beam.powerRatioError, self.BEAM.powerRatioError)
        self.assertEqual(pick.associationInfo.phase, self.ASSOCIATIONINFO.phase)
        self.assertEqual(pick.associationInfo.distance, self.ASSOCIATIONINFO.distance)
        self.assertEqual(pick.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth)
        self.assertEqual(pick.associationInfo.residual, self.ASSOCIATIONINFO.residual)
        self.assertEqual(pick.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)
        self.assertEqual(pick.classificationInfo.phase, self.CLASSIFICATIONINFO.phase)
        self.assertEqual(pick.classificationInfo.phaseProbability, self.CLASSIFICATIONINFO.phaseProbability)
        self.assertEqual(pick.classificationInfo.distance, self.CLASSIFICATIONINFO.distance)
        self.assertEqual(pick.classificationInfo.distanceProbability, self.CLASSIFICATIONINFO.distanceProbability)
        self.assertEqual(pick.classificationInfo.backazimuth, self.CLASSIFICATIONINFO.backazimuth)
        self.assertEqual(pick.classificationInfo.backazimuthProbability, self.CLASSIFICATIONINFO.backazimuthProbability) 
        self.assertEqual(pick.classificationInfo.magnitude, self.CLASSIFICATIONINFO.magnitude)
        self.assertEqual(pick.classificationInfo.magnitudeType, self.CLASSIFICATIONINFO.magnitudeType)
        self.assertEqual(pick.classificationInfo.magnitudeProbability, self.CLASSIFICATIONINFO.magnitudeProbability)
        self.assertEqual(pick.classificationInfo.depth, self.CLASSIFICATIONINFO.depth)
        self.assertEqual(pick.classificationInfo.depthProbability, self.CLASSIFICATIONINFO.depthProbability) 
        self.assertEqual(pick.classificationInfo.eventType.type, self.CLASSIFICATIONINFO.eventType.type)
        self.assertEqual(pick.classificationInfo.eventType.certainty, self.CLASSIFICATIONINFO.eventType.certainty)    
        self.assertEqual(pick.classificationInfo.eventTypeProbability, self.CLASSIFICATIONINFO.eventTypeProbability)   
        self.assertEqual(pick.classificationInfo.source.agencyID, self.CLASSIFICATIONINFO.source.agencyID)
        self.assertEqual(pick.classificationInfo.source.author, self.CLASSIFICATIONINFO.source.author)  

    def test_isValid(self):
        pick = detectionformats.pick.Pick(self.ID,
            self.SITE, self.SOURCE, self.TIME, self.PHASE, self.POLARITY,
            self.ONSET, self.PICKER, self.FILTERLIST, self.AMPLITUDE, self.BEAM,
            self.ASSOCIATIONINFO, self.CLASSIFICATIONINFO)
        self.assertTrue(pick.isValid())

        badPick = detectionformats.pick.Pick()
        self.assertFalse(badPick.isValid())

if __name__ == '__main__':
    unittest.main()
