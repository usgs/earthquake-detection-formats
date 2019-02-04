#!/usr/bin/env python

#stdlib imports
import json

class Amplitude:
    """ Amplitude - a conversion class used to create, parse, and validate  
        amplitude data as part of detection data.
    """
    # json keys
    AMPLITUDE_KEY = "Amplitude"
    PERIOD_KEY = "Period"
    SNR_KEY = "SNR"

    def __init__(self, newAmplitude=None, newPeriod=None, newSNR=None):
        """Initialize the amplitude object. Constructs an empty object
           if all arguments are None

        Args:
            newAmplitude: an optional Number containing the desired amplitude
                measurement as a float
            newPeriod: an optional Number containing the desired period
                measurement as a float
            newSNR: an optional Number containing the desired signal to noise
                measurement as a float
        Returns:
            Nothing
        Raises:
            Nothing
        """
        if newAmplitude is not None:
            self.amplitude = newAmplitude
        if newPeriod is not None:
            self.period = newPeriod
        if newSNR is not None:
            self.snr = newSNR

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
        if self.AMPLITUDE_KEY in aDict:
            self.amplitude = aDict[self.AMPLITUDE_KEY]
        if self.PERIOD_KEY in aDict:
            self.period = aDict[self.PERIOD_KEY]
        if self.SNR_KEY in aDict:
            self.snr = aDict[self.SNR_KEY]

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
        if hasattr(self, 'amplitude'):
            aDict[self.AMPLITUDE_KEY] = self.amplitude

        if hasattr(self, 'period'):
            aDict[self.PERIOD_KEY] = self.period

        if hasattr(self, 'snr'):
            aDict[self.SNR_KEY] = self.snr

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

        # all members are optional

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
        if hasattr(self, 'amplitude'):
            return False

        if hasattr(self, 'period'):
            return False

        if hasattr(self, 'snr'):
            return False

        return True
