
sed -E 's/^([A-Z][a-z]+ [A-Z][a-z]+) 0([1-9])/\1 +33\2/' calepin.txt

sed -E 's/^([A-Z][a-z]+ [A-Z][a-z]+) 0([1-8])/\1 +33\2/' calepin.txt

sed -E 's/^([A-Z]+) ([A-Za-z]+)/\2 \1/' calepin.txt


