#The code below reads in some important libraries
from socketIO_client import SocketIO
import serial
import argparse

#This code creates a parser
#A parser is used to parse input's to your program
#Recall you will be running your program as follows:
#client.py --station station_number --port port_number
#Your program thus has two arguments to parse, the station number and the port number

#This line creates an argument parser called parser
parser = argparse.ArgumentParser(description='Process station number and port number.')

#We now need to specify to parser, what arguments to look for
#To do this, we call the function parser.add_argument(argument_name)

#Your code here
parser.add_argument('--station')
parser.add_argument('--port')

#The line below has the argument parser parse all the inputs and return
#what the user input for each argument
args = parser.parse_args()

#Now we need to read in what the user specified for each argument
#We store it in two variables, station and port
station = #Your code here int(args.station)
port = #your code here args.port

#Station needs to be an integer not a string
station = int(station)

#Now that the program knows what station it is and port data is coming from
#We can start reading the serial input
#The line below creates a serial input on the port given as an argument
ser = serial.Serial(port)

#The lines below setup the websocket client so that we can start pushing
#data to the server
with SocketIO('hkn-iot-workshop.herokuapp.com', 80) as sock:
	while True:
		#The above lines create a loop that runs forever

		#Inside this loop, we need to read the serial input
		#The function ser.readline() reads an input from the serial port
		#We will store this input into a variable called value
		value = #Your code here ser.readline()

		#Now we need to decode the input text into a number we can send
		#The code below does that
		value = value.decode("utf-8").strip()
		#For debugging purposes, we will print out this value
		#Your code here print(value)

		#The code below will send the data to the server
		sock.emit('data', {'i':station, 'd':value})
