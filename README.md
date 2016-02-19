# Travel-Paths
Uses graphs and Djikstra's algorithm to find shortest paths 

Just found out that this DOES NOT WORK ON UNIX OPERATING SYSTEMS (I work through a server on Windows with no access to UNIX)

Code for Breadth first search is in Graph.cpp

Main function accepts a filename as argv[1]

The format of the file is as follows:

The number of cities followed by each city (one word) then the number of flights followed by where the flights leave from to where they go

[Number of cities]
City 1
City 2
City 3
...
...
City N

[Number of flights]
CityA CityB
CityC CityD
...
CityY CityZ

Heres an example:

5
New_York
Boston
San_Fransisco
Chicago
Dallas

5
New_York Dallas
New_York Chicago
Boston San_Fransisco
Chicago Boston
Boston New_York

The program prompts for a command. Commands are as follows

HOME [HomeCity]
TRAVEL [City1][City2]

HOME returns a loop path back to HomeCity
TRAVEL returns a the shortest path from City1 to City2
If no such path exists for either command, the program returns 'no'

Examples using the file above:

HOME Chicago --> Chicago Boston New_York Chicago
TRAVEL New_York San_Fransisco --> New_York Chicago Boston San_Fransisco
HOME Dallas --> no
