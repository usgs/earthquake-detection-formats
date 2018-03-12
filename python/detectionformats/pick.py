#!/usr/bin/env python

#package imports
import detectionformats.source
import detectionformats.site
import detectionformats.beam
import detectionformats.filter
import detectionformats.amplitude
import detectionformats.associated

#stdlib imports
import json
import datetime

# a conversion class used to create, parse, and validate a pick
# as part of detection data.
class Pick:
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

    # init
    def __init__(self, newID=None, newSite=None, newSource=None, newTime=None,
        newPhase=None, newPolarity=None, newOnset=None, newPicker=None,
        newFilterList=None, newAmplitude=None, newBeam=None,
        newAssociatioInfo=None) :
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
            newAssociatioInfo: an optional detectionformats.associated.Associated
                containing association information
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
            if newFilterList and len(newFilterList) > 0:
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

        if newAssociatioInfo is not None:
            self.associationInfo = newAssociatioInfo
        else:
            self.associationInfo = detectionformats.associated.Associated()

    # populate class from a json string
    def fromJSONString(self, jsonString) :
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

    # populate class from a dictonary
    def fromDict(self, aDict) :
        """Populates the object from a dictonary

        Args:
            aDict: a required Dictonary
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
        except (ValueError, KeyError, TypeError):
            print ("Dict format error")

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
            aFilterList = aDict[self.FILTER_KEY]
            if aFilterList:
                self.filterList = []
                for aFilter in aFilterList:
                    newFilter = detectionformats.filter.Filter()
                    newFilter.fromDict(aFilter)
                    self.filterList.append(newFilter)

        if self.AMPLITUDE_KEY in aDict:
            self.amplitude = detectionformats.amplitude.Amplitude()
            self.amplitude.fromDict(aDict[self.AMPLITUDE_KEY])

        if self.BEAM_KEY in aDict:
            self.beam = detectionformats.beam.Beam()
            self.beam.fromDict(aDict[self.BEAM_KEY])

        if self.ASSOCIATIONINFO_KEY in aDict:
            self.associationInfo = detectionformats.associated.Associated()
            self.associationInfo.fromDict(aDict[self.ASSOCIATIONINFO_KEY])

    # convert class to a json string
    def toJSONString(self) :
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

    # convert class to a dictonary
    def toDict(self) :
        """Converts the object to a dictonary

        Args:
            None
        Returns:
            The Dictonary
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
        except NameError:
            print ("Missing data error")

        # second optional keys
        try:
            aDict[self.PHASE_KEY] = self.phase
        except:
            pass

        try:
            aDict[self.POLARITY_KEY] = self.polarity
        except:
            pass

        try:
            aDict[self.ONSET_KEY] = self.onset
        except:
            pass

        try:
            aDict[self.PICKER_KEY] = self.picker
        except:
            pass

        try:
            aFilterList = []
            if self.filterList and len(self.filerList) > 0:
                for aFilter in self.filterList:
                    if aFilter.isEmpty() == False:
                        aFilterList.append(aFilter.toDict())

                aDict[self.FILTER_KEY] = aFilterList
        except:
            pass

        try:
            if self.amplitude.isEmpty() == False:
                aDict[self.AMPLITUDE_KEY] = self.amplitude.toDict()
        except:
            pass

        try:
            aDict[self.BEAM_KEY] = self.beam.toDict()
        except:
            pass

        try:
            if self.associationInfo.isEmpty() == False:
                aDict[self.ASSOCIATIONINFO_KEY] = self.associationInfo.toDict()
        except:
            pass

        return aDict

    # test to see if class is valid
    def isValid(self) :
        """Checks to see if the object is valid

        Args:
            None
        Returns:
            True if the object is valid, False otherwise
        Raises:
            Nothing
        """
        errorList = self.getErrors()

        if len(errorList) == 0:
            return True
        else:
            return False

    # get list of validation errors
    def getErrors(self) :
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
        except (NameError, AttributeError):
            errorList.append('No Type in Pick Class.')

        try:
            if self.id == '':
                errorList.append('Empty ID in Pick Class.')
        except (NameError, AttributeError):
            errorList.append('No ID in Pick Class.')

        try:
            if self.site.isValid() == False:
                errorList.append('Invalid Site in Pick Class.')
        except (NameError, AttributeError):
            errorList.append('No Site in Pick Class.')

        try:
            if self.source.isValid() == False:
                errorList.append('Invalid Source in Pick Class.')
        except (NameError, AttributeError):
            errorList.append('No Source in Pick Class.')

        try:
            self.time
        except (NameError, AttributeError):
            errorList.append('No Time in Pick Class.')

        # optional values
        try:
            self.polarity
            if self.polarity != 'up' and self.polarity != 'down' :
                errorList.append('Invalid Polarity in Pick Class.')
        except (NameError, AttributeError):
            pass

        try:
            self.onset
            if self.onset != 'impulsive' and self.onset != 'emergent' and self.onset != 'questionable':
                errorList.append('Invalid Onset in Pick Class.')
        except (NameError, AttributeError):
            pass

        try:
            self.picker
            if self.picker != 'manual' and self.picker != 'raypicker' and self.picker != 'filterpicker' and self.picker != 'earthworm' and self.picker != 'other':
                errorList.append('Invalid Picker in Pick Class.')
        except (NameError, AttributeError):
            pass

        try:
            if self.filterList and len(self.filerList) > 0:
                for aFilter in self.filterList:
                    if aFilter.isEmpty() == False:
                        if aFilter.isValid() == False:
                            errorList.append('Invalid Filter in Pick Class.')
        except (NameError, AttributeError):
            pass

        try:
            if self.amplitude.isEmpty() == False:
                if self.amplitude.isValid() == False:
                    errorList.append('Invalid Amplitude in Pick Class.')
        except (NameError, AttributeError):
            pass

        try:
            if self.beam.isEmpty() == False:
                if self.beam.isValid() == False:
                    errorList.append('Invalid Beam in Pick Class.')
        except (NameError, AttributeError):
            pass

        try:
            if self.associationInfo.isEmpty() == False:
                if self.associationInfo.isValid() == False:
                    errorList.append('Invalid AssociationInfo in Pick Class.')
        except (NameError, AttributeError):
            pass

        return errorList
