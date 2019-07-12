# Station Information Format Specification

## Description

StationInfo is a format designed to encode the basic information of a station
location and quality.  StationInfo uses the [JSON standard](http://www.json.org).

## Usage

StationInfo is intended for use in seismic data messaging between seismic
applications and organizations. The [StationInfoRequest](StationInfoRequest.md)
Format is intended as a method of requesting a StationInfo message.

## Output

```json
    {
      "Type"      : "StationInfo",
      "Site"      :
      {
         "Station"   : String,
         "Channel"   : String,
         "Network"   : String,
         "Location"  : String,
         "Latitude"  : Number,
         "Longitude" : Number,
         "Elevation" : Number,
      },
      "Quality"       : Number,
      "Enable"        : Boolean,
      "Use"           : Boolean,
      "UseForTeleseismic" : Boolean,
      "InformationRequestor" :
      {
         "AgencyID"  : String,
         "Author"    : String
      }
    }
```

## Glossary

**Required Values:**

These are the values **required** to define a StationInfo.

* Type - A string that identifies this message as a StationInfo.
* Site - An object containing the site for the station, see [Site](Site.md).

**Optional Values:**

The following are supplementary values that **may or may not** be provided as
part of a StationInfo.

* Quality - A decimal number that indicates the quality of the station in a range between 0.0 and 1.0, where 0.0 indicates that the station should not be used.
* Enable - A boolean flag indicating whether the station is enabled or not, defaults to true. This is intended to represent whether a station operator has disabled the station.
* Use - A boolean flag indicating whether the station is was used by an algorithm or not, defaults to true. This is intended to represent whether an algorithm has chosen to not use a station for quality or other reasons
* UseForTeleseismic - A boolean flag indicating whether to use the station for teleseismic algorithms, defaults to false.
* InformationRequestor - An object containing the source who requested the information, see [Source](Source.md).
