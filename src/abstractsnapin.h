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

#ifndef _ABSTRACTSNAPIN_H
#define _ABSTRACTSNAPIN_H

#include "plugin.h"
#include "isnapin.h"

#include <QUuid>
#include <QVersionNumber>

namespace gpui
{
class AbstractSnapInPrivate;

/**
 * @brief Adapts interface of a ISnapIn for a plugin.
 */
class AbstractSnapIn : protected Plugin, public ISnapIn
{
public:
    QUuid getId() override;

    QString getType() override;

    QUuid getRootNode() override;

    QString getDisplayName() override;

    QString getHelpText() override;

    QVersionNumber getVersion() override;

    QString getLicense() override;

    QString getCopyright() override;

protected:
    AbstractSnapIn(QString type, QString name,
                   QString helpText = {}, QVersionNumber version = {}, QString license = {}, QString copyright = {});
    ~AbstractSnapIn();

protected:
    void setId(QUuid id);

    void setRootNode(QUuid rootNode);

    void setHelpText(QString text);

    void setVersion(QString version);

    void setLicense(QString license);

    void setCopyright(QString copyright);

private:
    AbstractSnapIn(const AbstractSnapIn&)            = delete;   // copy ctor
    AbstractSnapIn(AbstractSnapIn&&)                 = delete;   // move ctor
    AbstractSnapIn& operator=(const AbstractSnapIn&) = delete;   // copy assignment
    AbstractSnapIn& operator=(AbstractSnapIn&&)      = delete;   // move assignment

private:
    AbstractSnapInPrivate* d;
};

}

#endif  //_ABSTRACTSNAPIN_H