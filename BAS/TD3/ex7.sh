
if [ $# -ne 2 ]; then
    echo "Erreur: Deux entiers requis." >&2
    exit 1
fi

if ! [[ "$1" =~ ^[1-9][0-9]*$ ]] || ! [[ "$2" =~ ^[1-9][0-9]*$ ]]; then
    echo "Erreur: Les deux valeurs doivent être des entiers strictement positifs." >&2
    exit 1
fi

if [ "$1" -gt "$2" ]; then
    echo "OK"
    exit 0
else
    exit 1
fi

