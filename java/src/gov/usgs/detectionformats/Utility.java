package gov.usgs.detectionformats;

import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.TimeZone;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import javax.xml.datatype.DatatypeConstants;
import javax.xml.datatype.DatatypeFactory;
import javax.xml.datatype.XMLGregorianCalendar;

/**
 * a utility class containing functions used by detectionformats.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Utility {

	/**
	 * File Extensions for detectionformats messages
	 */
	public static final String DETECTIONEXTENSION = "jsondetect";
	public static final String PICKEXTENSION = "jsonpick";
	public static final String CORRELATIONEXTENSION = "jsoncorl";
	public static final String STATIONEXTENSION = "jsonsta";

	/** Converts the provided string from a serialized JSON string, populating
	 * members
	 * @param jsonString - A string containing the serialized JSON
	 * @return Returns a JSONObject if successful, null otherwise
	 * @throws ParseException if one occurs
	 */
	public static JSONObject fromJSONString(String jsonString) throws ParseException {
		// use a parser to convert to a string
		JSONParser parser = new JSONParser();
		return((JSONObject) parser.parse(jsonString));
	}

	/** Converts the contents of the class to a serialized JSON string
	 *  @param newJSONObject - A JSONObject containing the JSON object to serialize
	 * @return Returns a String containing the serialized JSON data
	 */
	public static String toJSONString(JSONObject newJSONObject) {
		return(newJSONObject.toJSONString());
	}

	/**
	 * Validates that a string contains just characters
	 *
	 * @param testString
	 *     string to test.
	 * @return Returns true if it does, false otherwise
	 */
	public static boolean isStringAlpha(String testString) {
		// use regex to figure out if this string contains only letters
		return(testString.matches("^[A-Za-z]+$"));
	}

	/**
	 * Validates that a string contains a number
	 *
	 * @param testString
	 *     string to test.
	 * @return Returns true if it does, false otherwise
	 */
	public static boolean isStringNumber(String testString) {
		// use regex to figure out if this string contains a number
		// (decimal point and negative sign allowed)
		return(testString.matches("-?[0-9]+([.][0-9]+)?"));
	}

	/**
	 * Convenience method to format a Date as an XML DateTime String.
	 *
	 * @param date
	 *            the date to format.
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
	 * @param calendar
	 *            the calendar to format.
	 * @return the XML representation as a string.
	 */
	public static String formatGregorianCalendar(
			final GregorianCalendar calendar) {
		try {
			return DatatypeFactory.newInstance()
					.newXMLGregorianCalendar(calendar).normalize()
					.toXMLFormat();
		} catch (Exception e) {
			return null;
		}
	}

	/**
	 * Convenience method to parse an XML Date Time into a Date. Only useful
	 * when the XML Date Time is within the Date object time range.
	 *
	 * @param toParse
	 *            the xml date time string to parse.
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
	 * Convenience method to parse an XML Date Time into a GregorianCalender.
	 *
	 * @param toParse
	 *            the xml date time string to parse.
	 * @return the parsed Date object.
	 */
	public static GregorianCalendar getGregorianCalendar(final String toParse) {
		XMLGregorianCalendar calendar = getXMLGregorianCalendar(toParse);
		if (calendar != null) {
			return calendar.toGregorianCalendar();
		} else {
			return null;
		}
	}

	/**
	 * Parse an XML Date Time into an XMLGregorianCalendar.
	 *
	 * @param toParse
	 *            the xml date time string to parse.
	 * @return the parsed XMLGregorianCalendar object.
	 */
	public static XMLGregorianCalendar getXMLGregorianCalendar(
			final String toParse) {
		try {
			return DatatypeFactory.newInstance().newXMLGregorianCalendar(
					toParse);
		} catch (Exception e) {
			return null;
		}
	}

	/**
	 * Converts an XMLGregorianCalendar to a Date.
	 *
	 * @param xmlDate
	 *            XMLGregorianCalendar to convert.
	 * @return corresponding date object.
	 */
	public static Date getDate(final XMLGregorianCalendar xmlDate) {
		// TODO: is this equivalent to getDate(String) processing above??

		// start with UTC, i.e. no daylight savings time.
		TimeZone timezone = TimeZone.getTimeZone("GMT");

		// adjust timezone to match xmldate
		int offsetMinutes = xmlDate.getTimezone();
		if (offsetMinutes != DatatypeConstants.FIELD_UNDEFINED) {
			timezone.setRawOffset(
			// convert minutes to milliseconds
			offsetMinutes * 60 // seconds per minute
			* 1000 // milliseconds per second
			);
		}

		// use calendar so parsed date will be UTC
		Calendar calendar = Calendar.getInstance(timezone);
		calendar.clear();
		calendar.set(xmlDate.getYear(),
				// xmlcalendar is 1 based, calender is 0 based
				xmlDate.getMonth() - 1, xmlDate.getDay(), xmlDate.getHour(),
				xmlDate.getMinute(), xmlDate.getSecond());
		Date date = calendar.getTime();
		int millis = xmlDate.getMillisecond();
		if (millis != DatatypeConstants.FIELD_UNDEFINED) {
			calendar.setTimeInMillis(calendar.getTimeInMillis() + millis);
		}

		return date;
	}
}
