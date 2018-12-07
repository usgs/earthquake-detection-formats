# Correlation Format Specification

## Description

Correlation is a format designed to encode the basic information of a seismic
cross-correlation.  Correlation uses the [JSON standard](http://www.json.org).

## Usage

Correlation is intended for use in seismic data messaging between seismic
applications and organizations.

## Output

```json
    {
      "Type"      : "Correlation",
      "ID"        : String,
      "Site"      :
      {
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
      "Hypocenter"  :
      {
          "Latitude"        : Number,
          "Longitude"       : Number,
          "Depth"           : Number,
          "Time"            : ISO8601,
          "LatitudeError"   : Number,
          "LongitudeError"  : Number,
          "DepthError"      : Number,
          "TimeError"       : Number
      },
      "EventType" :
      {
          "Type"      : String,
          "Certainty" : String
      }
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
```

## Glossary

**Required Values:**

These are the values **required** to define a correlation.

* Type - A string that identifies this message as a correlation.
* ID - A string containing an unique identifier for this correlation.
* Site - An object containing the station the correlation was made at, see [Site](Site.md).
* Source - An object containing the source of the correlation, see [Source](Source.md).
* Phase - A string that identifies the seismic phase that was correlated.
* Time - A string containing the UTC arrival time of the phase that was correlated, in the ISO8601 format `YYYY-MM-DDTHH:MM:SS.SSSZ`.
* Correlation - A decimal number containing the correlation value of the detection.
* Hypocenter - An object containing the hypocenter of the correlation, see [Hypocenter](Hypocenter.md).

**Optional Values:**

The following are supplementary values that **may or may not** be provided by
various correlation algorithms.

* EventType - An object containing the event type of the correlation, see [EventType](EventType.md).
* Magnitude - A decimal number identifying the relative magnitude of the correlation.
* SNR - A decimal number identifying Signal to Noise Ratio at the time of the correlation.
* ZScore - A decimal number identifying Z Score at the time of the correlation.
* DetectionThreshold - A decimal number identifying detection threshold that was used to declare this correlation.
* ThresholdType - A string containing the type of detection threshold that was used.
* AssociationInfo - An object containing the association information if this correlation is used as data in a [Detection](Detection.md), see [Associated](Associated.md).
