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

        try:
            stationinfo.site.station
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.site.channel
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.site.network
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.site.location
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.latitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.longitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.elevation
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.quality
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.enable
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.useForTeleseismic
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.informationRequestor.agencyID
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            stationinfo.informationRequestor.author
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        stationinfo = detectionformats.stationinfo.StationInfo(self.SITE,
            self.LATITUDE, self.LONGITUDE, self.ELEVATION, self.QUALITY,
            self.ENABLE, self.USEFORTELESEISMIC, self.INFORMATIONREQUESTOR)

        try:
            stationinfo.site.station
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.site.station, self.SITE.station)

        try:
            stationinfo.site.channel
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.site.channel, self.SITE.channel)

        try:
            stationinfo.site.network
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.site.network, self.SITE.network)

        try:
            stationinfo.site.location
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.site.location, self.SITE.location)

        try:
            stationinfo.latitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.latitude, self.LATITUDE)

        try:
            stationinfo.longitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.longitude, self.LONGITUDE)

        try:
            stationinfo.elevation
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.elevation, self.ELEVATION)


        try:
            stationinfo.quality
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.quality, self.QUALITY)

        try:
            stationinfo.enable
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.enable, self.ENABLE)

        try:
            stationinfo.useForTeleseismic
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.useForTeleseismic, self.USEFORTELESEISMIC)

        try:
            stationinfo.informationRequestor.agencyID
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(stationinfo.informationRequestor.agencyID, self.INFORMATIONREQUESTOR.agencyID)

        try:
            stationinfo.informationRequestor.author
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

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
