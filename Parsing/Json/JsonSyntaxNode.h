//
// Created by LE, Duc Anh on 8/13/15.
//

#ifndef CLDEPARSER_PARSING_JSON_JSONSYNTAXNODE_H
#define CLDEPARSER_PARSING_JSON_JSONSYNTAXNODE_H

#include <vector>
#include "../../SyntaxNode.h"

namespace CldeParser {
    namespace Parsing {
        namespace Json {

            class JsonSyntaxNode : public SyntaxNode {

            public:
                JsonSyntaxNode(int id, std::string const &value);
                JsonSyntaxNode(const JsonSyntaxNode &) = default;
                JsonSyntaxNode(JsonSyntaxNode &&) = default;
                JsonSyntaxNode &operator=(const JsonSyntaxNode &) = default;
                JsonSyntaxNode &operator=(JsonSyntaxNode &&) = default;
                virtual ~JsonSyntaxNode() = default;

                // IPrintable

                virtual std::string CopyToString() const override;
            };

            using SPtrJsonSyntaxNode = std::shared_ptr<JsonSyntaxNode>;
            using SPtrJsonSyntaxNodeVector = std::vector<SPtrJsonSyntaxNode>;
        }
    }
}


#endif //CLDEPARSER_PARSING_JSON_JSONSYNTAXNODE_H
