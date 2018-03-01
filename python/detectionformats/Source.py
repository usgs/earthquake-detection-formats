#!/usr/bin/env python

#stdlib imports
import json

# a conversion class used to create, parse, and validate source data as part of
# detection data.
class Source:
    agencyID_key = "AgencyID"
    author_key = "Author"

    # init
    def __init__(self, newAgencyID, newAuthor) :
        self.agencyID = newAgencyID
        self.author = newAuthor

    # populate class from json
    def fromJSON(self, jsonString) :
        try:
            jsonObject = json.loads(jsonString)

            self.agencyID = jsonObject["AgencyID"]
            self.author = jsonObject["Author"]

        except (ValueError, KeyError, TypeError):
            print ("JSON format error")

    # convert class to json
    def toJSON(self) :
        jsonObject = {}
        try:
            jsonObject["AgencyID"] = self.agencyID
            jsonObject["Author"] = self.author
        except NameError:
            print ("Missing data error")

        return json.dumps(jsonObject, ensure_ascii=False)

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
