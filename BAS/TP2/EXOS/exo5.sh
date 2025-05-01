
if [ $# -lt 1 ] || [ $# -gt 2 ] 
then
    echo "Usage: $0 <directory> [extension]" >&2
    exit 1
fi

if [ ! -d $1 ] 
then
    echo "Error: $1 is not a directory" >&2
    exit 2
fi

if [ $# -eq 1 ] 
then
    echo $(find $1 -maxdepth 1 -name "*.sh")
    exit 0
else
    echo $(find $1 -maxdepth 1 -name "*.$2")
    exit 0
fi

