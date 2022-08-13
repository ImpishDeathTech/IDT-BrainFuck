# /usr/bin/sh

echo Compiling IDT-BrainFuck...
c++ -c brainfuck/main.cxx brainfuck/utils.cxx brainfuck/celllist.cxx brainfuck/interpreter.cxx

if [ $? == 1 ]
then
    echo "Fuckup! Could not compile IDT-BrainFuck x,..,X"
    exit 1
fi

echo Linking objects...
c++ -std=c++20 -o bf main.o utils.o celllist.o interpreter.o 

if [ $? == 1 ]
then
    echo "Fuckup! Could not link object files for IDT-BrainFuck x,..,X"
    exit 1
fi

echo Installing to "'/usr/bin/bf'"...
sudo mv bf /usr/bin/bf

if [ $? == 1 ]
then
    echo "Fuckup! IDT-BrainFuck compiled, but could not install to '/usr/bin/bf' x,..,X"
    exit 1
fi

echo
echo Done! BrainFuck has been installed on your system ^,..,^ 
echo 
echo Type 'bf -h' for options and usage
