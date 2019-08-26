#pragma once

#include <array>
#include <cstddef>
#include <json/value.h>
#include <utilxx/Opt.hpp>
#include <variant>
#include <vector>

namespace forge::core {

//need to redefine here to avoid circular header
//dependency
using EntryKey = std::vector<std::byte>;

// clang-format off
using IPv4Value = std::array<std::byte, 4>;
using IPv6Value = std::array<std::byte, 16>;
using ByteArray = std::vector<std::byte>;
struct NoneValue{
    auto operator==(const NoneValue&) const
    {
        return true;
    }
};
// clang-format on

//flag which identifies a UMENTRY
constexpr static inline auto UMENTRY_IDENTIFICATION_FLAG = static_cast<std::byte>(0b00000001);

constexpr static inline auto IPv4_VALUE_FLAG = static_cast<std::byte>(0b00000001);
constexpr static inline auto IPv6_VALUE_FLAG = static_cast<std::byte>(0b00000010);
constexpr static inline auto NONE_VALUE_FLAG = static_cast<std::byte>(0b00000100);
constexpr static inline auto BYTE_ARRAY_VALUE_FLAG = static_cast<std::byte>(0b00001000);

using UMEntryValue = std::variant<IPv4Value,
                                  IPv6Value,
                                  ByteArray,
                                  NoneValue>;

using UMEntry = std::pair<EntryKey,
                          UMEntryValue>;

auto parseValue(const std::vector<std::byte>& data)
    -> utilxx::Opt<UMEntryValue>;

auto parseKey(const std::vector<std::byte>& data)
    -> utilxx::Opt<EntryKey>;

auto parseUMEntry(const std::vector<std::byte>& data)
    -> utilxx::Opt<UMEntry>;

auto extractValueFlag(const UMEntryValue& value)
    -> std::byte;

auto entryValueToRawData(const UMEntryValue& value)
    -> std::vector<std::byte>;

auto entryToRawData(const UMEntry& entry)
    -> std::vector<std::byte>;

auto jsonToUMEntryValue(Json::Value&& value)
    -> utilxx::Opt<UMEntryValue>;

auto umentryValueToJson(UMEntryValue value)
    -> Json::Value;

auto umentryToJson(UMEntry value)
    -> Json::Value;

} // namespace forge::core
