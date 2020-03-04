/***************************************************************************
 *   Copyright (C) 2006-2019 by Ilya Kotov                                 *
 *   forkotov02@ya.ru                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#ifndef DECODER_ADPLUG_H
#define DECODER_ADPLUG_H

#include "adplugwrap.h"
#include <qmmp/decoder.h>

class DecoderAdplug : public Decoder
{
public:
    explicit DecoderAdplug(const QString &path);

    virtual bool initialize() override;
    virtual qint64 totalTime() const override;
    virtual int bitrate() const override;
    virtual qint64 read(unsigned char *, qint64) override;
    virtual void seek(qint64) override;

private:
    qint64 copy(unsigned char *, qint64);

    QString m_path;
    std::unique_ptr<AdplugWrap> m_adplug;
    unsigned char *m_bufptr = nullptr;
    qint64 m_buf_filled = 0;
    unsigned long m_time = 0;
    unsigned long m_length = 0;
    double m_divisor = 0.0;
};

#endif
