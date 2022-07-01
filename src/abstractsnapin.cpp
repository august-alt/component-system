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

#include "abstractsnapin.h"

namespace gpui
{

class AbstractSnapInPrivate
{
public:
    QUuid id {};
    QUuid rootNode {};
    QString type {};
    QString helpText {};
    QVersionNumber version {};
    QString license {};
    QString copyright {};
};

QUuid AbstractSnapIn::getId()
{
    return d->id;
}

QUuid AbstractSnapIn::getRootNode()
{
    return d->rootNode;
}

QString AbstractSnapIn::getDisplayName()
{
    return Plugin::getName();
}

QString AbstractSnapIn::getType()
{
    return d->type;
}

QString AbstractSnapIn::getHelpText()
{
    return d->helpText;
}

QVersionNumber AbstractSnapIn::getVersion()
{
    return d->version;
}

QString AbstractSnapIn::getLicense()
{
    return d->license;
}

QString AbstractSnapIn::getCopyright()
{
    return d->copyright;
}

AbstractSnapIn::AbstractSnapIn(QString type, QString name,
                               QString helpText, QVersionNumber version, QString license, QString copyright)
    : Plugin(name)
    , d(new AbstractSnapInPrivate())
{
    d->type = type;
    d->helpText = helpText;
    d->version = version;
    d->license = license;
    d->copyright = copyright;
}

AbstractSnapIn::~AbstractSnapIn()
{
    delete d;
}

}
