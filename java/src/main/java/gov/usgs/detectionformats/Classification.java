package gov.usgs.detectionformats;

import java.util.ArrayList;

import org.json.simple.*;

/**
 * a conversion class used to create, parse, and validate value added 
 * classification data from advanced algorithms such as machine learning as part 
 * of detectionformats data.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Classification implements DetectionInt {
	/**
	 * JSON Keys
	 */
    public static final String PHASE_KEY = "Phase";
    public static final String PHASEPROB_KEY = "PhaseProbability";
    public static final String DISTANCE_KEY = "Distance";
    public static final String DISTANCEPROB_KEY = "DistanceProbability";
    public static final String BACKAZIMUTH_KEY = "Backazimuth";
    public static final String BACKAZIMUTHPROB_KEY = "BackazimuthProbability";
    public static final String MAGNITUDE_KEY = "Magnitude";
    public static final String MAGNITUDETYPE_KEY = "MagnitudeType";
    public static final String MAGNITUDEPROB_KEY = "MagnitudeProbability";
    public static final String DEPTH_KEY = "Depth";
    public static final String DEPTHPROB_KEY = "DepthProbability";
    public static final String EVENTTYPE_KEY = "EventType";
    public static final String EVENTTYPEPROB_KEY = "EventTypeProbability";
    public static final String SOURCE_KEY = "Source";

    /**
	 * An optional private final String containing classification phase name.
	 */
	private final String phase;

	/**
	 * An optional private final Double containing the probability of the 
     * classification phase name
	 */
	private final Double phaseProbability;

	/**
	 * An optional private final Double containing the classification distance
	 */
	private final Double distance;

	/**
	 * An optional private final Double containing the probability of the 
     * classification distance
	 */
	private final Double distanceProbability;

	/**
	 * An optional private final Double containing the classification backazimuth
	 */
	private final Double backazimuth;

	/**
	 * An optional private final Double containing the probability of the 
     * classification backazimuth
	 */
	private final Double backazimuthProbability;

	/**
	 * An optional private final Double containing the classification magnitude
	 */
	private final Double magnitude;

    /**
	 * An optional private final String containing the classification magnitude 
     * type
	 */
    private final String magnitudeType;

	/**
	 * An optional private final Double containing the probability of the 
     * classification magnitude
	 */
	private final Double magnitudeProbability;

	/**
	 * An optional private final Double containing the classification depth
	 */
	private final Double depth;

    /**
	 * An optional private final Double containing the probability of the 
     * classification depth
	 */
	private final Double depthProbability;

    /**
	 * An optional EventType containing the classification 
     * event type
	 */
	private final EventType eventType;

    /**
	 * An optional private final Double containing the probability of the 
     * classification  event type
	 */
	private final Double eventTypeProbability;

    /**
	 * An optional Source containing the source of this classification information
	 */
	private final Source source;

	/**
	 * The constructor for the Classification class. Initializes members to null
	 * values.
	 */
	public Classification() {
        phase = null;
        phaseProbability = null;
        distance = null;
        distanceProbability = null;
        backazimuth = null;
        backazimuthProbability = null;
        magnitude = null;
        magnitudeType = null;
        magnitudeProbability = null;
        depth = null;
        depthProbability = null;
        eventType = null;
        eventTypeProbability = null;
        source = null;
	}

	/**
     * Advanced constructor
     * 
	 * The advanced constructor for the Classification class. Initializes 
     * members to provided values.
	 *
	 * @param newPhase
	 *            - A String containing the phase name to use (null omit)
     * @param newPhaseProb 
     *            - A Double containing the probability of the phase estimate
     * (null omit)
	 * @param newDistance
	 *            - A private final Double containing the distance to use (null 
     * omit)
     * @param newDistanceProb 
     *            - A Double containing the probability of the distance estimate
     * (null omit)
	 * @param newBackazimuth
	 *            - A private final Double containing the backazimuth to use (null 
     * omit)
     * @param newBackazimuthProb 
     *            - A Double containing the probability of the backazimuth estimate 
     * (null omit)
     * @param newMagnitude 
     *            - A Double containing the magnitude to use (null omit)
     * @param newMagType 
     *            - A String containing the magnitude type to use (null omit)
     * @param newMagProb 
     *            - A Double containing the probability of the magnitude 
     * estimate (null omit)
     * @param newDepth 
     *            - A Double containing the depth to use (null omit)
     * @param newDepthProb 
     *            - A Double containing the probability of the depth estimate
     * (null omit)
     * @param newEventType 
     *            - A String containing the event type to use (null omit)
	 * @param newEventTypeCertainty 
     *            - A String containing the event type certainty to use (null 
     * omit)
     * @param newEventTypeProb 
     *            - A Double containing the probability of the event type 
     * estimate (null omit)
     * @param newAgencyID
	 *            - A String containing the classifing agency id to use (null 
     * omit)
	 * @param newAuthor
	 *            - A String containing the classifing author to use (null omit)
	 */
	public Classification(String newPhase, Double newPhaseProb,
            Double newDistance, Double newDistanceProb, Double newBackazimuth,
            Double newBackazimuthProb, Double newMagnitude, String newMagType,
            Double newMagProb, Double newDepth, Double newDepthProb,
            String newEventType, String newEventTypeCertainty,
            Double newEventTypeProb, String newAgencyID,
            String newAuthor) {
        this(newPhase, newPhaseProb, newDistance, newDistanceProb, newBackazimuth,
                newBackazimuthProb, newMagnitude, newMagType, newMagProb, newDepth, 
                newDepthProb, new EventType(newEventType, newEventTypeCertainty), 
                newEventTypeProb, new Source(newAgencyID, newAuthor));
	}

    /**
     * Alternate Advanced constructor
     * 
	 * The alternate advanced constructor for the Classification class.  
     * Initializes members to provided values.
	 *
	 * @param newPhase
	 *            - A String containing the phase name to use (null omit)
     * @param newPhaseProb 
     *            - A Double containing the probability of the phase estimate
     * (null omit)
	 * @param newDistance
	 *            - A private final Double containing the distance to use (null 
     * omit)
     * @param newDistanceProb 
     *            - A Double containing the probability of the distance estimate
     * (null omit)
	 * @param newBackazimuth
	 *            - A private final Double containing the backazimuth to use (null 
     * omit)
     * @param newBackazimuthProb 
     *            - A Double containing the probability of the backazimuth estimate 
     * (null omit)
     * @param newMagnitude 
     *            - A Double containing the magnitude to use (null omit)
     * @param newMagType 
     *            - A String containing the magnitude type to use (null omit)
     * @param newMagProb 
     *            - A Double containing the probability of the magnitude 
     * estimate (null omit)
     * @param newDepth 
     *            - A Double containing the depth to use (null omit)
     * @param newDepthProb 
     *            - A Double containing the probability of the depth estimate
     * (null omit)
     * @param newEventType 
     *            - An EventType object containing the event type to use (null 
     * omit)
     * @param newEventTypeProb 
     *            - A Double containing the probability of the event type 
     * estimate (null omit)
     * @param newSource
	 *            - A Source object classifing source to use (null omit)
	 */
	public Classification(String newPhase, Double newPhaseProb,
            Double newDistance, Double newDistanceProb, Double newBackazimuth,
            Double newBackazimuthProb, Double newMagnitude, String newMagType,
            Double newMagProb, Double newDepth, Double newDepthProb,
            EventType newEventType, Double newEventTypeProb, Source newSource) {
        phase = newPhase;
        phaseProbability = newPhaseProb;
        distance = newDistance;
        distanceProbability = newDistanceProb;
        backazimuth = newBackazimuth;
        backazimuthProbability = newBackazimuthProb;
        magnitude = newMagnitude;
        magnitudeType = newMagType;
        magnitudeProbability = newMagProb;
        depth = newDepth;
        depthProbability = newDepthProb;
        eventType = newEventType;
        eventTypeProbability = newEventTypeProb;
        source = newSource;
	}

	/**
	 * Constructs the class from a JSONObject, populating members
	 *
	 * @param newJSONObject
	 *            - A JSONObject.
	 */
	public Classification(JSONObject newJSONObject) {
		// optional values
		// phase
		if (newJSONObject.containsKey(PHASE_KEY)) {
			phase = newJSONObject.get(PHASE_KEY).toString();
		} else {
			phase = null;
		}

        // phaseProbability
        if (newJSONObject.containsKey(PHASEPROB_KEY)) {
            phaseProbability = (double) newJSONObject.get(PHASEPROB_KEY);
        } else {
            phaseProbability = null;
        }

		// distance
		if (newJSONObject.containsKey(DISTANCE_KEY)) {
			distance = (double) newJSONObject.get(DISTANCE_KEY);
		} else {
			distance = null;
        }
        
		// distanceProbability
		if (newJSONObject.containsKey(DISTANCEPROB_KEY)) {
            distanceProbability = (double) newJSONObject.get(DISTANCEPROB_KEY);
		} else {
			distanceProbability = null;
		}        

		// backazimuth
		if (newJSONObject.containsKey(BACKAZIMUTH_KEY)) {
			backazimuth = (double) newJSONObject.get(BACKAZIMUTH_KEY);
		} else {
			backazimuth = null;
        }
        
		// backazimuthProbability
		if (newJSONObject.containsKey(BACKAZIMUTHPROB_KEY)) {
            backazimuthProbability = (double) newJSONObject.get(BACKAZIMUTHPROB_KEY);
		} else {
			backazimuthProbability = null;
		}        

		// magnitude
		if (newJSONObject.containsKey(MAGNITUDE_KEY)) {
			magnitude = (double) newJSONObject.get(MAGNITUDE_KEY);
		} else {
			magnitude = null;
		}

        // magnitudeType
        if (newJSONObject.containsKey(MAGNITUDETYPE_KEY)) {
            magnitudeType = newJSONObject.get(MAGNITUDETYPE_KEY).toString();
        } else {
            magnitudeType = null;
        }

		// magnitudeProbability
		if (newJSONObject.containsKey(MAGNITUDEPROB_KEY)) {
            magnitudeProbability = (double) newJSONObject.get(MAGNITUDEPROB_KEY);
		} else {
			magnitudeProbability = null;
        }
        
		// depth
		if (newJSONObject.containsKey(DEPTH_KEY)) {
			depth = (double) newJSONObject.get(DEPTH_KEY);
		} else {
			depth = null;
        }
        
		// depthProbability
		if (newJSONObject.containsKey(DEPTHPROB_KEY)) {
            depthProbability = 
                (double) newJSONObject.get(DEPTHPROB_KEY);
		} else {
			depthProbability = null;
        }     
        
        // eventType
		if (newJSONObject.containsKey(EVENTTYPE_KEY)) {
            eventType = 
                new EventType((JSONObject) newJSONObject.get(EVENTTYPE_KEY));
		} else {
			eventType = null;
        }
        
        // eventTypeProbability
        if (newJSONObject.containsKey(EVENTTYPEPROB_KEY)) {
            eventTypeProbability = (double) newJSONObject.get(EVENTTYPEPROB_KEY);
        } else {
            eventTypeProbability = null;
        } 

        // source
		if (newJSONObject.containsKey(SOURCE_KEY)) {
			source = new Source((JSONObject) newJSONObject.get(SOURCE_KEY));
		} else {
			source = null;
		}
	}

	/**
	 * Converts the contents of the class to a json object Overridden from
	 * DetectionBase.
	 *
	 * @return Returns a JSONObject containing the class contents
	 */
	@SuppressWarnings("unchecked")
	public JSONObject toJSON() {
		JSONObject newJSONObject = new JSONObject();

        String jsonPhase = getPhase();
        Double jsonPhaseProb = getPhaseProbability();
		Double jsonDistance = getDistance();
		Double jsonDistanceProb = getDistanceProbability();
		Double jsonBackazimuth = getBackazimuth();
		Double jsonBackazimuthProb = getBackazimuthProbability();
        Double jsonMagnitude = getMagnitude();
		String jsonMagnitudeType = getMagnitudeType();
		Double jsonMagnitudeProb = getMagnitudeProbability();
		Double jsonDepth = getDepth();
        Double jsonDepthProb = getDepthProbability();
		EventType jsonEventType = getEventType();
		Double jsonEventTypeProb = getEventTypeProbability();
		Source jsonSource = getSource();

		// optional values
		// phase
		if (jsonPhase != null) {
			newJSONObject.put(PHASE_KEY, jsonPhase);
        }
        
        // phaseProbability
		if (jsonPhaseProb != null) {
			newJSONObject.put(PHASEPROB_KEY, jsonPhaseProb);
		}

        // distance
		if (jsonDistance != null) {
			newJSONObject.put(DISTANCE_KEY, jsonDistance);
        }
        
        // distanceProbability
		if (jsonDistanceProb != null) {
			newJSONObject.put(DISTANCEPROB_KEY, jsonDistanceProb);
		}        

		// backazimuth
		if (jsonBackazimuth != null) {
			newJSONObject.put(BACKAZIMUTH_KEY, jsonBackazimuth);
        }
        
        // backazimuthProbability
		if (jsonBackazimuthProb != null) {
			newJSONObject.put(BACKAZIMUTHPROB_KEY, jsonBackazimuthProb);
		}

		// magnitude
		if (jsonMagnitude != null) {
			newJSONObject.put(MAGNITUDE_KEY, jsonMagnitude);
        }
        
        // magnitudeType
        if (jsonMagnitudeType != null) {
            newJSONObject.put(MAGNITUDETYPE_KEY, jsonMagnitudeType);
        }

		// magnitudeProbability
		if (jsonMagnitudeProb != null) {
			newJSONObject.put(MAGNITUDEPROB_KEY, jsonMagnitudeProb);
		}

		// depth
		if (jsonDepth != null) {
			newJSONObject.put(DEPTH_KEY, jsonDepth);
        }
        
        // depthProbability
		if (jsonDepthProb != null) {
			newJSONObject.put(DEPTHPROB_KEY, jsonDepthProb);
        }

        // eventType
        if (jsonEventType != null) {
            newJSONObject.put(EVENTTYPE_KEY, jsonEventType.toJSON());
        }  

        // eventTypeProbability
		if (jsonEventTypeProb != null) {
			newJSONObject.put(EVENTTYPEPROB_KEY, jsonEventTypeProb);
		}

        // source
        if (jsonSource != null) {
            newJSONObject.put(SOURCE_KEY, jsonSource.toJSON());
        }

		return (newJSONObject);
	}

	/**
	 * Validates the class.
	 *
	 * @return Returns true if successful
	 */
	public boolean isValid() {
		if (getErrors().size() == 0) {
			return (true);
		} else {
			return (false);
		}
	}

	/**
	 * Gets any validation errors in the class.
	 *
	 * @return Returns a List&lt;String&gt; of any errors found
	 */
	public ArrayList<String> getErrors() {
		String jsonPhase = getPhase();
 		Double jsonDistance = getDistance();
		Double jsonBackazimuth = getBackazimuth();
	    Double jsonMagnitude = getMagnitude();
		Double jsonDepth = getDepth();
		EventType jsonEventType = getEventType();
		Source jsonSource = getSource();

		ArrayList<String> errorList = new ArrayList<String>();

		// Optional Keys
		// phase
		if (jsonPhase != null) {
			// check phase string
			if (jsonPhase.isEmpty()) {
				// phase empty
				errorList.add("Empty Phase in Classification Class.");
			} else if (!Utility.isStringAlpha(jsonPhase)) {
				// invalid phase
				errorList.add("Phase did not validate in Classification class.");
			}
		}

		// distance
		if (jsonDistance != null) {
			// check distance
			if (jsonDistance < 0) {
				// distance negative (invalid)
				errorList.add("Invalid Distance in Classification Class.");
			}
		}

		// backazimuth
		if (jsonBackazimuth != null) {
			// check backazimuth
			if (jsonBackazimuth < 0) {
				// backazimuth negative (invalid)
				errorList.add("Invalid Backazimuth in Classification Class.");
			}
		}

        // magnitude
        if (jsonMagnitude != null) {
            // check magnitude
            if ((jsonMagnitude < -2) || (jsonMagnitude > 10)) {
                // magnitude invalid
                errorList.add("Invalid Magnitude in Classification Class.");
            }
        }

        // depth
		if (jsonDepth != null) {
			// check depth
			if ((jsonDepth < -100) || (jsonDepth > 1500)) {
				// depth invalid
				errorList.add("Invalid Depth in Classification Class.");
			}
		}

        // eventType
        if ((jsonEventType != null) && (!jsonEventType.isEmpty())) {
            if (!jsonEventType.isValid()) {
                // event type invalid
                errorList.add("Invalid EventType in Classification Class.");
            }
        }

        // source
        if ((jsonSource != null) && (!jsonSource.isEmpty())) {
            if (!jsonSource.isValid()) {
                // source invalid
                errorList.add("Invalid Source in Classification Class.");
            }
        }

		// success
		return (errorList);
	}

	/**
	 * Checks to see if this object is empty
	 *
	 * @return Returns true if empty, false otherwise.
	 */
	public boolean isEmpty() {
		if (getPhase() != null) {
			return (false);
        }
        if (getPhaseProbability() != null) {
			return (false);
		}
		if (getDistance() != null) {
			return (false);
		}
		if (getDistanceProbability() != null) {
			return (false);
		}
		if (getBackazimuth() != null) {
			return (false);
		}
		if (getBackazimuthProbability() != null) {
			return (false);
		}
		if (getMagnitude() != null) {
			return (false);
		}
		if (getMagnitudeType() != null) {
			return (false);
		}
		if (getMagnitudeProbability() != null) {
			return (false);
		}
		if (getDepth() != null) {
			return (false);
        }
		if (getDepthProbability() != null) {
			return (false);
		}
		if (getEventType() != null) {
			return (false);
		}
		if (getEventTypeProbability() != null) {
			return (false);
        }       
		if (getSource() != null) {
			return (false);
		}            
		return (true);
	}

	/**
	 * @return the phase
	 */
	public String getPhase() {
		return phase;
	}

	/**
	 * @return the phaseProbability
	 */
	public Double getPhaseProbability() {
		return phaseProbability;
	}

	/**
	 * @return the distance
	 */
	public Double getDistance() {
		return distance;
	}

	/**
	 * @return the distanceProbability
	 */
	public Double getDistanceProbability() {
		return distanceProbability;
    }
        
	/**
	 * @return the backazimuth
	 */
	public Double getBackazimuth() {
		return backazimuth;
	}

	/**
	 * @return the backazimuthProbability
	 */
	public Double getBackazimuthProbability() {
		return backazimuthProbability;
	}

	/**
	 * @return the magnitude
	 */
	public Double getMagnitude() {
		return magnitude;
	}

    /**
	 * @return the magnitudeType
	 */
	public String getMagnitudeType() {
		return magnitudeType;
	}

	/**
	 * @return the magnitudeProbability
	 */
	public Double getMagnitudeProbability() {
		return magnitudeProbability;
    }
  
	/**
	 * @return the depth
	 */
	public Double getDepth() {
		return depth;
	}    

	/**
	 * @return the depthProbability
	 */
	public Double getDepthProbability() {
		return depthProbability;
	}  

    /**
	 * @return the eventType
	 */
	public EventType getEventType() {
		return eventType;
	}

	/**
	 * @return the eventTypeProbability
	 */
	public Double getEventTypeProbability() {
		return eventTypeProbability;
    }

    /**
	 * @return the source
	 */
	public Source getSource() {
		return source;
	}
}
