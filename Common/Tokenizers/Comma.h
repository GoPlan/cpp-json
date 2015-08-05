//
// Created by LE, Duc Anh on 8/4/15.
//

#ifndef CLDEPARSER_COMMON_TOKENIZERS_COMMA_H
#define CLDEPARSER_COMMON_TOKENIZERS_COMMA_H

#include "../TokenType.h"
#include "../../Tokenizer.h"
#include "../../Exception/ScannerException.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            class Comma : public Tokenizer {

            public:
                Comma() = default;
                Comma(const Comma &) = default;
                Comma(Comma &&) = default;
                Comma &operator=(const Comma &) = default;
                Comma &operator=(Comma &&) = default;
                ~Comma() = default;

                // Tokenizer
                bool BeginWithCharacter(char character) override;
                const StateSet &CompleteStates() const override;
                const StateSet &AcceptedStates() const override;
                const TransitionMap &Transitions() const override;
                SPtrToken CreateSPtrToken() override;

            protected:
                bool IsValid(char character) override;
                bool CoreValidate(char character) override;
            };
        }
    }
}


#endif //CLDEPARSER_COMMON_TOKENIZERS_COMMA_H
