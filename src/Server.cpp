#include "Server.hpp"
#include <iostream>

namespace Boophie {
  namespace Network {
    Server::Server(boost::asio::io_service& io_service)
      : _isRunning(true),
	_ioService(io_service),
	_acceptor(io_service,
		  boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),
						 4242)) {
      this->accept();
    }

    void	Server::accept() {
      boost::shared_ptr<Client>	client = Client::create(this->_ioService);

      this->_acceptor.async_accept(client->socket(),
				   boost::bind(&Server::endAccept, this, client,
					       boost::asio::placeholders::error));
    }

    void	Server::endAccept(boost::shared_ptr<Client> client,
				  const boost::system::error_code& error) {
      if (!error) {
	this->_clients.push_back(client);
	client->write();
      }
      this->accept();
    }

    void	Server::run() {
      /*while (this->_isRunning == true) {
	std::cout << "Running !" << std::endl;
	std::list<boost::shared_ptr<Client> >::iterator	begin = this->_clients.begin();
	std::list<boost::shared_ptr<Client> >::iterator	end = this->_clients.end();

	for (; begin != end; ++begin) {
	  (*begin)->read();
	}
	}*/
    }
  }
}
