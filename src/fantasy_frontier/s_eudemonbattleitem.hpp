#ifndef XLELIB_FF_S_EUDEMONBATTLEITEM_HPP
#define XLELIB_FF_S_EUDEMONBATTLEITEM_HPP

#include "../xlelib.hpp"
#include "../conversion.hpp"

namespace XLELib {
	namespace FF {
		/* Exception to handle S_EudemonBattleItem table errors. */
		class S_EudemonBattleItemError : public std::exception {
			public:
				/* Create an error with given message. */
				S_EudemonBattleItemError(std::string msg);
				
				/* Give the error message. */
				const char* what() const throw();
				
			private:
				/* Error message. */
				std::string error;
		};
		
		/* Class to handle the S_EudemonBattleItem table type. */
		class S_EudemonBattleItem : public Conversion<S_EudemonBattleItem> {
			public:
				/* Create an empty S_EudemonBattleItem table without header. */
				S_EudemonBattleItem();
				
				/* Read the S_EudemonBattleItem table from a given file. */
				S_EudemonBattleItem(std::string input_file);
				
				/* Delete the S_EudemonBattleItem table. Does not delete any attached files. */
				virtual ~S_EudemonBattleItem();
				
				/* Init conversion and register required functions.
				   Do NOT call directly! This function is called by the constructor. */
				void init_conversion();
				
				/* Convert S_EudemonBattleItem from version 4.13 to 3.9.
				   This function removes the gaia chronicle fortification buffs for level 25-40 of eidolon accessories. */
				void convert_4_13_to_3_9();
		};
	}
}

#endif
