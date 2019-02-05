#!/usr/bin/env python

#package imports
import detectionformats.source
import detectionformats.site
import detectionformats.hypocenter
import detectionformats.eventtype
import detectionformats.association

#stdlib imports
import json
import datetime

class Correlation:
    """Correlation - a conversion class used to create, parse, and validate a 
        correlation as part of detection data.
    """
    # json keys
    TYPE_KEY = "Type"
    ID_KEY = "ID"
    SITE_KEY = "Site"
    SOURCE_KEY = "Source"
    PHASE_KEY = "Phase"
    TIME_KEY = "Time"
    CORRELATION_KEY = "Correlation"
    HYPOCENTER_KEY = "Hypocenter"
    EVENTTYPE_KEY = "EventType"
    MAGNITUDE_KEY = "Magnitude"
    SNR_KEY = "SNR"
    ZSCORE_KEY = "ZScore"
    DETECTIONTHRESHOLD_KEY = "DetectionThreshold"
    THRESHOLDTYPE_KEY = "ThresholdType"
    ASSOCIATIONINFO_KEY = "AssociationInfo"

    def __init__(self, newID=None, newSite=None, newSource=None, newPhase=None,
        newTime=None, newCorrelation=None, newHypocenter=None, newEventType=None,
        newMagnitude=None, newSNR=None, newZScore=None,
        newDetectionThreshold=None, newThresholdType=None,
        newAssociationInfo=None):
        """Initialize the correlation object. Constructs an empty object
           if all arguments are None

        Args:
            newID: a required String containing the desired ID
            newSite: a required detectionformats.site.Site containing the desired
                site
            newSource: a required detectionformats.source.Source containing the
                desired source
            newPhase: a required String containing the desired phase identifier
            newTime: a required datetime containing the correlation time
            newHypocenter: a required detectionformats.hypocenter.Hypocenter
                containing the desired hypocenter
            newEventType: an optional detectionformats.eventtype.EventType 
                containing the desired event type
            newMagnitude: an optional Number containing the desired magnitude
                estimate as a float
            newSNR: an optional Number containing the desired signal to noise
                measurement as a float
            newZScore: an optional Number containing the desired z score
                measurement as a float
            newDetectionThreshold: an optional Number containing the detection
                threshold used as a float
            newThresholdType: an optional String containing the type of detection
                threshold used
            newAssociationInfo: an optional detectionformats.association.Association
                containing association information
        Returns:
            Nothing
        Raises:
            Nothing
        """

        # first required keys
        self.type = 'Correlation'
        if newID is not None:
            self.id = newID

        if newSite is not None:
            self.site = newSite
        else:
            self.site = detectionformats.site.Site()

        if newSource is not None:
            self.source = newSource
        else:
            self.source = detectionformats.source.Source()

        if newPhase is not None:
            self.phase = newPhase

        if newTime is not None:
            self.time = newTime

        if newCorrelation is not None:
            self.correlation = newCorrelation

        if newHypocenter is not None:
            self.hypocenter = newHypocenter
        else:
            self.hypocenter = detectionformats.hypocenter.Hypocenter()

        # second optional keys
        if newEventType is not None:
            self.eventType = newEventType
        else:
            self.eventType = detectionformats.eventtype.EventType()

        if newMagnitude is not None:
            self.magnitude = newMagnitude

        if newSNR is not None:
            self.snr = newSNR

        if newZScore is not None:
            self.ZScore = newZScore

        if newDetectionThreshold is not None:
            self.detectionThreshold = newDetectionThreshold

        if newThresholdType is not None:
            self.thresholdType = newThresholdType

        if newAssociationInfo is not None:
            self.associationInfo = newAssociationInfo
        else:
            self.associationInfo = detectionformats.association.Association()

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
            self.type = aDict[self.TYPE_KEY]
            self.id = aDict[self.ID_KEY]
            self.site.fromDict(aDict[self.SITE_KEY])
            self.source.fromDict(aDict[self.SOURCE_KEY])
            self.phase = aDict[self.PHASE_KEY]
            timeString = aDict[self.TIME_KEY][:-1] + "000Z"
            self.time = datetime.datetime.strptime(timeString, "%Y-%m-%dT%H:%M:%S.%fZ")
            self.correlation = aDict[self.CORRELATION_KEY]
            self.hypocenter.fromDict(aDict[self.HYPOCENTER_KEY])
        except(ValueError, KeyError, TypeError) as e:
            print("Dict format error, missing required keys: %s" % e)

        # second optional keys
        if self.EVENTTYPE_KEY in aDict:
            self.eventType = detectionformats.eventtype.EventType()
            self.eventType.fromDict(aDict[self.EVENTTYPE_KEY])

        if self.MAGNITUDE_KEY in aDict:
            self.magnitude = aDict[self.MAGNITUDE_KEY]

        if self.SNR_KEY in aDict:
            self.snr = aDict[self.SNR_KEY]

        if self.ZSCORE_KEY in aDict:
            self.ZScore = aDict[self.ZSCORE_KEY]

        if self.DETECTIONTHRESHOLD_KEY in aDict:
            self.detectionThreshold = aDict[self.DETECTIONTHRESHOLD_KEY]

        if self.THRESHOLDTYPE_KEY in aDict:
            self.thresholdType = aDict[self.THRESHOLDTYPE_KEY]

        if self.ASSOCIATIONINFO_KEY in aDict:
            self.associationInfo = detectionformats.association.Association()
            self.associationInfo.fromDict(aDict[self.ASSOCIATIONINFO_KEY])

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
            aDict[self.TYPE_KEY] = self.type
            aDict[self.ID_KEY] = self.id
            aDict[self.SITE_KEY] = self.site.toDict()
            aDict[self.SOURCE_KEY] = self.source.toDict()
            aDict[self.PHASE_KEY] = self.phase
            timeString = self.time.isoformat(timespec='milliseconds') + "Z"
            aDict[self.TIME_KEY] = timeString
            aDict[self.CORRELATION_KEY] = self.correlation
            aDict[self.HYPOCENTER_KEY] = self.hypocenter.toDict()
        except(NameError, AttributeError) as e:
            print("Missing required data error: %s" % e)

        # second optional keys
        if hasattr(self, 'eventType'):
            if not self.eventType.isEmpty():
                aDict[self.EVENTTYPE_KEY] = self.eventType.toDict()

        if hasattr(self, 'magnitude'):
            aDict[self.MAGNITUDE_KEY] = self.magnitude

        if hasattr(self, 'snr'):
            aDict[self.SNR_KEY] = self.snr

        if hasattr(self, 'ZScore'):
            aDict[self.ZSCORE_KEY] = self.ZScore

        if hasattr(self, 'detectionThreshold'):
            aDict[self.DETECTIONTHRESHOLD_KEY] = self.detectionThreshold

        if hasattr(self, 'thresholdType'):
            aDict[self.THRESHOLDTYPE_KEY] = self.thresholdType

        if hasattr(self, 'associationInfo'):
            if not self.associationInfo.isEmpty():
                aDict[self.ASSOCIATIONINFO_KEY] = self.associationInfo.toDict()

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
            if self.type == '':
                errorList.append('Empty Type in Correlation Class.')
            elif self.type != 'Correlation':
                errorList.append('Non-Correlation Type in Correlation Class.')
        except(NameError, AttributeError):
            errorList.append('No Type in Correlation Class.')

        try:
            if self.id == '':
                errorList.append('Empty ID in Correlation Class.')
        except(NameError, AttributeError):
            errorList.append('No ID in Correlation Class.')

        try:
            if not self.site.isValid():
                errorList.append('Invalid Site in Correlation Class.')
        except(NameError, AttributeError):
            errorList.append('No Site in Correlation Class.')

        try:
            if not self.source.isValid():
                errorList.append('Invalid Source in Correlation Class.')
        except(NameError, AttributeError):
            errorList.append('No Source in Correlation Class.')

        try:
            self.phase
        except(NameError, AttributeError):
            errorList.append('No Phase in Correlation Class.')

        try:
            self.time
        except(NameError, AttributeError):
            errorList.append('No Time in Correlation Class.')

        try:
            if self.correlation < 0:
                errorList.append('Correlation in Correlation Class not in greater than 0.')
        except(NameError, AttributeError):
            errorList.append('No Correlation in Correlation Class.')

        try:
            if not self.hypocenter.isValid():
                errorList.append('Invalid Hypocenter in Correlation Class.')
        except(NameError, AttributeError):
            errorList.append('No Hypocenter in Correlation Class.')

        # optional values
        if hasattr(self, 'eventType'):
            if not self.eventType.isEmpty():
                if not self.eventType.isValid():
                    errorList.append('Invalid EventType in Correlation Class.')

        if hasattr(self, 'magnitude'):
            if self.magnitude < -2 or self.magnitude > 10:
                errorList.append('Magnitude in Correlation Class not in the range of -2 to 10.')

        if hasattr(self, 'thresholdType'):
            if self.thresholdType == '':
                errorList.append('Empty ThresholdType in Correlation Class.')

        if hasattr(self, 'associationInfo'):
            if not self.associationInfo.isEmpty():
                if not self.associationInfo.isValid():
                    errorList.append('Invalid AssociationInfo in Correlation Class.')

        return errorList
