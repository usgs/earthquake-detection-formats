# Detection Formats

[![Build Status](https://travis-ci.org/usgs/earthquake-detection-formats.svg?branch=master)](https://travis-ci.org/usgs/earthquake-detection-formats)

The US Geological Survey (USGS) National Earthquake Information Center (NEIC) defines a number of data exchange formats to communicate seismic event detection information between processing systems. These formats are defined using objects as defined in the [JSON standard](http://www.json.org).

[License](LICENSE.md)

The purpose of this project is to:
1. Store the format definitions in a source controlled manner.
2. Host libraries used to generate and parse the formats

## Defined formats:
* [PickJSON](PickJSON.md) Format - A format for unassociated picks from a waveform arrival time picking algorithm.
* [BeamJSON](BeamJSON.md) Format  - A format for unassociated beams from seismic array beamforming algorithm.
* [CorrelationJSON](CorrelationJSON.md) Format - A format to contain a seismic event detection made using a cross correlation algorithm.
* [OriginJSON](OriginJSON.md) Format - A format to contain a seismic event origin made using an event detection algorithm.
* [RetractJSON](RetractJSON.md) Format - A format to contain a seismic event retraction made using an event detection algorithm.

## Supporting objects:
* [Amplitude](Amplitude.md) Object - An object that contains information about an amplitude as part of a pick.
* [Associated](Associated.md) Object - An object that contains associated information if a pick, beam, or correlation is included in an origin.
* [Filter](Filter.md) Object - An object that contains filter information as part of a pick.
* [Site](Site.md) Object - An object that defines the station used to create a pick, beam, correlation,
* [Source](Source.md) Object - An object that defines the creator/source of a pick, beam, correlation, or origin

## Supported Languages:
Currently a library written in C++11, and a Java 1.7 jar file exist to generate and parse these formats.

Getting Started
=====

## C++11 library
* See the [C++ README](cpp/README.md).

## Java 1.7 jar
* See the [Java README](java/README.md).
