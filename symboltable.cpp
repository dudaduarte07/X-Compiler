#include "symboltable.h"

SymbolTable::SymbolTable()
{
    parent = 0;
}

SymbolTable::SymbolTable(SymbolTable* p)
{
    parent = p;
}

bool
SymbolTable::add(STEntry* t)
{
    if (!(symbols.find(t->token->lexeme) == symbols.end()))
        return false;
    
    symbols.insert({t->token->lexeme,t});
    return true;
}

bool
SymbolTable::remove(string name)
{
    return symbols.erase(name) != 0;
}

void 
SymbolTable::clear()
{
    symbols.clear();
}

bool
SymbolTable::isEmpty()
{
    symbols.empty();
}

STEnty*
SymbolTable::get(string name)
{
    SymbolTable* table = this;

    auto s = table->symbols.find(name);

    while (s == table->symbols.end())
    {
        table = table->parent;
        if (table == 0)
        {
            return 0;
        }

        s = table->symbols.find(name);
    }

    return s->second;
}

SymbolTable*
SymbolTable::getParent()
{
    return parent;
}