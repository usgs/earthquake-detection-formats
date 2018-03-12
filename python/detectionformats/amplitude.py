#!/usr/bin/env python

#stdlib imports
import json

# a conversion class used to create, parse, and validate amplitude data as part
# of detection data.
class Amplitude:
    # json keys
    AMPLITUDE_KEY = "Amplitude"
    PERIOD_KEY = "Period"
    SNR_KEY = "SNR"

    # init
    def __init__(self, newAmplitude=None, newPeriod=None, newSNR=None) :
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

    # populate class from a dictonary
    def fromDict(self, aDict) :
        """Populates the object from a dictonary

        Args:
            aDict: a required Dictonary
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

    # convert class to a dictonary
    def toDict(self) :
        """Converts the object to a dictonary

        Args:
            None
        Returns:
            The Dictonary
        Raises:
            Nothing
        """
        aDict = {}
        try:
            aDict[self.AMPLITUDE_KEY] = self.amplitude
        except:
            pass

        try:
            aDict[self.PERIOD_KEY] = self.period
        except:
            pass

        try:
            aDict[self.SNR_KEY] = self.snr
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

        # all members are optional

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
            self.amplitude
            return False
        except:
            pass

        try:
            self.period
            return False
        except:
            pass

        try:
            self.snr
            return False
        except:
            pass

        return True
