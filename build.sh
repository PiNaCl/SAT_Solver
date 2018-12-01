#!/bin/sh

BOLD=$(tput bold)
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC=$(tput sgr0)

echo "${BOLD}Moving to ./src${NC}"

cd ./src

echo "${BOLD}Compiling SAT solver...${NC}"

ok=$(make sat || echo "${RED}Compilation failed${NC}" && echo "${GREEN}Done${NC}")

echo "${BOLD}Cleaning temporary files...${NC}"

make || echo "\t${RED}Cleaning failed${NC}" && echo "\t${GREEN}Done${NC}"

echo "${BOLD}Moving executable at root...${NC}"

mv sat ../sat

if [ ok ]; then
    echo "${BLUE}You can start the program by executing ./sat${NC}"
fi