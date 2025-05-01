
echo "Il y a $(ls | grep -c ".txt$") fichiers (caches ou non) dont le nom se termine par .txt"
echo "Il y a $(ls | grep -c ".sh$") fichiers (caches ou non) dont le nom se termine par .sh"
echo "Il y a $(ls -a | grep -c "^\..*") fichiers caches"
echo "Il y a $(ls | grep -v -c "^\..*") autres fichiers"