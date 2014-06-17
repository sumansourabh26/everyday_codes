#!/bin/bash
#!/bin/sh

NAME=("val" "kakak" "ajkljll")
NAME[1]="kjsavkjengvkj"
a=0
b=1

count=0
#echo ${a[0]}

while(( $count < $1 ))
do
	b=` expr $b + $a`
	a=` expr $b - $a`
	count=`expr $count + 1`
done

echo $b