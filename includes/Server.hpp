#ifndef __SERVER_H__
# define __SERVER_H__

# include <boost/bind.hpp>
# include <boost/shared_ptr.hpp>
# include <boost/enable_shared_from_this.hpp>
# include <boost/asio.hpp>
# include "Client.hpp"
# include <list>

namespace Boophie {
  namespace Network {
    class Server {
    public:
      Server(boost::asio::io_service&);

      void	accept();
      void	endAccept(boost::shared_ptr<Client> client,
			  const boost::system::error_code& error);

      void	run();

    private:
      Server();

      bool					_isRunning;
      boost::asio::io_service			&_ioService;
      boost::asio::ip::tcp::acceptor		_acceptor;
      std::list<boost::shared_ptr<Client> >	_clients;
    };
  }
}

#endif
