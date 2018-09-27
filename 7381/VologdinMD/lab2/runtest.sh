#!/bin/bash
gcc ./Source/lab2_v2.c ./Source/func.h -o Lab2
echo "Test1 input: ((1,((5,3)(3,5)))(2,((3,1)(1,3))))"
cat ./Tests/test1.txt

echo "Test2 input: ((3,((2,((5,1)(1,((3,2)(2,3)))))(6,2)))(4,((1,((1,4)(4,1)))(5,1))))"
cat ./Tests/test2.txt

echo "Test3 input: ((1,((3,((2,2)(2,2)))(2,((2,((1,1)(1,1)))(1,4)))))(2,((6,4)(4,((1,3)(3,1))))))"
cat ./Tests/test3.txt

echo "Test4 input: ((2,0)(5,0))"
cat ./Tests/test4.txt

echo "Test5 input:  ((-6,2)(6,8))"
cat ./Tests/test5.txt