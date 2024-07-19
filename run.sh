if test -e exec.out; then
    echo Clearing previous file...
    rm exec.out
fi

scons

if test -e exec.out; then
    echo -e "\x1b[38;5;46m\x1b[1mFile built with success\x1b[0m"
    echo -e "\x1b[38;5;mstdout begin\x1b[0m"
    ./exec.out
    echo -e "\x1b[38;5;mstdout end\x1b[0m"
else
    echo -e "\x1b[38;5;196m\x1b[1mErrors occured while building the file\x1b[0m"
fi