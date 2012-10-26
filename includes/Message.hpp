#ifndef __MESSAGE_H__
# define __MESSAGE_H__

# include <cstdio>
# include <cstdlib>
# include <cstring>

namespace Boophie {
  namespace Network {
    class Message {
    public:
      enum { header_length = 16 };
      enum { max_body_length = 512 };

      typedef struct	sPackage {
	size_t		size;
	size_t		keycode;
	char		data[max_body_length];
      }			internalPackage;

      typedef union	uPackage {
	internalPackage	package;
	char		buffer[sizeof(internalPackage)];
      }			Packet;

      Message();

      char*		data();
      size_t		length() const;
      char*		body();
      char*		header();
      size_t		messageLength();
      void		messageLength(size_t);
      size_t		keyCode() const;

      bool		parseHeader();

    private:
      Packet	_data;
      //     char	_data[header_length + max_body_length];
      size_t	_messageLength;
      size_t	_keyCode;
    };
  }
}

#endif
