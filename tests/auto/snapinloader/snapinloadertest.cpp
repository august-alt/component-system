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

#include "snapinloadertest.h"

#include "snapindetailswidget.h"

#include "isnapin.h"

#include <QLineEdit>
#include <QPlainTextEdit>
#include <QTest>

using namespace ::testing;
using namespace ::gpui;

namespace test
{
SnapInLoaderTest::SnapInLoaderTest()
    : snapInLoader(&manager)
{}

TEST_F(SnapInLoaderTest, WidgetContainsValidSnapInAfterConstruction)
{
    EXPECT_NO_FATAL_FAILURE(snapInLoader.loadSnapIns(QDir("./")));

    EXPECT_EQ(manager.getSnapIns().size(), 3);

    EXPECT_EQ(manager.getSnapIns().front()->getDisplayName(), "BarSnapIn");

    EXPECT_EQ(manager.getSnapIns().back()->getDisplayName(), "FooSnapIn");
}

TEST_F(SnapInLoaderTest, SnapInStateAfterLoadAndCheckDepencies)
{
    EXPECT_NO_FATAL_FAILURE(snapInLoader.loadSnapIns(QDir("./")));

    auto snapIns = manager.getSnapIns();

    EXPECT_EQ(snapIns[0]->getState(), LOADED);
    EXPECT_EQ(snapIns[1]->getState(), NO_DEPENDENCIES);
    EXPECT_EQ(snapIns[2]->getState(), LOADED);
}

} // namespace test
