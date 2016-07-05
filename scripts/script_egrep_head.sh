#!/bin/bash
#script pra pegar os modulos dos certificados

rm ../certsBrasil3
rm ../certsBrasil4

for file in cert*
do
	rm certsBrasil3
	egrep -i -w 'boavista|caixa|fenacon|fenacor|imesp|instituto|brasileira|brasileiro|informacao|icp-brasil|notarial|brasil|petrobras|prodemge|proderj|prodest|serasa|serpro|sincor|tribunal' $file >> ../certsBrasil3
	if [ ! -s ../certsBrasil3 ]
	then
            echo $file >> certsBrasil4
        fi
done