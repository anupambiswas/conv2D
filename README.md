This project is based on dividing any singly connected 2D domain into internal polygonal domains all of which have their internal angles less than 180 degrees. Currently it has two projects included. This code may be used for generating points either inside or outside a complex two dimensional domain, which again has applications in mesh generation techniques.

The first project 'proj_0' is for region made up of 25 boundary line segments. The point data is read from a file named 'ds'. It makes 12 internal polygonal zones. Point data of each individual zone is given in files having filenames 'zoneNUM' (like zone8, zone11).

Instruction to build and run the code:

$ make
$ ./run

If you have gnuplot, you can run the following to visialize the zones.

$ gnuplot
> p 'ds' w l
# This will show the outline of the actual 2D domain

> p 'zones' w l,'cent'
# This will show the different zones and their respective centroids

> load 'vid'
# This will show a simple animation of the different zones as they were created during the run. If you do not want the legend to show up, modify the 'vid' file at the top by adding the line 'unset key'

For proj_1, you can generate different regions. On different runs of the code, it will create different 2D domains.

Instructions to build and run the code:

$ make
$ ./run
# This will create a region with 100 boundary line segments

$ ./run 20
# This will make a region with 20 boundary line segments

In order to clear all files created due to a single run of the code, use the following command.

$ make resetf
