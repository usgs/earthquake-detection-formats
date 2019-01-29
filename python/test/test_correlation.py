#!/usr/bin/env python

#package imports
import detectionformats.correlation
import detectionformats.site
import detectionformats.source
import detectionformats.hypocenter
import detectionformats.association
import detectionformats.eventtype

#stdlib imports
import unittest
import datetime

class TestCorrelation(unittest.TestCase):
    ID = '123456789'
    SITE = detectionformats.site.Site('BOZ', 'BHZ', 'US', '00')
    SOURCE = detectionformats.source.Source('testAgency', 'testAuthor')
    PHASE = 'P'
    TIME = datetime.datetime(2018, 2, 6, 12, 30, 59, 0)
    CORRELATION = 1.2
    HYPOCENTER = detectionformats.hypocenter.Hypocenter(45.123,
        -120.33, 55.2, datetime.datetime(2018, 2, 6, 12, 32, 50, 0), 2.5,
        1.2, 20.0, 6.5)
    EVENTTYPE = detectionformats.eventtype.EventType('Earthquake', 'Suspected')
    EVENTTYPETYPE = 'Earthquake'
    CERTAINTY = 'Suspected'
    MAGNITUDE = 2.5
    SNR = 1.2
    ZSCORE = 5.6
    DETECTIONTHRESHOLD = 1.0
    THRESHOLDTYPE = 'test'
    ASSOCIATIONINFO = detectionformats.association.Association('P',
        12.5, 255.0, 3.2, 4.8)

    JSONSTRING = '{"Type": "Correlation", "ID": "123456789", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Phase": "P", "Time": "2018-02-06T12:30:59.000Z", "Correlation": 1.2, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "Magnitude": 2.5, "SNR": 1.2, "ZScore": 5.6, "DetectionThreshold": 1.0, "ThresholdType": "test", "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}'
    DICT = {"Type": "Correlation", "ID": "123456789", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Phase": "P", "Time": "2018-02-06T12:30:59.000Z", "Correlation": 1.2, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "Magnitude": 2.5, "SNR": 1.2, "ZScore": 5.6, "DetectionThreshold": 1.0, "ThresholdType": "test", "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}

    def test_init(self):
        # Empty init
        correlation = detectionformats.correlation.Correlation()

        try:
            correlation.id
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.site.station
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.site.channel
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.site.network
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.site.location
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.source.agencyID
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.source.author
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.phase
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.correlation
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.time
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.hypocenter.latitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.hypocenter.longitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.hypocenter.depth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.hypocenter.time
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.hypocenter.latitudeError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.hypocenter.longitudeError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.hypocenter.depthError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.hypocenter.timeError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.eventType.type
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.eventType.certainty
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.magnitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.snr
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.ZScore
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.detectionThreshold
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.thresholdType
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.associationInfo.phase
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.associationInfo.distance
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.associationInfo.azimuth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.associationInfo.residual
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            correlation.associationInfo.sigma
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        correlation = detectionformats.correlation.Correlation(self.ID,
            self.SITE, self.SOURCE, self.PHASE, self.TIME, self.CORRELATION,
            self.HYPOCENTER, self.EVENTTYPE, self.MAGNITUDE, self.SNR,
            self.ZSCORE, self.DETECTIONTHRESHOLD, self.THRESHOLDTYPE,
            self.ASSOCIATIONINFO)

        try:
            correlation.id
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.id, self.ID)

        try:
            correlation.site.station
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.site.station, self.SITE.station)

        try:
            correlation.site.channel
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.site.channel, self.SITE.channel)

        try:
            correlation.site.network
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.site.network, self.SITE.network)

        try:
            correlation.site.location
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.site.location, self.SITE.location)

        try:
            correlation.source.agencyID
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.source.agencyID, self.SOURCE.agencyID)

        try:
            correlation.source.author
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.source.author, self.SOURCE.author)

        try:
            correlation.phase
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.phase, self.PHASE)

        try:
            correlation.correlation
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.correlation, self.CORRELATION)

        try:
            correlation.time
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.time, self.TIME)

        try:
            correlation.hypocenter.latitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.hypocenter.latitude, self.HYPOCENTER.latitude)

        try:
            correlation.hypocenter.longitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.hypocenter.longitude, self.HYPOCENTER.longitude)

        try:
            correlation.hypocenter.depth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.hypocenter.depth, self.HYPOCENTER.depth)

        try:
            correlation.hypocenter.time
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.hypocenter.time, self.HYPOCENTER.time)

        try:
            correlation.hypocenter.latitudeError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.hypocenter.latitudeError, self.HYPOCENTER.latitudeError)

        try:
            correlation.hypocenter.longitudeError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.hypocenter.longitudeError, self.HYPOCENTER.longitudeError)

        try:
            correlation.hypocenter.depthError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.hypocenter.depthError, self.HYPOCENTER.depthError)

        try:
            correlation.hypocenter.timeError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.hypocenter.timeError, self.HYPOCENTER.timeError)

        try:
            correlation.eventType.type
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.eventType.type, self.EVENTTYPETYPE)

        try:
            correlation.eventType.certainty
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.eventType.certainty, self.CERTAINTY)

        try:
            correlation.magnitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.magnitude, self.MAGNITUDE)

        try:
            correlation.snr
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.snr, self.SNR)

        try:
            correlation.ZScore
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.ZScore, self.ZSCORE)

        try:
            correlation.detectionThreshold
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.detectionThreshold, self.DETECTIONTHRESHOLD)

        try:
            correlation.thresholdType
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.thresholdType, self.THRESHOLDTYPE)

        try:
            correlation.associationInfo.phase
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.associationInfo.phase, self.ASSOCIATIONINFO.phase)

        try:
            correlation.associationInfo.distance
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.associationInfo.distance, self.ASSOCIATIONINFO.distance)

        try:
            correlation.associationInfo.azimuth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth)

        try:
            correlation.associationInfo.residual
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.associationInfo.residual, self.ASSOCIATIONINFO.residual)

        try:
            correlation.associationInfo.sigma
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(correlation.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)

    def test_toJSON(self):
        correlation = detectionformats.correlation.Correlation(self.ID,
            self.SITE, self.SOURCE, self.PHASE, self.TIME, self.CORRELATION,
            self.HYPOCENTER, self.EVENTTYPE, self.MAGNITUDE, self.SNR,
            self.ZSCORE, self.DETECTIONTHRESHOLD, self.THRESHOLDTYPE,
            self.ASSOCIATIONINFO)
        self.assertEqual(correlation.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        correlation = detectionformats.correlation.Correlation()
        correlation.fromJSONString(self.JSONSTRING)

        self.assertEqual(correlation.id, self.ID)
        self.assertEqual(correlation.site.station, self.SITE.station)
        self.assertEqual(correlation.site.channel, self.SITE.channel)
        self.assertEqual(correlation.site.network, self.SITE.network)
        self.assertEqual(correlation.site.location, self.SITE.location)
        self.assertEqual(correlation.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(correlation.source.author, self.SOURCE.author)
        self.assertEqual(correlation.phase, self.PHASE)
        self.assertEqual(correlation.correlation, self.CORRELATION)
        self.assertEqual(correlation.time, self.TIME)
        self.assertEqual(correlation.hypocenter.latitude, self.HYPOCENTER.latitude)
        self.assertEqual(correlation.hypocenter.longitude, self.HYPOCENTER.longitude)
        self.assertEqual(correlation.hypocenter.depth, self.HYPOCENTER.depth)
        self.assertEqual(correlation.hypocenter.time, self.HYPOCENTER.time)
        self.assertEqual(correlation.hypocenter.latitudeError, self.HYPOCENTER.latitudeError)
        self.assertEqual(correlation.hypocenter.longitudeError, self.HYPOCENTER.longitudeError)
        self.assertEqual(correlation.hypocenter.depthError, self.HYPOCENTER.depthError)
        self.assertEqual(correlation.hypocenter.timeError, self.HYPOCENTER.timeError)
        self.assertEqual(correlation.eventType.type, self.EVENTTYPETYPE)
        self.assertEqual(correlation.eventType.certainty, self.CERTAINTY)
        self.assertEqual(correlation.magnitude, self.MAGNITUDE)
        self.assertEqual(correlation.snr, self.SNR)
        self.assertEqual(correlation.ZScore, self.ZSCORE)
        self.assertEqual(correlation.detectionThreshold, self.DETECTIONTHRESHOLD)
        self.assertEqual(correlation.thresholdType, self.THRESHOLDTYPE)
        self.assertEqual(correlation.associationInfo.phase, self.ASSOCIATIONINFO.phase)
        self.assertEqual(correlation.associationInfo.distance, self.ASSOCIATIONINFO.distance)
        self.assertEqual(correlation.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth)
        self.assertEqual(correlation.associationInfo.residual, self.ASSOCIATIONINFO.residual)
        self.assertEqual(correlation.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)

    def test_toDict(self):
        correlation = detectionformats.correlation.Correlation(self.ID,
            self.SITE, self.SOURCE, self.PHASE, self.TIME, self.CORRELATION,
            self.HYPOCENTER, self.EVENTTYPE, self.MAGNITUDE, self.SNR,
            self.ZSCORE, self.DETECTIONTHRESHOLD, self.THRESHOLDTYPE,
            self.ASSOCIATIONINFO)
        self.assertEqual(correlation.toDict(), self.DICT)

    def test_fromDict(self):
        correlation = detectionformats.correlation.Correlation()
        correlation.fromDict(self.DICT)

        self.assertEqual(correlation.id, self.ID)
        self.assertEqual(correlation.site.station, self.SITE.station)
        self.assertEqual(correlation.site.channel, self.SITE.channel)
        self.assertEqual(correlation.site.network, self.SITE.network)
        self.assertEqual(correlation.site.location, self.SITE.location)
        self.assertEqual(correlation.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(correlation.source.author, self.SOURCE.author)
        self.assertEqual(correlation.phase, self.PHASE)
        self.assertEqual(correlation.correlation, self.CORRELATION)
        self.assertEqual(correlation.time, self.TIME)
        self.assertEqual(correlation.hypocenter.latitude, self.HYPOCENTER.latitude)
        self.assertEqual(correlation.hypocenter.longitude, self.HYPOCENTER.longitude)
        self.assertEqual(correlation.hypocenter.depth, self.HYPOCENTER.depth)
        self.assertEqual(correlation.hypocenter.time, self.HYPOCENTER.time)
        self.assertEqual(correlation.hypocenter.latitudeError, self.HYPOCENTER.latitudeError)
        self.assertEqual(correlation.hypocenter.longitudeError, self.HYPOCENTER.longitudeError)
        self.assertEqual(correlation.hypocenter.depthError, self.HYPOCENTER.depthError)
        self.assertEqual(correlation.hypocenter.timeError, self.HYPOCENTER.timeError)
        self.assertEqual(correlation.eventType.type, self.EVENTTYPETYPE)
        self.assertEqual(correlation.eventType.certainty, self.CERTAINTY)
        self.assertEqual(correlation.magnitude, self.MAGNITUDE)
        self.assertEqual(correlation.snr, self.SNR)
        self.assertEqual(correlation.ZScore, self.ZSCORE)
        self.assertEqual(correlation.detectionThreshold, self.DETECTIONTHRESHOLD)
        self.assertEqual(correlation.thresholdType, self.THRESHOLDTYPE)
        self.assertEqual(correlation.associationInfo.phase, self.ASSOCIATIONINFO.phase)
        self.assertEqual(correlation.associationInfo.distance, self.ASSOCIATIONINFO.distance)
        self.assertEqual(correlation.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth)
        self.assertEqual(correlation.associationInfo.residual, self.ASSOCIATIONINFO.residual)
        self.assertEqual(correlation.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)

    def test_isValid(self):
        correlation = detectionformats.correlation.Correlation(self.ID,
            self.SITE, self.SOURCE, self.PHASE, self.TIME, self.CORRELATION,
            self.HYPOCENTER, self.EVENTTYPE, self.MAGNITUDE, self.SNR,
            self.ZSCORE, self.DETECTIONTHRESHOLD, self.THRESHOLDTYPE,
            self.ASSOCIATIONINFO)
        self.assertTrue(correlation.isValid())

        badCorrelation = detectionformats.correlation.Correlation()
        self.assertFalse(badCorrelation.isValid())

if __name__ == '__main__':
    unittest.main()
