#include "retract.h"

// JSON Keys
#define TYPE_KEY "Type"
#define ID_KEY "ID"
#define SOURCE_KEY "Source"

namespace detectionformats
{
	retract::retract()
	{
		type = RETRACT_TYPE;
		id = "";
		source = detectionformats::source();
	}

	retract::retract(std::string newid, std::string newagencyid, std::string newauthor)
	{
		type = RETRACT_TYPE;
		id = newid;
		source = detectionformats::source(newagencyid, newauthor);
	}

	retract::retract(std::string newid, detectionformats::source newsource)
	{
		type = RETRACT_TYPE;
		id = newid;
		source = newsource;
	}

	retract::retract(rapidjson::Value &json)
	{
		// required values
		// type
		if ((json.HasMember(TYPE_KEY) == true) && (json[TYPE_KEY].IsString() == true))
			type = std::string(json[TYPE_KEY].GetString(), json[TYPE_KEY].GetStringLength());
		else
			type = "";

		// id
		if ((json.HasMember(ID_KEY) == true) && (json[ID_KEY].IsString() == true))
			id = std::string(json[ID_KEY].GetString(), json[ID_KEY].GetStringLength());
		else
			id = "";

		// source
		if ((json.HasMember(SOURCE_KEY) == true) && (json[SOURCE_KEY].IsObject() == true))
		{
			rapidjson::Value & sourcevalue = json[SOURCE_KEY];
			source = detectionformats::source(sourcevalue);
		}
		else
			source = detectionformats::source();
	}

	retract::retract(const retract & newretract)
	{
//		retract(newretract.id, newretract.source);
		type = RETRACT_TYPE;
		id = newretract.id;
		source = newretract.source;
	}

	retract::~retract()
	{
	}

	rapidjson::Value & retract::tojson(rapidjson::Value &json, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allocator)
	{
		json.SetObject();

		// required values
		// type
		rapidjson::Value typevalue;
		typevalue.SetString(rapidjson::StringRef(type.c_str()), allocator);
		json.AddMember(TYPE_KEY, typevalue, allocator);

		// id
		if (id != "")
		{
			rapidjson::Value idvalue;
			idvalue.SetString(rapidjson::StringRef(id.c_str()), allocator);
			json.AddMember(ID_KEY, idvalue, allocator);
		}

		// source
		rapidjson::Value sourcevalue(rapidjson::kObjectType);
		source.tojson(sourcevalue, allocator);
		json.AddMember(SOURCE_KEY, sourcevalue, allocator);

		return(json);
	}

	std::vector<std::string> retract::geterrors()
	{
		std::vector<std::string> errorlist;

		// check for requried keys
		// Type
		if (type != RETRACT_TYPE)
		{
			// wrong type
			errorlist.push_back("Non-retract type in retract class.");
		}
		
		// id
		if (id == "")
		{
			// empty id
			errorlist.push_back("Empty ID in retract class.");
		}
		
		// source
		if (source.isvalid() != true)
		{
			// bad source
			errorlist.push_back("Source object did not validate in retract class.");
		}

		// return the list of errors
		return (errorlist);
	}

}