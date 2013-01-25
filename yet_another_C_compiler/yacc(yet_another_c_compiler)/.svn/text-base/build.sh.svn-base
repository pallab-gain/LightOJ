#!/bin/sh
flex Parser.l
var=$?
if [ "$var" -eq 0 ] 
then 
    bison -dt Parser.y    
      var=$?
      if [ "$var" -eq 0 ] 
      then 
	gcc Parser.tab.c lex.yy.c -o run -ly -ll
	  if [ "$var" -eq 0 ] 
	  then 
	    ./run
	  fi
      fi
else
    echo ""
fi
exit
