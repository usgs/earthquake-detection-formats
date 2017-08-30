# Station Information Request Specification

## Description

StationInfoRequest is a format designed to encode the basic information of a
station information request.  StationInfoRequest uses the
[JSON standard](http://www.json.org).

## Usage
StationInfoRequest is intended for use by seismic applications requesting
station information from a station information data service or services. The
[StationInfo](StationInfo.md) Format is intended as the response to a
StationInfoRequest message.

## Output
```json
    {
      "Type"      : "StationInfoRequest",
      "Site"      :
      {
         "Station"   : String,
         "Channel"   : String,
         "Network"   : String,
         "Location"  : String
      },
      "Source"    :
      {
         "AgencyID"  : String,
         "Author"    : String
      }
    }
```

## Glossary
**Required Values:**

These are the values **required** to define a StationInfoRequest.
* Type - A string that identifies this message as a StationInfoRequest.
* Site - An object containing the site for the station information request, see
[Site](Site.md).
* Source - An object containing the source of the station information request,
see [Source](Source.md).
