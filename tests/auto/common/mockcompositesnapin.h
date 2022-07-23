/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#ifndef MOCK_SNAP_IN_MANAGER_H
#define MOCK_SNAP_IN_MANAGER_H

#include "icompositesnapin.h"

#include <QMap>
#include <QString>
#include <QUuid>
#include <QVersionNumber>

#include <gmock/gmock.h>

namespace test
{
class MockCompositeSnapIn : public ::gpui::ICompositeSnapIn
{
public:
    MOCK_METHOD0(onInitialize, void());

    MOCK_METHOD0(onShutdown, void());

    MOCK_CONST_METHOD0(getId, QUuid());

    MOCK_CONST_METHOD0(getType, QString());

    MOCK_CONST_METHOD0(getRootNode, QUuid());

    MOCK_CONST_METHOD0(getDisplayName, QString());

    MOCK_CONST_METHOD0(getHelpText, QString());

    MOCK_CONST_METHOD0(getVersion, QVersionNumber());

    MOCK_CONST_METHOD0(getLicense, QString());

    MOCK_CONST_METHOD0(getCopyright, QString());

    MOCK_CONST_METHOD0(getDependencies, QMap<QString, QVersionNumber>());

    MOCK_CONST_METHOD0(getState, SnapInState());

    MOCK_METHOD1(setState, void(SnapInState));
};
} // namespace test

#endif //MOCK_SNAP_IN_MANAGER_H
