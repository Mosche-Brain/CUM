#!/usr/bin/env bash

printf '| Commit | Date | Author | Insertions | Deletions | Files | Subject |\n'
printf '|---|---|---|---:|---:|---:|---|\n'

git log --all --no-renames \
    --format='COMMIT%x09%h%x09%aI%x09%an%x09%s' \
    --numstat |
awk -F '\t' '
BEGIN { ins=0; del=0; files=0; seen=0 }

/^COMMIT\t/ {
    if (seen)
        printf "| `%s` | %s | %s | %d | %d | %d | %s |\n",
               hash, date, author, ins, del, files, subject

    hash=$2
    date=$3
    author=$4
    subject=$5
    ins=0
    del=0
    files=0
    seen=1
    next
}

NF == 3 {
    if ($1 ~ /^[0-9]+$/ && $2 ~ /^[0-9]+$/) {
        ins += $1
        del += $2
        files++
    }
}

END {
    if (seen)
        printf "| `%s` | %s | %s | %d | %d | %d | %s |\n",
               hash, date, author, ins, del, files, subject
}'