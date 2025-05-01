
if [ $# -ne 1 ]; then
    echo "Usage: $0 <n>" >&2
    exit 1
fi

n=$1

if ! [[ $n =~ ^[0-9]+$ ]]; then
    echo "n doit être un entier positif" >&2
    exit 2
fi

if [ ! -f liste.txt ]; then
    echo "Le fichier liste.txt n'existe pas" >&2
    exit 3
fi

tail -n $n liste.txt

exit 0
