#!/bin/bash

javac lib/NodeGen.java
javac -Xlint lib/ZLListGen.java
javac Main.java

java Main
echo $?
