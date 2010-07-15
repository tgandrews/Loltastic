require 'socket'
include Socket::Constants

class VMReceiver
  include Singleton
  
  def initialize
    @sock = UDPSocket.new
    @sock.bind '0.0.0.0', 41588
    @callbacks = Array.new
    reading
  end
  
  def callback(method)
    @callbacks << method
  end
  
  private 
  def reading
    @listening_thread = Thread.new {
      while true
        data = @sock.recvfrom 1024
        #data = @sock.recvfrom_nonblock 4 + size, MSG_PEEK
        @callbacks.each { |m|
          m.call(data)
        }
      end
    }
  end
  
  def parsedata
    puts "Hello"
  end
  
end