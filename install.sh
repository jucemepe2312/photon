#!/bin/sh
set -e

SRC="src/photon.c"
BIN="bin/photon"
DEST="/usr/local/bin/photon"

command -v gcc >/dev/null 2>&1 || { echo "falta gcc"; exit 1; }

echo "compilando $SRC..."
mkdir -p bin
gcc -Wall -Wextra -O2 "$SRC" -o "$BIN"

echo "instalando en $DEST..."
install -Dm755 "$BIN" "$DEST"

echo "listo. prueba con: photon"