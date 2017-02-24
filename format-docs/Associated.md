# Associated Object Specification

## Description

The Associated object is an object designed to encode information provided when
a [Pick](Pick.md) or [Correlation](Correlation.md) is included
as supporting data in a [Detection](Detection.md).  Associated uses the
[JSON standard](http://www.json.org).

## Usage
Pick is intended for use as part of the [Pick](Pick.md), [Beam](Beam.md), or
[Correlation](Correlation.md) Formats in seismic data messaging between seismic
applications and organizations.

## Output
```json
    {
       "Phase"    : String,
       "Distance" : Number,
       "Azimuth"  : Number,
       "Residual" : Number,
       "Sigma"    : Number
    }
```

## Glossary

**Optional Values:**

The following are values that **may or may not** be provided as part of
association.

* Phase - A string that identifies the seismic phase for this data if
associated.
* Distance - A decimal number containing the distance in degrees between the
detection's and data's locations if associated.
* Azimuth - A decimal number containing the azimuth in degrees between the
detection's and data's locations if associated.
* Residual - A decimal number containing residual in seconds of the data if
associated.
* Sigma - A decimal number reflecting the number of standard deviations of the
data from the calculated value if associated.
