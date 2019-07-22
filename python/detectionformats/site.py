#!/usr/bin/env python

#stdlib imports
import json

class Site:
    """ Site - a conversion class used to create, parse, and validate site data 
        as part of detection data.
    """
    # json keys
    STATION_KEY = "Station"
    CHANNEL_KEY = "Channel"
    NETWORK_KEY = "Network"
    LOCATION_KEY = "Location"
    LATITUDE_KEY = "Latitude"
    LONGITUDE_KEY = "Longitude"
    ELEVATION_KEY = "Elevation"

    def __init__(self, newStation=None, newNetwork=None, newChannel=None,
        newLocation=None, newLatitude=None, newLongitude=None,
        newElevation=None,):
        """Initialize the site object. Constructs an empty object
           if all arguments are None

        Args:
            newStation: a required String containing the station identifier
            newNetwork: a required String containing the network identifier
            newChannel: an optional String containing the channel code
            newLocation: an optional String containing the location code
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # first required keys
        if newStation is not None:
            self.station = newStation
        if newNetwork is not None:
            self.network = newNetwork

        # second optional keys
        if newChannel is not None:
            if newChannel != '':
                self.channel = newChannel

        if newLocation is not None:
            if newLocation != '':
                self.location = newLocation

        if newLatitude is not None:
            self.latitude = newLatitude
        if newLongitude is not None:
            self.longitude = newLongitude
        if newElevation is not None:
            self.elevation = newElevation

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
            self.station = aDict[self.STATION_KEY]
            self.network = aDict[self.NETWORK_KEY]
        except(ValueError, KeyError, TypeError) as e:
            print("Dict format error, missing required keys: %s" % e)

        # second optional keys
        if self.CHANNEL_KEY in aDict:
            self.channel = aDict[self.CHANNEL_KEY]
        if self.LOCATION_KEY in aDict:
            self.location = aDict[self.LOCATION_KEY]
        if self.LATITUDE_KEY in aDict:
            self.latitude = aDict[self.LATITUDE_KEY]
        if self.LONGITUDE_KEY in aDict:
            self.longitude = aDict[self.LONGITUDE_KEY]
        if self.ELEVATION_KEY in aDict:
            self.elevation = aDict[self.ELEVATION_KEY]


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
            aDict[self.STATION_KEY] = self.station
            aDict[self.NETWORK_KEY] = self.network
        except(NameError, AttributeError) as e:
            print("Missing required data error: %s" % e)

        # second optional keys
        if hasattr(self, 'channel'):
            if self.channel != '':
                aDict[self.CHANNEL_KEY] = self.channel

        if hasattr(self, 'location'):
            if self.location != '':
                aDict[self.LOCATION_KEY] = self.location

        if hasattr(self, 'latitude'):
            aDict[self.LATITUDE_KEY] = self.latitude

        if hasattr(self, 'longitude'):
            aDict[self.LONGITUDE_KEY] = self.longitude

        if hasattr(self, 'elevation'):
            aDict[self.ELEVATION_KEY] = self.elevation

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

        try:
            if self.station == '':
                errorList.append('Empty Station in Site Class.')
        except(NameError, AttributeError):
            errorList.append('No Station in Site Class.')

        try:
            if self.network == '':
                errorList.append('Empty Network in Site Class.')
        except(NameError, AttributeError):
            errorList.append('No Network in Site Class.')

        if hasattr(self, 'latitude'):
            if self.latitude < -90 or self.latitude > 90:
                errorList.append('Latitude in Site Class not in the range of -90 to 90.')

        if hasattr(self, 'longitude'):
            if self.longitude < -180 or self.longitude > 180:
                errorList.append('Longitude in Site Class not in the range of -180 to 180.')

        if hasattr(self, 'elevation'):
            if self.elevation < -550 or self.elevation > 8900:
                errorList.append('Elevation in Site Class not in the range of -550 to 8900.')

        return errorList
