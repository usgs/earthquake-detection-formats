#!/usr/bin/env python

#package imports
import detectionformats.classification
import detectionformats.source
import detectionformats.eventtype

#stdlib imports
import unittest

class TestClassification(unittest.TestCase):
    PHASE = "P"
    PHASEPROBABILITY = 0.22
    DISTANCE = 0.442559
    DISTANCEPROBABILITY = 22.5
    BACKAZIMUTH = 0.418479
    BACKAZIMUTHPROBABILITY = 0.16
    MAGNITUDE = 2.14
    MAGNITUDETYPE = "Mb"
    MAGNITUDEPROBABILITY = 0.55
    DEPTH = 32.44
    DEPTHPROBABILITY = 11.2
    EVENTTYPE = detectionformats.eventtype.EventType('Earthquake', 'Suspected')
    EVENTTYPEPROBABILITY = 1.1
    SOURCE = detectionformats.source.Source('testAgency', 'testAuthor')

    JSONSTRING = '{"Phase": "P", "PhaseProbability": 0.22, "Distance": 0.442559, "DistanceProbability": 22.5, "Backazimuth": 0.418479, "BackazimuthProbability": 0.16, "Magnitude": 2.14, "MagnitudeType": "Mb", "MagnitudeProbability": 0.55, "Depth": 32.44, "DepthProbability": 11.2, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "EventTypeProbability": 1.1, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}'
    DICT = {"Phase": "P", "PhaseProbability": 0.22, "Distance": 0.442559, "DistanceProbability": 22.5, "Backazimuth": 0.418479, "BackazimuthProbability": 0.16, "Magnitude": 2.14, "MagnitudeType": "Mb", "MagnitudeProbability": 0.55, "Depth": 32.44, "DepthProbability": 11.2, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "EventTypeProbability": 1.1, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}

    def test_init(self):
        # Empty init
        classification = detectionformats.classification.Classification()

        self.assertFalse(hasattr(classification, 'phase'))
        self.assertFalse(hasattr(classification, 'phaseProbability'))
        self.assertFalse(hasattr(classification, 'distance'))
        self.assertFalse(hasattr(classification, 'distanceProbability'))
        self.assertFalse(hasattr(classification, 'backazimuth'))
        self.assertFalse(hasattr(classification, 'backazimuthProbability'))
        self.assertFalse(hasattr(classification, 'magnitude'))
        self.assertFalse(hasattr(classification, 'magnitudeType'))
        self.assertFalse(hasattr(classification, 'magnitudeProbability'))
        self.assertFalse(hasattr(classification, 'depth'))
        self.assertFalse(hasattr(classification, 'depthProbability'))
        self.assertFalse(hasattr(classification.eventType, 'type'))
        self.assertFalse(hasattr(classification.eventType, 'certainty'))
        self.assertFalse(hasattr(classification, 'eventTypeProbability'))
        self.assertFalse(hasattr(classification.source, 'agencyID'))
        self.assertFalse(hasattr(classification.source, 'author'))

        classification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, self.DISTANCE, self.DISTANCEPROBABILITY, 
            self.BACKAZIMUTH, self.BACKAZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, self.DEPTH, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)

        self.assertTrue(hasattr(classification, 'phase'))
        self.assertTrue(hasattr(classification, 'phaseProbability'))
        self.assertTrue(hasattr(classification, 'distance'))
        self.assertTrue(hasattr(classification, 'distanceProbability'))
        self.assertTrue(hasattr(classification, 'backazimuth'))
        self.assertTrue(hasattr(classification, 'backazimuthProbability'))
        self.assertTrue(hasattr(classification, 'magnitude'))
        self.assertTrue(hasattr(classification, 'magnitudeType'))
        self.assertTrue(hasattr(classification, 'magnitudeProbability'))
        self.assertTrue(hasattr(classification, 'depth'))
        self.assertTrue(hasattr(classification, 'depthProbability'))
        self.assertTrue(hasattr(classification.eventType, 'type'))
        self.assertTrue(hasattr(classification.eventType, 'certainty'))
        self.assertTrue(hasattr(classification, 'eventTypeProbability'))
        self.assertTrue(hasattr(classification.source, 'agencyID'))
        self.assertTrue(hasattr(classification.source, 'author'))

        self.assertEqual(classification.phaseProbability, self.PHASEPROBABILITY)
        self.assertEqual(classification.phase, self.PHASE)
        self.assertEqual(classification.distance, self.DISTANCE)
        self.assertEqual(classification.distanceProbability, self.DISTANCEPROBABILITY)
        self.assertEqual(classification.backazimuth, self.BACKAZIMUTH)
        self.assertEqual(classification.backazimuthProbability, self.BACKAZIMUTHPROBABILITY)      
        self.assertEqual(classification.magnitude, self.MAGNITUDE)
        self.assertEqual(classification.magnitudeType, self.MAGNITUDETYPE)
        self.assertEqual(classification.magnitudeProbability, self.MAGNITUDEPROBABILITY)
        self.assertEqual(classification.depth, self.DEPTH)
        self.assertEqual(classification.depthProbability, self.DEPTHPROBABILITY)  
        self.assertEqual(classification.eventType.type, self.EVENTTYPE.type) 
        self.assertEqual(classification.eventType.certainty, self.EVENTTYPE.certainty)  
        self.assertEqual(classification.eventTypeProbability, self.EVENTTYPEPROBABILITY)  
        self.assertEqual(classification.source.agencyID, self.SOURCE.agencyID) 
        self.assertEqual(classification.source.author, self.SOURCE.author)     

    def test_toJSON(self):
        classification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, self.DISTANCE, self.DISTANCEPROBABILITY, 
            self.BACKAZIMUTH, self.BACKAZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, self.DEPTH, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)
        self.maxDiff = None
        self.assertEqual(classification.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        classification = detectionformats.classification.Classification()
        classification.fromJSONString(self.JSONSTRING)

        self.assertEqual(classification.phase, self.PHASE)
        self.assertEqual(classification.phaseProbability, self.PHASEPROBABILITY)
        self.assertEqual(classification.distance, self.DISTANCE)
        self.assertEqual(classification.distanceProbability, self.DISTANCEPROBABILITY)
        self.assertEqual(classification.backazimuth, self.BACKAZIMUTH)
        self.assertEqual(classification.backazimuthProbability, self.BACKAZIMUTHPROBABILITY) 
        self.assertEqual(classification.magnitude, self.MAGNITUDE)
        self.assertEqual(classification.magnitudeType, self.MAGNITUDETYPE)
        self.assertEqual(classification.magnitudeProbability, self.MAGNITUDEPROBABILITY)
        self.assertEqual(classification.depth, self.DEPTH)
        self.assertEqual(classification.depthProbability, self.DEPTHPROBABILITY) 
        self.assertEqual(classification.eventType.type, self.EVENTTYPE.type)
        self.assertEqual(classification.eventType.certainty, self.EVENTTYPE.certainty)    
        self.assertEqual(classification.eventTypeProbability, self.EVENTTYPEPROBABILITY)   
        self.assertEqual(classification.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(classification.source.author, self.SOURCE.author)  

    def test_toDict(self):
        classification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, self.DISTANCE, self.DISTANCEPROBABILITY, 
            self.BACKAZIMUTH, self.BACKAZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, self.DEPTH, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)
        self.assertEqual(classification.toDict(), self.DICT)

    def test_fromDict(self):
        classification = detectionformats.classification.Classification()
        classification.fromDict(self.DICT)

        self.assertEqual(classification.phase, self.PHASE)
        self.assertEqual(classification.phaseProbability, self.PHASEPROBABILITY)
        self.assertEqual(classification.distance, self.DISTANCE)
        self.assertEqual(classification.distanceProbability, self.DISTANCEPROBABILITY)
        self.assertEqual(classification.backazimuth, self.BACKAZIMUTH)
        self.assertEqual(classification.backazimuthProbability, self.BACKAZIMUTHPROBABILITY) 
        self.assertEqual(classification.magnitude, self.MAGNITUDE)
        self.assertEqual(classification.magnitudeType, self.MAGNITUDETYPE)
        self.assertEqual(classification.magnitudeProbability, self.MAGNITUDEPROBABILITY)
        self.assertEqual(classification.depth, self.DEPTH)
        self.assertEqual(classification.depthProbability, self.DEPTHPROBABILITY) 
        self.assertEqual(classification.eventType.type, self.EVENTTYPE.type)
        self.assertEqual(classification.eventType.certainty, self.EVENTTYPE.certainty)    
        self.assertEqual(classification.eventTypeProbability, self.EVENTTYPEPROBABILITY)   
        self.assertEqual(classification.source.agencyID, self.SOURCE.agencyID)
        self.assertEqual(classification.source.author, self.SOURCE.author) 

    def test_isValid(self):
        classification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, self.DISTANCE, self.DISTANCEPROBABILITY, 
            self.BACKAZIMUTH, self.BACKAZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, self.DEPTH, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)
        self.assertTrue(classification.isValid())

        badClassification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, -1, self.DISTANCEPROBABILITY, 
            -1, self.BACKAZIMUTHPROBABILITY, -100.0, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, -9999.0, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)

        self.assertFalse(badClassification.isValid())

    def test_isEmpty(self):
        classification = detectionformats.classification.Classification()
        self.assertTrue(classification.isEmpty())

        classification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, self.DISTANCE, self.DISTANCEPROBABILITY, 
            self.BACKAZIMUTH, self.BACKAZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, self.DEPTH, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)
        self.assertFalse(classification.isEmpty())

if __name__ == '__main__':
    unittest.main()        