#!/usr/bin/env python

# stdlib imports
import json


class Filter:
    """Filter - a conversion class used to create, parse, and validate filter
    data as part of detection data.
    """

    # json keys
    TYPE_KEY = "Type"
    HIGHPASS_KEY = "HighPass"
    LOWPASS_KEY = "LowPass"
    UNITS_KEY = "Units"

    def __init__(self, newType=None, newHighPass=None, newLowPass=None, newUnits=None):
        """Initialize the filter object. Constructs an empty object
           if all arguments are None

        Args:
            newType: an optional String containing the type of the filter
                method
            newHighPass: an optional Number containing the desired filter high
                pass value as a float
            newLowPass: an optional Number containing the desired filter low
                pass value as a float
            newUnits: an optional String containing the units of the filter
                method
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # all members optional
        if newType is not None:
            self.type = newType
        if newHighPass is not None:
            self.highPass = newHighPass
        if newLowPass is not None:
            self.lowPass = newLowPass
        if newUnits is not None:
            self.units = newUnits

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
        if self.TYPE_KEY in aDict:
            self.type = aDict[self.TYPE_KEY]
        if self.HIGHPASS_KEY in aDict:
            self.highPass = aDict[self.HIGHPASS_KEY]
        if self.LOWPASS_KEY in aDict:
            self.lowPass = aDict[self.LOWPASS_KEY]
        if self.UNITS_KEY in aDict:
            self.units = aDict[self.UNITS_KEY]

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
        if hasattr(self, "type"):
            aDict[self.TYPE_KEY] = self.type

        if hasattr(self, "highPass"):
            aDict[self.HIGHPASS_KEY] = self.highPass

        if hasattr(self, "lowPass"):
            aDict[self.LOWPASS_KEY] = self.lowPass

        if hasattr(self, "units"):
            aDict[self.UNITS_KEY] = self.units

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

        # all members optional

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
        if hasattr(self, "type"):
            return False

        if hasattr(self, "highPass"):
            return False

        if hasattr(self, "lowPass"):
            return False

        if hasattr(self, "units"):
            return False

        return True
