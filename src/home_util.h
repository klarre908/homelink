#ifndef __HOME_UTIL_H__
#define __HOME_UTIL_H__

#include <string>
#include <sstream>
#include <vector>

namespace Home
{
	class Util
	{
	public:
		static inline int s2i(const std::string& str);
		static inline float s2f(const std::string& str);
		static inline int Util::split(const std::string& str, char delim
				, std::vector<std::string>& elements);
		static inline void trim(std::string& str);

		template<typename T>
		static std::string toString(const T& t);
	};

	// -------------------------------------------------------------------------
	inline int Util::s2i(const std::string& str)
	{
		return ::atoi(str.c_str());
	}

	// -------------------------------------------------------------------------
	inline float Util::s2f(const std::string& str)
	{
		return (float)::atof(str.c_str());
	}

	// -------------------------------------------------------------------------
	inline int Util::split(const std::string& str, char delim
			, std::vector<std::string>& elements)
	{
		std::stringstream ss(str);
		std::string item;
		int numElements = 0;
		while(std::getline(ss, item, delim))
		{
			elements.push_back(item);
			++numElements;
		}

		return numElements;
	}

	// -------------------------------------------------------------------------
	inline void Util::trim(std::string& str)
	{
		for(std::string::iterator i = str.begin(); i != str.end(); )
		{
			if(*i == '\t' || *i == ' ')
				i = str.erase(i);
			else
				break;
		}
	}

	// -------------------------------------------------------------------------
	template<typename T>
	std::string Util::toString(const T& t)
	{
		std::stringstream str;

		str << t;

		return str.str();
	}
}

#endif
