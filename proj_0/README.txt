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
