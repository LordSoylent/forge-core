/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_FORGE_RPC_READWRITEWALLETSTUBCLIENT_H_
#define JSONRPC_CPP_STUB_FORGE_RPC_READWRITEWALLETSTUBCLIENT_H_

#include <jsonrpccpp/client.h>

namespace forge {
    namespace rpc {
        class ReadWriteWalletStubClient : public jsonrpc::Client
        {
            public:
                ReadWriteWalletStubClient(jsonrpc::IClientConnector &conn, jsonrpc::clientVersion_t type = jsonrpc::JSONRPC_CLIENT_V2) : jsonrpc::Client(conn, type) {}

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
                Json::Value lookupuniquevalue(bool isstring, const std::string& key) 
                {
                    Json::Value p;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    Json::Value result = this->CallMethod("lookupuniquevalue",p);
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
                void addwatchonlyaddress(const std::string& address) 
                {
                    Json::Value p;
                    p["address"] = address;
                    this->CallNotification("addwatchonlyaddress",p);
                }
                void deletewatchonlyaddress(const std::string& address) 
                {
                    Json::Value p;
                    p["address"] = address;
                    this->CallNotification("deletewatchonlyaddress",p);
                }
                void addnewownedaddress(const std::string& address) 
                {
                    Json::Value p;
                    p["address"] = address;
                    this->CallNotification("addnewownedaddress",p);
                }
                Json::Value getownedumentrys() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getownedumentrys",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                Json::Value getwatchonlyumentrys() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getwatchonlyumentrys",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                Json::Value getallwatchedumentrys() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getallwatchedumentrys",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                Json::Value getowneduniqueentrys() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getowneduniqueentrys",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                Json::Value getwatchonlyuniqueentrys() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getwatchonlyuniqueentrys",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                Json::Value getallwatcheduniqueentrys() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getallwatcheduniqueentrys",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                Json::Value getwatchedaddresses() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getwatchedaddresses",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                Json::Value getownedaddresses() 
                {
                    Json::Value p;
                    p = Json::nullValue;
                    Json::Value result = this->CallMethod("getownedaddresses",p);
                    if (result.isArray())
                        return result;
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                bool ownesaddress(const std::string& address) 
                {
                    Json::Value p;
                    p["address"] = address;
                    Json::Value result = this->CallMethod("ownesaddress",p);
                    if (result.isBool())
                        return result.asBool();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                std::string createnewumentry(const std::string& address, int burnvalue, bool isstring, const std::string& key, const Json::Value& value) 
                {
                    Json::Value p;
                    p["address"] = address;
                    p["burnvalue"] = burnvalue;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    p["value"] = value;
                    Json::Value result = this->CallMethod("createnewumentry",p);
                    if (result.isString())
                        return result.asString();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                std::string createnewuniqueentry(const std::string& address, int burnvalue, bool isstring, const std::string& key, const Json::Value& value) 
                {
                    Json::Value p;
                    p["address"] = address;
                    p["burnvalue"] = burnvalue;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    p["value"] = value;
                    Json::Value result = this->CallMethod("createnewuniqueentry",p);
                    if (result.isString())
                        return result.asString();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                std::string updateumentry(int burnvalue, bool isstring, const std::string& key, const Json::Value& value) 
                {
                    Json::Value p;
                    p["burnvalue"] = burnvalue;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    p["value"] = value;
                    Json::Value result = this->CallMethod("updateumentry",p);
                    if (result.isString())
                        return result.asString();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                std::string renewentry(int burnvalue, bool isstring, const std::string& key) 
                {
                    Json::Value p;
                    p["burnvalue"] = burnvalue;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    Json::Value result = this->CallMethod("renewentry",p);
                    if (result.isString())
                        return result.asString();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                std::string deleteentry(int burnvalue, bool isstring, const std::string& key) 
                {
                    Json::Value p;
                    p["burnvalue"] = burnvalue;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    Json::Value result = this->CallMethod("deleteentry",p);
                    if (result.isString())
                        return result.asString();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                std::string transferownership(int burnvalue, bool isstring, const std::string& key, const std::string& newowner) 
                {
                    Json::Value p;
                    p["burnvalue"] = burnvalue;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    p["newowner"] = newowner;
                    Json::Value result = this->CallMethod("transferownership",p);
                    if (result.isString())
                        return result.asString();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
                std::string paytoentryowner(int amount, bool isstring, const std::string& key) 
                {
                    Json::Value p;
                    p["amount"] = amount;
                    p["isstring"] = isstring;
                    p["key"] = key;
                    Json::Value result = this->CallMethod("paytoentryowner",p);
                    if (result.isString())
                        return result.asString();
                    else
                        throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
                }
        };

    }
}
#endif //JSONRPC_CPP_STUB_FORGE_RPC_READWRITEWALLETSTUBCLIENT_H_
