#!/usr/bin/env python

#stdlib imports
import json

class Beam:
    """ Beam - a conversion class used to create, parse, and validate beam data 
        as part of detection data.
    """
    # json keys
    BACKAZIMUTH_KEY = "BackAzimuth"
    SLOWNESS_KEY = "Slowness"
    POWERRATIO_KEY = "PowerRatio"
    BACKAZIMUTHERROR_KEY = "BackAzimuthError"
    SLOWNESSERROR_KEY = "SlownessError"
    POWERRATIOERROR_KEY = "PowerRatioError"

    def __init__(self, newBackAzimuth=None, newSlowness=None, newPowerRatio=None,
        newBackAzimuthError=None, newSlownessError=None,
        newPowerRatioError=None):
        """Initialize the beam object. Constructs an empty object
           if all arguments are None

        Args:
            newBackAzimuth: a required Number containing the desired back
                azimuth measurement as a float
            newSlowness: a required Number containing the desired slowness
                measurement as a float
            newPowerRatio: an optional Number containing the desired power ratio
                measurement as a float
            newBackAzimuthError: an optional Number containing the desired back
                azimuth error measurement as a float
            newSlownessError: an optional Number containing the desired slowness
                error measurement as a float
            newPowerRatioError: an optional Number containing the desired power
                ratio error measurement as a float
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # first required keys
        if newBackAzimuth is not None:
            self.backAzimuth = newBackAzimuth
        if newSlowness is not None:
            self.slowness = newSlowness

        # second optional keys
        if newPowerRatio is not None:
            self.powerRatio = newPowerRatio
        if newBackAzimuthError is not None:
            self.backAzimuthError = newBackAzimuthError
        if newSlownessError is not None:
            self.slownessError = newSlownessError
        if newPowerRatioError is not None:
            self.powerRatioError = newPowerRatioError

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
        # first required keys
        try:
            self.backAzimuth = aDict[self.BACKAZIMUTH_KEY]
            self.slowness = aDict[self.SLOWNESS_KEY]
        except(ValueError, KeyError, TypeError) as e:
            print ("Dict format error, missing required keys: %s" % e)

        # second optional keys
        if self.POWERRATIO_KEY in aDict:
            self.powerRatio = aDict[self.POWERRATIO_KEY]
        if self.BACKAZIMUTHERROR_KEY in aDict:
            self.backAzimuthError = aDict[self.BACKAZIMUTHERROR_KEY]
        if self.SLOWNESSERROR_KEY in aDict:
            self.slownessError = aDict[self.SLOWNESSERROR_KEY]
        if self.POWERRATIOERROR_KEY in aDict:
            self.powerRatioError = aDict[self.POWERRATIOERROR_KEY]

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

        # first required keys
        try:
            aDict[self.BACKAZIMUTH_KEY] = self.backAzimuth
            aDict[self.SLOWNESS_KEY] = self.slowness
        except(NameError, AttributeError) as e:
            print ("Missing required data error: %s" % e)

        # second optional keys
        if hasattr(self, 'powerRatio'):
            aDict[self.POWERRATIO_KEY] = self.powerRatio

        if hasattr(self, 'backAzimuthError'):
            aDict[self.BACKAZIMUTHERROR_KEY] = self.backAzimuthError

        if hasattr(self, 'slownessError'):
            aDict[self.SLOWNESSERROR_KEY] = self.slownessError

        if hasattr(self, 'powerRatioError'):
            aDict[self.POWERRATIOERROR_KEY] = self.powerRatioError

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

        # first required keys
        try:
            if self.backAzimuth < 0:
                errorList.append('Invalid BackAzimuth in Beam Class.')
        except(NameError, AttributeError):
            errorList.append('No BackAzimuth in Beam Class.')

        try:
            if self.slowness < 0:
                errorList.append('Invalid Slowness in Beam Class.')
        except(NameError, AttributeError):
            errorList.append('No Slowness in Beam Class.')

        # second optional keys
        if hasattr(self, 'powerRatio'):
            if self.powerRatio < 0:
                errorList.append('Invalid PowerRatio in Beam Class.')

        if hasattr(self, 'backAzimuthError'):
            if self.backAzimuthError < 0:
                errorList.append('Invalid BackAzimuthError in Beam Class.')

        if hasattr(self, 'slownessError'):
            if self.slownessError < 0:
                errorList.append('Invalid SlownessError in Beam Class.')

        if hasattr(self, 'powerRatioError'):
            if self.powerRatioError < 0:
                errorList.append('Invalid PowerRatioError in Beam Class.')

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
        if hasattr(self, 'backAzimuth'):
            return False

        if hasattr(self, 'slowness'):
            return False

        if hasattr(self, 'powerRatio'):
            return False

        if hasattr(self, 'backAzimuthError'):
            return False

        if hasattr(self, 'slownessError'):
            return False

        if hasattr(self, 'powerRatioError'):
            return False           

        return True
