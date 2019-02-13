#!/usr/bin/env python

#package imports
import detectionformats.filter

#stdlib imports
import unittest

class TestFilter(unittest.TestCase):
    TYPE = 'BandPass'
    HIGHPASS = 3.2
    LOWPASS = 1.5
    UNITS = 'Hertz'
    JSONSTRING = '{"Type": "BandPass", "HighPass": 3.2, "LowPass": 1.5, "Units": "Hertz"}'
    DICT = {"Type": "BandPass", "HighPass": 3.2, "LowPass": 1.5, "Units": "Hertz"}

    def test_init(self):
        # Empty init
        filter = detectionformats.filter.Filter()

        self.assertFalse(hasattr(filter, 'type'))
        self.assertFalse(hasattr(filter, 'highPass'))
        self.assertFalse(hasattr(filter, 'lowPass'))
        self.assertFalse(hasattr(filter, 'units'))

        filter = detectionformats.filter.Filter(self.TYPE, self.HIGHPASS,
            self.LOWPASS, self.UNITS)

        self.assertTrue(hasattr(filter, 'type'))
        self.assertTrue(hasattr(filter, 'highPass'))
        self.assertTrue(hasattr(filter, 'lowPass'))
        self.assertTrue(hasattr(filter, 'units'))

        self.assertEqual(filter.type, self.TYPE)
        self.assertEqual(filter.highPass, self.HIGHPASS)
        self.assertEqual(filter.lowPass, self.LOWPASS)
        self.assertEqual(filter.units, self.UNITS)

    def test_toJSON(self):
        filter = detectionformats.filter.Filter(self.TYPE, self.HIGHPASS,
            self.LOWPASS, self.UNITS)
        self.assertEqual(filter.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        filter = detectionformats.filter.Filter()
        filter.fromJSONString(self.JSONSTRING)

        self.assertEqual(filter.type, self.TYPE)
        self.assertEqual(filter.highPass, self.HIGHPASS)
        self.assertEqual(filter.lowPass, self.LOWPASS)
        self.assertEqual(filter.units, self.UNITS)

    def test_toDict(self):
        filter = detectionformats.filter.Filter(self.TYPE, self.HIGHPASS,
            self.LOWPASS, self.UNITS)
        self.assertEqual(filter.toDict(), self.DICT)

    def test_fromDict(self):
        filter = detectionformats.filter.Filter()
        filter.fromDict(self.DICT)

        self.assertEqual(filter.type, self.TYPE)
        self.assertEqual(filter.highPass, self.HIGHPASS)
        self.assertEqual(filter.lowPass, self.LOWPASS)
        self.assertEqual(filter.units, self.UNITS)

    def test_isValid(self):
        filter = detectionformats.filter.Filter(self.TYPE, self.HIGHPASS,
            self.LOWPASS, self.UNITS)
        self.assertTrue(filter.isValid())

    def test_isEmpty(self):
        filter = detectionformats.filter.Filter()
        self.assertTrue(filter.isEmpty())

        filter = detectionformats.filter.Filter(self.TYPE, self.HIGHPASS,
            self.LOWPASS, self.UNITS)
        self.assertFalse(filter.isEmpty())

if __name__ == '__main__':
    unittest.main()
