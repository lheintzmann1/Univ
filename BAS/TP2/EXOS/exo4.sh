
if [ $# -eq 0 ]
then
    if [ -z "$(ls | grep .txt)" ]
    then
        echo "Aucun fichier .txt n'a été trouvé dans le répertoire courant" >&2
        exit 1
    else
        for fi in $(ls | grep .txt)
        do
            awk '{print $2}' $fi
            exit 0
        done
    fi
    
    done
    echo "Aucun fichier .txt n'a été trouvé dans le répertoire courant" >&2
    exit 1
fi

if [ ! -f $1 ]
then
    echo "Le fichier $1 n'existe pas" >&2
    exit 2
fi

if [ ! -r $1 ]
then
    echo "Le fichier $1 n'est pas lisible" >&2
    exit 3
fi


awk '{print $2}' $1
exit 0