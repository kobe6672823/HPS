#include "log.hpp"

Log::Log(string file_name = "")
{
	ofile.open(file_name.c_str(), ofstream::app);
}

void Log::log_for_request(string ip, int port, string file_name)
{
	output_current_time();
	ofile << "Client [" << ip << " : " << port << "] request file: " << file_name << endl;  
}

void Log::log_for_send(string ip, int port, string file_name, size_t file_size, int delay)
{
	output_current_time();
	ofile << "Successful send file " << file_name << " with " << file_size << "bytes to client [" << ip << " : " << port << "] after " << delay << "ms from receiving its request." << endl;
}

void Log::log_for_error(string ip, int port, string file_name, string err)
{
	output_current_time();
	ofile << "Fail to send file " << file_name << " to client [" << ip << " : " << port << "] due to error: " << err << "." << endl;
}


