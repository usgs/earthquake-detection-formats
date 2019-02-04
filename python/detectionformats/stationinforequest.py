#!/usr/bin/env python

#package imports
import detectionformats.site
import detectionformats.source

#stdlib imports
import json


class StationInfoRequest:
    """ StationInfoRequest - a conversion class used to create, parse, and 
        validate a station info request as part of detection data.
    """
    # json keys
    TYPE_KEY = "Type"
    SITE_KEY = "Site"
    SOURCE_KEY = "Source"

    def __init__(self, newSite=None, newSource=None):
        """Initialize the station info request object. Constructs an empty object
           if all arguments are None

        Args:
            newSite: a required detectionformats.site.Site containing the desired
                site
            newSource: a required detectionformats.source.Source containing the
                desired source
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # required keys
        self.type = 'StationInfoRequest'

        if newSite is not None:
            self.site = newSite
        else:
            self.site = detectionformats.site.Site()
            
        if newSource is not None:
            self.source = newSource
        else:
            self.source = detectionformats.source.Source()

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
            self.type = aDict[self.TYPE_KEY]
            self.site.fromDict(aDict[self.SITE_KEY])
            self.source.fromDict(aDict[self.SOURCE_KEY])
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

        # first required keys
        try:
            aDict[self.TYPE_KEY] = self.type
            aDict[self.SITE_KEY] = self.site.toDict()
            aDict[self.SOURCE_KEY] = self.source.toDict()
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
            if self.type == '':
                errorList.append('Empty Type in StationInfoRequest Class.')
            elif self.type != 'StationInfoRequest':
                errorList.append('Non-StationInfoRequest Type in StationInfoRequest Class.')
        except (NameError, AttributeError):
            errorList.append('No Type in StationInfoRequest Class.')

        try:
            if self.site.isValid() == False:
                errorList.append('Invalid Site in StationInfoRequest Class.')
        except (NameError, AttributeError):
            errorList.append('No Site in StationInfoRequest Class.')

        try:
            if self.source.isValid() == False:
                errorList.append('Invalid Source in StationInfoRequest Class.')
        except (NameError, AttributeError):
            errorList.append('No Source in StationInfoRequest Class.')

        return errorList
