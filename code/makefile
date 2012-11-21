all : hps

hps : connection.o main.o mime_types.o reply.o request_handler.o request_parser.o server.o
	g++ connection.o main.o mime_types.o reply.o request_handler.o request_parser.o server.o -I/usr/include/boost -L/usr/local/lib -lboost_thread -lboost_system -o hps 
	
connection.o : connection.cpp connection.hpp reply.hpp request.hpp request_handler.hpp request_parser.hpp
	g++ connection.cpp -I/usr/include/boost -L/usr/local/lib  -lboost_thread -lboost_system -o connection.o 

main.o : main.cpp server.hpp
	g++ main.cpp -L/usr/local/lib  -lboost_thread -lboost_system -o main.o

mime_types.o : mime_types.cpp mime_types.hpp
	g++ mime_types.cpp -L/usr/local/lib  -lboost_thread -lboost_system -o mime_types.o

reply.o : reply.cpp reply.hpp header.hpp
	g++ reply.cpp -L/usr/local/lib  -lboost_thread -lboost_system -o reply.o

request_handler.o : request_handler.cpp request_handler.hpp mime_types.hpp reply.hpp request.hpp
	g++ request_handler.cpp -L/usr/local/lib  -lboost_thread -lboost_system -o request_handler.o

request_parser.o : request_parser.cpp request_parser.hpp request.hpp
	g++ request_parser.cpp -L/usr/local/lib  -lboost_thread -lboost_system -o request_parser.o

server.o : server.cpp server.hpp connection.hpp request_handler.hpp
	g++ server.cpp -lboost_thread -L/usr/local/lib  -lboost_thread -lboost_system -o server.o

.PHONY :clean

clean:
	rm *.o hps
