# Site Object Specification

## Description

The Site object is an object designed to define the seismic station used to produce a [PickJSON](PickJSON.md), [BeamJSON](BeamJSON.md), or [CorrelationJSON](CorrelationJSON.md) message.  Site uses the [JSON standard](http://www.json.org) .

## Usage
Site is intended for use as part of the [PickJSON](PickJSON.md), [BeamJSON](BeamJSON.md), or [CorrelationJSON](CorrelationJSON.md) Formats in seismic data messaging between seismic applications and organizations.

## Output

    {
      "SiteID"    : String,
      "Station"   : String,
      "Channel"   : String,
      "Network"   : String,
      "Location"  : String
    }

## Glossary
**Required Values:**

These are the values **required** to define a Site.

* SiteID -  A unique string containing an unique identifier for this station usually formatted to contain the available station, channel, network, and/or location codes.
* Station - A string the station code.
* Site:Network - A string containing network code.

**Optional Values:**

The following are supplementary values that **may or may not** be provided as part of a Site.

* Channel - A string containing the channel code.
* Location - A string containing the location code.
