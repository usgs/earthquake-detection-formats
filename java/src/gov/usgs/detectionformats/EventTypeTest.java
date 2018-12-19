package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class EventTypeTest {
    public static final String EVENTTYPE_STRING = "{\"Type\":\"Earthquake\","
        + "\"Certainty\":\"Suspected\"}";
    public static final String TYPE = "Earthquake";
    public static final String EARTHQUAKE = "Earthquake";
    public static final String MINECOLLAPSE = "MineCollapse";
    public static final String NUCLEAREXPLOSION = "NuclearExplosion";
    public static final String QUARRYBLAST = "QuarryBlast";
    public static final String INDUCED = "InducedOrTriggered";
    public static final String ROCKBURST = "RockBurst";
    public static final String FLUIDINJECTION = "FluidInjection";
    public static final String ICEQUAKE = "IceQuake";
    public static final String VOLCANIC = "VolcanicEruption";
    public static final String CERTAINTY = "Suspected";
    public static final String SUSPECTED = "Suspected";
    public static final String CONFIRMED = "Confirmed";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
		EventType eventTypeObject = new EventType(TYPE, CERTAINTY);

		// write out to a string
		String jsonString = Utility.toJSONString(eventTypeObject.toJSON());

		// check the data
		try {
			CheckData(new EventType(Utility.fromJSONString(jsonString)),
					"WritesJSON");
		} catch (ParseException e) {
			e.printStackTrace();
			fail("exception in WritesJSON");
		}
	}

	/**
	 * Able to read a JSON string
	 */
	@Test
	public void ReadsJSON() {
		try {
			CheckData(new EventType(Utility.fromJSONString(EVENTTYPE_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
			fail("exception in ReadsJSON");
		}
	}

	/**
	 * Constructor fills in members correctly
	 */
	@Test
	public void Constructor() {
		EventType eventTypeObject = new EventType(TYPE, CERTAINTY);
			
		// check data values
		CheckData(eventTypeObject, "Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		EventType emptyObject = new EventType(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void Validate() {
		// build event type object
		EventType eventTypeObject = new EventType(TYPE, CERTAINTY);

		// Successful validation
		boolean rc = eventTypeObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad event type object
		EventType badEventTypeObject = new EventType("chair", "door");

		rc = badEventTypeObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

    /**
	 * Able to run validation function
	 */
	@Test
	public void ValidTypes() {
 		// build event type object
        EventType eventTypeObject = new EventType(EARTHQUAKE, CERTAINTY);
        boolean rc = eventTypeObject.isValid();
        assertEquals("Successful Validation", true, rc);       

        // build event type object
        EventType eventTypeObject2 = new EventType(MINECOLLAPSE, CERTAINTY);
        rc = eventTypeObject2.isValid();
        assertEquals("Successful Validation", true, rc);       

        // build event type object
        EventType eventTypeObject3 = new EventType(NUCLEAREXPLOSION, CERTAINTY);
        rc = eventTypeObject3.isValid();
        assertEquals("Successful Validation", true, rc);       

        // build event type object
        EventType eventTypeObject4 = new EventType(QUARRYBLAST, CERTAINTY);
        rc = eventTypeObject4.isValid();
        assertEquals("Successful Validation", true, rc);       

        // build event type object
        EventType eventTypeObject5 = new EventType(INDUCED, CERTAINTY);
        rc = eventTypeObject5.isValid();
        assertEquals("Successful Validation", true, rc);       

        // build event type object
        EventType eventTypeObject6 = new EventType(ROCKBURST, CERTAINTY);
        rc = eventTypeObject6.isValid();
        assertEquals("Successful Validation", true, rc);       

        // build event type object
        EventType eventTypeObject7 = new EventType(FLUIDINJECTION, CERTAINTY);
        rc = eventTypeObject7.isValid();
        assertEquals("Successful Validation", true, rc);     
        
        // build event type object
        EventType eventTypeObject8 = new EventType(ICEQUAKE, CERTAINTY);
        rc = eventTypeObject8.isValid();
        assertEquals("Successful Validation", true, rc);    

        // build event type object
        EventType eventTypeObject9 = new EventType(VOLCANIC, CERTAINTY);
        rc = eventTypeObject9.isValid();
        assertEquals("Successful Validation", true, rc);    
    }

    /**
	 * Able to run validation function
	 */
	@Test
	public void ValidCertainties() {
 		// build event type object
        EventType eventTypeObject = new EventType(EARTHQUAKE, SUSPECTED);
        boolean rc = eventTypeObject.isValid();
        assertEquals("Successful Validation", true, rc);       

        // build event type object
        EventType eventTypeObject2 = new EventType(EARTHQUAKE, CONFIRMED);
        rc = eventTypeObject2.isValid();
        assertEquals("Successful Validation", true, rc);          
    }

	/**
	 * Empty check function
	 */
	@Test
	public void IsEmpty() {
		// empty object
		EventType eventTypeObject = new EventType();

		// checked for empty
		boolean rc = eventTypeObject.isEmpty();

		// check return code
		assertEquals("Tested for empty.", true, rc);

		// not empty object
		EventType eventTypeObject2 = new EventType(TYPE, CERTAINTY);

		// checked for empty
		rc = eventTypeObject2.isEmpty();

		// check return code
		assertEquals("Tested for not empty.", false, rc);		
	}

	/**
	 * Checks the data in the class
	 */
	public void CheckData(EventType EventTypeObject, String TestName) {
		// check EventTypeObject.type
		if (EventTypeObject.getType() != null) {
			assertEquals(TestName + " Type Equals", TYPE,
				EventTypeObject.getType());
		}

		// check EventTypeObject.certainty
		if (EventTypeObject.getCertainty() != null) {
			assertEquals(TestName + " Certainty Equals", CERTAINTY,
				EventTypeObject.getCertainty());
		}
	}
}
