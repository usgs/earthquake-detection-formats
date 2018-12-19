package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.GregorianCalendar;
import org.json.simple.parser.ParseException;
import org.junit.Test;

public class UtilityTest {
    public static String JSON_STRING = "{\"Key\":\"Value\"}";
    public static String KEY = "Key";
    public static String VALUE = "Value";
    public static String LETTERS = "abcEFghijklmnoP";
    public static String NUMBERS = "-111.5";
    public static String BOTH = "aaaa-111.5ddddczx";
    public static String TIME = "2015-12-28T21:32:24.017Z";
    public static long TIMEMILI = 1451338344017L;
    public static Date DATE = new Date(TIMEMILI);

    /**
	 * Able to convert from a JSON string
	 */
    @Test
    @SuppressWarnings("unchecked")
	public void FromJSONString() {
		try {
			CheckData(Utility.fromJSONString(JSON_STRING),
					"FromJSONString");
		} catch (ParseException e) {
			e.printStackTrace();
			fail("exception in FromJSONString");
		}
	}

    /**
	 * Able to convert to a JSON string
	 */
    @Test
    @SuppressWarnings("unchecked")
	public void ToJSONString() {
        JSONObject aJSONObject = new JSONObject();
        aJSONObject.put(KEY, VALUE);
		try {
			CheckData(Utility.fromJSONString(Utility.toJSONString(aJSONObject)),
					"ToJSONString");
		} catch (ParseException e) {
			e.printStackTrace();
			fail("exception in ToJSONString");
		}
	}

    /**
	 * Check isStringAlpha
	 */
	@Test
	public void IsStringAlpha() {
        assertEquals("Is Alpha", true, Utility.isStringAlpha(LETTERS));

        assertEquals("Is Not Alpha", false, Utility.isStringAlpha(NUMBERS));

        assertEquals("Is Not Alpha (both)", false, Utility.isStringAlpha(BOTH));
	}

    /**
	 * Check isStringNumber
	 */
	@Test
	public void IsStringNumber() {
        assertEquals("Is Number", true, Utility.isStringNumber(NUMBERS));

        assertEquals("Is Not Number", false, Utility.isStringNumber(LETTERS));

        assertEquals("Is Not Number (both)", false, Utility.isStringAlpha(BOTH));
	}

    /**
	 * Check formatDate
	 */
	@Test
	public void FormatDate() {
        assertEquals("Format Date", TIME, Utility.formatDate(Utility.getDate(TIME)));

        assertEquals("Format Date null", null, Utility.formatDate(null));
	}

    /**
	 * Check formatGregorianCalendar
	 */
	@Test
	public void FormatGregorianCalendar() {
        GregorianCalendar calendar = new GregorianCalendar();
        calendar.setTimeInMillis(Utility.getDate(TIME).getTime());
        
        assertEquals("Format Gregorian Calendar", TIME, 
            Utility.formatGregorianCalendar(calendar));

        assertEquals("Format Gregorian Calendar null", null, 
            Utility.formatGregorianCalendar(null));
	}

    /**
	 * Check getXMLGregorianCalendar
	 */
	@Test
	public void getXMLGregorianCalendar() {    
        assertNotEquals("getXMLGregorianCalendar", null, 
            Utility.getXMLGregorianCalendar(TIME));

        assertEquals("getXMLGregorianCalendar null", null, 
            Utility.getXMLGregorianCalendar(null));
	}

    /**
	 * Check formatGregorianCalendar
	 */
	@Test
	public void getDate() {
        assertEquals("Get Date", DATE, Utility.getDate(TIME));

        assertEquals("Get Date null", null, Utility.getDate((String)null));

        // assertEquals("Get Date", DATE, 
        //     Utility.getDate(Utility.getXMLGregorianCalendar(TIME)));
	}

    public void CheckData(JSONObject aJSONObject, String TestName) {
        // key/value
        if (aJSONObject.containsKey(KEY)) {
            assertEquals(TestName + " Value Equals", VALUE,
                aJSONObject.get(KEY).toString());
        } else {
            fail("Key not found");
        }
    }
}