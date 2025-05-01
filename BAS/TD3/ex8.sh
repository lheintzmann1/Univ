
i=1
for param in "$@"; do
    echo "paramètre$i=$param"
    ((i++))
done

