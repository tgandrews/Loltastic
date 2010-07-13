require 'rubygems'
require 'cramp/controller'
require 'thin'

class WebsocketController < Cramp::Controller::Websocket
  before_start :test_request
  on_data :received_data

  def received_data(data)
  	puts "lol"
    render "Got your #{data}"
  end
  
  def test_request
    puts "Going to reject them"
    halt 500, {'Content-Type' => 'text/plain'}, "Invalid ID"
  end
end

