/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_FORGE_RPC_LOOKUPONLYSTUBCLIENT_H_
#define JSONRPC_CPP_STUB_FORGE_RPC_LOOKUPONLYSTUBCLIENT_H_

#include <jsonrpccpp/client.h>

namespace forge {
    namespace rpc {
        class LookupOnlyStubClient : public jsonrpc::Client
        {
            public:
                LookupOnlyStubClient(jsonrpc::IClientConnector &conn, jsonrpc::clientVersion_t type = jsonrpc::JSONRPC_CLIENT_V2) : jsonrpc::Client(conn, type) {}

                bool updatelookup() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("updatelookup",p);
                    if (result.isBool())
                        return result.asBool();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                void shutdown() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    this->CallNotification("shutdown",p);
                }
                void rebuildlookup() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    this->CallNotification("rebuildlookup",p);
                }
                Json::Value lookupumvalue(bool isstring, const std::string& key) 
                {
                    Json::Value p;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    Json::Value result = this->CallMethod("lookupumvalue",p);
                    if (result.isObject())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                std::string lookupowner(bool isstring, const std::string& key) 
                {
                    Json::Value p;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    Json::Value result = this->CallMethod("lookupowner",p);
                    if (result.isString())
                        return result.asString();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                int lookupactivationblock(bool isstring, const std::string& key) 
                {
                    Json::Value p;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    Json::Value result = this->CallMethod("lookupactivationblock",p);
                    if (result.isIntegral())
                        return result.asInt();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                bool checkvalidity() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("checkvalidity",p);
                    if (result.isBool())
                        return result.asBool();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                int getlastvalidblockheight() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getlastvalidblockheight",p);
                    if (result.isIntegral())
                        return result.asInt();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                Json::Value lookupallentrysof(const std::string& owner) 
                {
                    Json::Value p;
                    p["owner"] = owner;
                    Json::Value result = this->CallMethod("lookupallentrysof",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
        };

    }
}
#endif //JSONRPC_CPP_STUB_FORGE_RPC_LOOKUPONLYSTUBCLIENT_H_
