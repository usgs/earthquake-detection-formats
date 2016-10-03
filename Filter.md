# Filter Object Specification

## Description

The Filter object is an object designed to encode the filter frequencies that may or may not be part the [PickJSON](PickJSON.md) Format.  Filter uses the [JSON standard](http://www.json.org) .

## Usage
The Filter object is intended for use as part of the [PickJSON](PickJSON.md) Format in seismic data messaging between seismic applications and organizations.

## Output

    {
       "HighPass" : Number,
       "LowPass"  : Number
    }

## Glossary

**Optional Values:**

The following are values that **may or may not** be provided as part of a filter.

* HighPass - A decimal number containing the high pass frequency.
* LowPass - A decimal number containing the low pass frequency.
