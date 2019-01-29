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
    aFilter = detectionformats.filter.Filter(1.2, 0.2)
    FILTERLIST = [ aFilter ]
    AMPLITUDE = detectionformats.amplitude.Amplitude(5.5, 1.5, 6.2)
    BEAM = detectionformats.beam.Beam(22.5, 1.2, 4.6, 1.2, 3.5, 2.1)
    ASSOCIATIONINFO = detectionformats.association.Association('P', 12.5, 255.0,
        3.2, 4.8)
    EVENTTYPE = detectionformats.eventtype.EventType('Earthquake', 'Suspected')
    CLASSIFICATIONINFO = detectionformats.classification.Classification('P', 
        12.5, 22.0, 88.2, 45.0, 67.0, 1.2, 'Mb', 33.33, 12.5, 50.2, EVENTTYPE, 
        22.0, SOURCE)

    JSONSTRING = '{"Type": "Pick", "ID": "123456789", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Time": "2018-02-06T12:30:59.000Z", "Phase": "P", "Polarity": "up", "Onset": "impulsive", "Picker": "other", "Amplitude": {"Amplitude": 5.5, "Period": 1.5, "SNR": 6.2}, "Beam": {"BackAzimuth": 22.5, "Slowness": 1.2, "PowerRatio": 4.6, "BackAzimuthError": 1.2, "SlownessError": 3.5, "PowerRatioError": 2.1}, "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}, "ClassificationInfo": {"Phase": "P", "PhaseProbability": 12.5, "Distance": 22.0, "DistanceProbability": 88.2, "Azimuth": 45.0, "AzimuthProbability": 67.0, "Magnitude": 1.2, "MagnitudeType": "Mb", "MagnitudeProbability": 33.33, "Depth": 12.5, "DepthProbability": 50.2, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "EventTypeProbability": 22.0, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}}'
    DICT = {"Type": "Pick", "ID": "123456789", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Time": "2018-02-06T12:30:59.000Z", "Phase": "P", "Polarity": "up", "Onset": "impulsive", "Picker": "other", "Amplitude": {"Amplitude": 5.5, "Period": 1.5, "SNR": 6.2}, "Beam": {"BackAzimuth": 22.5, "Slowness": 1.2, "PowerRatio": 4.6, "BackAzimuthError": 1.2, "SlownessError": 3.5, "PowerRatioError": 2.1}, "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}, "ClassificationInfo": {"Phase": "P", "PhaseProbability": 12.5, "Distance": 22.0, "DistanceProbability": 88.2, "Azimuth": 45.0, "AzimuthProbability": 67.0, "Magnitude": 1.2, "MagnitudeType": "Mb", "MagnitudeProbability": 33.33, "Depth": 12.5, "DepthProbability": 50.2, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "EventTypeProbability": 22.0, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}}

    def test_init(self):
        # Empty init
        pick = detectionformats.pick.Pick()

        try:
            pick.id
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.site.station
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.site.channel
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.site.network
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.site.location
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.source.agencyID
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.source.author
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.phase
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.pick
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.polarity
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.onset
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.picker
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        # not sure how to handle filterList

        try:
            pick.amplitude.amplitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.amplitude.period
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.amplitude.snr
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.beam.backAzimuth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.beam.slowness
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.beam.powerRatio
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.beam.backAzimuthError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.beam.slownessError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.beam.powerRatioError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.associationInfo.phase
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.associationInfo.distance
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.associationInfo.azimuth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.associationInfo.residual
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.associationInfo.sigma
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.phase
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass
        
        try:
            pick.classificationInfo.phaseProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass    

        try:
            pick.classificationInfo.distance
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.distanceProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.azimuth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.azimuthProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.magnitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.magnitudeType
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass
        
        try:
            pick.classificationInfo.magnitudeProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.residual
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.depth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass  

        try:
            pick.classificationInfo.depthProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass  

        try:
            pick.classificationInfo.eventType.type
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.eventType.certainty
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.eventTypeProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.source.agencyID
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            pick.classificationInfo.source.author
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        pick = detectionformats.pick.Pick(self.ID,
            self.SITE, self.SOURCE, self.TIME, self.PHASE, self.POLARITY,
            self.ONSET, self.PICKER, self.FILTERLIST, self.AMPLITUDE, self.BEAM,
            self.ASSOCIATIONINFO, self.CLASSIFICATIONINFO)

        try:
            pick.id
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.id, self.ID)

        try:
            pick.site.station
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.site.station, self.SITE.station)

        try:
            pick.site.channel
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.site.channel, self.SITE.channel)

        try:
            pick.site.network
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.site.network, self.SITE.network)

        try:
            pick.site.location
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.site.location, self.SITE.location)

        try:
            pick.source.agencyID
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.source.agencyID, self.SOURCE.agencyID)

        try:
            pick.source.author
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.source.author, self.SOURCE.author)

        try:
            pick.time
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.time, self.TIME)

        try:
            pick.phase
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.phase, self.PHASE)

        try:
            pick.polarity
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.polarity, self.POLARITY)

        try:
            pick.onset
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.onset, self.ONSET)

        try:
            pick.picker
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.picker, self.PICKER)

