#!/bin/bash

getArtistName() {
    artist=$(ffprobe -loglevel error -show_entries format_tags=artist -of default=noprint_wrappers=1:nokey=1 "$1")

    artist="${artist// /}"

# I wrote this one to take one argument and set a global variable to the 
    # artist's name with whitespace removed
    # Note that this is where you'll want/need to use ffprobe
}

getSongName() {
   song=$(ffprobe -loglevel error -show_entries format_tags=title -of default=noprint_wrappers=1:nokey=1 "$1")

   song="${song// /}"

# Same deal as getArtistName but with the song name
    # Note that this is where you'll want/need to use ffprobe
}

doConversion() {
    # This function performs the conversion on a single file
   getArtistName "$1"
   getSongName "$1"
   dir="$2"
   ffmpeg -i "$1" "$dir"/"$artist"_"$song".mp3
}

# Takes one argument, that being a directory
TARGET_DIR=$1

# Now we should iterate over every file in the directory and do the conversion
# for each file
for i in $TARGET_DIR/*
do
 doConversion "$i" "$TARGET_DIR"
 rm "$i"
done
exit 0
