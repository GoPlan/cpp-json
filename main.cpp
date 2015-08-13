#include <string>
#include <iostream>
#include "CldeParser.h"
#include "Parsing/ParserFactory.h"

using namespace CldeParser;

int main() {

    std::string example{"{ a01 : { name: \"DucAnh\", age : 34 }, a02 : [1, 2 ,3 , 4, 5]}"};

    // Scanning
    Scanner scanner;
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNull());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolTrue());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBoolFalse());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateId());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateString());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateNumber());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateColon());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateComma());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateSpace());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateTab());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCurlyBraceOpen());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateCurlyBraceClosing());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBracketOpen());
    scanner.Tokenizers().push_back(Scanning::TokenizerFactory::CreateBracketClosing());

    SPtrTokenVector tokens = scanner.Scan(example);
    SPtrTokenVector filtereds(tokens.size());

    std::copy_if(tokens.cbegin(), tokens.cend(), filtereds.begin(),
                 [](SPtrToken const &token) -> bool {
                     std::cout << token->CopyToString() << std::endl;
                     return token->id() != (int) Scanning::TokenType::Space;
                 });

    filtereds.shrink_to_fit();

    // Parsing
    Parser parser;
    parser.Derivatives().push_back(Parsing::ParserFactory::CreateJsonDerivative());

    SPtrSyntaxModelVector syntaxTrees = parser.Parse(filtereds);
    std::cout << syntaxTrees.size() << std::endl;

    return EXIT_SUCCESS;
}