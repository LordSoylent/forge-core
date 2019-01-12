#include <chrono>
#include <fmt/core.h>
#include <fmt/format.h>
#include <jsonrpccpp/server.h>
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <lookup/LookupManager.hpp>
#include <rpc/LookupOnlyServer.hpp>
#include <thread>
#include <utilxx/Algorithm.hpp>
#include <utilxx/Overload.hpp>

using buddy::rpc::LookupOnlyServer;
using buddy::core::Entry;
using buddy::core::EntryKey;
using buddy::core::EntryValue;
using buddy::core::IPv4Value;
using buddy::core::IPv6Value;
using buddy::core::ByteArray;
using buddy::core::NoneValue;
using jsonrpc::PARAMS_BY_NAME;
using jsonrpc::Procedure;
using jsonrpc::JsonRpcException;


LookupOnlyServer::LookupOnlyServer(jsonrpc::AbstractServerConnector& connector,
                                   jsonrpc::serverVersion_t type,
                                   std::unique_ptr<daemon::ReadOnlyDaemonBase>&& daemon)
    : AbstractLookupOnlyStubSever(connector, type),
      lookup_(std::move(daemon))
{
    updatelookup();
}


auto LookupOnlyServer::shutdown()
    -> void
{
    should_shutdown_.store(true);
}

auto LookupOnlyServer::updatelookup()
    -> bool
{
    if(indexing_.load()) {
        throw JsonRpcException{"Server is already indexing"};
    }

    indexing_.store(true);

    auto res = lookup_.updateLookup();

    indexing_.store(false);

    if(!res) {
        auto error_msg = lookup::generateMessage(std::move(res.getError()));
        throw JsonRpcException{std::move(error_msg)};
    }

    return res.getValue();
}

auto LookupOnlyServer::rebuildlookup()
    -> void
{
    if(indexing_.load()) {
        throw JsonRpcException{"Server is already indexing"};
    }

    indexing_.store(true);
    auto res = lookup_.rebuildLookup();
    indexing_.store(false);

    if(!res) {
        auto error_msg = lookup::generateMessage(std::move(res.getError()));
        throw JsonRpcException{std::move(error_msg)};
    }
}

namespace {

auto entryValueToJson(EntryValue value)
    -> Json::Value
{
    static const auto visitor =
        utilxx::overload{
            [](IPv4Value&& value) {
                Json::Value json;
                json["type"] = "ipv4";

                std::vector<std::byte> helper(std::begin(value),
                                              std::end(value));

                json["value"] = buddy::core::toHexString(helper);

                return json;
            },
            [](IPv6Value&& value) {
                Json::Value json;
                json["type"] = "ipv6";

                std::vector<std::byte> helper(std::begin(value),
                                              std::end(value));

                json["value"] = buddy::core::toHexString(helper);

                return json;
            },
            [](ByteArray&& value) {
                Json::Value json;
                json["type"] = "bytearray";
                json["value"] = buddy::core::toHexString(value);

                return json;
            },
            [](NoneValue&& value) {
                Json::Value json;
                json["type"] = "none";
                json["value"] = nullptr;

                return json;
            }};

    return std::visit(visitor,
                      std::move(value));
}

auto entryToJson(Entry value)
    -> Json::Value
{
    Json::Value ret_json;
    ret_json["key"] = buddy::core::toHexString(value.first);

    auto trash_json = entryValueToJson(value.second);

    ret_json["type"] = std::move(trash_json["type"]);
    ret_json["value"] = std::move(trash_json["value"]);

    return ret_json;
}

} // namespace

