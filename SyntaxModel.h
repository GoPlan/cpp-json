//
// Created by LE, Duc Anh on 8/10/15.
//

#ifndef CLDEPARSER_SYNTAXTREE_H
#define CLDEPARSER_SYNTAXTREE_H

#include <memory>
#include "SyntaxNode.h"

namespace CldeParser {

    class SyntaxModel : public Core::IPrintable {

    public:
        SyntaxModel() = default;
        SyntaxModel(const SyntaxModel &) = default;
        SyntaxModel(SyntaxModel &&) = default;
        SyntaxModel &operator=(const SyntaxModel &) = default;
        SyntaxModel &operator=(SyntaxModel &&) = default;
        virtual ~SyntaxModel() = default;

        // Locals
        virtual void Reset() = 0;
        virtual SPtrSyntaxNode const &RootNode() = 0;
    };

    using SPtrSyntaxModel = std::shared_ptr<SyntaxModel>;
    using SPtrSyntaxModelVector = std::vector<SPtrSyntaxModel>;
}


#endif //CLDEPARSER_SYNTAXTREE_H
