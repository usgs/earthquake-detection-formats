#!/usr/bin/env python

# package imports
import detectionformats.source

# stdlib imports
import unittest


class TestSource(unittest.TestCase):
    AGENCYID = "testAgency"
    AUTHOR = "testAuthor"
    JSONSTRING = '{"AgencyID": "testAgency", "Author": "testAuthor"}'
    DICT = {"AgencyID": "testAgency", "Author": "testAuthor"}

    def test_init(self):
        # Empty init
        source = detectionformats.source.Source()

        self.assertFalse(hasattr(source, "agencyID"))
        self.assertFalse(hasattr(source, "author"))

        source = detectionformats.source.Source(self.AGENCYID, self.AUTHOR)

        self.assertTrue(hasattr(source, "agencyID"))
        self.assertTrue(hasattr(source, "author"))

        self.assertEqual(source.agencyID, self.AGENCYID)
        self.assertEqual(source.author, self.AUTHOR)

    def test_toJSON(self):
        source = detectionformats.source.Source(self.AGENCYID, self.AUTHOR)
        self.assertEqual(source.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        source = detectionformats.source.Source()
        source.fromJSONString(self.JSONSTRING)

        self.assertEqual(source.agencyID, self.AGENCYID)
        self.assertEqual(source.author, self.AUTHOR)

    def test_toDict(self):
        source = detectionformats.source.Source(self.AGENCYID, self.AUTHOR)
        self.assertEqual(source.toDict(), self.DICT)

    def test_fromDict(self):
        source = detectionformats.source.Source()
        source.fromDict(self.DICT)

        self.assertEqual(source.agencyID, self.AGENCYID)
        self.assertEqual(source.author, self.AUTHOR)

    def test_isValid(self):
        source = detectionformats.source.Source(self.AGENCYID, self.AUTHOR)
        self.assertTrue(source.isValid())

        badSource = detectionformats.source.Source()
        self.assertFalse(badSource.isValid())

    def test_isEmpty(self):
        source = detectionformats.source.Source()
        self.assertTrue(source.isEmpty())

        source = detectionformats.source.Source(self.AGENCYID, self.AUTHOR)
        self.assertFalse(source.isEmpty())


if __name__ == "__main__":
    unittest.main()
