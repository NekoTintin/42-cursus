find . -type f \( -name "*.sh" \) | rev | cut -c 4- | cut -f1 -d"/" | rev
