plot '<tail -n 200 plot.dat' using 1:2 with lines
set yrange[0:4100]
reread;

