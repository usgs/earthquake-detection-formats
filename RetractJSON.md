# RetractJSON Format Specification

## Description

RetractJSON is a format designed to encode the basic information of an earthquake event retraction.  RetractJSON uses the [JSON standard](http://www.json.org).

## Usage
RetractJSON is intended for use in seismic data messaging between seismic applications.

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
* Source - An object containing the source of the origin, see [Source](Source.md).
