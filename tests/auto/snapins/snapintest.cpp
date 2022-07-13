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

#include "snapintest.h"

#include "abstractsnapin.h"

using namespace gpui;

namespace test
{
const QString snapInType           = "ISnapIn";
const QString snapInName           = "TestSnapIn";
const QString snapInDescription    = "Description";
const QVersionNumber snapInVersion = {1, 0, 0};
const QString snapInLicesnce       = "MIT";
const QString snapInCopyright      = "BaseALT";
const QUuid snapInId               = "00000000-1111-2222-3333-000000000000";

class TestConstructorSnapIn : public AbstractSnapIn
{
public:
    TestConstructorSnapIn()
        : AbstractSnapIn(snapInType,
                         snapInName,
                         snapInDescription,
                         snapInVersion,
                         snapInLicesnce,
                         snapInCopyright)
    {
        setId(snapInId);
    }

    void onInitialize(){};

    void onShutdown(){};
};

TEST_F(SnapInTest, SnapInConstructorTest)
{
    TestConstructorSnapIn testSnapIn;

    ASSERT_EQ(testSnapIn.getId(), snapInId);
    ASSERT_EQ(testSnapIn.getDisplayName(), snapInName);
    ASSERT_EQ(testSnapIn.getType(), snapInType);
    ASSERT_EQ(testSnapIn.getHelpText(), snapInDescription);
    ASSERT_EQ(testSnapIn.getVersion(), snapInVersion);
    ASSERT_EQ(testSnapIn.getLicense(), snapInLicesnce);
    ASSERT_EQ(testSnapIn.getCopyright(), snapInCopyright);
    ASSERT_EQ(testSnapIn.getState(), NONE);
}

class TestSettersSnapIn : public AbstractSnapIn
{
public:
    TestSettersSnapIn()
        : AbstractSnapIn(snapInType, snapInName)
    {
        setId(snapInId);
        setHelpText(snapInDescription);
        setVersion(snapInVersion);
        setLicense(snapInLicesnce);
        setCopyright(snapInCopyright);
        setRootNode(snapInId);
        setState(LOADED);
    }

    void onInitialize(){};

    void onShutdown(){};
};

TEST_F(SnapInTest, SnapInSettersTest)
{
    TestSettersSnapIn testSnapIn;

    ASSERT_EQ(testSnapIn.getId(), snapInId);
    ASSERT_EQ(testSnapIn.getDisplayName(), snapInName);
    ASSERT_EQ(testSnapIn.getType(), snapInType);
    ASSERT_EQ(testSnapIn.getHelpText(), snapInDescription);
    ASSERT_EQ(testSnapIn.getLicense(), snapInLicesnce);
    ASSERT_EQ(testSnapIn.getCopyright(), snapInCopyright);
    ASSERT_EQ(testSnapIn.getVersion(), snapInVersion);
    ASSERT_EQ(testSnapIn.getRootNode(), snapInId);
    ASSERT_EQ(testSnapIn.getState(), LOADED);
}

} // namespace test
