#!/bin/sh

./compressor < compressor > compressor.compressed
./compressor -d < compressor.compressed > compressor2
cmp compressor compressor2 && echo "Ok." || echo "Fail."
