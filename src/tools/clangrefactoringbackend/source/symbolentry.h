/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include <utils/smallstring.h>

#include <llvm/ADT/SmallVector.h>
#include <llvm/ADT/StringRef.h>

#include <limits>
#include <unordered_map>
#include <iosfwd>

namespace ClangBackEnd {

class SymbolEntry
{
public:
    SymbolEntry(const llvm::SmallVector<char, 128> &usr,
                llvm::StringRef name)
        : usr(usr.data(), usr.size()),
          symbolName(name.data(), name.size())
    {}

    SymbolEntry(Utils::PathString &&usr,
                Utils::SmallString &&symbolName)
        : usr(std::move(usr)),
          symbolName(std::move(symbolName))
    {}

    Utils::PathString usr;
    Utils::SmallString symbolName;

    friend bool operator==(const SymbolEntry &first, const SymbolEntry &second)
    {
        return first.usr == second.usr && first.symbolName == second.symbolName;
    }
};

using SymbolEntries = std::unordered_map<uint, SymbolEntry>;

std::ostream &operator<<(std::ostream &out, const SymbolEntry &entry);

} // namespace ClangBackEnd