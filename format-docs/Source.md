# Source Object Specification

## Description

The Source object is an object designed to define the originating seismic
organization that produced a [Pick](Pick.md),
[Correlation](Correlation.md), or [Detection](Detection.md) message.
Site uses the [JSON standard](http://www.json.org).

## Usage

Source is intended for use as part of the [Pick](Pick.md),
[Correlation](Correlation.md), or [Origin](Origin.md) Formats in seismic data
messaging between seismic applications and organizations.

## Output

```json
    {
      "AgencyID"  : String,
      "Author"    : String
    }
```

## Glossary

**Required Values:**

These are the values **required** to define a Source

* AgencyID - A string containing the originating agency FDSN ID.
* Author - A string containing the source author.
