#!/usr/bin/env bash
set -e
mkdir build
cd build

cmake -DEmbCom_ENABLE_TESTING:BOOL=ON ..
