#!/bin/sh

TMP_FOLDER="./tmp"
BIN_FOLDER="./bin"
SRC_FOLDER="./src"
BIN_NAME="LanguageStat"

ARG=$1

main()
{
	if [ "$ARG" = "OBJ" ]
	then
		rm -r $TMP_FOLDER
	elif [ "$ARG" = "ALL" ]
	then
		rm -r $TMP_FOLDER $BIN_FOLDER
	else
		echo "Incorrect Argument!!!!"
	fi
}

main 
