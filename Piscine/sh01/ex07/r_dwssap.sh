cat /etc/passwd | grep -v '#' | sed '1d; n; d' | awk -F : '{print $1}' | rev | sort -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | sed 's/$/, /g' | tr -d '\n' | sed 's/..$/./g' | tr -d '\n'
