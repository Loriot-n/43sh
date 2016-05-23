#!/bin/bash

echo $$

SHELL="./42sh"
REFER="/bin/tcsh -f"

CAT=`which cat`
GREP=`which grep`
SED=`which sed`
RM=`which rm`
TR=`which tr`
HEAD=`which head`
TAIL=`which tail`
WC=`which wc`
CHMOD=`which chmod`
EXPR=`which expr`
MKDIR=`which mkdir`
CP=`which cp`

disp_test()
{
  id=$1
  $CAT tests | $GREP -A1000 "\[$id\]" | $GREP -B1000 "^\[$id-END\]" | $GREP -v "^\[.*\]"
}

run_script()
{
  SC="$1"
  echo "$SC" > /tmp/.tmp.$$
  . /tmp/.tmp.$$
  $RM -f /tmp/.tmp.$$
}

load_test()
{
  id=$1
  debug=1
  SETUP=`disp_test "$id" | $GREP "SETUP=" | $SED s/'SETUP='// | $SED s/'"'//g`
  CLEAN=`disp_test "$id" | $GREP "CLEAN=" | $SED s/'CLEAN='// | $SED s/'"'//g`
  NAME=`disp_test "$id" | $GREP "NAME=" | $SED s/'NAME='// | $SED s/'"'//g`
  TESTS=`disp_test "$id" | $GREP -v "SETUP=" | $GREP -v "CLEAN=" | $GREP -v "NAME=" | $GREP -v "TESTS=" | $TR "\n" "²" | $SED s/"²$"//`
  run_script "$SETUP"
  echo "#!/bin/bash" >/tmp/.test.$$
  echo "$TESTS" | $TR "²" "\n" >> /tmp/.test.$$
  $CHMOD 755 /tmp/.test.$$
  /bin/bash -c "/tmp/.test.$$ | $REFER ; echo exit "'$?' > /tmp/.output.refer.$$ 2>&1
  /bin/bash -c "/tmp/.test.$$ | $SHELL ; echo exit "'$?' > /tmp/.output.shell.$$ 2>&1
  nb=`$CAT /tmp/.output.refer.$$ | $WC -l`
  i=1
  ok=1
  while [ $i -le $nb ]
  do
    l=`$CAT /tmp/.output.refer.$$ | $HEAD -$i | $TAIL -1`
    a=`$CAT /tmp/.output.shell.$$ | $GREP -- "$l" | $WC -l`
    if [ $a -eq 0 ]
    then
      ok=0
    fi
    i=`$EXPR $i + 1`
  done
  run_script "$CLEAN"
  if [ $ok -eq 1 ]
  then
    if [ $debug -ge 1 ]
    then
      echo "Test $id ($NAME) : OK"
      if [ $debug -eq 2 ]
      then
        echo "Output $SHELL :"
        $CAT -e /tmp/.output.shell.$$
        echo ""
        echo "Output $REFER :"
        $CAT -e /tmp/.output.refer.$$
        echo ""
      fi
    else
      echo "OK"
    fi
  else
    if [ $debug -ge 1 ]
    then
      echo "Test $id ($NAME) : KO - Check output in /tmp/test.$$/$id/"
      $MKDIR -p /tmp/test.$$/$id 2>/dev/null
      $CP /tmp/.output.refer.$$ /tmp/test.$$/$id/tcsh.out
      $CP /tmp/.output.shell.$$ /tmp/test.$$/$id/mysh.out
    else
      echo "KO"
    fi
  fi
  $RM -f /tmp/.test.$$
  $RM -f /tmp/.output*$$
}

make_manifest()
{
  echo '{'
  echo '  "module": "B-PSU-156",'
  echo '  "project": "42sh",'
  echo '  "skills": {'
  i=0
  for lst in `cat tests | grep "^\[.*\]$" | grep -vi end | sed s/'\['// | sed s/'\]'//`
  do
  if [ $i -eq 1 ]
  then
    echo ','
  else
    i=1
  fi
  NAME=`disp_test "$lst" | $GREP "NAME=" | $SED s/'NAME='// | $SED s/'"'//g`
  echo '    "Test '$lst'": {'
  echo '      "output": ['
  echo '        {'
  echo '          "name": "'$NAME'",'
  echo '          "cmd": "./moul.sh '$lst'",'
  echo '          "expected": "^OK"'
  echo '        }'
  echo '      ]'
  echo -n '    }'
  done
  echo ""
  echo '  }'
  echo '}'
}

for sig in `trap -l`
do
  echo "$sig" | grep "^SIG" >/dev/null 2>&1
  if [ $? -eq 0 ]
  then
    trap "echo Received signal $sig !" $sig
  fi
done

if [ ! -f tests ]
then
  echo "No tests file. Please read README.ME"
  exit 1
fi

if [ ! -x $SHELL ]
then
  echo "Can't exec $SHELL"
  exit 1
fi

if [ $# -eq 2 ]
then
  echo "Debug mode"
  echo "Shell : $SHELL"
  echo "Reference : $REFER"
  echo ""
fi

if [ $# -eq 0 ]
then
  for lst in `cat tests | grep "^\[.*\]$" | grep -vi end | sed s/'\['// | sed s/'\]'//`
  do
    path_backup=$PATH
    load_test $lst 1
    export PATH=$path_backup
  done
else
  if [ "X$1" = "X0" ]
  then
    echo "Making manifest.json"
    make_manifest > manifest.json
  else
    if [ $# -eq 1 ]
    then
      load_test $1 0
    else
      if [ "X$1" = "X-d" ]
      then
        (load_test $2 2)
      else
        (load_test $1 2)
      fi
    fi
  fi
fi
