#include "home_configreader.h"
#include "home_util.h"
#include <fstream>

namespace Home
{
	// -------------------------------------------------------------------------
	ConfigReader::ConfigReader(const char* filename)
	{
		parse(filename);
	}

	// -------------------------------------------------------------------------
	const std::string& ConfigReader::get(const std::string& key) const
	{
		std::map<std::string, std::string>::const_iterator itr = mValues.find(key);
		if(itr != mValues.end())
			return itr->second;

		return "";
	}

	// -------------------------------------------------------------------------
	int ConfigReader::geti(const std::string& key) const
	{
		std::string value = get(key);
		if(value.empty())
			return 0;

		return Util::s2i(value);
	}

	// -------------------------------------------------------------------------
	float ConfigReader::getf(const std::string& key) const
	{
		std::string value = get(key);
		if(value.empty())
			return 0;

		return Util::s2f(value);
	}

	// -------------------------------------------------------------------------
	bool ConfigReader::getb(const std::string& key) const
	{
		std::string value = get(key);

		return value == "1" || value == "true";
	}

	// -------------------------------------------------------------------------
	void ConfigReader::parse(const char* filename)
	{
		std::ifstream file(filename);

		if(file.is_open())
		{
			while(!file.eof())
			{
				char buffer[1024];
				file.getline(buffer, sizeof(buffer));
				std::string line = buffer;
				if(line.empty() || line[0] == '#')
					continue;

				size_t p = line.find_first_of("\t ");
				if(p != std::string::npos)
				{
					std::string value = line.substr(p);
					Util::trim(value);
					mValues.insert(std::make_pair(line.substr(0, p), value));
				}
			}

			file.close();
		}
	}
}
