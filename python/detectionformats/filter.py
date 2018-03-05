#!/usr/bin/env python

#stdlib imports
import json

# a conversion class used to create, parse, and validate filter data as part of
# detection data.
class Filter:
    HIGHPASS_KEY = "HighPass"
    LOWPASS_KEY = "LowPass"

    # init
    def __init__(self, newHighPass=None, newLowPass=None) :
        # all members optional
        if newHighPass is not None:
            self.highPass = newHighPass
        if newLowPass is not None:
            self.lowPass = newLowPass

    # populate class from a json string
    def fromJSONString(self, jsonString) :
            jsonObject = json.loads(jsonString)
            self.fromDict(jsonObject)

    # populate class from a dictonary
    def fromDict(self, aDict) :
        # all members optional
        if self.HIGHPASS_KEY in aDict:
            self.highPass = aDict[self.HIGHPASS_KEY]
        if self.LOWPASS_KEY in aDict:
            self.lowPass = aDict[self.LOWPASS_KEY]

    # convert class to a json string
    def toJSONString(self) :
        jsonObject = self.toDict()

        return json.dumps(jsonObject, ensure_ascii=False)

    # convert class to a dictonary
    def toDict(self) :
        aDict = {}

        # all members optional
        try:
            aDict[self.HIGHPASS_KEY] = self.highPass
        except:
            pass

        try:
            aDict[self.LOWPASS_KEY] = self.lowPass
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

        # all members optional

        return errorList

    # test to see if class is empty
    def isEmpty(self) :
        try:
            self.highPass
            return False
        except:
            pass

        try:
            self.highPass
            return False
        except:
            pass

        return True
