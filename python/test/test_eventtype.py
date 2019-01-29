#!/usr/bin/env python

#package imports
import detectionformats.eventtype

#stdlib imports
import unittest

class TestEventType(unittest.TestCase):
    TYPE = 'Earthquake'
    EARTHQUAKE = 'Earthquake'
    MINECOLLAPSE = 'MineCollapse'
    NUCLEAREXPLOSION = 'NuclearExplosion'
    QUARRYBLAST = 'QuarryBlast'
    INDUCED = 'InducedOrTriggered'
    ROCKBURST = 'RockBurst'
    FLUIDINJECTION = 'FluidInjection'
    ICEQUAKE = 'IceQuake'
    VOLCANIC = 'VolcanicEruption'
    CERTAINTY = 'Suspected'
    SUSPECTED = 'Suspected'
    CONFIRMED = 'Confirmed'
    JSONSTRING = '{"Type": "Earthquake", "Certainty": "Suspected"}'
    DICT =  {"Type":"Earthquake","Certainty":"Suspected"}

    def test_init(self):
        # Empty init
        eventtype = detectionformats.eventtype.EventType()

        try:
            eventtype.type
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        try:
            eventtype.certainty
            self.assertTrue(False)
        except AttributeError:
            self.assertTrue(True)
            pass

        eventtype = detectionformats.eventtype.EventType(self.TYPE,
            self.CERTAINTY)

        try:
            eventtype.type
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(eventtype.type, self.TYPE)

        try:
            eventtype.certainty
            self.assertTrue(True)
        except AttributeError:
            self.assertTrue(False)
            pass

        self.assertEqual(eventtype.certainty, self.CERTAINTY)

    def test_toJSON(self):
        eventtype = detectionformats.eventtype.EventType(self.TYPE,
            self.CERTAINTY)
        self.assertEqual(eventtype.toJSONString(), self.JSONSTRING)

    def test_fromJSON(self):
        eventtype = detectionformats.eventtype.EventType()
        eventtype.fromJSONString(self.JSONSTRING)

        self.assertEqual(eventtype.type, self.TYPE)
        self.assertEqual(eventtype.certainty, self.CERTAINTY)

    def test_toDict(self):
        eventtype = detectionformats.eventtype.EventType(self.TYPE,
            self.CERTAINTY)
        self.assertEqual(eventtype.toDict(), self.DICT)

    def test_fromDict(self):
        eventtype = detectionformats.eventtype.EventType()
        eventtype.fromDict(self.DICT)

        self.assertEqual(eventtype.type, self.TYPE)
        self.assertEqual(eventtype.certainty, self.CERTAINTY)

    def test_isValid(self):
        eventtype = detectionformats.eventtype.EventType(self.TYPE,
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())

    def test_isEmpty(self):
        eventtype = detectionformats.eventtype.EventType()
        self.assertTrue(eventtype.isEmpty())

        eventtype = detectionformats.eventtype.EventType(self.TYPE,
            self.CERTAINTY)
        self.assertFalse(eventtype.isEmpty())

    def test_ValidTypes(self):
        eventtype = detectionformats.eventtype.EventType(self.EARTHQUAKE, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())   

        eventtype = detectionformats.eventtype.EventType(self.MINECOLLAPSE, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())      

        eventtype = detectionformats.eventtype.EventType(self.NUCLEAREXPLOSION, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())      

        eventtype = detectionformats.eventtype.EventType(self.QUARRYBLAST, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())    

        eventtype = detectionformats.eventtype.EventType(self.INDUCED, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())      

        eventtype = detectionformats.eventtype.EventType(self.ROCKBURST, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())

        eventtype = detectionformats.eventtype.EventType(self.FLUIDINJECTION, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())
        
        eventtype = detectionformats.eventtype.EventType(self.ICEQUAKE, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())

        eventtype = detectionformats.eventtype.EventType(self.VOLCANIC, 
            self.CERTAINTY)
        self.assertTrue(eventtype.isValid())

    def test_ValidCertainties(self):
        eventtype = detectionformats.eventtype.EventType(self.EARTHQUAKE, self.SUSPECTED)
        self.assertTrue(eventtype.isValid())
        
        eventtype = detectionformats.eventtype.EventType(self.EARTHQUAKE, self.CONFIRMED)
        self.assertTrue(eventtype.isValid())  
