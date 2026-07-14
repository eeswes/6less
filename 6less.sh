#!/bin/bash

export LD_PRELOAD=/usr/local/lib/lib6less.so
exec "$@"
