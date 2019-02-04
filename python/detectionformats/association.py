#!/usr/bin/env python

#stdlib imports
import json

class Association:
    """ Association - a conversion class used to create, parse, and validate 
        association data as part of detection data.
    """
    # json keys
    PHASE_KEY = "Phase"
    DISTANCE_KEY = "Distance"
    AZIMUTH_KEY = "Azimuth"
    RESIDUAL_KEY = "Residual"
    SIGMA_KEY = "Sigma"

    def __init__(self, newPhase=None, newDistance=None, newAzimuth=None,
        newResidual=None, newSigma=None):
        """Initialize the associated object. Constructs an empty object
           if all arguments are None

        Args:
            newPhase: an optional String containing the desired phase
                identification
            newDistance: an optional Number containing the desired distance
                measurement as a float
            newAzimuth: an optional Number containing the desired azimuth
                measurement as a float
            newResidual: an optional Number containing the desired residual
                measurement as a float
            newSigma: an optional Number containing the desired sigma measurement
                as a float
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # all members optional
        if newPhase is not None:
            self.phase = newPhase
        if newDistance is not None:
            self.distance = newDistance
        if newAzimuth is not None:
            self.azimuth = newAzimuth
        if newResidual is not None:
            self.residual = newResidual
        if newSigma is not None:
            self.sigma = newSigma

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
        if self.DISTANCE_KEY in aDict:
            self.distance = aDict[self.DISTANCE_KEY]
        if self.AZIMUTH_KEY in aDict:
            self.azimuth = aDict[self.AZIMUTH_KEY]
        if self.RESIDUAL_KEY in aDict:
            self.residual = aDict[self.RESIDUAL_KEY]
        if self.SIGMA_KEY in aDict:
            self.sigma = aDict[self.SIGMA_KEY]

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

        if hasattr(self, 'distance'):
            aDict[self.DISTANCE_KEY] = self.distance

        if hasattr(self, 'azimuth'):
            aDict[self.AZIMUTH_KEY] = self.azimuth

        if hasattr(self, 'residual'):
            aDict[self.RESIDUAL_KEY] = self.residual

        if hasattr(self, 'sigma'):
            aDict[self.SIGMA_KEY] = self.sigma

        return aDict

    # test to see if class is valid
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

        if len(errorList) == 0:
            return True
        else:
            return False

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

        # optional
        # need to lookup how to check if something is a string and
        # if it's a letter

        # second optional keys
        if hasattr(self, 'distance'):
            if self.distance < 0:
                errorList.append('Invalid Distance in Association Class.')

        if hasattr(self, 'azimuth'):
            if self.azimuth < 0:
                errorList.append('Invalid Azimuth in Association Class.')

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

        if hasattr(self, 'distance'):
            return False

        if hasattr(self, 'azimuth'):
            return False

        if hasattr(self, 'residual'):
            return False

        if hasattr(self, 'sigma'):
            return False

        return True
