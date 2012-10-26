#ifndef __PROTOCOLE_H__
# define __PROTOCOLE_H__

# include "Message.hpp"
# include "Client.hpp"

namespace Boophie {
  namespace Network {
    template <typename ProtocoleKeyCode>
    class Protocole : public ProtocoleKeyCode {
    public:
      static void	processMessage(const Message& iMessage, const Client& client) {
	ProtocoleKeyCode::init();
	ProtocoleKeyCode::getAction(iMessage.keyCode())(client, iMessage);
	//	ProtocoleKeyCode::_actions[iMessage.keyCode()](client, iMessage);
      }
    };
  }
}

#endif
