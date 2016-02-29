#!/bin/sh

killall testserver
MessageSize = 4 * 1024 * 1024
nClient = 100

./testServer & ServerPid=$!
./testClient 127.0.0.1 $nClient $MessageSize

kill -9 $ServerPid
