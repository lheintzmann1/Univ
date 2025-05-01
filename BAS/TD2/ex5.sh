
ls -l *.sh | grep "^-..w" | awk '{print $NF}' > exe.txt

ls -lS | grep "^-" | head -n 1

ls -a | grep "\." | wc -l

