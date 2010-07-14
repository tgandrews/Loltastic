require 'rubygems'
require 'cramp/controller'
require 'thin'
require 'socket'

class WebsocketController < Cramp::Controller::Websocket
  before_start :test_request
  on_data :received_data
  
  @count = 0
  
  def received_data(data)
    increment 
  	puts "Received: #{@count.to_s} #{data}"
    render "Got your #{@count.to_s} #{data}"
  end
  
  def test_request
    puts "Web socket connection requested"
    yield
    #halt 500, {'Content-Type' => 'text/plain'}, "Invalid ID"
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

