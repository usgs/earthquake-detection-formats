#!/usr/bin/env python

#stdlib imports
import json


class Source:
    """ Source - a conversion class used to create, parse, and validate source 
        data as part of detection data.
    """
    # json keys
    AGENCYID_KEY = "AgencyID"
    AUTHOR_KEY = "Author"

    def __init__(self, newAgencyID=None, newAuthor=None):
        """Initialize the source object. Constructs an empty object
           if all arguments are None

        Args:
            newAgencyID: a required String containing the agency identifier
            newAuthor: a required String containing the author name
        Returns:
            Nothing
        Raises:
            Nothing
        """
        if newAgencyID is not None:
            self.agencyID = newAgencyID
        if newAuthor is not None:
            self.author = newAuthor

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
            self.agencyID = aDict[self.AGENCYID_KEY]
            self.author = aDict[self.AUTHOR_KEY]

        except (ValueError, KeyError, TypeError):
            print ("Dict format error")

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
            aDict[self.AGENCYID_KEY] = self.agencyID
            aDict[self.AUTHOR_KEY] = self.author
        except NameError:
            print ("Missing data error")

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

        try:
            if self.agencyID == '':
                errorList.append('Empty AgencyID in Source Class.')
        except (NameError, AttributeError):
            errorList.append('No AgencyID in Source Class.')

        try:
            if self.author == '':
                errorList.append('Empty Author in Source Class.')
        except (NameError, AttributeError):
            errorList.append('No Author in Source Class.')

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
        if hasattr(self, 'agencyID'):
            return False

        if hasattr(self, 'author'):
            return False

        return True
