package gov.usgs.detectionformats;

import org.json.simple.JSONObject;

import static org.junit.Assert.*;

import org.json.simple.parser.ParseException;
import org.junit.Test;

public class ClassificationTest {

    public static final String CLASSIFICATION_STRING = "{\"Phase\":\"P\","
            + "\"PhaseProbability\":0.22,\"Distance\":0.442559," 
            + "\"DistanceProbability\":22.5,\"Azimuth\":0.418479," 
            + "\"AzimuthProbability\":0.16,\"Magnitude\":2.14,"
            + "\"MagnitudeType\":\"Mb\",\"MagnitudeProbability\":0.55,"
            + "\"Depth\":32.44,\"DepthProbability\":11.2,"
            + "\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},"
            + "\"EventTypeProbability\":1.1,\"Source\":{\"AgencyID\":\"US\","
            + "\"Author\":\"TestAuthor\"}}";
	
	public static final String PHASE = "P";
    public static final double PHASEPROBABILITY = 0.22;
    public static final double DISTANCE = 0.442559;
    public static final double DISTANCEPROBABILITY = 22.5;
    public static final double AZIMUTH = 0.418479;
    public static final double AZIMUTHPROBABILITY = 0.16;
    public static final double MAGNITUDE = 2.14;
    public static final String MAGNITUDETYPE = "Mb";
    public static final double MAGNITUDEPROBABILITY = 0.55;
    public static final double DEPTH = 32.44;
    public static final double DEPTHPROBABILITY = 11.2;
    public static final String EVENTTYPE = "Earthquake";
    public static final String CERTAINTY = "Suspected";
    public static final double EVENTTYPEPROBABILITY = 1.1;
    public static final String AGENCYID = "US";
    public static final String AUTHOR = "TestAuthor";

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void WritesJSON() {
        Classification classificationObject = new Classification(PHASE, 
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH, 
            AZIMUTHPROBABILITY, MAGNITUDE, MAGNITUDETYPE, MAGNITUDEPROBABILITY,
            DEPTH, DEPTHPROBABILITY, EVENTTYPE, CERTAINTY, EVENTTYPEPROBABILITY,
			AGENCYID, AUTHOR);

		// write out to a string
		String jsonString = Utility.toJSONString(classificationObject.toJSON());

		// check the data
		try {
			CheckData(new Classification(Utility.fromJSONString(jsonString)),
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
		// build Classification object
		try {
			CheckData(
				new Classification(Utility.fromJSONString(CLASSIFICATION_STRING)),
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
		Classification classificationObject = new Classification(PHASE, 
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH, 
            AZIMUTHPROBABILITY, MAGNITUDE, MAGNITUDETYPE, MAGNITUDEPROBABILITY,
            DEPTH, DEPTHPROBABILITY, EVENTTYPE, CERTAINTY, EVENTTYPEPROBABILITY,
            AGENCYID, AUTHOR);

		// check data values
		CheckData(classificationObject, "Constructor");

        Classification classificationObject2 = new Classification(PHASE, 
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH, 
            AZIMUTHPROBABILITY, MAGNITUDE, MAGNITUDETYPE, MAGNITUDEPROBABILITY,
            DEPTH, DEPTHPROBABILITY, new EventType(EVENTTYPE, CERTAINTY), 
            EVENTTYPEPROBABILITY, new Source(AGENCYID, AUTHOR));

        // check data values
        CheckData(classificationObject2, "Alternate Constructor");

		// empty constructor
		JSONObject emptyJSONObject = new JSONObject();
		Classification emptyObject = new Classification(emptyJSONObject);

		// check the data
		CheckData(emptyObject, "Empty Constructor");		
	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {
		Classification classificationObject = new Classification(PHASE, 
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH, 
            AZIMUTHPROBABILITY, MAGNITUDE, MAGNITUDETYPE, MAGNITUDEPROBABILITY,
            DEPTH, DEPTHPROBABILITY, EVENTTYPE, CERTAINTY, EVENTTYPEPROBABILITY,
			AGENCYID, AUTHOR);

		// Successful validation
		boolean rc = classificationObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Classification object
		Classification badClassificationObject = new Classification("22", null,
            -99.0, null, -99.0, null, -99.0, null, null, -9999.0, null, "chair",
            "bleh", null, "","");

		rc = badClassificationObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	/**
	 * Empty check function
	 */
	@Test
	public void IsEmpty() {
		// empty object
		Classification classificationObject = new Classification();

		// checked for empty
		boolean rc = classificationObject.isEmpty();

		// check return code
		assertEquals("Tested for empty.", true, rc);

		// not empty object
		Classification classificationObject2 = new Classification(PHASE, 
            PHASEPROBABILITY, DISTANCE, DISTANCEPROBABILITY, AZIMUTH, 
            AZIMUTHPROBABILITY, MAGNITUDE, MAGNITUDETYPE, MAGNITUDEPROBABILITY,
            DEPTH, DEPTHPROBABILITY, EVENTTYPE, CERTAINTY, EVENTTYPEPROBABILITY,
			AGENCYID, AUTHOR);

		// checked for empty
		rc = classificationObject2.isEmpty();

		// check return code
		assertEquals("Tested for not empty.", false, rc);		
	}

	/**
	 * Checks the data in the class
	 */
	public void CheckData(Classification ClassificationObject, String TestName) {
		// check ClassificationObject.phase
		if (ClassificationObject.getPhase() != null) {
			assertEquals(TestName + " Phase Equals", PHASE,
				ClassificationObject.getPhase());
		}

        // check ClassificationObject.phaseProbability
		if (ClassificationObject.getPhaseProbability() != null) {
            assertEquals(TestName + " Phase Probability Equals", 
                PHASEPROBABILITY, ClassificationObject.getPhaseProbability(), 0);
		}

		// check ClassificationObject.distance
		if (ClassificationObject.getDistance() != null) {
			assertEquals(TestName + " Distance Equals", DISTANCE,
			    ClassificationObject.getDistance(), 0);
        }
        
        // check ClassificationObject.distanceProbability
		if (ClassificationObject.getDistanceProbability() != null) {
            assertEquals(TestName + " Distance Probability Equals", 
                DISTANCEPROBABILITY, 
                ClassificationObject.getDistanceProbability(), 0);
		}        

		// check ClassificationObject.Azimuth
		if (ClassificationObject.getAzimuth() != null) {
			assertEquals(TestName + " Azimuth Equals", AZIMUTH,
				ClassificationObject.getAzimuth(), 0);
        }
        
        // check ClassificationObject.azimuthProbability
		if (ClassificationObject.getAzimuthProbability() != null) {
            assertEquals(TestName + " Azimuth Probability Equals", 
                AZIMUTHPROBABILITY, 
                ClassificationObject.getAzimuthProbability(), 0);
		}             

		// check ClassificationObject.magnitude
		if (ClassificationObject.getMagnitude() != null) {
			assertEquals(TestName + " Magnitude Equals", MAGNITUDE,
				ClassificationObject.getMagnitude(), 0);
		}

		// check ClassificationObject.magnitudeType
		if (ClassificationObject.getMagnitudeType() != null) {
			assertEquals(TestName + " Magnitude Type Equals", MAGNITUDETYPE,
				ClassificationObject.getMagnitudeType());
        }

        // check ClassificationObject.magnitudeProbability
		if (ClassificationObject.getMagnitudeProbability() != null) {
            assertEquals(TestName + " Magnitude Probability Equals", 
                MAGNITUDEPROBABILITY, 
                ClassificationObject.getMagnitudeProbability(), 0);
        }

        // check ClassificationObject.depth
		if (ClassificationObject.getDepth() != null) {
			assertEquals(TestName + " Depth Equals", DEPTH,
				ClassificationObject.getDepth(), 0);
        }

        // check ClassificationObject.depthProbability
		if (ClassificationObject.getDepthProbability() != null) {
            assertEquals(TestName + " Depth Probability Equals", 
                DEPTHPROBABILITY,
				ClassificationObject.getDepthProbability(), 0);
        }

        // check ClassificationObject.eventType
		if (ClassificationObject.getEventType() != null) {
			// check ClassificationObject.EventType.type
			if (ClassificationObject.getEventType().getType() != null) {
				assertEquals(TestName + " Type Equals", EVENTTYPE,
                    ClassificationObject.getEventType().getType());
			}

			// check ClassificationObject.EventType.certainty
			if (ClassificationObject.getEventType().getCertainty() != null) {
				assertEquals(TestName + " Certantity Equals", CERTAINTY,
                ClassificationObject.getEventType().getCertainty());
			}
		}
        
        // check ClassificationObject.eventTypeProbability
		if (ClassificationObject.getEventTypeProbability() != null) {
            assertEquals(TestName + " Event Type Probability Equals", 
                EVENTTYPEPROBABILITY,
				ClassificationObject.getEventTypeProbability(), 0);
        }

        // check ClassificationObject.source
		if (ClassificationObject.getSource() != null) {
			// check ClassificationObject.Source.AgencyID
			if (ClassificationObject.getSource().getAgencyID() != null) {
				assertEquals(TestName + " AgencyID Equals", AGENCYID,
                    ClassificationObject.getSource().getAgencyID());
			}

			// check ClassificationObject.Source.Author
			if (ClassificationObject.getSource().getAuthor() != null) {
				assertEquals(TestName + " Author Equals", AUTHOR,
                    ClassificationObject.getSource().getAuthor());
			}
		}      
	}
}
