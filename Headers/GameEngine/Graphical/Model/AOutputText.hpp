//
// EPITECH PROJECT, 2018
// CPP_rtype_2018
// File description:
// AOutputText class declaration
//

#ifndef AOUTPUTTEXT_HPP
#define AOUTPUTTEXT_HPP

#include <iostream>
#include "ADrawable.hpp"

namespace Engine {
	namespace Graphical {
		template<class T>
		class AOutputText : public ADrawable<T> {
			public:
			virtual ~AOutputText() = default;
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
			AOutputText(const std::string &text, const std::string
			&police, Vector3 size) : ADrawable<T>({0, 0, 0}, size,
			{50, 50, 50}), text(text), police(police)
			{
			}
			const std::string text;
			const std::string police;
		};
	}
}

#endif //AOUTPUTTEXT_HPP
