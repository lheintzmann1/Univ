
if [ $# -ne 2 ]; then
    echo "Usage: $0 <fichier_source> <fichier_traduit>"
    exit 1
fi

if [ ! -f $1 ]; then
    echo "Le fichier à traduire n'existe pas"
    exit 2
fi

if [ -f $2 ]; then
    echo "Le fichier de destination existe déjà"
    read -p "Voulez-vous l'écraser ? (o/n) " rep
    if [ $rep != "o" ]; then
        exit 3
    else
        rm $2
    fi
fi

while read ligne; do
    for mot in $ligne; do
        trad=$(grep -w $mot dico.txt | cut -d' ' -f2)
        if [ -z $trad ]; then
            echo "Le mot $mot n'a pas de traduction"
            exit 4
        fi
        echo -n "$trad " >> $2
    done
    echo >> $2
done < $1

exit 0
