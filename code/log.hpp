#ifndef HTTP_SERVER3_LOG_HPP
#define HTTP_SERVER3_LOG_HPP

#include <fstream>
#include <string>
#include <time.h>
#include <sys/timeb.h>
using namespace std;

class log
{
public :
	log(string file_name);
	void log_for_request(string ip, int port, string file_name);
	void log_for_send(string ip, int port, string file_name, size_t file_size, int delay);
	void log_for_error(string ip, int port, string file_name, string err);
	~log() { ofile.close(); }

private :
	ofstream ofile;
	void output_current_time()
	{
		struct timeb tp;
		struct tm *tm;

		ftime ( &tp );
		tm = localtime(&(tp.time));
		ofile << tm->tm_year + 1900 << "-" << tm->tm_mon + 1 << "-" << tm->tm_mday << " " << tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << "." << tp.millitm << " "; 
	}
};
#endif
