#!/usr/bin/env python

#package imports
import detectionformats.site
import detectionformats.source

#stdlib imports
import json

# a conversion class used to create, parse, and validate station info data as
# part of detection data.
class StationInfo:
    TYPE_KEY = "Type"
    SITE_KEY = "Site"
    LATITUDE_KEY = "Latitude"
    LONGITUDE_KEY = "Longitude"
    ELEVATION_KEY = "Elevation"
    QUALITY_KEY = "Quality"
    ENABLE_KEY = "Enable"
    USEFORTELESEISMIC_KEY = "UseForTeleseismic"
    INFORMATIONREQUESTOR_KEY = "InformationRequestor"

    # init
    def __init__(self, newSite, newLatitude, newLongitude, newElevation,
        newQuality=None, newEnable=None, newUseForTeleseismic=None,
        newInformationRequestor=None) :
        # first required keys
        self.type = 'StationInfo'
        self.site = newSite
        self.latitude = newLatitude
        self.longitude = newLongitude
        self.elevation = newElevation

        # second optional keys
        if newQuality is not None:
            self.quality = newQuality

        if newEnable is not None:
            self.enable = newEnable

        if newUseForTeleseismic is not None:
            self.useForTeleseismic = newUseForTeleseismic

        if newInformationRequestor is not None:
            self.informationRequestor = newInformationRequestor

    # populate class from a json string
    def fromJSONString(self, jsonString) :
        jsonObject = json.loads(jsonString)
        self.fromDict(jsonObject)

    # populate class from a dictonary
    def fromDict(self, aDict) :
        # first required keys
        try:
            self.type = aDict[self.TYPE_KEY]
            self.site.fromDict(aDict[self.SITE_KEY])
            self.latitude = aDict[self.LATITUDE_KEY]
            self.longitude = aDict[self.LONGITUDE_KEY]
            self.elevation = aDict[self.ELEVATION_KEY]
        except (ValueError, KeyError, TypeError):
            print ("Dict format error")

        # second optional keys
        if self.QUALITY_KEY in aDict:
            self.quality = aDict[self.QUALITY_KEY]

        if self.ENABLE_KEY in aDict:
            self.enable = aDict[self.ENABLE_KEY]

        if self.USEFORTELESEISMIC_KEY in aDict:
            self.useForTeleseismic = aDict[self.USEFORTELESEISMIC_KEY]

        if self.INFORMATIONREQUESTOR_KEY in aDict:
            self.informationRequestor.fromDict(aDict[self.INFORMATIONREQUESTOR_KEY])

    # convert class to a json string
    def toJSONString(self) :
        jsonObject = self.toDict()

        return json.dumps(jsonObject, ensure_ascii=False)

    # convert class to a dictonary
    def toDict(self) :
        aDict = {}

        # first required keys
        try:
            aDict[self.TYPE_KEY] = self.type
            aDict[self.SITE_KEY] = self.site.toDict()
            aDict[self.LATITUDE_KEY] = self.latitude
            aDict[self.LONGITUDE_KEY] = self.longitude
            aDict[self.ELEVATION_KEY] = self.elevation
        except NameError:
            print ("Missing data error")

        # second optional keys
        try:
            aDict[self.QUALITY_KEY] = self.quality
        except:
            pass

        try:
            aDict[self.ENABLE_KEY] = self.enable
        except:
            pass

        try:
            aDict[self.USEFORTELESEISMIC_KEY] = self.useForTeleseismic
        except:
            pass

        try:
            aDict[self.INFORMATIONREQUESTOR_KEY] = self.informationRequestor.toDict()
        except:
            pass

        return aDict

    # test to see if class is valid
    def isValid(self) :
        errorList = self.getErrors()

        if len(errorList) == 0:
            return True
        else:
            return False

    # get list of validation errors
    def getErrors(self) :
        errorList = []

        try:
            self.type
        except NameError:
            errorList.append('No Type in StationInfo Class.')

        if self.type == '':
            errorList.append('Empty Type in StationInfo Class.')
        elif self.type != 'StationInfo':
            errorList.append('Non-StationInfo Type in StationInfo Class.')

        try:
            self.site
        except NameError:
            errorList.append('No Site in StationInfo Class.')

        if self.site.isValid() == False:
            errorList.append('Invalid Site in StationInfo Class.')

        try:
            self.latitude
        except NameError:
            errorList.append('No Latitude in StationInfo Class.')

        if self.latitude < -90 or self.latitude > 90:
            errorList.append('Latitude in StationInfo Class not in the range of -90 to 90.')

        try:
            self.longitude
        except NameError:
            errorList.append('No Longitude in StationInfo Class.')

        if self.longitude < -180 or self.longitude > 180:
            errorList.append('Longitude in StationInfo Class not in the range of -180 to 180.')

        try:
            self.elevation
        except NameError:
            errorList.append('No Elevation in StationInfo Class.')

        try:
            self.informationRequestor
        except NameError:
            pass

        if self.informationRequestor.isValid() == False:
            errorList.append('Invalid InformationRequestor in StationInfo Class.')

        return errorList
