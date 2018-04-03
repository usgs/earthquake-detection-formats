#include <site.h>

#include <string>
#include <limits>
#include <vector>

// JSON Keys
#define STATION_KEY "Station"
#define CHANNEL_KEY "Channel"
#define NETWORK_KEY "Network"
#define LOCATION_KEY "Location"

namespace detectionformats {
site::site() {
	station = "";
	channel = "";
	network = "";
	location = "";
}

site::site(std::string newstation, std::string newchannel,
			std::string newnetwork, std::string newlocation) {
	station = newstation;
	channel = newchannel;
	network = newnetwork;
	location = newlocation;
}

site::site(rapidjson::Value &json) {
	// required values
	// station
	if ((json.HasMember(STATION_KEY) == true)
			&& (json[STATION_KEY].IsString() == true)) {
		station = std::string(json[STATION_KEY].GetString(),
								json[STATION_KEY].GetStringLength());
	} else {
		station = "";
	}

	// network
	if ((json.HasMember(NETWORK_KEY) == true)
			&& (json[NETWORK_KEY].IsString() == true)) {
		network = std::string(json[NETWORK_KEY].GetString(),
								json[NETWORK_KEY].GetStringLength());
	} else {
		network = "";
	}

	// optional values
	// channel
	if ((json.HasMember(CHANNEL_KEY) == true)
			&& (json[CHANNEL_KEY].IsString() == true)) {
		channel = std::string(json[CHANNEL_KEY].GetString(),
								json[CHANNEL_KEY].GetStringLength());
	} else {
		channel = "";
	}

	// location
	if ((json.HasMember(LOCATION_KEY) == true)
			&& (json[LOCATION_KEY].IsString() == true)) {
		location = std::string(json[LOCATION_KEY].GetString(),
								json[LOCATION_KEY].GetStringLength());
	} else {
		location = "";
	}
}

site::site(const site & newsite) {
	station = newsite.station;
	channel = newsite.channel;
	network = newsite.network;
	location = newsite.location;
}

site::~site() {
}

rapidjson::Value & site::tojson(
		rapidjson::Value &json,
		rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator) {
	json.SetObject();

	// required values
	// station
	if (station != "") {
		rapidjson::Value stationvalue;
		stationvalue.SetString(rapidjson::StringRef(station.c_str()),
								allocator);
		json.AddMember(STATION_KEY, stationvalue, allocator);
	}
	// network
	if (network != "") {
		rapidjson::Value networkvalue;
		networkvalue.SetString(rapidjson::StringRef(network.c_str()),
								allocator);
		json.AddMember(NETWORK_KEY, networkvalue, allocator);
	}

	// optional values
	// channel
	if (channel != "") {
		rapidjson::Value channelvalue;
		channelvalue.SetString(rapidjson::StringRef(channel.c_str()),
								allocator);
		json.AddMember(CHANNEL_KEY, channelvalue, allocator);
	}

	// location
	if (location != "") {
		rapidjson::Value locationvalue;
		locationvalue.SetString(rapidjson::StringRef(location.c_str()),
								allocator);
		json.AddMember(LOCATION_KEY, locationvalue, allocator);
	}

	return (json);
}

std::vector<std::string> site::geterrors() {
	std::vector<std::string> errorlist;

	// check for required keys
	// Station
	if (station == "") {
		// empty Station
		errorlist.push_back("Empty Station in site class.");
	}

	// Network
	if (network == "") {
		// empty network
		errorlist.push_back("Empty Network in site class.");
	}

	// since station, channel, network, and location are free text strings, no
	// further  validation is required.  channel and location are also optional
	// NOTE: Further validation COULD be done to confirm that values matched
	// seed standards.

	// return the list of errors
	return (errorlist);
}
}  // namespace detectionformats
