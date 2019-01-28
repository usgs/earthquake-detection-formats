#!/usr/bin/env python

#stdlib imports
import json

# a conversion class used to create, parse, and validate eventtype data as part 
# of detection data.
class EventType:
    TYPE_KEY = "Type"
    CERTAINTY_KEY = "Certainty"

    # init
    def __init__(self, newType=None, newCertainty=None) :
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
        try:
            self.type = aDict[self.TYPE_KEY]
            self.certainty = aDict[self.CERTAINTY_KEY]

        except (ValueError, KeyError, TypeError):
            print ("Dict format error")

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
        try:
            aDict[self.TYPE_KEY] = self.type
            aDict[self.CERTAINTY_KEY] = self.certainty
        except NameError:
            print ("Missing data error")

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

        # optional values

        try:
            self.type
            if self.type != 'Earthquake' and self.type != 'MineCollapse' and self.type != 'NuclearExplosion' and self.type != 'QuarryBlast' and self.type != 'InducedOrTriggered' and self.type != 'RockBurst' and self.type != 'FluidInjection' and self.type != 'IceQuake' and self.type != 'VolcanicEruption':
                errorList.append('Invalid Type in EventType Class.')
        except (NameError, AttributeError):
            pass

        try:
            self.certainty
            if self.certainty != 'Suspected' and self.certainty != 'Confirmed':
                errorList.append('Invalid Certainty in EventType Class.')
        except (NameError, AttributeError):
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
            self.type
            return False
        except:
            pass

        try:
            self.certainty
            return False
        except:
            pass

        return True
