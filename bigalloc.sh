#!/bin/bash

count=20
for i in $(seq $count); do
	sleep 1
	./bigalloc
	echo " "
done
