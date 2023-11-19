#!/usr/bin/awk -f

{
    if ($1 == "Astolfo") {
        print "PEAK!"
    }
    else {
        print "f..."
    }
}