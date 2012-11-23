#include "memcache.hpp"
#include <time.h>
#include <sys/timeb.h>
#include <iostream>

void memcache::update_cache(const std::string& full_path, const std::string content)
{
	if (file_cache.size() == memcache_size)
	{
		std::map<std::string, long>::iterator tag_iter;
		std::string old_path;//the path needed to be replace: because it has the least time_tag
		long least_tag = 1000000000;
		for (tag_iter = time_tag.begin(); tag_iter != time_tag.end(); tag_iter++)
		{
			if (tag_iter->second < least_tag)
			{
				least_tag = tag_iter->second;
				old_path = tag_iter->first;
			}
		}
		time_tag.erase(old_path);
		file_cache.erase(old_path);
	}
	file_cache[full_path] = content;
	time_tag[full_path] = current_time_tag();
}

long memcache::current_time_tag()
{
	struct timeb tp;
	long ttag;
 
	ftime(&tp);
	ttag = (tp.time) * 1000 + tp.millitm;//1354287198 is the seconds from 1970-1-1 0:0:0 to 2012-11-23 14:31:0
	return ttag;
}

void memcache::print_cache()
{
	std::map<std::string, long>::iterator tag_iter;
	for (tag_iter = time_tag.begin(); tag_iter != time_tag.end(); tag_iter++)
	{
		std::cout << tag_iter->first << "\t" << file_cache[tag_iter->first] << "\t" << tag_iter->second << std::endl;
	}
}
