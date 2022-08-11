/*
 * brainfuck/celllist.cxx
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

#include "celllist.hxx"

namespace bf {
    CellList::CellList() { 
        m_cells = (std::uint8_t*)malloc(m_size);
        m_ptr   = &m_cells[m_size / 2];
        m_head  = &m_cells[0];
        m_tail  = &m_cells[m_size - 1];

        for (std::size_t i = 0; i < m_size; i++)
            m_cells = 0x00;
    }

    CellList::CellList(std::size_t size) {
        m_size  = size;
        m_cells = (std::uint8_t*)malloc(m_size);
        m_ptr   = &m_cells[m_size / 2];
        m_head  = &m_cells[0];
        m_tail  = &m_cells[m_size - 1];

        for (std::size_t i = 0; i < m_size; i++)
            m_cells = 0x00;
    }

    void CellList::shiftRight() { 
        if (m_ptr != m_tail)
            m_ptr++;

        else m_ptr = m_head; 
    }

    void CellList::shiftLeft()  { 
        if (m_ptr != m_head)
            m_ptr--;
        
        else m_ptr = m_tail;
    }
            
}