# Station Information Format Specification

## Description

StationInfo is a format designed to encode the basic information of a station
location and quality.  StationInfo uses the [JSON standard](http://www.json.org).

## Usage

StationInfo is intended for use in seismic data messaging between seismic
applications and organizations. The [StationInfoRequest](StationInfoRequest.md)
Format is intended as a method of requesting a StationInfo message.

## Output

```json
    {
      "Type"      : "StationInfo",
      "Site"      :
      {
         "Station"   : String,
         "Channel"   : String,
         "Network"   : String,
         "Location"  : String,
         "Latitude"  : Number,
         "Longitude" : Number,
         "Elevation" : Number,
      },
      "GlassWeight"              : Number,
      "EnableForNucleation"      : Boolean
      "EnableForPicking"         : Boolean
      "EnableForAmplitudes"      : Boolean
      "Use"                      : Boolean,
      "UseForTeleseismic"        : Boolean,
      "InformationRequestor"     :
      "InformationProvider"      : Object,
      "MetricName"               : String,
      "MetricValue"              : Number,
      "DataStartDate"            : String,
      "DataEndDate"              : String,
      "UngappedDataDuration"     : Number,
      "UngappedDataDurationUnit" : String, 
      "LowPeriod"                : Number,
      "HighPeriod"               : Number,
      "BaseLineStartDate"        : String,
      "BaseLineEndDate"          : String,
      "Percentile"               : Number,
      {
         "AgencyID"  : String,
         "Author"    : String
      }
    }
```

## Glossary

**Required Values:**

These are the values **required** to define a StationInfo.

* Type - A string that identifies this message as a StationInfo.
* Site - An object containing the site for the station, see [Site](Site.md).

**Optional Values:**

The following are supplementary values that **may or may not** be provided as
part of a StationInfo.

* GlassWeight - A decimal number that indicates the quality of the station for Glass in a range between 0.0 and 1.0, where 0.0 indicates that the station should not be used.
* EnableForNucleation - A boolean flag indicating whether the station should be used for nucleation of seismic events, defaulting to true. This should only be set by a station operator or quality control algorithm based on data from this station.
* EnableForPicking - The same as EnableForNucleation, except pertaining to use for phase picking.  Defaults to true.
* EnableForAmplitudes - The same as EnableForNucleation, except pertaining to use for amplitude-based computations.  Defaults to true.
* Use - A boolean flag indicating whether the station is/was used by an algorithm or not, defaults to true. This is intended to represent whether an algorithm has chosen to not use a station for quality or other reasons
* UseForTeleseismic - A boolean flag indicating whether to use the station for teleseismic algorithms, defaults to false.
* InformationRequestor - An object containing the source who requested the information, see [Source](Source.md).
* InformationProvider - An object containing the source who produced this message.  Follows the same format as [Source](Source.md).
* MetricName - The name of a waveform data quality metric.
* MetricValue - A real number that is the value of the metric identified by MetricName.
* DataStartDate - Start date for the waveform data upon which MetricValue was computed.  Required if MetricName is specified.  Do not confuse with BaseLineStartDate.
* DataEndDate - Optional, unless different from DataStartDate.
* UngappedDataDuration - Optional parameter specifying the amount of data between DataStartDate and DataEndDate after all gaps have been removed.  This can be used as a check for statistical robustness.  No default value.
* UngappedDataDurationUnit - The unit of measure used for UngappedDataDuration:  "Seconds", "Hours", or "Days".  Default:  "Hours".
* LowPeriod - The low end value in seconds of the period band over which MetricValue was computed.  Required, if MetricValue is band-specific.  No default value.
* HighPeriod - The high end value associated with LowPeriod.  Required, if LowPeriod is required.  No default value.
* BaseLineStartDate - If MetricValue is referenced to a time window of previous data, e.g., the station deviation metric, this is the start date of that window and is required:  YYYY/MM/DD.  Normally, this window would not be expected to change frequently for a given station instrument.  No default value.
* BaseLineEndDate - Optional, unless BaseLineStartDate is required.  No default value.
* Percentile - The percentile (1 - 100) upon which MetricValue was computed.  Required, if MetricName is percentile-based.  Examples include noise metrics computed on percentiles of probability density functions (PDFs).  No default value.
