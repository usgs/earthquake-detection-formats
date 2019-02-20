#ifndef DETECTION_H
#define DETECTION_H

#include <string>

#include "detection.h" // NOLINT
#include "retract.h" // NOLINT
#include "pick.h" // NOLINT
#include "correlation.h" // NOLINT
#include "stationInfo.h" // NOLINT
#include "stationInfoRequest.h" // NOLINT

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
