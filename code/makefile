all: hps

hps: main.o server.o connection.o reply.o request_handler.o request_parser.o mime_types.o log.o memcache.o
	g++ -o hps -L/usr/local/lib main.o server.o connection.o reply.o request_handler.o request_parser.o mime_types.o -lboost_thread -lboost_system log.o memcache.o

main.o: main.cpp server.hpp
	g++ -o main.o -c -g main.cpp

server.o: server.cpp server.hpp connection.hpp request_handler.hpp log.hpp
	g++ -o server.o -c -g server.cpp

connection.o: connection.cpp connection.hpp reply.hpp request.hpp request_handler.hpp request_parser.hpp log.hpp
	g++ -o connection.o -c -g connection.cpp

reply.o: reply.cpp reply.hpp header.hpp
	g++ -o reply.o -c -g reply.cpp

request_handler.o: request_handler.cpp request_handler.hpp mime_types.hpp reply.hpp request.hpp memcache.hpp
	g++ -o request_handler.o -c -g request_handler.cpp

request_parser.o: request_parser.cpp request_parser.hpp request.hpp
	g++ -o request_parser.o -c -g request_parser.cpp

mime_types.o: mime_types.cpp mime_types.hpp
	g++ -o mime_types.o -c -g mime_types.cpp

clear:
	rm *.o hps
