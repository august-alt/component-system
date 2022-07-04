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

#include "abstractcompositesnapin.h"

#include <QMap>
#include <QString>
#include <QVersionNumber>

namespace gpui
{

class AbstractCompositeSnapInPrivate
{
public:
    QMap<QString, QVersionNumber> dependencies;
};

QMap<QString, QVersionNumber> AbstractCompositeSnapIn::getDependencies()
{
    return d->dependencies;
}

AbstractCompositeSnapIn::AbstractCompositeSnapIn(QString type, QString name, QString helpText,
                                                 QVersionNumber version, QString license, QString copyright)
    : AbstractSnapIn(type, name, helpText, version, license, copyright)
    , d(new AbstractCompositeSnapInPrivate())
{
}

AbstractCompositeSnapIn::~AbstractCompositeSnapIn()
{
    delete d;
}

void AbstractCompositeSnapIn::addDependency(const QString &name, const QVersionNumber &version)
{
    d->dependencies.insert(name, version);
}

void AbstractCompositeSnapIn::removeDependency(const QString &name)
{
    d->dependencies.remove(name);
}


}

