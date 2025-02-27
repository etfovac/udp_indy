#include <vcl.h>
#include <tchar.h>

#pragma hdrstop
#include <IdUDPClient.hpp>
#include <IdGlobal.hpp>
#include <iostream>

#pragma package(smart_init)

int _tmain(int argc, _TCHAR* argv[])
{
            try
    {
        // Create the UDP client
        TIdUDPClient *udpClient = new TIdUDPClient(NULL);

        // Set the port number to broadcast on
        udpClient->Port = 12345;

        // The message to be broadcasted
        String message = "Hello, this is a broadcast message!";
        TIdBytes bytes;
        // Convert the message to bytes
		bytes = ToBytes(message);

        // Broadcast the message
        udpClient->Broadcast(bytes, 12345);

        std::cout << "Message broadcasted successfully." << std::endl;

        // Clean up
        delete udpClient;
    }
    catch (const Exception &e)
    {
        std::cerr << "An error occurred: " << e.Message.c_str() << std::endl;
    }

	return 0;
}
