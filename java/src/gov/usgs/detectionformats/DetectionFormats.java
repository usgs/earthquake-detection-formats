package gov.usgs.detectionformats;

import java.util.ArrayList;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

/**
 * a general class containing functions global to detectionformats.
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class DetectionFormats {

    /**
	 * Checks to see if the provided json string is valid
	 * 
	 * @param jsonString
	 *            the json formatted string to check.
	 * @return Returns a true if valid, false otherwise
	 */
    public static boolean validateJSON(String jsonString) {
        String errorString = validateJSONErrors(jsonString);
    
        // it's valid if there are no errors
        if (errorString.length() == 0) {
            return(true);
        } else {
            return(false);
        }
    }

    /**
	 * Gets any validation errors in the provided json string.
	 * @param jsonString
	 *            the json object to check.
	 * @return Returns a String containing all errors found
	 */
    public static String validateJSONErrors(String jsonString) {
        // use a parser to convert to a string
		JSONParser parser = new JSONParser();

		// parse it
		JSONObject newJSONObject;
		try {
			newJSONObject = (JSONObject) parser.parse(jsonString);
		} catch (ParseException e) { 
			return("Bad Format");
		}

        // check type
        FormatTypes type = Utility.getDetectionType(newJSONObject);
        if (type == FormatTypes.Unknown) {
            return("Unknown Format");
        }

        // get errors based on type
        ArrayList<String> errorList = new ArrayList<String>();
        String errorString = new String();
        if (type == FormatTypes.Pick) {
            Pick testPick = new Pick(newJSONObject);
            errorList = testPick.getErrors();
        } else if (type == FormatTypes.Correlation) {
            Correlation testCorrelation = new Correlation(newJSONObject);
            errorList = testCorrelation.getErrors();
        } else if (type == FormatTypes.Detection) {
            Detection testDetection = new Detection(newJSONObject);
            errorList = testDetection.getErrors();
        } else if (type == FormatTypes.Retract) {
            Retract testRetract = new Retract(newJSONObject);
            errorList = testRetract.getErrors();
        } else if (type == FormatTypes.StationInfo) {
            StationInfo testStationInfo = new StationInfo(newJSONObject);
            errorList = testStationInfo.getErrors();
        } else if (type == FormatTypes.StationInfoRequest) {
            StationInfoRequest testRequest = new StationInfoRequest(newJSONObject);
            errorList = testRequest.getErrors();
        }

        // no errors
        if (errorList.size() == 0) {
            return ("");
        }

        // combine the errors into a single string
        for (int i = 0; i < errorList.size(); i++) {
            errorString += " " + errorList.get(i);
        }

        return(errorString);
    }
}
