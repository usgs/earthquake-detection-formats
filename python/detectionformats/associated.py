#!/usr/bin/env python

#stdlib imports
import json

# a conversion class used to create, parse, and validate source data as part of
# detection data.
class Associated:
    PHASE_KEY = "Phase"
    DISTANCE_KEY = "Distance"
    AZIMUTH_KEY = "Azimuth"
    RESIDUAL_KEY = "Residual"
    SIGMA_KEY = "Sigma"

    # init
    def __init__(self, newPhase=None, newDistance=None, newAzimuth=None,
        newResidual=None, newSigma=None) :
        # all members optional
        if newPhase is not None:
            self.phase = newPhase
        if newDistance is not None:
            self.distance = newDistance
        if newAzimuth is not None:
            self.azimuth = newAzimuth
        if newResidual is not None:
            self.residual = newResidual
        if newSigma is not None:
            self.sigma = newSigma

    # populate class from a json string
    def fromJSONString(self, jsonString) :
            jsonObject = json.loads(jsonString)
            self.fromDict(jsonObject)

    # populate class from a dictonary
    def fromDict(self, aDict) :
        # all members optional
        if self.PHASE_KEY in aDict:
            self.phase = aDict[self.PHASE_KEY]
        if self.DISTANCE_KEY in aDict:
            self.distance = aDict[self.DISTANCE_KEY]
        if self.AZIMUTH_KEY in aDict:
            self.azimuth = aDict[self.AZIMUTH_KEY]
        if self.RESIDUAL_KEY in aDict:
            self.residual = aDict[self.RESIDUAL_KEY]
        if self.SIGMA_KEY in aDict:
            self.sigma = aDict[self.SIGMA_KEY]

    # convert class to a json string
    def toJSONString(self) :
        jsonObject = self.toDict()

        return json.dumps(jsonObject, ensure_ascii=False)

    # convert class to a dictonary
    def toDict(self) :
        aDict = {}

        # all members optional
        try:
            aDict[self.PHASE_KEY] = self.phase
        except:
            pass

        try:
            aDict[self.DISTANCE_KEY] = self.distance
        except:
            pass

        try:
            aDict[self.AZIMUTH_KEY] = self.azimuth
        except:
            pass

        try:
            aDict[self.RESIDUAL_KEY] = self.residual
        except:
            pass

        try:
            aDict[self.SIGMA_KEY] = self.sigma
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

        # optional
        # need to lookup how to check if something is a string and
        # if it's a letter

        # second optional keys
        try:
            if self.distance < 0:
                errorList.append('Invalid Distance in Associated Class.')
        except:
            pass

        try:
            if self.azimuth < 0:
                errorList.append('Invalid Azimuth in Associated Class.')
        except:
            pass

        return errorList

    # test to see if class is empty
    def isEmpty(self) :
        try:
            self.phase
            return False
        except:
            pass

        try:
            self.distance
            return False
        except:
            pass

        try:
            self.azimuth
            return False
        except:
            pass

        try:
            self.residual
            return False
        except:
            pass

        try:
            self.sigma
            return False
        except:
            pass

        return True
