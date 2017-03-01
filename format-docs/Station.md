# Station Format Specification

## Description

Pick is a format designed to encode the basic information of a station location
and quality.  Station uses the [JSON standard](http://www.json.org).

## Usage
Station is intended for use in seismic data messaging between seismic
applications and organizations.

## Output
```json
    {
      "Type"      : "Station",
      "Site"      :
      {
         "Station"   : String,
         "Channel"   : String,
         "Network"   : String,
         "Location"  : String
      },
      "Latitude"      : Number,
      "Longitude"     : Number,
      "Elevation"     : Number,
      "Quality"       : Number,                  
      "Enable"        : Boolean
    }
```

## Glossary
**Required Values:**

These are the values **required** to define a station.
* Type - A string that identifies this message as a station.
* Site - An object containing the site for the station, see
[Site](Site.md).
* Latitude - A decimal number that identifies the latitude of this station in
degrees.
* Longitude - A decimal number that identifies the longitude of this station
in degrees.
* Elevation - A decimal number that identifies the elevation of this station in
kilometers.

**Optional Values:**

The following are supplementary values that **may or may not** be provided as
part of a station.
* Quality - A decimal number that indicates the quality of the station
* Enable - A boolean flag indicating whether use of the station is enabled or
not, defaults to true.
