#!/bin/bash
#script pra pegar os modulos dos certificados

for file in cert*
do
	./pegar $file
done