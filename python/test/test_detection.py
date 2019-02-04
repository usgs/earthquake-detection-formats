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
    SITE = detectionformats.site.Site('BOZ', 'BHZ', 'US', '00')
    TIME = datetime.datetime(2018, 2, 6, 12, 30, 59, 0)
    aFilter = detectionformats.filter.Filter(1.2, 0.2)
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

    JSONSTRING = '{"Type": "Detection", "ID": "123456789", "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "DetectionType": "New", "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "DetectionTime": "2018-02-06T12:31:59.000Z", "Bayes": 2.5, "MinimumDistance": 1.2, "RMS": 5.6, "Gap": 1.0, "Data": [{"Type": "Pick", "ID": "123", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Time": "2018-02-06T12:30:59.000Z", "Phase": "P", "Polarity": "up", "Onset": "impulsive", "Picker": "other", "Filter": [{"HighPass": 1.2, "LowPass": 0.2}], "Amplitude": {"Amplitude": 5.5, "Period": 1.5, "SNR": 6.2}, "Beam": {"BackAzimuth": 22.5, "Slowness": 1.2, "PowerRatio": 4.6, "BackAzimuthError": 1.2, "SlownessError": 3.5, "PowerRatioError": 2.1}, "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}, {"Type": "Correlation", "ID": "1234", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Phase": "P", "Time": "2018-02-06T12:30:59.000Z", "Correlation": 1.2, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "Magnitude": 5.6, "SNR": 1.2, "ZScore": 2.2, "DetectionThreshold": 1, "ThresholdType": "test", "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}]}'

    DICT = {"Type": "Detection", "ID": "123456789", "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "DetectionType": "New", "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "DetectionTime": "2018-02-06T12:31:59.000Z", "Bayes": 2.5, "MinimumDistance": 1.2, "RMS": 5.6, "Gap": 1.0, "Data": [{"Type": "Pick", "ID": "123", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Time": "2018-02-06T12:30:59.000Z", "Phase": "P", "Polarity": "up", "Onset": "impulsive", "Picker": "other", "Amplitude": {"Amplitude": 5.5, "Period": 1.5, "SNR": 6.2}, "Beam": {"BackAzimuth": 22.5, "Slowness": 1.2, "PowerRatio": 4.6, "BackAzimuthError": 1.2, "SlownessError": 3.5, "PowerRatioError": 2.1}, "Filter": [{"HighPass": 1.2, "LowPass": 0.2}], "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}, {"Type": "Correlation", "ID": "1234", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Phase": "P", "Time": "2018-02-06T12:30:59.000Z", "Correlation": 1.2, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "Magnitude": 5.6, "SNR": 1.2, "ZScore": 2.2, "DetectionThreshold": 1, "ThresholdType": "test", "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}]}

    def test_init(self):
        # Empty init
        detection = detectionformats.detection.Detection()

        try:
            detection.id
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.source.agencyID
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.source.author
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.hypocenter.latitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.hypocenter.longitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.hypocenter.depth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.hypocenter.time
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.hypocenter.latitudeError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.hypocenter.longitudeError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.hypocenter.depthError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.hypocenter.timeError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.detectionType
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.eventType.type
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.eventType.certainty
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.detectionTime
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.bayes
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.minimumDistance
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.rms
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.newGap
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.pickData
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            detection.correlationData
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        detection = detectionformats.detection.Detection(self.ID,
            self.SOURCE, self.HYPOCENTER, self.DETECTIONTYPE, self.EVENTTYPE,
            self.DETECTIONTIME, self.BAYES, self.MINIMUMDISTANCE, self.RMS,
            self.GAP, self.PICKDATA, self.CORRELATIONDATA)

        try:
            detection.id
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.id, self.ID)

        try:
            detection.source.agencyID
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.source.agencyID, self.SOURCE.agencyID)

        try:
            detection.source.author
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.source.author, self.SOURCE.author)

        try:
            detection.hypocenter.latitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.hypocenter.latitude, self.HYPOCENTER.latitude)

        try:
            detection.hypocenter.longitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.hypocenter.longitude, self.HYPOCENTER.longitude)

        try:
            detection.hypocenter.depth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.hypocenter.depth, self.HYPOCENTER.depth)

        try:
            detection.hypocenter.time
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.hypocenter.time, self.HYPOCENTER.time)

        try:
            detection.hypocenter.latitudeError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.hypocenter.latitudeError, self.HYPOCENTER.latitudeError)

        try:
            detection.hypocenter.longitudeError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.hypocenter.longitudeError, self.HYPOCENTER.longitudeError)

        try:
            detection.hypocenter.depthError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.hypocenter.depthError, self.HYPOCENTER.depthError)

        try:
            detection.hypocenter.timeError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.hypocenter.timeError, self.HYPOCENTER.timeError)

        try:
            detection.detectionType
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.detectionType, self.DETECTIONTYPE)

        try:
            detection.eventType.type
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.eventType.type, self.EVENTTYPE.type)

        try:
            detection.eventType.certainty
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.eventType.certainty, self.EVENTTYPE.certainty)

        try:
            detection.detectionTime
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.detectionTime, self.DETECTIONTIME)

        try:
            detection.bayes
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.bayes, self.BAYES)

        try:
            detection.minimumDistance
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.minimumDistance, self.MINIMUMDISTANCE)

        try:
            detection.rms
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.rms, self.RMS)

        try:
            detection.gap
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(detection.gap, self.GAP)

        try:
            detection.pickData
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        # not sure how to handle pick list

        try:
            detection.pickData
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        # not sure how to handle correlation list

    def test_toJSON(self):
        detection = detectionformats.detection.Detection(self.ID,
            self.SOURCE, self.HYPOCENTER, self.DETECTIONTYPE, self.EVENTTYPE,
            self.DETECTIONTIME, self.BAYES, self.MINIMUMDISTANCE, self.RMS,
            self.GAP, self.PICKDATA, self.CORRELATIONDATA)
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
        # not sure how to handle pick and correlation lists

    def test_toDict(self):
        detection = detectionformats.detection.Detection(self.ID,
            self.SOURCE, self.HYPOCENTER, self.DETECTIONTYPE, self.EVENTTYPE,
            self.DETECTIONTIME, self.BAYES, self.MINIMUMDISTANCE, self.RMS,
            self.GAP, self.PICKDATA, self.CORRELATIONDATA)
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
        # not sure how to handle pick and correlation lists

    def test_isValid(self):
        detection = detectionformats.detection.Detection(self.ID,
            self.SOURCE, self.HYPOCENTER, self.DETECTIONTYPE, self.EVENTTYPE,
            self.DETECTIONTIME, self.BAYES, self.MINIMUMDISTANCE, self.RMS,
            self.GAP, self.PICKDATA, self.CORRELATIONDATA)
        self.assertTrue(detection.isValid())

        badDetection = detectionformats.detection.Detection()
        self.assertFalse(badDetection.isValid())

if __name__ == '__main__':
    unittest.main()
