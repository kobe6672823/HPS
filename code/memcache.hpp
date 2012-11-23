#ifndef HTTP_SERVER3_MEMCACHE_HPP
#define HTTP_SERVER3_MEMCACHE_HPP

#include <map>
#include <string>

class memcache
{
public:
	bool in_cache(const std::string& full_path)
	{
		return file_cache.count(full_path);
	}
	std::string content_in_cache(const std::string& full_path)
	{
		//update time_tag then return the content
		time_tag[full_path] = current_time_tag();
		return file_cache[full_path];
	}
	void update_cache(const std::string& full_path, const std::string content);
	long current_time_tag();
	void print_cache();
private:
	std::map<std::string, std::string> file_cache;
	std::map<std::string, long> time_tag;//tag design needs to be changed
	const static int memcache_size = 10;
};
#endif
