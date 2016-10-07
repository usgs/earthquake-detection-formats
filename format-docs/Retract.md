# Retract Format Specification

## Description

Retract is a format designed to encode the basic information of an earthquake
event retraction.  Retract uses the [JSON standard](http://www.json.org).

## Usage
Retract is intended for use in seismic data messaging between seismic
applications.

## Output

    {
      "Type"        : "Retract",
      "ID"          : String,
      "Source"      :
      {
         "AgencyID" : String,
         "Author"   : String
      }
    }

## Glossary
Required Values:
* Type - A string that identifies this message as a detection.
* ID - A string containing an unique identifier for this origin.
* Source - An object containing the source of the origin, see
[Source](Source.md).
