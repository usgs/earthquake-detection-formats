#!/usr/bin/env python

#package imports
import detectionformats.source

#stdlib imports
import json

# a conversion class used to create, parse, and validate a retraction
# as part of detection data.
class Retract:
    TYPE_KEY = "Type"
    ID_KEY = "ID"
    SOURCE_KEY = "Source"

    # init
    def __init__(self, newID=None, newSource=None) :
        """Initialize the retract object. Constructs an empty object
           if all arguments are None

        Args:
            newID: a required String containing the desired ID
            newSource: a required detectionformats.source.Source containing the
                desired source
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # first required keys
        self.type = 'Retract'

        if newID is not None:
            self.id = newID

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
        # first required keys
        try:
            self.type = aDict[self.TYPE_KEY]
            self.id = aDict[self.ID_KEY]
            self.source.fromDict(aDict[self.SOURCE_KEY])
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

        # first required keys
        try:
            aDict[self.TYPE_KEY] = self.type
            aDict[self.ID_KEY] = self.id
            aDict[self.SOURCE_KEY] = self.source.toDict()
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

        try:
            if self.type == '':
                errorList.append('Empty Type in Retract Class.')
            elif self.type != 'Retract':
                errorList.append('Non-Retract Type in Retract Class.')
        except (NameError, AttributeError):
            errorList.append('No Type in Retract Class.')

        try:
            if self.id == '':
                errorList.append('Empty ID in Retract Class.')
        except (NameError, AttributeError):
            errorList.append('No ID in Retract Class.')

        try:
            if self.source.isValid() == False:
                errorList.append('Invalid Source in Retract Class.')
        except (NameError, AttributeError):
            errorList.append('No Source in Retract Class.')

        return errorList
