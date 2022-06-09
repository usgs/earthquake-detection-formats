#!/usr/bin/env python

# package imports
import detectionformats.correlation
import detectionformats.site
import detectionformats.source
import detectionformats.hypocenter
import detectionformats.association
import detectionformats.eventtype

# stdlib imports
import unittest
import datetime


class TestCorrelation(unittest.TestCase):
    ID = "123456789"
    SITE = detectionformats.site.Site("BOZ", "BHZ", "US", "00")
    SOURCE = detectionformats.source.Source("testAgency", "testAuthor")
    PHASE = "P"
    TIME = datetime.datetime(2018, 2, 6, 12, 30, 59, 0)
    CORRELATION = 1.2
    HYPOCENTER = detectionformats.hypocenter.Hypocenter(
        45.123,
        -120.33,
        55.2,
        datetime.datetime(2018, 2, 6, 12, 32, 50, 0),
        2.5,
        1.2,
        20.0,
        6.5,
    )
    EVENTTYPE = detectionformats.eventtype.EventType("Earthquake", "Suspected")
    EVENTTYPETYPE = "Earthquake"
    CERTAINTY = "Suspected"
    MAGNITUDE = 2.5
    SNR = 1.2
    ZSCORE = 5.6
    DETECTIONTHRESHOLD = 1.0
    THRESHOLDTYPE = "test"
    ASSOCIATIONINFO = detectionformats.association.Association(
        "P", 12.5, 255.0, 3.2, 4.8
    )

    JSONSTRING = '{"Type": "Correlation", "ID": "123456789", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}, "Phase": "P", "Time": "2018-02-06T12:30:59.000Z", "Correlation": 1.2, "Hypocenter": {"Latitude": 45.123, "Longitude": -120.33, "Depth": 55.2, "Time": "2018-02-06T12:32:50.000Z", "LatitudeError": 2.5, "LongitudeError": 1.2, "DepthError": 20.0, "TimeError": 6.5}, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "Magnitude": 2.5, "SNR": 1.2, "ZScore": 5.6, "DetectionThreshold": 1.0, "ThresholdType": "test", "AssociationInfo": {"Phase": "P", "Distance": 12.5, "Azimuth": 255.0, "Residual": 3.2, "Sigma": 4.8}}'
    DICT = {
        "Type": "Correlation",
        "ID": "123456789",
        "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"},
        "Source": {"AgencyID": "testAgency", "Author": "testAuthor"},
        "Phase": "P",
        "Time": "2018-02-06T12:30:59.000Z",
        "Correlation": 1.2,
        "Hypocenter": {
            "Latitude": 45.123,
            "Longitude": -120.33,
            "Depth": 55.2,
            "Time": "2018-02-06T12:32:50.000Z",
            "LatitudeError": 2.5,
            "LongitudeError": 1.2,
            "DepthError": 20.0,
            "TimeError": 6.5,
        },
        "EventType": {"Type": "Earthquake", "Certainty": "Suspected"},
        "Magnitude": 2.5,
        "SNR": 1.2,
        "ZScore": 5.6,
        "DetectionThreshold": 1.0,
        "ThresholdType": "test",
        "AssociationInfo": {
            "Phase": "P",
            "Distance": 12.5,
            "Azimuth": 255.0,
            "Residual": 3.2,
            "Sigma": 4.8,
        },
    }

    def test_init(self):
        # Empty init
        correlation = detectionformats.correlation.Correlation()

        self.assertFalse(hasattr(correlation, "id"))
        self.assertFalse(hasattr(correlation.site, "station"))
        self.assertFalse(hasattr(correlation.site, "channel"))
        self.assertFalse(hasattr(correlation.site, "network"))
        self.assertFalse(hasattr(correlation.site, "location"))
        self.assertFalse(hasattr(correlation.source, "agencyID"))
        self.assertFalse(hasattr(correlation.source, "author"))
        self.assertFalse(hasattr(correlation, "phase"))
        self.assertFalse(hasattr(correlation, "correlation"))
        self.assertFalse(hasattr(correlation, "time"))
        self.assertFalse(hasattr(correlation.hypocenter, "latitude"))
        self.assertFalse(hasattr(correlation.hypocenter, "longitude"))
        self.assertFalse(hasattr(correlation.hypocenter, "depth"))
        self.assertFalse(hasattr(correlation.hypocenter, "time"))
        self.assertFalse(hasattr(correlation.hypocenter, "latitudeError"))
        self.assertFalse(hasattr(correlation.hypocenter, "longitudeError"))
        self.assertFalse(hasattr(correlation.hypocenter, "depthError"))
        self.assertFalse(hasattr(correlation.hypocenter, "timeError"))
        self.assertFalse(hasattr(correlation.eventType, "type"))
        self.assertFalse(hasattr(correlation.eventType, "certainty"))
        self.assertFalse(hasattr(correlation, "magnitude"))
        self.assertFalse(hasattr(correlation, "snr"))
        self.assertFalse(hasattr(correlation, "ZScore"))
        self.assertFalse(hasattr(correlation, "detectionThreshold"))
        self.assertFalse(hasattr(correlation, "thresholdType"))
        self.assertFalse(hasattr(correlation.associationInfo, "phase"))
        self.assertFalse(hasattr(correlation.associationInfo, "distance"))
        self.assertFalse(hasattr(correlation.associationInfo, "azimuth"))
        self.assertFalse(hasattr(correlation.associationInfo, "residual"))
        self.assertFalse(hasattr(correlation.associationInfo, "sigma"))

        correlation = detectionformats.correlation.Correlation(
            self.ID,
            self.SITE,
            self.SOURCE,
            self.PHASE,
            self.TIME,
            self.CORRELATION,
            self.HYPOCENTER,
            self.EVENTTYPE,
            self.MAGNITUDE,
            self.SNR,
            self.ZSCORE,
            self.DETECTIONTHRESHOLD,
            self.THRESHOLDTYPE,
            self.ASSOCIATIONINFO,
        )

        self.assertTrue(hasattr(correlation, "id"))
        self.assertTrue(hasattr(correlation.site, "station"))
        self.assertTrue(hasattr(correlation.site, "channel"))
        self.assertTrue(hasattr(correlation.site, "network"))
        self.assertTrue(hasattr(correlation.site, "location"))
        self.assertTrue(hasattr(correlation.source, "agencyID"))
        self.assertTrue(hasattr(correlation.source, "author"))
        self.assertTrue(hasattr(correlation, "phase"))
        self.assertTrue(hasattr(correlation, "correlation"))
        self.assertTrue(hasattr(correlation, "time"))
        self.assertTrue(hasattr(correlation.hypocenter, "latitude"))
        self.assertTrue(hasattr(correlation.hypocenter, "longitude"))
        self.assertTrue(hasattr(correlation.hypocenter, "depth"))
        self.assertTrue(hasattr(correlation.hypocenter, "time"))
        self.assertTrue(hasattr(correlation.hypocenter, "latitudeError"))
        self.assertTrue(hasattr(correlation.hypocenter, "longitudeError"))
        self.assertTrue(hasattr(correlation.hypocenter, "depthError"))
        self.assertTrue(hasattr(correlation.hypocenter, "timeError"))
        self.assertTrue(hasattr(correlation.eventType, "type"))
        self.assertTrue(hasattr(correlation.eventType, "certainty"))
        self.assertTrue(hasattr(correlation, "magnitude"))
        self.assertTrue(hasattr(correlation, "snr"))
        self.assertTrue(hasattr(correlation, "ZScore"))
        self.assertTrue(hasattr(correlation, "detectionThreshold"))
        self.assertTrue(hasattr(correlation, "thresholdType"))
        self.assertTrue(hasattr(correlation.associationInfo, "phase"))
        self.assertTrue(hasattr(correlation.associationInfo, "distance"))
        self.assertTrue(hasattr(correlation.associationInfo, "azimuth"))
        self.assertTrue(hasattr(correlation.associationInfo, "residual"))
        self.assertTrue(hasattr(correlation.associationInfo, "sigma"))

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
        self.assertEqual(
            correlation.hypocenter.latitudeError, self.HYPOCENTER.latitudeError
        )
        self.assertEqual(
            correlation.hypocenter.longitudeError, self.HYPOCENTER.longitudeError
        )
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
        self.assertEqual(
            correlation.associationInfo.distance, self.ASSOCIATIONINFO.distance
        )
        self.assertEqual(
            correlation.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth
        )
        self.assertEqual(
            correlation.associationInfo.residual, self.ASSOCIATIONINFO.residual
        )
        self.assertEqual(correlation.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)

    def test_toJSON(self):
        correlation = detectionformats.correlation.Correlation(
            self.ID,
            self.SITE,
            self.SOURCE,
            self.PHASE,
            self.TIME,
            self.CORRELATION,
            self.HYPOCENTER,
            self.EVENTTYPE,
            self.MAGNITUDE,
            self.SNR,
            self.ZSCORE,
            self.DETECTIONTHRESHOLD,
            self.THRESHOLDTYPE,
            self.ASSOCIATIONINFO,
        )
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
        self.assertEqual(
            correlation.hypocenter.latitudeError, self.HYPOCENTER.latitudeError
        )
        self.assertEqual(
            correlation.hypocenter.longitudeError, self.HYPOCENTER.longitudeError
        )
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
        self.assertEqual(
            correlation.associationInfo.distance, self.ASSOCIATIONINFO.distance
        )
        self.assertEqual(
            correlation.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth
        )
        self.assertEqual(
            correlation.associationInfo.residual, self.ASSOCIATIONINFO.residual
        )
        self.assertEqual(correlation.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)

    def test_toDict(self):
        correlation = detectionformats.correlation.Correlation(
            self.ID,
            self.SITE,
            self.SOURCE,
            self.PHASE,
            self.TIME,
            self.CORRELATION,
            self.HYPOCENTER,
            self.EVENTTYPE,
            self.MAGNITUDE,
            self.SNR,
            self.ZSCORE,
            self.DETECTIONTHRESHOLD,
            self.THRESHOLDTYPE,
            self.ASSOCIATIONINFO,
        )
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
        self.assertEqual(
            correlation.hypocenter.latitudeError, self.HYPOCENTER.latitudeError
        )
        self.assertEqual(
            correlation.hypocenter.longitudeError, self.HYPOCENTER.longitudeError
        )
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
        self.assertEqual(
            correlation.associationInfo.distance, self.ASSOCIATIONINFO.distance
        )
        self.assertEqual(
            correlation.associationInfo.azimuth, self.ASSOCIATIONINFO.azimuth
        )
        self.assertEqual(
            correlation.associationInfo.residual, self.ASSOCIATIONINFO.residual
        )
        self.assertEqual(correlation.associationInfo.sigma, self.ASSOCIATIONINFO.sigma)

    def test_isValid(self):
        correlation = detectionformats.correlation.Correlation(
            self.ID,
            self.SITE,
            self.SOURCE,
            self.PHASE,
            self.TIME,
            self.CORRELATION,
            self.HYPOCENTER,
            self.EVENTTYPE,
            self.MAGNITUDE,
            self.SNR,
            self.ZSCORE,
            self.DETECTIONTHRESHOLD,
            self.THRESHOLDTYPE,
            self.ASSOCIATIONINFO,
        )
        self.assertTrue(correlation.isValid())

        badCorrelation = detectionformats.correlation.Correlation()
        self.assertFalse(badCorrelation.isValid())


if __name__ == "__main__":
    unittest.main()
