#ifndef XLELIB_FF_S_ACHIEVEMENT_HPP
#define XLELIB_FF_S_ACHIEVEMENT_HPP

#include "../xlelib.hpp"
#include "../conversion.hpp"

namespace XLELib {
	namespace FF {
		/* Exception to handle S_Achievement table errors. */
		class S_AchievementError : public std::exception {
			public:
				/* Create an error with given message. */
				S_AchievementError(std::string msg);
				
				/* Give the error message. */
				const char* what() const throw();
				
			private:
				/* Error message. */
				std::string error;
		};
		
		/* Class to handle the S_Achievement table type. */
		class S_Achievement : public Conversion<S_Achievement> {
			public:
				/* Create an empty S_Achievement table without header. */
				S_Achievement();
				
				/* Read the S_Achievement table from a given file. */
				S_Achievement(std::string input_file);
				
				/* Delete the S_Achievement table. Does not delete any attached files. */
				virtual ~S_Achievement();
				
				/* Init conversion and register required functions.
				   Do NOT call directly! This function is called by the constructor. */
				void init_conversion();
		};
	}
}

#endif
