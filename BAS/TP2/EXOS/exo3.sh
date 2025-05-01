
if [ $# -ne 3 ] ; then
    echo "Usage: $0 <source_file> <target_file> <target_directory>"
    exit 1
fi

if [ ! -f $1 ] ; then
    echo "Le fichier $1 n'existe pas ou n'est pas un fichier"
    exit 2
fi

if [ ! -r $1 ] ; then
    echo "Le fichier $1 n'est pas lisible"
    exit 3
fi

if [ -f $2 ] ; then
    if [ ! -w $2 ] ; then
        echo "Le fichier $2 n'est pas accessible en écriture"
        exit 4
    fi
fi

if [ -d $3 ] ; then
    if [ ! -w $3 ] ; then
        echo "Le répertoire $3 n'est pas accessible en écriture"
        exit 5
    fi
fi

if [ ! -d $3 ] ; then
    mkdir $3
fi

if [ ! -w $3 ] ; then
    echo "Le répertoire $3 n'est pas accessible en écriture"
    exit 6
fi

if [ ! -f $3/$2 ] ; then
    touch $3/$2
fi

sort -k1 $1 > $3/$2
exit 0
