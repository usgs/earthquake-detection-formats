# BeamJSON Format Specification

## Description

BeamJSON is a format designed to encode the basic information of an unassociated waveform beam.  PickJSON uses the [JSON standard](http://www.json.org) .

## Usage
BeamJSON is intended for use in seismic data messaging between seismic applications and organizations.

## Output

    {
      "Type"      : "Beam",
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
      "Time"             : ISO8601,
      "BackAzimuth"      : Number,
      "BackAzimuthError" : Number,
      "Slowness"         : Number,
      "SlownessError"    : Number,
      "AssociationInfo"  :
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

These are the values **required** to define a beam.
* Type - A string that identifies this message as a beam.
* ID - A string containing an unique identifier for this beam.
* Site - An object containing the station the beam was made at, see [Site](Site.md).
* Source - An object containing the source of the beam, see [Source](Source.md).
* Time - A string containing the UTC arrival time of the beam, in the ISO8601 format `YYYY-MM-DDTHH:MM:SS.SSSZ`.
* BackAzimuth - A decimal number containing the back azimuth.
* Slowness - A decimal number containing the horizontal slowness.

**Optional Values:**

The following are supplementary values that **may or may not** be provided by various algorithms.
* BackAzimuthError - A decimal number containing the back azimuth error.
* SlownessError - A decimal number containing the horizontal slowness error.
* AssociationInfo - An object containing the association information if this beam is used as data in an [OriginJSON](OriginJSON.md), see [Association](Association.md).
