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

#include "snapinloader.h"

#include "plugin.h"
#include "pluginstorage.h"

#include "abstractsnapin.h"
#include "isnapin.h"
#include "isnapinmanager.h"

#include <QMap>

namespace gpui
{
class SnapInLoaderPrivate
{
public:
    ISnapInManager *manager{nullptr};

    SnapInLoaderPrivate(ISnapInManager *manager)
        : manager(manager)
    {}
};

SnapInLoader::SnapInLoader(ISnapInManager *manager)
    : d(new SnapInLoaderPrivate(manager))
{}

SnapInLoader::~SnapInLoader()
{
    delete d;
}

void SnapInLoader::loadSnapIns(const QDir &snapInDirectory)
{
    const QFileInfoList files = snapInDirectory.entryInfoList();
    QString pluginName;

    for (const QFileInfo &file : files)
    {
        if (PluginStorage::instance()->loadPlugin(file, pluginName))
        {
            auto snapIn = PluginStorage::instance()->createPluginClass<ISnapIn>(pluginName);

            if (snapIn)
            {
                d->manager->addSnapIn(snapIn);

                snapIn->setState(LOADED);
            }
        }
    }

    checkSnapInsDependencies();
}

void SnapInLoader::checkSnapInsDependencies()
{
    auto snapIns = d->manager->getSnapIns();

    for (auto snapIn : snapIns)
    {
        ICompositeSnapIn *compositeSnapIn = dynamic_cast<ICompositeSnapIn *>(snapIn);
        if (compositeSnapIn)
        {
            if (!checkDependecies(compositeSnapIn))
            {
                compositeSnapIn->setState(NO_DEPENDENCIES);
            }
        }
    }
}

bool SnapInLoader::checkDependecies(ICompositeSnapIn *snapIn)
{
    auto dependencies = snapIn->getDependencies();

    bool depFlag = false;

    for (auto dependency : dependencies.toStdMap())
    {
        for (auto snapin : d->manager->getSnapIns())
        {
            if (QString::compare(dependency.first, snapin->getDisplayName()) == 0)
            {
                depFlag = (dependency.second == snapin->getVersion());
            }
        }
        if (!depFlag)
        {
            return depFlag;
        }
    }
    return depFlag;
}

} // namespace gpui
