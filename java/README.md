# Java 1.7 Detection Formats Library

This is the Java implementation of the library used to generate and parse the Detection Formats.

Dependencies
------
* Detection Formats utilizizes [JSON](www.json.org) for formatting.
* Detection Formats was written in Java 1.7
* Detection Formats is built with [Apache Ant](http://ant.apache.org/), and was written using Eclipse.  Eclipse project files, source files, and ant build.xml are included
* Detection Formats utilizizes [json.simple](http://code.google.com/p/json-simple/) to format, parse, and write JSON.  A copy of the json.simple jar is included in this project.
* Detection Formats uses [junit](http://junit.org/) for unit testing.
* Detection Formats uses [Cobertura](http://cobertura.github.io/cobertura/) and supporting jars for coverage testing.

Building
------
The steps to get and build detection-formats.jar using ant are as follows:
1. Clone detection-formats.
2. Open a command window and change directories to /java/
3. To build the jar file, run the command ant jar
4. To run junit tests, run the command ant test.
5. To generate javadocs, run the commant ant javadoc
6. To compile, instrument, test, run coverage report, generate javadocs, build jar, run the command ant all

Using
-----
Once you are able to build the detection-formats jar, simply include the jar file in your application.
