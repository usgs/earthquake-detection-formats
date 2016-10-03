# CorrelationJSON Format Specification

## Description

CorrelationJSON is a format designed to encode the basic information of a seismic cross-correlation.  CorrelationJSON uses the [JSON standard](http://www.json.org).

## Usage
CorrelationJSON is intended for use in seismic data messaging between seismic applications and organizations.

## Output

    {
      "Type"      : "Correlation",
      "ID"        : String,
      "Site"      :
      {
         "SiteID"   : String,
         "Station"  : String,
         "Channel"  : String,
         "Network"  : String,
         "Location" : String
      },
      "Source"      :
      {
         "AgencyID" : String,
         "Author"   : String
      },
      "Phase"       : String,
      "Time"        : ISO8601,
      "Correlation" : Number,
      "Latitude"    : Number,
      "Longitude"   : Number,
      "OriginTime"  : ISO8601,
      "Depth"       : Number,
      "EventType"   : String,
      "Magnitude"   : Number,
      "SNR"         : Number,
      "ZScore"      : Number,
      "DetectionThreshold" : Number,
      "ThresholdType"      : String,
      "AssociationInfo"    :
      {
         "Phase"    : String,
         "Distance" : Number,
         "Azimuth"  : Number,
         "Residual" : Number,
         "Sigma"    : Number
      }
    }

## Glossary
**Required Values:**

These are the values **required** to define a correlation.
* Type - A string that identifies this message as a correlation.
* ID - A string containing an unique identifier for this correlation.
* Site - An object containing the station the correlation was made at, see [Site](Site.md).
* Source - An object containing the source of the correlation, see [Source](Source.md).
* Phase - A string that identifies the seismic phase that was correlated.
* PhaseTime - A string containing the UTC arrival time of the phase that was correlated, in the ISO8601 format `YYYY-MM-DDTHH:MM:SS.SSSZ`.
* Correlation - A decimal number containing the correlation value of the detection.
* Latitude - A decimal number that identifies the computed origin latitude of the correlation.
* Longitude - A decimal number that identifies the computed origin longitude of the correlation.
* Depth - A decimal number that identifies the computed origin elevation of the correlation.
* OriginTime - A string containing the UTC computed origin time of the correlation, in the ISO8601 format `YYYY-MM-DDTHH:MM:SS.SSSZ`.

**Optional Values:**

The following are supplementary values that **may or may not** be provided by various correlation algorithms.
* EventType - A string containing the type of detection that was found; "earthquake" or "blast"
* Magnitude - A decimal number identifying the relative magnitude of the correlation.
* SNR - A decimal number identifying Signal to Noise Ratio at the time of the correlation.
* ZScore - A decimal number identifying Z Score at the time of the correlation.
* DetectionThreshold - A decimal number identifying detection threshold that was used to declare this correlation.
* ThresholdType - A string containing the type of detection threshold that was used.* AssociationInfo:Phase - A string that identifies the seismic phase for this data if associated.
* AssociationInfo - An object containing the association information if this correlation is used as data in an [OriginJSON](OriginJSON.md), see [Association](Association.md).
