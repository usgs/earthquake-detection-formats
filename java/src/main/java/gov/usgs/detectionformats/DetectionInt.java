package gov.usgs.detectionformats;

import java.util.ArrayList;
import org.json.simple.JSONObject;

public interface DetectionInt {
  public JSONObject toJSON();

  public boolean isValid();

  public ArrayList<String> getErrors();
}
