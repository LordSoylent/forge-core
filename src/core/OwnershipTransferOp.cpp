#include <core/Entry.hpp>
#include <core/OwnershipTransferOp.hpp>

using buddy::core::Entry;
using buddy::core::OwnershipTransferOp;

OwnershipTransferOp::OwnershipTransferOp(Entry&& entry,
                                         std::string&& old_owner,
                                         std::string&& new_owner,
                                         std::int64_t block,
                                         std::int64_t value)
    : entry_(std::move(entry)),
      old_owner_(std::move(old_owner)),
      new_owner_(std::move(new_owner)),
      block_(block),
      value_(value) {}


auto OwnershipTransferOp::getEntryKey() const
    -> const EntryKey&
{
    return entry_.first;
}

auto OwnershipTransferOp::getEntryKey()
    -> EntryKey&
{
    return entry_.first;
}

auto OwnershipTransferOp::getEntryValue() const
    -> const EntryValue&
{
    return entry_.second;
}

auto OwnershipTransferOp::getEntryValue()
    -> EntryValue&
{
    return entry_.second;
}

auto OwnershipTransferOp::getEntry() const
    -> const Entry&
{
    return entry_;
}
auto OwnershipTransferOp::getEntry()
    -> Entry&
{
    return entry_;
}

auto OwnershipTransferOp::getNewOwner() const
    -> const std::string&
{
    return new_owner_;
}

auto OwnershipTransferOp::getNewOwner()
    -> std::string&
{
    return new_owner_;
}

auto OwnershipTransferOp::getOwner() const
    -> const std::string&
{
    return old_owner_;
}

auto OwnershipTransferOp::getOwner()
    -> std::string&
{
    return old_owner_;
}

auto OwnershipTransferOp::getBlock() const
    -> std::int64_t
{
    return block_;
}

auto OwnershipTransferOp::getValue() const
    -> std::int64_t
{
    return value_;
}
