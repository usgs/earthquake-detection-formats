# Classification Object Specification

## Description

The Classification object is an object designed to encode value added
information available for a [Pick](Pick.md) from advanced algorithms such as
machine learning. Classification uses the [JSON standard](http://www.json.org).

## Usage

Classification is intended for use as part of the [Pick](Pick.md) Format in
seismic data messaging between seismic
applications and organizations.

## Output

```json
    {
        "Phase"                : String,
        "PhaseProbability"     : Number,
        "Distance"             : Number,
        "DistanceProbability"  : Number,
        "Azimuth"              : Number,
        "AzimuthProbability"   : Number,
        "Magnitude"            : Number,
        "MagnitudeType"        : String,
        "MagnitudeProbability" : Number,
        "Depth"                : Number,
        "DepthProbability"     : Number,
        "EventType" :
        {
            "Type"      : String,
            "Certainty" : String
        },
        "EventTypeProbability" : Number,
        "Source" :
        {
            "AgencyID" : String,
            "Author"   : String
        }
    }
```

## Glossary

**Optional Values:**

The following are values that **may or may not** be provided as part of classification.

* Phase - A string that identifies the seismic phase for this data
* PhaseProbability - A decimal number containing the probability of the phase identification
* Distance - A decimal number containing a distance estimation in degrees
* DistanceProbability - A decimal number containing the probability of the distance estimation
* Azimuth - A decimal number containing a azimuth estimation in degrees
* AzimuthProbability - A decimal number containing the probability of the azimuth estimation
* Magnitude - A decimal number containing the magnitude estimation
* MagnitudeType - A string that identifies the magnitude type
* MagnitudeProbability - A decimal number containing the probability of the magnitude estimation
* Depth - A decimal number containing a depth estimation in kilometers
* DepthProbability - A decimal number containing the probability of the depth estimation
* EventType - An object containing the event type, see [EventType](EventType.md).
* EventTypeProbability - A decimal number containing the probability of the event type estimation
* Source - An object containing the source of the classification, see [Source](Source.md).