#!/usr/bin/env python

#stdlib imports
import json

# a conversion class used to create, parse, and validate filter data as part of
# detection data.
class Filter:
    HIGHPASS_KEY = "HighPass"
    LOWPASS_KEY = "LowPass"

    # init
    def __init__(self, newHighPass=None, newLowPass=None) :
        """Initialize the filter object. Constructs an empty object
           if all arguments are None

        Args:
            newHighPass: an optional Number containing the desired filter high
                pass value as a float
            newLowPass: an optional Number containing the desired filter low
                pass value as a float
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # all members optional
        if newHighPass is not None:
            self.highPass = newHighPass
        if newLowPass is not None:
            self.lowPass = newLowPass

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
        # all members optional
        if self.HIGHPASS_KEY in aDict:
            self.highPass = aDict[self.HIGHPASS_KEY]
        if self.LOWPASS_KEY in aDict:
            self.lowPass = aDict[self.LOWPASS_KEY]

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

        # all members optional
        try:
            aDict[self.HIGHPASS_KEY] = self.highPass
        except:
            pass

        try:
            aDict[self.LOWPASS_KEY] = self.lowPass
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

        # all members optional

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
            self.highPass
            return False
        except:
            pass

        try:
            self.highPass
            return False
        except:
            pass

        return True
