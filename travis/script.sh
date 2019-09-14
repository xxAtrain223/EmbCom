#!/usr/bin/env bash
set -e

pushd build
make -j2

./EmbComTest

popd

cppcheck src/*.cpp include/EmbCom/*.hpp
