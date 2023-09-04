#!/opt/homebrew/bin/bash

## Not good
cp /my/location/from /my/location/to

cp /my/location/from/here /my/location/to/there

## Better
MY_LOCATION_FROM=/my/location/from
MY_LOCATION_TO=/my/location/to

cp $MY_LOCATION_FROM $MY_LOCATION_TO

cp "$MY_LOCATION_FROM/here" "$MY_LOCATION_TO/there"

cp "${MY_LOCATION_FROM}/here" "${MY_LOCATION_TO}/there"
