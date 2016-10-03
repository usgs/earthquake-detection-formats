# Associated Object Specification

## Description

The Associated object is an object designed to encode information provided when a [PickJSON](PickJSON.md), [BeamJSON](BeamJSON.md), or [CorrelationJSON](CorrelationJSON.md) is included as supporting data in a [OriginJSON](OriginJSON.md).  Associated uses the [JSON standard](http://www.json.org) .

## Usage
PickJSON is intended for use as part of the [PickJSON](PickJSON.md), [BeamJSON](BeamJSON.md), or [CorrelationJSON](CorrelationJSON.md) Formats in seismic data messaging between seismic applications and organizations.

## Output

    {
       "Phase"    : String,
       "Distance" : Number,
       "Azimuth"  : Number,
       "Residual" : Number,
       "Sigma"    : Number
    }

## Glossary

**Optional Values:**

The following are values that **may or may not** be provided as part of association.

* Phase - A string that identifies the seismic phase for this data if associated.
* Distance - A decimal number containing the distance between the detection's and data's locations if associated.
* Azimuth - A decimal number containing the azimuth between the detection's and data's locations if associated.
* Residual - A decimal number containing residual of the data if associated.
* Sigma - A decimal number reflecting the number of standard deviations of the data from the calculated value if associated.
