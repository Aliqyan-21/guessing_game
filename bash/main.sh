#!/bin/bash

game() {
  min=$1; max=$2
  rand_num=$((min + RANDOM % (max - min + 1)))
  user_guess=0
  count=0

  echo "Guess the number I am thinking of between $min and $max..."
  echo -n "Your guess: "
  read user_guess

  while true; do
    if [ $user_guess -gt $rand_num ]; then
      ((count++))
      echo "I am thinking of a smaller number than that..."
      echo "Try again:"
      echo -n "Your guess: "
      read user_guess
    elif [ $user_guess -lt $rand_num ]; then
      ((count++))
      echo "I am thinking of a greater number than that..."
      echo "Try again:"
      echo -n "Your guess: "
      read user_guess
    else
      echo "Yes, you guessed it right $user_guess is the number I was thinking of!"
      echo "Total number of tries you took: $count"
      choice=""
      echo -n "Play again? [y/n]: "
      read choice
      if [ "${choice,,}" = "y" ]; then
        echo -n "Difficulty mode [easy/medium/hard]: "
        read mode
        case "${mode,,}" in
          "easy")
            game 1 100
            ;;
          "medium")
            game 1 200
            ;;
          "hard")
            game 1 300
            ;;
          *)
            echo "invalid mode"
            exit 1
            ;;
        esac
      else
        exit
      fi
    fi
  done
}

usage() {
  if [ $# -ne 1 ]; then
    echo "usage: $0 <mode[easy, medium, hard]>"
  fi
}

main() {
  usage $1

  mode=$1

  case "${mode,,}" in
    "easy")
      game 1 100
      ;;
    "medium")
      game 1 200
      ;;
    "hard")
      game 1 300
      ;;
    *)
      echo "invalid mode"
      exit 1
      ;;
  esac
}

main $@
