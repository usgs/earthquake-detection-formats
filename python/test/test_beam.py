#!/usr/bin/env python

# package imports
import detectionformats.beam

# stdlib imports
import unittest


class TestBeam(unittest.TestCase):
    BACKAZIMUTH = 12.569
    SLOWNESS = 2.5
    POWERRATIO = 16.1
    BACKAZIMUTHERROR = 2.59
    SLOWNESSERROR = 5.56
    POWERRATIOERROR = 0.12
    JSONSTRING = '{"BackAzimuth": 12.569, "Slowness": 2.5, "PowerRatio": 16.1, "BackAzimuthError": 2.59, "SlownessError": 5.56, "PowerRatioError": 0.12}'
    DICT = {
        "BackAzimuth": 12.569,
        "Slowness": 2.5,
        "PowerRatio": 16.1,
        "BackAzimuthError": 2.59,
        "SlownessError": 5.56,
        "PowerRatioError": 0.12,
    }

    def test_init(self):
        # Empty init
        beam = detectionformats.beam.Beam()

        self.assertFalse(hasattr(beam, "backAzimuth"))
        self.assertFalse(hasattr(beam, "slowness"))
        self.assertFalse(hasattr(beam, "powerRatio"))
        self.assertFalse(hasattr(beam, "backAzimuthError"))
        self.assertFalse(hasattr(beam, "slownessError"))
        self.assertFalse(hasattr(beam, "powerRatioError"))

        beam = detectionformats.beam.Beam(
            self.BACKAZIMUTH,
            self.SLOWNESS,
            self.POWERRATIO,
            self.BACKAZIMUTHERROR,
            self.SLOWNESSERROR,
            self.POWERRATIOERROR,
        )

        self.assertTrue(hasattr(beam, "backAzimuth"))
        self.assertTrue(hasattr(beam, "slowness"))
        self.assertTrue(hasattr(beam, "powerRatio"))
        self.assertTrue(hasattr(beam, "backAzimuthError"))
        self.assertTrue(hasattr(beam, "slownessError"))
        self.assertTrue(hasattr(beam, "powerRatioError"))

        self.assertEqual(beam.backAzimuth, self.BACKAZIMUTH)
        self.assertEqual(beam.slowness, self.SLOWNESS)
        self.assertEqual(beam.powerRatio, self.POWERRATIO)
        self.assertEqual(beam.backAzimuthError, self.BACKAZIMUTHERROR)
        self.assertEqual(beam.slownessError, self.SLOWNESSERROR)
        self.assertEqual(beam.powerRatioError, self.POWERRATIOERROR)

    def test_toJSON(self):
        beam = detectionformats.beam.Beam(
            self.BACKAZIMUTH,
            self.SLOWNESS,
            self.POWERRATIO,
            self.BACKAZIMUTHERROR,
            self.SLOWNESSERROR,
            self.POWERRATIOERROR,
        )
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
        beam = detectionformats.beam.Beam(
            self.BACKAZIMUTH,
            self.SLOWNESS,
            self.POWERRATIO,
            self.BACKAZIMUTHERROR,
            self.SLOWNESSERROR,
            self.POWERRATIOERROR,
        )
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
        beam = detectionformats.beam.Beam(
            self.BACKAZIMUTH,
            self.SLOWNESS,
            self.POWERRATIO,
            self.BACKAZIMUTHERROR,
            self.SLOWNESSERROR,
            self.POWERRATIOERROR,
        )
        self.assertTrue(beam.isValid())

        badBeam = detectionformats.beam.Beam()
        self.assertFalse(badBeam.isValid())


if __name__ == "__main__":
    unittest.main()
