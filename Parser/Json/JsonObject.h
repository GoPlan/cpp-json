//
// Created by LE, Duc Anh on 8/9/15.
//

#ifndef CLDEPARSER_PARSER_JSONOBJECT_H
#define CLDEPARSER_PARSER_JSONOBJECT_H

namespace CldeParser {
    namespace Parser {

        class JsonObject {

        public:
            JsonObject() = default;
            JsonObject(const JsonObject &) = default;
            JsonObject(JsonObject &&) = default;
            JsonObject &operator=(const JsonObject &) = default;
            JsonObject &operator=(JsonObject &&) = default;
            virtual ~JsonObject() = default;
        };
    }
}


#endif //CLDEPARSER_PARSER_JSONOBJECT_H
