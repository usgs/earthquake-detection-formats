# EventType Object Specification

## Description

The EventType object is an object designed to encode type
information for [Correlation](Correlation.md) and [Detection](Detection.md)
messages. EventType uses the [JSON standard](http://www.json.org).

## Usage

EventType is intended for use as part of the [Correlation](Correlation.md) and
[Detection](Detection.md) Formats in seismic data messaging between seismic
applications and organizations.

## Output

```json
    {
       "Type"      : String,
       "Certainty" : String
    }
```git sta

## Glossary

**Required Values:**

These are the values **required** to define an event type.

* Type - A string containing the type of detection that was found; allowed type strings are: "Earthquake", "MineCollapse", "NuclearExplosion", "QuarryBlast", "InducedOrTriggered", "RockBurst", "FluidInjection", "IceQuake",and "VolcanicEruption"

**Optional Values:**

The following are values that **may or may not** be provided as part of
event type.

* Certainty - A string containing the certainty of the event type; allowed strings are: "Suspected" and "Confirmed".