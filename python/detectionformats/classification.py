#!/usr/bin/env python

#package imports
import detectionformats.source
import detectionformats.eventtype

#stdlib imports
import json

# a conversion class used to create, parse, and validate classification data as
# part of detection data.
class Classification:
    PHASE_KEY = "Phase"
    PHASEPROB_KEY = "PhaseProbability"
    DISTANCE_KEY = "Distance"
    DISTANCEPROB_KEY = "DistanceProbability"
    AZIMUTH_KEY = "Azimuth"
    AZIMUTHPROB_KEY = "AzimuthProbability"
    MAGNITUDE_KEY = "Magnitude"
    MAGNITUDETYPE_KEY = "MagnitudeType"
    MAGNITUDEPROB_KEY = "MagnitudeProbability"
    DEPTH_KEY = "Depth"
    DEPTHPROB_KEY = "DepthProbability"
    EVENTTYPE_KEY = "EventType"
    EVENTTYPEPROB_KEY = "EventTypeProbability"
    SOURCE_KEY = "Source"

    # init
    def __init__(self, newPhase=None, newPhaseProb=None, newDistance=None, 
        newDistanceProb=None, newAzimuth=None, newAzimuthProb=None,
        newMagnitude=None, newMagType=None, newMagProb=None, newDepth=None,
        newDepthProb=None, newEventType=None, newEventTypeProb=None, 
        newSource=None) :
        """Initialize the classification object. Constructs an empty object
           if all arguments are None

        Args:
            newPhase: an optional String containing the desired phase
                identification
            newPhaseProb: an optional Number representing the probability of 
                the phase identification as a float
            newDistance: an optional Number containing the desired distance
                measurement as a float 
            newDistanceProb: an optional Number representing the probability of 
                the distance measurement as a float
            newAzimuth: an optional Number containing the desired azimuth
                measurement as a float
            newAzimuthProb: an optional Number representing the probability of 
                the azimuth measurement as a float
            newMagnitude: an optional Number representing the desired magnitude
                estimate as a float
            newMagType: an optional String containing the desired magnitude type
                identification
            newMagProb: an optional Number representing the probability of 
                the magnitude estimate as a float
            newDepth: an optional Number containing the desired depth measurement
                as a float
            newDepthProb: an optional Number representing the probability of 
                the depth measurement as a float
            newEventType: an optional detectionformats.eventtype.EventType 
                containing the desired event type
            newEventTypeProb: an optional Number representing the probability of 
                the event type as a float
            newSource: an optional detectionformats.source.Source containing 
                the source of the classification information
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # all members optional
        if newPhase is not None:
            self.phase = newPhase

        if newPhaseProb is not None:
            self.phaseProbability = newPhaseProb

        if newDistance is not None:
            self.distance = newDistance

        if newDistanceProb is not None:
            self.distanceProbability = newDistanceProb

        if newAzimuth is not None:
            self.azimuth = newAzimuth

        if newAzimuthProb is not None:
            self.azimuthProbability = newAzimuthProb

        if newMagnitude is not None:
            self.magnitude = newMagnitude

        if newMagType is not None:
            self.magnitudeType = newMagType

        if newMagProb is not None:
            self.magnitudeProbability = newMagProb

        if newDepth is not None:
            self.depth = newDepth

        if newDepthProb is not None:
            self.depthProbability = newDepthProb

        if newEventType is not None:
            self.eventType = newEventType
        else:
            self.eventType = detectionformats.eventtype.EventType()

        if newEventTypeProb is not None:
            self.eventTypeProbability = newEventTypeProb

        if newSource is not None:
            self.source = newSource
        else:
            self.source = detectionformats.source.Source()

    # populate class from a json string
    def fromJSONString(self, jsonString) :
        """Populates the object from a json formatted string

        Args:
            jsonString: a required String containing the json formatted text
        Returns:
            Nothing
        Raises:
            Nothing
        """
        jsonObject = json.loads(jsonString)
        self.fromDict(jsonObject)

    # populate class from a dictionary
    def fromDict(self, aDict) :
        """Populates the object from a dictionary

        Args:
            aDict: a required dictionary
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # all members optional
        if self.PHASE_KEY in aDict:
            self.phase = aDict[self.PHASE_KEY]
        
        if self.PHASEPROB_KEY in aDict:
            self.phaseProbability = aDict[self.PHASEPROB_KEY]

        if self.DISTANCE_KEY in aDict:
            self.distance = aDict[self.DISTANCE_KEY]

        if self.DISTANCEPROB_KEY in aDict:
            self.distanceProbability = aDict[self.DISTANCEPROB_KEY]

        if self.AZIMUTH_KEY in aDict:
            self.azimuth = aDict[self.AZIMUTH_KEY]

        if self.AZIMUTHPROB_KEY in aDict:
            self.azimuthProbability = aDict[self.AZIMUTHPROB_KEY]

        if self.MAGNITUDE_KEY in aDict:
            self.magnitude = aDict[self.MAGNITUDE_KEY]

        if self.MAGNITUDETYPE_KEY in aDict:
            self.magnitudeType = aDict[self.MAGNITUDETYPE_KEY]

        if self.MAGNITUDEPROB_KEY in aDict:
            self.magnitudeProbability = aDict[self.MAGNITUDEPROB_KEY]

        if self.DEPTH_KEY in aDict:
            self.depth = aDict[self.DEPTH_KEY]

        if self.DEPTHPROB_KEY in aDict:
            self.depthProbability = aDict[self.DEPTHPROB_KEY]

        if self.EVENTTYPE_KEY in aDict:
            self.eventType = detectionformats.eventtype.EventType()
            self.eventType.fromDict(aDict[self.EVENTTYPE_KEY])         

        if self.EVENTTYPEPROB_KEY in aDict:
            self.eventTypeProbability = aDict[self.EVENTTYPEPROB_KEY]

        if self.SOURCE_KEY in aDict:
            self.source = detectionformats.source.Source()
            self.source.fromDict(aDict[self.SOURCE_KEY])

    # convert class to a json string
    def toJSONString(self) :
        """Converts the object to a json formatted string

        Args:
            None
        Returns:
            The JSON formatted message as a String
        Raises:
            Nothing
        """
        jsonObject = self.toDict()

        return json.dumps(jsonObject, ensure_ascii=False)

    # convert class to a dictionary
    def toDict(self) :
        """Converts the object to a dictionary

        Args:
            None
        Returns:
            The dictionary
        Raises:
            Nothing
        """
        aDict = {}

        # all members optional
        try:
            aDict[self.PHASE_KEY] = self.phase
        except:
            pass

        try:
            aDict[self.PHASEPROB_KEY] = self.phaseProbability
        except:
            pass    

        try:
            aDict[self.DISTANCE_KEY] = self.distance
        except:
            pass

        try:
            aDict[self.DISTANCEPROB_KEY] = self.distanceProbability
        except:
            pass    

        try:
            aDict[self.AZIMUTH_KEY] = self.azimuth
        except:
            pass

        try:
            aDict[self.AZIMUTHPROB_KEY] = self.azimuthProbability
        except:
            pass   

        try:
            aDict[self.MAGNITUDE_KEY] = self.magnitude
        except:
            pass

        try:
            aDict[self.MAGNITUDETYPE_KEY] = self.magnitudeType
        except:
            pass

        try:
            aDict[self.MAGNITUDEPROB_KEY] = self.magnitudeProbability
        except:
            pass

        try:
            aDict[self.DEPTH_KEY] = self.depth
        except:
            pass

        try:
            aDict[self.DEPTHPROB_KEY] = self.depthProbability
        except:
            pass

        try:
            if self.eventType.isEmpty() == False:
                aDict[self.EVENTTYPE_KEY] = self.eventType.toDict()
        except:
            pass

        try:
            aDict[self.EVENTTYPEPROB_KEY] = self.eventTypeProbability
        except:
            pass

        try:
            if self.source.isEmpty() == False:
                aDict[self.SOURCE_KEY] = self.source.toDict()
        except:
            pass

        return aDict

    # test to see if class is valid
    def isValid(self) :
        """Checks to see if the object is valid

        Args:
            None
        Returns:
            True if the object is valid, False otherwise
        Raises:
            Nothing
        """
        errorList = self.getErrors()

        if len(errorList) == 0:
            return True
        else:
            return False

    # get list of validation errors
    def getErrors(self) :
        """Gets a list of object validation errors

        Args:
            None
        Returns:
            A List of Strings containing the validation error messages
        Raises:
            Nothing
        """
        errorList = []

        # optional
        # need to lookup how to check if something is a string and
        # if it's a letter

        # second optional keys
        try:
            if self.distance < 0:
                errorList.append('Invalid Distance in Classification Class.')
        except:
            pass

        try:
            if self.azimuth < 0:
                errorList.append('Invalid Azimuth in Classification Class.')
        except:
            pass

        try:
            if self.magnitude < -2 or self.magnitude > 10:
                errorList.append('Magnitude in Classification Class not in the range of -2 to 10.')
        except:
            pass

        try:
            if self.depth < -100 or self.depth > 1500:
                errorList.append('Depth in Classification Class not in the range of -100 to 1500.')
        except:
            pass

        try:
            if self.eventType.isValid() == False:
                errorList.append('Invalid EventType in Classification Class.')
        except:
            pass

        try:
            if self.source.isValid() == False:
                errorList.append('Invalid Source in Classification Class.')
        except:
            pass

        return errorList

    # test to see if class is empty
    def isEmpty(self) :
        """Checks to see if the object is empty

        Args:
            None
        Returns:
            True if the object is empty, False otherwise
        Raises:
            Nothing
        """
        try:
            self.phase
            return False
        except:
            pass

        try:
            self.phaseProbability
            return False
        except:
            pass

        try:
            self.distance
            return False
        except:
            pass

        try:
            self.distanceProbability
            return False
        except:
            pass            

        try:
            self.azimuth
            return False
        except:
            pass

        try:
            self.azimuthProbability
            return False
        except:
            pass            

        try:
            self.magnitude
            return False
        except:
            pass

        try:
            self.magnitudeType
            return False
        except:
            pass

        try:
            self.magnitudeProbability
            return False
        except:
            pass

        try:
            self.depth
            return False
        except:
            pass

        try:
            self.depthProbability
            return False
        except:
            pass

        try:
            if self.eventType.isEmpty() == False:
                return False
        except:
            pass

        try:
            self.eventTypeProbability
            return False
        except:
            pass

        try:
            if self.source.isEmpty() == False:
                return False
        except:
            pass

        return True

