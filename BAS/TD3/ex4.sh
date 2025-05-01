
if [ $# -ne 1 ]; then
	echo "Usage: $0 <fichier>"
	exit 1
fi

if file "$1" | grep -q "executable"; then
	echo "OK"
	exit 0
else
	exit 1
fi


