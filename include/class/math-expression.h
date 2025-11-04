#pragma once

#include "./stack/stack-dynamic.h"

#include <string>
#include <string_view>

class MathExpress {
private:
    // Tables des symboles ouvrants/fermants alignés par index
    // '{' <-> '}', '(' <-> ')', '[' <-> ']'
    inline static const std::string kOpen  = "{([";
    inline static const std::string kClose = "})]";

    static bool isOpen(char c) {
        return kOpen.find(c) != std::string::npos;
    }

    static bool isClose(char c) {
        return kClose.find(c) != std::string::npos;
    }

    static bool isSymbol(char c) {
        return isOpen(c) || isClose(c);
    }

    // Vrai si 'open' et 'close' forment une paire correspondante
    static bool isMatching(char open, char close) {
        std::size_t iOpen  = kOpen.find(open);
        std::size_t iClose = kClose.find(close);
        return (iOpen != std::string::npos) &&
               (iClose != std::string::npos) &&
               (iOpen == iClose);
    }

public:
    // Valide la syntaxe d'une expression mathématique (parenthésage)
    static bool isValidMathExpression(std::string_view expr) {
        StackDynamic<char> symbolStack; // pile des symboles ouvrants

        for (char ch : expr) {
            // Ignorer tout caractère qui n'est pas un symbole
            if (!isSymbol(ch)) continue;

            if (isOpen(ch)) {
                // Empiler tout symbole ouvrant
                symbolStack.push(ch);
            } else {
                // On a un symbole fermant
                if (symbolStack.empty()) return false; // rien à fermer

                char top = symbolStack.getHead();      // dernier ouvrant
                if (!isMatching(top, ch)) return false; // type non correspondant

                symbolStack.pop(); // paire validée
            }
        }

        // Expression valide si aucune ouverture non fermée ne reste
        return symbolStack.empty();
    }
};
