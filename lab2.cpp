#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>

// Типи даних для визначення автомату
using State = std::string;
using Symbol = char;
using TransitionFunction = std::map<std::pair<State, Symbol>, State>;

// Функція для визначення несприйнятливих літер
std::unordered_set<Symbol> findUnacceptedSymbols(
    const std::unordered_set<Symbol>& alphabet,
    const std::unordered_set<State>& states,
    const TransitionFunction& delta
) {
    std::unordered_set<Symbol> unacceptedSymbols = alphabet;

    for (const auto& state : states) {
        for (const auto& symbol : alphabet) {
            auto transition = delta.find({state, symbol});
            if (transition != delta.end()) {
                unacceptedSymbols.erase(symbol);
            }
        }
    }

    return unacceptedSymbols;
}

int main() {
    // Вхідний алфавіт
    std::unordered_set<Symbol> alphabet = {'a', 'b', 'c', 'd'};
    
    // Набір станів
    std::unordered_set<State> states = {"q0", "q1", "q2"};
    
    // Функція переходів
    TransitionFunction delta = {
        {{"q0", 'a'}, "q0"},
        {{"q1", 'b'}, "q2"}
    };
    
    // Виклик функції для визначення несприйнятливих літер
    std::unordered_set<Symbol> unacceptedSymbols = findUnacceptedSymbols(alphabet, states, delta);
    
    // Виведення результату
    std::cout << "Unaccepted symbols: ";
    for (const auto& symbol : unacceptedSymbols) {
        std::cout << symbol << " ";
    }
    std::cout << std::endl;

    return 0;
}
