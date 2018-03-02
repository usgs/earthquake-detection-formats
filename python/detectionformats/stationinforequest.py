#!/usr/bin/env python

#package imports
import detectionformats.site
import detectionformats.source

#stdlib imports
import json

# a conversion class used to create, parse, and validate a station info request
# as part of detection data.
class StationInfoRequest:
    TYPE_KEY = "Type"
    SITE_KEY = "Site"
    SOURCE_KEY = "Source"

    # init
    def __init__(self, newSite, newSource) :
        # first required keys
        self.type = 'StationInfoRequest'
        self.site = newSite
        self.source = newSource

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
            self.source.fromDict(aDict[self.SOURCE_KEY])
        except (ValueError, KeyError, TypeError):
            print ("Dict format error")

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
            aDict[self.SOURCE_KEY] = self.source.toDict()
        except NameError:
            print ("Missing data error")

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
            errorList.append('No Type in StationInfoRequest Class.')

        if self.type == '':
            errorList.append('Empty Type in StationInfoRequest Class.')
        elif self.type != 'StationInfoRequest':
            errorList.append('Non-StationInfoRequest Type in StationInfoRequest Class.')

        try:
            self.site
        except NameError:
            errorList.append('No Site in StationInfoRequest Class.')

        if self.site.isValid() == False:
            errorList.append('Invalid Site in StationInfoRequest Class.')

        try:
            self.source
        except NameError:
            errorList.append('No Source in StationInfoRequest Class.')

        if self.source.isValid() == False:
            errorList.append('Invalid Source in StationInfoRequest Class.')

        return errorList