auto LookupOnlyServer::lookupvalue(bool isstring, const std::string& key)
    -> Json::Value
{
    if(indexing_.load()) {
        throw JsonRpcException{"Server is indexing"};
    }

    EntryKey key_vec;

    if(isstring) {
        std::transform(std::cbegin(key),
                       std::cend(key),
                       std::back_inserter(key_vec),
                       [](auto c) {
                           return static_cast<std::byte>(c);
                       });
    } else {
        auto vec_opt = core::stringToByteVec(key);
        if(!vec_opt) {
            throw JsonRpcException{"could not convert given bytestring into vector of byte"};
        }

        key_vec = std::move(vec_opt.getValue());
    }

    auto res = lookup_.lookupValue(key_vec);

    if(!res) {
        auto error_msg = fmt::format("no entrys with key {} found",
                                     key);
        throw JsonRpcException{std::move(error_msg)};
    }

    return entryValueToJson(res.getValue().get());
}

auto LookupOnlyServer::lookupowner(bool isstring, const std::string& key)
    -> std::string
{
    if(indexing_.load()) {
        throw JsonRpcException{"Server is indexing"};
    }

    EntryKey key_vec;

    if(isstring) {
        std::transform(std::cbegin(key),
                       std::cend(key),
                       std::back_inserter(key_vec),
                       [](auto c) {
                           return static_cast<std::byte>(c);
                       });
    } else {
        auto vec_opt = core::stringToByteVec(key);
        if(!vec_opt) {
            throw JsonRpcException{"could not convert given bytestring into vector of byte"};
        }

        key_vec = std::move(vec_opt.getValue());
    }

    auto res = lookup_.lookupOwner(key_vec);

    if(!res) {
        auto error_msg = fmt::format("no entrys with key {} found",
                                     key);
        throw JsonRpcException{std::move(error_msg)};
    }

    return res.getValue();
}

auto LookupOnlyServer::lookupactivationblock(bool isstring, const std::string& key)
    -> int
{
    if(indexing_.load()) {
        throw JsonRpcException{"Server is indexing"};
    }

    EntryKey key_vec;

    if(isstring) {
        std::transform(std::cbegin(key),
                       std::cend(key),
                       std::back_inserter(key_vec),
                       [](auto c) {
                           return static_cast<std::byte>(c);
                       });
    } else {
        auto vec_opt = core::stringToByteVec(key);
        if(!vec_opt) {
            throw JsonRpcException{"could not convert given bytestring into vector of byte"};
        }

        key_vec = std::move(vec_opt.getValue());
    }

    auto res = lookup_.lookupActivationBlock(key_vec);

    if(!res) {
        auto error_msg = fmt::format("no entrys with key {} found",
                                     key);
        throw JsonRpcException{std::move(error_msg)};
    }

    return res.getValue();
}

auto LookupOnlyServer::checkvalidity()
    -> bool
{
    if(indexing_.load()) {
        throw JsonRpcException{"Server is indexing"};
    }

    auto res = lookup_.lookupIsValid();

    if(!res) {
        auto error_msg = lookup::generateMessage(std::move(res.getError()));
        throw JsonRpcException{std::move(error_msg)};
    }

    return res.getValue();
}

auto LookupOnlyServer::lookupallentrysof(const std::string& owner)
    -> Json::Value
{
    if(indexing_.load()) {
        throw JsonRpcException{"Server is indexing"};
    }

    auto entrys = lookup_.getEntrysOfOwner(owner);

    auto json_entrys =
        utilxx::transform_into_vector(std::make_move_iterator(std::begin(entrys)),
                                      std::make_move_iterator(std::end(entrys)),
                                      [](auto&& entry) {
                                          return entryToJson(std::move(entry));
                                      });

    Json::Value ret_json;
    for(int i{0}; i < json_entrys.size() - 1; i++) {
        ret_json[i] = json_entrys[i];
    }

    return ret_json;
}


auto LookupOnlyServer::hasShutdownRequest() const
    -> bool
{
    return should_shutdown_.load();
}



auto buddy::rpc::waitForShutdown(const LookupOnlyServer& server)
    -> void
{
    using namespace std::literals::chrono_literals;

    while(!server.hasShutdownRequest()) {
        std::this_thread::sleep_for(1s);
    }
}
