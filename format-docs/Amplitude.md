# Amplitude Object Specification

## Description

The Amplitude object is an object designed to encode the amplitude information
that may or may not be part of the [Pick](Pick.md) Format.  Amplitude uses the
[JSON standard](http://www.json.org).

## Usage
The Amplitude object is intended for use as part of the [Pick](Pick.md) Format
in seismic data messaging between seismic applications and organizations.

## Output
```json
    {
       "Amplitude" : Number,
       "Period"    : Number,
       "SNR"       : Number
    }
```

## Glossary

**Optional Values:**

The following are values that **may or may not** be provided as part of an
amplitude.

* Amplitude - A decimal number containing the amplitude.
* Period - A decimal number containing the amplitude period.
* SNR - A decimal number containing the signal to noise ratio.
