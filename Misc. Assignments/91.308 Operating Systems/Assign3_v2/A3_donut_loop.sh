#! /bin/sh

# usage: A3_linux_donut_loop.sh  number_of_runs_integer
# so from the shell prompt:  $ A3_linux_donut_loop.sh 10 
# will run the proddonuts program and the consdonuts
# programs (5 of them) 10 times and report how many
# of the 10 runs ended in deadlock

if [ -z $1 ]
then
echo "USAGE: A3_linux_donut_loop.sh  number_of_runs_integer"
echo "Try the command again"
echo " "
fi

echo " "
echo "The configuration is for $1 LOOPS"
echo " "

local1=$1
count=0
while test $local1 -ne 0
do
echo " "
echo "Working on LOOP $local1"
echo " "
./proddonuts >  prod_out.txt & 
sleep 1 
./consdonuts 1 & ./consdonuts 2 & ./consdonuts 3 & ./consdonuts 4 & ./consdonuts 5 & 
sleep 20
pid=`ps | grep -v 'grep' | grep 'proddonuts' | cut -c1-6`
if ps | grep -v 'grep' | grep 'consdonuts'
then
echo " "
echo "DEADLOCK CITY ON LOOP $local1"
echo " "
count=`expr $count + 1`
fi
echo "#### KILLING PRODUCER PROCESS $pid"
kill $pid
local1=`expr $local1 - 1`
sleep 1
done
echo $1 loops and $count deadlocks
