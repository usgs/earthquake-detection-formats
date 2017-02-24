# Beam Object Specification

## Description

The Beam object is an object designed to encode waveform beam information
that may or may not be part of the [Pick](Pick.md) Format.  Beam uses the
[JSON standard](http://www.json.org).

## Usage
The Beam object is intended for use as part of the [Pick](Pick.md) Format
in seismic data messaging between seismic applications and organizations.

## Output
```json
    {    
      "BackAzimuth"      : Number,
      "BackAzimuthError" : Number,
      "Slowness"         : Number,
      "SlownessError"    : Number,
      "PowerRatio"       : Number,
      "PowerRatioError"  : Number,      
    }
```

## Glossary
**Required Values:**

These are the values **required** to define a beam.
* BackAzimuth - A decimal number containing the back azimuth.
* Slowness - A decimal number containing the horizontal slowness.

**Optional Values:**

The following are supplementary values that **may or may not** be provided by
various algorithms.
* BackAzimuthError - A decimal number containing the back azimuth error.
* SlownessError - A decimal number containing the horizontal slowness error.
* PowerRatio - A decimal number containing the power ratio.
* PowerRatioError - A decimal number containing the power ratio error.
