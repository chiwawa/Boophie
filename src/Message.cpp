#include "Message.hpp"

#include <iostream>

namespace Boophie {
  namespace Network {

    Message::Message()
      : _messageLength(0) {

    }

    char*	Message::data() { return this->_data.buffer; }

    size_t	Message::length() const { return header_length + max_body_length; }

    char*	Message::body() { return this->_data.buffer + header_length; }

    char*	Message::header() { return this->_data.buffer; }

    size_t	Message::messageLength() { return this->_messageLength; }

    void	Message::messageLength(size_t messageLength) {
      this->_messageLength = (messageLength > max_body_length ? max_body_length : messageLength );
    }

    size_t	Message::keyCode() const { return this->_keyCode; }

    bool	Message::parseHeader() {
      size_t	messageLength = this->_data.package.size;

      std::cout << messageLength << std::endl;
      if (messageLength > max_body_length) return false;
      this->_messageLength = messageLength;
      return true;
    }

  }
}
