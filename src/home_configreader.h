#ifndef __HOME_CONFIGREADER_H__
#define __HOME_CONFIGREADER_H__

#include <string>
#include <map>

namespace Home
{
	class ConfigReader
	{
	public:
		ConfigReader(const char* filename);

		const std::string& get(const std::string& key) const;
		int geti(const std::string& key) const;
		float getf(const std::string& key) const;
		bool getb(const std::string& key) const;

	private:
		void parse(const char* filename);

		std::map<std::string, std::string> mValues;
	};
}

#endif
