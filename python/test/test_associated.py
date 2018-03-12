#!/usr/bin/env python

#package imports
import detectionformats.associated

#stdlib imports
import unittest

class TestAssociated(unittest.TestCase):
    PHASE = 'P'
    DISTANCE = 22.5
    AZIMUTH = 32.0
    RESIDUAL = 1.32
    SIGMA = 5.23
    JSONSTRING = '{"Phase": "P", "Distance": 22.5, "Azimuth": 32.0, "Residual": 1.32, "Sigma": 5.23}'
    DICT = {"Phase": "P", "Distance": 22.5, "Azimuth": 32.0, "Residual": 1.32, "Sigma": 5.23}

    def test_init(self):
        # Empty init
        associated = detectionformats.associated.Associated()

        try:
            associated.phase
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            associated.distance
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            associated.azimuth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            associated.residual
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            associated.sigma
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        associated = detectionformats.associated.Associated(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)

        try:
            associated.phase
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(associated.phase, self.PHASE)

        try:
            associated.distance
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(associated.distance, self.DISTANCE)

        try:
            associated.azimuth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(associated.azimuth, self.AZIMUTH)

        try:
            associated.residual
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(associated.residual, self.RESIDUAL)

        try:
            associated.sigma
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(associated.sigma, self.SIGMA)

    def test_toJSON(self):
        associated = detectionformats.associated.Associated(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)
        self.assertEqual(associated.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        associated = detectionformats.associated.Associated()
        associated.fromJSONString(self.JSONSTRING)

        self.assertEqual(associated.phase, self.PHASE)
        self.assertEqual(associated.distance, self.DISTANCE)
        self.assertEqual(associated.azimuth, self.AZIMUTH)
        self.assertEqual(associated.residual, self.RESIDUAL)
        self.assertEqual(associated.sigma, self.SIGMA)

    def test_toDict(self):
        associated = detectionformats.associated.Associated(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)
        self.assertEqual(associated.toDict(), self.DICT)

    def test_fromDict(self):
        associated = detectionformats.associated.Associated()
        associated.fromDict(self.DICT)

        self.assertEqual(associated.phase, self.PHASE)
        self.assertEqual(associated.distance, self.DISTANCE)
        self.assertEqual(associated.azimuth, self.AZIMUTH)
        self.assertEqual(associated.residual, self.RESIDUAL)
        self.assertEqual(associated.sigma, self.SIGMA)

    def test_isValid(self):
        associated = detectionformats.associated.Associated(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)
        self.assertTrue(associated.isValid())

        badAssociated = detectionformats.associated.Associated(self.PHASE,
            -1, -1, self.RESIDUAL, self.SIGMA)
        self.assertFalse(badAssociated.isValid())

    def test_isEmpty(self):
        associated = detectionformats.associated.Associated()
        self.assertTrue(associated.isEmpty())

        associated = detectionformats.associated.Associated(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)
        self.assertFalse(associated.isEmpty())

if __name__ == '__main__':
    unittest.main()
