This has a C-shaped domain being simplified into a number of polygonal zones.

Instructions to build and run the code:

$ make
$ ./run
# This makes a default region with n = 10 and 2*n+2, i.e. 22 boundary line segments

$ ./run 20
# This deivides the region with n = 20 and 2 * n + 2 = 42 boundary line segments

In order to remove files generated due to a previous run of the code, use the following command:
$ make resetf

For visualization with gnuplot use the following commands:

$ gnuplot
> p 'datap' w l
# Shows the outline of the region

> p 'region_zones' w l
# Shows the outline of the inner zones

> load 'region_vid'
# This will show an animation of how the zones were created

> p 'datap w l,'pnts'
# Shows how only points outside the region were selected while randomly generating points

