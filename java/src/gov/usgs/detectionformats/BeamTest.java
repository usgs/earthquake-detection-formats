package gov.usgs.detectionformats;

import static org.junit.Assert.*;
import java.util.Date;
import org.json.simple.parser.ParseException;
import org.junit.Test;

public class BeamTest {

	public static String BEAM_STRING = "{\"Source\":{\"Author\":\"TestAuthor\","
			+ "\"AgencyID\":\"US\"},\"StartTime\":\"2015-12-28T21:32:24.017Z\","
			+ "\"EndTime\":\"2015-12-28T21:32:30.017Z\","
			+ "\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":"
			+ "\"LB\",\"Location\":\"01\",\"SiteID\":\"BMN.HHZ.LB.01\"},"
			+ "\"Type\":\"Beam\",\"BackAzimuth\":2.65,\"ID\":\"12GFH48776857\","
			+ "\"BackAzimuthError\":3.8,\"Slowness\":1.44,\"AssociationInfo\":"
			+ "{\"Distance\":0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\","
			+ "\"Sigma\":0.086333,\"Residual\":-0.025393},\"SlownessError\":0.4"
			+ "\"PowerRatio\":12.18,\"PowerRatioError\":0.557}";

	public static double BACKAZIMUTH = 2.65;
	public static double BACKAZIMUTHERROR = 3.8;
	public static double SLOWNESS = 1.44;
	public static double SLOWNESSERROR = 0.4;
	public static double POWERRATIO = 12.18;
	public static double POWERRATIOERROR = 0.557;

	/**
	 * Able to write a JSON string
	 */
	@Test
	public void writesJSON() {

		Beam beamObject = new Beam(BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS,
				SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

		// write out to a string
		String jsonString = Utility.toJSONString(beamObject.toJSON());

		// check the data
		try {
			checkData(new Beam(Utility.fromJSONString(jsonString)),
					"WritesJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Able to read a JSON string
	 */
	@Test
	public void readsJSON() {

		// build Beam object
		try {

			checkData(new Beam(Utility.fromJSONString(BEAM_STRING)),
					"ReadsJSON");
		} catch (ParseException e) {
			e.printStackTrace();
		}

	}

	/**
	 * Able to run validation function
	 */
	@Test
	public void validate() {

		Beam beamObject = new Beam(BACKAZIMUTH, BACKAZIMUTHERROR, SLOWNESS,
				SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

		// Successful validation
		boolean rc = beamObject.isValid();

		// check return code
		assertEquals("Successful Validation", true, rc);

		// build bad Beam object
		Beam badBeamObject = new Beam(null, BACKAZIMUTHERROR, null,
				SLOWNESSERROR, POWERRATIO, POWERRATIOERROR);

		rc = badBeamObject.isValid();

		// check return code
		assertEquals("Unsuccessful Validation", false, rc);
	}

	public void checkData(Beam beamObject, String TestName) {

		// check beamObject.BackAzimuth
		assertEquals(TestName + " BackAzimuth Equals", BACKAZIMUTH,
				beamObject.getBackAzimuth(), 0);

		// check beamObject.BackAzimuthError
		if (beamObject.getBackAzimuthError() != null) {
			assertEquals(TestName + " BackAzimuthError Equals",
					BACKAZIMUTHERROR, beamObject.getBackAzimuthError(), 0);
		}

		// check beamObject.Slowness
		assertEquals(TestName + " Slowness Equals", SLOWNESS,
				beamObject.getSlowness(), 0);

		// check beamObject.SlownessError
		if (beamObject.getSlownessError() != null) {
			assertEquals(TestName + " SlownessError Equals", SLOWNESSERROR,
					beamObject.getSlownessError(), 0);
		}

		// check beamObject.PowerRatio
		if (beamObject.getPowerRatio() != null) {
			assertEquals(TestName + " PowerRatio Equals", POWERRATIO,
					beamObject.getPowerRatio(), 0);
		}

		// check beamObject.PowerRatioError
		if (beamObject.getPowerRatioError() != null) {
			assertEquals(TestName + " PowerRatioError Equals", POWERRATIOERROR,
					beamObject.getPowerRatioError(), 0);
		}
	}
}
