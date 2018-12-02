//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AInputText class declaration
//

#ifndef AINPUTTEXT_HPP
#define AINPUTTEXT_HPP

#include <iostream>
#include "GameEngine/Graphical/Model/ADrawable.hpp"

namespace Engine {
	namespace Graphical {
		template<class T>
		class AInputText : public ADrawable<T> {
			public:
			virtual ~AInputText() = default;
			virtual void move(const Vector3 &dest) = 0;
			virtual void draw(T &window) const = 0;

			const std::string &getText() const
			{
				return text;
			}

			const std::string &getPolice() const
			{
				return police;
			}

			protected:
			AInputText(const std::string &text, const std::string
			&police) : ADrawable<T>({0, 0, 0}, {30, 30, 30},
			{50, 50, 50})
			{
				this->text = text;
				this->police = police;
			}

			std::string text;
			std::string police;
		};
	}
}


#endif //AINPUTTEXT_HPP
