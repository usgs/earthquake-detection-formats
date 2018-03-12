#!/usr/bin/env python

#package imports
import detectionformats.stationinforequest
import detectionformats.site
import detectionformats.source

#stdlib imports
import unittest

class TestStationInfoRequest(unittest.TestCase):
    SITE = detectionformats.site.Site('BOZ', 'BHZ', 'US', '00')
    SOURCE = detectionformats.source.Source('testAgency', 'testAuthor')
    JSONSTRING = '{"Type": "StationInfoRequest", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}'
    DICT = {"Type": "StationInfoRequest", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}

    def test_init(self):
        # Empty init
        stationinforequest = detectionformats.stationinforequest.StationInfoRequest()

        try:
            stationinforequest.site.station
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinforequest.site.channel
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinforequest.site.network
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinforequest.site.location
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinforequest.source.agencyID
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinforequest.source.author
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        stationinforequest = detectionformats.stationinforequest.StationInfoRequest(self.SITE,
            self.SOURCE)

        try:
            stationinforequest.site.station
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinforequest.site.station, self.SITE.station)

        try:
            stationinforequest.site.channel
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinforequest.site.channel, self.SITE.channel)

        try:
            stationinforequest.site.network
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinforequest.site.network, self.SITE.network)

        try:
            stationinforequest.site.location
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinforequest.site.location, self.SITE.location)

        try:
            stationinforequest.source.agencyID
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinforequest.source.agencyID, self.SOURCE.agencyID)

        try:
            stationinforequest.source.author
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinforequest.source.author, self.SOURCE.author)

    def test_toJSON(self):
        stationinforequest = detectionformats.stationinforequest.StationInfoRequest(self.SITE,
            self.SOURCE)
        self.assertEqual(stationinforequest.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        stationinforequest = detectionformats.stationinforequest.StationInfoRequest()
        stationinforequest.fromJSONString(self.JSONSTRING)

        self.assertEqual(stationinforequest.site.station, self.SITE.station)
        self.assertEqual(stationinforequest.site.channel, self.SITE.channel)
        self.assertEqual(stationinforequest.site.network, self.SITE.network)
        self.assertEqual(stationinforequest.site.location, self.SITE.location)
        self.assertEqual(stationinforequest.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(stationinforequest.source.author, self.SOURCE.author)

    def test_toDict(self):
        stationinforequest = detectionformats.stationinforequest.StationInfoRequest(self.SITE,
            self.SOURCE)
        self.assertEqual(stationinforequest.toDict(), self.DICT)

    def test_fromDict(self):
        stationinforequest = detectionformats.stationinforequest.StationInfoRequest()
        stationinforequest.fromDict(self.DICT)

        self.assertEqual(stationinforequest.site.station, self.SITE.station)
        self.assertEqual(stationinforequest.site.channel, self.SITE.channel)
        self.assertEqual(stationinforequest.site.network, self.SITE.network)
        self.assertEqual(stationinforequest.site.location, self.SITE.location)
        self.assertEqual(stationinforequest.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(stationinforequest.source.author, self.SOURCE.author)

    def test_isValid(self):
        stationinforequest = detectionformats.stationinforequest.StationInfoRequest(self.SITE,
            self.SOURCE)
        self.assertTrue(stationinforequest.isValid())

        badStationInfoRequest = detectionformats.stationinforequest.StationInfoRequest()
        self.assertFalse(badStationInfoRequest.isValid())

if __name__ == '__main__':
    unittest.main()
