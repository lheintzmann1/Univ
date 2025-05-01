
if [ $# -ne 1 ]; then
    echo "Usage: $0 <fichier>"
    exit 1
fi

fichier="$1"

echo "Nom du fichier : $fichier"

if [ -f "$fichier" ]; then
    echo "Type : Fichier"
elif [ -d "$fichier" ]; then
    echo "Type : Répertoire"
else
    echo "Type : Inconnu"
fi

[ -r "$fichier" ] && echo "Droit de lecture : Oui" || echo "Droit de lecture : Non"
[ -w "$fichier" ] && echo "Droit d'écriture : Oui" || echo "Droit d'écriture : Non"
[ -x "$fichier" ] && echo "Droit d'exécution : Oui" || echo "Droit d'exécution : Non"

