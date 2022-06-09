#!/usr/bin/env python

# package imports
import detectionformats.site

# stdlib imports
import unittest


class TestSite(unittest.TestCase):
    STATION = "BOZ"
    CHANNEL = "BHZ"
    NETWORK = "US"
    LOCATION = "00"
    LATITUDE = 45.6
    LONGITUDE = 111.5
    ELEVATION = 12.5
    JSONSTRING = '{"Station": "BOZ", "Network": "US", "Channel": "BHZ", "Location": "00", "Latitude": 45.6, "Longitude": 111.5, "Elevation": 12.5}'
    DICT = {
        "Channel": "BHZ",
        "Location": "00",
        "Network": "US",
        "Station": "BOZ",
        "Latitude": 45.6,
        "Longitude": 111.5,
        "Elevation": 12.5,
    }

    def test_init(self):
        # Empty init
        site = detectionformats.site.Site()

        self.assertFalse(hasattr(site, "station"))
        self.assertFalse(hasattr(site, "channel"))
        self.assertFalse(hasattr(site, "network"))
        self.assertFalse(hasattr(site, "location"))
        self.assertFalse(hasattr(site, "latitude"))
        self.assertFalse(hasattr(site, "longitude"))
        self.assertFalse(hasattr(site, "elevation"))

        site = detectionformats.site.Site(
            self.STATION,
            self.NETWORK,
            self.CHANNEL,
            self.LOCATION,
            self.LATITUDE,
            self.LONGITUDE,
            self.ELEVATION,
        )

        self.assertTrue(hasattr(site, "station"))
        self.assertTrue(hasattr(site, "channel"))
        self.assertTrue(hasattr(site, "network"))
        self.assertTrue(hasattr(site, "location"))
        self.assertTrue(hasattr(site, "latitude"))
        self.assertTrue(hasattr(site, "longitude"))
        self.assertTrue(hasattr(site, "elevation"))

        self.assertEqual(site.station, self.STATION)
        self.assertEqual(site.channel, self.CHANNEL)
        self.assertEqual(site.network, self.NETWORK)
        self.assertEqual(site.location, self.LOCATION)
        self.assertEqual(site.latitude, self.LATITUDE)
        self.assertEqual(site.longitude, self.LONGITUDE)
        self.assertEqual(site.elevation, self.ELEVATION)

    def test_toJSON(self):
        site = detectionformats.site.Site(
            self.STATION,
            self.NETWORK,
            self.CHANNEL,
            self.LOCATION,
            self.LATITUDE,
            self.LONGITUDE,
            self.ELEVATION,
        )
        self.assertEqual(site.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        site = detectionformats.site.Site()
        site.fromJSONString(self.JSONSTRING)

        self.assertEqual(site.station, self.STATION)
        self.assertEqual(site.channel, self.CHANNEL)
        self.assertEqual(site.network, self.NETWORK)
        self.assertEqual(site.location, self.LOCATION)
        self.assertEqual(site.latitude, self.LATITUDE)
        self.assertEqual(site.longitude, self.LONGITUDE)
        self.assertEqual(site.elevation, self.ELEVATION)

    def test_toDict(self):
        site = detectionformats.site.Site(
            self.STATION,
            self.NETWORK,
            self.CHANNEL,
            self.LOCATION,
            self.LATITUDE,
            self.LONGITUDE,
            self.ELEVATION,
        )
        self.assertEqual(site.toDict(), self.DICT)

    def test_fromDict(self):
        site = detectionformats.site.Site()
        site.fromDict(self.DICT)

        self.assertEqual(site.station, self.STATION)
        self.assertEqual(site.channel, self.CHANNEL)
        self.assertEqual(site.network, self.NETWORK)
        self.assertEqual(site.location, self.LOCATION)
        self.assertEqual(site.latitude, self.LATITUDE)
        self.assertEqual(site.longitude, self.LONGITUDE)
        self.assertEqual(site.elevation, self.ELEVATION)

    def test_isValid(self):
        site = detectionformats.site.Site(
            self.STATION, self.NETWORK, self.CHANNEL, self.LOCATION
        )
        self.assertTrue(site.isValid())

        badSite = detectionformats.site.Site()
        self.assertFalse(badSite.isValid())


if __name__ == "__main__":
    unittest.main()
