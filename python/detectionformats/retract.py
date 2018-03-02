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
    def __init__(self, newID, newSource) :
        # first required keys
        self.type = 'Retract'
        self.id = newID
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
            self.id = aDict[self.ID_KEY]
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
            aDict[self.ID_KEY] = self.id
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
            errorList.append('No Type in Retract Class.')

        if self.type == '':
            errorList.append('Empty Type in Retract Class.')
        elif self.type != 'Retract':
            errorList.append('Non-Retract Type in Retract Class.')

        try:
            self.id
        except NameError:
            errorList.append('No ID in Retract Class.')

        if self.id == '':
            errorList.append('Empty ID in Retract Class.')

        try:
            self.source
        except NameError:
            errorList.append('No Source in Retract Class.')

        if self.source.isValid() == False:
            errorList.append('Invalid Source in Retract Class.')

        return errorList
