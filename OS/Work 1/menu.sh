#!/bin/bash

echo "Menu"
echo "  1 Nano"
echo "  2 Vi"
echo "  3 Browser"
echo "  4 Exit"

read option;

case $option in
    "1")
        "nano"
        ;;
    "2")
        "nano"
        ;;
    "3")
        "ps"
        ;;
    "4")
        "exit"
        ;;
esac