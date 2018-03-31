# Morse code decoder

A morse code decoder that translates morse code into English.

## Getting Started

Download and unzip the project, then open the project in the arduino IDE. The arduino board should have two buttons, one connected to pin 3 and one connected to pin 4. The first is to input dots and dashes, and the second is to submit the letter once the user is done typing.

Note that to type a space between words - " " - the user needs to input 6 dots instead of just leaving a gap in the typing of words. This is so the user can slow down and explicitly state when they are done typing a word. 

You will be able to see the morse code and equivalant English in the serial monitor.

## Built With

* [Ardiuno](https://www.arduino.cc/en/Main/Docs)

## Contributing

Feel free to contribute however you see fit!

For a start, the code at the moment uses a huge amount of if-else statements instead of storing the morse code and equivalent ASCII in a struct and looping through somehow. I need to get around to fixing this up once I understand data structures in C++ a bit better.
