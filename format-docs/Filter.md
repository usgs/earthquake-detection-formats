# Filter Object Specification

## Description

The Filter object is an object designed to encode a single set of filter
frequencies that may or may not be part of the filter list in the [Pick](Pick.md)
Format. Filter uses the [JSON standard](http://www.json.org) .

## Usage
The Filter object is intended for use as part of the [Pick](Pick.md) Format
in seismic data messaging between seismic applications and organizations.

## Output
```json
   {
      "HighPass" : Number,
      "LowPass"  : Number
   }
```
## Glossary

**Optional Values:**

The following are values that **may or may not** be provided as part of a filter.

* HighPass - A decimal number containing the high pass frequency in Hz.
* LowPass - A decimal number containing the low pass frequency in Hz.

Note: The type of filter is assumed to be band-pass.
