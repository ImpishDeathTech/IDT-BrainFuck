/*
 * brainfuck/main.cxx
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

#include <cstring>
#include <list>

#include "brainfuck.hxx"

int main(int ac, char** av) {
    std::string     code     = "",
                    output   = "";
    bf::Interpreter brainfuck;

    if (ac >= 2) {
        if (!strcmp(av[1], "-h"))
            bf::help();

        else if (!strcmp(av[1], "-a"))
            brainfuck.repl(true);
        
        else {
            code = bf::read_in(av[1]);

            for (int i = 2; i < ac; i++) {
                if (!strcmp(av[i], "-i") && !brainfuck.input(av[++i]))
                    std::cerr << BF_FUCKUP_FILE << av[i] << BF_DOESNT_EXIST;

                else if (!strcmp(av[i], "-o"))
                    output = av[++i];

                else if (!strcmp(av[i], "-s")) {
                    std::stringstream ss;
                    std::size_t       size = 0;
                    ss << av[++i];
                    ss >> size;
                    brainfuck.resize(size);
                }
            }
            
            if (output == "")
                std::cout << brainfuck.eval(code);

            else {
                std::ofstream fp(output, std::ios::trunc);
                fp << brainfuck.eval(code);
                fp.close();
            }
        }
    }
    else brainfuck.repl();

    return EXIT_SUCCESS;
}
