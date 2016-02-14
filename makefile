all:	driver

driver:	City.o Graph.o driver.o
	g++ City.o Graph.o driver.o -o driver.exe

City.o Graph.o driver.o:	City.cpp Graph.cpp driver.cpp
	g++ -c City.cpp Graph.cpp driver.cpp

clean:	
	rm -f *.o City.o Graph.o driver.o driver.exe
