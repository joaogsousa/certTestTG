#!/bin/bash
#script pra pegar os modulos dos certificados

find . -size 0 -delete
find . -name "cert*" -size -120c -delete
find . -name "cert*" -size +1100c -delete

egrep -r -l -i '/' ./ >> to_delete
egrep -r -l -i '\' ./ >> to_delete
egrep -r -l -i ',' ./ >> to_delete
xargs rm < to_delete
rm to_delete