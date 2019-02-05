#!/usr/bin/env python

#package imports
import detectionformats.hypocenter

#stdlib imports
import unittest
import datetime

class TestHypocenter(unittest.TestCase):
    LATITUDE = 45.6
    LONGITUDE = 111.5
    DEPTH = 12.5
    TIME = datetime.datetime(2018, 2, 6, 12, 30, 59, 0)
    LATITUDEERROR = 1.6
    LONGITUDEERROR = 1.5
    DEPTHERROR = 32.5
    TIMEERROR = 11.2
    JSONSTRING = '{"Latitude": 45.6, "Longitude": 111.5, "Depth": 12.5, "Time": "2018-02-06T12:30:59.000Z", "LatitudeError": 1.6, "LongitudeError": 1.5, "DepthError": 32.5, "TimeError": 11.2}'
    DICT = {"Latitude": 45.6, "Longitude": 111.5, "Depth": 12.5, "Time": "2018-02-06T12:30:59.000Z", "LatitudeError": 1.6, "LongitudeError": 1.5, "DepthError": 32.5, "TimeError": 11.2}

    def test_init(self):
        # Empty init
        hypocenter = detectionformats.hypocenter.Hypocenter()

        self.assertFalse(hasattr(hypocenter, 'latitude'))
        self.assertFalse(hasattr(hypocenter, 'longitude'))
        self.assertFalse(hasattr(hypocenter, 'depth'))
        self.assertFalse(hasattr(hypocenter, 'time'))
        self.assertFalse(hasattr(hypocenter, 'latitudeError'))
        self.assertFalse(hasattr(hypocenter, 'longitudeError'))
        self.assertFalse(hasattr(hypocenter, 'depthError'))
        self.assertFalse(hasattr(hypocenter, 'timeError'))

        hypocenter = detectionformats.hypocenter.Hypocenter(self.LATITUDE,
            self.LONGITUDE, self.DEPTH, self.TIME, self.LATITUDEERROR,
            self.LONGITUDEERROR, self.DEPTHERROR, self.TIMEERROR)

        self.assertTrue(hasattr(hypocenter, 'latitude'))
        self.assertTrue(hasattr(hypocenter, 'longitude'))
        self.assertTrue(hasattr(hypocenter, 'depth'))
        self.assertTrue(hasattr(hypocenter, 'time'))
        self.assertTrue(hasattr(hypocenter, 'latitudeError'))
        self.assertTrue(hasattr(hypocenter, 'longitudeError'))
        self.assertTrue(hasattr(hypocenter, 'depthError'))
        self.assertTrue(hasattr(hypocenter, 'timeError'))

        self.assertEqual(hypocenter.latitude, self.LATITUDE)
        self.assertEqual(hypocenter.longitude, self.LONGITUDE)
        self.assertEqual(hypocenter.depth, self.DEPTH)
        self.assertEqual(hypocenter.time, self.TIME)
        self.assertEqual(hypocenter.latitudeError, self.LATITUDEERROR)
        self.assertEqual(hypocenter.longitudeError, self.LONGITUDEERROR)
        self.assertEqual(hypocenter.depthError, self.DEPTHERROR)
        self.assertEqual(hypocenter.timeError, self.TIMEERROR)

    def test_toJSON(self):
        hypocenter = detectionformats.hypocenter.Hypocenter(self.LATITUDE,
            self.LONGITUDE, self.DEPTH, self.TIME, self.LATITUDEERROR,
            self.LONGITUDEERROR, self.DEPTHERROR, self.TIMEERROR)
        self.assertEqual(hypocenter.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        hypocenter = detectionformats.hypocenter.Hypocenter()
        hypocenter.fromJSONString(self.JSONSTRING)

        self.assertEqual(hypocenter.latitude, self.LATITUDE)
        self.assertEqual(hypocenter.longitude, self.LONGITUDE)
        self.assertEqual(hypocenter.depth, self.DEPTH)
        self.assertEqual(hypocenter.time, self.TIME)
        self.assertEqual(hypocenter.latitudeError, self.LATITUDEERROR)
        self.assertEqual(hypocenter.longitudeError, self.LONGITUDEERROR)
        self.assertEqual(hypocenter.depthError, self.DEPTHERROR)
        self.assertEqual(hypocenter.timeError, self.TIMEERROR)

    def test_toDict(self):
        hypocenter = detectionformats.hypocenter.Hypocenter(self.LATITUDE,
            self.LONGITUDE, self.DEPTH, self.TIME, self.LATITUDEERROR,
            self.LONGITUDEERROR, self.DEPTHERROR, self.TIMEERROR)
        self.assertEqual(hypocenter.toDict(), self.DICT)

    def test_fromDict(self):
        hypocenter = detectionformats.hypocenter.Hypocenter()
        hypocenter.fromDict(self.DICT)

        self.assertEqual(hypocenter.latitude, self.LATITUDE)
        self.assertEqual(hypocenter.longitude, self.LONGITUDE)
        self.assertEqual(hypocenter.depth, self.DEPTH)
        self.assertEqual(hypocenter.time, self.TIME)
        self.assertEqual(hypocenter.latitudeError, self.LATITUDEERROR)
        self.assertEqual(hypocenter.longitudeError, self.LONGITUDEERROR)
        self.assertEqual(hypocenter.depthError, self.DEPTHERROR)
        self.assertEqual(hypocenter.timeError, self.TIMEERROR)

    def test_isValid(self):
        hypocenter = detectionformats.hypocenter.Hypocenter(self.LATITUDE,
            self.LONGITUDE, self.DEPTH, self.TIME, self.LATITUDEERROR,
            self.LONGITUDEERROR, self.DEPTHERROR, self.TIMEERROR)
        self.assertTrue(hypocenter.isValid())

        badHypocenter = detectionformats.hypocenter.Hypocenter()
        self.assertFalse(badHypocenter.isValid())

if __name__ == '__main__':
    unittest.main()
