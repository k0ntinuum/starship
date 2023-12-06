#!/bin/bash
clang starship.c -O3 -L /opt/homebrew/lib/ -I /opt/homebrew/include/ -lraylib -std=c2x -o s && ./s