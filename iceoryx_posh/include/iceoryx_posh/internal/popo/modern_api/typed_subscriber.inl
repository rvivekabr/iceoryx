// Copyright (c) 2020 by Robert Bosch GmbH. All rights reserved.
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

#ifndef IOX_POSH_POPO_TYPED_SUBSCRIBER_INL
#define IOX_POSH_POPO_TYPED_SUBSCRIBER_INL

namespace iox
{
namespace popo
{
template <typename T, typename base_subscriber_t>
TypedSubscriber<T, base_subscriber_t>::TypedSubscriber(const capro::ServiceDescription& service)
    : base_subscriber_t(service)
{
}

template <typename T, typename base_subscriber_t>
inline uid_t TypedSubscriber<T, base_subscriber_t>::getUid() const noexcept
{
    return base_subscriber_t::getUid();
}

template <typename T, typename base_subscriber_t>
inline capro::ServiceDescription TypedSubscriber<T, base_subscriber_t>::getServiceDescription() const noexcept
{
    return base_subscriber_t::getServiceDescription();
}

template <typename T, typename base_subscriber_t>
inline void TypedSubscriber<T, base_subscriber_t>::subscribe(const uint64_t queueCapacity) noexcept
{
    base_subscriber_t::subscribe(queueCapacity);
}

template <typename T, typename base_subscriber_t>
inline SubscribeState TypedSubscriber<T, base_subscriber_t>::getSubscriptionState() const noexcept
{
    return base_subscriber_t::getSubscriptionState();
}

template <typename T, typename base_subscriber_t>
inline void TypedSubscriber<T, base_subscriber_t>::unsubscribe() noexcept
{
    return base_subscriber_t::unsubscribe();
}

template <typename T, typename base_subscriber_t>
inline bool TypedSubscriber<T, base_subscriber_t>::hasNewSamples() const noexcept
{
    return base_subscriber_t::hasNewSamples();
}

template <typename T, typename base_subscriber_t>
inline cxx::expected<cxx::optional<Sample<const T>>, ChunkReceiveError>
TypedSubscriber<T, base_subscriber_t>::receive() noexcept
{
    return base_subscriber_t::receive();
}

template <typename T, typename base_subscriber_t>
inline void TypedSubscriber<T, base_subscriber_t>::releaseQueuedSamples() noexcept
{
    base_subscriber_t::releaseQueuedSamples();
}

} // namespace popo
} // namespace iox

#endif // IOX_POSH_POPO_TYPED_SUBSCRIBER_INL
