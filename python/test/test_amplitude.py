#!/usr/bin/env python

#package imports
import detectionformats.amplitude

#stdlib imports
import unittest

class TestAmplitude(unittest.TestCase):
    AMPLITUDE = 12.569
    PERIOD = 2.5
    SNR = 16
    JSONSTRING = '{"Amplitude": 12.569, "Period": 2.5, "SNR": 16}'
    DICT = {"Amplitude": 12.569, "Period": 2.5, "SNR": 16}

    def test_init(self):
        # Empty init
        amplitude = detectionformats.amplitude.Amplitude()

        try:
            amplitude.amplitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            amplitude.period
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            amplitude.snr
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        amplitude = detectionformats.amplitude.Amplitude(self.AMPLITUDE,
            self.PERIOD, self.SNR)

        try:
            amplitude.amplitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(amplitude.amplitude, self.AMPLITUDE)

        try:
            amplitude.period
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(amplitude.period, self.PERIOD)

        try:
            amplitude.snr
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(amplitude.snr, self.SNR)

    def test_toJSON(self):
        amplitude = detectionformats.amplitude.Amplitude(self.AMPLITUDE,
            self.PERIOD, self.SNR)
        self.assertEqual(amplitude.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        amplitude = detectionformats.amplitude.Amplitude()
        amplitude.fromJSONString(self.JSONSTRING)

        self.assertEqual(amplitude.amplitude, self.AMPLITUDE)
        self.assertEqual(amplitude.period, self.PERIOD)
        self.assertEqual(amplitude.snr, self.SNR)

    def test_toDict(self):
        amplitude = detectionformats.amplitude.Amplitude(self.AMPLITUDE,
            self.PERIOD, self.SNR)
        self.assertEqual(amplitude.toDict(), self.DICT)

    def test_fromDict(self):
        amplitude = detectionformats.amplitude.Amplitude()
        amplitude.fromDict(self.DICT)

        self.assertEqual(amplitude.amplitude, self.AMPLITUDE)
        self.assertEqual(amplitude.period, self.PERIOD)
        self.assertEqual(amplitude.snr, self.SNR)

    def test_isValid(self):
        amplitude = detectionformats.amplitude.Amplitude(self.AMPLITUDE,
            self.PERIOD, self.SNR)
        self.assertTrue(amplitude.isValid())

    def test_isEmpty(self):
        amplitude = detectionformats.amplitude.Amplitude()
        self.assertTrue(amplitude.isEmpty())

        amplitude = detectionformats.amplitude.Amplitude(self.AMPLITUDE,
            self.PERIOD, self.SNR)
        self.assertFalse(amplitude.isEmpty())

if __name__ == '__main__':
    unittest.main()
