
#ifndef RUCKSACK_SYMBOL_HPP_INCLUDED
#define RUCKSACK_SYMBOL_HPP_INCLUDED

#ifdef rucksack_EXPORTS
#include <fcppt/export_symbol.hpp>
#	define RUCKSACK_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#include <fcppt/import_symbol.hpp>
#	define RUCKSACK_SYMBOL FCPPT_IMPORT_SYMBOL
#endif

#endif
