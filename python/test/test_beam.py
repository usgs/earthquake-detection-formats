#!/usr/bin/env python

#package imports
import detectionformats.beam

#stdlib imports
import unittest

class TestBeam(unittest.TestCase):
    BACKAZIMUTH = 12.569
    SLOWNESS = 2.5
    POWERRATIO = 16.1
    BACKAZIMUTHERROR = 2.59
    SLOWNESSERROR = 5.56
    POWERRATIOERROR = 0.12
    JSONSTRING = '{"BackAzimuth": 12.569, "Slowness": 2.5, "PowerRatio": 16.1, "BackAzimuthError": 2.59, "SlownessError": 5.56, "PowerRatioError": 0.12}'
    DICT = {"BackAzimuth": 12.569, "Slowness": 2.5, "PowerRatio": 16.1, "BackAzimuthError": 2.59, "SlownessError": 5.56, "PowerRatioError": 0.12}

    def test_init(self):
        # Empty init
        beam = detectionformats.beam.Beam()

        try:
            beam.backAzimuth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            beam.slowness
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            beam.powerRatio
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            beam.backAzimuthError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            beam.slownessError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            beam.powerRatioError
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        beam = detectionformats.beam.Beam(self.BACKAZIMUTH, self.SLOWNESS,
            self.POWERRATIO, self.BACKAZIMUTHERROR, self.SLOWNESSERROR,
            self.POWERRATIOERROR)

        try:
            beam.backAzimuth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(beam.backAzimuth, self.BACKAZIMUTH)

        try:
            beam.slowness
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(beam.slowness, self.SLOWNESS)

        try:
            beam.powerRatio
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(beam.powerRatio, self.POWERRATIO)

        try:
            beam.backAzimuthError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(beam.backAzimuthError, self.BACKAZIMUTHERROR)

        try:
            beam.slownessError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(beam.slownessError, self.SLOWNESSERROR)

        try:
            beam.powerRatioError
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(beam.powerRatioError, self.POWERRATIOERROR)

    def test_toJSON(self):
        beam = detectionformats.beam.Beam(self.BACKAZIMUTH, self.SLOWNESS,
            self.POWERRATIO, self.BACKAZIMUTHERROR, self.SLOWNESSERROR,
            self.POWERRATIOERROR)
        self.assertEqual(beam.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        beam = detectionformats.beam.Beam()
        beam.fromJSONString(self.JSONSTRING)

        self.assertEqual(beam.backAzimuth, self.BACKAZIMUTH)
        self.assertEqual(beam.slowness, self.SLOWNESS)
        self.assertEqual(beam.powerRatio, self.POWERRATIO)
        self.assertEqual(beam.backAzimuthError, self.BACKAZIMUTHERROR)
        self.assertEqual(beam.slownessError, self.SLOWNESSERROR)
        self.assertEqual(beam.powerRatioError, self.POWERRATIOERROR)

    def test_toDict(self):
        beam = detectionformats.beam.Beam(self.BACKAZIMUTH, self.SLOWNESS,
            self.POWERRATIO, self.BACKAZIMUTHERROR, self.SLOWNESSERROR,
            self.POWERRATIOERROR)
        self.assertEqual(beam.toDict(), self.DICT)

    def test_fromDict(self):
        beam = detectionformats.beam.Beam()
        beam.fromDict(self.DICT)

        self.assertEqual(beam.backAzimuth, self.BACKAZIMUTH)
        self.assertEqual(beam.slowness, self.SLOWNESS)
        self.assertEqual(beam.powerRatio, self.POWERRATIO)
        self.assertEqual(beam.backAzimuthError, self.BACKAZIMUTHERROR)
        self.assertEqual(beam.slownessError, self.SLOWNESSERROR)
        self.assertEqual(beam.powerRatioError, self.POWERRATIOERROR)

    def test_isValid(self):
        beam = detectionformats.beam.Beam(self.BACKAZIMUTH, self.SLOWNESS,
            self.POWERRATIO, self.BACKAZIMUTHERROR, self.SLOWNESSERROR,
            self.POWERRATIOERROR)
        self.assertTrue(beam.isValid())

        badBeam = detectionformats.beam.Beam()
        self.assertFalse(badBeam.isValid())

if __name__ == '__main__':
    unittest.main()
