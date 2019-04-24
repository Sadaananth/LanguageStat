#!/bin/sh

TMP_FOLDER="./tmp"
BIN_FOLDER="./bin"
SRC_FOLDER="./src"
BIN_NAME="LanguageStat"
CMAKE_LISTS_PATH="../"

clean_pre_build()
{
	sh clean.sh "ALL"
}

clean_post_build()
{
	sh clean.sh "OBJ"
}

build_all()
{
	mkdir $TMP_FOLDER $BIN_FOLDER
	cd $TMP_FOLDER
	cmake $CMAKE_LISTS_PATH -DLOG_STATUS="ENABLED"
	make
	cd ../		
}

move_bin()
{
	mv $TMP_FOLDER/$BIN_NAME $BIN_FOLDER
}

main()
{
	clean_pre_build
	build_all
	move_bin
	clean_post_build
}

main
