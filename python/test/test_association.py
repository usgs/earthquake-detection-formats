#!/usr/bin/env python

#package imports
import detectionformats.association

#stdlib imports
import unittest

class TestAssociation(unittest.TestCase):
    PHASE = 'P'
    DISTANCE = 22.5
    AZIMUTH = 32.0
    RESIDUAL = 1.32
    SIGMA = 5.23
    JSONSTRING = '{"Phase": "P", "Distance": 22.5, "Azimuth": 32.0, "Residual": 1.32, "Sigma": 5.23}'
    DICT = {"Phase": "P", "Distance": 22.5, "Azimuth": 32.0, "Residual": 1.32, "Sigma": 5.23}

    def test_init(self):
        # Empty init
        association = detectionformats.association.Association()

        try:
            association.phase
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            association.distance
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            association.azimuth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            association.residual
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            association.sigma
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        association = detectionformats.association.Association(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)

        try:
            association.phase
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(association.phase, self.PHASE)

        try:
            association.distance
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(association.distance, self.DISTANCE)

        try:
            association.azimuth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(association.azimuth, self.AZIMUTH)

        try:
            association.residual
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(association.residual, self.RESIDUAL)

        try:
            association.sigma
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(association.sigma, self.SIGMA)

    def test_toJSON(self):
        association = detectionformats.association.Association(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)
        self.assertEqual(association.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        association = detectionformats.association.Association()
        association.fromJSONString(self.JSONSTRING)

        self.assertEqual(association.phase, self.PHASE)
        self.assertEqual(association.distance, self.DISTANCE)
        self.assertEqual(association.azimuth, self.AZIMUTH)
        self.assertEqual(association.residual, self.RESIDUAL)
        self.assertEqual(association.sigma, self.SIGMA)

    def test_toDict(self):
        association = detectionformats.association.Association(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)
        self.assertEqual(association.toDict(), self.DICT)

    def test_fromDict(self):
        association = detectionformats.association.Association()
        association.fromDict(self.DICT)

        self.assertEqual(association.phase, self.PHASE)
        self.assertEqual(association.distance, self.DISTANCE)
        self.assertEqual(association.azimuth, self.AZIMUTH)
        self.assertEqual(association.residual, self.RESIDUAL)
        self.assertEqual(association.sigma, self.SIGMA)

    def test_isValid(self):
        association = detectionformats.association.Association(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)
        self.assertTrue(association.isValid())

        badAssociation = detectionformats.association.Association(self.PHASE,
            -1, -1, self.RESIDUAL, self.SIGMA)
        self.assertFalse(badAssociation.isValid())

    def test_isEmpty(self):
        association = detectionformats.association.Association()
        self.assertTrue(association.isEmpty())

        association = detectionformats.association.Association(self.PHASE,
            self.DISTANCE, self.AZIMUTH, self.RESIDUAL, self.SIGMA)
        self.assertFalse(association.isEmpty())

if __name__ == '__main__':
    unittest.main()
