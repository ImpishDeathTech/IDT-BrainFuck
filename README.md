# IDT-BrainFuck Interpreter
### Speedy BrainFuck Interpreter with a fair ammount of features (for a brainfuck interpreter anyway)

 I was bored, so I decided to throw together a brainfuck interpreter of my own design.
 It's turned out pretty nice so far, so I thought I'd share it with the world. Enjoy
 a little product of my insanity. ;3

Note: **Do _not_** set the cell list size under 1014, or you will get undefined behavior.
      I will try to patch this bug in future builds.

### Usage:

Type `bf` alone in the terminal to run interactive interpreter
    
Type `bf <file path>.bf` to run a brainfuck script

Add switches to tell the interpreter what you want to do.
    
`-i`  `-o` & `-s` can be used in combination, `-a` & `-h` are to be used on their own.
    
### Switches:
    
    -i : Set the input file path 
        bf <file name>.bf -i <input file>
        
        - note that this is the input you read with the ',' command,
          not the script you are interpreting - that should simply 
          be the first argument of the program call
    
    -o : Set the output file path 
        bf <file name>.bf -o <output file>
    
    -s : Set the size of the cell array (currently broken)
        bf <file name>.bf -s <array size>
    
    -a : Start the interpreter in auto eval REPL mode
        bf -a
    
    -h : Prints this message
        bf -h

### REPL Commands:
    
    $ : Execute code in command execution mode
        - This allows you to write out several 
          lines before executing a block of brainfuck code
            
    % : Switch between auto eval and command eval
            
    * : Clears the REPL terminal

    @ : Show the current memory address and the contained value 
        - both are displayed in hexadecimal

    ! : Exit interpreter
    
### Installing:

I've written a simple install shell script for unix and unix-like users. All you need to do is:
    
```sh
git clone https://github.com/ImpishDeathTech/IDT-BrainFuck.git && cd IDT-BrainFuck
chmod +x install.sh && ./install.sh
``` 
