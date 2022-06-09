#!/usr/bin/env python

# stdlib imports
import json
import datetime


class Hypocenter:
    """Hypocenter - a conversion class used to create, parse, and validate
    hypocenter data as part of detection data.
    """

    # json keys
    LATITUDE_KEY = "Latitude"
    LONGITUDE_KEY = "Longitude"
    DEPTH_KEY = "Depth"
    TIME_KEY = "Time"
    LATITUDE_ERROR_KEY = "LatitudeError"
    LONGITUDE_ERROR_KEY = "LongitudeError"
    DEPTH_ERROR_KEY = "DepthError"
    TIME_ERROR_KEY = "TimeError"

    def __init__(
        self,
        newLatitude=None,
        newLongitude=None,
        newDepth=None,
        newTime=None,
        newLatitudeError=None,
        newLongitudeError=None,
        newDepthError=None,
        newTimeError=None,
    ):
        """Initialize the hypocenter object. Constructs an empty object
           if all arguments are None

        Args:
            newLatitude: a required Number containing the latitude as a float in
                degrees
            newLongitude: a required Number containing the longitude as a float
                in degrees
            newDepth: a required Number containing the depth as a float in km
            newTime: a required datetime containing the correlation time
            newMagnitude: an optional Number containing the desired magnitude
                estimate as a float
            newLatitudeError: an optional Number containing the latitude error
                measurement as a float
            newLongitudeError: an optional Number containing the longitude error
                measurement as a float
            newDepthError: an optional Number containing the depth error
                measurement as a float
            newTimeError: an optional Number containing the time error measurement
                as a float
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # first required keys
        if newLatitude is not None:
            self.latitude = newLatitude
        if newLongitude is not None:
            self.longitude = newLongitude
        if newDepth is not None:
            self.depth = newDepth
        if newTime is not None:
            self.time = newTime

        # second optional keys
        if newLatitudeError is not None:
            self.latitudeError = newLatitudeError

        if newLongitudeError is not None:
            self.longitudeError = newLongitudeError

        if newDepthError is not None:
            self.depthError = newDepthError

        if newTimeError is not None:
            self.timeError = newTimeError

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
            self.latitude = aDict[self.LATITUDE_KEY]
            self.longitude = aDict[self.LONGITUDE_KEY]
            self.depth = aDict[self.DEPTH_KEY]
            timeString = aDict[self.TIME_KEY][:-1] + "000Z"
            self.time = datetime.datetime.strptime(timeString, "%Y-%m-%dT%H:%M:%S.%fZ")
        except (ValueError, KeyError, TypeError) as e:
            print("Dict format error, missing required keys: %s" % e)

        # second optional keys
        if self.LATITUDE_ERROR_KEY in aDict:
            self.latitudeError = aDict[self.LATITUDE_ERROR_KEY]

        if self.LONGITUDE_ERROR_KEY in aDict:
            self.longitudeError = aDict[self.LONGITUDE_ERROR_KEY]

        if self.DEPTH_ERROR_KEY in aDict:
            self.depthError = aDict[self.DEPTH_ERROR_KEY]

        if self.TIME_ERROR_KEY in aDict:
            self.timeError = aDict[self.TIME_ERROR_KEY]

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
            aDict[self.LATITUDE_KEY] = self.latitude
            aDict[self.LONGITUDE_KEY] = self.longitude
            aDict[self.DEPTH_KEY] = self.depth
            timeString = self.time.isoformat(timespec="milliseconds") + "Z"
            aDict[self.TIME_KEY] = timeString
        except (NameError, AttributeError) as e:
            print("Missing required data error: %s" % e)

        # second optional keys
        if hasattr(self, "latitudeError"):
            aDict[self.LATITUDE_ERROR_KEY] = self.latitudeError

        if hasattr(self, "longitudeError"):
            aDict[self.LONGITUDE_ERROR_KEY] = self.longitudeError

        if hasattr(self, "depthError"):
            aDict[self.DEPTH_ERROR_KEY] = self.depthError

        if hasattr(self, "timeError"):
            aDict[self.TIME_ERROR_KEY] = self.timeError

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

        # required values
        try:
            if self.latitude < -90 or self.latitude > 90:
                errorList.append(
                    "Latitude in Hypocenter Class not in the range of -90 to 90."
                )
        except (NameError, AttributeError):
            errorList.append("No Latitude in Hypocenter Class.")

        try:
            if self.longitude < -180 or self.longitude > 180:
                errorList.append(
                    "Longitude in Hypocenter Class not in the range of -180 to 180."
                )
        except (NameError, AttributeError):
            errorList.append("No Longitude in Hypocenter Class.")

        try:
            if self.depth < -100 or self.depth > 1500:
                errorList.append(
                    "Depth in Hypocenter Class not in the range of -100 to 1500."
                )
        except (NameError, AttributeError):
            errorList.append("No Depth in Hypocenter Class.")

        return errorList
