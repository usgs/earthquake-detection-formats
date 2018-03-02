#!/usr/bin/env python

#stdlib imports
import json

# a conversion class used to create, parse, and validate source data as part of
# detection data.
class Amplitude:
    AMPLITUDE_KEY = "Amplitude"
    PERIOD_KEY = "Period"
    SNR_KEY = "SNR"

    # init
    def __init__(self, newAmplitude=None, newPeriod=None, newSNR=None) :
        if newAmplitude is not None:
            self.amplitude = newAmplitude
        if newPeriod is not None:
            self.period = newPeriod
        if newSNR is not None:
            self.snr = newSNR

    # populate class from a json string
    def fromJSONString(self, jsonString) :
            jsonObject = json.loads(jsonString)
            self.fromDict(jsonObject)

    # populate class from a dictonary
    def fromDict(self, aDict) :
        if self.AMPLITUDE_KEY in aDict:
            self.amplitude = aDict[self.AMPLITUDE_KEY]
        if self.PERIOD_KEY in aDict:
            self.period = aDict[self.PERIOD_KEY]
        if self.SNR_KEY in aDict:
            self.snr = aDict[self.SNR_KEY]

    # convert class to a json string
    def toJSONString(self) :
        jsonObject = self.toDict()

        return json.dumps(jsonObject, ensure_ascii=False)

    # convert class to a dictonary
    def toDict(self) :
        aDict = {}
        try:
            aDict[self.AMPLITUDE_KEY] = self.amplitude
        except:
            pass

        try:
            aDict[self.PERIOD_KEY] = self.period
        except:
            pass

        try:
            aDict[self.SNR_KEY] = self.snr
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

        # all members are optional

        return errorList

    # test to see if class is empty
    def isEmpty(self) :
        try:
            self.amplitude
            return False
        except:
            pass

        try:
            self.period
            return False
        except:
            pass

        try:
            self.snr
            return False
        except:
            pass

        return True
