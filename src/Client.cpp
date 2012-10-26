#include "Client.hpp"
#include "ProtocoleUsed.hpp"
#include "Protocole.hpp"
#include <iostream>

namespace Boophie {
  namespace Network {
    boost::shared_ptr<Client> Client::create(boost::asio::io_service& io_service) {
      return boost::shared_ptr<Client>(new Client(io_service));
    }

    Client::Client(boost::asio::io_service& io_service)
      : _socket(io_service) {
    }

    void					Client::write() {
      boost::asio::async_write(this->_socket, boost::asio::buffer("Salut :)"),
			       boost::bind(&Client::endWrite, shared_from_this(),
					   boost::asio::placeholders::error,
					   boost::asio::placeholders::bytes_transferred));
    }

    void					Client::endWrite(const boost::system::error_code&, size_t) {
      std::cout << "End Write" << std::endl;
      this->readHeader();
    }

    void					Client::readHeader() {
      std::cout << "Reading Header" << std::endl;
      boost::asio::async_read(this->_socket, boost::asio::buffer(this->_messageRead.data(), Message::header_length),
			      boost::bind(&Client::readBody, shared_from_this(),
					  boost::asio::placeholders::error)
			      );
    }

    void					Client::readBody(const boost::system::error_code& e) {
#warning "I NEED TO PARSE THE HEADER TO KNOW IF EVERYTHING IS OKAY :("
      if (!e) {// && this->_messageRead.parseHeader() == true) {
	std::cout << "Reading Body" << std::endl;
	boost::asio::async_read(this->_socket, boost::asio::buffer(this->_messageRead.body(), 4),//this->_messageRead.messageLength()),
				boost::bind(&Client::process, shared_from_this(),
					    boost::asio::placeholders::error)
				);
      }
    }

    void					Client::process(const boost::system::error_code& e) {
      std::cout << "Process request" << std::endl;
      if (!e) {
	*((int*)&this->_messageRead.header()[8]) = 0x01;
	Protocole<Admin>::processMessage(this->_messageRead, *this);
      }
      this->readHeader();
    }

    boost::asio::ip::tcp::socket&	Client::socket() {
      return this->_socket;
    }
  }
}
