// unit test data

// generic
#define PHASE "P"
#define SNR 3.8
#define ID "12GFH48776857"

// amplitude
#define AMPLITUDESTRING "{\"Amplitude\":1.05,\"Period\":2.65,\"SNR\":3.8}"
#define AMPLITUDEVALUE 1.05
#define PERIOD 2.65

// associated
#define ASSOCIATEDSTRING "{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}" // NOLINT
#define DISTANCE 0.442559
#define AZIMUTH 0.418479
#define RESIDUAL -0.025393
#define SIGMA 0.086333

// beam
#define BEAMSTRING "{\"BackAzimuth\":2.65,\"Slowness\":1.44,\"PowerRatio\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerRatioError\":0.557}" // NOLINT
#define BACKAZIMUTH 2.65
#define BACKAZIMUTHERROR 3.8
#define SLOWNESS 1.44
#define SLOWNESSERROR 0.4
#define POWERRATIO 12.18
#define POWERRATIOERROR 0.557

// correlation
#define CORRELATIONSTRING "{\"ZScore\":33.67,\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\",\"Location\":\"01\"},\"Magnitude\":2.14,\"Type\":\"Correlation\",\"Correlation\":2.65,\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},\"AssociationInfo\":{\"Distance\":0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":-0.025393},\"DetectionThreshold\":1.5,\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Hypocenter\":{\"TimeError\":1.984,\"Time\":\"2015-12-28T21:32:24.017Z\",\"LongitudeError\":22.64,\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44},\"SNR\":3.8,\"ID\":\"12GFH48776857\",\"ThresholdType\":\"minimum\",\"Phase\":\"P\"}" // NOLINT
#define CORRELATION 2.65
#define MAGNITUDE 2.14
#define ZSCORE 33.67
#define DETECTIONTHRESHOLD 1.5
#define THRESHOLDTYPE "minimum"

// detection
#define DETECTIONSTRING "{\"Type\":\"Detection\",\"ID\":\"12GFH48776857\",\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Hypocenter\":{\"TimeError\":1.984,\"Time\":\"2015-12-28T21:32:24.017Z\",\"LongitudeError\":22.64,\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44},\"DetectionType\":\"New\",\"DetectionTime\":\"2015-12-28T21:32:28.017Z\",\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},\"Bayes\":2.65,\"MinimumDistance\":2.14,\"RMS\":3.8,\"Gap\":33.67,\"Data\":[{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65}],\"Amplitude\":{\"Amplitude\":21.5,\"Period\":2.65,\"SNR\":3.8},\"Beam\":{\"BackAzimuth\":2.65,\"Slowness\":1.44,\"PowerRatio\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerRatioError\":0.557},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}},{\"ZScore\":33.67,\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\",\"Location\":\"01\"},\"Magnitude\":2.14,\"Type\":\"Correlation\",\"Correlation\":2.65,\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},\"AssociationInfo\":{\"Distance\":0.442559,\"Azimuth\":0.418479,\"Phase\":\"P\",\"Sigma\":0.086333,\"Residual\":-0.025393},\"DetectionThreshold\":1.5,\"Source\":{\"Author\":\"TestAuthor\",\"AgencyID\":\"US\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Hypocenter\":{\"TimeError\":1.984,\"Time\":\"2015-12-28T21:32:24.017Z\",\"LongitudeError\":22.64,\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44},\"SNR\":3.8,\"ID\":\"12GFH48776857\",\"ThresholdType\":\"minimum\",\"Phase\":\"P\"}]}" // NOLINT
#define DETECTIONTYPE "New"
#define DETECTIONTIME "2015-12-28T21:32:28.017Z"
#define BAYES 2.65
#define MINIMUMDISTANCE 2.14
#define RMS 3.8
#define GAP 33.67

// detection-formats
#define BADMESSAGE "non-json formatted string"
#define BADMESSAGE2 "{\"Type\":\"MadeUp\",\"Key\":\"Value\"}"

// eventtype
#define EVENTTYPESTRING "{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"}"
#define EVENTTYPE "Earthquake"
#define BADEVENTTYPE "chair"
#define CERTAINTY "Suspected"

// filter
#define FILTERSTRING "{\"Type\":\"BandPass\",\"HighPass\":1.05,\"LowPass\":2.65, \"Units\":\"Hertz\"}" // NOLINT
#define HIGHPASS 1.05
#define LOWPASS 2.65
#define FILTERTYPE "BandPass"
#define FILTERUNITS "Hertz"

// hypocenter
#define HYPOSTRING "{\"TimeError\":1.984,\"Time\":\"2015-12-28T21:32:24.017Z\",\"LongitudeError\":22.64,\"LatitudeError\":12.5,\"DepthError\":2.44,\"Latitude\":40.3344,\"Longitude\":-121.44,\"Depth\":32.44}" // NOLINT
#define LATITUDE 40.3344
#define LONGITUDE -121.44
#define TIME "2015-12-28T21:32:24.017Z"
#define DEPTH 32.44
#define LATITUDEERROR 12.5
#define LONGITUDEERROR 22.64
#define DEPTHERROR 2.44
#define TIMEERROR 1.984

