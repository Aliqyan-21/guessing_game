sub usage()
  print "usage: " & command(0) & " <mode[easy/medium/hard]>"
  end
end sub

function gen_rand(min as integer, max as integer) as integer
  return int(rnd  * (max - min)) + min
end function

sub game(mode as string)
  dim rand_num as integer

  select case mode
    case "easy"
      rand_num = gen_rand(1, 100)
    case "medium"
      rand_num = gen_rand(1, 200)
    case "hard"
      rand_num = gen_rand(1, 300)
    case else
      print "choose mode between easy, medium, hard, you chose: " & mode
      end
  end select

  while true
    dim user_guess as integer
    print "Enter your guess: ";
    input user_guess

    if (user_guess = rand_num) then
      print "Congratulations your guess is correct : " & rand_num
      dim choice as string
      print "Wanna play again?[y/n]: ";
      line input choice
      choice = lcase(trim(choice))
      if (choice = "y") then
        print "what mode u wanna play now[easy/medium/hard]: ";
        dim m as string
        line input m
        game(m)
        exit while
      else
        exit while
      end if
    elseif (user_guess < rand_num) then
      print "Think of a greater number than " & user_guess
    elseif (user_guess > rand_num) then
      print "Think of a lower number than " & user_guess
    end if
  wend

end sub

'' main
sub main()
randomize

dim mode as String

if (len(command(1)) = 0) then
  usage()
end if

mode = command(1)
mode = lcase(trim(mode))
game(mode)
end sub

main()
