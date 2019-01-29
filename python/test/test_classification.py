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
    AZIMUTH = 0.418479
    AZIMUTHPROBABILITY = 0.16
    MAGNITUDE = 2.14
    MAGNITUDETYPE = "Mb"
    MAGNITUDEPROBABILITY = 0.55
    DEPTH = 32.44
    DEPTHPROBABILITY = 11.2
    EVENTTYPE = detectionformats.eventtype.EventType('Earthquake', 'Suspected')
    EVENTTYPEPROBABILITY = 1.1
    SOURCE = detectionformats.source.Source('testAgency', 'testAuthor')

    JSONSTRING = '{"Phase": "P", "PhaseProbability": 0.22, "Distance": 0.442559, "DistanceProbability": 22.5, "Azimuth": 0.418479, "AzimuthProbability": 0.16, "Magnitude": 2.14, "MagnitudeType": "Mb", "MagnitudeProbability": 0.55, "Depth": 32.44, "DepthProbability": 11.2, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "EventTypeProbability": 1.1, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}'
    DICT = {"Phase": "P", "PhaseProbability": 0.22, "Distance": 0.442559, "DistanceProbability": 22.5, "Azimuth": 0.418479, "AzimuthProbability": 0.16, "Magnitude": 2.14, "MagnitudeType": "Mb", "MagnitudeProbability": 0.55, "Depth": 32.44, "DepthProbability": 11.2, "EventType": {"Type": "Earthquake", "Certainty": "Suspected"}, "EventTypeProbability": 1.1, "Source": {"AgencyID": "testAgency", "Author": "testAuthor"}}

    def test_init(self):
        # Empty init
        classification = detectionformats.classification.Classification()

        try:
            classification.phase
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass
        
        try:
            classification.phaseProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass    

        try:
            classification.distance
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.distanceProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.azimuth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.azimuthProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.magnitude
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.magnitudeType
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass
        
        try:
            classification.magnitudeProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.residual
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.depth
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass  

        try:
            classification.depthProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass  

        try:
            classification.eventType.type
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.eventType.certainty
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.eventTypeProbability
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.source.agencyID
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            classification.source.author
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        classification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, self.DISTANCE, self.DISTANCEPROBABILITY, 
            self.AZIMUTH, self.AZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, self.DEPTH, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)

        try:
            classification.phase
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.phase, self.PHASE)

        try:
            classification.phaseProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.phaseProbability, self.PHASEPROBABILITY)

        try:
            classification.distance
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.distance, self.DISTANCE)

        try:
            classification.distanceProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.distanceProbability, self.DISTANCEPROBABILITY)

        try:
            classification.azimuth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.azimuth, self.AZIMUTH)

        try:
            classification.azimuthProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.azimuthProbability, self.AZIMUTHPROBABILITY)        

        try:
            classification.magnitude
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.magnitude, self.MAGNITUDE)

        try:
            classification.magnitudeType
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.magnitudeType, self.MAGNITUDETYPE)

        try:
            classification.magnitudeProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.magnitudeProbability, self.MAGNITUDEPROBABILITY)

        try:
            classification.depth
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.depth, self.DEPTH)

        try:
            classification.depthProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.depthProbability, self.DEPTHPROBABILITY)  

        try:
            classification.eventType.type
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.eventType.type, self.EVENTTYPE.type)  

        try:
            classification.eventType.certainty
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.eventType.certainty, self.EVENTTYPE.certainty)  

        try:
            classification.eventTypeProbability
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.eventTypeProbability, self.EVENTTYPEPROBABILITY)   

        try:
            classification.source.agencyID
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.source.agencyID, self.SOURCE.agencyID)  

        try:
            classification.source.author
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(classification.source.author, self.SOURCE.author)     

    def test_toJSON(self):
        classification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, self.DISTANCE, self.DISTANCEPROBABILITY, 
            self.AZIMUTH, self.AZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
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
        self.assertEqual(classification.azimuth, self.AZIMUTH)
        self.assertEqual(classification.azimuthProbability, self.AZIMUTHPROBABILITY) 
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
            self.AZIMUTH, self.AZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
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
        self.assertEqual(classification.azimuth, self.AZIMUTH)
        self.assertEqual(classification.azimuthProbability, self.AZIMUTHPROBABILITY) 
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
            self.AZIMUTH, self.AZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, self.DEPTH, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)
        self.assertTrue(classification.isValid())

        badClassification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, -1, self.DISTANCEPROBABILITY, 
            -1, self.AZIMUTHPROBABILITY, -100.0, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, -9999.0, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)

        self.assertFalse(badClassification.isValid())

    def test_isEmpty(self):
        classification = detectionformats.classification.Classification()
        self.assertTrue(classification.isEmpty())

        classification = detectionformats.classification.Classification(self.PHASE,
            self.PHASEPROBABILITY, self.DISTANCE, self.DISTANCEPROBABILITY, 
            self.AZIMUTH, self.AZIMUTHPROBABILITY, self.MAGNITUDE, self.MAGNITUDETYPE, 
            self.MAGNITUDEPROBABILITY, self.DEPTH, self.DEPTHPROBABILITY, 
            self.EVENTTYPE, self.EVENTTYPEPROBABILITY, self.SOURCE)
        self.assertFalse(classification.isEmpty())

if __name__ == '__main__':
    unittest.main()        