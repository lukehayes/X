long int start = 0, end = 0;
double delta = 0;
double ns = 1000000.0 / 60.0; // Syncs updates at 60 per second (59 - 61)

while (!quit) {

    start  = timeAsMicro();
    delta += (double)(start - end) / ns;
    end   =  start;

    while (delta >= 1.0) {
       doUpdates();
       delta-=1.0;
    }
}
