/*
 * brainfuck/config.hxx
 *
 * BSD 3-Clause License
 * 
 * Copyright (c) 2022, Christopher Stephen Rafuse
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef IDT_BRAINFUCK_CONFIG
#define IDT_BRAINFUCK_CONFIG

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define BF_VERSION_MAJOR 1
#define BF_VERSION_MINOR 3
#define BF_VERSION_PATCH 2

#define BF_FILE_SUFFIX ".bf"
#define BF_PROMPT      "[BF]: "

#define BF_LEFT  '<'
#define BF_RIGHT '>'
#define BF_ADD   '+'
#define BF_SUB   '-'
#define BF_OUT   '.'
#define BF_IN    ','
#define BF_BEG   '['
#define BF_END   ']'
#define BF_STATE '#'
#define BF_NULL  '\0'
#define BF_MAX   0xFF

#define BF_REPL_CLEAR  '*'
#define BF_REPL_EXEC   '$'
#define BF_REPL_QUIT   '~'
#define BF_REPL_HELP   "?"
#define BF_REPL_MODE   '%'

#define BF_COMMENT_BEG ':'
#define BF_COMMENT_END ';'

#define BF_FUCKUP_SEG_FAULT "[FUCKUP]: Seg Fault! Can't pass addr:"
#define BF_FUCKUP_FILE      "[FUCKUP]: File '"
#define BF_DOESNT_EXIST     "' doesn't exist! x,..,X\n"
#define BF_IS_NOT_BF_FILE   "' is not a BrainFuck script!\n\tIDT-BrainFuck scripts are suffixed with '.bf'\n"

const std::string BF_HELP_MESSAGE = 
R"_help_(
    Type 'bf' alone in the terminal to run interactive interpreter
    Type 'bf <file path>.bf' to run a brainfuck script

switches:

    -i : Set the input file path 
        bf <file name>.bf -i <input file>

        - note that this is the input you read with the ',' command,
          not the script you are interpreting - that should simply 
          be the first argument of the program call

    -o : Set the output file path 
        bf <file name>.bf -o <output file>

    -s : Set the size of the cell array (minimum 1014 bytes)
        bf <file name>.bf -s <array size>

    -a : Start the interpreter in auto eval REPL mode
        bf -a

    -h : Prints this message
        bf -h

)_help_",
                 BF_REPL_HELP_MESSAGE =
R"_repl_help_(
Program State:

    # : shows the current pointer address and the first 10 cells
        this works in both scripts and the live interpreter

REPL Commands:

    $ : Execute code in command execution mode.
        - This allows you to write out several 
          lines beforeexecuting a block of brainfuck code
            
    % : Switch between auto execution and command execution
            
    * : Clears the REPL terminal

    @ : Show the current memory address and the contained value 
        - both are displayed in hexadecimal

    ~ : Exit interpreter

)_repl_help_";

#if defined(__unix__)
#define IDT_BRAINFUCK_UNIX
#include <unistd.h>

#elif defined(_WIN32)
#define IDT_BRAINFUCK_WINDOWS
#include <Windows.h>

#endif

#endif

#endif

