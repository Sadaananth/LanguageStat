#!/bin/sh

third_party_path="third_party"
yaml_path="$third_party_path/yaml_cpp"
yaml_file="yaml-cpp-0.7.0.zip"
yaml_extracted_folder="yaml-cpp-yaml-cpp-0.7.0"

build_yaml()
{
    cd "$yaml_path"
    if [ ! -d "$yaml_extracted_folder" ];
    then
        unzip "$yaml_file"
        ln -s "$yaml_extracted_folder" "yaml-cpp"
    fi
    cd "yaml-cpp"
    mkdir build
    cd build
    cmake ..
    make -j$(nproc)
}

# download dependencies
wget -nc -P "$yaml_path" "https://github.com/jbeder/yaml-cpp/archive/refs/tags/$yaml_file"

build_yaml
