#!/usr/bin/env python

# stdlib imports
import json


class EventType:
    """EventType - a conversion class used to create, parse, and validate
    event type data as part of detection data.
    """

    # json keys
    TYPE_KEY = "Type"
    CERTAINTY_KEY = "Certainty"

    def __init__(self, newType=None, newCertainty=None):
        """Initialize the event type object. Constructs an empty object
           if all arguments are None

        Args:
            newType: an optional String containing the event type to use
            newCertainty: an optional String containing the certainty to use
        Returns:
            Nothing
        Raises:
            Nothing
        """
        if newType is not None:
            self.type = newType
        if newCertainty is not None:
            self.certainty = newCertainty

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
        try:
            self.type = aDict[self.TYPE_KEY]
            self.certainty = aDict[self.CERTAINTY_KEY]
        except (ValueError, KeyError, TypeError) as e:
            print("Dict format error, missing required keys: %s" % e)

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
        try:
            aDict[self.TYPE_KEY] = self.type
            aDict[self.CERTAINTY_KEY] = self.certainty
        except (NameError, AttributeError) as e:
            print("Missing required data error: %s" % e)

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

        # optional values
        if hasattr(self, "type"):
            if self.type not in [
                "Earthquake",
                "MineCollapse",
                "NuclearExplosion",
                "QuarryBlast",
                "InducedOrTriggered",
                "RockBurst",
                "FluidInjection",
                "IceQuake",
                "VolcanicEruption",
            ]:
                errorList.append("Invalid Type in EventType Class.")

        if hasattr(self, "certainty"):
            if self.certainty not in ["Suspected", "Confirmed"]:
                errorList.append("Invalid Certainty in EventType Class.")

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

        if hasattr(self, "certainty"):
            return False

        return True
