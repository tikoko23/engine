if test exec.out; then
    rm exec.out
fi

g++ main.cpp -o exec.out -Wall -Wextra

if test exec.out; then
    echo File built with success
else
    echo Errors occured while building the file
fi