# Retract Format Specification

## Description

Retract is a format designed to encode the basic information of an earthquake
detection retraction.  Retract uses the [JSON standard](http://www.json.org).

## Usage
Retract is intended for use in seismic data messaging between seismic
applications.

## Output

```json
    {
      "Type"        : "Retract",
      "ID"          : String,
      "Source"      :
      {
         "AgencyID" : String,
         "Author"   : String
      }
    }
```

## Glossary

These are the values **required** to define a retraction.

* Type - A string that identifies this message as a detection.
* ID - A string containing an unique identifier for this origin.
* Source - An object containing the source of the origin, see [Source](Source.md).
