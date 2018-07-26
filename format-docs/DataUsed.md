# DataUsed Format Specification

## Description

DataUsed is a format designed to encode basic information of timeseries used by a process.  DataUsed uses the [JSON standard](http://www.json.org).


## Output
```json
  {
    "Type"       : "DataUsed",
    "Site"       : {
      "Station"  : String,
      "Channel"  : String,
      "Network"  : String,
      "Location" : String
    },
    "StartTime"  : ISO8601String,
    "EndTime"    : ISO8601String,
    "Filter"     : [],
    "Software"   : String,
    "Purpose"    : String
  }
```

### Usage within an application

```json
  {
    "Metadata": {
        "Software": "finite-fault v1.2.3",
        "Purpose": "short period waveforms",
        "DataselectServiceUsed": null,
        "StationXMLServiceUsed": null,
        ...
    },
    "Inputs": [
        DataUsed,
        DataUsed,
        DataUsed,
        ...
    ]
  }
```


## Glossary
**Required Values:**

These are the values **required** to define a dataused.
* Type      - `DataUsed` to indicate the message type.
* Site      - An object containing the station the data is from, see [Site](Site.md)
* StartTime - Time of the first sample used.
* EndTime   - Time of the last sample used

**Optional Values:**

The following are supplementary values that **may or may not** be provided by
various applications.

* Filter    - An array of objects containing the filters used, see [Filter](Filter.md).
* Software  - The software and version that used the data.
* Purpose   - Comment describing how the data was used.
