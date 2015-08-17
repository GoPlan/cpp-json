//
// Created by LE, Duc Anh on 8/9/15.
//

#include "JsonFactory.h"
#include "JsonObject.h"
#include "JsonArray.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {
            SPtrJsonEntity JsonFactory::CreateSPtrJsonObject() {
                return std::make_shared<JsonObject>();
            }
            SPtrJsonEntity JsonFactory::CreateSPtrJsonArray() {
                return std::make_shared<JsonArray>();
            }
            SPtrJsonSyntaxNode JsonFactory::CreateSPtrJsonSyntaxNode(int id, std::string const &value) {
                return std::make_shared<JsonSyntaxNode>(id, value);
            }
        }
    }
}


