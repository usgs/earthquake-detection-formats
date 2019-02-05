#!/usr/bin/env python

#package imports
import detectionformats.stationinfo
import detectionformats.site
import detectionformats.source

#stdlib imports
import unittest

class TestStationInfo(unittest.TestCase):
    SITE = detectionformats.site.Site('BOZ', 'BHZ', 'US', '00')
    LATITUDE = 45.6
    LONGITUDE = 111.5
    ELEVATION = 12.5
    QUALITY =1.2
    ENABLE = True
    USEFORTELESEISMIC = True
    INFORMATIONREQUESTOR = detectionformats.source.Source('testAgency', 'testAuthor')
    JSONSTRING = '{"Type": "StationInfo", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Latitude": 45.6, "Longitude": 111.5, "Elevation": 12.5, "Quality": 1.2, "Enable": true, "UseForTeleseismic": true, "InformationRequestor": {"AgencyID": "testAgency", "Author": "testAuthor"}}'
    DICT = {"Type": "StationInfo", "Site": {"Station": "BOZ", "Network": "BHZ", "Channel": "US", "Location": "00"}, "Latitude": 45.6, "Longitude": 111.5, "Elevation": 12.5, "Quality": 1.2, "Enable": True, "UseForTeleseismic": True, "InformationRequestor": {"AgencyID": "testAgency", "Author": "testAuthor"}}

    def test_init(self):
        # Empty init
        stationinfo = detectionformats.stationinfo.StationInfo()

        self.assertFalse(hasattr(stationinfo.site, 'station'))
        self.assertFalse(hasattr(stationinfo.site, 'channel'))
        self.assertFalse(hasattr(stationinfo.site, 'network'))
        self.assertFalse(hasattr(stationinfo.site, 'location'))
        self.assertFalse(hasattr(stationinfo, 'latitude'))
        self.assertFalse(hasattr(stationinfo, 'longitude'))
        self.assertFalse(hasattr(stationinfo, 'elevation'))
        self.assertFalse(hasattr(stationinfo, 'quality'))
        self.assertFalse(hasattr(stationinfo, 'enable'))
        self.assertFalse(hasattr(stationinfo, 'useForTeleseismic'))
        self.assertFalse(hasattr(stationinfo.informationRequestor, 'agencyID'))
        self.assertFalse(hasattr(stationinfo.informationRequestor, 'author'))

        stationinfo = detectionformats.stationinfo.StationInfo(self.SITE,
            self.LATITUDE, self.LONGITUDE, self.ELEVATION, self.QUALITY,
            self.ENABLE, self.USEFORTELESEISMIC, self.INFORMATIONREQUESTOR)

        self.assertTrue(hasattr(stationinfo.site, 'station'))
        self.assertTrue(hasattr(stationinfo.site, 'channel'))
        self.assertTrue(hasattr(stationinfo.site, 'network'))
        self.assertTrue(hasattr(stationinfo.site, 'location'))
        self.assertTrue(hasattr(stationinfo, 'latitude'))
        self.assertTrue(hasattr(stationinfo, 'longitude'))
        self.assertTrue(hasattr(stationinfo, 'elevation'))
        self.assertTrue(hasattr(stationinfo, 'quality'))
        self.assertTrue(hasattr(stationinfo, 'enable'))
        self.assertTrue(hasattr(stationinfo, 'useForTeleseismic'))
        self.assertTrue(hasattr(stationinfo.informationRequestor, 'agencyID'))
        self.assertTrue(hasattr(stationinfo.informationRequestor, 'author'))

        self.assertEqual(stationinfo.site.station, self.SITE.station)
        self.assertEqual(stationinfo.site.channel, self.SITE.channel)
        self.assertEqual(stationinfo.site.network, self.SITE.network)
        self.assertEqual(stationinfo.site.location, self.SITE.location)
        self.assertEqual(stationinfo.latitude, self.LATITUDE)
        self.assertEqual(stationinfo.longitude, self.LONGITUDE)
        self.assertEqual(stationinfo.elevation, self.ELEVATION)
        self.assertEqual(stationinfo.quality, self.QUALITY)
        self.assertEqual(stationinfo.enable, self.ENABLE)
        self.assertEqual(stationinfo.useForTeleseismic, self.USEFORTELESEISMIC)
        self.assertEqual(stationinfo.informationRequestor.agencyID, self.INFORMATIONREQUESTOR.agencyID)
        self.assertEqual(stationinfo.informationRequestor.author, self.INFORMATIONREQUESTOR.author)

    def test_toJSON(self):
        stationinfo = detectionformats.stationinfo.StationInfo(self.SITE,
            self.LATITUDE, self.LONGITUDE, self.ELEVATION, self.QUALITY,
            self.ENABLE, self.USEFORTELESEISMIC, self.INFORMATIONREQUESTOR)
        self.assertEqual(stationinfo.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        stationinfo = detectionformats.stationinfo.StationInfo()
        stationinfo.fromJSONString(self.JSONSTRING)

        self.assertEqual(stationinfo.site.station, self.SITE.station)
        self.assertEqual(stationinfo.site.channel, self.SITE.channel)
        self.assertEqual(stationinfo.site.network, self.SITE.network)
        self.assertEqual(stationinfo.site.location, self.SITE.location)
        self.assertEqual(stationinfo.latitude, self.LATITUDE)
        self.assertEqual(stationinfo.longitude, self.LONGITUDE)
        self.assertEqual(stationinfo.elevation, self.ELEVATION)
        self.assertEqual(stationinfo.quality, self.QUALITY)
        self.assertEqual(stationinfo.enable, self.ENABLE)
        self.assertEqual(stationinfo.useForTeleseismic, self.USEFORTELESEISMIC)
        self.assertEqual(stationinfo.informationRequestor.agencyID, self.INFORMATIONREQUESTOR.agencyID)
        self.assertEqual(stationinfo.informationRequestor.author, self.INFORMATIONREQUESTOR.author)

    def test_toDict(self):
        stationinfo = detectionformats.stationinfo.StationInfo(self.SITE,
            self.LATITUDE, self.LONGITUDE, self.ELEVATION, self.QUALITY,
            self.ENABLE, self.USEFORTELESEISMIC, self.INFORMATIONREQUESTOR)
        self.assertEqual(stationinfo.toDict(), self.DICT)

    def test_fromDict(self):
        stationinfo = detectionformats.stationinfo.StationInfo()
        stationinfo.fromDict(self.DICT)

        self.assertEqual(stationinfo.site.station, self.SITE.station)
        self.assertEqual(stationinfo.site.channel, self.SITE.channel)
        self.assertEqual(stationinfo.site.network, self.SITE.network)
        self.assertEqual(stationinfo.site.location, self.SITE.location)
        self.assertEqual(stationinfo.latitude, self.LATITUDE)
        self.assertEqual(stationinfo.longitude, self.LONGITUDE)
        self.assertEqual(stationinfo.elevation, self.ELEVATION)
        self.assertEqual(stationinfo.quality, self.QUALITY)
        self.assertEqual(stationinfo.enable, self.ENABLE)
        self.assertEqual(stationinfo.useForTeleseismic, self.USEFORTELESEISMIC)
        self.assertEqual(stationinfo.informationRequestor.agencyID, self.INFORMATIONREQUESTOR.agencyID)
        self.assertEqual(stationinfo.informationRequestor.author, self.INFORMATIONREQUESTOR.author)

    def test_isValid(self):
        stationinfo = detectionformats.stationinfo.StationInfo(self.SITE,
            self.LATITUDE, self.LONGITUDE, self.ELEVATION, self.QUALITY,
            self.ENABLE, self.USEFORTELESEISMIC, self.INFORMATIONREQUESTOR)
        self.assertTrue(stationinfo.isValid())

        badStationInfo = detectionformats.stationinfo.StationInfo()
        self.assertFalse(badStationInfo.isValid())

if __name__ == '__main__':
    unittest.main()
