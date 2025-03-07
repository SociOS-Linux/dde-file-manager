/*
 * Copyright (C) 2022 Uniontech Software Technology Co., Ltd.
 *
 * Author:     liuzhangjian<liuzhangjian@uniontech.com>
 *
 * Maintainer: liuzhangjian<liuzhangjian@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SEARCHSERVICE_P_H
#define SEARCHSERVICE_P_H

#include "searchservice.h"
#include "maincontroller/maincontroller.h"

class SearchServicePrivate : public QObject
{
    Q_OBJECT
    friend class SearchService;

public:
    explicit SearchServicePrivate(SearchService *parent);
    ~SearchServicePrivate();

private:
    MainController *mainController = nullptr;
};

#endif   // SEARCHSERVICE_P_H
