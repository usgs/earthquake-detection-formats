package gov.usgs.detectionformats;

/**
 * a launcher class used to print out the library version via the 
 * detection-formats jar JAR
 *
 * @author U.S. Geological Survey &lt;jpatton at usgs.gov&gt;
 */
public class Version {
        /** 
         * Version
         * NOTE: Make sure to also update the c++ version in version.cmake when 
         * updating this file
         */
        public static final Integer VERSION_MAJOR = 0;
        public static final Integer VERSION_MINOR = 9;
        public static final Integer VERSION_PATCH = 10; 

        /**
         * main function for launcher
         * 
         * @param args
         *            - A String[] containing the command line arguments.
         */
        public static void main(String[] args) {
                // print out the version
                System.out.println("Version: gov.usgs.detectionformats: v" + 
                                VERSION_MAJOR + "." + 
                                VERSION_MINOR + "." + 
                                VERSION_PATCH);
                System.exit(1);
        }
}
