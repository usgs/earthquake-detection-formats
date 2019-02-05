#!/usr/bin/env python

#package imports
import detectionformats.source
import detectionformats.site
import detectionformats.beam
import detectionformats.filter
import detectionformats.amplitude
import detectionformats.association
import detectionformats.classification

#stdlib imports
import json
import datetime

class Pick:
    """ Pick - a conversion class used to create, parse, and validate a pick
        as part of detection data.
    """
    # json keys
    TYPE_KEY = "Type"
    ID_KEY = "ID"
    SITE_KEY = "Site"
    SOURCE_KEY = "Source"
    TIME_KEY = "Time"
    PHASE_KEY = "Phase"
    POLARITY_KEY = "Polarity"
    ONSET_KEY = "Onset"
    PICKER_KEY = "Picker"
    FILTER_KEY = "Filter"
    AMPLITUDE_KEY = "Amplitude"
    BEAM_KEY = "Beam"
    ASSOCIATIONINFO_KEY = "AssociationInfo"
    CLASSIFICATIONINFO_KEY = "ClassificationInfo"

    def __init__(self, newID=None, newSite=None, newSource=None, newTime=None,
        newPhase=None, newPolarity=None, newOnset=None, newPicker=None,
        newFilterList=None, newAmplitude=None, newBeam=None,
        newAssociationInfo=None, newClassificationInfo=None):
        """Initialize the pick object. Constructs an empty object
           if all arguments are None

        Args:
            newID: a required String containing the desired ID
            newSite: a required detectionformats.site.Site containing the desired
                site
            newSource: a required detectionformats.source.Source containing the
                desired source
            newTime: a required datetime containing the pick time
            newPhase: an optional String containing the desired phase identifier
            newPolarity: an optional String containing the desired polarity
            newOnset: an optional String containing the desired onset
            newPicker: an optional String containing the picker used
            newMagnitude: an optional Number containing the desired magnitude
                estimate as a float
            newFilterList: an optional Array of detectionformats.filter.Filter
                objects containing the filters used
            newAmplitude: an optional detectionformats.amplitude.Amplitude
                containing the amplitude measurement
            newBeam: an optional detectionformats.beam.Beam containing the beam
                measurement
            newAssociationInfo: an optional detectionformats.association.Association
                containing association information
            newClassificationInfo: an optional detectionformats.classification.Classification
                containing classification information
        Returns:
            Nothing
        Raises:
            Nothing
        """

        # first required keys
        self.type = 'Pick'
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

        if newTime is not None:
            self.time = newTime

        # second optional keys
        if newPhase is not None:
            self.phase = newPhase

        if newPolarity is not None:
            self.polarity = newPolarity

        if newOnset is not None:
            self.onset = newOnset

        if newPicker is not None:
            self.picker = newPicker

        if newFilterList is not None:
            self.filterList = newFilterList
        else:
            self.filterlist = []

        if newAmplitude is not None:
            self.amplitude = newAmplitude
        else:
            self.amplitude = detectionformats.amplitude.Amplitude()

        if newBeam is not None:
            self.beam = newBeam
        else:
            self.beam = detectionformats.beam.Beam()

        if newAssociationInfo is not None:
            self.associationInfo = newAssociationInfo
        else:
            self.associationInfo = detectionformats.association.Association()

        if newClassificationInfo is not None:
            self.classificationInfo = newClassificationInfo
        else:
            self.classificationInfo = detectionformats.classification.Classification()

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
            timeString = aDict[self.TIME_KEY][:-1] + "000Z"
            self.time = datetime.datetime.strptime(timeString, "%Y-%m-%dT%H:%M:%S.%fZ")
        except(ValueError, KeyError, TypeError) as e:
            print("Dict format error, missing required keys: %s" % e)

        # second optional keys
        if self.PHASE_KEY in aDict:
            self.phase = aDict[self.PHASE_KEY]

        if self.POLARITY_KEY in aDict:
            self.polarity = aDict[self.POLARITY_KEY]

        if self.ONSET_KEY in aDict:
            self.onset = aDict[self.ONSET_KEY]

        if self.PICKER_KEY in aDict:
            self.picker = aDict[self.PICKER_KEY]

        if self.FILTER_KEY in aDict:
            aFilterList = []
            for aFilter in aDict[self.FILTER_KEY]:
                newFilter = detectionformats.filter.Filter()
                newFilter.fromDict(aFilter)
                aFilterList.append(newFilter)

            self.filterList = aFilterList

        if self.AMPLITUDE_KEY in aDict:
            self.amplitude = detectionformats.amplitude.Amplitude()
            self.amplitude.fromDict(aDict[self.AMPLITUDE_KEY])

        if self.BEAM_KEY in aDict:
            self.beam = detectionformats.beam.Beam()
            self.beam.fromDict(aDict[self.BEAM_KEY])

        if self.ASSOCIATIONINFO_KEY in aDict:
            self.associationInfo = detectionformats.association.Association()
            self.associationInfo.fromDict(aDict[self.ASSOCIATIONINFO_KEY])

        if self.CLASSIFICATIONINFO_KEY in aDict:
            self.classificationInfo = detectionformats.classification.Classification()
            self.classificationInfo.fromDict(aDict[self.CLASSIFICATIONINFO_KEY])    

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
            timeString = self.time.isoformat(timespec='milliseconds') + "Z"
            aDict[self.TIME_KEY] = timeString
        except(NameError, AttributeError) as e:
            print("Missing required data error: %s" % e)

        # second optional keys
        if hasattr(self, 'phase'):
            aDict[self.PHASE_KEY] = self.phase

        if hasattr(self, 'polarity'):
            aDict[self.POLARITY_KEY] = self.polarity

        if hasattr(self, 'onset'):
            aDict[self.ONSET_KEY] = self.onset

        if hasattr(self, 'picker'):
            aDict[self.PICKER_KEY] = self.picker

        if hasattr(self, 'filterList'):
            aFilterList = []
            for aFilter in self.filterList:
                if not aFilter.isEmpty():
                    aFilterList.append(aFilter.toDict())

            aDict[self.FILTER_KEY] = aFilterList

        if hasattr(self, 'amplitude'):
            if not self.amplitude.isEmpty():
                aDict[self.AMPLITUDE_KEY] = self.amplitude.toDict()

        if hasattr(self, 'beam'):
            if not self.beam.isEmpty():
                aDict[self.BEAM_KEY] = self.beam.toDict()

        if hasattr(self, 'associationInfo'):
            if not self.associationInfo.isEmpty():
                aDict[self.ASSOCIATIONINFO_KEY] = self.associationInfo.toDict()

        if hasattr(self, 'classificationInfo'):
            if not self.classificationInfo.isEmpty():
                aDict[self.CLASSIFICATIONINFO_KEY] = self.classificationInfo.toDict()

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
                errorList.append('Empty Type in Pick Class.')
            elif self.type != 'Pick':
                errorList.append('Non-Pick Type in Pick Class.')
        except(NameError, AttributeError):
            errorList.append('No Type in Pick Class.')

        try:
            if self.id == '':
                errorList.append('Empty ID in Pick Class.')
        except(NameError, AttributeError):
            errorList.append('No ID in Pick Class.')

        try:
            if not self.site.isValid():
                errorList.append('Invalid Site in Pick Class.')
        except(NameError, AttributeError):
            errorList.append('No Site in Pick Class.')

        try:
            if not self.source.isValid():
                errorList.append('Invalid Source in Pick Class.')
        except(NameError, AttributeError):
            errorList.append('No Source in Pick Class.')

        try:
            self.time
        except(NameError, AttributeError):
            errorList.append('No Time in Pick Class.')

        # optional values
        if hasattr(self, 'polarity'):
            if self.polarity not in ['up', 'down']:
                errorList.append('Invalid Polarity in Pick Class.')

        if hasattr(self, 'onset'):
            if self.onset not in ['impulsive', 'emergent', 'questionable']:
                errorList.append('Invalid Onset in Pick Class.')

        if hasattr(self, 'picker'):
            if self.picker not in ['manual', 'raypicker', 'filterpicker', 'earthworm', 'other']:
                errorList.append('Invalid Picker in Pick Class.')

        if hasattr(self, 'filterList'):
            for aFilter in self.filterList:
                if not aFilter.isEmpty():
                    if not aFilter.isValid():
                        errorList.append('Invalid Filter in Pick Class.')

        if hasattr(self, 'amplitude'):
            if not self.amplitude.isEmpty():
                if not self.amplitude.isValid():
                    errorList.append('Invalid Amplitude in Pick Class.')

        if hasattr(self, 'beam'):
            if not self.beam.isEmpty():
                if not self.beam.isValid():
                    errorList.append('Invalid Beam in Pick Class.')
        
        if hasattr(self, 'associationInfo'):
            if not self.associationInfo.isEmpty():
                if not self.associationInfo.isValid():
                    errorList.append('Invalid AssociationInfo in Pick Class.')

        if hasattr(self, 'classificationInfo'):
            if not self.classificationInfo.isEmpty():
                if not self.classificationInfo.isValid():
                    errorList.append('Invalid ClassificationInfo in Pick Class.')

        return errorList
