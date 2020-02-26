onerror {resume}
add list -width 10 /s1bit/x
add list /s1bit/y
add list /s1bit/cen
add list /s1bit/s
add list /s1bit/csal
configure list -usestrobe 0
configure list -strobestart {0 ps} -strobeperiod {0 ps}
configure list -usesignaltrigger 1
configure list -delta none
configure list -signalnamewidth 0
configure list -datasetprefix 0
configure list -namelimit 5
