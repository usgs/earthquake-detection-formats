#!/usr/bin/env python

#stdlib imports
import json

# a conversion class used to create, parse, and validate source data as part of
# detection data.
class Source:
    AGENCYID_KEY = "AgencyID"
    AUTHOR_KEY = "Author"

    # init
    def __init__(self, newAgencyID, newAuthor) :
        self.agencyID = newAgencyID
        self.author = newAuthor

    # populate class from a json string
    def fromJSONString(self, jsonString) :
            jsonObject = json.loads(jsonString)
            self.fromDict(jsonObject)

    # populate class from a dictonary
    def fromDict(self, aDict) :
        try:
            self.agencyID = aDict[self.AGENCYID_KEY]
            self.author = aDict[self.AUTHOR_KEY]

        except (ValueError, KeyError, TypeError):
            print ("Dict format error")

    # convert class to a json string
    def toJSONString(self) :
        jsonObject = self.toDict()

        return json.dumps(jsonObject, ensure_ascii=False)

    # convert class to a dictonary
    def toDict(self) :
        aDict = {}
        try:
            aDict[self.AGENCYID_KEY] = self.agencyID
            aDict[self.AUTHOR_KEY] = self.author
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
            self.agencyID
        except NameError:
            errorList.append('No AgencyID in Source Class.')

        if self.agencyID == '':
            errorList.append('Empty AgencyID in Source Class.')

        try:
            self.author
        except NameError:
            errorList.append('No Author in Source Class.')

        if self.author == '':
            errorList.append('Empty Author in Source Class.')

        return errorList
