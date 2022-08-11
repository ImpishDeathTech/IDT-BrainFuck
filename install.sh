echo Compiling IDT-BrainFuck...
c++ -c brainfuck/main.cxx brainfuck/utils.cxx brainfuck/celllist.cxx brainfuck/interpreter.cxx

echo Linking objects...
c++ -std=c++20 -o bf main.o utils.o celllist.o interpreter.o 

echo Istalling to '/usr/bin/bf'...
sudo mv bf /usr/bin/bf

echo
echo Done! BrainFuck has been installed on your system ^,..,^ 
echo 
echo Type 'bf -h' for options and usage
