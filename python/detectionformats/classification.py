#!/usr/bin/env python

#package imports
import detectionformats.source
import detectionformats.eventtype

#stdlib imports
import json

class Classification:
    """ Classification - a conversion class used to create, parse, and validate 
        value added classification data from advanced algorithms such as machine 
        learning as part of detection data.
    """
    # json keys
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

    def __init__(self, newPhase=None, newPhaseProb=None, newDistance=None, 
        newDistanceProb=None, newAzimuth=None, newAzimuthProb=None,
        newMagnitude=None, newMagType=None, newMagProb=None, newDepth=None,
        newDepthProb=None, newEventType=None, newEventTypeProb=None, 
        newSource=None):
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

    def fromJSONString(self, jsonString):
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

    def fromDict(self, aDict):
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

    def toJSONString(self):
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

    def toDict(self):
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
        if hasattr(self, 'phase'):
            aDict[self.PHASE_KEY] = self.phase

        if hasattr(self, 'phaseProbability'):
            aDict[self.PHASEPROB_KEY] = self.phaseProbability

        if hasattr(self, 'distance'):
            aDict[self.DISTANCE_KEY] = self.distance

        if hasattr(self, 'distanceProbability'):
            aDict[self.DISTANCEPROB_KEY] = self.distanceProbability

        if hasattr(self, 'azimuth'):
            aDict[self.AZIMUTH_KEY] = self.azimuth

        if hasattr(self, 'azimuthProbability'):
            aDict[self.AZIMUTHPROB_KEY] = self.azimuthProbability

        if hasattr(self, 'magnitude'):
            aDict[self.MAGNITUDE_KEY] = self.magnitude

        if hasattr(self, 'magnitudeType'):
            aDict[self.MAGNITUDETYPE_KEY] = self.magnitudeType

        if hasattr(self, 'magnitudeProbability'):
            aDict[self.MAGNITUDEPROB_KEY] = self.magnitudeProbability

        if hasattr(self, 'depth'):
            aDict[self.DEPTH_KEY] = self.depth

        if hasattr(self, 'depthProbability'):
            aDict[self.DEPTHPROB_KEY] = self.depthProbability

        if hasattr(self, 'eventType'):
            if not self.eventType.isEmpty():
                aDict[self.EVENTTYPE_KEY] = self.eventType.toDict()

        if hasattr(self, 'eventTypeProbability'):
            aDict[self.EVENTTYPEPROB_KEY] = self.eventTypeProbability

        if hasattr(self, 'source'):
            if not self.source.isEmpty():
                aDict[self.SOURCE_KEY] = self.source.toDict()

        return aDict

    def isValid(self):
        """Checks to see if the object is valid

        Args:
            None
        Returns:
            True if the object is valid, False otherwise
        Raises:
            Nothing
        """
        errorList = self.getErrors()

        return not errorList

    def getErrors(self):
        """Gets a list of object validation errors

        Args:
            None
        Returns:
            A List of Strings containing the validation error messages
        Raises:
            Nothing
        """
        errorList = []

        # second optional keys
        if hasattr(self, 'distance'):
            if self.distance < 0:
                errorList.append('Invalid Distance in Classification Class.')

        if hasattr(self, 'azimuth'):
            if self.azimuth < 0:
                errorList.append('Invalid Azimuth in Classification Class.')

        if hasattr(self, 'magnitude'):
            if self.magnitude < -2 or self.magnitude > 10:
                errorList.append('Magnitude in Classification Class not in the range of -2 to 10.')

        if hasattr(self, 'depth'):
            if self.depth < -100 or self.depth > 1500:
                errorList.append('Depth in Classification Class not in the range of -100 to 1500.')

        if hasattr(self, 'eventType'):
            if not self.eventType.isValid():
                errorList.append('Invalid EventType in Classification Class.')

        if hasattr(self, 'source'):
            if not self.source.isEmpty():
                if not self.source.isValid():
                    errorList.append('Invalid Source in Classification Class.')

        return errorList

    def isEmpty(self):
        """Checks to see if the object is empty

        Args:
            None
        Returns:
            True if the object is empty, False otherwise
        Raises:
            Nothing
        """
        if hasattr(self, 'phase'):
            return False

        if hasattr(self, 'phaseProbability'):
            return False

        if hasattr(self, 'distance'):
            return False

        if hasattr(self, 'distanceProbability'):
            return False

        if hasattr(self, 'azimuth'):
            return False

        if hasattr(self, 'azimuthProbability'):
            return False
 
        if hasattr(self, 'magnitude'):
            return False

        if hasattr(self, 'magnitudeType'):
            return False

        if hasattr(self, 'magnitudeProbability'):
            return False

        if hasattr(self, 'depth'):
            return False

        if hasattr(self, 'depthProbability'):
            return False

        if hasattr(self, 'eventType'):
            if not self.eventType.isEmpty():
                return False

        if hasattr(self, 'eventTypeProbability'):
            return False

        if hasattr(self, 'source'):
            if not self.source.isEmpty():
                return False

        return True

