#!/bin/bash

# Run factorial on the number in input.txt,
# pipe result into multiplyBy100,
# write final answer to output.txt
./printFactorial < input.txt | ./printMultiplyBy100 > output.txt