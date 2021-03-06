#pragma once

#include <entrys/umentry/UMEntry.hpp>

namespace forge::core {

class UMEntryUpdateOp
{
public:
    UMEntryUpdateOp(UMEntry&& entry,
                  std::string&& owner,
                  std::int64_t block,
                  std::int64_t value);

    auto getEntryKey() const
        -> const EntryKey&;
    auto getEntryKey()
        -> EntryKey&;

    auto getNewUMEntryValue() const
        -> const UMEntryValue&;

    auto getNewUMEntryValue()
        -> UMEntryValue&;

    auto getUMEntry() const
        -> const UMEntry&;
    auto getUMEntry()
        -> UMEntry&;

    auto getBlock() const
        -> std::int64_t;

    auto getValue() const
        -> std::int64_t;

    auto getOwner() const
        -> const std::string&;
    auto getOwner()
        -> std::string&;

private:
    UMEntry entry_;
    std::string owner_;
    std::int64_t block_;
    std::int64_t value_;
};

auto createUMEntryUpdateOpMetadata(EntryKey&& key,
                                 UMEntryValue new_value)
    -> std::vector<std::byte>;


} // namespace forge::core
