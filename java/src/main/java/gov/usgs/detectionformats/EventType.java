package gov.usgs.detectionformats;

import java.util.ArrayList;
import org.json.simple.JSONObject;

/**
 * a conversion class used to create, parse, and validate source data as part of detection data.
 * Detection formats supports a subset of the QuakeML 1.2 event types that are automatically
 * classifiable.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class EventType implements DetectionInt {

  /** JSON Keys */
  public static final String TYPE_KEY = "Type";

  public static final String CERTAINTY_KEY = "Certainty";

  /** Optional event type */
  private final String type;

  /** Optional event type certantity */
  private final String certainty;

  /** The constructor for the EventType class. Initializes members to null values. */
  public EventType() {

    type = null;
    certainty = null;
  }

  /**
   * The advanced constructor for the EventType class. Initializes members to provided values.
   *
   * @param newType - A String containing the event type to use
   * @param newCertainty - A String containing the certainty to use
   */
  public EventType(String newType, String newCertainty) {

    type = newType;
    certainty = newCertainty;
  }

  /**
   * Constructs the class from a JSONObject, populating members
   *
   * @param newJSONObject - A JSONObject.
   */
  public EventType(JSONObject newJSONObject) {

    // optional values
    // type
    if (newJSONObject.containsKey(TYPE_KEY)) {
      type = newJSONObject.get(TYPE_KEY).toString();
    } else {
      type = null;
    }

    // certainty
    if (newJSONObject.containsKey(CERTAINTY_KEY)) {
      certainty = newJSONObject.get(CERTAINTY_KEY).toString();
    } else {
      certainty = null;
    }
  }

  /**
   * Converts the contents of the class to a JSONObject
   *
   * @return Returns a JSONObject containing the class contents
   */
  @SuppressWarnings("unchecked")
  public JSONObject toJSON() {

    JSONObject newJSONObject = new JSONObject();

    String jsonType = getType();
    String jsonCertainty = getCertainty();

    // required values
    // agencyID
    if ((jsonType != null) && (!jsonType.isEmpty())) {
      newJSONObject.put(TYPE_KEY, jsonType);
    }

    // certainty
    if ((jsonCertainty != null) && (!jsonCertainty.isEmpty())) {
      newJSONObject.put(CERTAINTY_KEY, jsonCertainty);
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
    String jsonType = getType();
    String jsonCertainty = getCertainty();

    ArrayList<String> errorList = new ArrayList<String>();

    // check for optional keys
    // type
    if ((jsonType != null) && (!jsonType.isEmpty())) {
      boolean match = false;
      if (jsonType.equals("Earthquake")) {
        match = true;
      } else if (jsonType.equals("MineCollapse")) {
        match = true;
      } else if (jsonType.equals("NuclearExplosion")) {
        match = true;
      } else if (jsonType.equals("QuarryBlast")) {
        match = true;
      } else if (jsonType.equals("InducedOrTriggered")) {
        match = true;
      } else if (jsonType.equals("RockBurst")) {
        match = true;
      } else if (jsonType.equals("FluidInjection")) {
        match = true;
      } else if (jsonType.equals("IceQuake")) {
        match = true;
      } else if (jsonType.equals("VolcanicEruption")) {
        match = true;
      } else {
        match = false;
      }

      if (!match) {
        // invalid eventType
        errorList.add("Invalid Type in EventType Class.");
      }
    }

    // certainty
    if ((jsonCertainty != null) && (!jsonCertainty.isEmpty())) {
      boolean match = false;
      if (jsonCertainty.equals("Suspected")) {
        match = true;
      } else if (jsonCertainty.equals("Confirmed")) {
        match = true;
      } else {
        match = false;
      }

      if (!match) {
        // invalid Certainty
        errorList.add("Invalid Certainty in EventType Class.");
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
    if (getType() != null) {
      return (false);
    }
    if (getCertainty() != null) {
      return (false);
    }
    return (true);
  }

  /** @return the type */
  public String getType() {
    return type;
  }

  /** @return the certainty */
  public String getCertainty() {
    return certainty;
  }
}
