package gov.usgs.detectionformats;

import java.util.ArrayList;
import org.json.simple.JSONObject;

/**
 * a conversion class used to create, parse, and validate source data as part of detection data.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Source implements DetectionInt {

  /** JSON Keys */
  public static final String AGENCYID_KEY = "AgencyID";

  public static final String AUTHOR_KEY = "Author";

  /** Required Agency identifier */
  private final String agencyID;

  /** Required Author identifier */
  private final String author;

  /** The constructor for the Source class. Initializes members to null values. */
  public Source() {
    agencyID = null;
    author = null;
  }

  /**
   * The advanced constructor for the Source class. Initializes members to provided values.
   *
   * @param newAgencyID - A String containing the agencyID to use
   * @param newAuthor - A String containing the author to use
   */
  public Source(String newAgencyID, String newAuthor) {
    agencyID = newAgencyID;
    author = newAuthor;
  }

  /**
   * Constructs the class from a JSONObject, populating members
   *
   * @param newJSONObject - A JSONObject.
   */
  public Source(JSONObject newJSONObject) {
    // required values
    // agencyID
    if (newJSONObject.containsKey(AGENCYID_KEY)) {
      agencyID = newJSONObject.get(AGENCYID_KEY).toString();
    } else {
      agencyID = null;
    }

    // author
    if (newJSONObject.containsKey(AUTHOR_KEY)) {
      author = newJSONObject.get(AUTHOR_KEY).toString();
    } else {
      author = null;
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

    String jsonAgencyID = getAgencyID();
    String jsonAuthor = getAuthor();

    // required values
    // agencyID
    if ((jsonAgencyID != null) && (!jsonAgencyID.isEmpty())) {
      newJSONObject.put(AGENCYID_KEY, jsonAgencyID);
    }

    // author
    if ((jsonAuthor != null) && (!jsonAuthor.isEmpty())) {
      newJSONObject.put(AUTHOR_KEY, jsonAuthor);
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
    String jsonAgencyID = getAgencyID();
    String jsonAuthor = getAuthor();

    ArrayList<String> errorList = new ArrayList<String>();

    // check for required keys
    // agencyID
    if (jsonAgencyID == null) {
      // agencyID not found
      errorList.add("No AgencyID in Source Class.");
    } else if (jsonAgencyID.isEmpty()) {
      // agencyID empty
      errorList.add("Empty AgencyID in Source Class.");
    }

    // author
    if (jsonAuthor == null) {
      // author not found
      errorList.add("No Author in Source Class.");
    } else if (jsonAuthor.isEmpty()) {
      // author empty
      errorList.add("Empty Author in Source Class.");
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
    if (getAgencyID() != null) {
      return (false);
    }
    if (getAuthor() != null) {
      return (false);
    }
    return (true);
  }

  /** @return the agencyID */
  public String getAgencyID() {
    return agencyID;
  }

  /** @return the author */
  public String getAuthor() {
    return author;
  }
}