# not sure how to handle filterList

        try:
            pick.amplitude.amplitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.amplitude.amplitude, self.AMPLITUDE.amplitude)

        try:
            pick.amplitude.period
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.amplitude.period, self.AMPLITUDE.period)

        try:
            pick.amplitude.snr
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.amplitude.snr, self.AMPLITUDE.snr)

        try:
            pick.beam.backAzimuth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.beam.backAzimuth, self.BEAM.backAzimuth)

        try:
            pick.beam.slowness
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.beam.slowness, self.BEAM.slowness)

        try:
            pick.beam.powerRatio
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.beam.powerRatio, self.BEAM.powerRatio)

        try:
            pick.beam.backAzimuthError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.beam.backAzimuthError, self.BEAM.backAzimuthError)

        try:
            pick.beam.slownessError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.beam.slownessError, self.BEAM.slownessError)

        try:
            pick.beam.powerRatioError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.beam.powerRatioError, self.BEAM.powerRatioError)

        try:
            pick.associationInfo.phase
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.associationInfo.phase, self.ASSOCIATIONINFO.phase)

        try:
            pick.associationInfo.distance
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.associationInfo.distance, self.ASSOCIATIONINFO.distance)

        try:
            pick.associationInfo.azimuth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth)

        try:
            pick.associationInfo.residual
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.associationInfo.residual, self.ASSOCIATIONINFO.residual)

        try:
            pick.associationInfo.sigma
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)

        try:
            pick.classificationInfo.phase
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.phase, self.CLASSIFICATIONINFO.phase)

        try:
            pick.classificationInfo.phaseProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.phaseProbability, self.CLASSIFICATIONINFO.phaseProbability)

        try:
            pick.classificationInfo.distance
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.distance, self.CLASSIFICATIONINFO.distance)

        try:
            pick.classificationInfo.distanceProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.distanceProbability, self.CLASSIFICATIONINFO.distanceProbability)

        try:
            pick.classificationInfo.azimuth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.azimuth, self.CLASSIFICATIONINFO.azimuth)

        try:
            pick.classificationInfo.azimuthProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.azimuthProbability, self.CLASSIFICATIONINFO.azimuthProbability)        

        try:
            pick.classificationInfo.magnitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.magnitude, self.CLASSIFICATIONINFO.magnitude)

        try:
            pick.classificationInfo.magnitudeType
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.magnitudeType, self.CLASSIFICATIONINFO.magnitudeType)

        try:
            pick.classificationInfo.magnitudeProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.magnitudeProbability, self.CLASSIFICATIONINFO.magnitudeProbability)

        try:
            pick.classificationInfo.depth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.depth, self.CLASSIFICATIONINFO.depth)

        try:
            pick.classificationInfo.depthProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.depthProbability, self.CLASSIFICATIONINFO.depthProbability)  

        try:
            pick.classificationInfo.eventType.type
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.eventType.type, self.CLASSIFICATIONINFO.eventType.type)  

        try:
            pick.classificationInfo.eventType.certainty
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.eventType.certainty, self.CLASSIFICATIONINFO.eventType.certainty)  

        try:
            pick.classificationInfo.eventTypeProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.eventTypeProbability, self.CLASSIFICATIONINFO.eventTypeProbability)   

        try:
            pick.classificationInfo.source.agencyID
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(pick.classificationInfo.source.agencyID, self.SOURCE.agencyID)  

        try:
            pick.classificationInfo.source.author
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

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
        # not sure how to handle filterlist
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
        self.assertEqual(pick.classificationInfo.azimuth, self.CLASSIFICATIONINFO.azimuth)
        self.assertEqual(pick.classificationInfo.azimuthProbability, self.CLASSIFICATIONINFO.azimuthProbability) 
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
        # not sure how to handle filterlist
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
        self.assertEqual(pick.classificationInfo.azimuth, self.CLASSIFICATIONINFO.azimuth)
        self.assertEqual(pick.classificationInfo.azimuthProbability, self.CLASSIFICATIONINFO.azimuthProbability) 
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
