#ifndef __BOOPHIE_PROTOCOLE_H__
# define __BOOPHIE_PROTOCOLE_H__

# include "Client.hpp"

namespace Boophie {
  namespace Network {
    namespace ProtocoleKeyCode {
      class Admin {
      public:
	typedef void (*prot_action)(const Boophie::Network::Client&, const Boophie::Network::Message&);

	static void	init() {
	  if (Admin::_isAlreadyInitialized == false) {
	    /*Admin::_actions = new prot_action[5];
	    Admin::_actions[0] = &handShake;
	    Admin::_actions[1] = &listRoom;
	    Admin::_actions[2] = &connectionToRoom;
	    Admin::_actions[3] = &disconnectionFromRoom;
	    Admin::_actions[4] = &readyToLaunch;
	    */	    Admin::_isAlreadyInitialized = true;
	  }
	}

	static prot_action	getAction(size_t);
	static void		handShake(const Boophie::Network::Client&, const Boophie::Network::Message&);
	static void		listRoom(const Boophie::Network::Client&, const Boophie::Network::Message&);
	static void		connectionToRoom(const Boophie::Network::Client&, const Boophie::Network::Message&);
	static void		disconnectionFromRoom(const Boophie::Network::Client&, const Boophie::Network::Message&);
	static void		readyToLaunch(const Boophie::Network::Client&, const Boophie::Network::Message&);

	static prot_action	*_actions;
	static bool		_isAlreadyInitialized;
      };

    }
  }
}

# define INIT_PROTOCOLE() bool Boophie::Network::ProtocoleKeyCode::Admin::_isAlreadyInitialized = false;

#endif
