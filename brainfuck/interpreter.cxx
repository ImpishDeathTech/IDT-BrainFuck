/*
 * brainfuck/interpreter.cxx
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

#include "interpreter.hxx"
#include "utils.hxx"

namespace bf {
    bool Interpreter::input(std::string filePath) {
        std::ifstream fp(filePath);

        if (fp.fail()) {
            std::cerr << BF_FUCKUP_FILE << filePath << BF_DOESNT_EXIST;
            return false;
        }

        while (fp.good()) 
            m_input += fp.get();
        
        fp.close();

        return true;
    }

    std::string Interpreter::eval(std::string code) {
        std::stringstream output;
        std::size_t       codeIndex,
                          inputIndex = 0,
                          isLoop     = 0;

        for (codeIndex = 0; codeIndex < code.size(); codeIndex++) {
            switch (code[codeIndex]) {
                case BF_RIGHT:
                    m_cells->shiftRight();
                    break;
                
                case BF_LEFT:
                    m_cells->shiftLeft();
                    break;
                
                case BF_ADD:
                    m_cells->addOne();
                    break;
                
                case BF_SUB:
                    m_cells->subOne();
                    break;

                case BF_OUT:
                    output << m_cells->data();
                    break;
                
                case BF_IN:
                    m_cells->data() = m_input[inputIndex++];
                    break;
                
                case BF_BEG:
                    if (m_cells->data() == BF_NULL){
                        for (isLoop = 1; isLoop; codeIndex++) {
                            if (code[codeIndex] == BF_BEG)
                                isLoop++;
                        
                            else if (code[codeIndex] == BF_END) 
                                isLoop--;
                        }
                    }
                    break;
                
                case BF_END:
                    if (m_cells->data() != BF_NULL) {
                        codeIndex -= 2;

                        for (isLoop = 1; isLoop; codeIndex--) {
                            if (code[codeIndex] == BF_END)
                                isLoop++;
                            
                            else if (code[codeIndex] == BF_BEG)
                                isLoop--;
                        }

                        codeIndex++;
                    }
                    break;
            }
        }
        return output.str();
    }

    void Interpreter::repl(bool autoEval) {
        std::string code  = "",
                    input;

        std::cout << "IDT-BrainFuck " << BF_VERSION_MAJOR << '.' << BF_VERSION_MINOR << '.' << BF_VERSION_PATCH 
                  << " Copyright (c) 2022, Christopher Stephen Rafuse\n\tType '?' for input help\n\n[BF]: ";
        
        std::cin >> input;


        while (input[0] != BF_REPL_QUIT) {
            if (input[0] == BF_REPL_CLEAR) {

#if defined(IDT_BRAINFUCK_UNIX)
                system("clear");

#elif defined(IDT_BRAINFUCK_WINDOWS)
                system("clr");
#endif 
            }
            else if (input[0] == BF_REPL_CHECK) {
                std::cout << "\n[ADDR]: " << m_cells->address() << ")\n[DATA]: " << std::hex << (std::uint16_t)m_cells->data() << "\n\n";

                for (char& c : input) {
                    if (c == BF_REPL_CHECK)
                        continue;

                    code += c;
                }
            }
            else if (input == BF_REPL_HELP)
                repl_help();
            
            else if (input == BF_REPL_MODE) {
                if (autoEval = true)
                    autoEval = false;
                
                else autoEval = true;
            }
            else if (autoEval && input != "") {
                std::cout << eval(input) << std::endl;
                input = "";
            }
            else {
                if (input[input.size() - 1] == BF_REPL_EXEC) {
                    input.pop_back();
                    code += input;
                    std::cout << eval(code) << std::endl;
                    code = input = "";
                }
                else {
                    code += input;
                    input = "";
                }
            }

            std::cout << "[BF]: ";
            std::cin >> input;
        }
    }
      
}