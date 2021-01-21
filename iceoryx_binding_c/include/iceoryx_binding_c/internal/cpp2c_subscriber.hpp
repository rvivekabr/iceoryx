// Copyright (c) 2020 by Robert Bosch GmbH, Apex.AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef IOX_BINDING_C_CPP2C_SUBSCRIBER_HPP
#define IOX_BINDING_C_CPP2C_SUBSCRIBER_HPP

#include "iceoryx_binding_c/enums.h"
#include "iceoryx_posh/internal/popo/ports/subscriber_port_user.hpp"
#include "iceoryx_posh/popo/wait_set.hpp"

struct cpp2c_Subscriber
{
    cpp2c_Subscriber() = default;
    cpp2c_Subscriber(const cpp2c_Subscriber&) = delete;
    cpp2c_Subscriber(cpp2c_Subscriber&& rhs) = delete;
    ~cpp2c_Subscriber();

    cpp2c_Subscriber& operator=(const cpp2c_Subscriber&) = delete;
    cpp2c_Subscriber& operator=(cpp2c_Subscriber&& rhs) = delete;

    void enableEvent(const iox::popo::WaitSetAccessor,
                     iox::popo::TriggerHandle&& triggerHandle,
                     const iox_SubscriberEvent subscriberEvent) noexcept;

    void disableEvent(const iox::popo::WaitSetAccessor, const iox_SubscriberEvent event) noexcept;

    void invalidateTrigger(const uint64_t uniqueTriggerId) noexcept;

    bool hasSamples() const noexcept;

    iox::popo::WaitSetHasTriggeredCallback
    getHasTriggeredCallbackForEvent(const iox::popo::WaitSetAccessor,
                                    const iox_SubscriberEvent subscriberEvent) const noexcept;


    iox::popo::SubscriberPortData* m_portData{nullptr};
    iox::popo::TriggerHandle m_trigger;
};
#endif
