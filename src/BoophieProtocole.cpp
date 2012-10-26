#include "BoophieProtocole.hpp"

namespace Boophie {
  namespace Network {
    namespace ProtocoleKeyCode {

      bool Boophie::Network::ProtocoleKeyCode::Admin::_isAlreadyInitialized = false;
      Admin::prot_action	_actions[]  = {
	&Admin::handShake,
	&Admin::listRoom,
	&Admin::connectionToRoom,
	&Admin::disconnectionFromRoom,
	&Admin::readyToLaunch
      };

      Admin::prot_action	Admin::getAction(size_t keyCode) {
	static Admin::prot_action	actions[] = {
	  &Admin::handShake,
	  &Admin::listRoom,
	  &Admin::connectionToRoom,
	  &Admin::disconnectionFromRoom,
	  &Admin::readyToLaunch
	};

	return actions[keyCode];
      }

      void	Admin::handShake(const Boophie::Network::Client& client, const Boophie::Network::Message& message) {
	std::cout << "HandShaked" << std::endl;
      }

      void	Admin::listRoom(const Boophie::Network::Client& client, const Boophie::Network::Message& message) {

      }

      void	Admin::connectionToRoom(const Boophie::Network::Client& client, const Boophie::Network::Message& message) {

      }

      void	Admin::disconnectionFromRoom(const Boophie::Network::Client& client, const Boophie::Network::Message& message) {

      }

      void	Admin::readyToLaunch(const Boophie::Network::Client& client, const Boophie::Network::Message& message) {

      }
    }
  }
}
