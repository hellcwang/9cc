#!/bin/bash

try() {
	expected="$1"
	input="$2"

	./9cc "$input" 
	gcc -o tmp tmp.s
	./tmp
	actual="$?"
	if [ "$actual" = "$expected" ]; then
		echo "$input => $actual"
	else
		echo "$input => $expected expected but wrong with $?"
		exit 1
	fi
}

try 8 8
try 123 123 
echo OK

