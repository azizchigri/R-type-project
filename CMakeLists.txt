cmake_minimum_required(VERSION 3.10)
project(CPP_rtype_2018)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	conan_basic_setup()
else()
	message(WARNING "The file conanbuildinfo.cmake doesn't exist, you
have to run conan install first")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")

include_directories(Headers)
include_directories(${CMAKE_INCLUDE_PATH})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories( ${Boost_INCLUDE_DIRS} )

file(COPY Resources/arial.ttf DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY Resources/menu.wav DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY Resources/om.png DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY Resources/player1.png DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY Resources/player2.png DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY Resources/player3.png DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY Resources/player4.png DESTINATION ${CMAKE_BINARY_DIR}/bin)

add_executable(r-type_server
	Sources/Network/Server/main.cpp
	Sources/Network/Server/Player.cpp
	Sources/Network/Server/Room.cpp
	Sources/Network/Server/RoomManager.cpp
	Sources/Network/Server/TcpConnection.cpp
	Sources/Network/Server/Server.cpp
	Sources/Network/Server/UdpManager.cpp
	Sources/Network/Common/UdpConnection.cpp
	Sources/GameEngine/Game/Core/AGameServer.cpp
	Sources/GameEngine/Game/Core/Rtype/RtypeServer.cpp
	Sources/GameEngine/Common/ThreadLauncher.cpp
	)

target_link_libraries(r-type_server ${CONAN_LIBS})

add_executable(r-type_client
	Sources/Network/Client/main.cpp
	Sources/Network/Client/TcpClient.cpp
	Sources/Network/Common/UdpConnection.cpp
	Sources/Network/Server/UdpManager.cpp
	Sources/Network/Common/UdpClient.cpp
	Sources/GameEngine/Graphical/Model/GameObject.cpp
	Sources/GameEngine/Graphical/Model/AMusic.cpp
	Sources/GameEngine/Graphical/Model/Sfml/SfmlMusic.cpp
	Sources/GameEngine/Graphical/Model/Sfml/SfmlInputText.cpp
	Sources/GameEngine/Graphical/Model/Sfml/SfmlOutputText.cpp Sources/GameEngine/Graphical/Model/Sfml/SfmlShape.cpp
	Headers/GameEngine/Graphical/Model/Sfml/SfmlShape.hpp Headers/GameEngine/Graphical/Core/AEventManager.hpp
	Headers/GameEngine/Common/Event.hpp Headers/GameEngine/Common/Key.hpp
	Sources/GameEngine/Graphical/Core/Sfml/SfmlEventManager.cpp
	Headers/GameEngine/Graphical/Core/Sfml/SfmlEventManager.hpp
	Headers/GameEngine/Graphical/Model/ColliderObject.hpp
	Headers/GameEngine/Common/Vector2.hpp Headers/GameEngine/Graphical/Core/IMenu.hpp
	Sources/GameEngine/Graphical/Core/Sfml/SfmlMenu.cpp Headers/GameEngine/Graphical/Core/Sfml/SfmlMenu.hpp
	Headers/GameEngine/Game/Model/Enemy.hpp Headers/GameEngine/Game/Model/Entity.hpp
	Headers/GameEngine/Game/Model/EntityCollider.hpp
	Headers/GameEngine/Game/Model/Missile.hpp Headers/GameEngine/Game/Model/Player.hpp
	Headers/GameEngine/Common/IThreadable.hpp Headers/GameEngine/Common/ThreadLauncher.hpp
	Sources/GameEngine/Common/ThreadLauncher.cpp Sources/GameEngine/Game/Core/AGameServer.cpp Headers/GameEngine/Game/Core/AGameServer.hpp Sources/GameEngine/Game/Core/AGameClient.cpp Headers/GameEngine/Game/Core/AGameClient.hpp Sources/GameEngine/Game/Core/Rtype/RtypeClient.cpp Headers/GameEngine/Game/Core/Rtype/RtypeClient.hpp)

target_link_libraries(r-type_client ${CONAN_LIBS})

# Detect and add SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(r-type_client ${CONAN_LIBS} ${SFML_LIBRARIES}
		${SFML_DEPENDENCIES})
endif()