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

#ifndef _TOPOLOGY_ADAPTEREVENTLISTENER_H
#define _TOPOLOGY_ADAPTEREVENTLISTENER_H

#include <map>
#include "SubNet.h"
#include "Hub.h"

namespace PLCTool {
  class Adapter;

  class AdapterEventListener {
    Adapter *adapter;

  public:
    virtual ~AdapterEventListener();

    void setAdapter(Adapter *);
    virtual void onNodeUp(Node *) = 0;
    virtual void onNodeUpdated(Node *) = 0;
    virtual void onNodeDown(Node *) = 0;
    virtual void onHubAnnounce(Hub *) = 0;
    virtual void onLinkFrame(std::vector<uint8_t> const &) = 0;
    virtual void onNodeFrame(Node *, Node *, std::vector<uint8_t> const &) = 0;
  };
}

#endif // _TOPOLOGY_ADAPTEREVENTLISTENER_H
