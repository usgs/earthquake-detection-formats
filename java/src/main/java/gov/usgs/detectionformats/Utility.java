package gov.usgs.detectionformats;

import java.util.Date;
import java.util.GregorianCalendar;
import javax.xml.datatype.DatatypeFactory;
import javax.xml.datatype.XMLGregorianCalendar;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

/**
 * a utility class containing functions used by detectionformats.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Utility {
  /** JSON Keys */
  public static final String TYPE_KEY = "Type";

  public static final String DETECTION_TYPE = "Detection";
  public static final String CORRELATION_TYPE = "Correlation";
  public static final String PICK_TYPE = "Pick";
  public static final String RETRACT_TYPE = "Retract";
  public static final String STATIONINFO_TYPE = "StationInfo";
  public static final String STATIONINFOREQUEST_TYPE = "StationInfoRequest";

  /** File Extensions for detectionformats messages */
  public static final String DETECTIONEXTENSION = "jsondetect";

  public static final String PICKEXTENSION = "jsonpick";
  public static final String CORRELATIONEXTENSION = "jsoncorl";
  public static final String STATIONEXTENSION = "jsonsta";

  /**
   * Converts the provided string from a serialized JSON string, populating members
   *
   * @param jsonString - A string containing the serialized JSON
   * @return Returns a JSONObject if successful, null otherwise
   * @throws ParseException if one occurs
   */
  public static JSONObject fromJSONString(String jsonString) throws ParseException {
    // use a parser to convert to a string
    JSONParser parser = new JSONParser();
    return ((JSONObject) parser.parse(jsonString));
  }

  /**
   * Converts the contents of the class to a serialized JSON string
   *
   * @param newJSONObject - A JSONObject containing the JSON object to serialize
   * @return Returns a String containing the serialized JSON data
   */
  public static String toJSONString(JSONObject newJSONObject) {
    return (newJSONObject.toJSONString());
  }

  /**
   * Validates that a string contains just characters
   *
   * @param testString string to test.
   * @return Returns true if it does, false otherwise
   */
  public static boolean isStringAlpha(String testString) {
    // use regex to figure out if this string contains only letters
    return (testString.matches("^[A-Za-z]+$"));
  }

  /**
   * Validates that a string contains a number
   *
   * @param testString string to test.
   * @return Returns true if it does, false otherwise
   */
  public static boolean isStringNumber(String testString) {
    // use regex to figure out if this string contains a number
    // (decimal point and negative sign allowed)
    return (testString.matches("-?[0-9]+([.][0-9]+)?"));
  }

  /**
   * Convenience method to format a Date as an XML DateTime String.
   *
   * @param date the date to format.
   * @return the XML representation as a string.
   */
  public static String formatDate(final Date date) {
    if (date == null) {
      return null;
    }
    GregorianCalendar calendar = new GregorianCalendar();
    calendar.setTimeInMillis(date.getTime());
    return formatGregorianCalendar(calendar);
  }

  /**
   * Format a Gregorian Calendar as an XML DateTime String.
   *
   * @param calendar the calendar to format.
   * @return the XML representation as a string.
   */
  public static String formatGregorianCalendar(final GregorianCalendar calendar) {
    try {
      return DatatypeFactory.newInstance()
          .newXMLGregorianCalendar(calendar)
          .normalize()
          .toXMLFormat();
    } catch (Exception e) {
      return null;
    }
  }

  /**
   * Parse an XML Date Time into an XMLGregorianCalendar.
   *
   * @param toParse the xml date time string to parse.
   * @return the parsed XMLGregorianCalendar object.
   */
  public static XMLGregorianCalendar getXMLGregorianCalendar(final String toParse) {
    try {
      return DatatypeFactory.newInstance().newXMLGregorianCalendar(toParse);
    } catch (Exception e) {
      return null;
    }
  }

  /**
   * Convenience method to parse an XML Date Time into a Date. Only useful when the XML Date Time is
   * within the Date object time range.
   *
   * @param toParse the xml date time string to parse.
   * @return the parsed Date object.
   */
  public static Date getDate(final String toParse) {
    XMLGregorianCalendar calendar = getXMLGregorianCalendar(toParse);
    if (calendar != null) {
      return new Date(calendar.toGregorianCalendar().getTimeInMillis());
    } else {
      return null;
    }
  }

  /**
   * Convenience method to check if the provided string is valid json
   *
   * @param jsonString the json formatted string to check.
   * @return a boolean indicating whether the json is valid
   */
  public static boolean isJSONValid(String jsonString) {
    // use a parser to convert to a string
    JSONParser parser = new JSONParser();

    // parse it
    JSONObject newJSONObject;

    try {
      newJSONObject = (JSONObject) parser.parse(jsonString);
    } catch (ParseException e) {
      return (false);
    }

    return (true);
  }

  /**
   * Convenience method to check if the provided string is for one of the supported types
   *
   * @param jsonString the json formatted string to check.
   * @return a FormatTypes enum containing the type, or unknown if the type is not recognized
   */
  public static FormatTypes getDetectionType(String jsonString) {
    // use a parser to convert to a string
    JSONParser parser = new JSONParser();

    // parse it
    JSONObject newJSONObject;

    try {
      newJSONObject = (JSONObject) parser.parse(jsonString);
    } catch (ParseException e) {
      return (FormatTypes.Error);
    }

    return (getDetectionType(newJSONObject));
  }

  /**
   * Convenience method to check if the provided string is for one of the supported types
   *
   * @param jsonObject the json object to check.
   * @return a FormatTypes enum containing the type, or unknown if the type is not recognized
   */
  public static FormatTypes getDetectionType(JSONObject jsonObject) {
    // type
    String jsonType = new String();
    if (jsonObject.containsKey(TYPE_KEY)) {
      jsonType = jsonObject.get(TYPE_KEY).toString();
    } else {
      return (FormatTypes.Unknown);
    }

    // return appropriate type
    if (jsonType.equals(PICK_TYPE)) {
      return (FormatTypes.Pick);
    } else if (jsonType.equals(CORRELATION_TYPE)) {
      return (FormatTypes.Correlation);
    } else if (jsonType.equals(DETECTION_TYPE)) {
      return (FormatTypes.Detection);
    } else if (jsonType.equals(RETRACT_TYPE)) {
      return (FormatTypes.Retract);
    } else if (jsonType.equals(STATIONINFO_TYPE)) {
      return (FormatTypes.StationInfo);
    } else if (jsonType.equals(STATIONINFOREQUEST_TYPE)) {
      return (FormatTypes.StationInfoRequest);
    } else {
      return (FormatTypes.Unknown);
    }
  }
}
