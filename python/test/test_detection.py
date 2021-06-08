#!/usr/bin/env python

#package imports
import detectionformats.detection
import detectionformats.site
import detectionformats.source
import detectionformats.hypocenter
import detectionformats.pick
import detectionformats.correlation
import detectionformats.eventtype

#stdlib imports
import unittest
import datetime

class TestDetection(unittest.TestCase):
    ID = '123456789'
    SOURCE = detectionformats.source.Source('testAgency', 'testAuthor')
    HYPOCENTER = detectionformats.hypocenter.Hypocenter(45.123,
        -120.33, 55.2, datetime.datetime(2018, 2, 6, 12, 32, 50, 0), 2.5,
        1.2, 20.0, 6.5)
    DETECTIONTYPE = 'New'
    EVENTTYPE = detectionformats.eventtype.EventType('Earthquake', 'Suspected')
    DETECTIONTIME = datetime.datetime(2018, 2, 6, 12, 31, 59, 0)
    BAYES = 2.5
    MINIMUMDISTANCE = 1.2
    RMS = 5.6
    GAP = 1.0
    DETECTOR = "Global"
    SITE = detectionformats.site.Site('BOZ', 'BHZ', 'US', '00')
    TIME = datetime.datetime(2018, 2, 6, 12, 30, 59, 0)
    aFilter = detectionformats.filter.Filter('BandPass', 1.2, 0.2, 'Hertz')
    FILTERLIST = [ aFilter ]
    AMPLITUDE = detectionformats.amplitude.Amplitude(5.5, 1.5, 6.2)
    BEAM = detectionformats.beam.Beam(22.5, 1.2, 4.6, 1.2, 3.5, 2.1)
    ASSOCIATIONINFO = detectionformats.association.Association('P', 12.5, 255.0,
        3.2, 4.8)
    PICK = detectionformats.pick.Pick('123',
        SITE, SOURCE, TIME, 'P', 'up','impulsive', 'other', FILTERLIST,
        AMPLITUDE, BEAM, ASSOCIATIONINFO)
    CORRELATION = detectionformats.correlation.Correlation('1234',
        SITE, SOURCE, 'P', TIME, 1.2, HYPOCENTER, EVENTTYPE, 5.6, 1.2,
        2.2, 1, 'test', ASSOCIATIONINFO)
    PICKDATA = [ PICK ]
    CORRELATIONDATA = [ CORRELATION ]

    JSONSTRING = '{"Type": "Detection", "ID": "123456789", "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "DetectionType": "New", "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "DetectionTime": "2018-02-06T12:31:59.000Z", "Bayes": 2.5, "MinimumDistance": 1.2, "RMS": 5.6, "Gap": 1.0, "Detector": "Global", "Data": [{"Type": "Pick", "ID": "123", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Time": "2018-02-06T12:30:59.000Z", "Phase": "P", "Polarity": "up", "Onset": "impulsive", "Picker": "other", "Filter": [{"Type": "BandPass", "HighPass": 1.2, "LowPass": 0.2, "Units": "Hertz"}], "Amplitude": {"Amplitude": 5.5, "Period": 1.5, "SNR": 6.2}, "Beam": {"BackAzimuth": 22.5, "Slowness": 1.2, "PowerRatio": 4.6, "BackAzimuthError": 1.2, "SlownessError": 3.5, "PowerRatioError": 2.1}, "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}, {"Type": "Correlation", "ID": "1234", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Phase": "P", "Time": "2018-02-06T12:30:59.000Z", "Correlation": 1.2, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "Magnitude": 5.6, "SNR": 1.2, "ZScore": 2.2, "DetectionThreshold": 1, "ThresholdType": "test", "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}]}'

    DICT = {"Type": "Detection", "ID": "123456789", "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "DetectionType": "New", "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "DetectionTime": "2018-02-06T12:31:59.000Z", "Bayes": 2.5, "MinimumDistance": 1.2, "RMS": 5.6, "Gap": 1.0, "Detector": "Global", "Data": [{"Type": "Pick", "ID": "123", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Time": "2018-02-06T12:30:59.000Z", "Phase": "P", "Polarity": "up", "Onset": "impulsive", "Picker": "other", "Amplitude": {"Amplitude": 5.5, "Period": 1.5, "SNR": 6.2}, "Beam": {"BackAzimuth": 22.5, "Slowness": 1.2, "PowerRatio": 4.6, "BackAzimuthError": 1.2, "SlownessError": 3.5, "PowerRatioError": 2.1}, "Filter": [{"Type": "BandPass", "HighPass": 1.2, "LowPass": 0.2, "Units": "Hertz"}], "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}, {"Type": "Correlation", "ID": "1234", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Phase": "P", "Time": "2018-02-06T12:30:59.000Z", "Correlation": 1.2, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "Magnitude": 5.6, "SNR": 1.2, "ZScore": 2.2, "DetectionThreshold": 1, "ThresholdType": "test", "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}]}

    def test_init(self):
        # Empty init
        detection = detectionformats.detection.Detection()

        self.assertFalse(hasattr(detection, 'id'))
        self.assertFalse(hasattr(detection.source, 'agencyID'))
        self.assertFalse(hasattr(detection.source, 'author'))
        self.assertFalse(hasattr(detection.hypocenter, 'latitude'))
        self.assertFalse(hasattr(detection.hypocenter, 'longitude'))
        self.assertFalse(hasattr(detection.hypocenter, 'depth'))
        self.assertFalse(hasattr(detection.hypocenter, 'time'))
        self.assertFalse(hasattr(detection.hypocenter, 'latitudeError'))
        self.assertFalse(hasattr(detection.hypocenter, 'longitudeError'))
        self.assertFalse(hasattr(detection.hypocenter, 'depthError'))
        self.assertFalse(hasattr(detection.hypocenter, 'timeError'))
        self.assertFalse(hasattr(detection, 'detectionType'))
        self.assertFalse(hasattr(detection.eventType, 'type'))
        self.assertFalse(hasattr(detection.eventType, 'certainty'))
        self.assertFalse(hasattr(detection, 'detectionTime'))
        self.assertFalse(hasattr(detection, 'bayes'))
        self.assertFalse(hasattr(detection, 'minimumDistance'))
        self.assertFalse(hasattr(detection, 'rms'))
        self.assertFalse(hasattr(detection, 'gap'))
        self.assertFalse(hasattr(detection, 'detector'))
        self.assertFalse(hasattr(detection, 'pickData'))
        self.assertFalse(hasattr(detection, 'correlationData'))

        detection = detectionformats.detection.Detection(self.ID,
            self.SOURCE, self.HYPOCENTER, self.DETECTIONTYPE, self.EVENTTYPE,
            self.DETECTIONTIME, self.BAYES, self.MINIMUMDISTANCE, self.RMS,
            self.GAP, self.DETECTOR, self.PICKDATA, self.CORRELATIONDATA)

        self.assertTrue(hasattr(detection, 'id'))
        self.assertTrue(hasattr(detection.source, 'agencyID'))
        self.assertTrue(hasattr(detection.source, 'author'))
        self.assertTrue(hasattr(detection.hypocenter, 'latitude'))
        self.assertTrue(hasattr(detection.hypocenter, 'longitude'))
        self.assertTrue(hasattr(detection.hypocenter, 'depth'))
        self.assertTrue(hasattr(detection.hypocenter, 'time'))
        self.assertTrue(hasattr(detection.hypocenter, 'latitudeError'))
        self.assertTrue(hasattr(detection.hypocenter, 'longitudeError'))
        self.assertTrue(hasattr(detection.hypocenter, 'depthError'))
        self.assertTrue(hasattr(detection.hypocenter, 'timeError'))
        self.assertTrue(hasattr(detection, 'detectionType'))
        self.assertTrue(hasattr(detection.eventType, 'type'))
        self.assertTrue(hasattr(detection.eventType, 'certainty'))
        self.assertTrue(hasattr(detection, 'detectionTime'))
        self.assertTrue(hasattr(detection, 'bayes'))
        self.assertTrue(hasattr(detection, 'minimumDistance'))
        self.assertTrue(hasattr(detection, 'rms'))
        self.assertTrue(hasattr(detection, 'gap'))
        self.assertTrue(hasattr(detection, 'detector'))
        self.assertTrue(hasattr(detection, 'pickData'))
        self.assertTrue(hasattr(detection, 'correlationData'))

        self.assertEqual(detection.id, self.ID)
        self.assertEqual(detection.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(detection.source.author, self.SOURCE.author)
        self.assertEqual(detection.hypocenter.latitude, self.HYPOCENTER.latitude)
        self.assertEqual(detection.hypocenter.longitude, self.HYPOCENTER.longitude)
        self.assertEqual(detection.hypocenter.depth, self.HYPOCENTER.depth)
        self.assertEqual(detection.hypocenter.time, self.HYPOCENTER.time)
        self.assertEqual(detection.hypocenter.latitudeError, self.HYPOCENTER.latitudeError)
        self.assertEqual(detection.hypocenter.longitudeError, self.HYPOCENTER.longitudeError)
        self.assertEqual(detection.hypocenter.depthError, self.HYPOCENTER.depthError)
        self.assertEqual(detection.hypocenter.timeError, self.HYPOCENTER.timeError)
        self.assertEqual(detection.detectionType, self.DETECTIONTYPE)
        self.assertEqual(detection.eventType.type, self.EVENTTYPE.type)
        self.assertEqual(detection.eventType.certainty, self.EVENTTYPE.certainty)
        self.assertEqual(detection.detectionTime, self.DETECTIONTIME)
        self.assertEqual(detection.bayes, self.BAYES)
        self.assertEqual(detection.minimumDistance, self.MINIMUMDISTANCE)
        self.assertEqual(detection.rms, self.RMS)
        self.assertEqual(detection.gap, self.GAP)
        self.assertEqual(detection.detector, self.DETECTOR)
        # not sure how to handle pick list
        # not sure how to handle correlation list

    def test_toJSON(self):
        detection = detectionformats.detection.Detection(self.ID,
            self.SOURCE, self.HYPOCENTER, self.DETECTIONTYPE, self.EVENTTYPE,
            self.DETECTIONTIME, self.BAYES, self.MINIMUMDISTANCE, self.RMS,
            self.GAP, self.DETECTOR, self.PICKDATA, self.CORRELATIONDATA)
        self.maxDiff = None
        self.assertEqual(detection.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        detection = detectionformats.detection.Detection()
        detection.fromJSONString(self.JSONSTRING)

        self.assertEqual(detection.id, self.ID)
        self.assertEqual(detection.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(detection.source.author, self.SOURCE.author)
        self.assertEqual(detection.hypocenter.latitude, self.HYPOCENTER.latitude)
        self.assertEqual(detection.hypocenter.longitude, self.HYPOCENTER.longitude)
        self.assertEqual(detection.hypocenter.depth, self.HYPOCENTER.depth)
        self.assertEqual(detection.hypocenter.time, self.HYPOCENTER.time)
        self.assertEqual(detection.hypocenter.latitudeError, self.HYPOCENTER.latitudeError)
        self.assertEqual(detection.hypocenter.longitudeError, self.HYPOCENTER.longitudeError)
        self.assertEqual(detection.hypocenter.depthError, self.HYPOCENTER.depthError)
        self.assertEqual(detection.hypocenter.timeError, self.HYPOCENTER.timeError)
        self.assertEqual(detection.detectionType, self.DETECTIONTYPE)
        self.assertEqual(detection.eventType.type, self.EVENTTYPE.type)
        self.assertEqual(detection.eventType.certainty, self.EVENTTYPE.certainty)
        self.assertEqual(detection.detectionTime, self.DETECTIONTIME)
        self.assertEqual(detection.bayes, self.BAYES)
        self.assertEqual(detection.minimumDistance, self.MINIMUMDISTANCE)
        self.assertEqual(detection.rms, self.RMS)
        self.assertEqual(detection.gap, self.GAP)
        self.assertEqual(detection.detector, self.DETECTOR)
        # not sure how to handle pick and correlation lists

    def test_toDict(self):
        detection = detectionformats.detection.Detection(self.ID,
            self.SOURCE, self.HYPOCENTER, self.DETECTIONTYPE, self.EVENTTYPE,
            self.DETECTIONTIME, self.BAYES, self.MINIMUMDISTANCE, self.RMS,
            self.GAP, self.DETECTOR, self.PICKDATA, self.CORRELATIONDATA)
        self.maxDiff = None
        self.assertEqual(detection.toDict(), self.DICT)

    def test_fromDict(self):
        detection = detectionformats.detection.Detection()
        detection.fromDict(self.DICT)

        self.assertEqual(detection.id, self.ID)
        self.assertEqual(detection.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(detection.source.author, self.SOURCE.author)
        self.assertEqual(detection.hypocenter.latitude, self.HYPOCENTER.latitude)
        self.assertEqual(detection.hypocenter.longitude, self.HYPOCENTER.longitude)
        self.assertEqual(detection.hypocenter.depth, self.HYPOCENTER.depth)
        self.assertEqual(detection.hypocenter.time, self.HYPOCENTER.time)
        self.assertEqual(detection.hypocenter.latitudeError, self.HYPOCENTER.latitudeError)
        self.assertEqual(detection.hypocenter.longitudeError, self.HYPOCENTER.longitudeError)
        self.assertEqual(detection.hypocenter.depthError, self.HYPOCENTER.depthError)
        self.assertEqual(detection.hypocenter.timeError, self.HYPOCENTER.timeError)
        self.assertEqual(detection.detectionType, self.DETECTIONTYPE)
        self.assertEqual(detection.eventType.type, self.EVENTTYPE.type)
        self.assertEqual(detection.eventType.certainty, self.EVENTTYPE.certainty)
        self.assertEqual(detection.detectionTime, self.DETECTIONTIME)
        self.assertEqual(detection.bayes, self.BAYES)
        self.assertEqual(detection.minimumDistance, self.MINIMUMDISTANCE)
        self.assertEqual(detection.rms, self.RMS)
        self.assertEqual(detection.gap, self.GAP)
        self.assertEqual(detection.detector, self.DETECTOR)
        # not sure how to handle pick and correlation lists

    def test_isValid(self):
        detection = detectionformats.detection.Detection(self.ID,
            self.SOURCE, self.HYPOCENTER, self.DETECTIONTYPE, self.EVENTTYPE,
            self.DETECTIONTIME, self.BAYES, self.MINIMUMDISTANCE, self.RMS,
            self.GAP, self.DETECTOR, self.PICKDATA, self.CORRELATIONDATA)
        self.assertTrue(detection.isValid())

        badDetection = detectionformats.detection.Detection()
        self.assertFalse(badDetection.isValid())

if __name__ == '__main__':
    unittest.main()
