#ifndef __HOME_UTIL_H__
#define __HOME_UTIL_H__

#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <md5.h>

namespace Home
{
	class Util
	{
	public:
		static inline int s2i(const std::string& str);
		static inline float s2f(const std::string& str);
		static inline bool s2b(const std::string& str);
		static inline int split(const std::string& str, char delim
				, std::vector<std::string>& elements);
		static inline void trim(std::string& str);

		template<typename T>
		static inline std::string toString(const T& t);

		static inline std::string encodeMd5(const std::string& str, const std::string& salt);
	};

	// -------------------------------------------------------------------------
	inline int Util::s2i(const std::string& str)
	{
		return ::atoi(str.c_str());
	}

	// -------------------------------------------------------------------------
	inline bool Util::s2b(const std::string& str)
	{
		return ::atoi(str.c_str()) != 0;
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
	inline std::string Util::toString(const T& t)
	{
		std::stringstream str;

		str << t;

		return str.str();
	}

	// -------------------------------------------------------------------------
	inline std::string Util::encodeMd5(const std::string& str, const std::string& salt)
	{
		MD5 md5 = MD5(str + salt);

		return md5.finalize().hexdigest();
	}

}

#endif
