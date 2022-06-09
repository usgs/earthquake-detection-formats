package gov.usgs.detectionformats;

import java.util.*;
import org.json.simple.JSONObject;

/**
 * a conversion class used to create, parse, and validate detection retraction messages
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Retract implements DetectionInt {

  /** JSON Keys */
  public static final String TYPE_KEY = "Type";

  public static final String ID_KEY = "ID";
  public static final String SOURCE_KEY = "Source";

  /** Required type identifier for this Retract */
  private final String type;

  /** Required unique identifier for this Retract */
  private final String id;

  /** Required source. */
  private final Source source;

  /** The constructor for the Retract class. Initializes members to null values. */
  public Retract() {
    type = "Retract";
    source = null;
    id = null;
  }

  /**
   * Advanced constructor
   *
   * <p>The advanced constructor for the Retract class. Initializes members to provided values.
   *
   * @param newID - A String containing the id to use
   * @param newAgencyID - A String containing the agencyid to use
   * @param newAuthor - A String containing the author to use
   */
  public Retract(String newID, String newAgencyID, String newAuthor) {
    this(newID, new Source(newAgencyID, newAuthor));
  }

  /**
   * Alternate advanced constructor
   *
   * <p>The alternate advanced constructor for the Retract class. Initializes members to provided
   * values.
   *
   * @param newID - A String containing the id to use
   * @param newSource - A Source Object containing the source to use
   */
  public Retract(String newID, Source newSource) {

    type = "Retract";
    id = newID;
    source = newSource;
  }

  /**
   * Constructs the class from a JSONObject, populating members
   *
   * @param newJSONObject - A JSONObject.
   */
  public Retract(JSONObject newJSONObject) {

    // Required values
    // type
    if (newJSONObject.containsKey(TYPE_KEY)) {
      type = newJSONObject.get(TYPE_KEY).toString();
    } else {
      type = null;
    }

    // id
    if (newJSONObject.containsKey(ID_KEY)) {
      id = newJSONObject.get(ID_KEY).toString();
    } else {
      id = null;
    }

    // source
    if (newJSONObject.containsKey(SOURCE_KEY)) {
      source = new Source((JSONObject) newJSONObject.get(SOURCE_KEY));
    } else {
      source = null;
    }
  }

  /**
   * Converts the contents of the class to a json object
   *
   * @return Returns a JSONObject containing the class contents
   */
  @SuppressWarnings("unchecked")
  public JSONObject toJSON() {

    JSONObject newJSONObject = new JSONObject();

    String jsonType = getType();
    String jsonID = getID();
    Source jsonSource = getSource();

    // Required values
    // Type
    newJSONObject.put(TYPE_KEY, jsonType);

    // id
    if (jsonID != null) {
      newJSONObject.put(ID_KEY, jsonID);
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

    String jsonType = getType();
    String jsonID = getID();
    Source jsonSource = getSource();

    ArrayList<String> errorList = new ArrayList<String>();

    // Required Keys
    // type
    if (jsonType == null) {
      // type not found
      errorList.add("No Type in Retract Class.");
    } else if (jsonType.isEmpty()) {
      // type empty
      errorList.add("Empty Type in Retract Class.");
    } else if (!jsonType.equals("Retract")) {
      // wrong type
      errorList.add("Non-Retract type in Retract Class.");
    }

    // id
    if (jsonID == null) {
      // id not found
      errorList.add("No ID in Retract Class.");
    } else if (jsonID.isEmpty()) {
      // id empty
      errorList.add("Empty ID in Retract Class.");
    }

    // source
    if (jsonSource == null) {
      // source not found
      errorList.add("No Source in Retract Class.");
    } else if (!jsonSource.isValid()) {
      // source invalid
      errorList.add("Invalid Source in Retract Class.");
    }

    // success
    return (errorList);
  }

  /** @return the type */
  public String getType() {
    return type;
  }

  /** @return the id */
  public String getID() {
    return id;
  }

  /** @return the source */
  public Source getSource() {
    return source;
  }
}
