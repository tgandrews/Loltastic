require 'rubygems'
require 'cramp/controller'
require 'thin'
require 'socket'
require 'VMReceiver'

class WebsocketController < Cramp::Controller::Websocket
  before_start :test_request
  on_data :received_data
  
  @count = 0
  @conn
  
  def received_data(data)
    increment 
  	puts "Received: #{@count.to_s} #{data}"
  	@conn.send data, 0
    render "Got your #{@count.to_s} #{data}"
  end
  
  def test_request
    puts "Web socket connection requested"
    create_connection
    vmreceiver = VMReceiver.instance
    vmreceiver.callback method(:receive_vm_data)
    yield
  end
  
  def receive_vm_data(data)
    puts "Data from VM: #{data}"
    render "Data from VM: #{data}"
  end
  
  private
  def create_connection
    host = '192.168.1.65'
    port = '41588'
    @conn = UDPSocket.new
    @conn.connect(host, port)
  end
  
  def increment
    if @count.nil?
      @count = 0
    else
      @count += 1
    end
  end
end

