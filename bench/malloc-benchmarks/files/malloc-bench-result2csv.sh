#!/bin/sh

FOLDER=$(dirname "$1" 2>/dev/null)
[ -d "$FOLDER" ] && echo "no path given" && exit 1

SEP=";"
HEADER="User (U);System (S);Elapsed (E);Text (X);Data (D);Max Resident (M);Major Page Faults (F);Minor Page Faults(R);Swaps (W);Library;Test;CMD;ARG1;ARG2;..."

ALL="$HEADER"
for rf in $(find "$FOLDER" -iname "*.result") ; do
	CSV=$(sed "s/[[:space:]]/$SEP/g" $rf)
	echo "$HEADER
$CSV" > ${rf%.result}.csv
	ALL="$ALL
$CSV"
done

echo "$ALL" > "${OUT}/all.csv"
