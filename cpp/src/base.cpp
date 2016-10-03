#include "base.h"

namespace detectionformats
{
	detectionbase::detectionbase()
	{
		type = "";
	}

	detectionbase::detectionbase(std::string newtype)
	{
		type = newtype;
	}

	detectionbase::~detectionbase()
	{
	}

	bool detectionbase::isvalid()
	{
		std::vector<std::string> errorlist = geterrors();
		std::string errorstring = "";

		if (errorlist.size() == 0)
		{
			// no errors
			return (true);
		}
		else
		{
/*			// found at least one error, build a string
			// for the exception
			for (int i = 0; i < (int)errorlist.size(); i++)
			{
				errorstring += errorlist[i] + "; ";
			}

			throw std::invalid_argument::exception(errorstring.c_str());*/
			return (false);
		}
	}
}