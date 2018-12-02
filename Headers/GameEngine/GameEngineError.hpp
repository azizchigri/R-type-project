//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// GameEngineError exception class
//

#ifndef GAMEENGINEERROR_HPP
#define GAMEENGINEERROR_HPP

#include <exception>
#include <iostream>

namespace Engine {
	class GameEngineError : public std::runtime_error {
		public:
		explicit GameEngineError(const char *buff = "GameEngine Error")
		noexcept : runtime_error(buff)
		{}
	};
}

#endif //GAMEENGINEERROR_HPP
