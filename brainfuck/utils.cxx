/*
 * brainfuck/utils.cxx
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

#include "utils.hxx"
#include "config.hxx"

namespace bf {
    std::string read_in(std::string filePath) {
        std::string suffix = "",
                    output = "";
        
        for (size_t i = filePath.size() - 3; i < filePath.size(); i++) {
            suffix += filePath[i];
        }

        if (suffix != BF_FILE_SUFFIX) {
            std::cerr << BF_FUCKUP_FILE << filePath << BF_IS_NOT_BF_FILE;
            exit(EXIT_FAILURE);
        }

        else {
            std::ifstream fp(filePath);

            if (fp.fail()) {
                std::cerr << BF_FUCKUP_FILE << filePath << BF_DOESNT_EXIST;
                exit(EXIT_FAILURE);
            }
            
            while (fp.good()) 
                output += fp.get();
        }

        return output;
    }

    void help() {
        std::cout << "IDT-BrainFuck " << BF_VERSION_MAJOR << '.' << BF_VERSION_MINOR << '.' << BF_VERSION_PATCH 
                  << " Copyright (c) 2022, Christopher Stephen Rafuse\n"
                  << BF_HELP_MESSAGE;
    }

    void repl_help() { std::cout << BF_REPL_HELP_MESSAGE; }
}