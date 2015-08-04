//
// Created by LE, Duc Anh on 8/4/15.
//

#include "TokenizerFactory.h"
#include "Tokenizers/BraceOpen.h"
#include "Tokenizers/BraceClose.h"
#include "Tokenizers/Colon.h"
#include "Tokenizers/Id.h"
#include "Tokenizers/String.h"
#include "Tokenizers/Number.h"
#include "Tokenizers/Space.h"
#include "Tokenizers/Tab.h"

namespace CldeParser {
    namespace Common {

        SPtrTokenizer TokenizerFactory::CreateBraceOpen() {
            return std::make_shared<Tokenizers::BraceOpen>();
        }
        SPtrTokenizer TokenizerFactory::CreateBraceClose() {
            return std::make_shared<Tokenizers::BraceClose>();
        }
        SPtrTokenizer TokenizerFactory::CreateColon() {
            return std::make_shared<Tokenizers::Colon>();
        }
        SPtrTokenizer TokenizerFactory::CreateId() {
            return std::make_shared<Tokenizers::Id>();
        }
        SPtrTokenizer TokenizerFactory::CreateNumber() {
            return std::make_shared<Tokenizers::Number>();
        }
        SPtrTokenizer TokenizerFactory::CreateString() {
            return std::make_shared<Tokenizers::String>();
        }
        SPtrTokenizer TokenizerFactory::CreateSpace() {
            return std::make_shared<Tokenizers::Space>();
        }
        SPtrTokenizer TokenizerFactory::CreateTab() {
            return std::make_shared<Tokenizers::Tab>();
        }
    }
}

