cat /etc/passwd | awk "NR %2==1" | sed -e 's/:.*//' | rev |  sort -d -r |  sed -n "$FT_LINE1","$FT_LINE2"p | xargs |  sed -e 's/ /, /g' | sed '$s/$/./'
