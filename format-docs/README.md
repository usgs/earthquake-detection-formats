The purpose of these formats is to hold data representing the estimates of
various types of seismic event detections.

## Defined formats:
* [Pick](Pick.md) Format - A format for unassociated picks from a
waveform arrival time picking algorithm.
* [Correlation](Correlation.md) Format - A format to contain a seismic
event detection made using a cross correlation algorithm.
* [Detection](format-docs/Detection.md) Format - A format to contain a seismic
event detection generated using an event detection or association algorithm.
* [Retract](Retract.md) Format - A format to contain a seismic event
retraction made using an event detection algorithm.
* [StationInfo](StationInfo.md) Format - A format to contain basic station
location and quality information.
* [StationInfoRequest](StationInfoRequest.md) Format - A format for requesting
basic station location and quality information.

## Supporting objects:
* [Hypocenter](Hypocenter.md) Object - An object that contains information about
a hypocenter as part of a detection.
* [Amplitude](Amplitude.md) Object - An object that contains information about
an amplitude as part of a pick.
* [Beam](Beam.md) Object  - An object that contains information about a waveform
beam as part of a pick.
* [Associated](Associated.md) Object - An object that contains associated
information if a pick, beam, or correlation is included in an detection.
* [Filter](Filter.md) Object - An object that contains filter information as
part of a pick.
* [Site](Site.md) Object - An object that defines the station used to create a
pick, correlation, or station.
* [Source](Source.md) Object - An object that defines the creator/source of a
pick, correlation, or detection.
