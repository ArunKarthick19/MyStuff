import java.net.*;
import java.io.*;

public class Rfc865UdpClient {
    public static void main(String[] args) {
        try {
            // Step 1: Open a UDP socket
            DatagramSocket socket = new DatagramSocket();
            System.out.println("UDP Client started...");

            // Step 2: Define server details
            InetAddress serverAddress = InetAddress.getByName("10.96.179.143"); // Change to actual server IP
            int serverPort = 17; // Default QOTD port

            // Step 3: Send request to server
            byte[] buffer = new byte[1]; // Empty request
            DatagramPacket request = new DatagramPacket(buffer, buffer.length, serverAddress, serverPort);
            socket.send(request);
            System.out.println("Request sent to server...");

            // Step 4: Receive response from server
            byte[] responseBuffer = new byte[512]; // Buffer for response
            DatagramPacket response = new DatagramPacket(responseBuffer, responseBuffer.length);
            socket.receive(response);

            // Step 5: Convert and display the response
            String quote = new String(response.getData(), 0, response.getLength());
            System.out.println("Quote of the Day: " + quote);

            // Step 6: Close socket
            socket.close();
        } catch (SocketException e) {
            System.out.println("Socket error: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("IO error: " + e.getMessage());
        }
    }
}
