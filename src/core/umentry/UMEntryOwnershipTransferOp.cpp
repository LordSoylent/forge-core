#include <core/umentry/UMEntry.hpp>
#include <core/FlagIndexes.hpp>
#include <core/umentry/UMEntryOperation.hpp>
#include <core/umentry/UMEntryOwnershipTransferOp.hpp>

using forge::core::UMEntry;
using forge::core::UMEntryOwnershipTransferOp;
using forge::core::UMENTRY_OWNERSHIP_TRANSFER_FLAG;
using forge::core::FORGE_IDENTIFIER_MASK;

UMEntryOwnershipTransferOp::UMEntryOwnershipTransferOp(UMEntry&& entry,
                                         std::string&& old_owner,
                                         std::string&& new_owner,
                                         std::int64_t block,
                                         std::int64_t value)
    : entry_(std::move(entry)),
      old_owner_(std::move(old_owner)),
      new_owner_(std::move(new_owner)),
      block_(block),
      value_(value) {}


auto UMEntryOwnershipTransferOp::getUMEntryKey() const
    -> const UMEntryKey&
{
    return entry_.first;
}

auto UMEntryOwnershipTransferOp::getUMEntryKey()
    -> UMEntryKey&
{
    return entry_.first;
}

auto UMEntryOwnershipTransferOp::getUMEntryValue() const
    -> const UMEntryValue&
{
    return entry_.second;
}

auto UMEntryOwnershipTransferOp::getUMEntryValue()
    -> UMEntryValue&
{
    return entry_.second;
}

auto UMEntryOwnershipTransferOp::getUMEntry() const
    -> const UMEntry&
{
    return entry_;
}
auto UMEntryOwnershipTransferOp::getUMEntry()
    -> UMEntry&
{
    return entry_;
}

auto UMEntryOwnershipTransferOp::getNewOwner() const
    -> const std::string&
{
    return new_owner_;
}

auto UMEntryOwnershipTransferOp::getNewOwner()
    -> std::string&
{
    return new_owner_;
}

auto UMEntryOwnershipTransferOp::getOwner() const
    -> const std::string&
{
    return old_owner_;
}

auto UMEntryOwnershipTransferOp::getOwner()
    -> std::string&
{
    return old_owner_;
}

auto UMEntryOwnershipTransferOp::getBlock() const
    -> std::int64_t
{
    return block_;
}

auto UMEntryOwnershipTransferOp::getValue() const
    -> std::int64_t
{
    return value_;
}

auto forge::core::createUMEntryOwnershipTransferOpMetadata(UMEntry&& entry)
    -> std::vector<std::byte>
{
    auto data = forge::core::entryToRawData(entry);
    auto flag = forge::core::UMENTRY_OWNERSHIP_TRANSFER_FLAG;

    data.insert(std::begin(data), flag);

    data.insert(std::begin(data), UMENTRY_IDENTIFICATION_FLAG);

    data.insert(std::begin(data),
                std::begin(FORGE_IDENTIFIER_MASK),
                std::end(FORGE_IDENTIFIER_MASK));

    return data;
}