// pick
#define PICKSTRING "{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[{\"HighPass\":1.05,\"LowPass\":2.65},{\"HighPass\":2.10,\"LowPass\":3.58}],\"Amplitude\":{\"Amplitude\":1.05,\"Period\":2.65,\"SNR\":3.8},\"Beam\":{\"BackAzimuth\":2.65,\"Slowness\":1.44,\"PowerRatio\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerRatioError\":0.557},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}" // NOLINT
#define PICKSTRINGNOFILTER "{\"Type\":\"Pick\",\"ID\":\"12GFH48776857\",\"Site\":{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"},\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"},\"Time\":\"2015-12-28T21:32:24.017Z\",\"Phase\":\"P\",\"Polarity\":\"up\",\"Onset\":\"questionable\",\"Picker\":\"manual\",\"Filter\":[],\"Amplitude\":{\"Amplitude\":1.05,\"Period\":2.65,\"SNR\":3.8},\"Beam\":{\"BackAzimuth\":2.65,\"Slowness\":1.44,\"PowerRatio\":12.18,\"BackAzimuthError\":3.8,\"SlownessError\":0.4,\"PowerRatioError\":0.557},\"AssociationInfo\":{\"Phase\":\"P\",\"Distance\":0.442559,\"Azimuth\":0.418479,\"Residual\":-0.025393,\"Sigma\":0.086333}}" // NOLINT
#define POLARITY "up"
#define ONSET "questionable"
#define PICKER "manual"
#define HIGHPASS2 2.10
#define LOWPASS2 3.58

// retract
#define RETRACTSTRING "{\"Type\":\"Retract\",\"ID\":\"12GFH48776857\",\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}}" // NOLINT

// site
#define SITESTRING "{\"Station\":\"BMN\",\"Network\":\"LB\",\"Channel\":\"HHZ\",\"Location\":\"01\"}" // NOLINT
#define STATION "BMN"
#define CHANNEL "HHZ"
#define NETWORK "LB"
#define LOCATION "01"

// source
#define SOURCESTRING "{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}"
#define AGENCYID "US"
#define AUTHOR "TestAuthor"

// stationinfo
#define STATIONSTRING "{\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\",\"Location\":\"01\"},\"Enable\":true,\"Use\":true,\"Quality\":1.0,\"Type\":\"StationInfo\",\"Elevation\":1589.0,\"UseForTeleseismic\":false,\"Latitude\":40.3344,\"Longitude\":-121.44,\"InformationRequestor\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}}" // NOLINT
#define ELEVATION 1589.000000
#define QUALITY 1.0
#define ENABLE true
#define USE true
#define USEFORTELESEISM false

// stationinforequest
#define REQUESTSTRING "{\"Site\":{\"Station\":\"BMN\",\"Channel\":\"HHZ\",\"Network\":\"LB\",\"Location\":\"01\"},\"Type\":\"StationInfoRequest\",\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}}" // NOLINT

// classification
#define CLASSIFICATIONSTRING "{\"Phase\":\"P\",\"PhaseProbability\":0.22,\"Distance\":0.442559,\"DistanceProbability\":22.5,\"Azimuth\":0.418479,\"AzimuthProbability\":0.16,\"Magnitude\":2.14,\"MagnitudeType\":\"Mb\",\"MagnitudeProbability\":0.55,\"Depth\":32.44,\"DepthProbability\":11.2,\"EventType\":{\"Type\":\"Earthquake\",\"Certainty\":\"Suspected\"},\"EventTypeProbability\":1.1,\"Source\":{\"AgencyID\":\"US\",\"Author\":\"TestAuthor\"}}" // NOLINT
#define PHASEPROBABILITY 0.22
#define DISTANCEPROBABILITY 22.5
#define AZIMUTHPROBABILITY 0.16
#define MAGNITUDETYPE "Mb"
#define MAGNITUDEPROBABILITY 0.55
#define DEPTHPROBABILITY 11.2
#define EVENTTYPEPROBABILITY 1.1

// util
#define ISO8601TIME "2015-12-28T21:32:24.017Z"
#define EPOCHTIME 1451338344.017

#define ISO8601TIME2 "2015-12-28T21:32:24.500Z"
#define EPOCHTIME2 1451338344.50

#define ISO8601TIME3 "2015-12-28T21:32:25.000Z"
#define EPOCHTIME3 1451338344.9999997

#define ISO8601TIME4 "2015-12-28T21:32:24.000Z"
#define EPOCHTIME4 1451338344.00000000001

#define EMPTYTIME ""
#define BADYEARISO8601TIME "-215-13-28T21:32:24.000Z"
#define BADMONTHISO8601TIME "2015-13-28T21:32:24.000Z"
#define BADDAYISO8601TIME "2015-12-48T21:32:24.000Z"
#define BADHOURISO8601TIME "2015-12-28T31:32:24.000Z"
#define BADMINUTEISO8601TIME "2015-12-28T21:72:24.000Z"
#define BADSECONDISO8601TIME "2015-12-28T21:32:94.000Z"
#define BADZISO8601TIME "2015-12-28T21:32:24.000B"

#define BADISO8601TIME1 "2015-12-28T21:32:24Z"
#define BADISO8601TIME2 "2015-12-28T21:32:244.000Z"


