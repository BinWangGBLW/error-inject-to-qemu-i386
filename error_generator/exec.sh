#!/bin/bash
# This is the script of error generator is verify the performance of QEMU under i386 architecture
# For more details please contact Bin Wang B.Wang@qub.ac.uk

echo "Activating Simulation Debug"
#tail -f /var/log/syslog &

echo "Begin Error injection"

# -t    total ticks=12000000000 
# -i    golden simulation mem_init=0 
# -e    golden simulation mem_end=33554432 (128M)
# -f    number of errors to be generated
# -o    output file
# -r    target memory with errors mem_init=0x135488 
# -b    target memory with errors mem_end=0x1354A8
# -a    number of registers

#./error_generator  -t 240000000000 -i 0 -e 33554432 -f 5 -o /home/binqbu2002/error-record/error-simulate.txt -r 1266056 -b 1266856 -a 8
./error_generator  -t 120000000000 -i 0 -e 33554432 -f 5 -o /home/binqbu2002/error-record/error-simulate.txt -r 1266056 -b 1266856 -a 8
echo "Starting Simulation"


