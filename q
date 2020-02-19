#!/bin/bash
#========================================
# Script to submit job in Intel devcloud
#
# Author: rakshith.krishnappa@intel.com
# Version: 0.2
#========================================
if [ -z "$1" ]; then
    echo "Missing script argument, Usage: ./q run.sh"
elif [ ! -f "$1" ]; then
    echo "File $1 does not exist"
else
    script=$1
    rm *.sh.* > /dev/null 2>&1
    if []
    echo "Submitting job:"
    qsub -q batch@v-qsvr-nda -l nodes=1:gpu:ppn=2 -d . $script -F "$2"
    #qstat
    qstat -s batch@v-qsvr-nda
    #wait for output file to be generated and display
    echo -ne "Waiting for Output."
    until [ -f $script.o* ]; do
        sleep 1
        echo -ne "."
    done
    cat $script.o*
    cat $script.e*
fi
