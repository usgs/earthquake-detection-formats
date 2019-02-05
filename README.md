# Detection Formats

[![Build Status](https://travis-ci.org/usgs/earthquake-detection-formats.svg?branch=master)](https://travis-ci.org/usgs/earthquake-detection-formats)
[![codecov](https://codecov.io/gh/usgs/earthquake-detection-formats/branch/master/graph/badge.svg)](https://codecov.io/gh/usgs/earthquake-detection-formats)

The US Geological Survey (USGS) National Earthquake Information Center (NEIC)
defines a number of data exchange formats to communicate seismic event detection
information between processing systems. These formats are defined using objects
as defined in the [JSON standard](http://www.json.org).


[License](LICENSE.md)

The purpose of this project is to:

1. Define formats to hold data representing the estimates of various types of
seismic event detections.
2. Store the format definitions in a source controlled manner.
3. Host libraries used to generate and parse the formats

## Defined formats:
* [Pick](format-docs/Pick.md) Format - A format for unassociated picks from a
waveform arrival time picking algorithm.
* [Correlation](format-docs/Correlation.md) Format - A format to contain a
seismic event detection made using a cross correlation algorithm.
* [Detection](format-docs/Detection.md) Format - A format to contain a seismic
event detection generated using an event detection or association algorithm.
* [Retract](format-docs/Retract.md) Format - A format to contain a seismic event
retraction made using an event detection algorithm.
* [StationInfo](format-docs/StationInfo.md) Format - A format to contain basic
station location and quality information.
* [StationInfoRequest](format-docs/StationInfoRequest.md) Format - A format for
requesting basic station location and quality information.


## Supporting objects:
* [Hypocenter](format-docs/Hypocenter.md) Object - An object that contains
information about a hypocenter as part of a detection.
* [Amplitude](format-docs/Amplitude.md) Object - An object that contains
information about an amplitude as part of a pick.
* [Beam](format-docs/Beam.md) Object  - An object that contains information
about a waveform beam as part of a pick.
* [Associated](format-docs/Associated.md) Object - An object that contains
associated information if a pick or correlation is included in a detection.
* [Filter](format-docs/Filter.md) Object - An object that contains filter
information as part of a pick.
* [Site](format-docs/Site.md) Object - An object that defines the station used
to create a pick, correlation, or station.
* [Source](format-docs/Source.md) Object - An object that defines the
creator/source of a pick, correlation, or detection.

## Supported Languages:
Currently a library written in C++11, a Java 1.7 jar file, and a Python 3.6
implementation exist to generate and parse these formats.

Getting Started
=====

## C++11 library
* See the [C++ README](cpp/README.md).

## Java 1.7 jar
* See the [Java README](java/README.md).

## Python 3.6
* See the [Python README](python/README.md).
