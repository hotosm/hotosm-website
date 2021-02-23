#!/bin/bash

####################################################################
# This script will replace all the references to files in _uploads #
# to their respective URLs in the HOT CDN.                         #
####################################################################

DIR="${0%/*}"

# Loop through the files in _uploads

FILES=$DIR/_uploads/*
for f in $FILES
do
	echo "Processing $f file..."
	# step 1: find every reference to that file
	# step 2: if the same file exists on the cdn, replace it with the CDN URI
	# step 3: mark the file for manual deletion by moving it to an archive folder
done