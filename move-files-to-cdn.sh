#!/bin/bash

####################################################################
# This script will replace all the references to files in _uploads #
# to their respective URLs in the HOT CDN.                         #
####################################################################

DIR=${0%/*}

set -x

# Loop through the files in _uploads

FILES=$DIR/_uploads/*
for f in $FILES
do
	# a bunch of different ways to make the filename/path. Example: ./_uploads/image name.jpg
	FNAME=$(basename "$f")                          # image name.jpg
	FILE=/uploads/$FNAME                            # /uploads/image name.jpg
	FNOSPACE=${FILE// /%20}                         # /uploads/image%20name.jpg
	FNAMEAWS=${FNAME// /+}                          # image+name.jpg
	OUTDIR=$DIR/uploads_archive/

	echo "Processing $FNOSPACE file..."
	# step 1: find every reference to that file
	# step 2: if the same file exists on the cdn, replace it with the CDN URI
	# step 3: mark the file for manual deletion by moving it to an archive folder
	aws s3api head-object --bucket hotosm-cdn --key "website/$FNAME" || not_exist=true # fast way to check file exists on s3
	if [ $not_exist ]; then
		echo "it does not exist on s3"
	else
		echo "it exists on s3 as $FNAMEAWS"
		if grep -r --exclude-dir='$DIR/.git' --exclude-dir='$DIR/_uploads' $FNOSPACE; then # check if file is referenced anywhere
			echo "Found reference $FNOSPACE"
			# the find command pipes a list of markdown files nicely into sed, which replaces the reference with the cdn url
			# flist=`find $DIR -type f \( -name "*.markdown" -o -name "*.md" \) -print0`
			# sed -i'' -e 's|${FNOSPACE//\//\\/}|https:\/\/cdn.hotosm.org\/website\/$FNAMEAWS|g' $flist

			# find $DIR -type f \( -name "*.markdown" -o -name "*.md" \) -print0 | xargs -0 -n 1 sed -i'' -e 's|${FNOSPACE//\//\\/}|https:\/\/cdn.hotosm.org\/website\/$FNAMEAWS|g'

			find $DIR -type f \( -name "*.markdown" -o -name "*.md" \) -print0 | xargs -0 -n 1 sed -i -e 's|'"$FNOSPACE"'|https:\/\/cdn.hotosm.org\/website\/'"$FNAMEAWS"'|g' # {} \;

		else
			echo "could not find reference in any file"
		fi
		# move the file to an untracked archive (eg delete from git tracking). enable when everything else is working
		mv $f $OUTDIR/$FNAME
	fi
done