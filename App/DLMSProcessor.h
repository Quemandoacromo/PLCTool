//
// Copyright (c) 2020, Tarlogic Security SL
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 3. Neither the name of copyright holders nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS”
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#ifndef DLMSPROCESSOR_H
#define DLMSPROCESSOR_H

#include <QObject>
#include <PRIME/PrimeAdapter.h>
#include <GXDLMSTranslator.h>
#include <QVector>

struct DlmsMessage {
  QDateTime timeStamp;
  QString SNA;
  PLCTool::NodeId nodeId;
  QString type;
  bool downlink;
  QVector<uint8_t> pdu;
  QString xml;

  void setDlmsData(const uint8_t *data, size_t size);
  QString toText(void) const;
};


class DLMSProcessor : public QObject
{
  Q_OBJECT

  CGXDLMSTranslator translator;

public:
  explicit DLMSProcessor(QObject *parent = 0);

  static void registerTypes(void);

signals:
  void dlmsMessage(DlmsMessage);

public slots:
  void process(
      QString SNA,
      QDateTime timeStamp,
      quint64 id,
      bool downlink,
      QVector<uint8_t> data);
};

#endif // DLMSPROCESSOR_H
