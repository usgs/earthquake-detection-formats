#!/usr/bin/env python

#package imports
import detectionformats.retract
import detectionformats.source

#stdlib imports
import unittest

class TestRetract(unittest.TestCase):
    ID = '123456789'
    SOURCE = detectionformats.source.Source('testAgency', 'testAuthor')
    JSONSTRING = '{"Type": "Retract", "ID": "123456789", "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}'
    DICT = {"Type": "Retract", "ID": "123456789", "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}

    def test_init(self):
        # Empty init
        retract = detectionformats.retract.Retract()

        try:
            retract.id
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            retract.source.agencyID
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            retract.source.author
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        retract = detectionformats.retract.Retract(self.ID, self.SOURCE)

        try:
            retract.id
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(retract.id, self.ID)

        try:
            retract.source.agencyID
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(retract.source.agencyID, self.SOURCE.agencyID)

        try:
            retract.source.author
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(retract.source.author, self.SOURCE.author)

    def test_toJSON(self):
        retract = detectionformats.retract.Retract(self.ID, self.SOURCE)
        self.assertEqual(retract.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        retract = detectionformats.retract.Retract()
        retract.fromJSONString(self.JSONSTRING)

        self.assertEqual(retract.id, self.ID)
        self.assertEqual(retract.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(retract.source.author, self.SOURCE.author)

    def test_toDict(self):
        retract = detectionformats.retract.Retract(self.ID, self.SOURCE)
        self.assertEqual(retract.toDict(), self.DICT)

    def test_fromDict(self):
        retract = detectionformats.retract.Retract()
        retract.fromDict(self.DICT)

        self.assertEqual(retract.id, self.ID)
        self.assertEqual(retract.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(retract.source.author, self.SOURCE.author)

    def test_isValid(self):
        retract = detectionformats.retract.Retract(self.ID, self.SOURCE)
        self.assertTrue(retract.isValid())

        badRetract = detectionformats.retract.Retract()
        self.assertFalse(badRetract.isValid())

if __name__ == '__main__':
    unittest.main()
