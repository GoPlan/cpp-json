//
// Created by LE, Duc Anh on 8/4/15.
//

#include "Id.h"

namespace CldeParser {
    namespace Common {
        namespace Tokenizers {

            bool Id::isCharacter(char character) {
                return ((int) character > 65 && (int) character < 91)
                       || ((int) character > 96 && (int) character < 123);
            }

            bool Id::isDigit(char character) {
                return (int) character > 47 && (int) character < 58;
            }

            bool Id::isUnderscore(char character) {
                return (int) character == 95;
            }

            bool Id::BeginWithCharacter(char character) {
                return isCharacter(character) || isUnderscore(character);
            }

            SPtrToken Id::CreateSPtrToken() {
                return CldeParser::CreateSPtrToken((int) TokenType::Id, _lexeme);
            }

            const StateSet &Id::CompleteStates() const {
                throw ScannerException{"CompleteStates is not supported"};
            }

            const StateSet &Id::AcceptedStates() const {
                throw ScannerException{"AcceptedStates is not supported"};
            }

            const TransitionMap &Id::Transitions() const {
                throw ScannerException{"TransitionMap is not supported"};
            }

            bool Id::IsValid(char character) {
                return _currentState > 0 ? isDigit(character) || isCharacter(character) || isUnderscore(character)
                                         : isCharacter(character) || isUnderscore(character);
            }
            bool Id::CoreValidate(char character) {
                if (_lexeme.length() == 0) { _lexeme.reserve(20); }
                if (_currentState < 2) { _currentState = _currentState + 1; }
                _lexeme.append(1, character);
                return true;
            }
        }
    }
}

