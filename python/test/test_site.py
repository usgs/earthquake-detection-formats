#!/usr/bin/env python

#package imports
import detectionformats.site

#stdlib imports
import unittest

class TestSite(unittest.TestCase):
    STATION = 'BOZ'
    CHANNEL = 'BHZ'
    NETWORK = 'US'
    LOCATION = '00'
    JSONSTRING = '{"Station": "BOZ", "Network": "US", "Channel": "BHZ", "Location": "00"}'
    DICT = {'Channel': 'BHZ', 'Location': '00', 'Network': 'US', 'Station': 'BOZ'}

    def test_init(self):
        # Empty init
        site = detectionformats.site.Site()

        try:
            site.station
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            site.channel
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            site.network
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            site.location
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        site = detectionformats.site.Site(self.STATION, self.NETWORK,
            self.CHANNEL, self.LOCATION)

        try:
            site.station
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(site.station, self.STATION)

        try:
            site.channel
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(site.channel, self.CHANNEL)

        try:
            site.network
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(site.network, self.NETWORK)

        try:
            site.location
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(site.location, self.LOCATION)

    def test_toJSON(self):
        site = detectionformats.site.Site(self.STATION, self.NETWORK,
            self.CHANNEL, self.LOCATION)
        self.assertEqual(site.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        site = detectionformats.site.Site()
        site.fromJSONString(self.JSONSTRING)

        self.assertEqual(site.station, self.STATION)
        self.assertEqual(site.channel, self.CHANNEL)
        self.assertEqual(site.network, self.NETWORK)
        self.assertEqual(site.location, self.LOCATION)

    def test_toDict(self):
        site = detectionformats.site.Site(self.STATION, self.NETWORK,
            self.CHANNEL, self.LOCATION)
        self.assertEqual(site.toDict(), self.DICT)

    def test_fromDict(self):
        site = detectionformats.site.Site()
        site.fromDict(self.DICT)

        self.assertEqual(site.station, self.STATION)
        self.assertEqual(site.channel, self.CHANNEL)
        self.assertEqual(site.network, self.NETWORK)
        self.assertEqual(site.location, self.LOCATION)

    def test_isValid(self):
        site = detectionformats.site.Site(self.STATION, self.NETWORK,
            self.CHANNEL, self.LOCATION)
        self.assertTrue(site.isValid())

        badSite = detectionformats.site.Site()
        self.assertFalse(badSite.isValid())

if __name__ == '__main__':
    unittest.main()
