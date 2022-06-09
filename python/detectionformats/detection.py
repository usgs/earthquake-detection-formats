#!/usr/bin/env python

# package imports
import detectionformats.source
import detectionformats.pick
import detectionformats.correlation

# stdlib imports
import json
import datetime


class Detection:
    """Detection - a conversion class used to create, parse, and validate a
    Detection as part of detection data.
    """

    # json keys
    TYPE_KEY = "Type"
    ID_KEY = "ID"
    SOURCE_KEY = "Source"
    HYPOCENTER_KEY = "Hypocenter"
    DETECTIONTYPE_KEY = "DetectionType"
    EVENTTYPE_KEY = "EventType"
    DETECTIONTIME_KEY = "DetectionTime"
    BAYES_KEY = "Bayes"
    MINIMUMDISTANCE_KEY = "MinimumDistance"
    RMS_KEY = "RMS"
    GAP_KEY = "Gap"
    DATA_KEY = "Data"
    DETECTOR_KEY = "Detector"

    def __init__(
        self,
        newID=None,
        newSource=None,
        newHypocenter=None,
        newDetectionType=None,
        newEventType=None,
        newDetectionTime=None,
        newBayes=None,
        newMinimumDistance=None,
        newRMS=None,
        newGap=None,
        newDetector=None,
        newPickData=None,
        newCorrelationData=None,
    ):
        """Initialize the detection object. Constructs an empty object
           if all arguments are None

        Args:
            newID: a required String containing the desired ID
            newSource: a required detectionformats.source.Source containing the
                desired source
            newHypocenter: a required detectionformats.hypocenter.Hypocenter
                containing the desired hypocenter
            newDetectionType: an optional String containing the desired detection
                type
            newEventType: an optional detectionformats.eventtype.EventType
                containing the desired event type
            newDetectionTime: an optional datetime containing the time this
                detection was made
            newBayes: an optional Number containing the desired bayes estimate
                as a float
            newMinimumDistance: an optional Number containing the desired
                minimum Distance measurement as a float
            newRMS: an optional Number containing the desired RMS estimate as a
                float
            newGap: an optional Number containing the gap estimate as a float
            newDetector: an optioanl String containing the detection method
            newPickData: an optional array of detectionformats.pick.Pick objects
                that support this detection
            newCorrelationData: an optional array of
                detectionformats.correlation.Correlation objects that support
                this detection
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # first required keys
        self.type = "Detection"
        if newID is not None:
            self.id = newID

        if newSource is not None:
            self.source = newSource
        else:
            self.source = detectionformats.source.Source()

        if newHypocenter is not None:
            self.hypocenter = newHypocenter
        else:
            self.hypocenter = detectionformats.hypocenter.Hypocenter()

        # second optional keys
        if newDetectionType is not None:
            self.detectionType = newDetectionType

        if newEventType is not None:
            self.eventType = newEventType
        else:
            self.eventType = detectionformats.eventtype.EventType()

        if newDetectionTime is not None:
            self.detectionTime = newDetectionTime

        if newBayes is not None:
            self.bayes = newBayes

        if newMinimumDistance is not None:
            self.minimumDistance = newMinimumDistance

        if newRMS is not None:
            self.rms = newRMS

        if newGap is not None:
            self.gap = newGap

        if newDetector is not None:
            self.detector = newDetector

        if newPickData is not None:
            if newPickData and len(newPickData) > 0:
                self.pickData = newPickData

        if newCorrelationData is not None:
            if newCorrelationData and len(newCorrelationData) > 0:
                self.correlationData = newCorrelationData

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
            self.source.fromDict(aDict[self.SOURCE_KEY])
            self.hypocenter.fromDict(aDict[self.HYPOCENTER_KEY])
        except (ValueError, KeyError, TypeError) as e:
            print("Dict format error, missing required keys: %s" % e)

        # second optional keys
        if self.DETECTIONTYPE_KEY in aDict:
            self.detectionType = aDict[self.DETECTIONTYPE_KEY]

        if self.EVENTTYPE_KEY in aDict:
            self.eventType = detectionformats.eventtype.EventType()
            self.eventType.fromDict(aDict[self.EVENTTYPE_KEY])

        if self.DETECTIONTIME_KEY in aDict:
            timeString = aDict[self.DETECTIONTIME_KEY][:-1] + "000Z"
            self.detectionTime = datetime.datetime.strptime(
                timeString, "%Y-%m-%dT%H:%M:%S.%fZ"
            )

        if self.BAYES_KEY in aDict:
            self.bayes = aDict[self.BAYES_KEY]

        if self.MINIMUMDISTANCE_KEY in aDict:
            self.minimumDistance = aDict[self.MINIMUMDISTANCE_KEY]

        if self.RMS_KEY in aDict:
            self.rms = aDict[self.RMS_KEY]

        if self.GAP_KEY in aDict:
            self.gap = aDict[self.GAP_KEY]

        if self.DETECTOR_KEY in aDict:
            self.detector = aDict[self.DETECTOR_KEY]

        if self.DATA_KEY in aDict:
            aDataList = aDict[self.DATA_KEY]
            if aDataList:
                self.pickData = []
                self.correlationData = []
                for aData in aDataList:
                    if self.TYPE_KEY in aData:
                        if aData[self.TYPE_KEY] == "Pick":
                            newPick = detectionformats.pick.Pick()
                            newPick.fromDict(aData)
                            self.pickData.append(newPick)
                        elif aData[self.TYPE_KEY] == "Correlation":
                            newCorrelation = detectionformats.correlation.Correlation()
                            newCorrelation.fromDict(aData)
                            self.correlationData.append(newCorrelation)

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
            aDict[self.SOURCE_KEY] = self.source.toDict()
            aDict[self.HYPOCENTER_KEY] = self.hypocenter.toDict()
        except (NameError, AttributeError) as e:
            print("Missing required data error: %s" % e)

        # second optional keys
        if hasattr(self, "detectionType"):
            aDict[self.DETECTIONTYPE_KEY] = self.detectionType

        if hasattr(self, "eventType"):
            if not self.eventType.isEmpty():
                aDict[self.EVENTTYPE_KEY] = self.eventType.toDict()

        if hasattr(self, "detectionTime"):
            timeString = self.detectionTime.isoformat(timespec="milliseconds") + "Z"
            aDict[self.DETECTIONTIME_KEY] = timeString

        if hasattr(self, "bayes"):
            aDict[self.BAYES_KEY] = self.bayes

        if hasattr(self, "minimumDistance"):
            aDict[self.MINIMUMDISTANCE_KEY] = self.minimumDistance

        if hasattr(self, "rms"):
            aDict[self.RMS_KEY] = self.rms

        if hasattr(self, "gap"):
            aDict[self.GAP_KEY] = self.gap

        if hasattr(self, "detector"):
            aDict[self.DETECTOR_KEY] = self.detector

        aDataList = []
        if hasattr(self, "pickData"):
            if self.pickData and len(self.pickData) > 0:
                for aPick in self.pickData:
                    aDataList.append(aPick.toDict())

        if hasattr(self, "correlationData"):
            if self.correlationData and len(self.correlationData) > 0:
                for aCorrelation in self.correlationData:
                    aDataList.append(aCorrelation.toDict())

        aDict[self.DATA_KEY] = aDataList

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
            if self.type == "":
                errorList.append("Empty Type in Detection Class.")
            elif self.type != "Detection":
                errorList.append("Non-Detection Type in Detection Class.")
        except (NameError, AttributeError):
            errorList.append("No Type in Detection Class.")

        try:
            if self.id == "":
                errorList.append("Empty ID in Detection Class.")
        except (NameError, AttributeError):
            errorList.append("No ID in Detection Class.")

        try:
            if not self.source.isValid():
                errorList.append("Invalid Source in Detection Class.")
        except (NameError, AttributeError):
            errorList.append("No Source in Detection Class.")

        try:
            if not self.hypocenter.isValid():
                errorList.append("Invalid Hypocenter in Detection Class.")
        except (NameError, AttributeError):
            errorList.append("No Hypocenter in Detection Class.")

        # optional values
        if hasattr(self, "detectionType"):
            if self.detectionType not in ["New", "Update", "Final", "Retract"]:
                errorList.append("Invalid DetectionType in Detection Class.")

        if hasattr(self, "eventType"):
            if not self.eventType.isEmpty():
                if not self.eventType.isValid():
                    errorList.append("Invalid EventType in Detection Class.")

        if hasattr(self, "bayes"):
            if self.bayes < 0:
                errorList.append("Bayes in Detection Class not in greater than 0.")

        if hasattr(self, "minimumDistance"):
            if self.minimumDistance < 0:
                errorList.append(
                    "MinimumDistance in Detection Class not in greater than 0."
                )

        if hasattr(self, "gap"):
            if self.gap < 0 or self.gap > 360:
                errorList.append("Gap in Detection Class not in the range of 0 to 360.")

        if hasattr(self, "pickData"):
            if self.pickData and len(self.pickData) > 0:
                for aPick in self.pickData:
                    if not aPick.isValid():
                        errorList.append("Invalid Pick in Detection Class.")

        if hasattr(self, "correlationData"):
            if self.correlationData and len(self.correlationData) > 0:
                for aCorrelation in self.correlationData:
                    if not aCorrelation.isValid():
                        errorList.append("Invalid Correlation in Detection Class.")

        return errorList
