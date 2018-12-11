#ifndef DETECTION_H
#define DETECTION_H

#include <hypocenter.h>
#include <detection.h>
#include <retract.h>
#include <pick.h>
#include <beam.h>
#include <correlation.h>
#include <util.h>
#include <base.h>
#include <stationInfo.h>
#include <stationInfoRequest.h>

#include <string>

namespace detectionformats {
    /**
     * \brief detectionformats function to validate a provided
     * json formatted string
     */
    bool ValidateJSON(const std::string & jsonstring);

     /**
     * \brief detectionformats function to print out validation errors from a 
     * provided json formatted string
     */
    std::string ValidateJSONErrors(const std::string & jsonstring);
}  // namespace detectionformats
#endif  // DETECTION_H
